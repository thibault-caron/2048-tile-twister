FROM ubuntu:22.04

# Avoid interactive prompts during build
ENV DEBIAN_FRONTEND=noninteractive
ARG TARGET_PLATFORM=windows

# Install common build tools
RUN apt-get update && apt-get install -y \
    cmake \
    make \
    wget \
    unzip \
    && rm -rf /var/lib/apt/lists/*

# Install platform-specific tools
RUN if [ "$TARGET_PLATFORM" = "windows" ]; then \
        apt-get update && apt-get install -y \
        mingw-w64 \
        g++-mingw-w64-x86-64 \
        && rm -rf /var/lib/apt/lists/*; \
    else \
        apt-get update && apt-get install -y \
        build-essential \
        g++ \
        libsdl3-dev \
        && rm -rf /var/lib/apt/lists/*; \
    fi

# Download and install SDL3 for Windows cross-compilation
RUN if [ "$TARGET_PLATFORM" = "windows" ]; then \
        cd /tmp && \
        wget https://sourceforge.net/projects/simple-directmedia.mirror/files/release-3.2.28/SDL3-devel-3.2.28-mingw.tar.gz/download -O SDL3-devel-3.2.28-mingw.tar.gz && \
        tar -xzf SDL3-devel-3.2.28-mingw.tar.gz && \
        cp -r SDL3-3.2.28/x86_64-w64-mingw32/* /usr/x86_64-w64-mingw32/ && \
        rm -rf SDL3-*; \
    fi

# Create toolchain file for Windows cross-compilation
RUN if [ "$TARGET_PLATFORM" = "windows" ]; then \
        echo 'set(CMAKE_SYSTEM_NAME Windows)' > /toolchain.cmake && \
        echo 'set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)' >> /toolchain.cmake && \
        echo 'set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)' >> /toolchain.cmake && \
        echo 'set(CMAKE_RC_COMPILER x86_64-w64-mingw32-windres)' >> /toolchain.cmake && \
        echo 'set(CMAKE_FIND_ROOT_PATH /usr/x86_64-w64-mingw32)' >> /toolchain.cmake && \
        echo 'set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)' >> /toolchain.cmake && \
        echo 'set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)' >> /toolchain.cmake && \
        echo 'set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)' >> /toolchain.cmake; \
    fi

# Set working directory
WORKDIR /app

# Build script
COPY build.sh ./build.sh
RUN chmod +x ./build.sh
