cmake_minimum_required(VERSION 3.29)
project(cpp_26_fun)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_PREFIX_PATH "$ENV{CMAKE_PREFIX_PATH}")

if (WIN32)
    add_compile_definitions(_WIN32_WINNT=0x0501)
endif ()

#Grab generated lin called "src" from the subfolder so we can linked it to the main program
add_subdirectory(src)

#Create exe
add_executable(main main.cpp)

if (WIN32)
    target_link_libraries(main PUBLIC src wsock32 ws2_32)
endif ()



