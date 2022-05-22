cmake_minimum_required(VERSION 3.5)

project(Cleaf)

set(LIBRARY_LINK_TYPE SHARED)
set(CLEAF_ADDITIONAL_LIBRARIES "")

find_library(
	LEAFCORE_LIB leafcore
)

if(${LEAFCORE_LIB} STREQUAL "LEAFCORE_LIB-NOTFOUND")
    message(FATAL_ERROR "Couldn't find the 'leafcore' library")
endif()

option(CLEAF_STATIC "Compile a static library" OFF)
if (CLEAF_STATIC)
	set(LIBRARY_LINK_TYPE STATIC)
	message("Compiling a static library")
endif()

if (${CMAKE_CXX_COMPILER_ID} MATCHES "GNU")
	message("Forcing the GNU compiler to link against stdc++fs")
	set(CLEAF_ADDITIONAL_LIBRARIES ${LEAF_ADDITIONAL_LIBRARIES} stdc++fs)
endif()

include_directories(include)
include_directories(Log/include)

add_subdirectory(Log)

file (GLOB_RECURSE cxx_files "src/**.cpp")
file (GLOB_RECURSE headers "include/**.h")

add_library(cleaf ${LIBRARY_LINK_TYPE} ${headers} ${cxx_files})
target_link_libraries(cleaf PRIVATE ${LEAFCORE_LIB} log ${CLEAF_ADDITIONAL_LIBRARIES})
install(TARGETS cleaf DESTINATION /usr/lib)
install(DIRECTORY include/ DESTINATION include/cleaf)
