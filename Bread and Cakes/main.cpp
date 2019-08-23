/*Author: Gabriel Suttner
Email: GabrielSuttner@gmail.com
Sec: 006
Description: this program simulates a order and receipt of an order. It asks the user for Items in a bakery, These items are then priced
discounted and totaled. */
//libraries included. 
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <ios>
#include <cctype>
#include <vector>

using namespace std;
//header files needed. 
#include "CupCake.h"
#include "LayerCake.h"
#include "Bread.h"
//this function validates the users choice and makes the program able to use a switch statement. 
int ValidateSelection(string sUserInput) {
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
//combines like items on an order. 
void CombineLikeItem(vector<BakedGood*>& vOrder) {
	for (int i = 0; i < vOrder.size(); i++) {
		//executes for all 'bread' items
		if (vOrder.at(i)->GetItem() == "Bread") {
			for (int j = i + 1; j < vOrder.size(); j++) {
				//checks to see if Item @ i is the same as anyother item in the order
				if (vOrder.at(i)->ToString() == vOrder.at(j)->ToString())  {
					//if it is, then combine quantities and totals. 
					vOrder.at(i)->SetQuantity(vOrder.at(i)->GetQuantity() + vOrder.at(j)->GetQuantity());
					vOrder.at(i)->SetRunningTotal(vOrder.at(i)->GetRunningTotal() + vOrder.at(j)->GetRunningTotal());
					//delete the pointer and its value in vector
					delete vOrder.at(j);
					//remove that location in the vector
					vOrder.erase(vOrder.begin() + j);
					vOrder.at(i)->DiscountedPrice();
				}
			}
		}
		//executes for all 'layercake' items 
		else if (vOrder.at(i)->GetItem() == "LayerCake") {
			for (int j = i+1; j < vOrder.size(); j++) {
				if (vOrder.at(i)->ToString() == vOrder.at(j)->ToString()) {
					vOrder.at(i)->SetQuantity(vOrder.at(i)->GetQuantity() + vOrder.at(j)->GetQuantity());
					vOrder.at(i)->SetRunningTotal(vOrder.at(i)->GetRunningTotal() + vOrder.at(j)->GetRunningTotal());
					delete vOrder.at(j);
					vOrder.erase(vOrder.begin() + j);
					vOrder.at(i)->DiscountedPrice();
				}
			}
		}
		//executes for all cupcake items
		else {
			for (int j = i+1; j < vOrder.size(); j++) {
				if (vOrder.at(i)->ToString() == vOrder.at(j)->ToString()) {
					vOrder.at(i)->SetQuantity(vOrder.at(i)->GetQuantity() + vOrder.at(j)->GetQuantity());
					vOrder.at(i)->SetRunningTotal(vOrder.at(i)->GetRunningTotal() + vOrder.at(j)->GetRunningTotal());
					delete vOrder.at(j);
					vOrder.erase(vOrder.begin() + j);
					vOrder.at(i)->DiscountedPrice();
				}
			}
		}
	}
}
//calculate the order total
void CalculateTotal(vector<BakedGood*>& vOrder){
	int iTempQuantity = 0;
	double dTempTotal = 0.0;
	for (int i = 0; i < vOrder.size(); i++) {
		iTempQuantity += vOrder.at(i)->GetQuantity();
		dTempTotal += vOrder.at(i)->GetRunningTotal();
	}
	//output in correct format
	cout << setw(75) << left << "Totals";
	cout << setw(9) << left << iTempQuantity;
	cout << setw(9) << right << fixed << setprecision(2) << dTempTotal << endl;
}
int main() {
	//decleration of all pointers related variables. 
	CupCake* ptrCupCake = nullptr;
	LayerCake* ptrLayerCake = nullptr;
	Bread* ptrBread = nullptr;
	vector<BakedGood*> vOrder;
	//declare all strings
	string sUserInput = "";
	string sFlushString = "none";
	string sBreadVariety = "";
	string sFlavorBread = "";
	string sFrostingColor = "";
	string sSprinkleColor = "";
	int iCakeLayers = 0;
	int iSelectedOption = 0;
	int iQuantityHolder;
	//stringstream to make correct output. 
	istringstream inSS;

	cout << "**Bread and Cakes Bakery**" << endl << endl;
	cout << "Enter sub-order (enter \"done\" to finish)" << endl;
	//switch statement repeats till "done" is inputed. 
	do {
		cout << "Sub-Order:" << endl;
		getline(cin, sUserInput);
		//use above function
		iSelectedOption = ValidateSelection(sUserInput);
		//clear out the stringstream then fill with user's input
		inSS.clear();
		inSS.str(sUserInput);

		switch (iSelectedOption)
		{
		case 1:
			//put strings from buffer into variables. 
			inSS >> sFlushString;
			inSS >> sBreadVariety;
			inSS >> iQuantityHolder;
			//create new pointer and put into vector. 
			ptrBread = new Bread(sBreadVariety, iQuantityHolder);
			vOrder.push_back(ptrBread);
			break;
		case 2:
			inSS >> sFlushString;
			inSS >> sFlavorBread;
			inSS >> sFrostingColor;
			inSS >> sSprinkleColor;
			inSS >> iQuantityHolder;
			ptrCupCake = new CupCake(sFlavorBread, sFrostingColor, sSprinkleColor, iQuantityHolder);
			vOrder.push_back(ptrCupCake);
			break;
		case 3:
			inSS >> sFlushString;
			inSS >> sFlavorBread;
			inSS >> sFrostingColor;
			inSS >> iCakeLayers;
			inSS >> iQuantityHolder;
			ptrLayerCake = new LayerCake(sFlavorBread, sFrostingColor, iCakeLayers, iQuantityHolder);
			vOrder.push_back(ptrLayerCake);
			break;
			//after "done" is entered this will execute. 
		default:
			cout << endl << "Order Confirmations:" << endl;
			//converts the values in The order into a string to be output. 
			for (int i = 0; i < vOrder.size(); i++) {
				if (vOrder.at(i)->GetQuantity() > 1) {
					vOrder.at(i)->SetPrice();
					for (int j = 0; j < vOrder.at(i)->GetQuantity(); j++) {
						sFlushString = vOrder.at(i)->ToString();
						cout << sFlushString << endl;
					}
					//after the order has been output then the order's running total is changed to a disocounted price. 
					vOrder.at(i)->DiscountedPrice();
				}
				else
				{
					sFlushString = vOrder.at(i)->ToString();
					cout << sFlushString << endl;
					vOrder.at(i)->DiscountedPrice();
				}
			}
			//combine like values
			CombineLikeItem(vOrder);
			//output invoice
			cout << endl << "Invoice:" << endl;
			cout << setw(75) << left << "Baked Good";
			cout << setw(9) << left << "Quantity";
			cout << setw(9) << right << "Total" << endl;
			//prints each item in order. 
			for (int i = 0; i < vOrder.size(); i++) {
				vOrder.at(i)->PrintInvoice();
			}
			//outpute the total. 
			CalculateTotal(vOrder);
			cout << "Good Bye";
			break;
		}
	} while (iSelectedOption != 4);
	return 0;
}
