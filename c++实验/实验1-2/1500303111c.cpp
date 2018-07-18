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
		 cout<<"请输入该学生的学号:";
		 cin>>num;
		 cout<<endl;
		 cout<<"请输入该学生的姓名:";
		 cin>>name;
		 cout<<endl;
		 cout<<"请输入该学生的出生年份:";
		 cin>>birthyear;
		 cout<<endl;
		 cout<<"请输入该学生的出生月份:";
		 cin>>birthmonth;
		 cout<<endl;
		 cout<<"请输入该学生科目1的名称:";
		 cin>>class1;
		 cout<<endl;
		 cout<<"请输入该学生该科成绩:";
		 cin>>score1;
		 cout<<endl;
		 cout<<"请输入该学生该科学分:";
		 cin>>xuefen1;
		 cout<<endl;
		 cout<<"请输入该学生科目2的名称:";
		 cin>>class2;
		 cout<<endl;
		 cout<<"请输入该学生该科成绩:";
		 cin>>score2;
		 cout<<endl;
		 cout<<"请输入该学生该科学分:";
		 cin>>xuefen2;
		 cout<<endl;
	 }
	 void display()
	 {
		 cout<<"num:"<<num<<endl;
		 cout<<"name:"<<name<<endl;
		 cout<<"birth:"<<birthyear<<"年"<<birthmonth<<"月"<<endl;
		 cout<<"科目1:"<<class1<<"   成绩:"<<score1<<"   学分:"<<xuefen1<<endl;
		 cout<<"科目2:"<<class2<<"   成绩:"<<score2<<"   学分:"<<xuefen2<<endl;
		 cout<<endl;
	 }
	 int age()
	 {
		 int a;
		 a=2016-birthyear+1;
		 cout<<"年龄:"<<a;
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
	cout<<"15计算机1班"<<" 1500303111 "<<"陈嘉豪"<<endl;
	cout<<"**********请输入第一名学生的有关信息**********"<<endl;
	s1.set();
	cout<<"**********请输入第二名学生的有关信息**********"<<endl;
	s2.set();
	s1.display();
	s2.display();
	cout<<"*****************************************************************"<<endl;
	cout<<"第一名学生的年龄:"<<s1.age()<<endl;
	cout<<"第二名学生的年龄:"<<s2.age()<<endl;
	cout<<"第一名学生的平均绩点:"<<s1.ave()<<endl;
	cout<<"第二名学生的平均绩点:"<<s2.ave()<<endl;
	cout<<"*****************************************************************"<<endl;
	cout<<"交换两门课程的成绩后"<<endl;
	s1.exchange();
	s2.exchange();
	s1.display();
	s2.display();
	return 0;
}

		

