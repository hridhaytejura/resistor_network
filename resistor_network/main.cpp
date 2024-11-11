// //
// //  main.cpp
// //  Lab 3 The Resistor Network Program
// //
// //  Created by Nathan Hung on 2024-09-11.
// //  Modified by Salma Emara on 2024-09-30
// //
// //  Permission is hereby granted to use this code in ECE244 at
// //  the University of Toronto. It is prohibited to distribute
// //  this code, either publicly or to third parties.
// //
// //  ECE244 Student: Complete the skeletal code of the main function in this file

// #include <iomanip>
// #include <iostream>
// #include <sstream>
// #include <string>

// #include "Node.h"
// #include "Resistor.h"

// using namespace std;

// Resistor** resistors =
//     nullptr;  // Pointer that should point to an array of Resistor pointers
// Node* nodes = nullptr;  // pointer that should hold address to an array of Nodes
// int maxNodeNumber = 0;  // maximum number of nodes as set in the command line
// int maxResistors = 0;  // maximum number of resistors as set in the command line
// int resistorsCount = 0;  // count the number of resistors

// string errorArray[10] = {
//     "invalid command",                                  // 0
//     "invalid argument",                                 // 1
//     "negative resistance",                              // 2
//     "node value is out of permitted range",             // 3
//     "resistor name cannot be keyword \"all\"",          // 4
//     "both terminals of resistor connect to same node",  // 5
//     "too few arguments",                                // 6
// };

// // Function Prototypes
// bool getInteger(stringstream& ss, int& x);
// bool getString(stringstream& ss, string& s);
// bool getDouble(stringstream& ss, double& s);

// void handleMaxVal(stringstream& ss);
// void handleInsertR(stringstream& ss);
// void handleModifyR(stringstream& ss);
// void handlePrintR(stringstream& ss);
// void handleDeleteR(stringstream& ss);
// void handleSetV(stringstream& ss);

// int main() {
//   // string line;
//   // string command;

//   while (!cin.eof()) {
//     string line;
//     string command;
//     bool cmd = false;
//     cout << fixed << setprecision(2) << ">>> ";
//     cout.flush();
//     getline(cin, line);
//     stringstream ss(line);

//     ss >> command;

//     if (command == "maxVal") {
//       handleMaxVal(ss);
//       cmd = true;
//     } 
//     if (command == "insertR") {
//       handleInsertR(ss);
//       cmd = true;
//     } 
//     if (command == "modifyR") {
//       handleModifyR(ss);
//       cmd = true;
//     }
//     if (command == "printR") {
//       handlePrintR(ss);
//       cmd = true;
//     } 
//     if (command == "deleteR") {
//       handleDeleteR(ss);
//       cmd = true;
//     } 
//     if (command == "setV") {
//       handleSetV(ss);
//       cmd = true;
//     }  
//     if (command == "solve") {
//       cmd = true;
//     } 
//     if(!cmd) {
//       cout << "Error: " << errorArray[0] << endl;
//     }
//   }
//   // cout << ">>> ";
//   // cout.flush();
//   // TODO: Implement the main function here
//   return 0;
// }

// // TODO: Implement functions here

// // bool getInteger(stringstream& ss, int& x) {}

// // bool getString(stringstream& ss, string& s) {}

// // bool getDouble(stringstream& ss, double& s) {}

// void handleMaxVal(stringstream& ss)  // might have to do some sort of checking
//                                      // here before assigning values
// {
//   if (ss.eof()) {
//     cout << "Error: " << errorArray[6] << endl;
//     return;
//   }
//   ss >> maxNodeNumber;
//   if (ss.fail()) {
//     cout << "Error: " << errorArray[1] << endl;
//     ss.clear();
//     ss.ignore();
//     return;
//   }

//   if (ss.eof()) {
//     cout << "Error: " << errorArray[6] << endl;
//     return;
//   }
//   ss >> maxResistors;
//   if (ss.fail()) {
//     cout << "Error: " << errorArray[1] << endl;
//     ss.clear();
//     ss.ignore();
//     return;
//   }

//   resistors = new Resistor*[maxResistors];
//   for (int i = 0; i < maxResistors; i++) {
//     resistors[i] = nullptr;
//   }

//   nodes = new Node[maxNodeNumber];  // Constructor sets numRes of each node to 0

//   cout << "New network: max node number is " << maxNodeNumber << "; "
//        << "max resistors is " << maxResistors << endl;
//   // for(int i = 0; i<maxNodeNumber; i++)
//   // {
//   //   nodes[i] = new Node();
//   // }
// }

// void handleInsertR(stringstream& ss) {
//   string name;
//   double resistance;
//   int node1id, node2id;

//   if (ss.eof()) {
//     cout << "Error: " << errorArray[6] << endl;
//     return;
//   }
//   ss >> name;
 
//   if (ss.fail()) {
//     cout << "Error: " << errorArray[1] << endl;
//     ss.clear();
//     ss.ignore();
//     return;
//   }

//   if (ss.eof()) {
//     cout << "Error: " << errorArray[6] << endl;
//     return;
//   }
//   ss >> resistance;
  
//   if (ss.fail()) {
//     cout << "Error: " << errorArray[1] << endl;
//     ss.clear();
//     ss.ignore();
//     return;
//   }

//   if (ss.eof()) {
//     cout << "Error: " << errorArray[6] << endl;
//     return;
//   }
//   ss >> node1id;

//   if (ss.fail()) {
//     cout << "Error: " << errorArray[1] << endl;
//     ss.clear();
//     ss.ignore();
//     return;
//   }

//   if (ss.eof()) {
//     cout << "Error: " << errorArray[6] << endl;
//     return;
//   }
//   ss >> node2id;
  
//   if (ss.fail()) {
//     cout << "Error: " << errorArray[1] << endl;
//     ss.clear();
//     ss.ignore();
//     return;
//   }

//   if (resistance < 0) {
//     cout << "Error: " << errorArray[2] << endl;
//     return;
//   }

//   if (name == "all") {
//     cout << "Error: " << errorArray[4] << endl;
//     return;
//   }

//   for (int i = 0; i < maxResistors; i++) {
//     if (resistors[i]->getName() == name) {
//       cout << "Error: resistor name already exists" << endl;
//       return;
//     }
//   }

//   if (!(1 <= node1id && node1id <= maxNodeNumber)) {
//     cout << "Error: " << errorArray[3] << " 1 - " << maxNodeNumber << endl;
//     return;
//   }

//   if (!(1 <= node2id && node2id <= maxNodeNumber)) {
//     cout << "Error: " << errorArray[3] << " 1 - " << maxNodeNumber << endl;
//     return;
//   }

//   if (node1id == node2id) {
//     cout << "Error: " << errorArray[5] << endl;
//     return;
//   }

//   int endpoints [2] = {node2id, node2id};
  
  

//   // Resistor* r = new Resistor(name, resistance, endpoints);
//   resistors[resistorsCount] = new Resistor(name, resistance, endpoints);
//   resistorsCount++;
  

//   nodes[node1id].addResistor(resistorsCount);
//   nodes[node2id].addResistor(resistorsCount);

//   cout << "Inserted: resistor " << name << resistance << " Ohms " << node1id
//        << " -> " << node2id << endl;
// }

// void handleModifyR(stringstream& ss) {
//   string name;
//   double resistance;
//   double oldresistance;
//   bool flag = false;

//   if (ss.eof()) {
//     cout << "Error: " << errorArray[6] << endl;
//     return;
//   }
//   ss >> name;
//   if (ss.fail()) {
//     cout << "Error: " << errorArray[1] << endl;
//     ss.clear();
//     ss.ignore();
//     return;
//   }

//   if (ss.eof()) {
//     cout << "Error: " << errorArray[6] << endl;
//     return;
//   }
//   ss >> resistance;
//   if (ss.fail()) {
//     cout << "Error: " << errorArray[1] << endl;
//     ss.clear();
//     ss.ignore();
//     return;
//   }

//   if (resistance < 0) {
//     cout << "Error: " << errorArray[2] << endl;
//     return;
//   }

//   if (name == "all") {
//     cout << "Error: " << errorArray[4] << endl;
//     return;
//   }

//   for (int i = 0; i < maxResistors; i++) {
//     if ((resistors[i])->getName() == name) {
//       oldresistance = resistors[i]->getResistance();
//       resistors[i]->setResistance(resistance);
//       flag = true;
//       cout << "Modified: resistor " << name << " from " << oldresistance
//            << " Ohms to " << resistance << " Ohms" << endl;
//     }
//   }
//   if (!flag) {
//     cout << "Error: resistor " << name << " not found" << endl;
//   }
// }

// void handlePrintR(stringstream& ss) {
//   string name;

//   if (ss.eof()) {
//     cout << "Error: " << errorArray[6] << endl;
//     return;
//   }
//   ss << name;
//   if (ss.fail()) {
//     cout << "Error: " << errorArray[1] << endl;
//     ss.clear();
//     ss.ignore();
//     return;
//   }

//   bool flag = false;

//   for (int i = 0; i < maxResistors; i++) {
//     if (resistors[i]->getName() == name) {
//       resistors[i]->print();
//       flag = true;
//     }
//   }

//   if (!flag) {
//     cout << "Error: resistor " << name << " not found" << endl;
//   }
// }

// void handleDeleteR(stringstream& ss) {
//   string all;

//   if (ss.eof()) {
//     cout << "Error: " << errorArray[6] << endl;
//     return;
//   }
//   ss >> all;
//   if (ss.fail()) {
//     cout << "Error: " << errorArray[1] << endl;
//     ss.clear();
//     ss.ignore();
//     return;
//   }

//   if (all != "all") {
//     cout << "Error: " << errorArray[1] << endl;
//     return;
//   }

//   for (int i = 0; i < maxResistors; i++) {
//     delete (resistors[i]);
//     resistors[i] = nullptr;
//   }
//   resistorsCount = 0;
// }

// void handleSetV(stringstream& ss) {
//   int nodeid;
//   double voltage;

//   if (ss.eof()) {
//     cout << "Error: " << errorArray[6] << endl;
//     return;
//   }
//   ss >> nodeid;
//   if (ss.fail()) {
//     cout << "Error: " << errorArray[1] << endl;
//     ss.clear();
//     ss.ignore();
//     return;
//   }

//   if (ss.eof()) {
//     cout << "Error: " << errorArray[6] << endl;
//     return;
//   }
//   ss >> voltage;
//   if (ss.fail()) {
//     cout << "Error: " << errorArray[1] << endl;
//     ss.clear();
//     ss.ignore();
//     return;
//   }

//   if (!(1 <= nodeid && nodeid <= maxNodeNumber)) {
//     cout << "Error: " << errorArray[3] << " 1 - " << maxNodeNumber << endl;
//     return;
//   }

//   nodes[nodeid].setVoltage(voltage);
// }


//new main begins here:

//
//  main.cpp
//  Lab 3 The Resistor Network Program
//
//  Created by Nathan Hung on 2024-09-11.
//  Modified by Salma Emara on 2024-09-30
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: Complete the skeletal code of the main function in this file

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <cmath>

#include "Node.h"
#include "Resistor.h"

using namespace boost::algorithm;
using namespace std;

Resistor** resistors =
    nullptr;  // Pointer that should point to an array of Resistor pointers
Node* nodes = nullptr;  // pointer that should hold address to an array of Nodes
int maxNodeNumber = 0;  // maximum number of nodes as set in the command line
int maxResistors = 0;  // maximum number of resistors as set in the command line
int resistorsCount = 0;  // count the number of resistors

string errorArray[10] = {
    "invalid command",                                  // 0
    "invalid argument",                                 // 1
    "negative resistance",                              // 2
    "node value is out of permitted range",             // 3
    "resistor name cannot be keyword \"all\"",          // 4
    "both terminals of resistor connect to same node",  // 5
    "too few arguments",                                // 6
};

// Function Prototypes
bool getInteger(stringstream& ss, int& x);
bool getString(stringstream& ss, string& s);
bool getDouble(stringstream& ss, double& s);

void handleMaxVal(stringstream& ss);
void handleInsertR(stringstream& ss);
void handleModifyR(stringstream& ss);
void handlePrintR(stringstream& ss);
void handleDeleteR(stringstream& ss);
void handleSetV(stringstream& ss);

int main() {
  // string line;
  // string command;

  while (!cin.eof()) {
    string line;
    string command;
    bool cmd = false;
    cout << fixed << setprecision(2) << ">>> ";
    cout.flush();
    getline(cin, line);
    if(cin.eof())
    {
      continue;
    }
    trim_right(line);
    stringstream ss(line);

    ss >> command;

    if (command == "maxVal") {
      handleMaxVal(ss);
      cmd = true;
    } 
    if (command == "insertR") {
      handleInsertR(ss);
      cmd = true;
    } 
    if (command == "modifyR") {
      handleModifyR(ss);
      cmd = true;
    }
    if (command == "printR") {
      handlePrintR(ss);
      cmd = true;
    } 
    if (command == "deleteR") {
      handleDeleteR(ss);
      cmd = true;
    } 
    if (command == "setV") {
      handleSetV(ss);
      cmd = true;
    }  
    if (command == "solve") {
      
      cmd = true;
      //const double MIN_ITERATION_CHANGE = 0.0001;
      double change = 0.00011;
      //long whilecount = 0;

      for(int i = 0; i<maxNodeNumber; i++)
      {
        if(!(nodes[i].isVoltageSet()))
        {
          nodes[i].setVoltageInternally(0);
          
        }
      }
      
      while(change > 0.0001)// && whilecount < 1000000)
      {
        double  tempchange = 0.0;
        //cout << "entered while loop" << endl;//remove
        for(int i = 0; i<maxNodeNumber; i++)
        {
          //cout << "i = " << i << endl;//remove
          if(!(nodes[i].isVoltageSet()))
          {
            //cout << "Node " << i + 1 << " (i+1) was not set" << endl;//remove
            double oldv = nodes[i].getVoltage();
            //int resistorIDs [nodes[i].getNumRes()]; // = new int [nodes[i].getNumRes()];
            // for(int k = 0; k<nodes[i].getNumRes(); k++)
            // {
            //   resistorIDs[k] = nodes[i].getResIDArray()[k];
            //   cout << k << endl;
            // }
            //resistorIDs = nodes[i].getResIDArray();
            double term1den = 0.0;
            double term2 = 0.0;
            for(int j = 0; j<nodes[i].getNumRes(); j++)
            {
              term1den += 1/resistors[*(nodes[i].getResIDArray() + j)]->getResistance();
              term2 += nodes[resistors[*(nodes[i].getResIDArray() + j)]->getOtherEndpoint(i)].getVoltage() / resistors[*(nodes[i].getResIDArray() + j)]->getResistance();
              //cout << "j = " << j <<endl; //remove
            }
            nodes[i].setVoltageInternally((1/term1den) * term2);
            //cout << "Node " << i+1 << " (i+1) voltage set to " << nodes[i].getVoltage() << endl;//remove
            tempchange = (abs(oldv - nodes[i].getVoltage()) > tempchange) ? abs(oldv - nodes[i].getVoltage()) : tempchange;
            //cout << "Change for node " << i+1 << " = " << change << endl;//remove
            //delete[] resistorIDs;
            //resistorIDs = nullptr;
          }
        }
        change = tempchange;
        //whilecount++;
        //cout << "while loop last line " << endl;//remove
      }

      cout << "Solve:" << endl;
      for(int i = 0; i<maxNodeNumber; i++)
      {
        if(nodes[i].getNumRes() >= 1)
        {
          cout << "Node " << i+1 << ": " << nodes[i].getVoltage() << " V" << endl;
        }
      }

    } 

    if(!cmd) {
      cout << "Error: " << errorArray[0] << endl;
    }
  }
  // cout << ">>> ";
  // cout.flush();
  // TODO: Implement the main function here
  return 0;
}

// TODO: Implement functions here

// bool getInteger(stringstream& ss, int& x) {}

// bool getString(stringstream& ss, string& s) {}

// bool getDouble(stringstream& ss, double& s) {}

void handleMaxVal(stringstream& ss)  // might have to do some sort of checking
                                     // here before assigning values
{
  int maxR = maxResistors;
  if (ss.eof()) {
    cout << "Error: " << errorArray[6] << endl;
    return;
  }
  ss >> maxNodeNumber;
  if (ss.fail()) {
    cout << "Error: " << errorArray[1] << endl;
    ss.clear();
    ss.ignore();
    return;
  }

  if (ss.eof()) {
    cout << "Error: " << errorArray[6] << endl;
    return;
  }
  ss >> maxResistors;
  if (ss.fail()) {
    cout << "Error: " << errorArray[1] << endl;
    ss.clear();
    ss.ignore();
    return;
  }

  for (int i = 0; i < maxR; i++) {
    delete resistors[i];
    resistors[i] = nullptr;
  }
  delete[] resistors;
  resistors = nullptr;
  resistorsCount = 0;

  delete []nodes;
  nodes = nullptr;

  resistors = new Resistor*[maxResistors];
  for (int i = 0; i < maxResistors; i++) {
    resistors[i] = nullptr;
  }

  nodes = new Node[maxNodeNumber];  // Constructor sets numRes of each node to 0

  cout << "New network: max node number is " << maxNodeNumber << "; "
       << "max resistors is " << maxResistors << endl;
  // for(int i = 0; i<maxNodeNumber; i++)
  // {
  //   nodes[i] = new Node();
  // }
}

void handleInsertR(stringstream& ss) {
  string name;
  double resistance;
  int node1id, node2id;

  if (ss.eof()) {
    cout << "Error: " << errorArray[6] << endl;
    return;
  }
  ss >> name;
  if (ss.fail()) {
    cout << "Error: " << errorArray[1] << endl;
    ss.clear();
    ss.ignore();
    return;
  }

  if (ss.eof()) {
    cout << "Error: " << errorArray[6] << endl;
    return;
  }
  ss >> resistance;
  if (ss.fail()) {
    cout << "Error: " << errorArray[1] << endl;
    ss.clear();
    ss.ignore();
    return;
  }

  if (ss.eof()) {
    cout << "Error: " << errorArray[6] << endl;
    return;
  }
  ss >> node1id;
  if (ss.fail()) {
    cout << "Error: " << errorArray[1] << endl;
    ss.clear();
    ss.ignore();
    return;
  }

  if (ss.eof()) {
    cout << "Error: " << errorArray[6] << endl;
    return;
  }
  ss >> node2id;
  if (ss.fail()) {
    cout << "Error: " << errorArray[1] << endl;
    ss.clear();
    ss.ignore();
    return;
  }

  if (resistance < 0) {
    cout << "Error: " << errorArray[2] << endl;
    return;
  }

  if (name == "all") {
    cout << "Error: " << errorArray[4] << endl;
    return;
  }

  for (int i = 0; i < resistorsCount; i++) {
    if (resistors[i]->getName() == name) {
      cout << "Error: resistor name already exists" << endl;
      return;
    }
  }

  if (node1id < 1 || node1id > maxNodeNumber) {
    cout << "Error: " << errorArray[3] << " 1 - " << maxNodeNumber << endl;
    return;
  }

  if (node2id < 1 || node2id > maxNodeNumber) {
    cout << "Error: " << errorArray[3] << " 1 - " << maxNodeNumber << endl;
    return;
  }
  

  if (node1id == node2id) {
    cout << "Error: " << errorArray[5] << endl;
    return;
  }
  
  
  

  int endpoints [2] = {node1id-1, node2id-1};
  
 

  // Resistor* r = new Resistor(name, resistance, endpoints);
  resistors[resistorsCount] = new Resistor(name, resistance, endpoints);
  resistorsCount++;
  

  nodes[node1id-1].addResistor(resistorsCount-1);
  nodes[node2id-1].addResistor(resistorsCount-1);

  cout << "Inserted: resistor " << name << " " << resistance << " Ohms " << node1id
       << " -> " << node2id << endl;
}

void handleModifyR(stringstream& ss) {
  string name;
  double resistance;
  double oldresistance;
  bool flag = false;

  if (ss.eof()) {
    cout << "Error: " << errorArray[6] << endl;
    return;
  }
  ss >> name;
  if (ss.fail()) {
    cout << "Error: " << errorArray[1] << endl;
    ss.clear();
    ss.ignore();
    return;
  }

  if (ss.eof()) {
    cout << "Error: " << errorArray[6] << endl;
    return;
  }
  ss >> resistance;
  if (ss.fail()) {
    cout << "Error: " << errorArray[1] << endl;
    ss.clear();
    ss.ignore();
    return;
  }

  if (resistance < 0) {
    cout << "Error: " << errorArray[2] << endl;
    return;
  }

  if (name == "all") {
    cout << "Error: " << errorArray[4] << endl;
    return;
  }

  for (int i = 0; i < resistorsCount; i++) {
    if ((resistors[i])->getName() == name) {
      oldresistance = resistors[i]->getResistance();
      resistors[i]->setResistance(resistance);
      flag = true;
      cout << "Modified: resistor " << name << " from " << oldresistance
           << " Ohms to " << resistance << " Ohms" << endl;
    }
  }
  if (!flag) {
    cout << "Error: resistor " << name << " not found" << endl;
  }
}

void handlePrintR(stringstream& ss) {
  string name;

  if (ss.eof()) {
    cout << "Error: " << errorArray[6] << endl;
    return;
  }
  ss << name;
  if (ss.fail()) {
    cout << "Error: " << errorArray[1] << endl;
    ss.clear();
    ss.ignore();
    return;
  }

  bool flag = false;
  cout << "Print:" << endl;

  for (int i = 0; i < resistorsCount; i++) {
    if (resistors[i]->getName() == name) {
      resistors[i]->print();
      flag = true;
    }
  }

  if (!flag) {
    cout << "Error: resistor " << name << " not found" << endl;
  }
}

void handleDeleteR(stringstream& ss) {
  string all;

  if (ss.eof()) {
    cout << "Error: " << errorArray[6] << endl;
    return;
  }
  ss >> all;
  if (ss.fail()) {
    cout << "Error: " << errorArray[1] << endl;
    ss.clear();
    ss.ignore();
    return;
  }

  if (all != "all") {
    cout << "Error: " << errorArray[1] << endl;
    return;
  }

  for (int i = 0; i < resistorsCount; i++) {
    delete (resistors[i]);
    resistors[i] = nullptr;
  }
  delete[] resistors;
  resistors = nullptr;
  resistorsCount = 0;
}

void handleSetV(stringstream& ss) {
  int nodeid;
  double voltage;

  if (ss.eof()) {
    cout << "Error: " << errorArray[6] << endl;
    return;
  }
  ss >> nodeid;
  if (ss.fail()) {
    cout << "Error: " << errorArray[1] << endl;
    ss.clear();
    ss.ignore();
    return;
  }

  if (ss.eof()) {
    cout << "Error: " << errorArray[6] << endl;
    return;
  }
  ss >> voltage;
  if (ss.fail()) {
    cout << "Error: " << errorArray[1] << endl;
    ss.clear();
    ss.ignore();
    return;
  }

  if (!(1 <= nodeid && nodeid <= maxNodeNumber)) {
    cout << "Error: " << errorArray[3] << " 1 - " << maxNodeNumber << endl;
    return;
  }

  nodes[nodeid-1].setVoltage(voltage);
  cout << "Set: node " << nodeid << " to " << voltage << " Volts" << endl;
}

