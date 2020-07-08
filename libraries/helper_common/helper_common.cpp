#include <Arduino.h>
#include "helper_common.h"
 
void turn_led(const int led) {
    digitalWrite(led, HIGH);
    delay(1000);         
    digitalWrite(led, LOW); 
    delay(500);         
}

void turn_control_led(const int led_pin) {
	static bool led_state = false;
	
	led_state = !led_state;
	digitalWrite(led_pin , led_state ? HIGH : LOW);  
}

void print_temp(const float temp) {
	  Serial.print("Temperature: ");
	  Serial.print(temp);
	  Serial.println(" *C ");
}
