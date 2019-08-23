#pragma once
#include <iomanip>
#include <string>

using namespace std;

#include "BakedGood.h"
class Cake : public BakedGood{
	public:
		//default constructor. no overloaded because cake constructor isn't really used. 
		Cake() : sFrostingType("vanilla"), BakedGood() {}
	private:
	protected:
		string sFlavor; 
		string sFrostingType;
};