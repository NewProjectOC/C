#include"header.h"

using namespace std;

int main()
{
	cout << "1500303111     15�����1��      �¼κ�" << endl;
	int i;
	srand(time(0));

	cout << "***************************************************************************" << endl;
	vector<Point>p(3);		//��vector������������
	for(i=0;i<3;i++)
	{
		Shape *pt;
		pt=&p[i];
		p[i].ShapeName();		//��̬����
		p[i].setPoint();		//��̬����
		cout<<i+1<<":";
		cout<<p[i];
	}
	cout << "***************************************************************************" << endl;
	vector<Circle>s(3);		//��vector������������
	vector<float>Circle_Area(3);		//��vector������������
	vector<float>Circle_Circumference(3);		//��vector������������
	for(i=0;i<3;i++)
	{
		Shape *pt;
		pt=&s[i];
		s[i].ShapeName();		//��̬����
		s[i].setCircle();		//��̬����
		cout<<i+1<<":"<<s[i];
		cout<<"�ܳ�:"<<pt->Circumference()<<endl;		//��ָ�뽨����̬����
		cout<<"���:"<<pt->Area()<<endl;		//��ָ�뽨����̬����
		Circle_Area[i]=pt->Area();		//��ָ�뽨����̬����
		Circle_Circumference[i]=pt->Circumference();		//��ָ�뽨����̬����
		pt->PointIsIn();		//��ָ�뽨����̬����
	}
	cout << "***************************************************************************" << endl;
	vector<Triangle>t(3);		//��vector������������
	vector<float>Triangle_Area(3);		//��vector������������
	vector<float>Triangle_Circumference(3);		//��vector������������
	for (i=0;i<3;i++)
	{
		Shape *pt;
		pt = &t[i];
		t[i].ShapeName();		//��̬����
		t[i].setTriangle();		//��̬����
		cout<<i+1<<":"<<t[i];
		cout<<"�ܳ�:"<<pt->Circumference()<<endl;		//��ָ�뽨����̬����
		cout<<"���:"<<pt->Area()<<endl;		//��ָ�뽨����̬����
		Triangle_Area[i]=pt->Area();		//��ָ�뽨����̬����
		Triangle_Circumference[i]=pt->Circumference();		//��ָ�뽨����̬����
		pt->PointIsIn();		//��ָ�뽨����̬����
	}
	cout << "***************************************************************************" << endl;
	vector<Rectangle>q(3);		//��vector������������
	vector<float>Rectangle_Area(3);		//��vector������������
	vector<float>Rectangle_Circumference(3);		//��vector������������
	for(i=0;i<3;i++)
	{
		Shape *pt;
		pt=&q[i];
		q[i].ShapeName();		//��̬����
		q[i].setRectangle();		//��̬����
		cout<<i+1<<":"<<q[i];
		cout<<"�ܳ�:"<<pt->Circumference()<<endl;		//��ָ�뽨����̬����
		cout<<"���:"<<pt->Area()<<endl;		//��ָ�뽨����̬����
		Rectangle_Area[i]=pt->Area();		//��ָ�뽨����̬����
		Rectangle_Circumference[i] = pt->Circumference();		//��ָ�뽨����̬����
		pt->PointIsIn();		//��ָ�뽨����̬����
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
	cout<<endl<<"���ļ��ж�ȡ��Ϣ"<<endl;
	fstream fin("1500303111.txt",ios::in);
	vector<string>str(3*14);
	for (i=0;i<(3*14);i++)
	{
		fin>>str[i];
		cout<<str[i]<<endl;
	}

	system("pause");		//���ڽ�����д�������
	return 0;
}