#pragma once
#include "BST.h"


class DataAnalysis {

public:
DataAnalysis();
~DataAnalysis();

void runAnalysis(); //the only public function;calls all the other private functions.


protected:




private:
void fileOpener(); //uses mCsvStream() to open the file
void lineProcessor(int &units, string &type, string &trans);
void fileLooper(); //loops until all lines are read from the file. calls function below, then displays current contents of both BST's. use inOrderTraversal to display contents
void datafieldCompare(int &units, string &type, string &trans);
void displayTrends(); //displays the trends seen in our tree


BST mTreeSold;
BST mTreePurchased;
ifstream mCsvStream;


};