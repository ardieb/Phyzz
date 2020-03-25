CMAKE_MINIMUM_REQUIRED(VERSION 3.15 FATAL_ERROR)
PROJECT(Phyzz)

set(CMAKE_CXX_STANDARD 17)

# Add dear imgui includes
INCLUDE_DIRECTORIES(imgui)
INCLUDE_DIRECTORIES(imgui/impl/libs/gl3w/GL)
INCLUDE_DIRECTORIES(imgui/impl/libs/glfw)
INCLUDE_DIRECTORIES(imgui/impl/libs/glfw/include)
INCLUDE_DIRECTORIES(imgui/impl/libs/glfw/include/GLFW)
INCLUDE_DIRECTORIES(imgui/impl/libs/usynergy)
INCLUDE_DIRECTORIES(imgui/misc/cpp)
INCLUDE_DIRECTORIES(imgui/misc/freetype)
INCLUDE_DIRECTORIES(imgui/misc/single_file)

# Add Eigen3
INCLUDE_DIRECTORIES(Eigen)

SET(IMGUI_SOURCES
        imgui/impl/libs/gl3w/GL/gl3w.c
        imgui/impl/libs/gl3w/GL/gl3w.h
        imgui/impl/libs/gl3w/GL/glcorearb.h
        imgui/impl/libs/glfw/include/GLFW/glfw3.h
        imgui/impl/libs/glfw/include/GLFW/glfw3native.h
        imgui/impl/libs/usynergy/uSynergy.c
        imgui/impl/libs/usynergy/uSynergy.h
        imgui/impl/imgui_impl_allegro5.cpp
        imgui/impl/imgui_impl_allegro5.h
        imgui/impl/imgui_impl_dx10.cpp
        imgui/impl/imgui_impl_dx10.h
        imgui/impl/imgui_impl_dx11.cpp
        imgui/impl/imgui_impl_dx11.h
        imgui/impl/imgui_impl_dx12.cpp
        imgui/impl/imgui_impl_dx12.h
        imgui/impl/imgui_impl_dx9.cpp
        imgui/impl/imgui_impl_dx9.h
        imgui/impl/imgui_impl_glfw.cpp
        imgui/impl/imgui_impl_glfw.h
        imgui/impl/imgui_impl_glut.cpp
        imgui/impl/imgui_impl_glut.h
        imgui/impl/imgui_impl_marmalade.cpp
        imgui/impl/imgui_impl_marmalade.h
        imgui/impl/imgui_impl_metal.h
        imgui/impl/imgui_impl_metal.mm
        imgui/impl/imgui_impl_opengl2.cpp
        imgui/impl/imgui_impl_opengl2.h
        imgui/impl/imgui_impl_opengl3.cpp
        imgui/impl/imgui_impl_opengl3.h
        imgui/impl/imgui_impl_osx.h
        imgui/impl/imgui_impl_osx.mm
        imgui/impl/imgui_impl_sdl.cpp
        imgui/impl/imgui_impl_sdl.h
        imgui/impl/imgui_impl_vulkan.cpp
        imgui/impl/imgui_impl_vulkan.h
        imgui/impl/imgui_impl_win32.cpp
        imgui/impl/imgui_impl_win32.h
        imgui/misc/cpp/imgui_stdlib.cpp
        imgui/misc/cpp/imgui_stdlib.h
        imgui/misc/fonts/binary_to_compressed_c.cpp
        imgui/misc/freetype/imgui_freetype.cpp
        imgui/misc/freetype/imgui_freetype.h
        imgui/misc/single_file/imgui_single_file.h
        imgui/imconfig.h
        imgui/imgui.cpp
        imgui/imgui.h
        imgui/imgui_demo.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_internal.h
        imgui/imgui_widgets.cpp
        imgui/imstb_rectpack.h
        imgui/imstb_textedit.h
        imgui/imstb_truetype.h)

SET(PHYZZ_SOURCES
        src/App.cpp
        src/Main.cpp
        src/Toolkit/Solver.cpp
        src/Physics/Field.cpp
        src/Physics/PSimulation.cpp
        src/Logging/PLogger.cpp)

ADD_EXECUTABLE(Phyzz ${IMGUI_SOURCES} ${PHYZZ_SOURCES})

# Find spdlog for debugging
FIND_PACKAGE(spdlog)
TARGET_LINK_LIBRARIES(Phyzz spdlog::spdlog)




