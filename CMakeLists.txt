cmake_minimum_required(VERSION 3.0)
SET(PROJECT_NAME DNG)

#set project
project(${PROJECT_NAME})

#variables for directories
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_CXX_DIR ${PROJECT_SOURCE_DIR}/src)
set(PROJECT_MODULES_DIR ${PROJECT_SOURCE_DIR}/modules)

if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please make a build directory" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
  message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
  message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()

#compiler flags
SET(CMAKE_CXX_FLAGS "-std=c++14")

if(CMAKE_COMPILER_IS_GNUCXX)
add_definitions(
  -g
  -Wall
)
endif()

#git is used to download glm
find_package(PkgConfig REQUIRED)

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
#add unix macros
add_definitions(-D_UNIX)

elseif()
endif()



add_subdirectory(${PROJECT_MODULES_DIR})
add_subdirectory(${PROJECT_CXX_DIR})

include_directories(
	${PROJECT_INCLUDE_DIR}
	${FIBBONACI_INC}
)

get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
	  message(STATUS "dir='${dir}'")
endforeach()

add_executable(${PROJECT_NAME} ${MAIN_SOURCE})
target_link_libraries(${PROJECT_NAME} dl)
