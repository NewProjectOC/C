#include<iostream>
#include<string>
using namespace std;
struct Student
{private:
	 int num;
	 string name;
	 int birthyear;
	 int birthmonth;
	 string class1;
	 string class2;
	 float score1;
	 float score2;
	 float xuefen1;
	 float xuefen2;
 public:
	 void set()
	 {
		 cout<<"�������ѧ����ѧ��:";
		 cin>>num;
		 cout<<endl;
		 cout<<"�������ѧ��������:";
		 cin>>name;
		 cout<<endl;
		 cout<<"�������ѧ���ĳ������:";
		 cin>>birthyear;
		 cout<<endl;
		 cout<<"�������ѧ���ĳ����·�:";
		 cin>>birthmonth;
		 cout<<endl;
		 cout<<"�������ѧ����Ŀ1������:";
		 cin>>class1;
		 cout<<endl;
		 cout<<"�������ѧ���ÿƳɼ�:";
		 cin>>score1;
		 cout<<endl;
		 cout<<"�������ѧ���ÿ�ѧ��:";
		 cin>>xuefen1;
		 cout<<endl;
		 cout<<"�������ѧ����Ŀ2������:";
		 cin>>class2;
		 cout<<endl;
		 cout<<"�������ѧ���ÿƳɼ�:";
		 cin>>score2;
		 cout<<endl;
		 cout<<"�������ѧ���ÿ�ѧ��:";
		 cin>>xuefen2;
		 cout<<endl;
	 }
	 void display()
	 {
		 cout<<"num:"<<num<<endl;
		 cout<<"name:"<<name<<endl;
		 cout<<"birth:"<<birthyear<<"��"<<birthmonth<<"��"<<endl;
		 cout<<"��Ŀ1:"<<class1<<"   �ɼ�:"<<score1<<"   ѧ��:"<<xuefen1<<endl;
		 cout<<"��Ŀ2:"<<class2<<"   �ɼ�:"<<score2<<"   ѧ��:"<<xuefen2<<endl;
		 cout<<endl;
	 }
	 int age()
	 {
		 int a;
		 a=2016-birthyear+1;
		 cout<<"����:"<<a;
		 return a;
	 }
	 float ave()
	 {
		 float a;
		 a=(float)(xuefen1*(float)(score1/10-5)+xuefen2*(float)(score2/10-5))/(xuefen1+xuefen2);
		 return a;
	 }
	 void swap(float &a,float &b)
	 {
		 float temp=a;
		 a=b;
		 b=temp;
	 }
	 void exchange()
	 {
		 swap(score1,score2);
	 }
};
Student s1,s2;
int main()
{	
	cout<<"15�����1��"<<" 1500303111 "<<"�¼κ�"<<endl;
	cout<<"**********�������һ��ѧ�����й���Ϣ**********"<<endl;
	s1.set();
	cout<<"**********������ڶ���ѧ�����й���Ϣ**********"<<endl;
	s2.set();
	s1.display();
	s2.display();
	cout<<"*****************************************************************"<<endl;
	cout<<"��һ��ѧ��������:"<<s1.age()<<endl;
	cout<<"�ڶ���ѧ��������:"<<s2.age()<<endl;
	cout<<"��һ��ѧ����ƽ������:"<<s1.ave()<<endl;
	cout<<"�ڶ���ѧ����ƽ������:"<<s2.ave()<<endl;
	cout<<"*****************************************************************"<<endl;
	cout<<"�������ſγ̵ĳɼ���"<<endl;
	s1.exchange();
	s2.exchange();
	s1.display();
	s2.display();
	return 0;
}

		

