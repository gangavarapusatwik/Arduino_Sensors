#include "dht.h"
#include <ArduinoJson.h>
#define dht_apin 3
dht DHT; // Creats a DHT object
int smokeA0 = A0;
int smokeA1 = A1;
int smokeA2 = A2;
int smokeA3 = A3;
int smokeA4 = A4;
int smokeA5 = A5;
float m = -0.318; //Slope 
float b = 1.133; //Y-Intercept 
float R0 = 11.820; //Sensor Resistance in fresh air from previous code
void setup() {
  pinMode(smokeA0, INPUT);
  pinMode(smokeA1, INPUT);
  pinMode(smokeA2, INPUT);
  pinMode(smokeA3, INPUT);
  pinMode(smokeA4, INPUT);
  pinMode(smokeA5, INPUT);
  Serial.begin(9600);
}

void loop() {

  float sensor_volt; //Define variable for sensor voltage 
  float RS_gas; //Define variable for sensor resistance  
  float ratio; //Define variable for ratio
  float sensorValue = analogRead(smokeA0); //Read analog values of sensor  
  sensor_volt = sensorValue*(5.0/1023.0); //Convert analog values to voltage
  RS_gas = ((5.0*10.0)/sensor_volt)-10.0; //Get value of RS in a gas
  ratio = RS_gas/R0;  // Get ratio RS_gas/RS_air
  double ppm_log0 = (log10(ratio)-b)/m; //Get ppm value in linear scale according to the the ratio value  
  double ppm0 = pow(10, ppm_log0); //Convert ppm value to log scale 
  double percentage0 = ppm0/10000; //Convert to percentage 
  /*Serial.print("METHANE_MQ4: ");
  Serial.print(sensorValue);
  Serial.print(";   PPM: ");
  Serial.print(ppm0);
  Serial.print(";   PERCENTAGE: ");
  Serial.println(percentage0);
*/
  
  
  float sensorValue1 = analogRead(smokeA1); //Read analog values of sensor  
  sensor_volt = sensorValue1*(5.0/1023.0); //Convert analog values to voltage
  RS_gas = ((5.0*10.0)/sensor_volt)-10.0; //Get value of RS in a gas
  ratio = RS_gas/R0;  // Get ratio RS_gas/RS_air
  double ppm_log1 = (log10(ratio)-b)/m; //Get ppm value in linear scale according to the the ratio value  
  double ppm1 = pow(10, ppm_log1); //Convert ppm value to log scale 
  double percentage1 = ppm1/10000; //Convert to percentage 
  /*Serial.print("ALCHOL_MQ3: ");
  Serial.print(sensorValue1);
  Serial.print(";   PPM: ");
  Serial.print(ppm1);
  Serial.print(";   PERCENTAGE: ");
  Serial.println(percentage1);
*/
  
 
  float sensorValue2 = analogRead(smokeA2); //Read analog values of sensor  
  sensor_volt = sensorValue2*(5.0/1023.0); //Convert analog values to voltage
  RS_gas = ((5.0*10.0)/sensor_volt)-10.0; //Get value of RS in a gas
  ratio = RS_gas/R0;  // Get ratio RS_gas/RS_air
  double ppm_log2 = (log10(ratio)-b)/m; //Get ppm value in linear scale according to the the ratio value  
  double ppm2 = pow(10, ppm_log2); //Convert ppm value to log scale 
  double percentage2 = ppm2/10000; //Convert to percentage 
  /*Serial.print("MQ135_AQ ");
  Serial.print(sensorValue2);
  Serial.print(";   PPM: ");
  Serial.print(ppm2);
  Serial.print(";   PERCENTAGE: ");
  Serial.println(percentage2);
  */
  
  
  float sensorValue3 = analogRead(smokeA3); //Read analog values of sensor  
  sensor_volt = sensorValue3*(5.0/1023.0); //Convert analog values to voltage
  RS_gas = ((5.0*10.0)/sensor_volt)-10.0; //Get value of RS in a gas
  ratio = RS_gas/R0;  // Get ratio RS_gas/RS_air
  double ppm_log3 = (log10(ratio)-b)/m; //Get ppm value in linear scale according to the the ratio value  
  double ppm3 = pow(10, ppm_log3); //Convert ppm value to log scale 
  double percentage3 = ppm3/10000; //Convert to percentage 
  /*Serial.print("SMOKE MQ2: ");
  Serial.print(sensorValue3);
  Serial.print(";   PPM: ");
  Serial.print(ppm3);
  Serial.print(";   PERCENTAGE: ");
  Serial.println(percentage3);
  */
  
  float sensorValue4 = analogRead(smokeA4); //Read analog values of sensor  
  sensor_volt = sensorValue4*(5.0/1023.0); //Convert analog values to voltage
  RS_gas = ((5.0*10.0)/sensor_volt)-10.0; //Get value of RS in a gas
  ratio = RS_gas/R0;  // Get ratio RS_gas/RS_air
  double ppm_log4 = (log10(ratio)-b)/m; //Get ppm value in linear scale according to the the ratio value  
  double ppm4 = pow(10, ppm_log4); //Convert ppm value to log scale 
  double percentage4 = ppm4/10000; //Convert to percentage 
  /*Serial.print("CO MQ7: ");
  Serial.print(sensorValue4);
  Serial.print(";   PPM: ");
  Serial.print(ppm4);
  Serial.print(";   PERCENTAGE: ");
  Serial.println(percentage4);
*/
  
  float sensorValue5 = analogRead(smokeA5); //Read analog values of sensor  
  sensor_volt = sensorValue5*(5.0/1023.0); //Convert analog values to voltage
  RS_gas = ((5.0*10.0)/sensor_volt)-10.0; //Get value of RS in a gas
  ratio = RS_gas/R0;  // Get ratio RS_gas/RS_air
  double ppm_log5 = (log10(ratio)-b)/m; //Get ppm value in linear scale according to the the ratio value  
  double ppm5 = pow(10, ppm_log5); //Convert ppm value to log scale 
  double percentage5 = ppm5/10000; //Convert to percentage 
  /*Serial.print("LPG_MQ9: ");
  Serial.print(sensorValue5);
  Serial.print(";  PPM: ");
  Serial.print(ppm5);
  Serial.print(";  PERCENTAGE: ");
  Serial.println(percentage5);
*/

  DHT.read11(dht_apin);
  /*Serial.print("Current humidity = ");
  Serial.print(DHT.humidity);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(DHT.temperature); 
  Serial.println("C  ");
*/

  
  DynamicJsonDocument doc(1024);
  doc["TEMPERATURE"] = DHT.temperature;
  doc["HUMIDITY"] = DHT.humidity;
  doc["METHANE_MQ4"] = ppm0;
  doc["ALCHOL_MQ3"] = ppm1;
  doc["MQ135_AQ"] = ppm2;
  doc["SMOKE MQ2"] = ppm3;
  doc["CO MQ7"] = ppm4;
  doc["LPG_MQ9"] = ppm5;
                        
  
  serializeJson(doc, Serial);
   Serial.println();
  delay(10000);
  
}
