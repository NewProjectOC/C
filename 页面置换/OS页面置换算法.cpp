#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PAGES 20                                                //ҳ���������
#define M 3                                                     //������������

int page[PAGES]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};      //ҳ������ô�
int rs[M][PAGES];                                               //�洢�������

/*�����ṹ��*/
typedef struct
{
    int num;                                                    //�ÿ��������ҳ���
    int tm;                                                     //�����һ�ε�����������ʱ��
    int ntm;
}PBlock;

/*��ʼ�������ͽ������Ϊ-1*/
void init(PBlock *pb)
{
    int i,j;
    for(i=0;i<M;i++)
    {
        pb[i].num=-1;
        pb[i].tm=-1;
        pb[i].ntm=-1;
        for(j=0; j<PAGES; j++)
            rs[i][j]=-1;
    }
}

/*����ʵ��Ҫ����һ����320����������飬��ŵ�ָ����������ʵ��Ҫ��*/
/*void createData()
{
    int s,i;
    int a[320];
    srand(time(0));                                             //��ʼ������
    s=rand()%320;
    for(i=0;i<320;i+=4)                                         //����ָ�����
    {
        if(s<0||s>319)
        {
            printf("When i==%d,Error,s==%d\n",i,s);
            exit(0);
        }
        a[i]=s;                                                 //��ѡһָ����ʵ�m
        a[i+1]=a[i]+1;                                          //˳��ִ��һ��ָ��
        a[i+2]=rand()%(a[i+1]);                                 //ִ��ǰ��ַָ��m'
        a[i+3]=a[i+2]+1;                                        //˳��ִ��һ��ָ��

        s=a[i+3]+rand()%(318-a[i+3]);
        if((a[i+2]>318)||(s>319))
            printf("a[%d+2],a number which is :%d and s==%d\n",i,a[i+2],s);
    }
    for(i=0;i<320;i+=4)
    {
        printf("%d %d %d %d\n",a[i],a[i+1],a[i+2],a[i+3]);
    }
}*/

/*��ӡ������飬�������û��ҳ���ʱ��ʾΪ'_'����ҳ���ʱ��ʾ����ҳ���*/
void printRs(int rs[M][PAGES])
{
    int i,j;
    for(i=0;i<M;i++)
    {
        for(j=0;j<PAGES;j++)
        {
            if(rs[i][j]==-1)
                printf("_ ");
            else
                printf("%d ",rs[i][j]);
        }
        printf("\n");
    }
}

/*�ж�ҳ���Ϊnum��ҳ���Ƿ����ڴ����,���ڷ���1*/
int doExist(int num,PBlock *pb,int m)
{
    int i;
    int b=0;
    for(i=0;i<m;i++)
    {
        if(pb[i].num==num)
        {
            b=1;
            break;
        }
    }
    return b;
}

/*FIFO �㷨*/
int FIFO(PBlock *pb,int m)
{
    int i;
    int qy=0;                                                   //ȱҳ����
    float qyl;                                                  //ȱҳ��
    int p=0;                                                    //�滻ָ��
    int index=0;                                                //ҳ�������
    while(index<PAGES)
    {
        if(!doExist(page[index],pb,M))                          //���������ڲ�����ҳ��ţ���˳��д��
        {
            pb[p].num=page[index];
            p=(p+1)%M;
            qy++;
            for(i=0;i<M;i++)
            {
                rs[i][index]=pb[i].num;
            }
        }
        index++;
    }
    printf("**************** FIFO *******************\n");
    printf("�������Ϊ:\n");
    printRs(rs);
    printf("FIFO�㷨ȱҳ����Ϊ: %d\n",qy);
    qyl=(float)qy/PAGES;
    printf("FIFO�㷨ȱҳ��Ϊ: %.4f \n",qyl);
    printf("\n");
    return 0;
}

/*���������δʹ�õ�ҳ��Ŀ��*/
int selectByTm(PBlock *pb,int p)
{
    int i;
    bool notEmpty;
    notEmpty=true;
    for(i=0;i<M;i++)                                            //����������ڿգ���ֱ��ѡ���λ��
    {
        if(pb[i].tm==-1)
        {
            notEmpty=false;
            p=i;
            break;
        }
    }
    if(notEmpty)                                                //���ȫ������Ƚ����ǵ�tm��ѡ��tm����λ��
    {
        if(pb[0].tm>pb[1].tm&&pb[0].tm>pb[2].tm)
            p=0;
        else if(pb[1].tm>pb[0].tm&&pb[1].tm>pb[2].tm)
            p=1;
        else
            p=2;
    }
    return p;
}

/*LRU �㷨*/
void LRU(PBlock *pb,int m)
{
    int i;
    int qy=0;                                                   //ȱҳ����
    float qyl;                                                  //ȱҳ��
    int p=0;                                                    //�滻ָ��
    int index=0;                                                //ҳ�������
    while(index<PAGES)
    {
        if(!doExist(page[index],pb,m))                          //���������ڲ�����ҳ��ţ���ʹÿ��������tm++
        {                                                       //Ȼ��ͨ��selectByTm����ѡ��Ҫ�滻��ҳ��ţ�����tmΪ0
            for(i=0;i<M;i++)
            {
                if(pb[i].num!=-1)
                {
                    pb[i].tm++;
                }
            }
            p=selectByTm(pb,p);
            pb[p].num=page[index];
            pb[p].tm=0;
            qy++;
            for(i=0;i<M;i++)
            {
                rs[i][index]=pb[i].num;
            }
        }
        else                                                    //����Ѵ���ҳ��ţ���ʹ��Ӧλ�õ�tm++
        {
            for(i=0;i<M;i++)
            {
                if(pb[i].num==page[index])
                {
                    pb[i].tm=0;
                }
                else
                {
                    pb[i].tm++;
                }
            }
        }
        index++;
    }
    printf("**************** LRU *******************\n");
    printf("�������Ϊ:\n");
    printRs(rs);
    printf("LRU�㷨ȱҳ����Ϊ: %d \n",qy);
    qyl=(float)qy/PAGES;
    printf("LRU�㷨ȱҳ��Ϊ: %.4f\n",qyl);
    printf("\n");
}

/*����ʱ���ڲ���ʹ�õ�ҳ��Ŀ��*/
int selectByOpt(PBlock *pb,int index,int p)
{
    int i,j;
    bool notEmpty;
    notEmpty=true;
    for(i=0;i<M;i++)                                            //����������ڿգ���ֱ��ѡ���λ��
    {
        if(pb[i].ntm==-1)
        {
            notEmpty=false;
            p=i;
            break;
        }
    }
    if(notEmpty)                                                //���ȫ���������ҳ��Ŵ��ҵ��ٴγ��ֵ�λ��
    {                                                           //�ֱ��¼����������ntm��ѡ��������ΪҪ�滻��ҳ���
        for(i=0;i<M;i++)
        {
            for(j=index;j<PAGES;j++)
            {
                if(pb[i].num==page[j])
                {
                    pb[i].ntm=j;
                    break;
                }
                if(j==(PAGES-1)&&pb[i].num!=page[j])
                    pb[i].ntm=1000;
            }
        }
        /*for(i=0;i<M;i++)
        {
            printf("%d|",pb[i].ntm);
        }
        printf("\n");*/
        for(i=0;i<M;i++)
        {
            if(pb[0].ntm>pb[1].ntm&&pb[0].ntm>pb[2].ntm)
                p=0;
            else if(pb[1].ntm>pb[0].ntm&&pb[1].ntm>pb[2].ntm)
                p=1;
            else
                p=2;
        }

    }
    return p;
}

/*OPT�㷨*/
void OPT(PBlock *pb,int m)
{
    int i;
    int qy=0;                                                   //ȱҳ����
    float qyl;                                                  //ȱҳ��
    int p=0;                                                    //�滻ָ��
    int index=0;                                                //ҳ�������
    while(index<PAGES)
    {
        if(!doExist(page[index],pb,m))                          //���������ڲ�����ҳ���
        {
            p=selectByOpt(pb,index,p);
            //printf("[%d] ",p);
            pb[p].ntm=10000;
            pb[p].num=page[index];
            qy++;
            for(i=0;i<M;i++)
            {
                rs[i][index]=pb[i].num;
            }
        }
        else
        {

        }
        index++;
    }
    printf("**************** OPT *******************\n");
    printf("�������Ϊ:\n");
    printRs(rs);
    printf("OPT�㷨ȱҳ����Ϊ: %d \n",qy);
    qyl=(float)qy/PAGES;
    printf("OPT�㷨ȱҳ��Ϊ: %.4f\n",qyl);
    printf("\n");
}

int main()
{
    int i;
    PBlock pb[M];
    printf("�������Ϊ %d ,ҳ�������Ϊ:\n",M);
    for(i=0;i<20;i++)
        printf("%d  ",page[i]);
    printf("\n\n");
    init(pb);
    FIFO(pb,M);
    init(pb);
    LRU(pb,M);
    init(pb);
    OPT(pb,M);
    return 0;
}
