cmake_minimum_required(VERSION 3.10)

# set the project name
project(TacticalRPGcpp VERSION 1.0)

# specify the C++ standard
# compiling this project using C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add compiler arguments (-Wall and -Wextra for warnings and -O3 for LVL3 optimizations)
add_compile_options(-Wall -Wextra -O3)

# get all *.cpp files recursively
# store them into a variable called "SOURCES"
file(GLOB_RECURSE SOURCES "src/*.cpp")

# add the executable with the files contained inside "SOURCES"
add_executable(TacticalRPGcpp ${SOURCES})

# add the binary tree to the search path for include files, which is the "include" directory
target_include_directories(TacticalRPGcpp PUBLIC
	${PROJECT_SOURCE_DIR}/include
)

# add the binary tree to the search path for libraries to link
target_link_directories(TacticalRPGcpp PUBLIC
	${PROJECT_SOURCE_DIR}/lib/linux
)

# add the libraries to the build
target_link_libraries(TacticalRPGcpp PUBLIC
	sfml-graphics
	sfml-window
	sfml-system
	sfml-audio
	pthread
)

# set the project output directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
