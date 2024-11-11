//
//  Resistor.cpp
//  Lab 3 The Resistor Network Program
// Author: Hridhay Tejura
// Date: 7th October, 2024

#include "Resistor.h"

#include <iomanip>

Resistor:: Resistor(string name_, double resistance_, int endpoints_[2])  // sets name, resistance and endpoint node IDs
{
  name = name_;
  resistance = resistance_;
  for(int i = 0; i<2; i++)
  {
    endpointNodeIDs[i] = endpoints_[i];
  }
}

string Resistor:: getName()                        // returns the name
{
  return name;
}

double Resistor:: getResistance()                  // returns the resistance
{
  return resistance;
}

void Resistor:: setResistance(double resistance_)  // sets the resistance
{
  resistance = resistance_;
}

int Resistor::getOtherEndpoint(int nodeIndex)  
// returns the other node ID that the resistor is attached to (other than nodeIndex)
{
 return (endpointNodeIDs[0] != nodeIndex) ? endpointNodeIDs[0] : endpointNodeIDs[1];
}



void Resistor::print() {
  cout << std::left << std::setw(20) << name << std::right << std::setw(8)
       << std::fixed << std::setprecision(2) << resistance << " Ohms "
       << endpointNodeIDs[0] << " -> " << endpointNodeIDs[1] << endl;
}
