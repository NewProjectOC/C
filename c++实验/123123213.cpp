#include<stdio.h>
void max(int i,int j)
{
	if(i>j)
		printf("%d",i);
	else
		printf("%d",j);
}
int main()
{
	int i=1,j=2;
	max(i,j);
}