#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char A[32],B[32],C[31],S[32];
	char X[32],Y[32];

    cout<<"������������������(ǰ�������0):"<<endl;
	cout<<"������A��ֵ:";
	cin>>X;
	cout<<"������B��ֵ:";
	cin>>Y;
	int x=strlen(X);
	int y=strlen(Y);

	int i,j;
	j=0;
	for(i=0;i<32-x;i++)
        A[i]='0';
    for(i=32-x;i<32;i++)
    {
        A[i]=X[j];
        j++;
    }
    cout<<"A=";
    for(i=0;i<32;i++)
        cout<<A[i];
    cout<<endl;
    j=0;
	for(i=0;i<32-y;i++)
        B[i]='0';
    for(i=32-y;i<32;i++)
    {
        B[i]=Y[j];
        j++;
    }
    cout<<"B=";
    for(i=0;i<32;i++)
        cout<<B[i];
    cout<<endl;

    for(i=0;i<31;i++)
        C[i]='0';
    j=0;
    for(i=32;i>=0;i--)
    {
        if((A[i]-48)+(B[i]-48)+(C[j]-48)==0)
        {
            S[i]='0';
            C[j+1]='0';
            j++;
        }
        else if((A[i]-48)+(B[i]-48)+(C[j]-48)==1)
        {
            S[i]='1';
            C[j+1]='0';
            j++;
        }
        else if((A[i]-48)+(B[i]-48)+(C[j]-48)==2)
        {
            S[i]='0';
            C[j+1]='1';
            j++;
        }
    }
    if(C[j]==C[j-1])
    {
        cout<<"û�����"<<endl;
        cout<<"Sum=";
        for(i=0;i<32;i++)
            cout<<S[i];
    }
    else if(C[j]!=C[j-1])
    {
        cout<<"���!"<<endl;
    }
    else
    {
        cout<<"ERROR!"<<endl;;
    }
}
