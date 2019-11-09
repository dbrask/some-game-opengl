project(some-game)
cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

set (CMAKE_CXX_STANDARD 20)

set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS         OFF) # ignore debug libs and
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

#set(Boost_INCLUDE_DIR ./boost_1_71_0)
set(Boost_INCLUDE_DIR ./boost/)
set(Boost_LIBRARY_DIR ./boost/lib)

find_package(Boost)
find_package(OpenGL REQUIRED COMPONENTS OpenGL)
find_package(GLUT REQUIRED)

include_directories(${GLUT_INCLUDE_DIRS} )
include_directories(${Boost_INCLUDE_DIRS})

add_executable(some-game main.cc
                         Game.cc)

add_dependencies(some-game OpenGL::OpenGL)
target_link_libraries(some-game ${Boost_LIBRARIES})
target_link_libraries(some-game OpenGL::OpenGL ${GLUT_LIBRARY} )
