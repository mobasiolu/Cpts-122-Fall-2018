#include "Common.h"

class Node
{
public:

//Node();
Node(string const &data); //constructor 
virtual ~Node();//destructor

//getters
string getmData();
Node*& getmpLeft();
Node*& getmpRight();

//setters
void setmData(string data);
void setmpLeft(Node* leftPtr);
void setmpRight(Node* rightPtr);

virtual void printData() = 0; //pure virtual function 

protected:
string mData;
Node* mpLeft;
Node* mpRight;


};