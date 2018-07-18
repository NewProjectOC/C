#include<iostream>
#include<string>
#include<time.h>
using namespace std;
class student
{public:
	string num;
	string name;
	struct tm birth;
	char sex;	
	void renshu();
	void setdate();
	void display();
	student(const student &b);
	student()
	{
		birth.tm_year=1998;
		birth.tm_mon=3;
	}
	friend void fdisplay(student &p);
	~student()
	{
		 cout<<endl;
		 cout<<"ÒÑÎö¹¹"<<endl;
	}
 private:
	static int sum;
	string classroom;	 
};