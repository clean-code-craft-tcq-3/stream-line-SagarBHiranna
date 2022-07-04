#include "sender.h"

void displayOnConsole(float tempData, float socData)
{
    printf("{  tempData = %.2f , socData = %.2f  }\n", tempData, socData);
}

float* checkAndFixInvalidValue(float sensorData[], int lengthOfSensorData, sensorThresholdValues thresoldValues)
{
    for (int sensorValueIter = 0; sensorValueIter < lengthOfSensorData; sensorValueIter++)
    {
        if (!((sensorData[sensorValueIter]>thresoldValues.minimumValue) && (sensorData[sensorValueIter]<thresoldValues.maximumValue)))
        {
            sensorData[sensorValueIter] = ((thresoldValues.minimumValue+thresoldValues.maximumValue)*0.5);//assigning median value incase of invalid value
        }
    }
    return sensorData;
}

streamingDataFormat* storeSensorData(float tempSensorValues[], float socSensorValues[], streamingDataFormat* streamingData, int lengthOfSensorValues)
{
    for (int sensorValueIter = 0; sensorValueIter < lengthOfSensorValues; sensorValueIter++)
    {
        streamingData[sensorValueIter].temperatureSensorReadings = tempSensorValues[sensorValueIter];
        streamingData[sensorValueIter].socSensorReadings = socSensorValues[sensorValueIter];
    }
    return streamingData;
}

 void streamSenderData(streamingDataFormat* streamingData, void(*fpStreamingMediumFunction)(float, float), int lengthOfStreamingData)
 {
     for (int sensorValueIter = 0; sensorValueIter < lengthOfStreamingData; sensorValueIter++)
    {
        fpStreamingMediumFunction(streamingData[sensorValueIter].temperatureSensorReadings, streamingData[sensorValueIter].socSensorReadings);
    }
 }

void streamMainFunction(sensorDataExtract sensorsData, sensorThresholdValues tempthresoldValues, sensorThresholdValues socthresoldValues)
{
    float* tempSensorDataVerified, *socSensorDataVerified;
    streamingDataFormat* streamingDataInfo;
    streamingDataFormat streamingData[sensorsData.lengthOfArray];

    tempSensorDataVerified = checkAndFixInvalidValue(sensorsData.tempSensorValues, sensorsData.lengthOfArray, tempthresoldValues);
    socSensorDataVerified = checkAndFixInvalidValue(sensorsData.socSensorValues, sensorsData.lengthOfArray, socthresoldValues);
    streamingDataInfo = storeSensorData(tempSensorDataVerified, socSensorDataVerified, streamingData, sensorsData.lengthOfArray);
    streamSenderData(streamingDataInfo, displayOnConsole, sensorsData.lengthOfArray);
     
}

/*int main()
{
    float tempSensorData[] = {12.0, 20.0, 40.0, 30.0};
    float socSensorData[] = {60.0, 25.0, 45.0, 34.0};
    sensorThresholdValues tempthresoldValues = {.maximumValue = 45.0, .minimumValue=10.0};
    sensorThresholdValues socthresoldValues = {.maximumValue = 80.0, .minimumValue=20.0};
    sensorDataExtract sensorDataInput = {.lengthOfArray = 4, .tempSensorValues = tempSensorData, .socSensorValues = socSensorData};
    streamMainFunction(sensorDataInput, tempthresoldValues, socthresoldValues);
}*/