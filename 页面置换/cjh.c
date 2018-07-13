#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
//#include <unistd.h>

#define PAGES 320                                               //ҳ���������
//#define M 3                                                     //������������
int M;
int page[PAGES];                                                //ҳ������ô�
//int rs[][PAGES];                                               //�洢�������

/*�����ṹ��*/
typedef struct
{
    int num;                                                    //�ÿ��������ҳ���
    int tm;                                                     //�����һ�ε�����������ʱ��
    int ntm;
}PBlock;

/*��ʼ�������ͽ������Ϊ-1*/
void init(PBlock *pb,int M)
{
    int i,j;
    for(i=0;i<M;i++)
    {
        pb[i].num=-1;
        pb[i].tm=-1;
        pb[i].ntm=-1;
        /*for(j=0; j<PAGES; j++)
            rs[i][j]=-1;*/
    }
}

/*����ʵ��Ҫ����һ����320����������飬��ŵ�ָ����������ʵ��Ҫ��*/
void createData()
{
    int s,i,j;
    srand(time(0)); /*ÿ������ʱ���̺Ų�ͬ��������Ϊ��ʼ����������еġ����ӡ�*/
    s=rand()%319+1;  //
    for(i=0;i<PAGES;i+=4) /*����ָ�����*/
    {
        if(s<0||s>319)
        {
            printf("When i==%d,Error,s==%d\n",i,s);
            exit(0);
        }
        page[i]=s;                            /*��ѡһָ����ʵ�m*/
        page[i+1]=page[i]+1;                     /*˳��ִ��һ��ָ��*/
        page[i+2]=rand( )%page[i]; /*ִ��ǰ��ַָ��m' */
        page[i+3]=page[i+2]+1;                   /*˳��ִ��һ��ָ��*/

        s=rand()%(319-page[i+2])+page[i+2]+1;
        if((page[i+2]>318)||(s>319))
            printf("page[%d+2],a number which is :%d and s==%d\n",i,page[i+2],s);
    }
    for(i=0;i<PAGES;i++)
        page[i]=page[i]/10;
    for(i=0;i<PAGES;i++)
        printf("%d ",page[i]);
    printf("\n");
}

/*��ӡ������飬�������û��ҳ���ʱ��ʾΪ'_'����ҳ���ʱ��ʾ����ҳ���*/
/*void printRs(int rs[][PAGES])
{
    int i,j;
    int m;
    for(i=0;i<M;i++)
    {
        for(j=0;j<PAGES;j++)
        {
            if(rs[i][j]==-1)
                printf("_   ");
            else
                printf("%d   ",rs[i][j]);
        }
        printf("\n");
    }
}*/

/*�ж�ҳ���Ϊnum��ҳ���Ƿ����ڴ����,���ڷ���1*/
int doExist(int num,PBlock *pb,int M)
{
    int i;
    int b=0;
    for(i=0;i<M;i++)
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
void FIFO(PBlock *pb,int M)
{
    int i;
    int qy=0;                                                   //ȱҳ����
    float qyl=0;                                                  //ȱҳ��
    int p=0;                                                    //�滻ָ��
    int index=0;                                                //ҳ�������
    while(index<PAGES)
    {
        if(!doExist(page[index],pb,M))                          //���������ڲ�����ҳ��ţ���˳��д��
        {
            pb[p].num=page[index];
            p=(p+1)%M;
            qy++;
            /*for(i=0;i<M;i++)
            {
                rs[i][index]=pb[i].num;
            }*/
        }
        index++;
    }
    printf("FIFO:\n");
    /*printf("�������Ϊ:\n");
    printRs(rs);*/
    printf("\tFIFO�㷨ȱҳ����Ϊ: %d\n",qy);
    qyl=(float)qy/PAGES;
    //printf("\tFIFO�㷨ȱҳ��Ϊ: %.4f \n",qyl);
    printf("\thit rate= %.4f \n",1-(float)qy/320);
}

/*���������δʹ�õ�ҳ��Ŀ��*/
int selectByTm(PBlock *pb,int p,int M)
{
    int i,j;
    PBlock temp;
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
        for(i=0;i<M-1;i++)
        {
            if(pb[i].tm>pb[i+1].tm)
            {
                temp=pb[i];
                pb[i]=pb[i+1];
                pb[i+1]=temp;
            }
        }
        p=M-1;
    }
    return p;
}

/*LRU �㷨*/
void LRU(PBlock *pb,int M)
{
    int i;
    int qy=0;                                                   //ȱҳ����
    float qyl=0;                                                  //ȱҳ��
    int p=0;                                                    //�滻ָ��
    int index=0;                                                //ҳ�������
    while(index<PAGES)
    {
        if(!doExist(page[index],pb,M))                          //���������ڲ�����ҳ��ţ���ʹÿ��������tm++
        {
            for(i=0;i<M;i++)                                                       //Ȼ��ͨ��selectByTm����ѡ��Ҫ�滻��ҳ��ţ�����tmΪ0
                if(pb[i].num!=-1)
                    pb[i].tm++;
            p=selectByTm(pb,p,M);
            pb[p].num=page[index];
            pb[p].tm=0;
            qy++;
            /*for(i=0;i<M;i++)
            {
                rs[i][index]=pb[i].num;
            }*/
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
    printf("LRU:\n");
    /*printf("�������Ϊ:\n");
    printRs(rs);*/
    printf("\tLRU�㷨ȱҳ����Ϊ: %d \n",qy);
    qyl=(float)qy/PAGES;
    //printf("\tLRU�㷨ȱҳ��Ϊ: %.4f\n",qyl);
    printf("\thit rate= %.4f \n",1-(float)qy/320);
}

/*����ʱ���ڲ���ʹ�õ�ҳ��Ŀ��*/
int selectByOpt(PBlock *pb,int index,int p,int M)
{
    int i,j;
    PBlock temp;
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
        for(i=0;i<M-1;i++)
        {
            if(pb[i].ntm>pb[i+1].ntm)
            {
                temp=pb[i];
                pb[i]=pb[i+1];
                pb[i+1]=temp;
            }
        }
        p=M-1;
    }
    return p;
}

/*OPT�㷨*/
void OPT(PBlock *pb,int M)
{
    int i;
    int qy=0;                                                   //ȱҳ����
    float qyl=0;                                                  //ȱҳ��
    int p=0;                                                    //�滻ָ��
    int index=0;                                                //ҳ�������
    while(index<PAGES)
    {
        if(!doExist(page[index],pb,M))                          //���������ڲ�����ҳ���
        {
            p=selectByOpt(pb,index,p,M);
            //printf("[%d] ",p);
            pb[p].ntm=1000;
            pb[p].num=page[index];
            qy++;
            /*for(i=0;i<M;i++)
            {
                rs[i][index]=pb[i].num;
            }*/
        }
        index++;
    }
    printf("OPT:\n");
    /*printf("�������Ϊ:\n");
    printRs(rs);*/
    printf("\tOPT�㷨ȱҳ����Ϊ: %d \n",qy);
    qyl=(float)qy/PAGES;
    //printf("\tOPT�㷨ȱҳ��Ϊ: %.4f\n",qyl);
    printf("\thit rate= %.4f \n",1-(float)qy/320);
}

int main()
{
    createData();
    //printf("�������Ϊ %d ,ҳ�������Ϊ:\n",M);
    /*for(i=0;i<PAGES;i++)
        printf("%d  ",page[i]);
    printf("\n\n");*/
    for(M=4;M<33;M++)
    {
        printf("*************�������Ϊ: %d ***********\n",M);
        //int rs[M][PAGES];
        PBlock pb[M];
        init(pb,M);
        FIFO(pb,M);
        init(pb,M);
        LRU(pb,M);
        init(pb,M);
        OPT(pb,M);
    }

    return 0;
}
