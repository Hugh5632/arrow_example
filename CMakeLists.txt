cmake_minimum_required(VERSION 3.15)
project(arrow_test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Release)

set(INC_DIR /usr/include
        /usr/local/include)
set(LINK_DIR /usr/lib64
        /usr/local/lib)
find_package(Arrow REQUIRED)

option(ARROW_LINK_SHARED "Link to the Arrow shared library" ON)
add_executable(arrow_test main.cc)
include_directories(${INC_DIR})
link_directories(${LINK_DIR})

if (ARROW_LINK_SHARED)
    target_link_libraries(arrow_test PRIVATE arrow_shared libparquet.so)
else()
    set(THREADS_PREFER_PTHREAD_FLAG ON)
    find_package(Threads REQUIRED)
    target_link_libraries(arrow_test PRIVATE arrow_static Threads::Threads libparquet.so)
endif()