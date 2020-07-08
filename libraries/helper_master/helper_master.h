#ifndef HELPER_MASTER_H
#define HELPER_MASTER_H

#include <RCSwitch.h>
#include <helper_common.h>

void convert_binary_to_float(float * value, char * binary);
void convert_binary_to_float(float * value, unsigned long binary);
// void print_bvalues(float_as_byte fbytes);


void print_received_message(RCSwitch mySwitch);
void print_received_bit_length(RCSwitch mySwitch);
void print_received_delay(RCSwitch mySwitch);
void print_protocol(RCSwitch mySwitch);
void print_received_temp(RCSwitch mySwitch);

#endif
