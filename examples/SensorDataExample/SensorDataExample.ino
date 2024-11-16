#include <SensorData.h>

SensorData<int> sensorData(10, 3); // 10 readings, 3 variables per reading

void setup() {
  Serial.begin(9600);

  while (!Serial) {
    delay(10);
  }
  Serial.println("Sensor Data Example");

  // Add readings
  int data1[] = {10, 20, 30};
  int data2[] = {15, 25, 35};
  sensorData.addReadings(data1);
  sensorData.addReadings(data2);

  // Get averages
  int* averages = sensorData.getAverage();
  Serial.println("Averages:");
  for (int i = 0; i < 3; i++) {
    Serial.println(averages[i]);
  }

  // Get last readings
  int* lastReadings = sensorData.getLastReadings();
  Serial.println("Last readings:");
  for (int i = 0; i < 3; i++) {
    Serial.println(lastReadings[i]);
  }
}

void loop() {
  // Add more readings in the loop as needed
}
