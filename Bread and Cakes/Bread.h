#pragma once
#include <iomanip>
#include <string>

using namespace std;
#include "BakedGood.h"

class Bread : public BakedGood {
	public:
		string ToString();
		void DiscountedPrice();
		void PrintInvoice();
		void SetPrice();
		//default and overloaded constructor
		Bread() : BakedGood() {};
		Bread(string sVarietyOfBread, int iQuantity);
	private:
		string sVarietyOfBread;
	protected:
};