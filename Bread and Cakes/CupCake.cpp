#include <iomanip>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

#include "CupCake.h"
//overloaded constructor
CupCake::CupCake(string sFlavor, string sFrosting, string sSprinkleColor, int iQuantityHolder) {
	this->sFlavor = sFlavor;
	this->sFrostingType = sFrosting;
	this->sSprinkleColor = sSprinkleColor;
	this->iQuantityPurchased = iQuantityHolder;
	this->dItemPrice = 1.95;
	this->sItemType = "CupCake";
}
//converts all the values to a string to be returned
string CupCake::ToString() {
	string sCombinedValues = "e";
	ostringstream oSS;
	string sDoubleString;
	//makes it so the double is output correctly
	oSS.precision(2);
	oSS << fixed << dItemPrice;
	sDoubleString = oSS.str();
	//Concatenates all of the values into string
	sCombinedValues = sFlavor + " cupcake with " + sFrostingType + " frosting" + " and " + sSprinkleColor + " sprinkles ($" + sDoubleString + ")";
	return sCombinedValues;
}
//calculates discount
void CupCake::DiscountedPrice() {
	double dTempPrice = 0.0;
	if (iQuantityPurchased >= 4) {
		dTempPrice = dItemPrice - .40;
	}
	else if (iQuantityPurchased >= 2) {
		dTempPrice = dItemPrice - .30;
	}
	else {
		dTempPrice = dItemPrice;
	}
	
	this->dRunningTotal = (dTempPrice * iQuantityPurchased);
}
//prints the final invoice 
void CupCake::PrintInvoice() {
	ostringstream oSS;
	oSS << 	sFlavor << " cupcake with " << sFrostingType << " frosting" << " and " << sSprinkleColor << " sprinkles" << " ($" << fixed << setprecision(2) << dItemPrice << ")";
	//outputs to correct widths
	cout << setw(75) << left << oSS.str();
	cout << setw(9) << left << iQuantityPurchased;
	cout << setw(9) << right << fixed << setprecision(2) << dRunningTotal << endl;
}
//if there is cream chees the price for each is increased. 
void CupCake::SetPrice() {
	if (sFrostingType == "cream-cheese") {
		dItemPrice += .20;
	}
}

