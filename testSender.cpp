#define CATCH_CONFIG_MAIN 


#include "test/catch.hpp"
#include <time.h>
#include <stdlib.h>
#include "sender.h"

sensorThresholdValues tempthresoldValues = {.maximumValue = 45.0, .minimumValue=10.0};
sensorThresholdValues socthresoldValues = {.maximumValue = 80.0, .minimumValue=20.0};

void testPrint(float tempData, float socData)
{
    printf("{  tempData = %.2f , socData = %.2f  }\n", tempData, socData);
}

TEST_CASE("TestCase1 : Stream Valid Data From Sensor") {

    float tempSensorData[] = {12.0, 20.0, 40.0, 30.0};
    float socSensorData[] = {60.0, 25.0, 45.0, 34.0};
    sensorDataExtract sensorDataInput = {.lengthOfArray = 4, .tempSensorValues = tempSensorData, .socSensorValues = socSensorData};  
    REQUIRE(streamMainFunction(sensorDataInput, tempthresoldValues, socthresoldValues, testPrint)==1);
}

TEST_CASE("TestCase2 : Stream InValid Data From Sensor and check whether the value is being rectified before streaming") {

    float tempSensorDataInvalid[] = {50.0, 20.0, 40.0, 9.0};
    float socSensorDataInvalid[] = {90.0, 25.0, 45.0, 10.0};
    sensorDataExtract sensorDataInputInvalid = {.lengthOfArray = 4, .tempSensorValues = tempSensorDataInvalid, .socSensorValues = socSensorDataInvalid};  
    REQUIRE(streamMainFunction(sensorDataInputInvalid, tempthresoldValues, socthresoldValues, testPrint)==1);
}
