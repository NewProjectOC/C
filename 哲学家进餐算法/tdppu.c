/********************************************************
**		        ��ѧ�ҽ�������(������)
**
**��������Ӻ����û���ҿ����򱣳�����ӣ��ᵼ������
**
**	       15��1      1500303111        �¼κ�
********************************************************/

/**��������
*�����̺߳���     pthread_create(pthread_t *thread,pthread_attr_t,(void *)(*start_routine),void *arg)
*       �������̱߳�ʶ�����߳��������ã��̺߳�����ʼ��ַ(���к���)�����ݸ����к����Ĳ���
*����������      pthread_mutex_t
*��ʼ��������     pthread_mutex_init
*����������      pthread_mutex_lock
*�ͷŻ�����      pthread_mutex_unlock
*�����Ƿ��������������򷵻�EBUSY������������	pthread_mutex_trylock
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>

#define NUM 5		//��ѧ��(����)����

pthread_mutex_t chopstick[NUM];		//������Ϊ�ź���

/*��ѧ�ҽ����㷨*/
void *eat_think(void *arg)
{
    int n = *((int *)arg);
	int left,right; //���ҿ���
	left = n%NUM;
	right = (n+1)%NUM;
	int i;
	while(1)
	{
		Sleep(2); //˼��ʱ��
		printf("Philosopher %d is HUNGRY.\n",n);
		/*�ж�������Ƿ���ã����������𣬲��������ӡ������*/
		if (pthread_mutex_trylock(&chopstick[left]) == EBUSY)
		{
			printf("Philosopher %d doesn't have LEFT chopstick %d\n", n, left);
			continue;
		}
		printf("Philosopher %d takes LEFT chopstick %d\n", n, left);
		/*�ж��ҿ����Ƿ���ã����������𲢽��ͣ��������򱣳������(���ڲ�������)����ӡ������*/
		if (pthread_mutex_trylock(&chopstick[right]) == EBUSY)
		{
			printf("Philosopher %d doesn't have RIGHT chopstick %d\n", n, left);
			//pthread_mutex_unlock(&chopstick[left]);
			//printf("Philosopher %d release LEFT chopstick %d\n", n, left);
			continue;
		}
		printf("Philosopher %d takes RIGHT chopstick %d\n", n, right);
		printf("Philosopher %d is EATING.\n",n);
		Sleep(2); //�Է�ʱ��
		/*���������������ҿ��ӿ�ʼ˼��*/
		pthread_mutex_unlock(&chopstick[left]);
		printf("Philosopher %d release LEFT chopstick %d\n", n, left);
		pthread_mutex_unlock(&chopstick[right]);
		printf("Philosopher %d release RIGHT chopstick %d\n", n, right);
		printf("Philosopher %d is THINKING.\n",n);
	}
}

int main()
{
	pthread_t p[NUM];	//��ѧ���߳�����
	int i,s[NUM];
	/*��ʼ��*/
	for (i=0;i<NUM;i++)
	{
		pthread_mutex_init(&chopstick[i],NULL);
		s[i] = i;
	}
	/*��ʼ�߳�*/
	for(i=0;i<NUM;i++)
	{
		pthread_create(&p[i],NULL, eat_think, (void *)&s[i]);
	}
	for(i=0;i<NUM;i++)
	{
		pthread_join(p[i],NULL);
	}
	return 0;
}
