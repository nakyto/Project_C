set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

add_library(Sylphon SHARED Sylphon.c Sylphon.h)
#add_library(Sylphon STATIC arithmetic.c arithmetic.h)

set_target_properties (Sylphon
	PROPERTIES
		OUTPUT_NAME sylphon
)

add_executable(sylphon Sylphon.c)
add_dependencies(sylphon Sylphon)
target_link_libraries(sylphon Sylphon)

configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/sylphon.pc.in
	${CMAKE_CURRENT_BINARY_DIR}/sylphon.pc
	@ONLY
)
install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/sylphon.pc
	DESTINATION share/pkgconfig
	COMPONENT "PkgConfig"
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
	${CMAKE_CURRENT_SOURCE_DIR}/SylphonConfig.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/SylphonConfig.cmake
	INSTALL_DESTINATION cmake
)
install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/SylphonConfig.cmake
	DESTINATION cmake
)

install(
	TARGETS sylphon Sylphon 
	LIBRARY DESTINATION lib COMPONENT "Library"
	ARCHIVE DESTINATION lib COMPONENT "Library"
	RUNTIME DESTINATION bin COMPONENT "Runtime"
)

install(
	FILES sylphon.h
	DESTINATION include
	COMPONENT "Header"
)

find_package(Coverage)
enable_coverage()

find_package(HtmlCoverage)
enable_html_coverage()

