
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#define LEN sizeof(struct Movie)
#define Hang 5
#define Lie 10

void menu();			//用户系统主界面
void login();			//电影院管理员登录界面
void admin();			//电影院管理员界面 
void modify();			//信息修改函数
void save();			//电影信息录入
void del();				//信息删除函数
void gaimi();			//电影院管理员密码修改
void users_interface();	//用户进入界面
void registers();		//用户注册账号
void Create_File();		//创建账号文件
void Input_login();		//用户登录账号
void user();			//购票用户
void book();			//预订
void save_out();		//显示电影信息模块
int load(char * a);		//计算参数所指定的文件中的记录的个数的函数
void transform_text();	//文件类型转换（二进制->文本）
void transform_2();		//文件类型转换（文本->二进制）
void sort();			//定义排序函数
void search();			//查询功能

struct Time
{
    int hour;
    int min;
};

struct Date
{
    int year;
    int mon;
    int day;
};

struct Movie
{
    char name[100],type[100],type2[100];
    struct Time time;
    struct Date date;
    float price;
    struct Movie*next;
};

struct custom	//存放用户账户密码的结构体
{
    char name[20],zh[20],code[10];
    struct custom*next;
} custom[3];

struct user		//存放管理员的结构体
{
    char pwd[20];
} us;
char username[15]="guanliyuan",pwd1[50];    //username[15]原始管理员账号，pwd1修改密码时的比较


int main()
{
    menu();
}


void menu()		//登录系统主界面
{

    while(1)	//使最初界面始终在主界面而不关闭程序
    {
        system("cls");
        printf("\n\n\n");
        printf("\t\t******************************************************\n");
        printf("\t\t***              电影院预定及售票系统              ***\n");
        printf("\t\t******************************************************\n");
        printf("\t\t***                                                ***\n");
        printf("\t\t***                                                ***\n");
        printf("\t\t***               请选择用户类型:                  ***\n");
        printf("\t\t***                A.购票用户                      ***\n");
        printf("\t\t***                B.电影院管理员                  ***\n");
        printf("\t\t***                                                ***\n");
        printf("\t\t***                                                ***\n");
        printf("\t\t******************************************************\n");
        printf("\t\t******************************************************");
        printf("\n");
        printf("\t\t您的选择是:[ ]\b\b");
        char first_select = 0;
        scanf("%c",&first_select);
        if(first_select=='A')
			users_interface();
        if(first_select=='B')
			login();
        system("cls");
    }
}


void login()     //管理员登录界面
{
    system("cls");
    int i=0,k=0,j;
    FILE *fe;
    if((fe=fopen("name.txt","r"))==NULL)
    {
        strcpy(us.pwd,"123456");
    }//如果文件打开错误初始密码
    fscanf(fe,"%s",us.pwd);
    char username1[15];   //定义与原始密码相比较的变量
    printf("\n\n");
    //系统默认管理员名：guanliyuan,密码：123456
    printf("\t\t★★★★★★★  欢迎使用登录系统  ★★★★★★★\n\n");
    for(i=0; i<3; i++)
    {
        printf("\t\t请输入管理员名称:");
        scanf("%s",username1);
        printf("\t\t请输入6位密码:");
        for(j=0; j<100; j++)
        {
            pwd1[j]=getch();
            if(pwd1[j]=='\r')
                break;
            printf("*");
        }
        pwd1[j]='\0';
        if((strcmp(username,username1)==0)&&(strcmp(us.pwd,pwd1)==0))
        {
            printf("\n\n\t\t您已经成功登录！\n\t\t");
            k=1;
            for(i=0; i<6; i++)
            {
                printf(".");
                Sleep(200);
            }
            system("cls");
            admin();            //跳转到管理员主界面
            break;
        }
        else
            printf("\n\n\t\t用户名或密码无效，请重新输入:\n\n");
        continue;
    }
    if(k==0)
        printf("\n\t\t连续输入错误3次将退出程序\n");
    Sleep(1000);            //程序暂停函数（单位毫秒），本次暂停2000毫秒
    return;//连续三次错误跳转退出界面
}


void admin()	//管理员界面
{
    int n, w1; 	// n 记录选择的菜单选项， w1 记录选择是否符合要求 
    while(1)	//循环使得退出后能在选择界面
    {
        system("cls");
        //电影院工作人员输入界面
        system("cls");
        do
        {
            system("cls");//清屏
            puts("\t\t\t     欢迎进入电影院管理员界面！ ");
            puts("\t\t*********************菜单*********************\n\n");
            puts("\t\t\t\t1.显示电影信息");
            puts("\t\t\t\t2.电影信息排序");
            puts("\t\t\t\t3.电影信息查询");
            puts("\t\t\t\t4.修改电影信息");
            puts("\t\t\t\t5.删除电影信息");
            puts("\t\t\t\t6.账号修改密码");
            puts("\t\t\t\t7.返回至主界面");
            puts("\n\n\t\t**********************************************\n");
            printf("请选择数字(1~7): [ ]\b\b");
            scanf("%d",&n);
            getchar();
            if(n<1||n>9) /*对选择的数字作判断*/
            {
                w1=1;
                getchar();
            }
            else w1=0;
        }
        while(w1==1);
        switch(n) 	//菜单选择功能
        {
        case 1:
        	save_out();
            break; 	//信息显示模块
        case 2:
			sort();		
            break; 	//信息排序模块
        case 3:
            search();
            break; 	//信息查询模块
        case 4:
            modify();
            break; 	//信息修改模块
        case 5:
            del();
            break;	//信息删除模块
        case 6:
        	gaimi();//修改密码
            break;
        case 7:
            menu();	//返回菜单 
        case 8:
		    save(); // 
        }
    }
}


void modify() //信息修改函数 
{
    struct Node     /*创建电影名链表用于查询*/
    {
        char name[100];
        struct Node * next;
    };
    int amount; /* 信息文件中的记录总数 */
    int con=0; /* 已处理的文件记录总数 */
    struct Node * head=NULL, * pf=NULL, * pb=NULL;
    struct Movie movie;
    FILE * fp;
    int total=0;
    long offset=1; /* 文件位置指针偏移量 */
    int flag=0; /* 指示是否继续进行修改，为 1 时继续 */
    char ID[100]; /* 待修改的记录的电影名称 */
    int ord; /* 待修改的项目指示 */
    int repeat; /* 在修改中用于重复的输入 */
    int Yes=0; /* 指示是否保存修改 */
    if((fp=fopen("movie.txt","r")) == NULL)       /*打开文件*/
    {
        printf("\tCan not open the inform file!");
        getch();
        exit(1);
    }
    transform_2 ();       /*转换成二进制文件*/
    fclose(fp);
    amount=load("movie0.txt");      /*获取文件中已有电影信息个数*/
    fp=fopen("movie0.txt","rb");       /*打开文件*/
    for(con=0; con<amount; con++)
    {
        if(fread(&movie, sizeof(movie), 1, fp) != 1)      /*获取电影名*/
        {
            printf("\nfile read wrong!\n");
            getch();
            exit(1);
        }
        pb=(struct Node *)malloc(sizeof(struct Node)); /* 创建包含电影名信息的链表，用于后续的查找 */
        /*malloc函数分配内存，返回起始地址*/
        strcpy(pb->name,movie.name);
        if(total==0) head=pf=pb;
        else pf->next=pb;
        pb->next=NULL;
        pf=pb;
        total++;

        printf("\n 电影名称:《%s》\n",movie.name);     /*输出已存在电影信息*/
        printf(" 电影上映时间:%d年%d月%d日%d:%d\n",movie.date.year,movie.date.mon,movie.date.day,movie.time.hour,movie.time.min);
        printf(" 电影类型:%s、%s\n",movie.type,movie.type2);
        printf(" 电影票价:%.2f\n\n",movie.price);

        if((total != 0) && (total%10 ==0))
        {
            printf("\n\n按任意键继续操作\nPress any key to continue......");
            getch();
            puts("\n\n");
        }
    }
    fclose(fp);
    do
    {
        printf("\n请输入需要修改的电影名字:");      /*输入需要修改的电影名*/
        gets(ID);
        pf=head;
        offset=0;
        while(strcmp(strlwr(pf->name),strlwr(ID)) && pf->next!=NULL)    /*查找电影信息位置*/
        {
            pf=pf->next;
            offset++;
        }
        if(!strcmp(strlwr(pf->name),strlwr(ID))) /* 待修改的记录存在 */
        {
            if((fp=fopen("movie0.txt","rb+"))==NULL)        /* 打开文件失败 */
            {
                printf("\n\nfile open wrong!");
                getch();
                exit(1);
            }
            offset *= sizeof(struct Movie);     /* 使文件位置指针移动到待修改记录处 */
            rewind(fp);      /*文件位置标记重返开头*/
            if(fseek(fp, offset, 0) != 0)
            {
                printf("\n\nfile operation wrong !");
                getch();
                exit(1);
            }
            fread(&movie, sizeof(movie), 1, fp);      /* 读取待修改记录 */
            fseek(fp,(-1)*(long)sizeof(struct Movie), 1); /* 使文件位置指针返回到待修改记录处 */
            printf("\nthe record you want to modify is:\n");    /* 输出待修改记录 */

            printf(" 电影名称:《%s》\n",movie.name);      /* 输出待修改记录 */
            printf(" 电影上映时间:%d年%d月%d日%d:%d\n",movie.date.year,movie.date.mon,movie.date.day,movie.time.hour,movie.time.min);
            printf(" 电影类型:%s、%s\n",movie.type,movie.type2);
            printf(" 电影票价:%.2f\n\n",movie.price);

            do
            {
                /* 选择需要修改的部分 */
                printf("\n\n你可以修改以下内容:1).名称\t2).时间\t3).上映类型\t4).票价\t5).返回");
                printf("\n请选择你需要修改的项目: [ ]\b\b");
                scanf("%d", &ord);
                getchar();
            }
            while(ord>7 || ord<1);
            switch(ord)
            {
            case 1:
                printf("\t将该电影名称修改为:");
                do
                {
                    repeat=0;
                    gets(ID);
                    pb=head;
                    while(strcmp(strlwr(pf->name),strlwr(ID)) && pb->next !=NULL)      //判断名称是否已存在
                        pb=pb->next;
                    if(!strcmp(strlwr(pf->name),strlwr(ID)))
                    {
                        printf("\n该名称已存在，请重新输入...\n\t名称:");
                        repeat=1;
                    }
                }
                while(repeat);         //如果存在则重新输入
                strcpy(movie.name, ID);
                break;
            case 2:
                printf(" 将该电影上映年份修改为(格式如：2020或2021):");
                scanf("%d",&movie.date.year);
                while((movie.date.year!=2020&&movie.date.year!=2021))
                {
                    printf("\n");
                    printf("***************************\n");
                    printf("**                       **\n");
                    printf("** 输入有误，请重新输入！**\n");
                    printf("**                       **\n");
                    printf("***************************\n");
                    printf(" 请输入电影上映年份(范围为2020-2021):");
                    scanf("%d",&movie.date.year);
                }
                printf("\n");
                printf(" 将该电影上映月份修改为(格式如：1~12):");
                scanf("%d",&movie.date.mon);
                while((movie.date.mon<1||movie.date.mon>12))
                {
                    printf("\n");
                    printf("***************************\n");
                    printf("**                       **\n");
                    printf("** 输入有误，请重新输入！**\n");
                    printf("**                       **\n");
                    printf("***************************\n");
                    printf(" 请输入电影上映月份(范围为1~12):");
                    scanf("%d",&movie.date.mon);
                }
                printf("\n");
                printf(" 将该电影上映日期修改为(格式如：1~30):");
                scanf("%d",&movie.date.day);
                while((movie.date.day<1||movie.date.day>31))
                {
                    printf("\n");
                    printf("***************************\n");
                    printf("**                       **\n");
                    printf("** 输入有误，请重新输入！**\n");
                    printf("**                       **\n");
                    printf("***************************\n");
                    printf(" 请输入电影上映日期:");
                    scanf("%d",&movie.date.day);
                }
                printf("\n");
                printf(" 请输入电影上映时间(时)(格式如：0~23):");
                scanf("%d",&movie.time.hour);
                while((movie.time.hour<0||movie.time.hour>23))
                {
                    printf("\n");
                    printf("***************************\n");
                    printf("**                       **\n");
                    printf("** 输入有误，请重新输入！**\n");
                    printf("**                       **\n");
                    printf("***************************\n");
                    printf(" 请输入电影上映时间(时)(范围为0~24):");
                    scanf("%d",&movie.time.hour);
                }
                printf("\n");
                printf(" 请输入电影上映时间(分)(格式如：0~59):");
                scanf("%d",&movie.time.min);
                while((movie.time.min<0||movie.time.min>59))
                {
                    printf("\n");
                    printf("***************************\n");
                    printf("**                       **\n");
                    printf("** 输入有误，请重新输入！**\n");
                    printf("**                       **\n");
                    printf("***************************\n");
                    printf(" 请输入电影上映时间(分)（范围为0~59）:");
                    scanf("%d",&movie.time.min);
                }
                getchar();
                break;

            case 3:
                printf("\t上映类型:");
                scanf("%s%s",movie.type,movie.type2);
                getchar();
                break;

            case 4:
                printf("\t票价:");
                scanf("%f",&movie.price);
                while((movie.price<0||movie.price>1000))
                {
                    printf("\n");
                    printf("***************************\n");
                    printf("**                       **\n");
                    printf("** 输入有误，请重新输入！**\n");
                    printf("**                       **\n");
                    printf("***************************\n");
                    printf(" 请输入电影票价:");
                    scanf("%f",&movie.price);
                }
                getchar();
                break;

            case 5:
            default:
                printf("\n\n");
                //menu();
            }
            printf("\n是否确定修改?\n\n\t1).确定 2).取消并返回 [ ]\b\b");    /*是否确定*/
            scanf("%d",&Yes);
            getchar();
            if(Yes==1)       /* 将更改后的数据写回到文件中去 */
                if((fwrite(&movie, sizeof(struct Movie), 1, fp))==1) printf("\n修改成功 ^_^");
                else printf("\n修改未成功 ! ");
            else
            {
                printf("\n%d\n",Yes);
                getch();
            }
            fclose(fp);
        }
        else
        {
            printf("\n\n您输入的记录未找到!\tany key to continue...");
            getch();
        }
        printf("\n\n是否继续修改?:\t\t1).是\t2).否 [ ]\b\b");/* 是否继续修改其他记录 */
        scanf("%d",&flag);
        getchar();
    }
    while(flag == 1);
    transform_text ();
    free(pb);
    printf("\n\n\t按下任意键以返回管理员界面......");
    getch();
    puts("\n\n");
    //menu();
}


void save()//管理员：电影信息录入
{
    struct Movie*head;
    struct Movie*p1,*p2;
    int n,a,b;
    p1=p2=(struct Movie*) malloc(LEN);
    //malloc是申请内存函数,申请len个字节的内存,并把返回的申请到的内存首地址赋给指针
    system("cls");
    printf("\n\n");
    head=NULL;
    FILE*fp;
    if((fp=fopen("movie.txt","a"))==NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }
    //按提示输入电影相关信息
    printf(" 请输入电影名称:");
    scanf("%s",p1->name);
    printf("\n");
    while(1)
    {
        printf(" 请输入电影上映时间(年)(如:2020或2021):");
        if(! scanf("%d",&p1->date.year))       fflush(stdin);//清空输入缓冲区
        else if(p1->date.year==2020||p1->date.year==2021)  break;
        printf("\n");
    		printf("\t***************************\n");
            printf("\t**                       **\n");
            printf("\t** 输入有误，请重新输入！**\n");
            printf("\t**                       **\n");
            printf("\t***************************\n");
        printf("\n");
    }
    printf("\n");
    while(1)
    {
        printf(" 请输入电影上映时间(月)(范围为：1~12):");
        if(!scanf("%d",&p1->date.mon))           fflush(stdin);//清空输入缓冲区
        else if(!(p1->date.mon<1||p1->date.mon>12))    break;
        printf("\n");
        	printf("\t***************************\n");
            printf("\t**                       **\n");
            printf("\t** 输入有误，请重新输入！**\n");
            printf("\t**                       **\n");
            printf("\t***************************\n");
        printf("\n");
    }
    printf("\n");
    while(1)
    {
        printf(" 请输入电影上映时间(日)(范围为：1~31):");
        if(!scanf("%d",&p1->date.day))            fflush(stdin);//清空输入缓冲区
        else if(!(p1->date.day<1||p1->date.day>31))     break;
        printf("\n");
        	printf("\t***************************\n");
            printf("\t**                       **\n");
            printf("\t** 输入有误，请重新输入！**\n");
            printf("\t**                       **\n");
            printf("\t***************************\n");
        printf("\n");
    }
    printf("\n");
    while(1)
    {
        printf(" 请输入电影上映时间(时)(范围为0~23):");
        if(!scanf("%d",&p1->time.hour))           fflush(stdin);//清空输入缓冲区
        else if(!(p1->time.hour<0||p1->time.hour>23))      break;
        printf("\n");
        	printf("\t***************************\n");
            printf("\t**                       **\n");
            printf("\t** 输入有误，请重新输入！**\n");
            printf("\t**                       **\n");
            printf("\t***************************\n");
        printf("\n");
    }
    printf("\n");
    while(1)
    {
        printf(" 请输入电影上映时间(分)（范围为0~59）:");
        if(!scanf("%d",&p1->time.min))             fflush(stdin);//清空输入缓冲区
        else if(!(p1->time.min<0||p1->time.min>59))        break;
		    printf("\n");
		printf("\t***************************\n");
        printf("\t**                       **\n");
        printf("\t** 输入有误，请重新输入！**\n");
        printf("\t**                       **\n");
        printf("\t***************************\n");
        printf("\n");
    }
    printf("\n");
    printf(" 请输入电影类型(需输入如：喜剧 动作):");
    scanf("%s %s",p1->type,p1->type2);
    printf("\n");
    printf(" 请输入电影票价:") ;
    while(1)
    {
        if(!scanf("%f",&p1->price))                fflush(stdin);//清空输入缓冲区
        else if(!(p1->price<0||p1->price>1000))            break;
        printf("\n");
        printf("\t***************************\n");
        printf("\t**                       **\n");
        printf("\t** 输入有误，请重新输入！**\n");
        printf("\t**                       **\n");
        printf("\t***************************\n");
        printf(" 请输入电影票价:");
        printf("\n");
    }
    getchar();//缓冲
    printf("\n\n");
    char select;
    for(a=0,n=0; a==0;) //循环，可以输入多组数据
    {
        n=n+1;//指针的交替实现动态链表
        if(n==1)head=p1;
        else p2->next=p1;
        p2=p1;
        fprintf(fp,"%s %d %d %d %d %d %s %s %s %f\n",p2->name,p2->date.year,
                p2->date.mon,p2->date.day,p2->time.hour,p2->time.min,p2->type,p2->type2,p2->price);
        //写入链表数据
        for(b=0; b==0;)
        {
        	printf(" 电影录入成功 ^_^\n\n");
            printf(" 是否退出文件编辑(y or n)\n\n");
            printf(" 您的输入是:[ ]\b\b");
            scanf("%c",&select);
            if(select=='y') break;
            if(select=='n') break;
            else
            {
                system("cls");
                printf("\n\n");
                printf("\t***********************\n");
                printf("\t**                   **\n");
                printf("\t** 请输入正确选项!!! **\n");
                printf("\t**                   **\n");
                printf("\t***********************\n\n\n");
            }
        }
        if(select=='y') break;
        if(select=='n') system("cls");
        printf("\n\n");
        printf(" 请输入电影名称:");
        scanf("%s",p1->name);
        printf("\n");
        while(1)
        {
            printf(" 请输入电影上映时间(年)(如:20或21):");
            if(! scanf("%d",&p1->date.year))       fflush(stdin);//清空输入缓冲区
            else if(p1->date.year==20||p1->date.year==21)  break;
            printf("\n");
            printf("\t***************************\n");
            printf("\t**                       **\n");
            printf("\t** 输入有误，请重新输入！**\n");
            printf("\t**                       **\n");
            printf("\t***************************\n");
            printf("\n");
        }
        printf("\n");
        while(1)
        {
            printf(" 请输入电影上映时间(月)(范围为：1~12):");
            if(!scanf("%d",&p1->date.mon))           fflush(stdin);//清空输入缓冲区
            else if(!(p1->date.mon<1||p1->date.mon>12))    break;
            printf("\t***************************\n");
            printf("\t**                       **\n");
            printf("\t** 输入有误，请重新输入！**\n");
            printf("\t**                       **\n");
            printf("\t***************************\n");
            printf("\n");
        }
        printf("\n");
        while(1)
        {
            printf(" 请输入电影上映时间(日)(范围为：1~31):");
            if(!scanf("%d",&p1->date.day))            fflush(stdin);//清空输入缓冲区
            else if(!(p1->date.day<1||p1->date.day>31))     break;
            printf("\n");
            printf("\t***************************\n");
            printf("\t**                       **\n");
            printf("\t** 输入有误，请重新输入！**\n");
            printf("\t**                       **\n");
            printf("\t***************************\n");
            printf("\n");
        }
        printf("\n");
        while(1)
        {
            printf(" 请输入电影上映时间(时)(范围为0~23):");
            if(!scanf("%d",&p1->time.hour))           fflush(stdin);//清空输入缓冲区
            else if(!(p1->time.hour<0||p1->time.hour>23))      break;
            printf("\n");
            printf("\t***************************\n");
            printf("\t**                       **\n");
            printf("\t** 输入有误，请重新输入！**\n");
            printf("\t**                       **\n");
            printf("\t***************************\n");
            printf("\n");
        }
        printf("\n");
        while(1)
        {
            printf(" 请输入电影上映时间(分)（范围为0~59）:");
            if(!scanf("%d",&p1->time.min))             fflush(stdin);//清空输入缓冲区
            else if(!(p1->time.min<0||p1->time.min>59))        break;
            printf("\n");
            printf("\t***************************\n");
            printf("\t**                       **\n");
            printf("\t** 输入有误，请重新输入！**\n");
            printf("\t**                       **\n");
            printf("\t***************************\n");
            printf("\n");
        }
        printf("\n");
        printf(" 请输入电影类型(如:喜剧/动作):");
        scanf("%s",p1->type);
        printf(" 请输入电影类型(如:喜剧/动作):");
        scanf("%s",p1->type2);
        printf("\n");
        printf(" 请输入电影票价:") ;
        while(1)
        {
            if(!scanf("%f",&p1->price))                fflush(stdin);//清空输入缓冲区
            else if(!(p1->price<0||p1->price>1000))    break;
            printf("\n");
            printf("\t***************************\n");
            printf("\t**                       **\n");
            printf("\t** 输入有误，请重新输入！**\n");
            printf("\t**                       **\n");
            printf("\t***************************\n");
            printf(" 请输入电影票价:");
            printf("\n");
        }
        printf("\n\n");
        getchar();//缓冲
    }
    p2->next=NULL;
    fclose(fp);

}
//用动态链表输入数据，并将数据存储在建立的movie.txt文件中


void del()      // 管理员：信息删除函数
{
    struct Node
    {
        char name[100];
        struct Node * next;
    };
    int amount;      // 信息文件中的记录总数
    int con=0;      // 已处理的文件记录总数
    struct Node * head=NULL, * pf=NULL, * pb=NULL;
    struct Movie movie;
    FILE * fp, *fp1;      // fp 用于指示信息文件 inform，而 fp1 用于指示临时文件
    int total=0;
    int offset=0;      // 文件位置指针偏移量
    int flag=0;      // 指示是否继续进行修改，为 1 时继续
    char ID[100];     // 待修改的记录的职工号
    int Yes=0;      // 指示是否保存修改
    if((fp=fopen("movie.txt","r")) == NULL)       /*打开文件*/
    {
        printf("\tCan not open the inform file!");
        getch();
        exit(1);
    }
    transform_2 ();
    fclose(fp);
    amount=load("movie0.txt");
    fp=fopen("movie0.txt","rb");
    for(con=0; con<amount; con++)
    {
        if(fread(&movie, sizeof(movie), 1, fp) != 1)
        {
            printf("\nfile read wrong!\n");
            getch();
            exit(1);
        }
        pb=(struct Node *)malloc(sizeof(struct Node));   // 创建包含 num 信息的链表，用于后续的查找
        strcpy(pb->name, movie.name);
        if(total==0) head=pf=pb;
        else pf->next=pb;
        pb->next=NULL;
        pf=pb;
        total++;

        printf(" 电影名称:《%s》\n",movie.name);
        printf(" 电影上映时间:%d年%d月%d日%d:%d\n",movie.date.year,movie.date.mon,movie.date.day,movie.time.hour,movie.time.min);
        printf(" 电影类型:%s、%s\n",movie.type,movie.type2);
        printf(" 电影票价:%.2f\n\n",movie.price);

        if((total != 0) && (total%10 ==0))
        {
            printf("\n\n按下任意键继续操作\nPress any key to continue......");
            getch();
            puts("\n\n");
        }
    }
    fclose(fp);
    do
    {
        printf("请输入需要删除的电影名:");
        gets(ID);
        pf=head;
        while(strcmp(strlwr(pf->name),strlwr(ID)) && pf->next!=NULL)
        {
            pf=pf->next;
            offset++;
        }
        if(!strcmp(strlwr(pf->name),strlwr(ID)))     // 待删除的记录存在
        {
            printf("\n是否确定删除?:\t\t1).确认\t2).取消 [ ]\b\b");
            scanf("%d",&Yes);
            if(Yes==1)     // 如果确定要删除该记录
            {
                if((fp=fopen("movie0.txt","rb"))==NULL)
                {
                    printf("\n\nfile open wrong!");
                    getch();
                    exit(1);
                }
                if((fp1=fopen("movie_temp.txt","wb"))==NULL)
                {
                    printf("\n\nfile open wrong!");
                    getch();
                    exit(1);
                }
                total=0;
                amount=load("movie0.txt");
                for(con=0; con<amount; con++)
                {
                    if(total==offset-1) fseek(fp,(long)sizeof(struct Movie),1);
                    fread(&movie,sizeof(struct Movie),1,fp);
                    if(strcmp(strlwr(pf->name),strlwr(ID)))
                   		fwrite(&movie,sizeof(struct Movie),1,fp1);
                }
                fclose(fp1);
                fclose(fp);
                remove("movie0.txt");         // 删除旧文件
                rename("movie_temp.txt","movie0.txt");      // 临时文件替换原文件
            }
        }
        else    // 待删除的记录不存在
        {
            printf("\n\n您输入的记录未找到!\tany key to continue...");
            getch();
        }
        printf("\n删除成功！^_^\n");
        printf("\n\n是否继续?:\t\t1).Yes\t2).No [ ]\b\b");
        scanf("%d",&flag);
        getchar();
    }
    while(flag == 1);
    transform_text ();
    printf("\n\n\t按下任意键以返回管理员界面......");
    getch();
    puts("\n\n");
    //menu();
}


void gaimi()     //修改管理员密码程序
{
    system("cls");
    char c;
    int j;
    FILE *fe;
    if((fe=fopen("name.txt","w"))==NULL)
    {
        printf("文件打开错误！");
        exit(0);
    }
    printf("\n请输入您的原始密码:\n");
    fflush(stdin);         //清除缓冲
    for(j=0; j<100; j++)
    {
        us.pwd[j]=getch();
        if(us.pwd[j]=='\r')
            break;
        printf("*");
    }
    us.pwd[j]='\0';
    if((strcmp(us.pwd,pwd1)==0))
    {
        printf("\n请输入您要修改的密码\n");
        for(j=0; j<100; j++)
        {
            us.pwd[j]=getch();
            if(us.pwd[j]=='\r')
                break;
            printf("*");
        }
        us.pwd[j]='\0';
        fflush(stdin);         //清除缓冲
        printf("\n请再次确认你的密码\n");
        for(j=0; j<100; j++)
        {
            pwd1[j]=getch();
            if(pwd1[j]=='\r')
                break;
            printf("*");
        }
        pwd1[j]='\0';
        if((strcmp(us.pwd,pwd1)==0))
        {
        	FILE *fe;
		    fe=fopen("name.txt","a");
		        fprintf(fe,"%s\n",us.pwd);
		    fclose(fe);
            printf("\n\n密码修改成功，请重新登录。\n");
            Sleep(1000);
            system("cls");
            login();
        }
        else
        {
            printf("\n\n两次密码不符合，本次服务到此结束！\n\n");
            printf("\n\n按任意键返回\n");
            c=getch();
            system("cls");
            admin();
        }
    }
    else
    {
        printf("\n密码输入错误！\n\n");
        printf("\n\n按任意键返回\n");
        c=getch();
        system("cls");
        admin();
    }
}


void users_interface()	//用户登录界面
{
    while(1)//使最初界面始终在主界面而不关闭程序
    {
        system("cls");
        printf("\n\n\n");
        printf("\t\t******************************************************\n");
        printf("\t\t***               购票用户登录界面                 ***\n");
        printf("\t\t******************************************************\n");
        printf("\t\t***                                                ***\n");
        printf("\t\t***                                                ***\n");
        printf("\t\t***           请选择:                              ***\n");
        printf("\t\t***                 1.注册                         ***\n");
        printf("\t\t***                 2.登录                         ***\n");
        printf("\t\t***                                                ***\n");
        printf("\t\t***                                                ***\n");
        printf("\t\t******************************************************\n");
        printf("\t\t******************************************************");
        printf("\n\n");
        printf("\t\t您的选择是:[ ]\b\b");
        char select;
        scanf("%c",&select);
        if(select=='1')registers();
        if(select=='2')Input_login();
        system("cls");
    }
}

/*注册账号*/
void registers()  //按结构体的大小，一次写入或者读入1个结构体大小
{
    system("cls");
    printf("\t\t★★★★★★★  欢迎使用注册系统  ★★★★★★★\n");
    int i,j;
    int z=0;
    char name[20];
    char zh[20];
a:
    printf("\t\t请输入姓名:");
    scanf("%s",name);
    printf("\t\t请输入账号：");
    scanf("%s",zh);
    for (i=0; i<=z; i++)
    {
        if(strcmp(name,custom[i].name)==0||strcmp(zh,custom[i].zh)==0)
        {
            printf("\t\t用户名或账号已存在！\n");
            printf("\t\t请重新输入：\n\n");
            goto a;
        }
    }
    strcpy(custom[z].name,name);
    strcpy(custom[z].zh,zh);


b:
    printf("\t\t请输入密码(6位数字):");
    scanf("%s",custom[z].code);
    if(strlen(custom[z].code)!=6)
    {
        printf("\t\t密码格式输入错误，请重新输入\n");
        goto b;
    }
    z++;
    printf("\t\t注册成功！\n\t\t正在返回");
    for(i=0; i<6; i++)
    {
        printf(".");
        Sleep(200);
    }
    FILE *fq;
    fq=fopen("file","a");
    for(j=0; j<z; j++)
    {
        fprintf(fq,"%s %s %s\n",custom[j].name,custom[j].zh,custom[j].code);
    }
    fclose(fq);
    users_interface();
}


/*创建储存用户账号密码的文件*/
void Create_File()
{
    int z;
    FILE *fq;
    int j=0;
    if((fq=fopen("file","r"))==NULL)
    {
        printf("用户信息文件不存在！\n");
        printf("请进行注册！\n");
        registers();
    }
    while(fscanf(fq,"%s%s%s",custom[j].name,custom[j].zh,custom[j].code)==3)
    {
        j++;
    }
    if(j==0)
    {
        printf("用户信息为空！请进行注册，否则不能进入系统\n");
        registers();
    }
    z=j;
    fclose(fq);
}


/*用户登录系统*/
void Input_login()
{
    system("cls");
    Create_File();
    printf("\t\t★★★★★★★  欢迎使用登录系统  ★★★★★★★\n");
    char zh[20],name[20],code[7];
    int a=0,i,k,f=0,u=0;
    printf("\t\t请输入账号:");
a:
    if(f==3)
    {
        printf("输入3次无效账号退出登录！");
        Sleep(1000);
        menu();
    }
    scanf("%s",zh);
    for (i=0; i<=3; i++)
    {
        if (strcmp(zh,custom[i].zh)==0)
        {
            a=1;
            k=i;
        }
    }
    if(a==0)
    {
        printf("\t\t该账号不存在！\n\n");
        printf("\t\t请重新输入账号：");
        f=f+1;
        goto a;
    }
    printf("\t\t请输入密码:");
b:
    for(i=0; i<100; i++)
    {
        code[i]=getch();
        if(code[i]=='\r')
            break;
        printf("*");
    }
    code[i]='\0';
    if (strcmp(code,custom[k].code)!=0)
    {
        printf("\t\t密码错误，请重新输入:");
        u++;
        if(u==3)
        {
            printf("输入3次无效密码退出登录！");
            Sleep(1000);
            menu();
        }
        goto b;
    }
    printf("\n\t\t登陆中");
    for(i=0; i<6; i++)
    {
        printf(".");
        Sleep(200);
    }
    user();
}


void user()//用户界面
{
    int n,w1;
    system("cls");
    while(1)//循环使得退出后能在选择界面
    {
        do
        {
            system("cls");
            puts("\t\t\t        欢迎进入用户界面！ ");
            puts("\t\t*********************菜单*********************\n\n");
            puts("\t\t\t\t1.显示电影信息");
            puts("\t\t\t\t2.电影信息排序");
            puts("\t\t\t\t3.电影信息查询");
            puts("\t\t\t\t4.售票/退票");
            puts("\t\t\t\t5.退出至主界面");
            puts("\n\n\t\t**********************************************\n");
            printf("请选择数字(1-5): [ ]\b\b");
            scanf("%d",&n);
            getchar();
            if(n<1||n>5) //对选择的数字作判断
            {
                w1=1;
                getchar();
            }
            else w1=0;
        }
        while(w1==1);
        switch(n) //菜单选择功能
        {
        case 1:
            save_out();
            break; //信息显示模块
        case 2:
            sort();
            break; //信息排序模块
        case 3:
            search();
            break;//信息查询模块
        case 4:
            book();
            break;//选票退票
        case 5:
            menu();
            break;
            //case 4:book();break;
            //default: ;/*退出*/
        }
    }
}


void book()	//用户:电影售票与退票
{
	system("cls");
	char a[100];
    int b,c,d,e,f;
    char g[100];
    char h[100];
    char q[100];
    float i;
    int v=1;
    int aw[Hang][Lie];//可改变座位行列数
    //座位数组
    int num;
    int m,j;
    for(m=0; m<Hang; m++)
        for(j=0; j<Lie; j++)
            aw[m][j]=0;
    
    //intseat初始化座位
    FILE *in;
        if((in=fopen("movie.txt","r"))==NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }
     while(!feof(in))//判断是否在文件尾
    {
    	printf("(%d)",v);
		fscanf(in,"%s %d %d %d %d %d %s %s %f\n",a,&b,&c,&d,&e,&f,h,q,&i);
        printf("\t电影名称:《%s》",a);
        printf("\n");
    	printf("\t电影上映时间:%d年%d月%d日%d:%d",b,c,d,e,f);
        printf("\n\n");
        v++;
    }
    int k,l,count;

    /*printf("\n请输入观影日期(29-31)：");
    printf("\t您的选择是:[ ]\b\b");
    scanf("%d",&l);*/
    printf("\n请输入您想观看电影的序号(1-10):");
    printf("\t您的选择是:[  ]\b\b\b");
    scanf("%d",&k);
    int choice=1;
    fclose(in);
    while(choice)
    {
        int z;
        printf("继续操作or返回(1/0):[ ]\b\b");
        scanf("%d",&z);
        switch(z)
        {
        case 1:
        {
        	system("cls");
            puts("\t\t\t     欢迎进入电影票订购！ ");
            puts("\t\t*********************菜单*********************\n\n");
            puts("\t\t\t\t1.查询座位信息");
            puts("\t\t\t\t2.购买电影票");
            puts("\t\t\t\t3.售后退票");
            puts("\t\t\t\t4.返回");
            puts("\n\n\t\t**********************************************\n");
            printf("请选择你的数字(1-3): [ ]\b\b");
            scanf("%d",&num);
            break;
        }
        case 0:
        {
            printf("****退出成功!!欢迎下次光临****\n");
            choice = 0;
            num = 0;
            break;
        }
        default:
            break;
        }

        switch(num)
        {
        case 1:
        {
            printf("查询座位信息:\n");
            count=0;
            printf("\t\t\t\t电影院座位表：\n\t\t");
            for(m=0; m<Hang; m++)
                for(j=0; j<Lie; j++)
                {
                    if(aw[m][j]==1)
                        printf(" ▇ ");
                    else
                        printf(" □ ");
                    count++;
                    if(count%10==0)
                        printf("\n\t\t");//输出座位
                }
            break;
        }
        case 2://选座
        {
            int x,y;
            int choice;
            srand(time(0));//读取计算机时间(从而实现取随机数)
            printf("\n请选择手动选择还是系统随机（1 or 0）：\n 1.手动选择\t 0.系统随机\t[ ]\b\b");
            scanf("%d",&choice);//赋值给choice选择手动与随机
            while((choice!=0)&&(choice!=1))
            {
                printf("\n输入错误，请重新选择（1 or 0）：\n 1.手动选择\t 0.系统随机\n");
                scanf("%d",&choice);
            }
            if(choice)
            {
                count=0;
                printf("\t\t\t\t电影院座位表：\n\t\t");
                for(m=0;m<Hang; m++)
                    for(j=0; j<Lie; j++)
                    {
                        if(aw[m][j]==1)
                            printf(" ▇ ");
                        else
                            printf(" □ ");
                        count++;
                        if(count%10==0)
                            printf("\n\t\t");//输出座位
                    }
                printf("\n请选择你要的位置\t行:");
                scanf("%d",&m);
                printf("\n\t\t\t列:");
                scanf("%d",&j);
                while(!((0<=m)&(m<=Hang))||!((0<=j)&(j<=Lie)))
                {
                    printf("\n输入错误，请重新选择你要的位置（x，y）：");
                    scanf("%d,%d",&m,&j);
                }
            }
            else
            {
                m=rand()%Hang+1,j=rand()%Lie+1;//i和j取1-Hang/Lie的随机数
            }
            while (aw[m-1][j-1]==1)
            {
                printf("\n您选择的座位已经出售,请重新输入; \t行:");
                scanf("%d",&m);
                printf("\n\t\t\t\t\t列:");
                scanf("%d",&j);
            }
            printf("恭喜您购买成功!!\n");
            x=m-1,y=j-1;
            aw[x][y]=1;//改变所选的座位状态

            printf("\t\t\t\t电影院座位表：\n\t\t");
            for(m=0; m<Hang;m++)
                for(j=0; j<Lie; j++)
                {
                    if(aw[m][j]==1)
                        printf(" ▇ ");
                    else
                        printf(" □ ");
                    count++;
                    if(count%10==0)
                        printf("\n\t\t");//输出座位
                }
            printf("你的位置坐标为（%d，%d）\n",x+1,y+1);
            break;
        }
        case 3://退票
        {
            printf("退票:\n");
            printf("\n请选择你要退订的位置\t行:");
            scanf("%d",&m);
            printf("\n\t\t\t列:");
            scanf("%d",&j);
            if (aw[m-1][j-1]==0)
            {
                printf("输入错误,请重新输入!\n");
            }
            else
            {
                aw[m-1][j-1]=0;
                printf("退票成功!\n");
            }
            int count=0;
            printf("\t\t\t\t电影院座位表：\n\t\t");
            for(m=0; m<Hang; m++)
                for(j=0; j<Lie; j++)
                {
                    if(aw[m][j]==1)
                        printf(" ▇ ");
                    else
                        printf(" □ ");
                    count++;
                    if(count%10==0)
                        printf("\n\t\t");//输出座位
                }
            break;
        }
        case 4:
        {
            printf("******退出成功!!欢迎下次光临******\n");
            choice = 0;
            break;
        }
        default:
            break;
        }
    }
}


void save_out()//显示电影信息模块
{
    system("cls");
    FILE*in;
    if((in=fopen("movie.txt","r"))==NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }
    char name_1[100];
    int year_1,mon_1,day_1,hour_1,min_1;
    int j = 1,flag = -1;
    char g[100];
    char h[100];
    char q[100];
    float i;
    while(!feof(in))//判断是否在文件尾
    {
        printf("\n\n");
        printf("(%d)",j);
        fscanf(in,"%s %d %d %d %d %d %s %s %f\n",name_1,&year_1,&mon_1,&day_1,&hour_1,&min_1,h,q,&i);
        printf("\t电影名称:《%s》",name_1);
        printf("\n");
        printf("\t电影上映时间:%d年%d月%d日%d:%d",year_1,mon_1,day_1,hour_1,min_1);
        printf("\n");
        printf("\t电影类型:%s、%s",h,q);
        printf("\n");
        printf("\t电影票价:%.2f",i);
        printf("\n");
        j++;
    }
    printf("\n是否进行购票or返回(1/0)：[ ]\b\b"); 
    scanf("%d",&flag);
    while((flag!=0)&&(flag!=1))
            {
                printf("\n输入错误，请重新选择（1 or 0）：\n 1.手动选择\t 0.系统随机\n");
                scanf("%d",&flag);
            }
    if(flag == 1)
        book();
    if(flag ==0)
    {
        getchar();//缓冲
        fclose(in);
    }

}
//将文件中所有数据展示给电影操作员，操作员可以通过查阅数据决定是否对数据修改、增添，是否返回选择界面

int load(char * a)//计算参数所指定的文件中记录的电影信息总数
{
    struct Movie movie;
    FILE *fp;
    int i;
    if((fp=fopen(a,"rb"))==NULL)
    {
        printf("\nCannot open file\n");
        getch();
        return 0;
    }
    for(i=0; !feof(fp); i++)
        fread(&movie,sizeof(struct Movie),1,fp);
    fclose(fp);
    return(i-1); //返回记录个数
}


void transform_2()//文件类型转换（文本->二进制）
{
    struct Movie movie;
    FILE *in, *out;
    in=fopen("movie.txt","r");
    out=fopen("movie0.txt","wb+");
    while(!feof(in))
    {
        fscanf(in,"%s %d %d %d %d %d %s %s %f\n",
               movie.name,&movie.date.year,&movie.date.mon,&movie.date.day,
               &movie.time.hour,&movie.time.min,movie.type,movie.type2,&movie.price);
        fwrite(&movie, sizeof(struct Movie), 1, out);
    }
    fclose(in);
    fclose(out);
}


void transform_text () //文件类型转换（二进制->文本）
{
    struct Movie movie;
    FILE *in, *out;
    int amount;     // 信息文件中的记录总数
    int con;      //已处理的文件记录总数
    in=fopen("movie0.txt","rb");
    out=fopen("movie1.txt","w+");
    amount=load("movie0.txt");
    for(con=0; con<amount; con++)
    {
        fread(&movie, sizeof(struct Movie),1,in);
        fprintf(out,"%s %d %d %d %d %d %s %s %f\n",
                movie.name,movie.date.year,movie.date.mon,movie.date.day,
                movie.time.hour,movie.time.min,movie.type,movie.type2,movie.price);
    }
    fclose(in);
    fclose(out);
    remove("movie0.txt");         //删除旧文件
    remove("movie.txt");
    rename("movie1.txt","movie.txt");      //临时文件替换原文件
}


void sort()//定义排序函数
{
    FILE*in;
    int flag;
    int total;//符合条件的记录数
    int movie_price[20];
    int movie_day[10];
    int movie_hour[10];
    int t,t1,t2;//电影票价格排序方式选择标志位,t=1,价格升序；t=2,价格降序
    int n,qw,q2;
    int w;//相同标志位 ,w与i比较
    int l1=1;//复位
    float i;
    int year1;
    int l;//test
    char a[100];
    int b,c,d,e,f;
    char h[100];
    char q[100];
    printf("\n");
    printf("|**************************************************************|");
    printf("\n\n\t请输入您所需的排序方式:\n\t(1)电影票价格排序\t(2)电影时间排序\n\t[ ]\b\b");
    scanf("%d",&flag);
    while(!(flag==1||flag==2))
    {
        printf("\t输入有误，请重新输入,例如输入1或2\n\t[ ]\b\b");
        scanf("%d",&flag);
    }
    if(flag==1) /* 按电影票价格排序 */
    {
        printf("\n");
        printf("|**************************************************************|");
        printf("\n\t进入电影票价格排序系统\n");
        printf("\t请选择排序方式：\n\t（1）价格升序\t(2)价格降序\n\t[ ]\b\b");
        scanf("%d",&t);
        while(!(t==1||t==2))
        {
            printf("\t输入有误，请重新输入,例如输入1或2\n\t[ ]\b\b");
            scanf("%d",&t);
        }




        if((in=fopen("movie.txt","r"))==NULL)//打开文档
        {
            printf("cannot open file\n");
            exit(0);
        }

        for(total=0; !feof(in); total++)
        {
            fscanf(in,"%s %d %d %d %d %d %s %s %f\n",a,&b,&c,&d,&e,&f,h,q,&i);
            movie_price[total]=i;
        }
        fclose(in);
        //起泡法排序
        for(i=0; i<total-1; i++)
        {
            for(n=0; n<total-1-i; n++)
            {
                if(movie_price[n]<movie_price[n+1])
                {
                    qw=movie_price[n];
                    movie_price[n]=movie_price[n+1];
                    movie_price[n+1]=qw;
                }
            }
        }
        if(t==1)//价格升序
        {
            printf("\n\t电影票价格升序排序:");
            printf("\n\t系统查询结果:\n");

            for(l=total-1; l>=0; l--) //与原数值匹配,升序
            {
                if((in=fopen("movie.txt","r"))==NULL)//打开文档
                {
                    printf("cannot open file\n");
                    exit(0);
                }

                while(!feof(in))
                {
                    fscanf(in,"%s %d %d %d %d %d %s %s %f\n",a,&b,&c,&d,&e,&f,h,q,&i);
                    if(movie_price[l]==i)
                    {
                        if(w==movie_price[l])//出现相同匹配
                        {
                        }
                        else
                        {
                            printf("\n(%d)",l1);
                            printf("\t电影名称:《%s》",a);
                            printf("\n");
                            printf("\t电影上映时间:%d年%d月%d日%d:%d",b,c,d,e,f);
                            printf("\n");
                            printf("\t电影类型:%s、%s",h,q);
                            printf("\n");
                            printf("\t电影票价:%.2f",i);
                            printf("\n\n");
                            l1++;
                        }
                    }
                }
                w=movie_price[l];//记录上次的比较值
                fclose(in);//关闭
            }
            l1=1;//复位
        }
        else if(t==2)//价格降序
        {
            printf("\n\t电影票价格降序排序:\n");
            printf("\n\t系统查询结果：\n");
            //title();
            for(l=0; l<=total-1; l++) //与原数值匹配,降序
            {
                if((in=fopen("movie.txt","r"))==NULL)//打开文档
                {
                    printf("cannot open file\n");
                    exit(0);
                }
                while(!feof(in))
                {
                    fscanf(in,"%s %d %d %d %d %d %s %s %f\n",a,&b,&c,&d,&e,&f,h,q,&i);
                    if(movie_price[l]==i)
                    {
                        if(w==movie_price[l])//出现相同匹配
                        {
                        }
                        else
                        {
                            printf("(%d)\n",l1);
                            printf("\t电影名称:《%s》",a);
                            printf("\n");
                            printf("\t电影上映时间:%d年%d月%d日%d:%d",b,c,d,e,f);
                            printf("\n");
                            printf("\t电影上映类型:%s、%s",h,q);
                            printf("\n");
                            printf("\t电影票价:%.2f",i);
                            printf("\n\n");
                            l1++;
                        }
                    }
                }
                w=movie_price[l];//记录上次的比较值
                fclose(in);//关闭
            }
        }
    }

    if(flag==2) //按电影时间排序
    {

        printf("\n");
        printf("|**************************************************************|");
        printf("\n\t进入电影票时间排序\n");
        printf("\t请选择排序方式：\n\t（1）时间升序\t(2)时间降序\n\t[ ]\b\b");
        scanf("%d",&t);
        while(!(t==1||t==2))
        {
            printf("\t输入有误，请重新输入,例如输入1或2\n\t[ ]\b\b");
            scanf("%d",&t);
        }
        if(t==1)//电影时间升序
        {
            do
            {
                qw=0;//复位
                printf("\n");
                printf("|**************************************************************|");
                printf("\n\t进入电影时间升序排序\n");
                printf("\n\t系统查询结果：\n");
                if((in=fopen("movie.txt","r"))==NULL)//打开文档
                {
                    printf("cannot open file\n");
                    exit(0);
                }
                for(total=0,t=0; !feof(in); total++) //升序
                {
                    fscanf(in,"%s %d %d %d %d %d %s %s %f\n",a,&b,&c,&d,&e,&f,h,q,&i);
                        movie_day[t]=d;//记录下来
                        //printf("已记录\n");
                        t++;
                        //day排序
                        for(i=0; i<t-1; i++)
                        {
                            for(n=0; n<t-1-i; n++)
                            {
                                if(movie_day[n]<movie_day[n+1])
                                {
                                    qw=movie_day[n];
                                    movie_day[n]=movie_day[n+1];
                                    movie_day[n+1]=qw;
                                }
                            }
                        }
                    //w=movie_price[l];//记录上次的比较值
                }
                if(t!=0)
                {
                    printf("\t共为您找到%d条符合条件的信息\n",t);

                    for(l=t-1; l>=0; l--) //与原数值匹配,升序 读取后排序后输出
                    {
                        if((in=fopen("movie.txt","r"))==NULL)//打开文档
                        {
                            printf("cannot open file\n");
                            exit(0);
                        }
                        while(!feof(in))
                        {
                            fscanf(in,"%s %d %d %d %d %d %s %s %f\n",a,&b,&c,&d,&e,&f,h,q,&i); 
								if(movie_day[l]==d){
								if(w==movie_day[l])//出现相同匹配
                                {}
                                else
                                {
                                    printf("\n(%d)",l1);
                                    printf("\t电影名称:《%s》",a);
                                    printf("\n");
                                    printf("\t电影上映时间:%d年%d月%d日",b,c,d);
                                    printf("\n");
                                    printf("\t电影类型:%s、%s",h,q);
                                    printf("\n");
                                    printf("\t电影票价:%.2f",i);
                                    printf("\n\n");
                                    l1++;
                                }
								}
								else
								{}
                         
                        }
                        w=movie_day[l];//记录上次的比较值
                        fclose(in);//关闭
                    }
                    t=0;//复位
                }
                else
                {
                    printf("\n\t没有找到符合条件的信息\n");
                    printf("\n\n\tPress any key to continue......");
                    getch();
                    puts("\n\n");
                    printf("\t如需重新查询，请输入1\t如退出，请输入2\t\n\t[ ]\b\b");
                    getchar();
                    scanf("%d",&qw);
                    while(!(qw==1||qw==2))
                    {
                        printf("\n\t输入有误，请重新输入\n");
                        printf("\t如需重新查询，请输入1\t如退出，请输入2\t\n\t[ ]\b\b");
                        getchar();
                        scanf("%d",&qw);
                    }
                }
                fclose(in);//关闭
                printf("\n");
                /*	for(l=t-1;l>=0;l--)//测试用，可删除
                {
                printf("\t输出原来排序%d\n",movie_day[l]);
                } */
            }while(qw==1);
        }


       if(t==2)//电影时间降序 
        {
            do
            {
                qw=0;//复位
                printf("\n");
                printf("|**************************************************************|");
                printf("\n\t进入电影时间降序排序\n");
                printf("\n\t系统查询结果：\n");
                if((in=fopen("movie.txt","r"))==NULL)//打开文档
                {
                    printf("cannot open file\n");
                    exit(0);
                }
                for(total=0,t=0; !feof(in); total++) //降序
                {
                    fscanf(in,"%s %d %d %d %d %d %s %s %f\n",a,&b,&c,&d,&e,&f,h,q,&i);
                        movie_day[t]=d;//记录下来
                        t++;
                        //day排序
                        for(i=0; i<t-1; i++)
                        {
                            for(n=0; n<t-1-i; n++)
                            {
                                if(movie_day[n]<movie_day[n+1])
                                {
                                    qw=movie_day[n];
                                    movie_day[n]=movie_day[n+1];
                                    movie_day[n+1]=qw;
                                }
                            }
                        }
                    //w=movie_price[l];//记录上次的比较值
                }
                if(t!=0)
                {
                    printf("\t共为您找到%d条符合条件的信息\n",t);

                    for(l=0; l<=t-1; l++) //与原数值匹配,降序 读取后排序后输出
                    {
                        if((in=fopen("movie.txt","r"))==NULL)//打开文档
                        {
                            printf("cannot open file\n");
                            exit(0);
                        }
                        while(!feof(in))
                        {
                            fscanf(in,"%s %d %d %d %d %d %s %s %f\n",a,&b,&c,&d,&e,&f,h,q,&i); 
								if(movie_day[l]==d){
								if(w==movie_day[l])//出现相同匹配
                                {}
                                else
                                {
                                    printf("\n(%d)",l1);
                                    printf("\t电影名称:《%s》",a);
                                    printf("\n");
                                    printf("\t电影上映时间:%d年%d月%d日",b,c,d);
                                    printf("\n");
                                    printf("\t电影类型:%s、%s",h,q);
                                    printf("\n");
                                    printf("\t电影票价:%.2f",i);
                                    printf("\n\n");
                                    l1++;
                                }
								}
								else
								{}
                        }
                        w=movie_day[l];//记录上次的比较值
                        fclose(in);//关闭
                    }
                    t=0;//复位
                }
                else
                {
                    printf("\n\t没有找到符合条件的信息\n");
                    printf("\n\n\tPress any key to continue......");
                    getch();
                    puts("\n\n");
                    printf("\t如需重新查询，请输入1\t如退出，请输入2\t\n\t[ ]\b\b");
                    getchar();
                    scanf("%d",&qw);
                    while(!(qw==1||qw==2))
                    {
                        printf("\n\t输入有误，请重新输入\n");
                        printf("\t如需重新查询，请输入1\t如退出，请输入2\t\n\t[ ]\b\b");
                        getchar();
                        scanf("%d",&qw);
                    }
                }
                fclose(in);//关闭
                printf("\n");
                /*	for(l=t-1;l>=0;l--)//测试用，可删除
                {
                printf("\t输出原来排序%d\n",movie_day[l]);
                } */
            }while(qw==1);
        }
    }
    printf("\n\n\t按下任意键以返回上一界面......");
    getch();
    puts("\n\n");
    //menu();
}


void search()//查询功能
{

    FILE*in;
    int flag;
    int total;//符合条件的记录数
    char str[100];//输入查询电影类型 
    float i;//i=0即信息输入有误
    float price1,price2;//用于比较范围

    int qw;
    int l1=1;//复位

    char a[100];
    int b,c,d,e,f,t;
    char g[100];
    char h[100];
    char q[100];
    do
    {
        printf("\n\n\t请输入您所需的查询方式:\n\t(1)电影类型查询\t(2)电影价格查询\n\t[ ]\b\b");
        scanf("%d",&flag);
    }
    while(!(flag==1||flag==2));
    if(flag==1) /* 按电影类型查询 */
    {
        printf("\n");
        printf("|**************************************************************|");
        printf("\n\t进入电影类型查询\n");
        do
        {
            i=0,qw=0;//标志位复位
            printf("\t请输入查询类型(如：喜剧/动作)：");
            fflush(stdin);//使 gets（）正常运行
            gets(str);
            printf("\t您想要查询的名称为%s\n",str);
            printf("\n\t系统查询结果：\n");
            //title();
            //电影类型查询匹配
            //与原数值匹配,升序

            if((in=fopen("movie.txt","r"))==NULL)//打开文档
            {
                printf("cannot open file\n");
                exit(0);
            }
            //fgetc(in);
            while(!feof(in))
            {
                fscanf(in,"%s %d %d %d %d %d %s %s %f\n",a,&b,&c,&d,&e,&f,h,q,&i);
                if(!strcmp(str,h)||!strcmp(str,q))
                {
                    printf("(%d)\n",l1);
                    printf("\t电影名称:《%s》",a);
                    printf("\n");
                    printf("\t电影上映时间:%d年%d月%d日",b,c,d);
                    printf("\n");
                    printf("\t电影类型:%s、%s",h,q);
                    printf("\n");
                    printf("\t电影票价:%.2f",i);
                    printf("\n\n");
                    l1++;
                }
            }
            fclose(in);//关闭

            total=l1-1;
            if(total!=0)
            {
                printf("\t共为您找到%d条符合条件的信息\n\n",total);
                total=0;//复位
                printf("\t如需重新查询，请输入1\t如退出，请输入2\t\n\t[ ]\b\b");
                i=0;
                scanf("%d",&qw);
                while(!(qw==1||qw==2))
                {
                    printf("\n\t输入有误，请重新输入\n");
                    scanf("%d",&qw);
                }
            }
            else
            {
                printf("\n\t没有找到符合条件的信息\n");
                printf("\n\tPress any key to continue......\n");
                printf("\t如需重新查询，请输入1\t如退出，请输入2\t\n\t[ ]\b\b");
                i=0;
                scanf("%d",&qw);
                while(!(qw==1||qw==2))
                {
                    printf("\n\t输入有误，请重新输入\n");
                    scanf("%d",&qw);
                }
            }
        }
        while(qw==1);
    }

    if(flag==2) /* 按电影价格查询 */
    {
        printf("\n");
        printf("|**************************************************************|");
        printf("\n\t进入电影价格查询\n");
        do
        {
            i=0,qw=0;//标志位复位
            printf("\t请输入查询价格范围：\n\t(1)30~40\t(2)40~50\t(3)>50\n\t[ ]\b\b");
            scanf("%d",&t);
            while(!(t==1||t==2||t==3))
            {
                printf("\n\t输入有误，请重新输入\n\t[ ]\b\b");
                scanf("%d",&t);
            }
            if(t==1)
            {
                price1=30;
                price2=40;
                printf("\t您想要查询的价格范围为: 30~40\n");
            }
            else if(t==2)
            {
                price1=40;
                price2=50;
                printf("\t您想要查询的价格范围为: 40~50\n");
            }
            else
            {
                price1=50;
                price2=1000000;
                printf("\t您想要查询的价格范围为: >50\n");
            }

            printf("\n\t系统查询结果：\n");

            if((in=fopen("movie.txt","r"))==NULL)//打开文档
            {
                printf("cannot open file\n");
                exit(0);
            }
            l1=0;
            while(!feof(in))
            {
                fscanf(in,"%s %d %d %d %d %d %s %s %f\n",a,&b,&c,&d,&e,&f,h,q,&i);
                if(price1<i&&i<=price2)
                {
                    printf("(%d)\n",l1);
                    printf("\t电影名称:《%s》",a);
                    printf("\n");
                    printf("\t电影上映时间:%d年%d月%d日%d时%d分",b,c,d,e,f);
                    printf("\n");
                    printf("\t电影上映类型:%s、%s",h,q);
                    printf("\n");
                    printf("\t电影票价:%.2f",i);
                    printf("\n\n");
                    l1++;
                }
            }
            fclose(in);//关闭

            total=l1-1;
            if(total!=0)
            {
                printf("\t共为您找到%d条符合条件的信息\n\n",total);
                printf("\t如需重新查询，请输入1\t如退出，请输入2\t\n\t[ ]\b\b");
                i=0;
                scanf("%d",&qw);
                while(!(qw==1||qw==2))
                {
                    printf("\n\t输入有误，请重新输入\n\t\n\t[ ]\b\b");
                    scanf("%d",&qw);
                }
            }
            else
            {
                printf("\n\t没有找到符合条件的信息\n");
                printf("\n\n\tPress any key to continue......");
                getch();
                puts("\n\n");
                printf("\t如需重新查询，请输入1\t如退出，请输入2\t\n\t[ ]\b\b");
                i=0;
                scanf("%d",&qw);
                while(!(qw==1||qw==2))
                {
                    printf("\n\t输入有误，请重新输入\n\t\n\t[ ]\b\b");
                    scanf("%d",&qw);
                }
            }
        }
        while(qw==1);
    }
    printf("\n\n\t按下任意键以返回上一界面......");
    getch();
    puts("\n\n");
}
