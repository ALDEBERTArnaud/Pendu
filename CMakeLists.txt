cmake_minimum_required(VERSION 3.5)
project(pendu C)

set(CMAKE_C_STANDARD 99)

add_executable(pendu pendu.c dico.c stats.c)

if(MSVC)
    target_compile_options(pendu PRIVATE /W4 /WX)
else()
    target_compile_options(pendu PRIVATE -Wall -Wextra -pedantic)
endif()

configure_file(dico.txt dico.txt COPYONLY)
