//============================================================================
// Name        : TDacTest.cpp
// Author      : sby_kz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include <TreeList.h>
#include <stdio.h>

#ifndef NULL
#	define NULL 0
#endif

class NameTreeList : public TreeList
{
public:
	NameTreeList(const char * const name) :
		mName(name)
	{

	}

	void DumpPrint(int depth = 0)
	{
		for(int i=0; i<depth; i++)
		{
			printf(" ");
		}
		printf("Node : %s\n", mName);
	
		std::list<TreeList*>::iterator it;
		for(it = GetChild()->begin(); it != GetChild()->end(); it++)
		{
			dynamic_cast<NameTreeList*>(*it)->DumpPrint(depth+1);
		}
	}

private:
	const char * const mName;
};


int main(int argc, char *argv[]) 
{
	NameTreeList root("root");
	NameTreeList sub0("sub0");
	NameTreeList sub0_0("sub0_0");
	NameTreeList sub0_1("sub0_1");

	NameTreeList sub1("sub1");
	NameTreeList sub1_0("sub1_0");
	NameTreeList sub1_1("sub1_1");
	NameTreeList sub1_2("sub1_2");

	sub0.AddChild(&sub0_0);
	sub0.AddChild(&sub0_1);

	sub1.AddChild(&sub1_0);
	sub1.AddChild(&sub1_1);
	sub1.AddChild(&sub1_2);

	root.AddChild(&sub0);
	root.AddChild(&sub1);

	root.DumpPrint();
	printf("\n");

	sub0_0.AddChild(&sub0_1);
	sub1_0.AddChild(&sub1_1);
	sub1_1.AddChild(&sub1_2);

	root.DumpPrint();
	printf("\n");

	sub1_2.AddChild(&sub0);

	root.DumpPrint();
	printf("\n");

	return 0;
}
