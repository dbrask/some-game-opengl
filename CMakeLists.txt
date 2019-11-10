project(SomeGame)
cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

set (CMAKE_CXX_STANDARD 20)

#set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
#set(Boost_USE_DEBUG_LIBS         OFF) # ignore debug libs and
#set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
#set(Boost_USE_MULTITHREADED      ON)
#set(Boost_USE_STATIC_RUNTIME    OFF)

#set(Boost_INCLUDE_DIR ./boost)
#set(Boost_LIBRARY_DIR ./boost/lib)

#set(GLFW3_INCLUDE_DIR ./glfw)
#set(GLFW3_LIBRARY_DIR ./glfw/include)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(glfw)
add_subdirectory(src)

#find_package(glfw3 3.3 REQUIRED)


#find_package(Boost REQUIRED)
find_package(OpenGL REQUIRED)
#find_package(GLUT REQUIRED)
#find_package(glad REQUIRED)


add_executable(SomeGame src/main.cc src/Game.cc src/Config.cc)

target_include_directories(SomeGame PUBLIC ${OPENGL_INCLUDE_DIR})
target_link_libraries(SomeGame ${OPENGL_gl_LIBRARY})
target_link_libraries(SomeGame ${OPENGL_glu_LIBRARY})
target_link_libraries(SomeGame glfw)

#target_link_libraries(SomeGame glfw)
#target_link_libraries(SomeGame ${GLFW3_LIBRARY})
#target_link_libraries(SomeGame ${Boost_LIBRARY})
#target_link_libraries(SomeGame OpenGL::OpenGL ${GLUT_LIBRARY} )

#add_dependencies(SomeGame OpenGL::OpenGL)


#include_directories(${GLFW3_LIBRARY_DIR})
#include_directories(${Boost_INCLUDE_DIRS})
#include_directories(${OPENGL_INCLUDE_DIRS})
