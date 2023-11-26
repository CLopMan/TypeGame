# General
cmake_minimum_required(VERSION 3.25)
project(TypeGame LANGUAGES CXX)
add_executable(TypeGame main.cpp game.cpp)

# Estandar
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Opciones de compilacion
add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors)

#include(FetchContent)

#Enable google test - por si me apetece hacer unittest
# FETCHCONTENT_DECLARE(
#         googletest
#         GIT_REPOSITORY https://github.com/google/googletest.git
#         GIT_TAG v1.14.0
# )
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# FETCHCONTENT_MAKEAVAILABLE(googletest)


# incluir todos los directorios de código
include_directories(PUBLIC .)

#enable_testing()
#add_subdirectory(utest)
