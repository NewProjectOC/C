#include"head.h"
using namespace std;

Complex::Complex()
{
	real=0;
	imag=0;
}
Complex::Complex(int r,int i)
{
	real=r;
	imag=i;
}
Complex Complex::operator + (Complex &c1,Complex &c2)
{
	Complex c;
	c.real=c1.real+c2.real;
	c.imag=c1.imag+c2.imag;
	return c;
}
Complex Complex::operator - (Complex &c1,Complex &c2)
{
	Complex c;
	c.real=c1.real-c2.real;
	c.imag=c1.imag-c2.imag;
	return c;
}
Complex Complex::operator * (Complex &c1,Complex &c2)
{
	Complex c;
	c.real=c1.real*c2.real-c1.imag*c2.imag;
	c.imag=c1.imag*c2.real+c1.real*c2.imag;
	return c;
}
Complex Complex::operator / (Complex &c1,Complex &c2)
{
	Complex c;
	c.real=(c1.real*c2.real+c1.imag*c2.imag)/(c2.real*c2.real+c2.imag*c2.imag);
	c.imag=(c1.imag*c2.real-c1.real*c2.imag)/(c2.real*c2.real+c2.imag*c2.imag);0
	return c;
}
Complex Complex::operator == (Complex &c1,Complex &c2)
{
	if (c1.real==c2.real&&c1.imag==c2.imag)
		return 1;
	else
		return 0;
}
Complex Complex::operator != (Complex &c1,Complex &c2)
{
	if (c1.real==c2.real&&c1.imag==c2.imag)
		return 0;
	else
		return 1;
}
ostream& operator << (ostream &output,Complex &c)
{
	output<<"("<<real<<")"<<"+("<<imag<<")i"<<endl;
}
Complex Complex::operator += (Complex &c1)
{
	Complex c;
	c.real+=c1.real;
	c.imag+=c1.imag;
	return c;
}
Complex Complex::operator ++ ()
{
	Complex c;
	c.real=c.real+1;
	c.imag=c.imag+1;
	return c;
}
Complex Complex::operator -- ()
{
	Complex c;
	c.real=c.real-1;
	c.imag=c.imag-1;
	return c;
}
Complex Complex::operator = (Complex &c1)
{
	Complex c;
	c.real=c1.real;
	c.imag=c1.imag;
	return c;
}