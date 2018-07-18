#include<iostream>
using namespace std;

class Complex
{private:
	int real;
	int imag;

 public:
	Complex();
	
	Complex(int r,int i);

	Complex operator += (Complex &c1);

	Complex operator ++ ();

	Complex operator -- ();

	Complex operator = (Complex &c1);

	friend Complex operator + (Complex &c1,Complex &c2);

	friend Complex operator - (Complex &c1,Complex &c2);

	friend Complex operator * (Complex &c1,Complex &c2);

	friend Complex operator / (Complex &c1,Complex &c2);

	friend Complex operator == (Complex &c1,Complex &c2);

	friend Complex operator != (Complex &c1,Complex &c2);

	friend ostream& operator << (ostream&,Complex&);
};
