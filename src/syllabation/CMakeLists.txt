set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

add_library(Syllabation SHARED syllabation.c syllabation.h)
#add_library(arithmeticStatic STATIC arithmetic.c arithmetic.h)

set_target_properties (Syllabation
	PROPERTIES
		OUTPUT_NAME syllabation
)

add_executable(syllabation syllabation.c)
add_dependencies(syllabation Syllabation)
target_link_libraries(syllabation Syllabation)

configure_file(
	${CMAKE_CURRENT_SOURCE_DIR}/syllabation.pc.in
	${CMAKE_CURRENT_BINARY_DIR}/syllabation.pc
	@ONLY
)
install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/syllabation.pc
	DESTINATION share/pkgconfig
	COMPONENT "PkgConfig"
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
	${CMAKE_CURRENT_SOURCE_DIR}/SyllabationConfig.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/SyllabationConfig.cmake
	INSTALL_DESTINATION cmake
)
install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/SyllabationConfig.cmake
	DESTINATION cmake
)

install(
	TARGETS syllabation Syllabation 
	LIBRARY DESTINATION lib COMPONENT "Library"
	ARCHIVE DESTINATION lib COMPONENT "Library"
	RUNTIME DESTINATION bin COMPONENT "Runtime"
)

install(
	FILES syllabation.h
	DESTINATION include
	COMPONENT "Header"
)

find_package(Coverage)
enable_coverage()

find_package(HtmlCoverage)
enable_html_coverage()

