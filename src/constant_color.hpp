#ifndef _CONSTANT_COLOR_HPP_
#define _CONSTANT_COLOR_HPP_

#include "ws2811_8.h"

#include "string.h"

namespace constant_color
{


	template< uint8_t num_led, uint8_t num_sequence >
	void populate( ws2811::rgb (&led_array)[num_led], ws2811::rgb (&sequence)[num_sequence] )
	{
		uint16_t sequence_byte_length = num_sequence * sizeof( sequence[0] );
		uint16_t led_byte_length = num_led * sizeof( led_array[0] );
		ws2811::rgb* leds = led_array;

		while( sequence_byte_length < led_byte_length )
		{
			memcpy( leds, sequence, sequence_byte_length );

			led_byte_length -= sequence_byte_length;
			leds            += sequence_byte_length;
		}

		memcpy( leds, sequence, led_byte_length );
	}

	template< uint8_t num_led >
	void start( ws2811::rgb (&leds)[num_led], uint8_t channel )
	{
		ws2811::rgb sequence[] =
			{   
			   	ws2811::rgb( 255,   0,   0 ),
			   	ws2811::rgb( 255,   0,   0 ),
				ws2811::rgb( 255,   0,   0 ),
				ws2811::rgb(   0, 255,   0 ),
				ws2811::rgb(   0, 255,   0 ),
				ws2811::rgb(   0, 255,   0 ),
				ws2811::rgb(   0,   0, 255 ),
				ws2811::rgb(   0,   0, 255 ),
				ws2811::rgb(   0,   0, 255 )
			};

		populate( leds, sequence );

		send( leds, channel );
	}


}


#endif // _CONSTANT_COLOR_HPP_