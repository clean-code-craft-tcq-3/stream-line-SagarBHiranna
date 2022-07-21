#include"Receiver.h"

void testReceiver(){
    cout<<"Test Case 1 for string"<<endl;
    vector<float> tempStream, socStream,expTempStream,expSocStream;
    string tempMatchString("tempData = "), socMatchString("socData = ");
    vector<string> streamOfLines{"tempData = 26.33 , socData = 28.33","tempData = 31.8 , socData = 42.6",\
    "tempData = 27.66 , socData = 23.11","tempData = 16.14 , socData = 18.14","tempData = 41.25 , socData = 6.79"};
    vector<string>::iterator itr = streamOfLines.begin();
    while(itr != streamOfLines.end()){
        findMatchStringAndValue(tempStream,tempMatchString,*itr);
        findMatchStringAndValue(socStream,socMatchString,*itr);
        itr++;
    }
    expTempStream = {26.33,31.8,27.66,16.14,41.25};
    expSocStream = {28.33,42.6,23.11,18.14,6.79};
    assert(tempStream == expTempStream);
    cout<<"Test passed"<<endl<<endl;

    cout<<"Test Case 2 for statistics of temperature data"<<endl;
    tempStream = {31.8,27.66,8.26,25.15,16.14,41.25};
    float expMin,expMax,expSMA,minVal,maxVal,smaVal;
    minVal = computeMin(tempStream);
    expMin = 8.26;
    maxVal = computeMax(tempStream);
    expMax = 41.25;
    smaVal = computeSMA(tempStream);
    expSMA = 23.692;
    assert(minVal == expMin);
    assert(maxVal == expMax);
    assert((smaVal - expSMA) < 0.00001);
    cout<<"Test passed"<<endl<<endl;

    cout<<"Test Case 2 for statistics of SOC data"<<endl;
    socStream = {42.6,23.11,37.98,32.6,18.14,6.79};
    minVal = computeMin(socStream);
    maxVal = computeMax(socStream);
    smaVal = computeSMA(socStream);
    expMin = 6.79;
    expMax = 42.6;
    expSMA = 23.724;
    assert(minVal == expMin);
    assert(maxVal == expMax);
    assert((smaVal - expSMA) < 0.00001);
    cout<<"Test passed"<<endl<<endl;
}
