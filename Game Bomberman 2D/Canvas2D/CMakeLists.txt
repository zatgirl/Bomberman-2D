cmake_minimum_required(VERSION 3.20)
project(gl_1_canvasGlut)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(include/GL)
include_directories(src)

add_executable(gl_1_canvasGlut
        include/GL/freeglut.h
        include/GL/freeglut_ext.h
        include/GL/freeglut_std.h
        include/GL/glut.h
        src/Bola.h
        src/Botao.h
        src/gl_canvas2d.cpp
        src/gl_canvas2d.h
        src/main.cpp
        src/Relogio.cpp
        src/Relogio.h
        src/Vector2.h)
