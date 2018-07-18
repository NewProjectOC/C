#include<iostream>
using namespace std;
#include<string>
#include<cstdlib>
#include<ctime>
template<typename T>
int paixu(T *p,int n)
{
	int i,j;
	T temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(*(p+i)>*(p+j))
			{
				temp=*(p+i);
				*(p+i)=*(p+j);
				*(p+j)=temp;
			}
		}
	}
	for(i=0;i<n;i++)
		cout<<*(p+i)<<" ";
	cout<<endl;
	return 0;
	return 0;
}
int main()
{
	cout<<"15¼ÆËã»ú1°à ³Â¼ÎºÀ 1500303111"<<endl;
	int n;
	srand(time(0));
	n=rand()%9+2;
	cout<<"n="<<n<<endl;
	int i=n;
	int *o,a[10];
	for(i=0;i<n;i++)
	{
		a[i]=rand();
	}
	o=a;
	cout<<"int:   ";
	paixu(o,n);
	float *p,b[10];
	for(i=0;i<n;i++)
	{
		b[i]=(float)rand()/100;
	}
	p=b;
	cout<<"float:   ";
	paixu(p,n);
	double *q,c[10];
	for(i=0;i<n;i++)
	{
		c[i]=(double)rand()/1000000;
	}
	q=c;
	cout<<"double:   ";
	paixu(q,n);
	string *r,d[10];
	for(i=0;i<n;i++)
	{
		d[i]=rand()%26+65;
	}
	r=d;
	cout<<"string:   ";
	paixu(r,n);
	return 0;
}