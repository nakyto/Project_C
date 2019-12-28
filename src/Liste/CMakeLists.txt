set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

add_library(ListePrio SHARED listePrio.c listePrio.h)
#add_library(arithmeticStatic STATIC listePrio.c listePrio.h)

set_target_properties (ListePrio
	PROPERTIES
		OUTPUT_NAME listePrio
)

add_executable(listePrio listePrio.c)
add_dependencies(listePrio ListePrio)
target_link_libraries(listePrio ListePrio)

configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/listePrio.pc.in
	${CMAKE_CURRENT_BINARY_DIR}/listePrio.pc
	@ONLY
)
install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/listePrio.pc
	DESTINATION share/pkgconfig
	COMPONENT "PkgConfig"
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
	${CMAKE_CURRENT_SOURCE_DIR}/ListeConfig.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/ListeConfig.cmake
	INSTALL_DESTINATION cmake
)
install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/ListeConfig.cmake
	DESTINATION cmake
)

install(
	TARGETS listePrio ListePrio
	LIBRARY DESTINATION lib COMPONENT "Library"
	ARCHIVE DESTINATION lib COMPONENT "Library"
	RUNTIME DESTINATION bin COMPONENT "Runtime"
)

install(
	FILES listePrio.h
	DESTINATION include
	COMPONENT "Header"
)

find_package(Coverage)
enable_coverage()

find_package(HtmlCoverage)
enable_html_coverage()

