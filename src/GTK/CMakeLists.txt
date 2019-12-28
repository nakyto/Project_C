set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

add_library(Gtk SHARED gtk.c)
#add_library(RimeStatic STATIC rime.c Rime.h)

set_target_properties (Gtk
	PROPERTIES
		OUTPUT_NAME gtk
)

add_executable(gtk gtk.c)
add_dependencies(gtk Gtk)
target_link_libraries(gtk Gtk)
#target_link_libraries(gcd arithmetic arithmeticStatic)

configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/gtk.pc.in
	${CMAKE_CURRENT_BINARY_DIR}/gtk.pc
	@ONLY
)
install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/gtk.pc
	DESTINATION share/pkgconfig
	COMPONENT "PkgConfig"
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
	${CMAKE_CURRENT_SOURCE_DIR}/GtkConfig.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/GtkConfig.cmake
	INSTALL_DESTINATION cmake
)
install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/GtkConfig.cmake
	DESTINATION cmake
)

install(
	TARGETS gtk Gtk
	LIBRARY DESTINATION lib COMPONENT "Library"
	ARCHIVE DESTINATION lib COMPONENT "Library"
	RUNTIME DESTINATION bin COMPONENT "Runtime"
)

install(
	FILES gtk.h
	DESTINATION include
	COMPONENT "Header"
)

find_package(Coverage)
enable_coverage()

find_package(HtmlCoverage)
enable_html_coverage()

