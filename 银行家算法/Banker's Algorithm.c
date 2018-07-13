/***************************************************
**           ���м��㷨(5������,3����Դ)
**
**      15�����1��    1500303111     �¼κ�
****************************************************/
#include<stdio.h>
#include<stdlib.h>

#define P 5     //������
#define M 3     //��Դ��

/*���̽ṹ��*/
struct pnum{
    int Max[M];
    int Allocation[M];
    int Need[M];
};
struct pnum pnum[P];

/*�б�Max,Allocation,Need,Available�Ƿ񶼺Ϸ��ı���*/
int mTRUE = 1;          //max
int alTRUE = 1;         //allocation
int nTRUE = 1;          //need
int avTRUE = 1;         //available
int sTRUE = 1;          //mmax

int mMax[M];            //��Դ����
int Available[M];       //Available����
int path[P];            //��ȫ·������
int isUsed[P];          //�ж��Ƿ��ѱ�ʹ��
int pathnum = 0;        //��ȫ·������

/*���ļ���ȡ��Դ����*/
int readmMax()
{
    /*��FILEָ���ȡ�ļ�*/
    FILE *fp;
    int i;
    fp=fopen("sum.txt","r");
    if(fp==NULL)
    {
        printf("Can't open file");
        sTRUE = 0;
        return -1;
    }
    /*����ȡ���ݴ������*/
    while(!feof(fp))
    {
        for(i=0;i<M;i++)
        {
            fscanf(fp,"%d",&mMax[i]);
        }
    }
    fclose(fp);
    /*�ж��Ƿ�Ϸ�*/
    for(i=0;i<M;i++)                              //
    {
        if(mMax[i]<0)
        {
            printf("��%d����Դ������������������\n",i+1);
            sTRUE = 0;
            return -1;
        }
    }
    return mMax[M];
}

/*���ļ���ȡMax*/
int readMax()
{
    /*��FILEָ���ȡ�ļ�*/
    FILE *fp;
    int i,j;
    fp=fopen("max.txt","r");
    if(fp==NULL)
    {
        printf("Can't open file");
        mTRUE = 0;
        return -1;
    }
    /*����ȡ���ݴ������*/
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
    /*�ж��Ƿ�Ϸ�*/
    for(i=0;i<P;i++)                              //
    {
        for(j=0;j<M;j++)
        {
            if(pnum[i].Max[j]<0)
            {
                printf("��%d�����̵ĵ�%d����Դ��Max��������������\n",i+1,j+1);
                mTRUE = 0;
                return -1;
            }
        }
    }
    return pnum[P].Max[M];
}

/*���ļ���ȡAllocation*/
int readAllocation()
{
    /*��FILEָ���ȡ�ļ�*/
    FILE *fp;
    int i,j;
    fp = fopen("allocation.txt","r");
    if(fp==NULL)
    {
        printf("Can't open file");
        alTRUE = 0;
        return -1;
    }
    /*����ȡ���ݴ������*/
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
    /*�ж��Ƿ�Ϸ�*/
    for(i=0;i<P;i++)                              //
    {
        for(j=0;j<M;j++)
        {
            if(pnum[i].Allocation[j]<0)
            {
                printf("��%d�����̵ĵ�%d����Դ��Allocation��������������\n",i+1,j+1);
                alTRUE = 0;
                return -1;
            }
        }
    }
    return pnum[P].Allocation[M];
}

/*����Need, Need = Max - Allocation*/
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
    /*�ж��Ƿ�Ϸ�*/
    for(i=0;i<P;i++)
    {
        for(j=0;j<M;j++)
        {
            if(pnum[i].Need[j]<0)
            {
                printf("��%d�����̵ĵ�%d����ԴNeed<0,�����·���\n",i+1,j+1);
                nTRUE = 0;
                return -1;
            }
        }
    }
    return pnum[P].Need[M];
}

/*����Available, Available = mMax - sum[Allocation]*/
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
    /*�ж��Ƿ�Ϸ�*/
    for(i=0;i<M;i++)
    {
        if(Available[i]<0)
        {
            printf("��%d����Դ��Available<0,�����·���\n",i+1);
            avTRUE = 0;
        }
    }
    return Available[M];
}

/*��ӡ������֪����:Max,Allocation,Need,Available*/
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

/*�ж��Ƿ���ڰ�ȫ����*/
int isPath()
{
    if(pathnum==0)
        return 0;
    return 1;
}

/*���Ұ�ȫ·���㷨������Ĳ���Ϊ���еڼ���λ�ã�����λ�����Ƿ��пɷ������*/
void findSecurePath(int n)
{
    int i,j,k;
    for(i=0;i<P;i++)
    {
        /*�жϸý����Ƿ��Ѿ����*/
        if(isUsed[i])
            continue;
        /*�Ƚϸý��̵�Need�Ƿ�<=Available*/
        for(j=0;j<M;j++)
        {
            if(pnum[i].Need[j]>Available[j])
                break;
        }
        /*�������Need<=Available���ͼ�¼�������ݹ���ò��Һ�������������
        ����Ҳ����򷵻���һλ��������ʹ��ȷ�����ٲ��Ҹý���*/
        if(j == M)
        {
            path[n] = i;
            /*���parh����˵�����ҵ�һ����ȫ·������ӡ*/
            if(n == P-1)
            {
                printf("��ȫ·�� %2d:  ",++pathnum);
                for(i=0;i<P;i++)
                {
                    printf("%d ",path[i]);
                }
                printf("\n");
            }
            isUsed[i] = 1;
            /*ÿ���һ�����̣��ͷ���Դ*/
            for(k=0;k<M;k++)
                Available[k]=Available[k]+pnum[i].Allocation[k];
            findSecurePath(n+1);
            /*�����꣬�ջ���Դ*/
            for(k=0;k<M;k++)
                Available[k]=Available[k]-pnum[i].Allocation[k];
            isUsed[i] = 0;
        }
    }
    /*���û��·��*/
    if(!isPath())
    {
        printf("\n�Ҳ�����ȫ·��\n");
    }
}

/*ruquest�����㷨*/
int request()
{
    int isTrue = 1;
    int i;
    int x;
    int s[M];
    int notneed = 0;
    printf("������Ҫ����Ľ��̺�(0~4):");
    scanf("%d",&x);
    printf("�밴˳������Ҫ�������Դ��:");
    for(i=0;i<M;i++)
    {
        scanf("%d",&s[i]);
    }
    /*�ж�Need�Ƿ�Ϸ�*/
    for(i=0;i<M;i++)
    {
        if(s[i]>pnum[x].Need[i])
        {
            notneed = 1;
            isTrue = 0;
            break;
        }
    }
    /*�ж�Available�Ƿ�Ϸ�*/
    for(i=0;i<M;i++)
    {
        if(s[i]>Available[i])
        {
            isTrue = 0;
            break;
        }
    }
    /*Need,Available�����ϣ������й�������ȥ���Ұ�ȫ·��*/
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
        /*����ҵ���ȫ·����˵����������*/
        if(isPath())
        {
            char k;
            printf("\n����Ϸ�\n");
            printf("\n��ѡ��:\n");
            printf("\t1.����������Դ\n");
            printf("\t2.������ҳ\n");
            printf("\t����������˳�\n");
            printf("����:");
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
        /*�Ҳ�����ȫ·����������*/
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
            printf("\n���󲻺Ϸ�,�޷�����\n");
            printf("\n��ѡ��:\n");
            printf("\t1.���·�����Դ\n");
            printf("\t2.������ҳ\n");
            printf("\t����������˳�\n");
            printf("����:");
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
    /*Need,Available�����ϣ���ʾ������Ϣ*/
    else
    {
        if(notneed)
            printf("\nRequest>Need,�޷�����\n");
        else
            printf("\nRequest>Available,�޷�����\n");
        printf("\n���󲻺Ϸ�,�޷�����\n");
        printf("\n��ѡ��:\n");
        printf("\t1.���·�����Դ\n");
        printf("\t2.������ҳ\n");
        printf("\t����������˳�\n");
        printf("����:");
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

/*��ʼ������*/
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

/*ѡ���㷨*/
int choose()
{
    char i;
    int x,a,b,c;
    printf("����:");
    scanf("%s",&i);
    switch(i)
    {
        case '1':
            printf("\n");
            findSecurePath(0);
            printf("\n����1������ҳ,�����˳�:");
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
            printf("\n������������������\n");
            choose();
            break;
    }
}

/*�˵�����*/
int menu()
{
    initial();
    system("cls");
    printf("***************************************************************\n");
    printf("**                ���м��㷨(5������,3����Դ)                **\n");
    printf("**                                                           **\n");
    printf("**                15��1   1500303111   �¼κ�                **\n");
    printf("***************************************************************\n");
    printf("\n");
    printp();
    printf("\n��ѡ����:\n");
    printf("\t1.��ǰ�����²��Ұ�ȫ·��\n");
    printf("\t2.���������Դ\n");
    printf("\t3.�˳�\n");
    choose();
}

int main()
{
    menu();
    return 0;
}
