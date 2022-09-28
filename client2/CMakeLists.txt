# CMakeList.txt : CMake project for client2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (client2 "client2.cpp" "client2.h")

# TODO: Add tests and install targets if needed.
 target_include_directories(client2 PUBLIC include)

 set_property(TARGET client2 PROPERTY ENABLE_EXPORTS 1)
	
enable_testing()