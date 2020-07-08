#include <rcswitch_wrapper.h>
#include <helper_node.h>
#include <DHT.h>

#define CONTROL_LED_PIN 11
#define RF_RT_PIN 10
#define DHT_PIN 2
#define DHT_TYPE DHT11

RCSwitchWrapper rcs_wrapper(RF_RT_PIN);
DHT dht(DHT_PIN, DHT_TYPE);
char binary_temp[32 + 1];

void setup() {
    Serial.begin(9600);
    
    pinMode(CONTROL_LED_PIN , OUTPUT); 
    dht.begin();
}

void loop() {
  delay(5000);  
  
  //turn_control_led(CONTROL_LED_PIN);

  // DHT11 does not have decimals. We add 0.47 to check this part.
  float temp = dht.readTemperature() + 0.47;

  if (isnan(temp)) {
    Serial.println("Error reading from DHT11");
    return;
  }

  print_temp(temp);

  convert_float_to_binary(temp, binary_temp);
  rcs_wrapper.send_binary_code(binary_temp);
}
