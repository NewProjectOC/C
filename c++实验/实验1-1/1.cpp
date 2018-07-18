#include<iostream>
using namespace std;
#include<string>
#include<cstdlib>
#include<ctime>
int paixu(int *p,int n)
{
	int i,j,temp;
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
	cout<<"int:   ";
	for(i=0;i<n;i++)
		cout<<*(p+i)<<" ";
	cout<<endl;
	return 0;
}
float paixu(float *p,int n)
{
	int i,j;
	float temp;
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
	cout<<"float:   ";
	for(i=0;i<n;i++)
		cout<<*(p+i)<<" ";
	cout<<endl;
	return 0;
}
double paixu(double *p,int n)
{
	int i,j;
	double temp;
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
	cout<<"double:   ";
	for(i=0;i<n;i++)
		cout<<*(p+i)<<" ";
	cout<<endl;
	return 0;
}
int paixu(string *p,int n)
{
	int i,j;
	string temp;
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
	cout<<"string:   ";
	for(i=0;i<n;i++)
		cout<<*(p+i)<<" ";
	cout<<endl;
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
	paixu(o,n);
	float *p,b[10];
	for(i=0;i<n;i++)
	{
		b[i]=(float)rand()/100;
	}
	p=b;
	paixu(p,n);
	double *q,c[10];
	for(i=0;i<n;i++)
	{
		c[i]=(double)rand()/1000000;
	}
	q=c;
	paixu(q,n);
	string *r,d[10];
	for(i=0;i<n;i++)
	{
		d[i]=rand()%26+65;
	}
	r=d;
	paixu(r,n);
	return 0;
}
