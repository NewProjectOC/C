#include"head.h"
using namespace std;
//���캯��
student::student(string num1="1500303111",string name1="�¼κ�",char sex1='m'):num(num1),name(name1),sex(sex1)
{

}
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
//��������
student::~student()
{
	sum--;
	num='\0';
	name='\0';
	sex='\0';
	classroom='\0';
	birth.tm_year=0;
	birth.tm_mon=0;
	cout <<"��������ѧ������-1";
	cout <<"ѧ������:"<<sum<<endl;
}