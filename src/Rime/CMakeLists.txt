set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

add_library(Rime SHARED rime-doc.c Rime.h)
#add_library(RimeStatic STATIC rime.c Rime.h)

set_target_properties (Rime
	PROPERTIES
		OUTPUT_NAME rime
)

add_executable(rime-doc rime-doc.c)
add_dependencies(rime-doc Rime)
target_link_libraries(rime-doc Rime)
#target_link_libraries(gcd arithmetic arithmeticStatic)

configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/Rime.pc.in
	${CMAKE_CURRENT_BINARY_DIR}/Rime.pc
	@ONLY
)
install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/Rime.pc
	DESTINATION share/pkgconfig
	COMPONENT "PkgConfig"
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
	${CMAKE_CURRENT_SOURCE_DIR}/RimeConfig.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/RimeConfig.cmake
	INSTALL_DESTINATION cmake
)
install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/RimeConfig.cmake
	DESTINATION cmake
)

install(
	TARGETS rime-doc Rime 
	LIBRARY DESTINATION lib COMPONENT "Library"
	ARCHIVE DESTINATION lib COMPONENT "Library"
	RUNTIME DESTINATION bin COMPONENT "Runtime"
)

install(
	FILES rime.h
	DESTINATION include
	COMPONENT "Header"
)

find_package(Coverage)
enable_coverage()

find_package(HtmlCoverage)
enable_html_coverage()

