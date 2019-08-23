//libraries needed
#include <iomanip>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
#include "LayerCake.h"
//overloaded constructor
LayerCake::LayerCake(string sFlavor, string sFrosting, int iLayerNumber, int iQuantityHolder) {
	this->sFlavor = sFlavor;
	this->sFrostingType = sFrosting;
	this->iNumberOfLayers = iLayerNumber;
	this->iQuantityPurchased = iQuantityHolder;
	this->dItemPrice = 9.00;
	this->sItemType = "LayerCake";
}
//converts all variables to a neat string
string LayerCake::ToString() {
	string sCombinedValues = "e";
	ostringstream oSS;
	string sDoubleString ="";
	//output the price correctly. 
	oSS.precision(2);
	oSS << fixed << dItemPrice;
	sDoubleString = oSS.str();
	sCombinedValues = to_string(iNumberOfLayers) + "-layer " + sFlavor + " cake with " + sFrostingType + " frosting ($" + sDoubleString + ")";
	return sCombinedValues;
}
//calculate discount for multiple itesm purchased. 
void LayerCake::DiscountedPrice() {
	double dTempPrice = 0.00;
	dTempPrice = (iQuantityPurchased >= 3)? dItemPrice - 2.00  : dItemPrice;
	//calculate running total
	this->dRunningTotal = (dTempPrice * iQuantityPurchased);
}
//print invoice correctly 
void LayerCake::PrintInvoice() {
	ostringstream oSS;
	oSS << iNumberOfLayers << "-layer " << sFlavor << " cake with " << sFrostingType << " frosting " << "($" << fixed << setprecision(2) << dItemPrice << ")";
	cout << setw(75) << left << oSS.str();
	cout << setw(9) << left << iQuantityPurchased;
	cout << setw(9) << right << fixed << setprecision(2) <<  dRunningTotal << endl;
}
//increase price if certain conditions are met. 
void LayerCake::SetPrice() {
	if (iNumberOfLayers > 1) {
		for (int i = 0; i < iNumberOfLayers; i++) {
			if (sFrostingType == "cream-cheese") {
				dItemPrice += 1.00;
			}
			if (i > 0) {
				dItemPrice += 3.00;
			}
		}
	}
}

