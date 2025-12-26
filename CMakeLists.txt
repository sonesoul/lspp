set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories("include")
project ("lspp")

file (GLOB_RECURSE SRC_FILES 
	"include/*.h"
	"include/*.hpp"
	"src/*.cpp")

add_executable (lspp ${SRC_FILES})