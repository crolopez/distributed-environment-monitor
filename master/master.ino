#include <helper_master.h>

#define CONTROL_LED_PIN 16 // D0
#define RF_RX_PIN 0 // D3

RCSwitch mySwitch = RCSwitch();

void setup() {
    Serial.begin(115200);
    
    mySwitch.enableReceive(RF_RX_PIN); 
     
    pinMode(CONTROL_LED_PIN, OUTPUT); 
    digitalWrite(CONTROL_LED_PIN, LOW); 
    delay(1000);         
    turn_led(CONTROL_LED_PIN);
    
    Serial.println("\nStarting");
}

void loop() {
    if (mySwitch.available()) {
        process_message();
    }
}

void process_message() {
    Serial.println("-------------");
    print_received_message(mySwitch);
    print_received_bit_length(mySwitch);
    print_received_delay(mySwitch);
    print_protocol(mySwitch);
    print_received_temp(mySwitch);
    
    mySwitch.resetAvailable();
    turn_led(CONTROL_LED_PIN);
}
