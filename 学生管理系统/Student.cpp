#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>

using namespace std;

struct Lesson               //�ɼ���
{
    char lesson1[10];
    char lesson2[10];
    char lesson3[10];
    float grades1;
    float grades2;
    float grades3;
}L;

struct Student              //ѧ����
{
	int num;
	char name[10];
	Lesson L;
}s[40];

void IntiStudent(Student s[40])     //��ʼ��
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

int numbermax()         //��Ч��Ϣ��ĸ���
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

void VisitAll()         //�鿴������Ϣ
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
				cout<<"ѧ��:"<<s[i].num<<"\t����:"<<s[i].name<<"\t"<<s[i].L.grades1<<s[i].L.grades2<<s[i].L.grades3<<endl;
			}
	}
	for(j=0;j<numbermax();j++)
    {
        a1+=s[j].L.grades1;
        a2+=s[j].L.grades2;
        a3+=s[j].L.grades3;
    }
    m=numbermax();
    cout<<"ƽ����:/t/t/t"<<a1/m<<a2/m<<a3/m<<endl;
	fclose(fp);
}

void searchbynumber()       //��ѧ�Ų���
{
    int i;
    int x;
    printf("������Ҫ���ҵ�ѧ��:");
    scanf("%d",&x);
    for(i=0;i<numbermax();i++)
    {
        if(s[i].num==x)
        {
            cout<<"ѧ��:"<<s[i].num<<endl;
            cout<<"����:"<<s[i].name<<endl;
            cout<<s[i].L.lesson1<<":"<<s[i].L.grades1<<endl;
            cout<<s[i].L.lesson2<<":"<<s[i].L.grades2<<endl;
            cout<<s[i].L.lesson3<<":"<<s[i].L.grades3<<endl;
        }
    }
    if(i>=numbermax())
        printf("δ�ҵ�����Ϣ!");
}

void searchbyname()         //����������
{
    int i;
    char x[10];
    printf("������Ҫ���ҵ�����:");
    scanf("%s",x);
    for(i=0;i<numbermax();i++)
    {
        if(strcmp(s[i].name,x)==0)
        {
            cout<<"ѧ��:"<<s[i].num<<endl;
            cout<<"����:"<<s[i].name<<endl;
            cout<<s[i].L.lesson1<<":"<<s[i].L.grades1<<endl;
            cout<<s[i].L.lesson2<<":"<<s[i].L.grades2<<endl;
            cout<<s[i].L.lesson3<<":"<<s[i].L.grades3<<endl;
        }
    }
    if(i>=numbermax())
        printf("δ�ҵ�����Ϣ!");
}
void add()          //���
{
	FILE *fp;
	int i,l;
	printf("������Ҫ�¼����ѧ����Ϣ:(ѧ��,����,�ɼ�1,�ɼ�2,�ɼ�3)");
		scanf("%d%s%f%f%f",&s[]);
	if((fp=fopen("Student.txt","a"))==NULL)
	{
		printf("cannot open the file\n");
		exit(0);
	}
	for(i=4;i<10&&m[i].number!=0;i++)
	{
		fprintf(fp,"���:%d\n����:%s\n�۸�:%.2f\n���۴���:%d\n��������:%d\n\n\n",m[i].number,m[i].name,m[i].price,m[i].place,m[i].sum);
	}
	fclose(fp);
	printf("�뷵����ҳѡ��'�鿴������Ϣ'�Ժ˶�\n");
	printf("\n��Ҫ�ټ�һ���밴9,������ʾ�Ƿ񷵻���ҳ:");
	scanf("%d",&l);
	if(l==9)
		add();
	else
		return;
}
void Delete()           //ɾ��
{
	int i,k,l;
	printf("������Ҫɾ������Ϣ�ı��:");
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

	printf("\n�뷵����ҳѡ��'�鿴������Ϣ'�Ժ˶�");
	printf("\n\n��Ҫ�ٴ�ɾ��һ���밴9,������ʾ�Ƿ񷵻���ҳ:");
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
	printf("\n\t\t\t��ӭʹ��ѧ����Ϣ����ϵͳ\n");
	printf("\t\t\t\t\t\t\t����:�¼κ�");
	printf("\n********************************************************************************\n");
	printf("\t\t��ѡ��:\n");
	printf("\t\t1.�鿴������Ϣ\n");
	printf("\t\t2.����Ų�ѯ\n");
	printf("\t\t3.��������ѯ\n");
	printf("\t\t4.�¼����Ʒ\n");
	printf("\t\t5.ɾ����Ʒ\n");
	printf("\t\t6.�鿴������������\n");
	printf("\t\t7.��������\n");
	printf("ѡ��:");
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
				printf("��ѡ����ȷ��ѡ��,лл���\nѡ��:");
				break;
			}
	}
	if(k>=1&&k<7)
		printf("������ҳ�밴0,�����������:");
	scanf("%d",&a);
	if(a==0)
	{
		printf("\t��\n\t\tл\n\t\t\t��\n\t\t\t\t��\n\t\t\t\t\tʹ\n\t\t\t\t\t\t��\n\t\t\t\t\t\t\t��\n\t\t\t\t\t\t\t\t��\n\t\t\t\t\t\t\t\t\t��");
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
		fprintf(fp,"���:%d\n����:%s\n�۸�:%.2f\n���۴���:%d\n��������:%d\n\n\n",m[i].number,m[i].name,m[i].price,m[i].place,m[i].sum);
	}
	fclose(fp);
}
void main()
{
	int l;
	choose();
}

