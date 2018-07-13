/***************************************************
**           银行家算法(5个进程,3类资源)
**
**      15计算机1班    1500303111     陈嘉豪
****************************************************/
#include<stdio.h>
#include<stdlib.h>

#define P 5     //进程数
#define M 3     //资源数

/*进程结构体*/
struct pnum{
    int Max[M];
    int Allocation[M];
    int Need[M];
};
struct pnum pnum[P];

/*判别Max,Allocation,Need,Available是否都合法的变量*/
int mTRUE = 1;          //max
int alTRUE = 1;         //allocation
int nTRUE = 1;          //need
int avTRUE = 1;         //available
int sTRUE = 1;          //mmax

int mMax[M];            //资源总数
int Available[M];       //Available数组
int path[P];            //安全路径数组
int isUsed[P];          //判断是否已被使用
int pathnum = 0;        //安全路径条数

/*从文件读取资源总数*/
int readmMax()
{
    /*用FILE指针读取文件*/
    FILE *fp;
    int i;
    fp=fopen("sum.txt","r");
    if(fp==NULL)
    {
        printf("Can't open file");
        sTRUE = 0;
        return -1;
    }
    /*将读取内容存放数组*/
    while(!feof(fp))
    {
        for(i=0;i<M;i++)
        {
            fscanf(fp,"%d",&mMax[i]);
        }
    }
    fclose(fp);
    /*判断是否合法*/
    for(i=0;i<M;i++)                              //
    {
        if(mMax[i]<0)
        {
            printf("第%d类资源总数有误，请重新输入\n",i+1);
            sTRUE = 0;
            return -1;
        }
    }
    return mMax[M];
}

/*从文件读取Max*/
int readMax()
{
    /*用FILE指针读取文件*/
    FILE *fp;
    int i,j;
    fp=fopen("max.txt","r");
    if(fp==NULL)
    {
        printf("Can't open file");
        mTRUE = 0;
        return -1;
    }
    /*将读取内容存放数组*/
    while(!feof(fp))
    {
        for(i=0;i<P;i++)
        {
            for(j=0;j<M;j++)
            {
                fscanf(fp,"%d",&pnum[i].Max[j]);
            }
        }
    }
    fclose(fp);
    /*判断是否合法*/
    for(i=0;i<P;i++)                              //
    {
        for(j=0;j<M;j++)
        {
            if(pnum[i].Max[j]<0)
            {
                printf("第%d个进程的第%d类资源的Max有误，请重新输入\n",i+1,j+1);
                mTRUE = 0;
                return -1;
            }
        }
    }
    return pnum[P].Max[M];
}

/*从文件读取Allocation*/
int readAllocation()
{
    /*用FILE指针读取文件*/
    FILE *fp;
    int i,j;
    fp = fopen("allocation.txt","r");
    if(fp==NULL)
    {
        printf("Can't open file");
        alTRUE = 0;
        return -1;
    }
    /*将读取内容存放数组*/
    while(!feof(fp))
    {
        for(i=0;i<P;i++)
        {
            for(j=0;j<M;j++)
            {
                fscanf(fp,"%d",&pnum[i].Allocation[j]);
            }
        }
    }
    fclose(fp);
    /*判断是否合法*/
    for(i=0;i<P;i++)                              //
    {
        for(j=0;j<M;j++)
        {
            if(pnum[i].Allocation[j]<0)
            {
                printf("第%d个进程的第%d类资源的Allocation有误，请重新输入\n",i+1,j+1);
                alTRUE = 0;
                return -1;
            }
        }
    }
    return pnum[P].Allocation[M];
}

/*计算Need, Need = Max - Allocation*/
int setNeed()
{
    int i,j;
    if(alTRUE&&mTRUE)
    {
        for(i=0;i<P;i++)
        {
            for(j=0;j<M;j++)
            {
                pnum[i].Need[j]=pnum[i].Max[j]-pnum[i].Allocation[j];
            }
        }
    }
    /*判断是否合法*/
    for(i=0;i<P;i++)
    {
        for(j=0;j<M;j++)
        {
            if(pnum[i].Need[j]<0)
            {
                printf("第%d个进程的第%d类资源Need<0,请重新分配\n",i+1,j+1);
                nTRUE = 0;
                return -1;
            }
        }
    }
    return pnum[P].Need[M];
}

/*计算Available, Available = mMax - sum[Allocation]*/
int setAvailable()
{
    int i,j;
    int sum=0;
    for(i=0;i<M;i++)
    {
        for(j=0;j<P;j++)
        {
            sum=sum+pnum[j].Allocation[i];
        }
        Available[i]=mMax[i]-sum;
        sum=0;
    }
    /*判断是否合法*/
    for(i=0;i<M;i++)
    {
        if(Available[i]<0)
        {
            printf("第%d类资源的Available<0,请重新分配\n",i+1);
            avTRUE = 0;
        }
    }
    return Available[M];
}

/*打印完整已知条件:Max,Allocation,Need,Available*/
void printp()
{
    if(mTRUE&&alTRUE&&nTRUE&&avTRUE&&sTRUE)
    {
        int i;
        printf("\tMax:\t\tAllocation:\tNeed:\t\tAvailable:\n");
        for(i=0;i<P;i++)
        {
            printf("P%d :",i);
            if(i==0)
                printf("\t%d %d %d\t\t%d %d %d\t\t%d %d %d\t\t%d %d %d",pnum[i].Max[0],pnum[i].Max[1],pnum[i].Max[2],pnum[i].Allocation[0],pnum[i].Allocation[1],pnum[i].Allocation[2],pnum[i].Need[0],pnum[i].Need[1],pnum[i].Need[2],Available[0],Available[1],Available[2]);
            else
                printf("\t%d %d %d\t\t%d %d %d\t\t%d %d %d",pnum[i].Max[0],pnum[i].Max[1],pnum[i].Max[2],pnum[i].Allocation[0],pnum[i].Allocation[1],pnum[i].Allocation[2],pnum[i].Need[0],pnum[i].Need[1],pnum[i].Need[2]);
            printf("\n");
        }
    }
}

/*判断是否存在安全序列*/
int isPath()
{
    if(pathnum==0)
        return 0;
    return 1;
}

/*查找安全路径算法，后面的参数为序列第几个位置，即按位查找是否有可分配进程*/
void findSecurePath(int n)
{
    int i,j,k;
    for(i=0;i<P;i++)
    {
        /*判断该进程是否已经完成*/
        if(isUsed[i])
            continue;
        /*比较该进程的Need是否都<=Available*/
        for(j=0;j<M;j++)
        {
            if(pnum[i].Need[j]>Available[j])
                break;
        }
        /*如果满足Need<=Available，就记录下来并递归调用查找函数继续往下找
        如果找不到则返回上一位，并记已使用确保不再查找该进程*/
        if(j == M)
        {
            path[n] = i;
            /*如果parh满则说明已找到一条安全路径，打印*/
            if(n == P-1)
            {
                printf("安全路径 %2d:  ",++pathnum);
                for(i=0;i<P;i++)
                {
                    printf("%d ",path[i]);
                }
                printf("\n");
            }
            isUsed[i] = 1;
            /*每完成一个进程，释放资源*/
            for(k=0;k<M;k++)
                Available[k]=Available[k]+pnum[i].Allocation[k];
            findSecurePath(n+1);
            /*查找完，收回资源*/
            for(k=0;k<M;k++)
                Available[k]=Available[k]-pnum[i].Allocation[k];
            isUsed[i] = 0;
        }
    }
    /*如果没有路径*/
    if(!isPath())
    {
        printf("\n找不到安全路径\n");
    }
}

/*ruquest分配算法*/
int request()
{
    int isTrue = 1;
    int i;
    int x;
    int s[M];
    int notneed = 0;
    printf("请输入要申请的进程号(0~4):");
    scanf("%d",&x);
    printf("请按顺序输入要分配的资源数:");
    for(i=0;i<M;i++)
    {
        scanf("%d",&s[i]);
    }
    /*判断Need是否合法*/
    for(i=0;i<M;i++)
    {
        if(s[i]>pnum[x].Need[i])
        {
            notneed = 1;
            isTrue = 0;
            break;
        }
    }
    /*判断Available是否合法*/
    for(i=0;i<M;i++)
    {
        if(s[i]>Available[i])
        {
            isTrue = 0;
            break;
        }
    }
    /*Need,Available都符合，更新有关数据再去查找安全路径*/
    if(isTrue)
    {
        for(i=0;i<M;i++)
        {
            pnum[x].Allocation[i]=pnum[x].Allocation[i]+s[i];
            pnum[x].Need[i]=pnum[x].Need[i]-s[i];
            Available[i]=Available[i]-s[i];
        }
        system("cls");
        printp();
        findSecurePath(0);
        /*如果找到安全路径则说明可以申请*/
        if(isPath())
        {
            char k;
            printf("\n请求合法\n");
            printf("\n请选择:\n");
            printf("\t1.继续分配资源\n");
            printf("\t2.返回主页\n");
            printf("\t其他任意键退出\n");
            printf("输入:");
            scanf("%s",&k);
            switch(k)
            {
                case '1':
                    pathnum = 0;
                    request();
                    break;
                case '2':
                    menu();
                    break;
                default:
                    return 0;
                    break;
            }
        }
        /*找不到安全路径则不能申请*/
        else
        {
            for(i=0;i<M;i++)
            {
                pnum[x].Allocation[i]=pnum[x].Allocation[i]-s[i];
                pnum[x].Need[i]=pnum[x].Need[i]+s[i];
                Available[i]=Available[i]+s[i];
            }
            system("cls");
            printp();
            char k;
            printf("\n请求不合法,无法分配\n");
            printf("\n请选择:\n");
            printf("\t1.重新分配资源\n");
            printf("\t2.返回主页\n");
            printf("\t其他任意键退出\n");
            printf("输入:");
            scanf("%s",&k);
            switch(k)
            {
                case '1':
                    request();
                    break;
                case '2':
                    menu();
                    break;
                default:
                    return 0;
            }
        }
    }
    /*Need,Available不符合，显示错误信息*/
    else
    {
        if(notneed)
            printf("\nRequest>Need,无法申请\n");
        else
            printf("\nRequest>Available,无法申请\n");
        printf("\n请求不合法,无法分配\n");
        printf("\n请选择:\n");
        printf("\t1.重新分配资源\n");
        printf("\t2.返回主页\n");
        printf("\t其他任意键退出\n");
        printf("输入:");
        char k;
        scanf("%s",&k);
        switch(k)
        {
            case '1':
                request();
                break;
            case '2':
                menu();
                break;
            default:
                return 0;
        }
    }
}

/*初始化函数*/
void initial()
{
    int i;
    for(i=0;i<P;i++)
    {
        isUsed[i] = 0;
    }
    pathnum = 0;
    readmMax();
    readMax();
    readAllocation();
    setNeed();
    setAvailable();
}

/*选择算法*/
int choose()
{
    char i;
    int x,a,b,c;
    printf("输入:");
    scanf("%s",&i);
    switch(i)
    {
        case '1':
            printf("\n");
            findSecurePath(0);
            printf("\n输入1返回主页,否则退出:");
            int k;
            scanf("%d",&k);
            if(k==1)
                menu();
            else
                return 0;
            break;
        case '2':
            request();
            break;
        case '3':
            return 0;
            break;
        default:
            printf("\n输入有误，请重新输入\n");
            choose();
            break;
    }
}

/*菜单函数*/
int menu()
{
    initial();
    system("cls");
    printf("***************************************************************\n");
    printf("**                银行家算法(5个进程,3类资源)                **\n");
    printf("**                                                           **\n");
    printf("**                15算1   1500303111   陈嘉豪                **\n");
    printf("***************************************************************\n");
    printf("\n");
    printp();
    printf("\n请选择功能:\n");
    printf("\t1.当前条件下查找安全路径\n");
    printf("\t2.申请分配资源\n");
    printf("\t3.退出\n");
    choose();
}

int main()
{
    menu();
    return 0;
}
