#include<stdlib.h>
#include<malloc.h>
/*�ڵ�����ݽṹ*/
struct
{
    int num;
    char str[20];
    struct node *next;
};

    /* * * * * * * * * * * * * * * * * * * * * */
    /* * * ��������* * * * * * * * * * * */
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
    /* * * * * * * * * * ����ڵ�* * * * * * * * * */
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


    /* * * * * ɾ���ڵ�* * * * * * * * * * * * */
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
    /* * * * * * * * * * ������ڵ�����* * * * * * * * * */
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
    head=NULL; /*���ձ�*/
    head=creat(head); /*���ú���������head Ϊͷ������*/
    print(head);/*���ú�������ڵ�*/
    printf("\n input inserted num,name:\n");
    gets(str); /*����ѧ��*/
    n=atoi(str);
    gets(str); /*��������*/
    head=insert(head, str, n); /*�ڵ��������*/

    print(head);
    printf("\n input deleted name:\n");
    gets(str); /*���뱻ɾ����*/
    head=delet(head,str); /*�ú���ɾ���ڵ�*/
    print(head); /*���ú�������ڵ�*/
    return;
    }
