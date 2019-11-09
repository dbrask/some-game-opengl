project(SomeGame)
cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

set (CMAKE_CXX_STANDARD 20)

set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS         OFF) # ignore debug libs and
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

find_package(Boost)
find_package(OpenGL REQUIRED COMPONENTS OpenGL)
find_package(GLUT REQUIRED)

set(Boost_INCLUDE_DIRS ./boost)
set(Boost_LIBRARY_DIRS ./boost/lib)

add_executable(SomeGame src/main.cc src/Game.cc src/Config.cc)

target_link_libraries(SomeGame ${Boost_LIBRARY})
target_link_libraries(SomeGame OpenGL::OpenGL ${GLUT_LIBRARY} )
add_dependencies(SomeGame OpenGL::OpenGL)

include_directories(${GLUT_INCLUDE_DIRS} )
include_directories(${Boost_INCLUDE_DIRS})

add_subdirectory(src)
