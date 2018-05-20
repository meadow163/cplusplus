#include<cstring>//c++ strlen strcpy
#include<iostream>
using namespace std;

class Complex
{
	public:
		double real,imag;
 		Complex(double r=0.0,double i=0.0):real(r),imag(i){};
		Complex operator-(const Complex &c);
};

Complex operator+(const Complex & a,const Complex &b)
{

	return Complex(a.real+b.real,a.imag+b.imag);//返回临时对象

}//重载为普通函数
Complex Complex::operator-(const Complex & c)
{
	return Complex(real-c.real,imag-c.imag);

}//重载为成员函数，参数个数

class String 
{
private:
	char* str;
public:
	String():str(new char[1]){str[0]=0;}
	const char * c_str() {return str;}
	String & operator=(const char * s);
	~String()
	{
		delete [] str;
	}


};
String& String::operator=(const char * s)
{
	//重载“=”以使得obj="hello"能够成立
	cout << "operator = called"<<endl;
	delete [] str;
	str=new char[strlen(s+1)];
	strcpy(str,s);
	return *this;

}
class CArray
{
	int size;
	int *ptr;
public:
	CArray(int s=0);
	CArray(const CArray &);
	~CArray();
	void push_back(int v);
	CArray & operator=(const CArray &a);
	int length(){return size;}
	int & operator[](const int i);

};
CArray::CArray(int s):size(s)
{
	if(s<=0)
	{
//		cout<<"array len error,array failed."<<endl;
		ptr=NULL;
	}
	else	
		ptr=new int[s];
	cout<<"constrator called:s="<<s<<endl;
}
CArray::~CArray()
{	
	cout<<endl;
	cout<<"deconstrator called"<<endl;
	if(ptr!=NULL)
	{		
		delete [] ptr;
		cout<<"arrary released"<<endl;
	}
}

void CArray::push_back(int v)
{
	int *temp_ptr;
	if(ptr!=NULL)
	{	
		temp_ptr=new int[size+1];
		memcpy(temp_ptr,ptr,size*sizeof(int));
		temp_ptr[size++]=v;
		delete [] ptr;
		ptr=temp_ptr;
	}
	else
	{
		ptr=new int[1];
		ptr[size++]=v;
	
	}
	return;
}

CArray::CArray(const CArray & B)
{

	cout<<"copy constrator called"<<endl;
	if(B.ptr==NULL)
	{
		if(ptr)	delete [] ptr;
		ptr=NULL;
		size=0;	
	}
	else
	{
		if(ptr) delete [] ptr;
		size=B.size;
		ptr=new int[size];
		memcpy(ptr,B.ptr,size*sizeof(int));
	}	
}

CArray & CArray::operator=(const CArray & c)//must return & type or program error
{
	
	if(ptr==c.ptr)
		return *this;
	if(ptr!=NULL)
		delete [] ptr;
	if(c.ptr==NULL)
	{
		ptr=NULL;
		size=0;
		return *this;

	}

	ptr=new int[c.size];
	memcpy(ptr,c.ptr,c.size*sizeof(int));
	size=c.size;

	return *this;	


}
int & CArray::operator[](const int i)
{
	
	return ptr[i];	
}

int  main()
{

//	Complex a(3,3),b(1,1);
//	cout<< (a+b).real<<(a+b).imag <<endl;
//	cout<< (a-b).real <<endl;	
//	String s;
//	s="good luck!";//s.operator=("good luck")
//	cout << s.c_str()<<endl;


	CArray a;
	for(int i=0;i<5;++i)
	{
		a.push_back(i);

	}
	for(int i=0;i<a.length();++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;


	CArray a3,a2=a;
	for(int i=0;i<a.length();++i)
	{
		cout<<a2[i]<<" ";
	}
	cout<<endl;


	a2=a3;
	for(int i=0;i<a2.length();i++)
		cout<<a2[i]<<" ";
	cout<<endl;
/*	a3[3]=100;	
	CArray a4(a);
	for(int i=0;i<a4.length();i++)
		cout<<a4[i]<<" ";
	
*/
	return 0;

}
