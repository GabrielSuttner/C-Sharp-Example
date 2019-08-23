#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <ios>
#include <cctype>
#include <vector>

using namespace std;
#include "CupCake.h"
#include "LayerCake.h"
#include "Bread.h"
int ValidateSelection(string sUserInput) {
	bool bTypeSelector = 0;
	int i = 0;
	if (sUserInput == "done") {
		return 4; 
	}

	if ((toupper(sUserInput.at(i)) == 'B') && (toupper(sUserInput.at(i+1)) == 'R') && (toupper(sUserInput.at(i+2)) == 'E')) {
		return 1; 
	}

	if ((toupper(sUserInput.at(i)) == 'C') && (toupper(sUserInput.at(i + 1)) == 'U') && (toupper(sUserInput.at(i + 2)) == 'P')) {
		return 2;
	}
	if ((toupper(sUserInput.at(i)) == 'L') && (toupper(sUserInput.at(i + 1)) == 'A') && (toupper(sUserInput.at(i + 2)) == 'Y')) {
		return 3;
	}
	return 4; 
}
void CombineLikeOrder(vector<BakedGood*> vOrder){
	for(int i = 0; i < vOrder.size(); i++){
		for(int j = 0; j < vOrder.size(); j++){
			if(
		}
	}
}
int main() {
	CupCake* ptrCupCake = nullptr;
	LayerCake* ptrLayerCake = nullptr;
	Bread* ptrBread = nullptr;
	vector<BakedGood*> vOrder;
	string sUserInput = "";
	int iSelectedOption = 0; 
	istringstream inSS;
	string sFlushString = "none";
	string sBreadVariety;
	string sFlavor; 
	string sFrosting;
	string sSprinkleColor;
	int iCakeLayers = 0; 
	
	
	cout << "**Bread and Cakes Bakery**" << endl << endl;
	cout << "Enter sub-order (enter \"done\" to finish)" << endl;
	do {
		cout << "Sub-Order:" << endl;
		getline(cin, sUserInput);
		iSelectedOption = ValidateSelection(sUserInput);
		inSS.clear();
		inSS.str(sUserInput);
		
		switch (iSelectedOption)
		{
		case 1:

			int iQuantityHolder;
			inSS >> sFlushString;
			inSS >> sBreadVariety;
			inSS >> iQuantityHolder;
			ptrBread = new Bread(sBreadVariety, iQuantityHolder);
			vOrder.push_back(ptrBread);
			break;
		case 2:
			inSS >> sFlushString;
			inSS >> sFlavor;
			inSS >> sFrosting;
			inSS >> sSprinkleColor;
			inSS >> iQuantityHolder;
			ptrCupCake = new CupCake(sFlavor, sFrosting, sSprinkleColor, iQuantityHolder);
			vOrder.push_back(ptrCupCake);

			break;
		case 3:
			inSS >> sFlushString;
			inSS >> sFlavor;
			inSS >> sFrosting;
			inSS >> iCakeLayers;
			inSS >> iQuantityHolder;
			ptrLayerCake = new LayerCake(sFlavor, sFrosting, iCakeLayers, iQuantityHolder);
			vOrder.push_back(ptrLayerCake);
			break;
		default:
			cout << endl << "Order Confirmations:" << endl;
			for (int i = 0; i < vOrder.size(); i++) {
				if (vOrder.at(i)->GetQuantity() > 1) {
					vOrder.at(i)->SetPrice();
					for (int j = 0; j < vOrder.at(i)->GetQuantity(); j++) {
						sFlushString = vOrder.at(i)->ToString();
						cout << sFlushString << endl;
					}
					vOrder.at(i)->DiscountedPrice();
				}
				else
				{
					sFlushString = vOrder.at(i)->ToString();
					cout << sFlushString << endl;
					vOrder.at(i)->DiscountedPrice();
				}
			}
			CombineLikeOrder(vOrder);
			cout << endl << "Invoice:" << endl;
			cout << setw(80) << left << "Baked Good";
			cout << setw(10) << left << "Quantity";
			cout << setw(10) << right << "Total" << endl;
			for (int i = 0; i < vOrder.size(); i++) {
				vOrder.at(i)->PrintInvoice();
			}
			cout << setw(80) << left << "Totals";
			cout << setw(10) << left; 

			break;
		}
	} while (iSelectedOption != 4);
	return 0; 
}
