#include<iostream>
#include<string>
#include<time.h>
#include<vector>
#include<math.h>
#include<cstdlib>
#include<fstream>

using namespace std;

class Shape		//�������Shape
{public:
	 virtual float Circumference() const {return 0.0;}		//�麯��
	 virtual float Area() const {return 0.0;}		//�麯��
	 virtual void ShapeName() const{}		//���麯��
	 virtual void PointIsIn() const{}		//���麯��
};

class Point:public Shape		//����̳���Point���̳���Point
{public:
	 void setPoint();		//������캯��
	 virtual void ShapeName() const {cout<<"Point:";}		//���麯���ٶ���
	 friend ostream & operator << (ostream &,const Point&);		//���������<<

 protected:
	 float x,y;
};

class Circle:public Point		//����̳���Circle���̳���Point
{public:
	 void setCircle();		//������캯��		
	 virtual float Circumference() const;
	 virtual float Area() const;
	 virtual void ShapeName() const {cout<<"Circle:";}		//���麯���ٶ���
	 friend ostream & operator << (ostream &,const Circle&);		//���������<<
	 virtual void PointIsIn() const;

protected:
	float r;
};

class Triangle:public Point		//����̳���Triangle���̳���Point
{public:
	 void setTriangle();		//������캯��
	 virtual float Circumference() const;
	 virtual float Area() const;
	 virtual void ShapeName() const {cout<<"Triangle:";}		//���麯���ٶ���
	 friend ostream & operator << (ostream &,const Triangle&);		//���������<<
	 virtual void PointIsIn() const;

 protected:
	 float x1,x2,x3,y1,y2,y3;
};

class Rectangle:public Point		//����̳���Rectangle���̳���Shape
{public:
	 void setRectangle();		//������캯��
	 virtual float Circumference() const;
	 virtual float Area() const;
	 virtual void ShapeName() const {cout<<"Rectangle:";}		//���麯���ٶ���
	 friend ostream & operator << (ostream &,const Rectangle&);		//���������<<
	 virtual void PointIsIn() const;

 protected:
	float x1,x2,y1,y2;
};
