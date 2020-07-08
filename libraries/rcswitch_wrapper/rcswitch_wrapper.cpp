#include "rcswitch_wrapper.h"
#include <helper_node.h>

RCSwitchWrapper::RCSwitchWrapper(int rx_pin) {
	mySwitch = RCSwitch();
	mySwitch.enableTransmit(rx_pin);
}

void RCSwitchWrapper::send_decimal_code(int code) {
	mySwitch.send(code, 24);
	delay(SEND_DELAY);  
};

void RCSwitchWrapper::send_binary_code(const char * code) {
	mySwitch.send(code);
	delay(SEND_DELAY);  
}

void RCSwitchWrapper::send_hex_code(const char * code) {
	mySwitch.sendTriState(code);
	delay(SEND_DELAY);  
}

void RCSwitchWrapper::switch_on() {
	mySwitch.switchOn(DIP_SWITCH_1, DIP_SWITCH_2);
	delay(SEND_DELAY);
}

void RCSwitchWrapper::switch_off() {
	mySwitch.switchOff(DIP_SWITCH_1, DIP_SWITCH_2);
	delay(SEND_DELAY);
}

