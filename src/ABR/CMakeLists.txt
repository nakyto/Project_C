set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

add_library(Abr SHARED ABR.c ABR-doc.h)
#add_library(AbrStatic STATIC  ABR.c ABR-doc.h)

set_target_properties (Abr
	PROPERTIES
		OUTPUT_NAME abr
)

add_executable(ABR ABR.c)
add_dependencies(ABR Abr)
target_link_libraries(ABR Abr)
#target_link_libraries(gcd arithmetic arithmeticStatic)

configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/ABR.pc.in
	${CMAKE_CURRENT_BINARY_DIR}/ABR.pc
	@ONLY
)
install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/ABR.pc
	DESTINATION share/pkgconfig
	COMPONENT "PkgConfig"
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
	${CMAKE_CURRENT_SOURCE_DIR}/AbrConfig.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/AbrConfig.cmake
	INSTALL_DESTINATION cmake
)
install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/AbrConfig.cmake
	DESTINATION cmake
)

install(
	TARGETS ABR Abr 
	LIBRARY DESTINATION lib COMPONENT "Library"
	ARCHIVE DESTINATION lib COMPONENT "Library"
	RUNTIME DESTINATION bin COMPONENT "Runtime"
)

install(
	FILES ABR-doc.h
	DESTINATION include
	COMPONENT "Header"
)

find_package(Coverage)
enable_coverage()

find_package(HtmlCoverage)
enable_html_coverage()

