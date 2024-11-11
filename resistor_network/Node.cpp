//
//  Node.cpp
//  Lab 3 The Resistor Network Program
// Author: Hridhay Tejura
// Date: 7th October 2024

#include "Node.h"
#include "Resistor.h"

using namespace std;

Node:: Node()
{
    numRes = 0;
    voltage = 0;
    voltageIsSet = false;
    //resIDArray = new int [MAX_RESISTORS_PER_NODE];
}

bool Node:: canAddResistor() // returns if the number of resistors is less than MAX_RESISTORS_PER_NODE
{
    if(numRes < MAX_RESISTORS_PER_NODE)
        return true;
    return false;

}


void Node:: addResistor(int rIndex)  // adds a resistor to resIDArray array and
                                // increments number of resistors
{
    if(canAddResistor())
    {
        resIDArray[numRes] = rIndex;
        numRes++;
    }
}


double Node:: getVoltage()  // returns voltage
{
    return voltage;
}


void Node:: setVoltage(double voltage_)  // sets voltage and sets voltageIsSet to true
{
    voltage = voltage_;
    voltageIsSet = true;
}


void Node::setVoltageInternally(double voltage_)  // sets voltage temporarily during iterations for solve command
{
    voltage = voltage_;
}


bool Node:: isVoltageSet()   // returns voltageIsSet
{
    return voltageIsSet;
}


int Node:: getNumRes()       // returns numRes
{
    return numRes;
}


int* Node:: getResIDArray()  // returns resIDArray
{
    return resIDArray;
}
