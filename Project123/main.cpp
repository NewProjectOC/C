#include"head.h"
using namespace std;
int student::sum=0;
int main()
{
	cout<<"15�����1��  �¼κ�  1500303111"<<endl;
	cout<<endl;
	int i;
	char j;
	cout<<endl;
	for(i=0;j!='*';i++)
	{
		student a;
		student i(a);
		i.setdate();
		i.display();
		i.renshu();
		fdisplay(i);
		cout<<endl;
		cout<<"�Ƿ����?(����*�������������)"<<endl;
		cin>>j;
	}
	return 0;
}
