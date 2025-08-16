cmake_minimum_required(VERSION 3.20)
project(test_matrix LANGUAGES CXX)

# Ищем библиотеку (статическую или динамическую)
find_library(MATRIX_LIB
    NAMES 
        static-matrixlib 
        shared-matrixlib
    PATHS 
        "${CMAKE_CURRENT_SOURCE_DIR}/libs/matrixlib"
        "${CMAKE_CURRENT_SOURCE_DIR}/../lib/build/Release"
    NO_DEFAULT_PATH
    REQUIRED  # Прерывает сборку, если библиотека не найдена
)

if(NOT MATRIX_LIB)
    message(FATAL_ERROR "Matrix library not found! Tried paths: 
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/matrixlib
        ${CMAKE_CURRENT_SOURCE_DIR}/../lib/build/Release")
endif()

add_executable(test_matrix src/main.cpp)
target_link_libraries(test_matrix PRIVATE ${MATRIX_LIB})

# Для динамической библиотеки: копируем .dll
if(WIN32 AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/libs/matrixlib/shared-matrixlib.dll")
    add_custom_command(TARGET test_matrix POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
            "${CMAKE_CURRENT_SOURCE_DIR}/libs/matrixlib/shared-matrixlib.dll"
            $<TARGET_FILE_DIR:test_matrix>
    )
endif()