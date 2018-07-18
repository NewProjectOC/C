#include"head.h"
using namespace std;
//构造函数
student::student(string num1="1500303111",string name1="陈嘉豪",char sex1='m'):num(num1),name(name1),sex(sex1)
{

}
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
//析构函数
student::~student()
{
	sum--;
	num='\0';
	name='\0';
	sex='\0';
	classroom='\0';
	birth.tm_year=0;
	birth.tm_mon=0;
	cout <<"已析构，学生人数-1";
	cout <<"学生人数:"<<sum<<endl;
}