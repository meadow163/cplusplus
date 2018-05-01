// cplusplusproject.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "common.h"
#include <iostream>
using namespace std;

extern void week1();
extern int & SetValue();
extern void MyPrintf(const char *p);
extern void func(int x1,int x2=2,int x3=3);
int _tmain(int argc, _TCHAR* argv[])
{

/*
	week1();
	cout<<SetValue()<<endl;
	SetValue()=800;
	cout<<SetValue()<<endl;
	*/
	//const char *p="Beijing";
	//MyPrintf(p);
	func(10);
	return 0;
}

