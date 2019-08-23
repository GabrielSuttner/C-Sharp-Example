#pragma once
#include <iomanip>
#include <string>

using namespace std;
class BakedGood {
	public:
		//functions that effect the protected variables. 
		int GetQuantity();
		double GetRunningTotal();
		string GetItem();
		void SetQuantity(int iQuantiyPurchased);
		void SetRunningTotal(double dRunningTotal);

		//functions that each subclass uses but is different for each. 
		virtual string ToString() = 0;
		virtual void SetPrice() = 0;
		virtual void DiscountedPrice() = 0;
		virtual void PrintInvoice() = 0;
		//no overloaded constructor because it doesn't need one. never called.  
		BakedGood() :sItemType("Bread"), iQuantityPurchased(0), dItemPrice(4.50), dRunningTotal(0.0) {}
	private:
	protected:
		string sItemType;
		int iQuantityPurchased;
		double dItemPrice;
		double dRunningTotal;
};