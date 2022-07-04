#define CATCH_CONFIG_MAIN 

#include "test/catch.hpp"
#include <time.h>
#include <stdlib.h>
#include "sender.h"


TEST_CASE("TestCase1 : Stream Valid Data From Sensor") {

    float tempSensorData[] = {12.0, 20.0, 40.0, 30.0};
    float socSensorData[] = {60.0, 25.0, 45.0, 34.0};
    sensorThresholdValues tempthresoldValues = {.maximumValue = 45.0, .minimumValue=10.0};
    sensorThresholdValues socthresoldValues = {.maximumValue = 80.0, .minimumValue=20.0};
    sensorDataExtract sensorDataInput = {.lengthOfArray = 4, .tempSensorValues = tempSensorData, .socSensorValues = socSensorData};  
    REQUIRE(streamMainFunction(sensorDataInput, tempthresoldValues, socthresoldValues));
}


TEST_CASE("TestCase2 : Stream InValid Data From Sensor and check whether the value is being rectified before streaming") {

    float tempSensorData[] = {50.0, 20.0, 40.0, 9.0};
    float socSensorData[] = {90.0, 25.0, 45.0, 10.0};
    sensorThresholdValues tempthresoldValues = {.maximumValue = 45.0, .minimumValue=10.0};
    sensorThresholdValues socthresoldValues = {.maximumValue = 80.0, .minimumValue=20.0};
    sensorDataExtract sensorDataInput = {.lengthOfArray = 4, .tempSensorValues = tempSensorData, .socSensorValues = socSensorData};  
    REQUIRE(streamMainFunction(sensorDataInput, tempthresoldValues, socthresoldValues));
}

TEST_CASE("Test 3 : Prepare Data from Sensor : Manual Data") {

  BatteryParameterInfo parameterInfo [NoOfParameter] ;
  Sender DataFromSender ;
  
  parameterInfo[0].minimumThreshold = 5.0;
  parameterInfo[0].maximumThreshold = 20.0;
  
  parameterInfo[1].minimumThreshold = 10.0;
  parameterInfo[1].maximumThreshold = 50.0;
  
  DataFromSender.number_of_values = 2;
  float (*funp_ReadDataFromSensor)(float,float) = SimulateReadDataFromSensor_ManualData;
  
  REQUIRE(ProcessSenderData(parameterInfo ,&DataFromSender,funp_ReadDataFromSensor) == TRUE);
}