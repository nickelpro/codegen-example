cmake_minimum_required(VERSION 4.0)

project(codegen-example LANGUAGES CXX)

add_executable(codegenerator)

target_sources(codegenerator
  PRIVATE
    codegenerator.cpp
)

add_custom_command(
  OUTPUT generated.cpp generated.hpp
  COMMAND codegenerator generated
  DEPENDS codegenerator
  VERBATIM
)

add_library(generated OBJECT)
target_sources(generated
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/generated.cpp
  INTERFACE
    FILE_SET HEADERS
    BASE_DIRS
      ${CMAKE_CURRENT_BINARY_DIR}
    FILES
      ${CMAKE_CURRENT_BINARY_DIR}/generated.hpp
)

add_executable(main)
target_sources(main
  PRIVATE
    main.cpp

  PRIVATE
    FILE_SET HEADERS
    BASE_DIRS
      non-generated
)
target_link_libraries(main
  PRIVATE
    generated
)

enable_testing()
add_test(NAME main COMMAND main)
