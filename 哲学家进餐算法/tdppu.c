/********************************************************
**		        哲学家进餐问题(会死锁)
**
**拿起左筷子后如果没有右筷子则保持左筷子，会导致死锁
**
**	       15算1      1500303111        陈嘉豪
********************************************************/

/**函数解析
*创建线程函数     pthread_create(pthread_t *thread,pthread_attr_t,(void *)(*start_routine),void *arg)
*       参数：线程标识符，线程属性设置，线程函数起始地址(运行函数)，传递给运行函数的参数
*创建互斥锁      pthread_mutex_t
*初始化互斥锁     pthread_mutex_init
*锁定互斥锁      pthread_mutex_lock
*释放互斥锁      pthread_mutex_unlock
*检验是否锁定，已锁定则返回EBUSY，否则将其锁定	pthread_mutex_trylock
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>

#define NUM 5		//哲学家(筷子)总数

pthread_mutex_t chopstick[NUM];		//筷子作为信号量

/*哲学家进餐算法*/
void *eat_think(void *arg)
{
    int n = *((int *)arg);
	int left,right; //左右筷子
	left = n%NUM;
	right = (n+1)%NUM;
	int i;
	while(1)
	{
		Sleep(2); //思考时间
		printf("Philosopher %d is HUNGRY.\n",n);
		/*判断左筷子是否可用，可用则拿起，不可用则打印并结束*/
		if (pthread_mutex_trylock(&chopstick[left]) == EBUSY)
		{
			printf("Philosopher %d doesn't have LEFT chopstick %d\n", n, left);
			continue;
		}
		printf("Philosopher %d takes LEFT chopstick %d\n", n, left);
		/*判断右筷子是否可用，可用则拿起并进餐，不可用则保持左筷子(用于产生死锁)，打印并结束*/
		if (pthread_mutex_trylock(&chopstick[right]) == EBUSY)
		{
			printf("Philosopher %d doesn't have RIGHT chopstick %d\n", n, left);
			//pthread_mutex_unlock(&chopstick[left]);
			//printf("Philosopher %d release LEFT chopstick %d\n", n, left);
			continue;
		}
		printf("Philosopher %d takes RIGHT chopstick %d\n", n, right);
		printf("Philosopher %d is EATING.\n",n);
		Sleep(2); //吃饭时间
		/*进餐完毕则放下左右筷子开始思考*/
		pthread_mutex_unlock(&chopstick[left]);
		printf("Philosopher %d release LEFT chopstick %d\n", n, left);
		pthread_mutex_unlock(&chopstick[right]);
		printf("Philosopher %d release RIGHT chopstick %d\n", n, right);
		printf("Philosopher %d is THINKING.\n",n);
	}
}

int main()
{
	pthread_t p[NUM];	//哲学家线程数组
	int i,s[NUM];
	/*初始化*/
	for (i=0;i<NUM;i++)
	{
		pthread_mutex_init(&chopstick[i],NULL);
		s[i] = i;
	}
	/*开始线程*/
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
