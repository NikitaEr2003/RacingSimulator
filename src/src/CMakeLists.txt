file(GLOB SOURCES *.cpp )

add_executable(Simulator ${SOURCES})

target_include_directories(Simulator PRIVATE ./include)
