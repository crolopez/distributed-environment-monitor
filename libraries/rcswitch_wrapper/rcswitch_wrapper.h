#ifndef RCSWIITCH_WRAPPER_H
#define RCSWIITCH_WRAPPER_H

#include <RCSwitch.h>

#define DIP_SWITCH_1 "11111"
#define DIP_SWITCH_2 "00010"
#define SEND_DELAY 500

class RCSwitchWrapper {
	private:
	RCSwitch mySwitch;

	public:
	RCSwitchWrapper(int rx_pin);

	void send_decimal_code(int code);
	void send_binary_code(const char * code);
	void send_hex_code(const char * code);

	void recv_block();

	
	void switch_on();
	void switch_off();
};

#endif