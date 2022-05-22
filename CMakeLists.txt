cmake_minimum_required(VERSION 3.5)

project(Cleaf)

set(LIBRARY_LINK_TYPE SHARED)

option(CLEAF_STATIC "Compile a static library" OFF)
if (CLEAF_STATIC)
	set(LIBRARY_LINK_TYPE STATIC)
	message("Compiling a static library")
endif()

include_directories(include)

file (GLOB_RECURSE cxx_files "src/**.cpp")
file (GLOB_RECURSE headers "include/**.h")

add_library(cleaf ${LIBRARY_LINK_TYPE} ${headers} ${cxx_files})
install(TARGETS cleaf DESTINATION /usr/lib)
install(DIRECTORY include/ DESTINATION include/cleaf)
