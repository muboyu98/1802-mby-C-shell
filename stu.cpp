#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;
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

//C++和shell混编部分 

void writeTempFile(const char *command) {      //调用shell脚本的函数 
	 FILE *in;
     char buff[512];
     in = popen(command, "w");
     pclose(in);
     
}

void clearTempFile() {           //清空shell脚本创建的临时记录文件  
	 FILE *in;
     char buff[512];
     in = popen("clear.sh", "w");
     pclose(in);
}

void writeTemp() {        // 调用shell脚本，从shell脚本输入，shell会创建txt文件 
	printf("请在shell界面输入您的信息。。。\n");
	writeTempFile("information.sh");
	printf("输入完成！\n");
}




void input(stu *p1)    //输入相关数据
{
    FILE* fp;
//	char file[100];
//	cout << "请输入要读取的文件名：";
//	scanf("%s", file);	//C:\\Users\\柠檬\\Desktop\\test\\temp\\aa.txt
	fp = fopen("temp\\information.txt", "r");
	if (fp == NULL) {
		//cout << "failed to open"<< endl;
		printf("failed to open\n");
		return;
	}
	char szTest[1000] = { 0 };
	int cnt = 0,mark = 1;
	while (!feof(fp)){
		if(mark == 1){
			mark = 0;
			continue;
		}
		memset(szTest, 0, sizeof(szTest));
		fgets(szTest, sizeof(szTest) - 1, fp); 
		cnt++;
		//printf("%s", szTest);
		for (int i = 0; i < 1000; i++)
			if (szTest[i] == '\n') {
				szTest[i] = '\0';
				break;
			}
		switch (cnt) {
		case 1:
			strcpy(p1->name, szTest);
			break;
		case 2:
			strcpy(p1->num, szTest);
			break;
		case 3:
			strcpy(p1->sex, szTest);
			break;
		case 4:
			strcpy(p1->from, szTest);
			break;
		case 5:
			strcpy(p1->political, szTest);
			break;
		case 6:
			strcpy(p1->phone, szTest);
			break;
		case 7:
			strcpy(p1->QQ, szTest);
			break;
		case 8:
			strcpy(p1->dorm, szTest);
			break;
		}
		if (cnt == 8) {
			printf("输入完毕。");
		}
	}
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


stu * lookdata(stu *p1)     //查看数据的函数
{
    printf("\n\t\t\t☆☆☆显示数据☆☆☆\n");
    printf("----------------------------------------------------------------------\n");
    while(p1!=NULL)
    {
        printf("姓名:%s\n",p1->name);
        printf("学号:%s\t",p1->num);
        printf("性别:%s\t",p1->sex);
        printf("籍贯:%s\t",p1->from);
        printf("政治面貌:%s\t",p1->political);
        printf("手机号:%s\t",p1->phone);
        printf("QQ号:%s\t",p1->QQ);
        printf("宿舍:%s\n",p1->dorm);
        printf("======================================================================\n");
        p1=p1->next;
    }
    return p1;
}


void insert()      //插入数据
{
    int i;
    char named[20];
    stu *p1,*p2,*p3;
    p1=head;
    p3=(stu *)malloc(sizeof(stu));
    p3->next=NULL;
    printf("\n\t\t\t☆☆☆插入数据☆☆☆\n");
    printf("----------------------------------------------------------------------\n");
    printf("请输入插入者的资料:\n");
    writeTemp();
    input(p3);
    clearTempFile();     //使用临时数据之后，删除information.txt文件 
    printf("\n插入选项\n");
    printf("1.首位置插入\t2.尾位置插入\t3.前插\n");
    printf("请输入你的选择:");
    scanf("%d",&i);
    switch(i)
    {
    case 1:p3->next=p1;
        head=p3;
        break;
    case 2:while(p1->next!=NULL)
           {
               p2=p1;
               p1=p1->next;
           }
        p1->next=p3;
        break;
    case 3:printf("请输入姓名（前插）:");
        scanf("%s",named);
        while(strcmp(named,p1->name)!=0)
        {
            p2=p1;
            p1=p1->next;
        }
        p2->next=p3;
        p3->next=p1;
        break;
    }
    printf("插入成功!\n");
    printf("======================================================================\n");
    return;
}

void deleted()          //删除数据
{
    stu *p1,*p2;
    char Name[20];  //想要删除的人的姓名
    printf("\n\t\t\t☆☆☆删除数据☆☆☆\n");
    printf("----------------------------------------------------------------------\n");
    printf("请输入要删除的姓名:");
    scanf("%s",Name);
    p1=head;
    if(head==NULL)
    {
    printf("内存空空神马都没有!\n");
    printf("======================================================================\n");
    return;
    }
    if(strcmp(Name,p1->name)==0)
    {
    head=p1->next;
    printf("删除成功!\n");
    printf("======================================================================\n");
    return;
    }
    while(p1!=NULL&&(strcmp(Name,p1->name)!=0))
    {
    p2=p1;
    p1=p1->next;
    }
    if(p1==NULL)
    {
    printf("此人不存在!\n");
    printf("======================================================================\n");
    return;
    }
    if(p1->next!=NULL)
    {
    p1=p1->next;
    p2->next=p1;
    printf("删除成功!\n");
    printf("======================================================================\n");
    return;
    }
    else
    {
    p2->next=NULL;
    printf("删除成功!\n");
    printf("======================================================================\n");
    return;
    }
}


void find(stu *p2)        //通过姓名查找查看数据的函数
{
    char name[20];
    int b=0;
    printf("\n\t\t\t☆☆☆查看数据☆☆☆\n");
    printf("----------------------------------------------------------------------\n");
    printf("请输入您想查找人的姓名:");
    scanf("%s",name);
    while(p2!=NULL)
    {
        if(strcmp(name,p2->name)==0)
        {
            printf("你要找到的数据\n");
            printf("姓名:%s\n",p2->name);
            printf("学号:%s\t",p2->num);
            printf("性别:%s\t",p2->sex);
            printf("籍贯:%s\t",p2->from);
            printf("政治面貌:%s\t",p2->political);
            printf("手机号:%s\t",p2->phone);
            printf("QQ号:%s\t",p2->QQ);
            printf("宿舍:%s\n",p2->dorm);
            printf("======================================================================\n");
            b=1;
        }
        p2=p2->next;
    }
    if(b==0)
    {
        printf("\n您要查找的人不存在!\n");
    }
}


void update(stu *p2)   //通过姓名查找修改数据
{
    char name[20];
    int b=0,i;
    printf("\n\t\t\t☆☆☆修改数据☆☆☆\n");
    printf("----------------------------------------------------------------------\n");
    printf("请输入将要修改人的姓名:");
    scanf("%s",name);
    while(p2!=NULL)
    {
        if(strcmp(name,p2->name)==0)
        {
            printf("该同学的基本信息\n");
            printf("姓名:%s\n",p2->name);
            printf("学号:%s\t",p2->num);
             printf("性别:%s\t",p2->sex);
            printf("籍贯:%s\t",p2->from);
            printf("政治面貌:%s\t",p2->political);
            printf("手机号:%s\t",p2->phone);
            printf("QQ号:%s\t",p2->QQ);
            printf("宿舍:%s\n",p2->dorm);
            printf("\n请选择要修改的信息\n");
            printf("\t1.姓名\t2.学号\t3.性别\t4.籍贯\n\t5.政治面貌\t6.手机号\t7.QQ\t8.宿舍\n");
            printf("\n您的选择是(1~8):");
            scanf("%d",&i);
            printf("请输入修改之后的内容\n");
            switch(i)
            {
            case 1:printf("姓名:");
                scanf("%s",&p2->name);
                break;
            case 2:printf("学号:");
                scanf("%s",&p2->num);
                break;
            case 3:printf("性别:");
                scanf("%s",&p2->sex);
                break;
            case 4:printf("籍贯:");
                scanf("%s",&p2->from);
                break;
            case 5:printf("政治面貌:");
                scanf("%s",&p2->political);
                break;
            case 6:printf("手机号:");
                scanf("%s",&p2->phone);
                break;
            case 7:printf("QQ:");
                scanf("%s",&p2->QQ);
                break;
            case 8:printf("宿舍:");
                scanf("%d",&p2->dorm);
                break;
            }
            printf("\n修改成功!\n");
            printf("=========================================================================\n");
            b=1;
        }
        p2=p2->next;
    }
    if(b==0)
    {
        printf("没有找到该人的资料!\n");
    }
}


void save(stu *p2)   //保存数据
{
    FILE *fp;
    char file[15];
    printf("\n\t\t\t☆☆☆保存数据☆☆☆\n");
    printf("----------------------------------------------------------------------\n");
    printf("输入文件名:");
    scanf("%s",file);
    if((fp=fopen(file,"w"))==NULL)
    {
        printf("cannot open this file\n");
        exit(0);
    }
    fprintf(fp,"姓名\t学号\t性别\t籍贯\t政治面貌\t手机号\tQQ号\t宿舍\n");
    while(p2!=NULL)
    {
        fprintf(fp,"%s\t",p2->name);
        fprintf(fp,"%s\t",p2->num);
        fprintf(fp,"%s\t",p2->sex);
        fprintf(fp,"%s\t",p2->from);
        fprintf(fp,"%s\t",p2->political);
        fprintf(fp,"%s\t",p2->phone);
        fprintf(fp,"%s\t",p2->QQ);
        fprintf(fp,"%s\n",p2->dorm);
        p2=p2->next;
    }
    printf("\n保存成功!\n");
    printf("======================================================================\n");
    fclose(fp);
}


void screen()
{
    int i;
    char s[251]={"欢迎使用班级通讯录管理系统，\n\n\t\t\t本系统用于通讯录管理----排序，打印\n\n\n\t\tWelcome to use produced by MbyAndZxx class address book\n\n\t\t management system,sorting,printing"};

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
    system("color 5e");
    screen();
    Sleep(3000);
    print();
    while(1)
    {
        printf("请输入你的选择(1~9):");
        loop:scanf("%d",&i);
        if(i<1||i>9)
        {
            printf("输入有误,请在1~9中进行选择:");
            goto loop;
        }
        switch(i)
        {
        case 1:
            inputdata();
            break;
        case 2:
            lookdata(head);
            break;
        case 3:
            insert();
            break;
        case 4:
             deleted();
            break;
        case 5:
            find(head);
            break;
        case 6:
            update(head);
            break;
        case 7:
            save(head);
            break;
        case 8:
            print();
            break;
        case 9:
            exit(1);
            break;
        }
    }
}
