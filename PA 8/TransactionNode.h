#pragma once
#include "Common.h";
#include "Node.h";

class TransactionNode : public Node {
	
public:

TransactionNode(string data, int unitNumber); //: Node(data); //should invoke Class Node constructor
~TransactionNode();

//setters
void setmUnits(int setUnit);

//getters
int getmUnits();

void printData(); //overrides the pure virtual function in Node class 

private:

int mUnits;


};
