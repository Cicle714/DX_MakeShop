#include "StartFlag.h"

#include<fstream>
#include<sstream>

StartFlag::StartFlag(){

    auto csv = LoadCSV("messages.csv");
    MessageNum = 0;

    message = new std::string[csv.size()];

    for (int i = 0; i < csv.size(); i++) {
        message[i] = std::stoi(csv[i][0]);
    }

}

StartFlag::~StartFlag()
{
	delete[] message;
}

void StartFlag::Update()
{

}

void StartFlag::Draw()
{
}


