#include<malloc.h>
void push(struct student *p);
void pop(struct student *p);
struct student
{
   int num;
   float score;
   struct student *next;
};
struct student *top=0,st1,st2,st3;   
#include <stdio.h>
int main(int argc, char *argv[])
{  struct student *p1,*p2,*p3;
   int x=100,y;
   p1=p2=p3=(struct student *)malloc(sizeof(struct student));
   
   p1->num=44;
   p1->score=11;
   p1->next=0;
   
   p2->num=55;
   p2->score=22;
   p2->next=0;
   
   p3->num=66;
   p3->score=33;
   p3->next=0;
   
   push(p1);
   pop(&st1);
   printf("num:%d\n",st1.num);
   printf("y=%.0f",st1.score);
   push(p2);
   pop(&st2);
   printf("num:%d\n",st2.num);
   printf("y=%.0f",st2.score);
   push(p3);
   pop(&st3);
   printf("num:%d\n",st3.num);
   printf("y=%.0f",st3.score);
   return 0;
}
void push(struct student *p)
{ if(top==0)top=p;
  else
  { p->next=top;
    top=p; 
  }
  top++;
}
void pop(struct student *p)
{ struct student *t;
  p->num=top->num;
  p->score=top->score;
  t=top;
  top=top->next;
  top++;
  free(t);
}