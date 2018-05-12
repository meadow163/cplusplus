#include<iostream>
using namespace std;

class CRectangle
{
	private:
		int w,h;
		static int nTotalArea;
		static int nTotalNumber;//不属于特定对象
	public:
		CRectangle(int w_,int h_);
		~CRectangle();
		static void PrintTotal();//不属于特定对象，所以只能访问静态成员变量。 

		//void PrintTotal(); 
};


int CRectangle::nTotalArea=0;
int CRectangle::nTotalNumber=0;
CRectangle::CRectangle(int w_,int h_)
{

	this->w=w_;
	this->h=h_;

	//w=w_;
	//h=h_;
	nTotalNumber++;
	nTotalArea+=w*h;

}

CRectangle::~CRectangle()
{
	nTotalNumber--;
	this->nTotalArea-=w*h;

}
void CRectangle::PrintTotal()
{
	cout<<nTotalNumber<<","<<nTotalArea<<endl;

}


//知识点，复制构造函数的调用
class A
{

	public:
		A(){cout <<"A constructor called"<<endl;}
		A(A & )
		{
			cout<<"A copy contstructor called"<<endl;
		}

};

class B
{

	A a;

};

class Sample{

public:
	int value;
	void GetValue() const;//不能修改成员变量
	void func(){};
	Sample(){};

};
void Sample::GetValue() const
{

//	value=0;//wrong
//	func();//wrong

}

int main()
{

	//CRectangle r1(3,3),r2(2,2);
	//cout<<CRectangle::nTotalNumber<<endl;
	//CRectangle::PrintTotal();
//	cout<<CRectangle::w<<endl;
	//r1.PrintTotal();
	//B b1,b2(b1);
	//const Sample o;//常量对象不能修改成员变量，所以也不能调用非常量成员函	
	

	return 0;

}
