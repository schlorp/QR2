cmake_minimum_required(VERSION 3.20)
project(QR2)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/qrmethods.cpp
    libs/qrcodegenerator/src/qrcodegen.cpp
    libs/tinyfiledialogs/src/tinyfiledialogs.c
    src/draggablepanel.cpp
    src/qrpanel.cpp
    src/customtextinputbox.cpp
    src/app.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
    src                     # for qrmethods.h and qrpanel.h
    libs/raylib/include     # raylib.h, raymath.h, rlgl.h
    libs/raygui/include     # raygui.h
    libs/qrcodegenerator/include      # qrcodegen.h
    libs/tinyfiledialogs/include     # tinyfiledialogs.h
)

target_link_directories(${PROJECT_NAME} PRIVATE
    libs/raylib/lib
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    raylib          # links raylib.lib
    winmm           # Windows multimedia (required by raylib)
    gdi32           # Windows GDI (required by raylib)
    opengl32        # OpenGL (required by raylib)
)

# Copy resources folder next to the executable after build
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/resources
    $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources
)