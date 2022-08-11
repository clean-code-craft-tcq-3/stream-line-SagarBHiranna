#include"ComputeStats.h"

void updateFloatValFromString(vector<float> &streamData,string line,size_t foundPos, string matchString){
    string valueString;
    float valueData;
    valueString = line.substr(foundPos+matchString.length(),DIGITS);
    if(valueString != ""){
        int valueLength = valueString.size()+1;
        char valueArray[valueLength];
        strcpy(valueArray,valueString.c_str());
        valueData = strtof(valueArray,nullptr);
        streamData.push_back(valueData);
    }
}

void findMatchStringAndValue(vector<float> &streamData, string matchString, string line){
    size_t foundPos = line.find(matchString);
    if(foundPos != string::npos){
        updateFloatValFromString(streamData,line,foundPos,matchString);
    }
}

void computeStatistics(vector<float> streamData,stats &statObj){
    statObj.minValue = computeMin(streamData);
    statObj.maxValue = computeMax(streamData);
    statObj.smaValue = computeSMA(streamData);
}

void processStringLines(vector<string> senderLines, void (*printPtr)(stats)){
    vector<float> tempStream, socStream;
    string tempMatchString("tempData = "), socMatchString("socData = "), line;
    for(unsigned int i = 0; i < senderLines.size();i++){
        line = senderLines[i];
        findMatchStringAndValue(tempStream,tempMatchString,line);
        findMatchStringAndValue(socStream,socMatchString,line);
    }
    stats tempObj, socObj;
    computeStatistics(tempStream,tempObj);
    computeStatistics(socStream,socObj);
    printPtr(tempObj);
    printPtr(socObj);
}
