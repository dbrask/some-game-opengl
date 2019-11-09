project(Hello_Universe)
cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS         OFF) # ignore debug libs and
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

set(Boost_INCLUDE_DIR ./boost_1_71_0)
set(Boost_LIBRARY_DIR /usr/local/src/boost_1_71_1/lib)

find_package(Boost 1.71.0 REQUIRED)
find_package(OpenGL REQUIRED COMPONENTS OpenGL)
find_package(GLUT REQUIRED)

include_directories(${GLUT_INCLUDE_DIRS} )
include_directories(${Boost_INCLUDE_DIRS})

add_executable(Hello_Universe main.cc
                                Game.cc)

add_dependencies(Hello_Universe OpenGL::OpenGL)
target_link_libraries(Hello_Universe ${Boost_LIBRARIES})
target_link_libraries(Hello_Universe OpenGL::OpenGL ${GLUT_LIBRARY} )
