#include"head.h"
using namespace std;
int student::sum=0;
int main()
{
	cout<<"15¼ÆËã»ú1°à  ³Â¼ÎºÀ  1500303111"<<endl;
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
		cout<<"ÊÇ·ñ¼ÌĞø?(ÊäÈë*½áÊø£¬·ñÔò¼ÌĞø)"<<endl;
		cin>>j;
	}
	return 0;
}
