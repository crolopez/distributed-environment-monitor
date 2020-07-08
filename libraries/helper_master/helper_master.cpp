#include <Arduino.h>
#include "helper_master.h"

void convert_binary_to_float(float * value, char * binary) {
	float_as_byte fbytes;
	fbytes.fvalue = 0;

	for (int i = 0; i < 32; i++) {
		fbytes.bvalue[i / 8] |= (binary[i] == '1' ? 1 : 0 ) << (i % 8);
	}
	
	*value = fbytes.fvalue;
	
	// print_bvalues(fbytes);
}

void convert_binary_to_float(float * value, unsigned long binary) {
	float_as_byte fbytes;
	fbytes.fvalue = 0;

	for (int i = 0; i < 32; i++) {
		fbytes.bvalue[(31 - i) / 8] |= ((binary >> i) & 0X01 == 0X01 ? 1 : 0 ) << ( (31 - i) % 8);
	}

	*value = fbytes.fvalue;
}


/*
void print_bvalues(float_as_byte fbytes) {
	Serial.println("\n******FBYTES****");
	Serial.print("\nFloat value: ");
	Serial.print(fbytes.fvalue);
	Serial.print("\nBytes: ");
	for (int i = 0; i < 4; i++) {
		Serial.print(fbytes.bvalue[i]);
		Serial.print("    ");
	}
	Serial.println("\n**********");
}
*/

void print_received_message(RCSwitch mySwitch) {
    Serial.print("Received: ");
    Serial.println(mySwitch.getReceivedValue());
}

void print_received_bit_length(RCSwitch mySwitch) {
    Serial.print("Received bit length: ");
    Serial.println(mySwitch.getReceivedBitlength());
}

void print_received_delay(RCSwitch mySwitch) {
    Serial.print("Received delay: ");
    Serial.println(mySwitch.getReceivedDelay());
}

void print_protocol(RCSwitch mySwitch) {
    Serial.print("Protocol: ");
    Serial.println(mySwitch.getReceivedProtocol());
}

void print_received_temp(RCSwitch mySwitch) {
    float temp;
    convert_binary_to_float(&temp, mySwitch.getReceivedValue());  
	print_temp(temp);
} 
