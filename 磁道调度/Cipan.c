#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define NUM 10                                      //�ŵ�������
int num[NUM];                                       //�ŵ�������

/*���ļ��ж�ȡ�ŵ��ţ�����num[]����*/
int openFile()
{
    int isTrue=1;
    FILE *fp;
    int i;
    fp=fopen("num.txt","r");
    if(fp==NULL)
    {
        printf("Can't open file");
        isTrue=0;
        return -1;
    }
    for(i=0;!feof(fp);i++)
    {
        fscanf(fp,"%d",&num[i]);
    }
    fclose(fp);
    for(i=0;i<NUM;i++)                              //�������дŵ����Ƿ�Ϸ����ŵ��ű���Ϊ�����������
    {
        if(num[i]<0||num[i]==0)
        {
            printf("��%d���ŵ���%d����Ҫ������������\n",i+1,num[i]);
            isTrue=0;
            return -1;
        }
    }
    if(isTrue)
    {
        printf("�ŵ�������Ϊ:\n");
        for(i=0;i<NUM;i++)
        {
            printf("%d ",num[i]);
        }
        printf("\n");
    }
    printf("\n");
    return num[NUM];
}

/*FCFS�����ȷ����㷨*/
void FCFS()
{
    printf("**************** FCFS ****************\n");
    int i,j;
    float sum=0.0;
    int k=0;
    int move[NUM-1];
    for(i=0,k=0;i<NUM-1,k<NUM-1;i++,k++)                    //Ѱ�����Ⱦ͵��ڴŵ���������֮��
    {
        move[k]=abs(num[i]-num[i+1]);
    }
    printf("��һ���ŵ���:     �ƶ�����(�ŵ���):\n");
    for(i=1,k=0;i<NUM,k<NUM-1;i++,k++)
    {
        sum+=move[k];
        printf("\t%d",num[i]);
        printf("\t\t%d\n",move[k]);
    }
    sum=(float)sum/(NUM-1);
    printf("\nFCFSƽ��Ѱ������Ϊ:%.1f\n",sum);
}

/*SSTF���Ѱ��ʱ�������㷨*/
void SSTF()
{
    printf("**************** SSTF ****************\n");
    int i,j,t,p;
    int l,r;
    float sum=0.0;
    int k=0;
    int move[NUM-1],numsort[NUM],numSSTF[NUM];
    for(i=0;i<NUM;i++)
        numsort[i]=num[i];

    for(i=0;i<NUM;i++)                                     //�ŵ��Ŵ�С��������
    {
        for(j=0;j<NUM-1;j++)
        {
            if(numsort[j]>numsort[j+1])
            {
                t=numsort[j];
                numsort[j]=numsort[j+1];
                numsort[j+1]=t;
            }
        }
    }

    for(i=0;i<NUM;i++)                                      //�ҵ���һ���ŵ����������������λ��Ϊp
    {
        if(numsort[i]==num[0])
        {
            numSSTF[k]=num[0];
            p=i;
            l=i-1;                                          //lΪpǰһ��λ��
            r=i+1;                                          //rΪp��һ��λ��
        }
    }
    for(k=1;k<NUM;k++)                                      //��pΪ��㣬�Ƚ�ǰһ�����һ��ֻ��ľ���ֵ��С��ǰ��С���lλ�÷������������l--������ͬ��
    {
        if(l>=0&&r<=NUM-1)
        {
            if(abs(numsort[l]-numsort[p])<=abs(numsort[p]-numsort[r]))
            {
                  numSSTF[k]=numsort[l];
                  p--;
                  l--;
            }
            else
            {
                numSSTF[k]=numsort[r];
                p++;
                r++;
            }
        }
        else if(l<0)
        {
            numSSTF[k]=numsort[r];
            r++;
        }
        else if(r>NUM-1)
        {
            numSSTF[k]=numsort[l];
            l--;
        }
        else
            printf("error");
    }

    for(i=0,k=0;i<NUM-1,k<NUM-1;i++,k++)
    {
        move[k]=abs(numSSTF[i]-numSSTF[i+1]);
    }
    printf("��һ���ŵ���:     �ƶ�����(�ŵ���):\n");
    for(i=1,k=0;i<NUM,k<NUM-1;i++,k++)
    {
        sum+=move[k];
        printf("\t%d",numSSTF[i]);
        printf("\t\t%d\n",move[k]);
    }
    sum=(float)sum/(NUM-1);
    printf("\nSSTFƽ��Ѱ������Ϊ:%.1f\n",sum);
}

/*SCANɨ���㷨*/
void SCAN()                                                 //��SSTF�㷨ͬ��ֻ�������㷨ֱ��ָ��һ��������ǰ�����Ѱ��
{
    printf("**************** SCAN ****************\n");
    int i,j,t,p,x;
    int l,r;
    float sum=0.0;
    int k=0;
    int move[NUM-1],numsort[NUM],numSCAN[NUM];
    for(i=0;i<NUM;i++)
        numsort[i]=num[i];

    for(i=0;i<NUM;i++)
    {
        for(j=0;j<NUM-1;j++)
        {
            if(numsort[j]>numsort[j+1])
            {
                t=numsort[j];
                numsort[j]=numsort[j+1];
                numsort[j+1]=t;
            }
        }
    }

    printf("��ѡ��: 1.�ŵ���������;  2.�ŵ���������\n");
    printf("ѡ��:");
    scanf("%d",&x);
    if(x==1)
    {
        for(i=0;i<NUM;i++)
        {
            if(numsort[i]==num[0])
            {
                numSCAN[k]=num[0];
                p=i;
                l=i-1;
                r=i+1;
            }
        }
        for(k=1;k<NUM;k++)
        {
            if(l>=0)
            {
                numSCAN[k]=numsort[l];
                l--;
            }
            else if(r<=NUM-1)
            {
                numSCAN[k]=numsort[r];
                r++;
            }
            else
                printf("error");
        }

        for(i=0,k=0;i<NUM-1,k<NUM-1;i++,k++)
        {
            move[k]=abs(numSCAN[i]-numSCAN[i+1]);
        }
        printf("��һ���ŵ���:     �ƶ�����(�ŵ���):\n");
        for(i=1,k=0;i<NUM,k<NUM-1;i++,k++)
        {
            sum+=move[k];
            printf("\t%d",numSCAN[i]);
            printf("\t\t%d\n",move[k]);
        }
        sum=(float)sum/(NUM-1);
        printf("\nSSTFƽ��Ѱ������Ϊ:%.1f\n",sum);
    }
    else if(x==2)
    {
        for(i=0;i<NUM;i++)
        {
            if(numsort[i]==num[0])
            {
                numSCAN[k]=num[0];
                p=i;
                l=i-1;
                r=i+1;
            }
        }
        for(k=1;k<NUM;k++)
        {
            if(r<=NUM-1)
            {
                numSCAN[k]=numsort[r];
                r++;
            }
            else if(l>=0)
            {
                numSCAN[k]=numsort[l];
                l--;
            }
            else
                printf("error");
        }

        for(i=0,k=0;i<NUM-1,k<NUM-1;i++,k++)
        {
            move[k]=abs(numSCAN[i]-numSCAN[i+1]);
        }
        printf("��һ���ŵ���:     �ƶ�����(�ŵ���):\n");
        for(i=1,k=0;i<NUM,k<NUM-1;i++,k++)
        {
            sum+=move[k];
            printf("\t%d",numSCAN[i]);
            printf("\t\t%d\n",move[k]);
        }
        sum=(float)sum/(NUM-1);
        printf("\nSSTFƽ��Ѱ������Ϊ:%.1f\n",sum);
    }

}

/*��ҳ��ѡ���㷨*/
void select()
{
    printf("��ѡ���㷨:\n");
    printf("\t1.FCFS\n");
    printf("\t2.SSTF\n");
    printf("\t3.SCAN\n");
    printf("\t0.�˳�\n");
    choose();
}
/*����ѡ���жϹ���*/
int choose()
{
    int i,j;
    printf("ѡ��:");
    scanf("%d",&i);
    switch(i)
    {
        case 0:
            return 0;
        case 1:
            FCFS();
            break;
        case 2:
            SSTF();
            break;
        case 3:
            SCAN();
            break;
        default:
            printf("������������������\n");
            choose();
            break;
    }

    if(i==1||i==2||i==3)
    {
        printf("\n����1���ء������˳� :");
        scanf("%d",&j);
        if(j==1)
        {
            system("cls");
            select();
        }
        else
            return 0;
    }
}
int main()
{
    openFile();
    select();
    return 0;
}
