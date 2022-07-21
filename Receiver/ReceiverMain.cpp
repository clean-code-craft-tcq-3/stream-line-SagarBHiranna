#include"Test-Receiver.h"

void getLines(vector<string> &lines){
    string line;
    do{
        getline(cin,line,'\n');
        lines.push_back(line);
    }while(line != "");
}

int main(){
    vector<string> lines;
    getLines(lines);
    void (*printPtr)(stats) = &printStats;
    processStringLines(lines,printPtr);
    testReceiver();
    cout<<"ALL Test cases passed"<<endl;
}

