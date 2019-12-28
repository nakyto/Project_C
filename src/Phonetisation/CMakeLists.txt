set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

add_library(Phonetisation SHARED phonetisation.c phonetisation.h)
#add_library(phonetisation STATIC arithmetic.c arithmetic.h)

set_target_properties (Phonetisation
	PROPERTIES
		OUTPUT_NAME phonetisation
)

add_executable(phonetisation phonetisation.c)
add_dependencies(phonetisation Phonetisation)
target_link_libraries(phonetisation Phonetisation )

configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/phonetisation.pc.in
	${CMAKE_CURRENT_BINARY_DIR}/phonetisation.pc
	@ONLY
)
install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/phonetisation.pc
	DESTINATION share/pkgconfig
	COMPONENT "PkgConfig"
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
	${CMAKE_CURRENT_SOURCE_DIR}/PhonetisationConfig.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/PhonetisationConfig.cmake
	INSTALL_DESTINATION cmake
)
install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/PhonetisationConfig.cmake
	DESTINATION cmake
)

install(
	TARGETS phonetisation Phonetisation 
	LIBRARY DESTINATION lib COMPONENT "Library"
	ARCHIVE DESTINATION lib COMPONENT "Library"
	RUNTIME DESTINATION bin COMPONENT "Runtime"
)

install(
	FILES arithmetic.h
	DESTINATION include
	COMPONENT "Header"
)

find_package(Coverage)
enable_coverage()

find_package(HtmlCoverage)
enable_html_coverage()

