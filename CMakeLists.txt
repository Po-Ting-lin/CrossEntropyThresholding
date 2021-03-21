cmake_minimum_required(VERSION 3.0.0)
project(CrossEntropyThreshold VERSION 0.1.0)

include(CTest)
enable_testing()

# c++17
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# Using AVX, AVX intrinsic set
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mavx")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mavx2")

# Using OpenMp 
find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

# Set the files
set(SOURCES
    EntropyThresholding/main.cpp
    EntropyThresholding/entropy_thresholding.cpp
    EntropyThresholding/entropy_thresholding.h
    EntropyThresholding/math_log.h
)

add_executable(CrossEntropyThreshold ${SOURCES})

# Using OpenCV Lib
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
target_link_libraries( CrossEntropyThreshold ${OpenCV_LIBS} )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
