cmake_minimum_required(VERSION 3.0.0)
project(Homework VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Homework main.cpp MyString.cpp Vehicle.cpp VehicleAllocator.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address,undefined") 

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
