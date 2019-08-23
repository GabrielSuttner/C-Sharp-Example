//needed libraries
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
#include "Bread.h"
//overloaded constructor
Bread::Bread(string sVarietyOfBread, int iQuantity) {
	this->sVarietyOfBread = sVarietyOfBread; 
	this->iQuantityPurchased = iQuantity;
	this->dItemPrice = 4.5;
	this->sItemType = "Bread";
}
//converts to a string
string Bread::ToString() {
	ostringstream oSS;
	string sDoubleString;
	string sCombinedValues = "e";
	//output double correctly 
	oSS.precision(2);
	oSS << fixed << dItemPrice;
	sDoubleString = oSS.str();
	sCombinedValues = sVarietyOfBread + " bread ($" + sDoubleString + ")";
	return sCombinedValues;
}
//calculate price if mutliple items are bought 
void Bread::DiscountedPrice() {
	double dTotalPrice = 0.0;
	if (iQuantityPurchased >= 6) {
		dTotalPrice = (iQuantityPurchased * dItemPrice) - (dItemPrice * 2);
	}
	else if (iQuantityPurchased >= 3) {
		dTotalPrice = (iQuantityPurchased * dItemPrice) - dItemPrice;
	}
	else {
		dTotalPrice = iQuantityPurchased * dItemPrice;
	}
	this->dRunningTotal = dTotalPrice;
}
//output invoice correctly 
void Bread::PrintInvoice() {
	ostringstream oSS;
	oSS << sVarietyOfBread << " bread ($" << fixed << setprecision(2) << dItemPrice << ")";
	cout << setw(75) << left << oSS.str();
	cout << setw(9) << left << iQuantityPurchased;
	cout << setw(9) << right << fixed << setprecision(2) << dRunningTotal << endl;
}
//set price. 
void Bread::SetPrice() {
	dItemPrice = dItemPrice;
}

