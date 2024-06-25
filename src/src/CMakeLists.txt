file(GLOB SOURCES *.cpp )
add_executable(Simulator ${SOURCES})

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc -static-libstdc++")
endif()

target_include_directories(Simulator PRIVATE ./include)