cmake_minimum_required(VERSION 3.5)
project(pendu C)

set(CMAKE_C_STANDARD 11)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

add_executable(pendu pendu.c dico.c stats.c)

if(MSVC)
    target_compile_options(pendu PRIVATE
            /W4
            /WX
            /wd4996
            $<$<CONFIG:Debug>:/Od>
            $<$<CONFIG:Release>:/O2>
    )
    target_compile_definitions(pendu PRIVATE
            _CRT_SECURE_NO_WARNINGS
    )
    target_link_options(pendu PRIVATE $<$<CONFIG:Debug>:/INCREMENTAL:NO>)
    target_compile_definitions(pendu PRIVATE $<$<CONFIG:Debug>:_CRTDBG_MAP_ALLOC>)
else()
    target_compile_options(pendu PRIVATE
            -Wall
            -Wextra
            -pedantic
            -Werror
            $<$<CONFIG:Debug>:-O0 -g>
            $<$<CONFIG:Release>:-O3>
    )
endif()

configure_file(${CMAKE_SOURCE_DIR}/dico.txt ${CMAKE_BINARY_DIR}/dico.txt COPYONLY)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(WIN32)
    find_program(DR_MEMORY "drmemory.exe")
    if(DR_MEMORY)
        add_custom_target(run_drmemory
                COMMAND ${DR_MEMORY} -- $<TARGET_FILE:pendu>
                DEPENDS pendu
                WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
                COMMENT "Running Dr. Memory..."
        )
    endif()
endif()