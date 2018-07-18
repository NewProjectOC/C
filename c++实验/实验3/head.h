#include<iostream>
#include<string>
#include<time.h>
using namespace std;
class student
{public:
	static int sum;
	void setdate();
	void display();
	student(const student &b);
	student()
	{
		birth.tm_year=1998;
		birth.tm_mon=3;
	}
	student(string num1="1500303111",string name1="³Â¼ÎºÀ",char sex1='m'):num(num1),name(name1),sex(sex1){}
	friend void fdisplay(student &p);
	~student();
 private:
	string num;
	string name;
	struct tm birth;
	char sex;
	string classroom;
	stuscore score[2];
};

class stuscore
{public:
	string classname;
    float score;
	float xuefen;
};
