#include<iostream>
#include<assert.h>
#include<vector>
#include<bits/stdc++.h>

#define LAST_FIVE 5
#define DIGITS 5
using namespace std;

struct stats{
    float minValue = 0, maxValue = 0, smaValue = 0;
};
void printStats(stats statObj){
    cout<<"Min element :"<<statObj.minValue<<endl;
    cout<<"Max element :"<<statObj.maxValue<<endl;
    cout<<"Simple moving average :"<<statObj.smaValue<<endl;
}

float computeMin(vector<float> streamData){
    if(!streamData.empty()){
        return *min_element(streamData.begin(),streamData.end());
    }
    return 0;
}
float computeMax(vector<float> streamData){
    if(!streamData.empty()){
        return *max_element(streamData.begin(),streamData.end());
    }
    return 0;
}
float computeSMA(vector<float> streamData){
    int iter = LAST_FIVE, divisorValue = 0;
    float streamDataSum = 0;
    while(iter != 0){
        if(streamData.empty()){
            break;
        }
        streamDataSum = streamDataSum + streamData.back();
        streamData.pop_back();
        divisorValue++;
        iter--;
    }
    if(divisorValue == 0){
        divisorValue = 1;
    }
    return streamDataSum / divisorValue;
}
