#include<iostream>
using namespace std;
#include<string>
#include<cstdlib>
#include<ctime>
struct Student
{
	int num;
	int score;
	char name;
};
int main()
{
	struct Student s[10];
	int i,j,temp;
	srand(time(0));
	for(i=0;i<10;i++)
	{
		s[i].num=i+1;
		s[i].score=rand()%100+1;
		s[i].name=rand()%26+65;
	}
	cout<<"15�����1�� �¼κ� 1500303111"<<endl;
	cout<<"********************************************"<<endl;
	cout<<"ѧ�� "<<"���� "<<"�ɼ�"<<"(��ѧ��)"<<endl;
	for(i=0;i<10;i++)
		cout<<s[i].num<<"     "<<s[i].name<<"     "<<s[i].score<<endl;
	cout<<"********************************************"<<endl;
	cout<<"ѧ�� "<<"���� "<<"�ɼ�"<<"(���ɼ�)"<<endl;
	for(i=0;i<10;i++)
		for(j=i+1;j<10;j++)
		{
			if(s[i].score>s[j].score)
			{	
				temp=s[i].score;
				s[i].score=s[j].score;
				s[j].score=temp;
				
				temp=s[i].name;
				s[i].name=s[j].name;
				s[j].name=temp;
				
				temp=s[i].num;
				s[i].num=s[j].num;
				s[j].num=temp;
			}
		}
	for(i=0;i<10;i++)
		cout<<s[i].num<<"     "<<s[i].name<<"     "<<s[i].score<<endl;
	cout<<"********************************************"<<endl;
	cout<<"ѧ�� "<<"���� "<<"�ɼ�"<<"(������)"<<endl;
	for(i=0;i<10;i++)
		for(j=i+1;j<10;j++)
		{
			if(s[i].name>s[j].name)
			{	
				temp=s[i].score;
				s[i].score=s[j].score;
				s[j].score=temp;
				
				temp=s[i].name;
				s[i].name=s[j].name;
				s[j].name=temp;
				
				temp=s[i].num;
				s[i].num=s[j].num;
				s[j].num=temp;
			}
		}
	for(i=0;i<10;i++)
		cout<<s[i].num<<"     "<<s[i].name<<"     "<<s[i].score<<endl;
	return 0;
}