include_directories(
	include
	${PROJECT_INCLUDE_DIR}
	)

file(GLOB SOURCE *.c)
add_library(dng_fibbonaci_i SHARED ${SOURCE})

set(FIBBONACI_INC ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE)
