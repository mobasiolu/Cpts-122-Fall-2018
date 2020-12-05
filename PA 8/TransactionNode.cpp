#include "TransactionNode.h"

TransactionNode::TransactionNode(string data, int unitNumber) : Node (data) //should invoke the Node class' constructor
{
	mUnits = unitNumber;
}

TransactionNode::~TransactionNode()
{
}

void TransactionNode::setmUnits(int setUnit)
{
	this->mUnits = setUnit;
}

int TransactionNode::getmUnits()
{
	return mUnits;
}

void TransactionNode::printData() 
{
cout << "Item:" << getmData() << "Units of it:" << mUnits << endl;
}
