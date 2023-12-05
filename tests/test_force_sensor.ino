int forceSensor = A0; // The fsr and 10K pulldown are connected to A0
int sensorReading;

void setup() {
    Serial.begin(9600);
}

void loop() {
    sensorReading = analogRead(A0);

    Serial.print("Analog reading = ");
    Serial.print(sensorReading); // The raw analog reading

    // We'll have a few threshholds, qualitatively determined
    if (sensorReading < 25) {
    Serial.println(" - No pressure");
    } 
    else if (sensorReading < 100) {
        Serial.println(" - Light touch");
    } 
    else if (sensorReading < 300) {
        Serial.println(" - Light squeeze");
    } 
    else if (sensorReading < 600) {
        Serial.println(" - Medium squeeze");
    } 
    else if (sensorReading < 1000) {
        Serial.println(" - Big squeeze");
    }

    delay(1000);
}