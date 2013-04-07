
set(WS2811_SOURCES
	ws2811_controller.cpp
	)

set(WS2811_HEADERS
	ws2811_8.h
	color_cycle.hpp
	water_torture.hpp
	chasers.hpp
	flares.hpp
	)


generate_arduino_firmware( ws2811 
	BOARD atmega328
	PORT /dev/ttyUSB0
	SRCS ${WS2811_SOURCES}
	HDRS ${WS2811_HEADERS}
	)