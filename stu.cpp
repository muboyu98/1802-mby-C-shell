#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
typedef struct student     //定义结构体
{
    char name[20];    //姓名
    char num[15];      //学号
    char sex[10];     //性别
    char from[20];    //籍贯
    char political[10];    //政治面貌
    char phone[15];      //手机号
    char QQ[15];         //QQ号
    char dorm[10];     //宿舍
    struct student *next;  //结构体指针
}stu;
stu *head;

void print()    //主菜单
{
    system("cls");
    printf("\n\n\n");
    printf("      ☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆\n");
    printf("      ***********************************************************\n");
    printf("      \t\t\t班级通讯录管理系统\n");
    printf("\n");
    printf("      \t\t1. 输入数据");
    printf("\t\t2. 显示数据\n");
    printf("      \t\t3. 插入数据");
    printf("\t\t4. 删除数据\n");
    printf("      \t\t5. 查看数据");
    printf("\t\t6. 修改数据\n");
    printf("      \t\t7. 保存数据");
    printf("\t\t8. 返回主菜单\n");
    printf("      ***********************************************************\n");
    printf("      ~~~~~退~~~~~~~~~~出~~~~~~~~~~请~~~~~~~~~~按~~~~~~~~~~9~~~~~\n");
    printf("      -----------------------------------------------------------\n\n");
}

void input(stu *p1)    //输入相关数据
{
    printf("姓名:");
    scanf("%s",&p1->name);
    printf("学号:");
    scanf("%s",&p1->num);
    printf("性别:");
    scanf("%s",&p1->sex);
    printf("籍贯:");
    scanf("%s",&p1->from);
    printf("政治面貌:");
    scanf("%s",&p1->political);
    printf("手机号:");
    scanf("%s",&p1->phone);
    printf("QQ号:");
    scanf("%s",&p1->QQ);
    printf("宿舍:");
    scanf("%s",&p1->dorm);
}


stu * inputdata()     //数据输入的函数
{
    stu *p1,*p2;
    int i=1;
    p1=(stu *)malloc(sizeof(stu));
    if(p1!=NULL)
    {
        head=p1;
        printf("\n\t\t\t☆☆☆输入数据☆☆☆\n");
        printf("------------------------------------------------------------------\n");
        printf("在姓名处输入“ok”代表输入数据结束\n");
        while(i)
        {
            printf("姓名:");
            scanf("%s",&p1->name);
            if(strcmp(p1->name,"ok")==0)
            {
                printf("\n输入完毕!\n");
                printf("========================================================================\n");
                i=0;
                p2->next=NULL;
                free(p1);
                p1=p2;
            }
            else
            {
                printf("学号:");
                scanf("%s",&p1->num);
                printf("性别:");
                scanf("%s",&p1->sex);
                printf("籍贯:");
                 scanf("%s",&p1->from);
                printf("政治面貌:");
                scanf("%s",&p1->political);
                printf("手机号:");
                scanf("%s",&p1->phone);
                printf("QQ号:");
                scanf("%s",&p1->QQ);
                printf("宿舍:");
                scanf("%s",&p1->dorm);
                printf("=====================================\n");
                p2=p1;
                p1=(stu *)malloc(sizeof(stu));
                if(p1!=NULL)
                {
                    p2->next=p1;
                }
            }
        }
        return(p1->next);
    }
}
void screen()  //用于显示页面 
{
    int i;
    char s[251]={"欢迎使用班级通讯录管理系统，\n\n\t\t\t本系统用于通讯录管理----排序，打印\n\n\n\t\tWelcome to use produced by ZM class address book\n\n\t\t management system,sorting,printing"};

    printf("\n================================================================================\n");
    printf("\n\n\n\t\t\t");
    for(i=0;s[i]!=NULL;i++)
    {
        Sleep(30);
        printf("%c",s[i]);
    }
    printf("\n\n\n\n\n\n\n\n\t\t ~ Hi~ o(*￣▽￣*)ブ~ ~ ~祝您旅途愉快~ ~\n");
    printf("================================================================================\n");

}
int main()
{
    int i;
    system("color 4e");
    screen();
}
