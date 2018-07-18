#include"header.h"

using namespace std;

int main()
{
	cout << "1500303111     15计算机1班      陈嘉豪" << endl;
	int i;
	srand(time(0));

	cout << "***************************************************************************" << endl;
	vector<Point>p(3);		//用vector生成三组数据
	for(i=0;i<3;i++)
	{
		Shape *pt;
		pt=&p[i];
		p[i].ShapeName();		//静态关联
		p[i].setPoint();		//静态关联
		cout<<i+1<<":";
		cout<<p[i];
	}
	cout << "***************************************************************************" << endl;
	vector<Circle>s(3);		//用vector生成三组数据
	vector<float>Circle_Area(3);		//用vector生成三组数据
	vector<float>Circle_Circumference(3);		//用vector生成三组数据
	for(i=0;i<3;i++)
	{
		Shape *pt;
		pt=&s[i];
		s[i].ShapeName();		//静态关联
		s[i].setCircle();		//静态关联
		cout<<i+1<<":"<<s[i];
		cout<<"周长:"<<pt->Circumference()<<endl;		//用指针建立动态关联
		cout<<"面积:"<<pt->Area()<<endl;		//用指针建立动态关联
		Circle_Area[i]=pt->Area();		//用指针建立动态关联
		Circle_Circumference[i]=pt->Circumference();		//用指针建立动态关联
		pt->PointIsIn();		//用指针建立动态关联
	}
	cout << "***************************************************************************" << endl;
	vector<Triangle>t(3);		//用vector生成三组数据
	vector<float>Triangle_Area(3);		//用vector生成三组数据
	vector<float>Triangle_Circumference(3);		//用vector生成三组数据
	for (i=0;i<3;i++)
	{
		Shape *pt;
		pt = &t[i];
		t[i].ShapeName();		//静态关联
		t[i].setTriangle();		//静态关联
		cout<<i+1<<":"<<t[i];
		cout<<"周长:"<<pt->Circumference()<<endl;		//用指针建立动态关联
		cout<<"面积:"<<pt->Area()<<endl;		//用指针建立动态关联
		Triangle_Area[i]=pt->Area();		//用指针建立动态关联
		Triangle_Circumference[i]=pt->Circumference();		//用指针建立动态关联
		pt->PointIsIn();		//用指针建立动态关联
	}
	cout << "***************************************************************************" << endl;
	vector<Rectangle>q(3);		//用vector生成三组数据
	vector<float>Rectangle_Area(3);		//用vector生成三组数据
	vector<float>Rectangle_Circumference(3);		//用vector生成三组数据
	for(i=0;i<3;i++)
	{
		Shape *pt;
		pt=&q[i];
		q[i].ShapeName();		//静态关联
		q[i].setRectangle();		//静态关联
		cout<<i+1<<":"<<q[i];
		cout<<"周长:"<<pt->Circumference()<<endl;		//用指针建立动态关联
		cout<<"面积:"<<pt->Area()<<endl;		//用指针建立动态关联
		Rectangle_Area[i]=pt->Area();		//用指针建立动态关联
		Rectangle_Circumference[i] = pt->Circumference();		//用指针建立动态关联
		pt->PointIsIn();		//用指针建立动态关联
	}
	cout << "***************************************************************************" << endl;

	fstream outfile; 
	outfile.open("1500303111.txt", ios::out);
	if(!outfile.is_open())
	{
		cout<<"open error"<<endl;
		return 0;
	}
	for(i=0;i<3;i++)
	{
		outfile<<"Point"<<i+1<<":"<<p[i]<<endl;
	}
	outfile<<endl<<endl;
	for(i=0;i<3;i++)
	{
		outfile<<"Circle"<<i+1<<":"<<s[i]<<"Circumference="<<Circle_Circumference[i]<<endl<<"Area="<<Circle_Area[i]<<endl;
	}
	outfile << endl << endl;
	for (i = 0; i < 3; i++)
	{
		outfile<<"Triangle"<<i+1<<":"<<t[i]<<"Circumference="<<Triangle_Circumference[i]<<endl<<"Area="<<Triangle_Area[i]<<endl;
	}
	outfile<<endl<<endl;
	for(i=0;i<3;i++)
	{
		outfile<<"Rectangle"<<i+1<<":"<<q[i]<<"Circumference="<<Rectangle_Circumference[i]<<endl<<"Area="<<Rectangle_Area[i]<<endl;
	}
	outfile.close();
	cout<<endl<<"从文件中读取信息"<<endl;
	fstream fin("1500303111.txt",ios::in);
	vector<string>str(3*14);
	for (i=0;i<(3*14);i++)
	{
		fin>>str[i];
		cout<<str[i]<<endl;
	}

	system("pause");		//用于解决运行窗口闪退
	return 0;
}