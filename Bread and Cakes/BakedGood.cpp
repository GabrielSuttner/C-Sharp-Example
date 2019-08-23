#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#include "BakedGood.h"

int BakedGood::GetQuantity() {
	return this->iQuantityPurchased;
}
void BakedGood::SetQuantity(int iQuantityPurchased) {
	this->iQuantityPurchased = iQuantityPurchased;
}
double BakedGood::GetRunningTotal() {
	return this->dRunningTotal;
}
void BakedGood::SetRunningTotal(double dRunningTotal) {
	this->dRunningTotal = dRunningTotal;
}
string BakedGood::GetItem() {
	return this->sItemType;
}