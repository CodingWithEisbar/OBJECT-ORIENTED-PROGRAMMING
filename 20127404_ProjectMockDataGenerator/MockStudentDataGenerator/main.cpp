//20127404
//Nguyen Trung Nguyen
//20CLC07

#include <iostream>

#include "RandomIntegerGenerator.h"
using namespace std;

int main() {

	//Generate randomly a number n in the range of[5, 10]
	RandomIntegerGenerator _rig;
	int n = _rig.next(5, 10);

	return 0;
}