cmake_minimum_required(VERSION 2.8.9)
project(chicony-ir-toggle)

configure_file(
    ${PROJECT_SOURCE_DIR}/system/99-ir-led.rules.cmake
    ${PROJECT_BINARY_DIR}/system/99-ir-led.rules
)
configure_file(
    ${PROJECT_SOURCE_DIR}/system/ir-led.sh.cmake
    ${PROJECT_BINARY_DIR}/system/ir-led.sh
)


add_executable(${PROJECT_NAME} main.c)

install(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION bin)

install(FILES ${PROJECT_BINARY_DIR}/system/99-ir-led.rules
		DESTINATION /lib/udev/rules.d/)
install(PROGRAMS ${PROJECT_BINARY_DIR}/system/ir-led.sh
		DESTINATION /lib/systemd/system-sleep)
