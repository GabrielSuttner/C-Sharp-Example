#pragma once
#include <iomanip>
#include <string>

using namespace std;
#include "Cake.h"

class CupCake : public Cake {
	public:
		void SetPrice();
		string ToString();
		void DiscountedPrice();
		void PrintInvoice();
		//default and overloaded constructor. 
		CupCake() : sSprinkleColor("none"), Cake(){}
		CupCake(string sFlavor, string sFrosting, string sSprinkleColor, int iQuantityHolder);
	private:
		string sSprinkleColor;
	protected:

};