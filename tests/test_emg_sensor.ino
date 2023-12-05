void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // put your main code here, to run repeatedly:
  int sensorValueOne = analogRead(A1);
  int sensorValueTwo = analogRead(A0);

  Serial.println(sensorValueOne);
  
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltageOne = sensorValueOne * (5.0 / 1023.0);
  float voltageTwo = sensorValueTwo * (5.0 / 1023.0);


  Serial.println(voltageOne);
  Serial.println(voltageTwo);
  delay(0);
}