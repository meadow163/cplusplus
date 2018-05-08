#include "stdafx.h"
#include <iostream>
using namespace std;

void week1(void)
{
	int n=7;	
	int & r=n;//same var
	const int & m=r;
	const int &q=r; 
	int z=1000;	
	cout<<q;

	//m=60000;//error C3892: “m”: 不能给常量赋值
	r=4;

	cout<<r<<n;

	n=5;
	cout<<r;
	
	return;
}

int n=4;
int & SetValue(){return n;}

void MyPrintf(const char *p)
{
	char *p1="I am good!";
	//p=p1;
	//strcpy(p,"this");
	cout<<p;

}
void MemManage(void)
{
	int *pn;
	
	pn=new int[10];
	*pn=5;

	delete [] pn;

	return;
}

void func(int x1,int x2=2,int x3=3){//最右边的连续缺省

	cout<<x1<<x2<<x3<<endl;
}
