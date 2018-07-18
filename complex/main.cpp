#include"head.h"
using namespace std;

int main()
{
	cout<<"1500303111    ³Â¼ÎºÀ     15¼ÆËã»ú1°à"<<endl;
	cout<<endl;

	Complex<int>n1(3,2);
	cout<<"n1=";
	n1.display();
	Complex<int>n2(4,6);
	cout<<"n2=";
	n2.display();
	Complex<int>n3;
	cout<<"n1+n2=";
	n3=n1+n2;
	n3.display();

	cout<<endl;

	Complex <double> n4(1.2,3.8);
	cout<<"n4=";
	n4.display();
	Complex <double> n5(4.7,2.6);
	cout<<"n5=";
	n5.display();
	Complex <double> n6;
	cout<<"n4*n5=";
	n6=n6.mul(n4,n5);
	n6.display();
	cout<<endl;

	/*Complex<double>n4(1.2,2.1);
	cout<<"n4=";
	n4.display();
	Complex<double>n5(4.2,3.3);
	cout<<"n5=";
	n5.display();
	Complex<double>n6;
	cout<<"n1+n2=";
	n6=n4*n5;
	n6.display();*/

	cout<<endl;

	return 0;
}