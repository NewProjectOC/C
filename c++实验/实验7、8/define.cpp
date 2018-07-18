#include"header.h"

using namespace std;


void Point::setPoint()		//������ɵ�����
{
	x=(rand()%10+1)/2.0;
	y=(rand()%10+1)/2.0;
}
ostream &operator<<(ostream &output,const Point &b)
{
	output<<"("<<b.x<<","<<b.y<<")"<<endl;
	return output;
}

void Circle::setCircle()		//�������Բ��������뾶
{
	x=(rand()%10+1)/2.0;
	y=(rand()%10+1)/2.0;
	r=(rand()%10+1)/2.0;
}
float Circle::Circumference() const		//�����ܳ�
{
	return 2*3.14*r;
}
float Circle::Area() const		//�������
{
	return 3.14*r*r;
}
void Circle::PointIsIn() const		//�жϵ�λ��
{
	float a,b;
	cout<<"������������:"<<endl;
	cout<<"x=";
	cin>>a;
	cout<<"y=";
	cin>>b;

	if(sqrt((a-x)*(a-x)+(b-y)*(b-y))<r)
		cout<<"����Բ��"<<endl;
	else if(sqrt((a-x)*(a-x)+(b-y)*(b-y))==r)
		cout<<"����Բ��"<<endl;
	else
		cout<<"����Բ��"<<endl;
	cout<<endl;
}
ostream &operator<<(ostream &output,const Circle &b)
{
	output<<"Բ��:("<<b.x<<","<<b.y<<"),�뾶:"<<b.r<<endl;
	return output;
}

void Triangle::setTriangle()		//������������θ���������
{
	x1=rand()%15/1.5;
	y1=rand()%15/1.5;
	x2=rand()%15/1.5;
	y2=rand()%15/1.5;
	x3=rand()%15/1.5;
	y3=rand()%15/1.5;
}
float Triangle::Circumference() const		//�����ܳ�
{
	float m1,m2,m3;
	m1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	m2=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	m3=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	return m1+m2+m3;
}
float Triangle::Area() const		//�������
{
	float m;
	float m1,m2,m3;
	m1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	m2=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	m3=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	m=(m1+m2+m3)/2.0;
	return sqrt(m*(m-m1)*(m-m2)*(m-m3));
}
void Triangle::PointIsIn() const		//�жϵ�λ��
{
	float a,b;
	cout<<"������������:"<<endl;
	cout<<"x=";
	cin>>a;
	cout<<"y=";
	cin>>b;

	float s1,s2,s3,s;
	s1=(1/2)*(a*y2+x2*y3+x3*b-a*y3-x2*b-x3*y2);
	s2=(1/2)*(x1*b+a*y3+x3*y1-x1*y3-a*y1-x3*b);
	s3=(1/2)*(x1*y2+x2*b+a*y1-x1*b-x2*y1-a*y2);
	s=(1/2)*(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2);

	if(s1+s2+s3 == s)
		cout<<"������������"<<endl;
	else
		cout<<"�㲻����������"<<endl;
	cout<<endl;
}
ostream &operator<<(ostream &output,const Triangle &b)
{
	output<<"������������ֱ�Ϊ:"<<"("<<b.x1<<","<<b.y1<<"),"<<"("<<b.x2<<","<<b.y2<<"),"<<"("<<b.x3<<","<<b.y3<<")"<<endl;
	return output;
}

void Rectangle::setRectangle()		//������ɾ��ζԽ�������������
{
	x1=(rand()%10+2)/2.0;
	y1=(rand()%10+2)/2.0;
	x2=(rand()%10+2)/2.0;
	y2=(rand()%10+2)/2.0;
}
float Rectangle::Circumference() const		//�����ܳ�
{
	return 2*(abs(x2-x1)+abs(y2-y1));
}
float Rectangle::Area() const		//�������
{
	return (abs(x2-x1))*(abs(y2-y1));
}
void Rectangle::PointIsIn() const		//�жϵ�λ��
{
	float a,b;
	cout<<"������������:"<<endl;
	cout<<"x=";
	cin>>a;
	cout<<"y=";
	cin>>b;

	if((a>x1||a>x2)&&(a<x1||a<x2)&&(b>y1||b>y2)&&(b<y1||b<y2))
	{
		cout << "���ھ�����" << endl;
	}
	else
	{
		cout << "�㲻�ھ�����" << endl;
	}
	cout<<endl;
}
ostream &operator<<(ostream &output,const Rectangle &b)
{
	output<<"�Խ����ϵ���������:"<<"("<<b.x1<<","<<b.y1<<"),"<<"("<<b.x2<<","<<b.y2<<")"<<endl;
	return output;
}