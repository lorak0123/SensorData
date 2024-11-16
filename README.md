# SensorData Library

This library provides an efficient way to store, manage, and analyze multi-variable sensor data. It supports:
- Adding individual values or sets of variable readings.
- Calculating averages.
- Retrieving the last recorded readings.

## Installation

1. Download the library as a ZIP file.
2. Open Arduino IDE.
3. Go to **Sketch > Include Library > Add .ZIP Library...**.
4. Select the downloaded ZIP file.

## Usage

See the example in the `examples/SensorDataExample` folder for usage details.

## API

### Class: `SensorData<T>`
- **Constructor:** `SensorData(int maxReadings, int numVariables)`
- **Methods:**
  - `void addReading(int variableIndex, T value)`
  - `void addReadings(T values[])`
  - `T* getAverage() const`
  - `T* getLastReadings() const`

### Example

```cpp
SensorData<int> sensorData(10, 3);
int data[] = {10, 20, 30};
sensorData.addReadings(data);
int* averages = sensorData.getAverage();
// Use averages...
delete[] averages;
```