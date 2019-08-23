#pragma once
#include <iomanip>
#include <string>

using namespace std;
#include "Cake.h"
class LayerCake : public Cake {
	public:
		string ToString();
		void SetPrice();
		void DiscountedPrice();
		void PrintInvoice();
		//defult and overloaded constructor. 
		LayerCake() : iNumberOfLayers(0), Cake() {}
		LayerCake(string sFlavor, string sFrosting, int iLayerNumber, int iQuantityHolder);
	private:
		int iNumberOfLayers;
	protected:

};