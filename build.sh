#!/bin/bash

set -e

echo "================================================"
echo "Step 1: Building and Running Tests (Linux)"
echo "================================================"

# Build tests natively on Linux first
mkdir -p build-test
cd build-test

echo "Configuring tests..."
cmake -DCMAKE_BUILD_TYPE=Release \
      -DBUILD_TESTS_ONLY=ON \
      ..

echo "Building test executable..."
make test

echo ""
echo "Running tests..."
./test

TEST_RESULT=$?

if [ $TEST_RESULT -ne 0 ]; then
    echo ""
    echo "❌ Tests FAILED! Aborting build."
    exit 1
fi

echo ""
echo "✅ All tests PASSED!"
echo ""

cd ..
rm -rf build-test

echo "================================================"
echo "Step 2: Building Windows Executable"
echo "================================================"

# Now build for Windows
mkdir -p build
cd build

if [ "${TARGET_PLATFORM}" = "linux" ]; then
    echo "Configuring for Linux..."
    cmake -DCMAKE_BUILD_TYPE=Release ..
    make

    mkdir -p /app/dist-linux
    cp ${PROJECT_NAME} /app/dist-linux/

    echo ""
    echo "✅ Linux build complete! Executable in dist-linux/"

else
    echo "Configuring for Windows..."
    cmake -DCMAKE_TOOLCHAIN_FILE=/toolchain.cmake \
          -DCMAKE_BUILD_TYPE=Release \
          -DBUILD_TESTS_ONLY=OFF \
          ..
    
    # Build only the main application, NOT the tests
    make ${PROJECT_NAME}

    mkdir -p /app/dist-windows
    cp ${PROJECT_NAME}.exe /app/dist-windows/
    cp /usr/x86_64-w64-mingw32/bin/SDL3.dll /app/dist-windows/
    cp /usr/x86_64-w64-mingw32/bin/SDL3_ttf.dll /app/dist-windows/

    echo ""
    echo "✅ Windows build complete! Executable and DLLs in dist-windows/"
fi

echo ""
echo "================================================"
echo "BUILD SUCCESSFUL!"
echo "================================================"