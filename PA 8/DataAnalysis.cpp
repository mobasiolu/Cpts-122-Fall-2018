#include "DataAnalysis.h"

DataAnalysis::DataAnalysis()
{

}

DataAnalysis::~DataAnalysis()
{
	//cout << "data analysis destructor being called" << endl;
}

void DataAnalysis::runAnalysis()
{
	fileLooper(); //processes all the data
	displayTrends(); //displays the trends on the data
					
	mCsvStream.close();	//close the file
	
}

void DataAnalysis::fileOpener()
{
	mCsvStream.open("data.csv");

	
}

void DataAnalysis::lineProcessor(int &units, string &type, string &trans)
{
	string fileLine; 

	getline(mCsvStream, fileLine, ',');

	units = stoi(fileLine);

	getline(mCsvStream, type, ','); //directly storing 2nd data field into type variable
	getline(mCsvStream, trans);

}

void DataAnalysis::fileLooper() //not finished 
{
	int dataUnits;
	string dataType;
	string dataTrans;
	string tempString;

	fileOpener(); //opens the file
	getline(mCsvStream, tempString);

	while (!mCsvStream.eof()) //not at the end of the file
	{
		lineProcessor(dataUnits, dataType, dataTrans);
		datafieldCompare(dataUnits, dataType, dataTrans);
	}


}

void DataAnalysis::datafieldCompare(int &units, string &type, string &trans)
{
	if (trans == "Sold")
	{
		mTreeSold.publicInsert(units, type);
	}
	else
	{
		mTreePurchased.publicInsert(units, type);
	}
}

void DataAnalysis::displayTrends()
{
	cout << "Purchased Tree Max:" << endl;
	mTreePurchased.findLargest(mTreePurchased.getmpRoot()).printData();

	cout << "Sold Tree Max:" << endl;
	mTreeSold.findLargest(mTreeSold.getmpRoot()).printData();

	cout << "Purchased Tree Min:" << endl;
	mTreePurchased.findSmallest(mTreePurchased.getmpRoot()).printData();


	cout << "Sold Tree Min:" << endl;
	mTreeSold.findSmallest(mTreeSold.getmpRoot()).printData();


	

}

