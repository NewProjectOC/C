#include"head.h"
using namespace std;
void student::renshu()
{
	cout<<endl;
	sum++;
	cout<<"Ŀǰ������Ϊ:"<<sum<<endl;
}
void student::setdate()
{
	cout<<"������ѧ��:";
	cin>>num;
	cout<<endl;
	cout<<"����������:";
	cin>>name;
	cout<<endl;
	cout<<"�������Ա�(m/f):";
	cin>>sex;
	cout<<endl;
	cout<<"������༶:";
	cin>>classroom;
}
void student::display()
{
	cout<<endl;
	cout<<"ѧ��:"<<num<<endl;
	cout<<"����:"<<name<<endl;
	cout<<"�Ա�:"<<sex<<endl;
	cout<<"��������:"<<birth.tm_year<<"��"<<birth.tm_mon<<"��"<<endl;
}
student::student(const student &b)
{
	num=b.num;
	name=b.name;
	sex=b.sex;
	classroom=b.classroom;
	birth=b.birth;
}
void fdisplay(student &p)
{
	cout<<"�༶(��Ԫ):"<<p.classroom<<endl;
}
