#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct  {
  float temperatureSensorReadings;
  float socSensorReadings;
} streamingDataFormat;

typedef struct  {
    float maximumValue;
    float minimumValue;
}sensorThresholdValues;

typedef struct  {
    int lengthOfArray;
    float* tempSensorValues;
    float* socSensorValues;
}sensorDataExtract;

float* checkAndFixInvalidValue(float sensorData[], int lengthOfSensorData, sensorThresholdValues thresoldValues);
streamingDataFormat* storeSensorData(float tempSensorValues[], float socSensorValues[], streamingDataFormat* streamingData, int lengthOfSensorValues);
void streamSenderData(streamingDataFormat streamingData[], void(*fpStreamingMediumFunction)(float, float), int lengthOfStreamingData);
int streamMainFunction(sensorDataExtract sensorsData, sensorThresholdValues tempthresoldValues, sensorThresholdValues socthresoldValues, void(*fpStreamingMediumFunction)(float, float));