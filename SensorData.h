#ifndef SENSORDATA_H
#define SENSORDATA_H

// Template class to handle sensor data storage and analysis
template <typename T>
class SensorData {
  private:
    int max_readings; // Maximum number of readings
    int num_variables; // Number of variables per reading
    T** data; // 2D array to store readings
    int index; // Current index for new readings
    int count; // Total number of readings stored

  public:
    // Constructor: Allocates memory for the data array
    SensorData(int maxReadings, int numVariables)
        : max_readings(maxReadings), num_variables(numVariables), index(0), count(0) {
        data = new T*[max_readings];
        for (int i = 0; i < max_readings; ++i) {
            data[i] = new T[num_variables]();
        }
    }

    // Destructor: Frees allocated memory
    ~SensorData() {
        for (int i = 0; i < max_readings; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Adds a single value to the specified variable index in the current reading
    void addReading(int variableIndex, T value) {
        if (variableIndex >= 0 && variableIndex < num_variables) {
            data[index][variableIndex] = value;
        }
    }

    // Adds a full set of values for a single reading
    void addReadings(T values[]) {
        for (int i = 0; i < num_variables; ++i) {
            data[index][i] = values[i];
        }
        index = (index + 1) % max_readings; // Wrap around if max readings exceeded
        if (count < max_readings) count++;
    }

    // Calculates and returns the average for all variables
    T* getAverage() const {
        if (count == 0) return nullptr;
        T* average = new T[num_variables]();
        for (int i = 0; i < count; ++i) {
            for (int j = 0; j < num_variables; ++j) {
                average[j] += data[i][j];
            }
        }
        for (int i = 0; i < num_variables; ++i) {
            average[i] /= count;
        }
        return average;
    }

    // Returns the last reading
    T* getLastReadings() const {
        if (count == 0) return nullptr;
        return data[(index + max_readings - 1) % max_readings];
    }
};

#endif
