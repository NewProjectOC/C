#include<stdlib.h>
#include<malloc.h>
/*节点的数据结构*/
struct
{
    int num;
    char str[20];
    struct node *next;
};

    /* * * * * * * * * * * * * * * * * * * * * */
    /* * * 创建链表* * * * * * * * * * * */
    struct node *creat(struct node *head)
    {
        char temp[30];
        struct node *pl,*p2;
        pl=p2=(struct node*)malloc(sizeof(struct node));
        printf("input num, name: \n");
        printf("exit:double times Enter!\n");
        gets(temp);
        gets(pl->str);
        pl->num=atoi(temp);
        pl->next = NULL ;
        while(strlen(pl->str)>0)
        {
            if(head==NULL)//if the chain is null
                 head= pl;//
            else
                p2->next=pl;//set the p2->next NULL
            p2 = pl;//
        pl=(struct node*)malloc(sizeof(struct node));
        printf ("input num, name: \n");
        printf("exit:double times Enter!\n");
        gets(temp);
        gets(pl->str);
        pl->num=atoi(temp);
        pl->next= NULL;
        }
        return head;
    }
    /* * * * * * * * * * * * * * * * * * * */
    /* * * * * * * * * * 插入节点* * * * * * * * * */
    struct node *insert(head, pstr,n)
    struct node *head;
    char *pstr;
    int n;
    {
        struct node *pl,*p2,*p3;
        pl=(struct node*)malloc(sizeof(struct node));
        strcpy (pl->str, pstr);
        pl->num = n;
        p2 = head;
        if(head == NULL)

        {
            head = pl;
            pl->next = NULL;
        }
        else
        {
        while (n>p2->num&&p2->next!=NULL)
        {
            p3 = p2;
            p2= p2->next;
        }
        if (n<=p2->num)
        if (head==p2)
        {
            head = pl;
            pl->next = p2;
        }
        else
        {
            p3->next = pl;
            pl->next=  p2;
        }
        else
        {
            p2->next= pl;
            pl->next = NULL;
        }
    }
        return(head);
    }
    /* * * * * * * * * * * * * * * * * * * * * * * * */


    /* * * * * 删除节点* * * * * * * * * * * * */
    struct node *delet (head, pstr)
    struct node *head;
    char *pstr;
    {
        struct node *temp,*p;
        temp =head;
        if (head==NULL)
        printf("\nList is null!\n");
        else
        {
            temp = head;
            while(strcmp(temp->str,pstr)!= 0 && temp->next!=NULL)
            {
                p = temp;
                temp= temp->next;
            }
            if(strcmp(temp->str,pstr)== 0)
            {
                if (temp== head)
                {
                    head = head->next;
                    free(temp);
                }
                else
                {
                    p->next =temp->next;
                    printf("delete string :%s\n",temp->str);
                    free(temp);
                }
            }
            else
                printf("\nno find string!\n");
        }
        return(head);
    }
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    /* * * * * * * * * * 链表各节点的输出* * * * * * * * * */
    void print(struct node *head)
    {
    struct node *temp;
    temp = head;
    printf("\n output strings:\n");
    while (temp!=NULL)
    {
    printf("\n%d-----%s\n",temp->num,temp->str);
    temp= temp->next;
    }
    return;
    }
int main( )
{
    struct node *head;
    char str[20];
    int n;
    head=NULL; /*做空表*/
    head=creat(head); /*调用函数创建以head 为头的链表*/
    print(head);/*调用函数输出节点*/
    printf("\n input inserted num,name:\n");
    gets(str); /*输入学号*/
    n=atoi(str);
    gets(str); /*输入姓名*/
    head=insert(head, str, n); /*节点插入链表*/

    print(head);
    printf("\n input deleted name:\n");
    gets(str); /*输入被删姓名*/
    head=delet(head,str); /*用函数删除节点*/
    print(head); /*调用函数输出节点*/
    return;
    }
