cmake_minimum_required(VERSION 2.8.9)
project (mpeg7fex)

find_package(OpenCV 3.1.0 EXACT REQUIRED PATHS dependencies)
file(GLOB AddressLib_SRCS AddressLib/*.c AddressLib/*.h)
file(GLOB Descriptors_SRCS Descriptors/*.cpp Descriptors/*.h)
file(GLOB Extraction_SRCS Extraction/*.cpp Extraction/*.h Extraction/*.c)
file(GLOB SRCS *.cpp *.h test/*.cpp test/*.h)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

include_directories(.)
include_directories(dependencies/include)
link_directories(dependencies/lib)

add_executable(mpeg7fex ${SRCS} ${AddressLib_SRCS} ${Descriptors_SRCS} ${Extraction_SRCS})
target_link_libraries(mpeg7fex ${OpenCV_LIBS})
