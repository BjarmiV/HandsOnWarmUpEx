const int sensorPin = A0; //there is something wrong with the sensor value temperature sensor is not working as it should....
const float baselineTemp = 25.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for(int pinNumber = 6; pinNumber<9; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
int sensorVal = analogRead(sensorPin);
Serial.print("Sensor Value: ");
Serial.print(sensorVal);
Serial.println();
delay(1000);
float voltage = (sensorVal/1024.0)*5.0;
Serial.print("Volts: ");
Serial.print(voltage);
Serial.println();

Serial.print("Degrees C: ");
float temperature = (voltage-0.5)*100;
Serial.print(temperature);
Serial.println();

if(temperature < baselineTemp){
digitalWrite(6, LOW);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
}else if(temperature >= baselineTemp+2 &&
temperature < baselineTemp+4){
digitalWrite(6, HIGH);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
}else if(temperature >= baselineTemp+4 &&
temperature < baselineTemp+6){
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
digitalWrite(8, LOW);
}else if(temperature >= baselineTemp+6){
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
}
delay(1);

}
