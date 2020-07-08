#ifndef HELPER_COMMON_H
#define HELPER_COMMON_H

typedef union float_as_byte {
    float fvalue;
    byte bvalue[4];
} float_as_byte;

void turn_led(const int led);
void turn_control_led(const int led_pin);
void print_temp(const float temp);

#endif