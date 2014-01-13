//============================================================================
// Name        : TDacTest.cpp
// Author      : sby_kz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//#include <TreeList.h>

#include "../../TDacCore/include/TreeList.h"

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	TreeList root;
	TreeList sub0;
	TreeList sub0_0;
	TreeList sub0_1;

	TreeList sub1;
	TreeList sub1_0;
	TreeList sub1_1;
	TreeList sub1_2;

	sub0.AddChild(sub0_0);
	sub0.AddChild(sub0_1);

	sub1.AddChild(sub1_0);
	sub1.AddChild(sub1_1);
	sub1.AddChild(sub1_2);

	root.AddChild(sub0);
	root.AddChild(sub1);

	root.DumpPrint();

	return 0;
}
