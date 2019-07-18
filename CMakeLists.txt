# CMakeLists.txt for the ROOT test programs.
# This shows nicely how to compile and link applications
# using the ROOT libraries on all supported platforms.
#
# Author: Pere Mato, 25/10/2010
CMAKE_MINIMUM_REQUIRED(VERSION 3.09.0 FATAL_ERROR)
foreach(p
  CMP0025 # CMake 3.0
  CMP0028 # double colon for imported and alias targets
  CMP0042 # CMake 3.0
  CMP0054 # Only interpret ``if()`` arguments as variables or keywords when unquoted.
  )
  if(POLICY ${p})
  cmake_policy(SET ${p} NEW)
  endif()
endforeach()

project(MiniFair)
enable_language(Fortran)


SET(FAIRROOT_MAJOR_VERSION 18)
SET(FAIRROOT_MINOR_VERSION 2)
SET(FAIRROOT_PATCH_VERSION 0)


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")

    SET(FAIRROOT_LIBRARY_PROPERTIES ${FAIRROOT_LIBRARY_PROPERTIES}
        VERSION "${FAIRROOT_MAJOR_VERSION}"
        SOVERSION "${FAIRROOT_MAJOR_VERSION}"
        SUFFIX ".so"
    )

include(FairMacros)
include(FindROOT)
include(ROOTMacros)


set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/lib")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")

find_package2(PUBLIC ROOT VERSION 6.10.00 REQUIRED)


if(CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 5.0)
  set (CMAKE_CXX_STANDARD 11)
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

add_subdirectory(fairlogger)
add_subdirectory(base)
add_subdirectory(tools)

set(BASE_INCLUDE_DIRECTORIES 
${BASE_INCLUDE_DIRECTORIES}
${CMAKE_SOURCE_DIR}/
${CMAKE_SOURCE_DIR}/base
${CMAKE_SOURCE_DIR}/tools
)


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

set(setenvironment ENVIRONMENT PATH=${CMAKE_BINARY_DIR}/bin${cfgdir}:$ENV{PATH})

SetBasicVariables()

#GENERATE_BASH()


