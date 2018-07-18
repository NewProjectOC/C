#include<iostream>
using namespace std;
template<class T>
class Complex
{private:
	T real;
	T imag;
public:
	Complex()
	{
		real=0;
		imag=0;
	}
	Complex(T r,T i)
	{
		real=r;
		imag=i;
	}
	template<class T>
	friend Complex<T> operator + (Complex<T> &c1,Complex <T> &c2);
	//friend Complex<T> operator * (Complex<T> &c1,Complex <T> &c2);
	void display()
	{
		cout<<'('<<real<<')'<<'+'<<'('<<imag<<')'<<'i'<<endl;
	}
	Complex mul(Complex<T> &a ,Complex<T> &b)
	 {
		Complex <T> n;
		n.real=a.real*b.real-a.imag*b.imag;
		n.imag=a.imag*b.real+a.real*b.imag;
		return n;
	 }
};
template<class T>
Complex<T> operator + (Complex<T> &c1,Complex <T> &c2)
{
	Complex<T>c;
	c.real = c1.real + c2.real;
	c.imag = c1.imag + c2.imag;
	return c;
}

/*template<class T>
Complex<T> operator * (Complex<T> &c1,Complex <T> &c2)
{
	Complex<T>c;
	c.real = c1.real*c2.real-c1.imag*c2.imag;
	c.imag = c1.real*c2.imag+c2.real*c1.imag;
	return c;
}*/