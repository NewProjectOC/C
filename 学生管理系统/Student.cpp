#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>

using namespace std;

struct Lesson               //成绩类
{
    char lesson1[10];
    char lesson2[10];
    char lesson3[10];
    float grades1;
    float grades2;
    float grades3;
}L;

struct Student              //学生类
{
	int num;
	char name[10];
	Lesson L;
}s[40];

void IntiStudent(Student s[40])     //初始化
{
    int i;
    for(i=0;i<40;i++)
    {
        s[i].num=0;
        strcpy(s[i].L.lesson1,"\0");
        strcpy(s[i].L.lesson2,"\0");
        strcpy(s[i].L.lesson3,"\0");
        s[i].L.grades1=0.0;
        s[i].L.grades1=0.0;
        s[i].L.grades1=0.0;
    }
}

int numbermax()         //有效信息组的个数
{
	int i,a;
	a=0;
	for(i=0;i<40;i++)
	{
		if(s[i].num!=0)
			a++;
	}
	return a;
}

void VisitAll()         //查看完整信息
{
	FILE *fp;
	int i,j;
	float m;
	float a1,a2,a3;
	if((fp=fopen("Student.txt","r"))==NULL)
	{
		printf("cannot open the file\n");
	}
	for(i=0;i<numbermax();i++)
	{
		if(!feof(fp))
			{
			    cout<<"\t\t\t"<<s[i].L.lesson1<<"\t"<<s[i].L.lesson2<<"\t"<<s[i].L.lesson3<<endl;
				cout<<"学号:"<<s[i].num<<"\t姓名:"<<s[i].name<<"\t"<<s[i].L.grades1<<s[i].L.grades2<<s[i].L.grades3<<endl;
			}
	}
	for(j=0;j<numbermax();j++)
    {
        a1+=s[j].L.grades1;
        a2+=s[j].L.grades2;
        a3+=s[j].L.grades3;
    }
    m=numbermax();
    cout<<"平均分:/t/t/t"<<a1/m<<a2/m<<a3/m<<endl;
	fclose(fp);
}

void searchbynumber()       //按学号查找
{
    int i;
    int x;
    printf("请输入要查找的学号:");
    scanf("%d",&x);
    for(i=0;i<numbermax();i++)
    {
        if(s[i].num==x)
        {
            cout<<"学号:"<<s[i].num<<endl;
            cout<<"姓名:"<<s[i].name<<endl;
            cout<<s[i].L.lesson1<<":"<<s[i].L.grades1<<endl;
            cout<<s[i].L.lesson2<<":"<<s[i].L.grades2<<endl;
            cout<<s[i].L.lesson3<<":"<<s[i].L.grades3<<endl;
        }
    }
    if(i>=numbermax())
        printf("未找到该信息!");
}

void searchbyname()         //按姓名查找
{
    int i;
    char x[10];
    printf("请输入要查找的姓名:");
    scanf("%s",x);
    for(i=0;i<numbermax();i++)
    {
        if(strcmp(s[i].name,x)==0)
        {
            cout<<"学号:"<<s[i].num<<endl;
            cout<<"姓名:"<<s[i].name<<endl;
            cout<<s[i].L.lesson1<<":"<<s[i].L.grades1<<endl;
            cout<<s[i].L.lesson2<<":"<<s[i].L.grades2<<endl;
            cout<<s[i].L.lesson3<<":"<<s[i].L.grades3<<endl;
        }
    }
    if(i>=numbermax())
        printf("未找到该信息!");
}
void add()          //添加
{
	FILE *fp;
	int i,l;
	printf("请输入要新加入的学生信息:(学号,姓名,成绩1,成绩2,成绩3)");
		scanf("%d%s%f%f%f",&s[]);
	if((fp=fopen("Student.txt","a"))==NULL)
	{
		printf("cannot open the file\n");
		exit(0);
	}
	for(i=4;i<10&&m[i].number!=0;i++)
	{
		fprintf(fp,"编号:%d\n菜名:%s\n价格:%.2f\n出售窗口:%d\n当季销量:%d\n\n\n",m[i].number,m[i].name,m[i].price,m[i].place,m[i].sum);
	}
	fclose(fp);
	printf("请返回主页选择'查看完整信息'以核对\n");
	printf("\n若要再加一条请按9,否则将提示是否返回首页:");
	scanf("%d",&l);
	if(l==9)
		add();
	else
		return;
}
void Delete()           //删除
{
	int i,k,l;
	printf("请输入要删除的信息的编号:");
	scanf("%d",&k);
	for(i=0;i<numbermax();i++)
	{
		if(k==m[i].number)
		{
			m[i].number=m[i+1].number;
			strcpy(m[i].name,m[i+1].name);
			m[i].place=m[i+1].place;
			m[i].price=m[i+1].price;
			m[i].sum=m[i+1].sum;
		}
		else
			continue;
	}

	printf("\n请返回首页选择'查看完整信息'以核对");
	printf("\n\n若要再次删除一条请按9,否则将提示是否返回首页:");
	scanf("%d",&l);
	if(l==9)
		deleTe();
	else
		return;
}

void choose()
{
	int k,a;
	printf("\n********************************************************************************\n");
	printf("\n\t\t\t欢迎使用学生信息管理系统\n");
	printf("\t\t\t\t\t\t\t作者:陈嘉豪");
	printf("\n********************************************************************************\n");
	printf("\t\t请选择:\n");
	printf("\t\t1.查看完整信息\n");
	printf("\t\t2.按编号查询\n");
	printf("\t\t3.按菜名查询\n");
	printf("\t\t4.新加入菜品\n");
	printf("\t\t5.删除菜品\n");
	printf("\t\t6.查看当季销量排行\n");
	printf("\t\t7.结束程序\n");
	printf("选择:");
	scanf("%d",&k);
	switch(k)
	{
		case 1:lookmenu();
		    break;
		case 2:searchbynumber();
			break;
		case 3:searchbyname();
			break;
		case 4:add();
			break;
		case 5:deleTe();
			break;
		case 6:rank();
			break;
		case 7:
			return;
		default:
			{
				printf("请选择正确的选项,谢谢配合\n选择:");
				break;
			}
	}
	if(k>=1&&k<7)
		printf("返回首页请按0,否则结束程序:");
	scanf("%d",&a);
	if(a==0)
	{
		printf("\t感\n\t\t谢\n\t\t\t再\n\t\t\t\t次\n\t\t\t\t\t使\n\t\t\t\t\t\t用\n\t\t\t\t\t\t\t本\n\t\t\t\t\t\t\t\t程\n\t\t\t\t\t\t\t\t\t序");
		choose();
	}
	else
		return;
}
void chushihua()
{
	FILE *fp;
	int i;
	if((fp=fopen("menu.txt","w"))==NULL)
	{
		printf("cannot open the file\n");
		exit(0);
	}
	for(i=0;i<10;i++)
	{
		fprintf(fp,"编号:%d\n菜名:%s\n价格:%.2f\n出售窗口:%d\n当季销量:%d\n\n\n",m[i].number,m[i].name,m[i].price,m[i].place,m[i].sum);
	}
	fclose(fp);
}
void main()
{
	int l;
	choose();
}

