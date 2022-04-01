cmake_minimum_required(VERSION 3.20.2)

project(cpp_clean_code_training
  VERSION 0.1.0
  DESCRIPTION "Personal toy project  for the clean code training."
  LANGUAGES CXX
  )

set(CMAKE_CXX_STANDARD 17)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
include(GNUInstallDirs)

# Target names
set(target_name_obj_lib ${PROJECT_NAME}.o)
set(target_prefix_example ${PROJECT_NAME}.e)
set(target_prefix_test ${PROJECT_NAME}.t)

# Source file globing
file(GLOB_RECURSE source_files_hpp 
  LIST_DIRECTORIES false
  CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp
  )
file(GLOB_RECURSE source_files_cpp 
  LIST_DIRECTORIES false
  CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
  )
file(GLOB_RECURSE source_files_test_main_cpp 
  LIST_DIRECTORIES false
  CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/test/app/*.cpp
  )
file(GLOB_RECURSE source_files_example_main_cpp 
  LIST_DIRECTORIES false
  CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/example/*.cpp
  )

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/include
  PREFIX "include (public)"
  FILES ${source_files_hpp}
  )
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/src
  PREFIX src
  FILES ${source_files_cpp}
  )

# Stage: Build
add_library(${target_name_obj_lib} OBJECT)
set_target_properties(${target_name_obj_lib} PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(${target_name_obj_lib}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_BINDIR}>
  )
target_sources(${target_name_obj_lib}
  PRIVATE
    ${source_files_cpp}
    ${source_files_hpp}
  )

foreach(file ${source_files_example_main_cpp})
  get_filename_component(basename ${file} NAME_WE)
  set(target_name ${target_prefix_example}.${basename})
  add_executable(${target_name})
  target_link_libraries(${target_name} PRIVATE ${target_name_obj_lib} )
  target_sources(${target_name} PRIVATE ${file})

  list(APPEND targets_example ${target_name})
endforeach()
