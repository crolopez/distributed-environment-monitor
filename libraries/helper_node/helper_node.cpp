#include <Arduino.h>
#include "helper_node.h"

// To try: casting from float to long, send said long, casting from long to float ...
void convert_float_to_binary(float value, char * binary_str) {
	float_as_byte fbytes;
	fbytes.fvalue = value;
		
	for (int i = 0; i < 4; i++) {
		byte bvalue = fbytes.bvalue[i];
		for (int j = 0; j < 8; j++ )
		{
			binary_str[j + i * 8] = (bvalue >> j) & 0X01 ? '1' : '0';
		}
	}
	
	  binary_str[32] = '\0';
}
