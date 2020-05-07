/**
 * File    : HouseHoldtest.cpp
 * Purpose : Test program to test HouseHold class  
 * Author  : Ramesh Sinnarajah
 * Date    : April 10, 2020
 **/


#include "HouseHold.h"
#include "Account.h"
#include "DebitCardAccount.h"
#include "CreditCardAccount.h"

int main() {

	DebitCardAccount da("Rameshwaran", "121121212", "12/12/2000", 2000, 2);
	HouseHold hh("Rameswarn Sinnarajah",  &da);

	hh.toString();

	cout << endl;

	CreditCardAccount ca("Thaneswaran", "12121211212", "12/12/2000", 2000, 0.9);
	HouseHold hh2("Thaneswaran Sinnarajah", &ca);
	hh2.toString();


	return 0;

}