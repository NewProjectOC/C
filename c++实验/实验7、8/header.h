#include<iostream>
#include<string>
#include<time.h>
#include<vector>
#include<math.h>
#include<cstdlib>
#include<fstream>

using namespace std;

class Shape		//定义基类Shape
{public:
	 virtual float Circumference() const {return 0.0;}		//虚函数
	 virtual float Area() const {return 0.0;}		//虚函数
	 virtual void ShapeName() const{}		//纯虚函数
	 virtual void PointIsIn() const{}		//纯虚函数
};

class Point:public Shape		//定义继承类Point，继承于Point
{public:
	 void setPoint();		//随机构造函数
	 virtual void ShapeName() const {cout<<"Point:";}		//对虚函数再定义
	 friend ostream & operator << (ostream &,const Point&);		//重载运算符<<

 protected:
	 float x,y;
};

class Circle:public Point		//定义继承类Circle，继承于Point
{public:
	 void setCircle();		//随机构造函数		
	 virtual float Circumference() const;
	 virtual float Area() const;
	 virtual void ShapeName() const {cout<<"Circle:";}		//对虚函数再定义
	 friend ostream & operator << (ostream &,const Circle&);		//重载运算符<<
	 virtual void PointIsIn() const;

protected:
	float r;
};

class Triangle:public Point		//定义继承类Triangle，继承于Point
{public:
	 void setTriangle();		//随机构造函数
	 virtual float Circumference() const;
	 virtual float Area() const;
	 virtual void ShapeName() const {cout<<"Triangle:";}		//对虚函数再定义
	 friend ostream & operator << (ostream &,const Triangle&);		//重载运算符<<
	 virtual void PointIsIn() const;

 protected:
	 float x1,x2,x3,y1,y2,y3;
};

class Rectangle:public Point		//定义继承类Rectangle，继承于Shape
{public:
	 void setRectangle();		//随机构造函数
	 virtual float Circumference() const;
	 virtual float Area() const;
	 virtual void ShapeName() const {cout<<"Rectangle:";}		//对虚函数再定义
	 friend ostream & operator << (ostream &,const Rectangle&);		//重载运算符<<
	 virtual void PointIsIn() const;

 protected:
	float x1,x2,y1,y2;
};
