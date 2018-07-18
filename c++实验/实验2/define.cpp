#include"head.h"
using namespace std;
void student::renshu()
{
	cout<<endl;
	sum++;
	cout<<"目前总人数为:"<<sum<<endl;
}
void student::setdate()
{
	cout<<"请输入学号:";
	cin>>num;
	cout<<endl;
	cout<<"请输入姓名:";
	cin>>name;
	cout<<endl;
	cout<<"请输入性别(m/f):";
	cin>>sex;
	cout<<endl;
	cout<<"请输入班级:";
	cin>>classroom;
}
void student::display()
{
	cout<<endl;
	cout<<"学号:"<<num<<endl;
	cout<<"姓名:"<<name<<endl;
	cout<<"性别:"<<sex<<endl;
	cout<<"出生年月:"<<birth.tm_year<<"年"<<birth.tm_mon<<"月"<<endl;
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
	cout<<"班级(友元):"<<p.classroom<<endl;
}
