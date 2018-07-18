#include<iostream>
#include<string>
#include<time.h>
using namespace std;
class student
{public:
	static int sum;
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
	~student();
 private:
	string num;
	string name;
	struct tm birth;
	char sex;
	string classroom;
};

class stuscore
{public:
	string classname;
    float score;
	float xuefen;
};
