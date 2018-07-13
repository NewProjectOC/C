#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PAGES 20                                                //页面号引用数
#define M 3                                                     //分配的物理块数

int page[PAGES]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};      //页面号引用串
int rs[M][PAGES];                                               //存储结果数组

/*物理块结构体*/
typedef struct
{
    int num;                                                    //该块中所存的页面号
    int tm;                                                     //从最近一次调入所经历的时间
    int ntm;
}PBlock;

/*初始化物理块和结果数组为-1*/
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

/*根据实验要求构造一个长320的随机数数组，存放的指令序列满足实验要求*/
/*void createData()
{
    int s,i;
    int a[320];
    srand(time(0));                                             //初始化种子
    s=rand()%320;
    for(i=0;i<320;i+=4)                                         //产生指令队列
    {
        if(s<0||s>319)
        {
            printf("When i==%d,Error,s==%d\n",i,s);
            exit(0);
        }
        a[i]=s;                                                 //任选一指令访问点m
        a[i+1]=a[i]+1;                                          //顺序执行一条指令
        a[i+2]=rand()%(a[i+1]);                                 //执行前地址指令m'
        a[i+3]=a[i+2]+1;                                        //顺序执行一条指令

        s=a[i+3]+rand()%(318-a[i+3]);
        if((a[i+2]>318)||(s>319))
            printf("a[%d+2],a number which is :%d and s==%d\n",i,a[i+2],s);
    }
    for(i=0;i<320;i+=4)
    {
        printf("%d %d %d %d\n",a[i],a[i+1],a[i+2],a[i+3]);
    }
}*/

/*打印结果数组，当物理块没有页面号时显示为'_'，有页面号时显示具体页面号*/
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

/*判断页面号为num的页面是否在内存块中,存在返回1*/
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

/*FIFO 算法*/
int FIFO(PBlock *pb,int m)
{
    int i;
    int qy=0;                                                   //缺页次数
    float qyl;                                                  //缺页率
    int p=0;                                                    //替换指针
    int index=0;                                                //页面号索引
    while(index<PAGES)
    {
        if(!doExist(page[index],pb,M))                          //如果物理块内不存在页面号，则按顺序写入
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
    printf("结果数列为:\n");
    printRs(rs);
    printf("FIFO算法缺页次数为: %d\n",qy);
    qyl=(float)qy/PAGES;
    printf("FIFO算法缺页率为: %.4f \n",qyl);
    printf("\n");
    return 0;
}

/*获得最近最久未使用的页面的块号*/
int selectByTm(PBlock *pb,int p)
{
    int i;
    bool notEmpty;
    notEmpty=true;
    for(i=0;i<M;i++)                                            //如果物理块存在空，则直接选择空位置
    {
        if(pb[i].tm==-1)
        {
            notEmpty=false;
            p=i;
            break;
        }
    }
    if(notEmpty)                                                //如果全满，则比较它们的tm，选出tm最大的位置
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

/*LRU 算法*/
void LRU(PBlock *pb,int m)
{
    int i;
    int qy=0;                                                   //缺页次数
    float qyl;                                                  //缺页率
    int p=0;                                                    //替换指针
    int index=0;                                                //页面号索引
    while(index<PAGES)
    {
        if(!doExist(page[index],pb,m))                          //如果物理块内不存在页面号，先使每个物理块的tm++
        {                                                       //然后通过selectByTm方法选出要替换的页面号，并置tm为0
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
        else                                                    //如果已存在页面号，则使对应位置的tm++
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
    printf("结果数组为:\n");
    printRs(rs);
    printf("LRU算法缺页次数为: %d \n",qy);
    qyl=(float)qy/PAGES;
    printf("LRU算法缺页率为: %.4f\n",qyl);
    printf("\n");
}

/*获得最长时间内不被使用的页面的块号*/
int selectByOpt(PBlock *pb,int index,int p)
{
    int i,j;
    bool notEmpty;
    notEmpty=true;
    for(i=0;i<M;i++)                                            //如果物理块存在空，则直接选择空位置
    {
        if(pb[i].ntm==-1)
        {
            notEmpty=false;
            p=i;
            break;
        }
    }
    if(notEmpty)                                                //如果全满，则遍历页面号串找到再次出现的位置
    {                                                           //分别记录三个物理块的ntm，选出最大的作为要替换的页面号
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

/*OPT算法*/
void OPT(PBlock *pb,int m)
{
    int i;
    int qy=0;                                                   //缺页次数
    float qyl;                                                  //缺页率
    int p=0;                                                    //替换指针
    int index=0;                                                //页面号索引
    while(index<PAGES)
    {
        if(!doExist(page[index],pb,m))                          //如果物理块内不存在页面号
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
    printf("结果数组为:\n");
    printRs(rs);
    printf("OPT算法缺页次数为: %d \n",qy);
    qyl=(float)qy/PAGES;
    printf("OPT算法缺页率为: %.4f\n",qyl);
    printf("\n");
}

int main()
{
    int i;
    PBlock pb[M];
    printf("物理块数为 %d ,页面号序列为:\n",M);
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
