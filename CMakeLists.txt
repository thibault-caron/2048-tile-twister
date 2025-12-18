cmake_minimum_required(VERSION 3.15)

if(DEFINED ENV{PROJECT_NAME})
    set(APP_NAME $ENV{PROJECT_NAME})
else()
    set(APP_NAME "SDL3App")
endif()

project(${APP_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SDL3
find_package(SDL3 REQUIRED)
find_package(SDL3_ttf REQUIRED)

# Create executable
add_executable(${PROJECT_NAME} src/main.cpp
    src/core/tile.cpp
    src/core/grid.cpp
    src/views/window.cpp
    src/core/game.cpp
    src/views/tileView.cpp
    src/views/gridView.cpp
    src/views/gameObject.cpp
)

# Link SDL3
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3 SDL3_ttf::SDL3_ttf)

# Windows-specific libraries
if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE mingw32 -mwindows)
endif()

# Windows-specific settings
if(WIN32)
    # Hide console window for release builds
    set_target_properties(${PROJECT_NAME} PROPERTIES
        WIN32_EXECUTABLE ON
    )

    # Copy SDL3 DLL to output directory
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        /usr/x86_64-w64-mingw32/bin/SDL3.dll
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif()

# Copy SDL3_ttf DLL to output directory
if(WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        /usr/x86_64-w64-mingw32/bin/SDL3_ttf.dll
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif()

# Installation rules
install(TARGETS ${PROJECT_NAME} DESTINATION .)
install(FILES /usr/x86_64-w64-mingw32/bin/SDL3.dll DESTINATION . OPTIONAL)
