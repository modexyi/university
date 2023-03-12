
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#define LEN sizeof(struct Movie)
#define Hang 5
#define Lie 10

void menu();			//�û�ϵͳ������
void login();			//��ӰԺ����Ա��¼����
void admin();			//��ӰԺ����Ա���� 
void modify();			//��Ϣ�޸ĺ���
void save();			//��Ӱ��Ϣ¼��
void del();				//��Ϣɾ������
void gaimi();			//��ӰԺ����Ա�����޸�
void users_interface();	//�û��������
void registers();		//�û�ע���˺�
void Create_File();		//�����˺��ļ�
void Input_login();		//�û���¼�˺�
void user();			//��Ʊ�û�
void book();			//Ԥ��
void save_out();		//��ʾ��Ӱ��Ϣģ��
int load(char * a);		//���������ָ�����ļ��еļ�¼�ĸ����ĺ���
void transform_text();	//�ļ�����ת����������->�ı���
void transform_2();		//�ļ�����ת�����ı�->�����ƣ�
void sort();			//����������
void search();			//��ѯ����

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

struct custom	//����û��˻�����Ľṹ��
{
    char name[20],zh[20],code[10];
    struct custom*next;
} custom[3];

struct user		//��Ź���Ա�Ľṹ��
{
    char pwd[20];
} us;
char username[15]="guanliyuan",pwd1[50];    //username[15]ԭʼ����Ա�˺ţ�pwd1�޸�����ʱ�ıȽ�


int main()
{
    menu();
}


void menu()		//��¼ϵͳ������
{

    while(1)	//ʹ�������ʼ��������������رճ���
    {
        system("cls");
        printf("\n\n\n");
        printf("\t\t******************************************************\n");
        printf("\t\t***              ��ӰԺԤ������Ʊϵͳ              ***\n");
        printf("\t\t******************************************************\n");
        printf("\t\t***                                                ***\n");
        printf("\t\t***                                                ***\n");
        printf("\t\t***               ��ѡ���û�����:                  ***\n");
        printf("\t\t***                A.��Ʊ�û�                      ***\n");
        printf("\t\t***                B.��ӰԺ����Ա                  ***\n");
        printf("\t\t***                                                ***\n");
        printf("\t\t***                                                ***\n");
        printf("\t\t******************************************************\n");
        printf("\t\t******************************************************");
        printf("\n");
        printf("\t\t����ѡ����:[ ]\b\b");
        char first_select = 0;
        scanf("%c",&first_select);
        if(first_select=='A')
			users_interface();
        if(first_select=='B')
			login();
        system("cls");
    }
}


void login()     //����Ա��¼����
{
    system("cls");
    int i=0,k=0,j;
    FILE *fe;
    if((fe=fopen("name.txt","r"))==NULL)
    {
        strcpy(us.pwd,"123456");
    }//����ļ��򿪴����ʼ����
    fscanf(fe,"%s",us.pwd);
    char username1[15];   //������ԭʼ������Ƚϵı���
    printf("\n\n");
    //ϵͳĬ�Ϲ���Ա����guanliyuan,���룺123456
    printf("\t\t��������  ��ӭʹ�õ�¼ϵͳ  ��������\n\n");
    for(i=0; i<3; i++)
    {
        printf("\t\t���������Ա����:");
        scanf("%s",username1);
        printf("\t\t������6λ����:");
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
            printf("\n\n\t\t���Ѿ��ɹ���¼��\n\t\t");
            k=1;
            for(i=0; i<6; i++)
            {
                printf(".");
                Sleep(200);
            }
            system("cls");
            admin();            //��ת������Ա������
            break;
        }
        else
            printf("\n\n\t\t�û�����������Ч������������:\n\n");
        continue;
    }
    if(k==0)
        printf("\n\t\t�����������3�ν��˳�����\n");
    Sleep(1000);            //������ͣ��������λ���룩��������ͣ2000����
    return;//�������δ�����ת�˳�����
}


void admin()	//����Ա����
{
    int n, w1; 	// n ��¼ѡ��Ĳ˵�ѡ� w1 ��¼ѡ���Ƿ����Ҫ�� 
    while(1)	//ѭ��ʹ���˳�������ѡ�����
    {
        system("cls");
        //��ӰԺ������Ա�������
        system("cls");
        do
        {
            system("cls");//����
            puts("\t\t\t     ��ӭ�����ӰԺ����Ա���棡 ");
            puts("\t\t*********************�˵�*********************\n\n");
            puts("\t\t\t\t1.��ʾ��Ӱ��Ϣ");
            puts("\t\t\t\t2.��Ӱ��Ϣ����");
            puts("\t\t\t\t3.��Ӱ��Ϣ��ѯ");
            puts("\t\t\t\t4.�޸ĵ�Ӱ��Ϣ");
            puts("\t\t\t\t5.ɾ����Ӱ��Ϣ");
            puts("\t\t\t\t6.�˺��޸�����");
            puts("\t\t\t\t7.������������");
            puts("\n\n\t\t**********************************************\n");
            printf("��ѡ������(1~7): [ ]\b\b");
            scanf("%d",&n);
            getchar();
            if(n<1||n>9) /*��ѡ����������ж�*/
            {
                w1=1;
                getchar();
            }
            else w1=0;
        }
        while(w1==1);
        switch(n) 	//�˵�ѡ����
        {
        case 1:
        	save_out();
            break; 	//��Ϣ��ʾģ��
        case 2:
			sort();		
            break; 	//��Ϣ����ģ��
        case 3:
            search();
            break; 	//��Ϣ��ѯģ��
        case 4:
            modify();
            break; 	//��Ϣ�޸�ģ��
        case 5:
            del();
            break;	//��Ϣɾ��ģ��
        case 6:
        	gaimi();//�޸�����
            break;
        case 7:
            menu();	//���ز˵� 
        case 8:
		    save(); // 
        }
    }
}


void modify() //��Ϣ�޸ĺ��� 
{
    struct Node     /*������Ӱ���������ڲ�ѯ*/
    {
        char name[100];
        struct Node * next;
    };
    int amount; /* ��Ϣ�ļ��еļ�¼���� */
    int con=0; /* �Ѵ�����ļ���¼���� */
    struct Node * head=NULL, * pf=NULL, * pb=NULL;
    struct Movie movie;
    FILE * fp;
    int total=0;
    long offset=1; /* �ļ�λ��ָ��ƫ���� */
    int flag=0; /* ָʾ�Ƿ���������޸ģ�Ϊ 1 ʱ���� */
    char ID[100]; /* ���޸ĵļ�¼�ĵ�Ӱ���� */
    int ord; /* ���޸ĵ���Ŀָʾ */
    int repeat; /* ���޸��������ظ������� */
    int Yes=0; /* ָʾ�Ƿ񱣴��޸� */
    if((fp=fopen("movie.txt","r")) == NULL)       /*���ļ�*/
    {
        printf("\tCan not open the inform file!");
        getch();
        exit(1);
    }
    transform_2 ();       /*ת���ɶ������ļ�*/
    fclose(fp);
    amount=load("movie0.txt");      /*��ȡ�ļ������е�Ӱ��Ϣ����*/
    fp=fopen("movie0.txt","rb");       /*���ļ�*/
    for(con=0; con<amount; con++)
    {
        if(fread(&movie, sizeof(movie), 1, fp) != 1)      /*��ȡ��Ӱ��*/
        {
            printf("\nfile read wrong!\n");
            getch();
            exit(1);
        }
        pb=(struct Node *)malloc(sizeof(struct Node)); /* ����������Ӱ����Ϣ���������ں����Ĳ��� */
        /*malloc���������ڴ棬������ʼ��ַ*/
        strcpy(pb->name,movie.name);
        if(total==0) head=pf=pb;
        else pf->next=pb;
        pb->next=NULL;
        pf=pb;
        total++;

        printf("\n ��Ӱ����:��%s��\n",movie.name);     /*����Ѵ��ڵ�Ӱ��Ϣ*/
        printf(" ��Ӱ��ӳʱ��:%d��%d��%d��%d:%d\n",movie.date.year,movie.date.mon,movie.date.day,movie.time.hour,movie.time.min);
        printf(" ��Ӱ����:%s��%s\n",movie.type,movie.type2);
        printf(" ��ӰƱ��:%.2f\n\n",movie.price);

        if((total != 0) && (total%10 ==0))
        {
            printf("\n\n���������������\nPress any key to continue......");
            getch();
            puts("\n\n");
        }
    }
    fclose(fp);
    do
    {
        printf("\n��������Ҫ�޸ĵĵ�Ӱ����:");      /*������Ҫ�޸ĵĵ�Ӱ��*/
        gets(ID);
        pf=head;
        offset=0;
        while(strcmp(strlwr(pf->name),strlwr(ID)) && pf->next!=NULL)    /*���ҵ�Ӱ��Ϣλ��*/
        {
            pf=pf->next;
            offset++;
        }
        if(!strcmp(strlwr(pf->name),strlwr(ID))) /* ���޸ĵļ�¼���� */
        {
            if((fp=fopen("movie0.txt","rb+"))==NULL)        /* ���ļ�ʧ�� */
            {
                printf("\n\nfile open wrong!");
                getch();
                exit(1);
            }
            offset *= sizeof(struct Movie);     /* ʹ�ļ�λ��ָ���ƶ������޸ļ�¼�� */
            rewind(fp);      /*�ļ�λ�ñ���ط���ͷ*/
            if(fseek(fp, offset, 0) != 0)
            {
                printf("\n\nfile operation wrong !");
                getch();
                exit(1);
            }
            fread(&movie, sizeof(movie), 1, fp);      /* ��ȡ���޸ļ�¼ */
            fseek(fp,(-1)*(long)sizeof(struct Movie), 1); /* ʹ�ļ�λ��ָ�뷵�ص����޸ļ�¼�� */
            printf("\nthe record you want to modify is:\n");    /* ������޸ļ�¼ */

            printf(" ��Ӱ����:��%s��\n",movie.name);      /* ������޸ļ�¼ */
            printf(" ��Ӱ��ӳʱ��:%d��%d��%d��%d:%d\n",movie.date.year,movie.date.mon,movie.date.day,movie.time.hour,movie.time.min);
            printf(" ��Ӱ����:%s��%s\n",movie.type,movie.type2);
            printf(" ��ӰƱ��:%.2f\n\n",movie.price);

            do
            {
                /* ѡ����Ҫ�޸ĵĲ��� */
                printf("\n\n������޸���������:1).����\t2).ʱ��\t3).��ӳ����\t4).Ʊ��\t5).����");
                printf("\n��ѡ������Ҫ�޸ĵ���Ŀ: [ ]\b\b");
                scanf("%d", &ord);
                getchar();
            }
            while(ord>7 || ord<1);
            switch(ord)
            {
            case 1:
                printf("\t���õ�Ӱ�����޸�Ϊ:");
                do
                {
                    repeat=0;
                    gets(ID);
                    pb=head;
                    while(strcmp(strlwr(pf->name),strlwr(ID)) && pb->next !=NULL)      //�ж������Ƿ��Ѵ���
                        pb=pb->next;
                    if(!strcmp(strlwr(pf->name),strlwr(ID)))
                    {
                        printf("\n�������Ѵ��ڣ�����������...\n\t����:");
                        repeat=1;
                    }
                }
                while(repeat);         //�����������������
                strcpy(movie.name, ID);
                break;
            case 2:
                printf(" ���õ�Ӱ��ӳ����޸�Ϊ(��ʽ�磺2020��2021):");
                scanf("%d",&movie.date.year);
                while((movie.date.year!=2020&&movie.date.year!=2021))
                {
                    printf("\n");
                    printf("***************************\n");
                    printf("**                       **\n");
                    printf("** �����������������룡**\n");
                    printf("**                       **\n");
                    printf("***************************\n");
                    printf(" �������Ӱ��ӳ���(��ΧΪ2020-2021):");
                    scanf("%d",&movie.date.year);
                }
                printf("\n");
                printf(" ���õ�Ӱ��ӳ�·��޸�Ϊ(��ʽ�磺1~12):");
                scanf("%d",&movie.date.mon);
                while((movie.date.mon<1||movie.date.mon>12))
                {
                    printf("\n");
                    printf("***************************\n");
                    printf("**                       **\n");
                    printf("** �����������������룡**\n");
                    printf("**                       **\n");
                    printf("***************************\n");
                    printf(" �������Ӱ��ӳ�·�(��ΧΪ1~12):");
                    scanf("%d",&movie.date.mon);
                }
                printf("\n");
                printf(" ���õ�Ӱ��ӳ�����޸�Ϊ(��ʽ�磺1~30):");
                scanf("%d",&movie.date.day);
                while((movie.date.day<1||movie.date.day>31))
                {
                    printf("\n");
                    printf("***************************\n");
                    printf("**                       **\n");
                    printf("** �����������������룡**\n");
                    printf("**                       **\n");
                    printf("***************************\n");
                    printf(" �������Ӱ��ӳ����:");
                    scanf("%d",&movie.date.day);
                }
                printf("\n");
                printf(" �������Ӱ��ӳʱ��(ʱ)(��ʽ�磺0~23):");
                scanf("%d",&movie.time.hour);
                while((movie.time.hour<0||movie.time.hour>23))
                {
                    printf("\n");
                    printf("***************************\n");
                    printf("**                       **\n");
                    printf("** �����������������룡**\n");
                    printf("**                       **\n");
                    printf("***************************\n");
                    printf(" �������Ӱ��ӳʱ��(ʱ)(��ΧΪ0~24):");
                    scanf("%d",&movie.time.hour);
                }
                printf("\n");
                printf(" �������Ӱ��ӳʱ��(��)(��ʽ�磺0~59):");
                scanf("%d",&movie.time.min);
                while((movie.time.min<0||movie.time.min>59))
                {
                    printf("\n");
                    printf("***************************\n");
                    printf("**                       **\n");
                    printf("** �����������������룡**\n");
                    printf("**                       **\n");
                    printf("***************************\n");
                    printf(" �������Ӱ��ӳʱ��(��)����ΧΪ0~59��:");
                    scanf("%d",&movie.time.min);
                }
                getchar();
                break;

            case 3:
                printf("\t��ӳ����:");
                scanf("%s%s",movie.type,movie.type2);
                getchar();
                break;

            case 4:
                printf("\tƱ��:");
                scanf("%f",&movie.price);
                while((movie.price<0||movie.price>1000))
                {
                    printf("\n");
                    printf("***************************\n");
                    printf("**                       **\n");
                    printf("** �����������������룡**\n");
                    printf("**                       **\n");
                    printf("***************************\n");
                    printf(" �������ӰƱ��:");
                    scanf("%f",&movie.price);
                }
                getchar();
                break;

            case 5:
            default:
                printf("\n\n");
                //menu();
            }
            printf("\n�Ƿ�ȷ���޸�?\n\n\t1).ȷ�� 2).ȡ�������� [ ]\b\b");    /*�Ƿ�ȷ��*/
            scanf("%d",&Yes);
            getchar();
            if(Yes==1)       /* �����ĺ������д�ص��ļ���ȥ */
                if((fwrite(&movie, sizeof(struct Movie), 1, fp))==1) printf("\n�޸ĳɹ� ^_^");
                else printf("\n�޸�δ�ɹ� ! ");
            else
            {
                printf("\n%d\n",Yes);
                getch();
            }
            fclose(fp);
        }
        else
        {
            printf("\n\n������ļ�¼δ�ҵ�!\tany key to continue...");
            getch();
        }
        printf("\n\n�Ƿ�����޸�?:\t\t1).��\t2).�� [ ]\b\b");/* �Ƿ�����޸�������¼ */
        scanf("%d",&flag);
        getchar();
    }
    while(flag == 1);
    transform_text ();
    free(pb);
    printf("\n\n\t����������Է��ع���Ա����......");
    getch();
    puts("\n\n");
    //menu();
}


void save()//����Ա����Ӱ��Ϣ¼��
{
    struct Movie*head;
    struct Movie*p1,*p2;
    int n,a,b;
    p1=p2=(struct Movie*) malloc(LEN);
    //malloc�������ڴ溯��,����len���ֽڵ��ڴ�,���ѷ��ص����뵽���ڴ��׵�ַ����ָ��
    system("cls");
    printf("\n\n");
    head=NULL;
    FILE*fp;
    if((fp=fopen("movie.txt","a"))==NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }
    //����ʾ�����Ӱ�����Ϣ
    printf(" �������Ӱ����:");
    scanf("%s",p1->name);
    printf("\n");
    while(1)
    {
        printf(" �������Ӱ��ӳʱ��(��)(��:2020��2021):");
        if(! scanf("%d",&p1->date.year))       fflush(stdin);//������뻺����
        else if(p1->date.year==2020||p1->date.year==2021)  break;
        printf("\n");
    		printf("\t***************************\n");
            printf("\t**                       **\n");
            printf("\t** �����������������룡**\n");
            printf("\t**                       **\n");
            printf("\t***************************\n");
        printf("\n");
    }
    printf("\n");
    while(1)
    {
        printf(" �������Ӱ��ӳʱ��(��)(��ΧΪ��1~12):");
        if(!scanf("%d",&p1->date.mon))           fflush(stdin);//������뻺����
        else if(!(p1->date.mon<1||p1->date.mon>12))    break;
        printf("\n");
        	printf("\t***************************\n");
            printf("\t**                       **\n");
            printf("\t** �����������������룡**\n");
            printf("\t**                       **\n");
            printf("\t***************************\n");
        printf("\n");
    }
    printf("\n");
    while(1)
    {
        printf(" �������Ӱ��ӳʱ��(��)(��ΧΪ��1~31):");
        if(!scanf("%d",&p1->date.day))            fflush(stdin);//������뻺����
        else if(!(p1->date.day<1||p1->date.day>31))     break;
        printf("\n");
        	printf("\t***************************\n");
            printf("\t**                       **\n");
            printf("\t** �����������������룡**\n");
            printf("\t**                       **\n");
            printf("\t***************************\n");
        printf("\n");
    }
    printf("\n");
    while(1)
    {
        printf(" �������Ӱ��ӳʱ��(ʱ)(��ΧΪ0~23):");
        if(!scanf("%d",&p1->time.hour))           fflush(stdin);//������뻺����
        else if(!(p1->time.hour<0||p1->time.hour>23))      break;
        printf("\n");
        	printf("\t***************************\n");
            printf("\t**                       **\n");
            printf("\t** �����������������룡**\n");
            printf("\t**                       **\n");
            printf("\t***************************\n");
        printf("\n");
    }
    printf("\n");
    while(1)
    {
        printf(" �������Ӱ��ӳʱ��(��)����ΧΪ0~59��:");
        if(!scanf("%d",&p1->time.min))             fflush(stdin);//������뻺����
        else if(!(p1->time.min<0||p1->time.min>59))        break;
		    printf("\n");
		printf("\t***************************\n");
        printf("\t**                       **\n");
        printf("\t** �����������������룡**\n");
        printf("\t**                       **\n");
        printf("\t***************************\n");
        printf("\n");
    }
    printf("\n");
    printf(" �������Ӱ����(�������磺ϲ�� ����):");
    scanf("%s %s",p1->type,p1->type2);
    printf("\n");
    printf(" �������ӰƱ��:") ;
    while(1)
    {
        if(!scanf("%f",&p1->price))                fflush(stdin);//������뻺����
        else if(!(p1->price<0||p1->price>1000))            break;
        printf("\n");
        printf("\t***************************\n");
        printf("\t**                       **\n");
        printf("\t** �����������������룡**\n");
        printf("\t**                       **\n");
        printf("\t***************************\n");
        printf(" �������ӰƱ��:");
        printf("\n");
    }
    getchar();//����
    printf("\n\n");
    char select;
    for(a=0,n=0; a==0;) //ѭ�������������������
    {
        n=n+1;//ָ��Ľ���ʵ�ֶ�̬����
        if(n==1)head=p1;
        else p2->next=p1;
        p2=p1;
        fprintf(fp,"%s %d %d %d %d %d %s %s %s %f\n",p2->name,p2->date.year,
                p2->date.mon,p2->date.day,p2->time.hour,p2->time.min,p2->type,p2->type2,p2->price);
        //д����������
        for(b=0; b==0;)
        {
        	printf(" ��Ӱ¼��ɹ� ^_^\n\n");
            printf(" �Ƿ��˳��ļ��༭(y or n)\n\n");
            printf(" ����������:[ ]\b\b");
            scanf("%c",&select);
            if(select=='y') break;
            if(select=='n') break;
            else
            {
                system("cls");
                printf("\n\n");
                printf("\t***********************\n");
                printf("\t**                   **\n");
                printf("\t** ��������ȷѡ��!!! **\n");
                printf("\t**                   **\n");
                printf("\t***********************\n\n\n");
            }
        }
        if(select=='y') break;
        if(select=='n') system("cls");
        printf("\n\n");
        printf(" �������Ӱ����:");
        scanf("%s",p1->name);
        printf("\n");
        while(1)
        {
            printf(" �������Ӱ��ӳʱ��(��)(��:20��21):");
            if(! scanf("%d",&p1->date.year))       fflush(stdin);//������뻺����
            else if(p1->date.year==20||p1->date.year==21)  break;
            printf("\n");
            printf("\t***************************\n");
            printf("\t**                       **\n");
            printf("\t** �����������������룡**\n");
            printf("\t**                       **\n");
            printf("\t***************************\n");
            printf("\n");
        }
        printf("\n");
        while(1)
        {
            printf(" �������Ӱ��ӳʱ��(��)(��ΧΪ��1~12):");
            if(!scanf("%d",&p1->date.mon))           fflush(stdin);//������뻺����
            else if(!(p1->date.mon<1||p1->date.mon>12))    break;
            printf("\t***************************\n");
            printf("\t**                       **\n");
            printf("\t** �����������������룡**\n");
            printf("\t**                       **\n");
            printf("\t***************************\n");
            printf("\n");
        }
        printf("\n");
        while(1)
        {
            printf(" �������Ӱ��ӳʱ��(��)(��ΧΪ��1~31):");
            if(!scanf("%d",&p1->date.day))            fflush(stdin);//������뻺����
            else if(!(p1->date.day<1||p1->date.day>31))     break;
            printf("\n");
            printf("\t***************************\n");
            printf("\t**                       **\n");
            printf("\t** �����������������룡**\n");
            printf("\t**                       **\n");
            printf("\t***************************\n");
            printf("\n");
        }
        printf("\n");
        while(1)
        {
            printf(" �������Ӱ��ӳʱ��(ʱ)(��ΧΪ0~23):");
            if(!scanf("%d",&p1->time.hour))           fflush(stdin);//������뻺����
            else if(!(p1->time.hour<0||p1->time.hour>23))      break;
            printf("\n");
            printf("\t***************************\n");
            printf("\t**                       **\n");
            printf("\t** �����������������룡**\n");
            printf("\t**                       **\n");
            printf("\t***************************\n");
            printf("\n");
        }
        printf("\n");
        while(1)
        {
            printf(" �������Ӱ��ӳʱ��(��)����ΧΪ0~59��:");
            if(!scanf("%d",&p1->time.min))             fflush(stdin);//������뻺����
            else if(!(p1->time.min<0||p1->time.min>59))        break;
            printf("\n");
            printf("\t***************************\n");
            printf("\t**                       **\n");
            printf("\t** �����������������룡**\n");
            printf("\t**                       **\n");
            printf("\t***************************\n");
            printf("\n");
        }
        printf("\n");
        printf(" �������Ӱ����(��:ϲ��/����):");
        scanf("%s",p1->type);
        printf(" �������Ӱ����(��:ϲ��/����):");
        scanf("%s",p1->type2);
        printf("\n");
        printf(" �������ӰƱ��:") ;
        while(1)
        {
            if(!scanf("%f",&p1->price))                fflush(stdin);//������뻺����
            else if(!(p1->price<0||p1->price>1000))    break;
            printf("\n");
            printf("\t***************************\n");
            printf("\t**                       **\n");
            printf("\t** �����������������룡**\n");
            printf("\t**                       **\n");
            printf("\t***************************\n");
            printf(" �������ӰƱ��:");
            printf("\n");
        }
        printf("\n\n");
        getchar();//����
    }
    p2->next=NULL;
    fclose(fp);

}
//�ö�̬�����������ݣ��������ݴ洢�ڽ�����movie.txt�ļ���


void del()      // ����Ա����Ϣɾ������
{
    struct Node
    {
        char name[100];
        struct Node * next;
    };
    int amount;      // ��Ϣ�ļ��еļ�¼����
    int con=0;      // �Ѵ�����ļ���¼����
    struct Node * head=NULL, * pf=NULL, * pb=NULL;
    struct Movie movie;
    FILE * fp, *fp1;      // fp ����ָʾ��Ϣ�ļ� inform���� fp1 ����ָʾ��ʱ�ļ�
    int total=0;
    int offset=0;      // �ļ�λ��ָ��ƫ����
    int flag=0;      // ָʾ�Ƿ���������޸ģ�Ϊ 1 ʱ����
    char ID[100];     // ���޸ĵļ�¼��ְ����
    int Yes=0;      // ָʾ�Ƿ񱣴��޸�
    if((fp=fopen("movie.txt","r")) == NULL)       /*���ļ�*/
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
        pb=(struct Node *)malloc(sizeof(struct Node));   // �������� num ��Ϣ���������ں����Ĳ���
        strcpy(pb->name, movie.name);
        if(total==0) head=pf=pb;
        else pf->next=pb;
        pb->next=NULL;
        pf=pb;
        total++;

        printf(" ��Ӱ����:��%s��\n",movie.name);
        printf(" ��Ӱ��ӳʱ��:%d��%d��%d��%d:%d\n",movie.date.year,movie.date.mon,movie.date.day,movie.time.hour,movie.time.min);
        printf(" ��Ӱ����:%s��%s\n",movie.type,movie.type2);
        printf(" ��ӰƱ��:%.2f\n\n",movie.price);

        if((total != 0) && (total%10 ==0))
        {
            printf("\n\n�����������������\nPress any key to continue......");
            getch();
            puts("\n\n");
        }
    }
    fclose(fp);
    do
    {
        printf("��������Ҫɾ���ĵ�Ӱ��:");
        gets(ID);
        pf=head;
        while(strcmp(strlwr(pf->name),strlwr(ID)) && pf->next!=NULL)
        {
            pf=pf->next;
            offset++;
        }
        if(!strcmp(strlwr(pf->name),strlwr(ID)))     // ��ɾ���ļ�¼����
        {
            printf("\n�Ƿ�ȷ��ɾ��?:\t\t1).ȷ��\t2).ȡ�� [ ]\b\b");
            scanf("%d",&Yes);
            if(Yes==1)     // ���ȷ��Ҫɾ���ü�¼
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
                remove("movie0.txt");         // ɾ�����ļ�
                rename("movie_temp.txt","movie0.txt");      // ��ʱ�ļ��滻ԭ�ļ�
            }
        }
        else    // ��ɾ���ļ�¼������
        {
            printf("\n\n������ļ�¼δ�ҵ�!\tany key to continue...");
            getch();
        }
        printf("\nɾ���ɹ���^_^\n");
        printf("\n\n�Ƿ����?:\t\t1).Yes\t2).No [ ]\b\b");
        scanf("%d",&flag);
        getchar();
    }
    while(flag == 1);
    transform_text ();
    printf("\n\n\t����������Է��ع���Ա����......");
    getch();
    puts("\n\n");
    //menu();
}


void gaimi()     //�޸Ĺ���Ա�������
{
    system("cls");
    char c;
    int j;
    FILE *fe;
    if((fe=fopen("name.txt","w"))==NULL)
    {
        printf("�ļ��򿪴���");
        exit(0);
    }
    printf("\n����������ԭʼ����:\n");
    fflush(stdin);         //�������
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
        printf("\n��������Ҫ�޸ĵ�����\n");
        for(j=0; j<100; j++)
        {
            us.pwd[j]=getch();
            if(us.pwd[j]=='\r')
                break;
            printf("*");
        }
        us.pwd[j]='\0';
        fflush(stdin);         //�������
        printf("\n���ٴ�ȷ���������\n");
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
            printf("\n\n�����޸ĳɹ��������µ�¼��\n");
            Sleep(1000);
            system("cls");
            login();
        }
        else
        {
            printf("\n\n�������벻���ϣ����η��񵽴˽�����\n\n");
            printf("\n\n�����������\n");
            c=getch();
            system("cls");
            admin();
        }
    }
    else
    {
        printf("\n�����������\n\n");
        printf("\n\n�����������\n");
        c=getch();
        system("cls");
        admin();
    }
}


void users_interface()	//�û���¼����
{
    while(1)//ʹ�������ʼ��������������رճ���
    {
        system("cls");
        printf("\n\n\n");
        printf("\t\t******************************************************\n");
        printf("\t\t***               ��Ʊ�û���¼����                 ***\n");
        printf("\t\t******************************************************\n");
        printf("\t\t***                                                ***\n");
        printf("\t\t***                                                ***\n");
        printf("\t\t***           ��ѡ��:                              ***\n");
        printf("\t\t***                 1.ע��                         ***\n");
        printf("\t\t***                 2.��¼                         ***\n");
        printf("\t\t***                                                ***\n");
        printf("\t\t***                                                ***\n");
        printf("\t\t******************************************************\n");
        printf("\t\t******************************************************");
        printf("\n\n");
        printf("\t\t����ѡ����:[ ]\b\b");
        char select;
        scanf("%c",&select);
        if(select=='1')registers();
        if(select=='2')Input_login();
        system("cls");
    }
}

/*ע���˺�*/
void registers()  //���ṹ��Ĵ�С��һ��д����߶���1���ṹ���С
{
    system("cls");
    printf("\t\t��������  ��ӭʹ��ע��ϵͳ  ��������\n");
    int i,j;
    int z=0;
    char name[20];
    char zh[20];
a:
    printf("\t\t����������:");
    scanf("%s",name);
    printf("\t\t�������˺ţ�");
    scanf("%s",zh);
    for (i=0; i<=z; i++)
    {
        if(strcmp(name,custom[i].name)==0||strcmp(zh,custom[i].zh)==0)
        {
            printf("\t\t�û������˺��Ѵ��ڣ�\n");
            printf("\t\t���������룺\n\n");
            goto a;
        }
    }
    strcpy(custom[z].name,name);
    strcpy(custom[z].zh,zh);


b:
    printf("\t\t����������(6λ����):");
    scanf("%s",custom[z].code);
    if(strlen(custom[z].code)!=6)
    {
        printf("\t\t�����ʽ�����������������\n");
        goto b;
    }
    z++;
    printf("\t\tע��ɹ���\n\t\t���ڷ���");
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


/*���������û��˺�������ļ�*/
void Create_File()
{
    int z;
    FILE *fq;
    int j=0;
    if((fq=fopen("file","r"))==NULL)
    {
        printf("�û���Ϣ�ļ������ڣ�\n");
        printf("�����ע�ᣡ\n");
        registers();
    }
    while(fscanf(fq,"%s%s%s",custom[j].name,custom[j].zh,custom[j].code)==3)
    {
        j++;
    }
    if(j==0)
    {
        printf("�û���ϢΪ�գ������ע�ᣬ�����ܽ���ϵͳ\n");
        registers();
    }
    z=j;
    fclose(fq);
}


/*�û���¼ϵͳ*/
void Input_login()
{
    system("cls");
    Create_File();
    printf("\t\t��������  ��ӭʹ�õ�¼ϵͳ  ��������\n");
    char zh[20],name[20],code[7];
    int a=0,i,k,f=0,u=0;
    printf("\t\t�������˺�:");
a:
    if(f==3)
    {
        printf("����3����Ч�˺��˳���¼��");
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
        printf("\t\t���˺Ų����ڣ�\n\n");
        printf("\t\t�����������˺ţ�");
        f=f+1;
        goto a;
    }
    printf("\t\t����������:");
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
        printf("\t\t�����������������:");
        u++;
        if(u==3)
        {
            printf("����3����Ч�����˳���¼��");
            Sleep(1000);
            menu();
        }
        goto b;
    }
    printf("\n\t\t��½��");
    for(i=0; i<6; i++)
    {
        printf(".");
        Sleep(200);
    }
    user();
}


void user()//�û�����
{
    int n,w1;
    system("cls");
    while(1)//ѭ��ʹ���˳�������ѡ�����
    {
        do
        {
            system("cls");
            puts("\t\t\t        ��ӭ�����û����棡 ");
            puts("\t\t*********************�˵�*********************\n\n");
            puts("\t\t\t\t1.��ʾ��Ӱ��Ϣ");
            puts("\t\t\t\t2.��Ӱ��Ϣ����");
            puts("\t\t\t\t3.��Ӱ��Ϣ��ѯ");
            puts("\t\t\t\t4.��Ʊ/��Ʊ");
            puts("\t\t\t\t5.�˳���������");
            puts("\n\n\t\t**********************************************\n");
            printf("��ѡ������(1-5): [ ]\b\b");
            scanf("%d",&n);
            getchar();
            if(n<1||n>5) //��ѡ����������ж�
            {
                w1=1;
                getchar();
            }
            else w1=0;
        }
        while(w1==1);
        switch(n) //�˵�ѡ����
        {
        case 1:
            save_out();
            break; //��Ϣ��ʾģ��
        case 2:
            sort();
            break; //��Ϣ����ģ��
        case 3:
            search();
            break;//��Ϣ��ѯģ��
        case 4:
            book();
            break;//ѡƱ��Ʊ
        case 5:
            menu();
            break;
            //case 4:book();break;
            //default: ;/*�˳�*/
        }
    }
}


void book()	//�û�:��Ӱ��Ʊ����Ʊ
{
	system("cls");
	char a[100];
    int b,c,d,e,f;
    char g[100];
    char h[100];
    char q[100];
    float i;
    int v=1;
    int aw[Hang][Lie];//�ɸı���λ������
    //��λ����
    int num;
    int m,j;
    for(m=0; m<Hang; m++)
        for(j=0; j<Lie; j++)
            aw[m][j]=0;
    
    //intseat��ʼ����λ
    FILE *in;
        if((in=fopen("movie.txt","r"))==NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }
     while(!feof(in))//�ж��Ƿ����ļ�β
    {
    	printf("(%d)",v);
		fscanf(in,"%s %d %d %d %d %d %s %s %f\n",a,&b,&c,&d,&e,&f,h,q,&i);
        printf("\t��Ӱ����:��%s��",a);
        printf("\n");
    	printf("\t��Ӱ��ӳʱ��:%d��%d��%d��%d:%d",b,c,d,e,f);
        printf("\n\n");
        v++;
    }
    int k,l,count;

    /*printf("\n�������Ӱ����(29-31)��");
    printf("\t����ѡ����:[ ]\b\b");
    scanf("%d",&l);*/
    printf("\n����������ۿ���Ӱ�����(1-10):");
    printf("\t����ѡ����:[  ]\b\b\b");
    scanf("%d",&k);
    int choice=1;
    fclose(in);
    while(choice)
    {
        int z;
        printf("��������or����(1/0):[ ]\b\b");
        scanf("%d",&z);
        switch(z)
        {
        case 1:
        {
        	system("cls");
            puts("\t\t\t     ��ӭ�����ӰƱ������ ");
            puts("\t\t*********************�˵�*********************\n\n");
            puts("\t\t\t\t1.��ѯ��λ��Ϣ");
            puts("\t\t\t\t2.�����ӰƱ");
            puts("\t\t\t\t3.�ۺ���Ʊ");
            puts("\t\t\t\t4.����");
            puts("\n\n\t\t**********************************************\n");
            printf("��ѡ���������(1-3): [ ]\b\b");
            scanf("%d",&num);
            break;
        }
        case 0:
        {
            printf("****�˳��ɹ�!!��ӭ�´ι���****\n");
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
            printf("��ѯ��λ��Ϣ:\n");
            count=0;
            printf("\t\t\t\t��ӰԺ��λ��\n\t\t");
            for(m=0; m<Hang; m++)
                for(j=0; j<Lie; j++)
                {
                    if(aw[m][j]==1)
                        printf(" �~ ");
                    else
                        printf(" �� ");
                    count++;
                    if(count%10==0)
                        printf("\n\t\t");//�����λ
                }
            break;
        }
        case 2://ѡ��
        {
            int x,y;
            int choice;
            srand(time(0));//��ȡ�����ʱ��(�Ӷ�ʵ��ȡ�����)
            printf("\n��ѡ���ֶ�ѡ����ϵͳ�����1 or 0����\n 1.�ֶ�ѡ��\t 0.ϵͳ���\t[ ]\b\b");
            scanf("%d",&choice);//��ֵ��choiceѡ���ֶ������
            while((choice!=0)&&(choice!=1))
            {
                printf("\n�������������ѡ��1 or 0����\n 1.�ֶ�ѡ��\t 0.ϵͳ���\n");
                scanf("%d",&choice);
            }
            if(choice)
            {
                count=0;
                printf("\t\t\t\t��ӰԺ��λ��\n\t\t");
                for(m=0;m<Hang; m++)
                    for(j=0; j<Lie; j++)
                    {
                        if(aw[m][j]==1)
                            printf(" �~ ");
                        else
                            printf(" �� ");
                        count++;
                        if(count%10==0)
                            printf("\n\t\t");//�����λ
                    }
                printf("\n��ѡ����Ҫ��λ��\t��:");
                scanf("%d",&m);
                printf("\n\t\t\t��:");
                scanf("%d",&j);
                while(!((0<=m)&(m<=Hang))||!((0<=j)&(j<=Lie)))
                {
                    printf("\n�������������ѡ����Ҫ��λ�ã�x��y����");
                    scanf("%d,%d",&m,&j);
                }
            }
            else
            {
                m=rand()%Hang+1,j=rand()%Lie+1;//i��jȡ1-Hang/Lie�������
            }
            while (aw[m-1][j-1]==1)
            {
                printf("\n��ѡ�����λ�Ѿ�����,����������; \t��:");
                scanf("%d",&m);
                printf("\n\t\t\t\t\t��:");
                scanf("%d",&j);
            }
            printf("��ϲ������ɹ�!!\n");
            x=m-1,y=j-1;
            aw[x][y]=1;//�ı���ѡ����λ״̬

            printf("\t\t\t\t��ӰԺ��λ��\n\t\t");
            for(m=0; m<Hang;m++)
                for(j=0; j<Lie; j++)
                {
                    if(aw[m][j]==1)
                        printf(" �~ ");
                    else
                        printf(" �� ");
                    count++;
                    if(count%10==0)
                        printf("\n\t\t");//�����λ
                }
            printf("���λ������Ϊ��%d��%d��\n",x+1,y+1);
            break;
        }
        case 3://��Ʊ
        {
            printf("��Ʊ:\n");
            printf("\n��ѡ����Ҫ�˶���λ��\t��:");
            scanf("%d",&m);
            printf("\n\t\t\t��:");
            scanf("%d",&j);
            if (aw[m-1][j-1]==0)
            {
                printf("�������,����������!\n");
            }
            else
            {
                aw[m-1][j-1]=0;
                printf("��Ʊ�ɹ�!\n");
            }
            int count=0;
            printf("\t\t\t\t��ӰԺ��λ��\n\t\t");
            for(m=0; m<Hang; m++)
                for(j=0; j<Lie; j++)
                {
                    if(aw[m][j]==1)
                        printf(" �~ ");
                    else
                        printf(" �� ");
                    count++;
                    if(count%10==0)
                        printf("\n\t\t");//�����λ
                }
            break;
        }
        case 4:
        {
            printf("******�˳��ɹ�!!��ӭ�´ι���******\n");
            choice = 0;
            break;
        }
        default:
            break;
        }
    }
}


void save_out()//��ʾ��Ӱ��Ϣģ��
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
    while(!feof(in))//�ж��Ƿ����ļ�β
    {
        printf("\n\n");
        printf("(%d)",j);
        fscanf(in,"%s %d %d %d %d %d %s %s %f\n",name_1,&year_1,&mon_1,&day_1,&hour_1,&min_1,h,q,&i);
        printf("\t��Ӱ����:��%s��",name_1);
        printf("\n");
        printf("\t��Ӱ��ӳʱ��:%d��%d��%d��%d:%d",year_1,mon_1,day_1,hour_1,min_1);
        printf("\n");
        printf("\t��Ӱ����:%s��%s",h,q);
        printf("\n");
        printf("\t��ӰƱ��:%.2f",i);
        printf("\n");
        j++;
    }
    printf("\n�Ƿ���й�Ʊor����(1/0)��[ ]\b\b"); 
    scanf("%d",&flag);
    while((flag!=0)&&(flag!=1))
            {
                printf("\n�������������ѡ��1 or 0����\n 1.�ֶ�ѡ��\t 0.ϵͳ���\n");
                scanf("%d",&flag);
            }
    if(flag == 1)
        book();
    if(flag ==0)
    {
        getchar();//����
        fclose(in);
    }

}
//���ļ�����������չʾ����Ӱ����Ա������Ա����ͨ���������ݾ����Ƿ�������޸ġ������Ƿ񷵻�ѡ�����

int load(char * a)//���������ָ�����ļ��м�¼�ĵ�Ӱ��Ϣ����
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
    return(i-1); //���ؼ�¼����
}


void transform_2()//�ļ�����ת�����ı�->�����ƣ�
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


void transform_text () //�ļ�����ת����������->�ı���
{
    struct Movie movie;
    FILE *in, *out;
    int amount;     // ��Ϣ�ļ��еļ�¼����
    int con;      //�Ѵ�����ļ���¼����
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
    remove("movie0.txt");         //ɾ�����ļ�
    remove("movie.txt");
    rename("movie1.txt","movie.txt");      //��ʱ�ļ��滻ԭ�ļ�
}


void sort()//����������
{
    FILE*in;
    int flag;
    int total;//���������ļ�¼��
    int movie_price[20];
    int movie_day[10];
    int movie_hour[10];
    int t,t1,t2;//��ӰƱ�۸�����ʽѡ���־λ,t=1,�۸�����t=2,�۸���
    int n,qw,q2;
    int w;//��ͬ��־λ ,w��i�Ƚ�
    int l1=1;//��λ
    float i;
    int year1;
    int l;//test
    char a[100];
    int b,c,d,e,f;
    char h[100];
    char q[100];
    printf("\n");
    printf("|**************************************************************|");
    printf("\n\n\t�����������������ʽ:\n\t(1)��ӰƱ�۸�����\t(2)��Ӱʱ������\n\t[ ]\b\b");
    scanf("%d",&flag);
    while(!(flag==1||flag==2))
    {
        printf("\t������������������,��������1��2\n\t[ ]\b\b");
        scanf("%d",&flag);
    }
    if(flag==1) /* ����ӰƱ�۸����� */
    {
        printf("\n");
        printf("|**************************************************************|");
        printf("\n\t�����ӰƱ�۸�����ϵͳ\n");
        printf("\t��ѡ������ʽ��\n\t��1���۸�����\t(2)�۸���\n\t[ ]\b\b");
        scanf("%d",&t);
        while(!(t==1||t==2))
        {
            printf("\t������������������,��������1��2\n\t[ ]\b\b");
            scanf("%d",&t);
        }




        if((in=fopen("movie.txt","r"))==NULL)//���ĵ�
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
        //���ݷ�����
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
        if(t==1)//�۸�����
        {
            printf("\n\t��ӰƱ�۸���������:");
            printf("\n\tϵͳ��ѯ���:\n");

            for(l=total-1; l>=0; l--) //��ԭ��ֵƥ��,����
            {
                if((in=fopen("movie.txt","r"))==NULL)//���ĵ�
                {
                    printf("cannot open file\n");
                    exit(0);
                }

                while(!feof(in))
                {
                    fscanf(in,"%s %d %d %d %d %d %s %s %f\n",a,&b,&c,&d,&e,&f,h,q,&i);
                    if(movie_price[l]==i)
                    {
                        if(w==movie_price[l])//������ͬƥ��
                        {
                        }
                        else
                        {
                            printf("\n(%d)",l1);
                            printf("\t��Ӱ����:��%s��",a);
                            printf("\n");
                            printf("\t��Ӱ��ӳʱ��:%d��%d��%d��%d:%d",b,c,d,e,f);
                            printf("\n");
                            printf("\t��Ӱ����:%s��%s",h,q);
                            printf("\n");
                            printf("\t��ӰƱ��:%.2f",i);
                            printf("\n\n");
                            l1++;
                        }
                    }
                }
                w=movie_price[l];//��¼�ϴεıȽ�ֵ
                fclose(in);//�ر�
            }
            l1=1;//��λ
        }
        else if(t==2)//�۸���
        {
            printf("\n\t��ӰƱ�۸�������:\n");
            printf("\n\tϵͳ��ѯ�����\n");
            //title();
            for(l=0; l<=total-1; l++) //��ԭ��ֵƥ��,����
            {
                if((in=fopen("movie.txt","r"))==NULL)//���ĵ�
                {
                    printf("cannot open file\n");
                    exit(0);
                }
                while(!feof(in))
                {
                    fscanf(in,"%s %d %d %d %d %d %s %s %f\n",a,&b,&c,&d,&e,&f,h,q,&i);
                    if(movie_price[l]==i)
                    {
                        if(w==movie_price[l])//������ͬƥ��
                        {
                        }
                        else
                        {
                            printf("(%d)\n",l1);
                            printf("\t��Ӱ����:��%s��",a);
                            printf("\n");
                            printf("\t��Ӱ��ӳʱ��:%d��%d��%d��%d:%d",b,c,d,e,f);
                            printf("\n");
                            printf("\t��Ӱ��ӳ����:%s��%s",h,q);
                            printf("\n");
                            printf("\t��ӰƱ��:%.2f",i);
                            printf("\n\n");
                            l1++;
                        }
                    }
                }
                w=movie_price[l];//��¼�ϴεıȽ�ֵ
                fclose(in);//�ر�
            }
        }
    }

    if(flag==2) //����Ӱʱ������
    {

        printf("\n");
        printf("|**************************************************************|");
        printf("\n\t�����ӰƱʱ������\n");
        printf("\t��ѡ������ʽ��\n\t��1��ʱ������\t(2)ʱ�併��\n\t[ ]\b\b");
        scanf("%d",&t);
        while(!(t==1||t==2))
        {
            printf("\t������������������,��������1��2\n\t[ ]\b\b");
            scanf("%d",&t);
        }
        if(t==1)//��Ӱʱ������
        {
            do
            {
                qw=0;//��λ
                printf("\n");
                printf("|**************************************************************|");
                printf("\n\t�����Ӱʱ����������\n");
                printf("\n\tϵͳ��ѯ�����\n");
                if((in=fopen("movie.txt","r"))==NULL)//���ĵ�
                {
                    printf("cannot open file\n");
                    exit(0);
                }
                for(total=0,t=0; !feof(in); total++) //����
                {
                    fscanf(in,"%s %d %d %d %d %d %s %s %f\n",a,&b,&c,&d,&e,&f,h,q,&i);
                        movie_day[t]=d;//��¼����
                        //printf("�Ѽ�¼\n");
                        t++;
                        //day����
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
                    //w=movie_price[l];//��¼�ϴεıȽ�ֵ
                }
                if(t!=0)
                {
                    printf("\t��Ϊ���ҵ�%d��������������Ϣ\n",t);

                    for(l=t-1; l>=0; l--) //��ԭ��ֵƥ��,���� ��ȡ����������
                    {
                        if((in=fopen("movie.txt","r"))==NULL)//���ĵ�
                        {
                            printf("cannot open file\n");
                            exit(0);
                        }
                        while(!feof(in))
                        {
                            fscanf(in,"%s %d %d %d %d %d %s %s %f\n",a,&b,&c,&d,&e,&f,h,q,&i); 
								if(movie_day[l]==d){
								if(w==movie_day[l])//������ͬƥ��
                                {}
                                else
                                {
                                    printf("\n(%d)",l1);
                                    printf("\t��Ӱ����:��%s��",a);
                                    printf("\n");
                                    printf("\t��Ӱ��ӳʱ��:%d��%d��%d��",b,c,d);
                                    printf("\n");
                                    printf("\t��Ӱ����:%s��%s",h,q);
                                    printf("\n");
                                    printf("\t��ӰƱ��:%.2f",i);
                                    printf("\n\n");
                                    l1++;
                                }
								}
								else
								{}
                         
                        }
                        w=movie_day[l];//��¼�ϴεıȽ�ֵ
                        fclose(in);//�ر�
                    }
                    t=0;//��λ
                }
                else
                {
                    printf("\n\tû���ҵ�������������Ϣ\n");
                    printf("\n\n\tPress any key to continue......");
                    getch();
                    puts("\n\n");
                    printf("\t�������²�ѯ��������1\t���˳���������2\t\n\t[ ]\b\b");
                    getchar();
                    scanf("%d",&qw);
                    while(!(qw==1||qw==2))
                    {
                        printf("\n\t������������������\n");
                        printf("\t�������²�ѯ��������1\t���˳���������2\t\n\t[ ]\b\b");
                        getchar();
                        scanf("%d",&qw);
                    }
                }
                fclose(in);//�ر�
                printf("\n");
                /*	for(l=t-1;l>=0;l--)//�����ã���ɾ��
                {
                printf("\t���ԭ������%d\n",movie_day[l]);
                } */
            }while(qw==1);
        }


       if(t==2)//��Ӱʱ�併�� 
        {
            do
            {
                qw=0;//��λ
                printf("\n");
                printf("|**************************************************************|");
                printf("\n\t�����Ӱʱ�併������\n");
                printf("\n\tϵͳ��ѯ�����\n");
                if((in=fopen("movie.txt","r"))==NULL)//���ĵ�
                {
                    printf("cannot open file\n");
                    exit(0);
                }
                for(total=0,t=0; !feof(in); total++) //����
                {
                    fscanf(in,"%s %d %d %d %d %d %s %s %f\n",a,&b,&c,&d,&e,&f,h,q,&i);
                        movie_day[t]=d;//��¼����
                        t++;
                        //day����
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
                    //w=movie_price[l];//��¼�ϴεıȽ�ֵ
                }
                if(t!=0)
                {
                    printf("\t��Ϊ���ҵ�%d��������������Ϣ\n",t);

                    for(l=0; l<=t-1; l++) //��ԭ��ֵƥ��,���� ��ȡ����������
                    {
                        if((in=fopen("movie.txt","r"))==NULL)//���ĵ�
                        {
                            printf("cannot open file\n");
                            exit(0);
                        }
                        while(!feof(in))
                        {
                            fscanf(in,"%s %d %d %d %d %d %s %s %f\n",a,&b,&c,&d,&e,&f,h,q,&i); 
								if(movie_day[l]==d){
								if(w==movie_day[l])//������ͬƥ��
                                {}
                                else
                                {
                                    printf("\n(%d)",l1);
                                    printf("\t��Ӱ����:��%s��",a);
                                    printf("\n");
                                    printf("\t��Ӱ��ӳʱ��:%d��%d��%d��",b,c,d);
                                    printf("\n");
                                    printf("\t��Ӱ����:%s��%s",h,q);
                                    printf("\n");
                                    printf("\t��ӰƱ��:%.2f",i);
                                    printf("\n\n");
                                    l1++;
                                }
								}
								else
								{}
                        }
                        w=movie_day[l];//��¼�ϴεıȽ�ֵ
                        fclose(in);//�ر�
                    }
                    t=0;//��λ
                }
                else
                {
                    printf("\n\tû���ҵ�������������Ϣ\n");
                    printf("\n\n\tPress any key to continue......");
                    getch();
                    puts("\n\n");
                    printf("\t�������²�ѯ��������1\t���˳���������2\t\n\t[ ]\b\b");
                    getchar();
                    scanf("%d",&qw);
                    while(!(qw==1||qw==2))
                    {
                        printf("\n\t������������������\n");
                        printf("\t�������²�ѯ��������1\t���˳���������2\t\n\t[ ]\b\b");
                        getchar();
                        scanf("%d",&qw);
                    }
                }
                fclose(in);//�ر�
                printf("\n");
                /*	for(l=t-1;l>=0;l--)//�����ã���ɾ��
                {
                printf("\t���ԭ������%d\n",movie_day[l]);
                } */
            }while(qw==1);
        }
    }
    printf("\n\n\t����������Է�����һ����......");
    getch();
    puts("\n\n");
    //menu();
}


void search()//��ѯ����
{

    FILE*in;
    int flag;
    int total;//���������ļ�¼��
    char str[100];//�����ѯ��Ӱ���� 
    float i;//i=0����Ϣ��������
    float price1,price2;//���ڱȽϷ�Χ

    int qw;
    int l1=1;//��λ

    char a[100];
    int b,c,d,e,f,t;
    char g[100];
    char h[100];
    char q[100];
    do
    {
        printf("\n\n\t������������Ĳ�ѯ��ʽ:\n\t(1)��Ӱ���Ͳ�ѯ\t(2)��Ӱ�۸��ѯ\n\t[ ]\b\b");
        scanf("%d",&flag);
    }
    while(!(flag==1||flag==2));
    if(flag==1) /* ����Ӱ���Ͳ�ѯ */
    {
        printf("\n");
        printf("|**************************************************************|");
        printf("\n\t�����Ӱ���Ͳ�ѯ\n");
        do
        {
            i=0,qw=0;//��־λ��λ
            printf("\t�������ѯ����(�磺ϲ��/����)��");
            fflush(stdin);//ʹ gets������������
            gets(str);
            printf("\t����Ҫ��ѯ������Ϊ%s\n",str);
            printf("\n\tϵͳ��ѯ�����\n");
            //title();
            //��Ӱ���Ͳ�ѯƥ��
            //��ԭ��ֵƥ��,����

            if((in=fopen("movie.txt","r"))==NULL)//���ĵ�
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
                    printf("\t��Ӱ����:��%s��",a);
                    printf("\n");
                    printf("\t��Ӱ��ӳʱ��:%d��%d��%d��",b,c,d);
                    printf("\n");
                    printf("\t��Ӱ����:%s��%s",h,q);
                    printf("\n");
                    printf("\t��ӰƱ��:%.2f",i);
                    printf("\n\n");
                    l1++;
                }
            }
            fclose(in);//�ر�

            total=l1-1;
            if(total!=0)
            {
                printf("\t��Ϊ���ҵ�%d��������������Ϣ\n\n",total);
                total=0;//��λ
                printf("\t�������²�ѯ��������1\t���˳���������2\t\n\t[ ]\b\b");
                i=0;
                scanf("%d",&qw);
                while(!(qw==1||qw==2))
                {
                    printf("\n\t������������������\n");
                    scanf("%d",&qw);
                }
            }
            else
            {
                printf("\n\tû���ҵ�������������Ϣ\n");
                printf("\n\tPress any key to continue......\n");
                printf("\t�������²�ѯ��������1\t���˳���������2\t\n\t[ ]\b\b");
                i=0;
                scanf("%d",&qw);
                while(!(qw==1||qw==2))
                {
                    printf("\n\t������������������\n");
                    scanf("%d",&qw);
                }
            }
        }
        while(qw==1);
    }

    if(flag==2) /* ����Ӱ�۸��ѯ */
    {
        printf("\n");
        printf("|**************************************************************|");
        printf("\n\t�����Ӱ�۸��ѯ\n");
        do
        {
            i=0,qw=0;//��־λ��λ
            printf("\t�������ѯ�۸�Χ��\n\t(1)30~40\t(2)40~50\t(3)>50\n\t[ ]\b\b");
            scanf("%d",&t);
            while(!(t==1||t==2||t==3))
            {
                printf("\n\t������������������\n\t[ ]\b\b");
                scanf("%d",&t);
            }
            if(t==1)
            {
                price1=30;
                price2=40;
                printf("\t����Ҫ��ѯ�ļ۸�ΧΪ: 30~40\n");
            }
            else if(t==2)
            {
                price1=40;
                price2=50;
                printf("\t����Ҫ��ѯ�ļ۸�ΧΪ: 40~50\n");
            }
            else
            {
                price1=50;
                price2=1000000;
                printf("\t����Ҫ��ѯ�ļ۸�ΧΪ: >50\n");
            }

            printf("\n\tϵͳ��ѯ�����\n");

            if((in=fopen("movie.txt","r"))==NULL)//���ĵ�
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
                    printf("\t��Ӱ����:��%s��",a);
                    printf("\n");
                    printf("\t��Ӱ��ӳʱ��:%d��%d��%d��%dʱ%d��",b,c,d,e,f);
                    printf("\n");
                    printf("\t��Ӱ��ӳ����:%s��%s",h,q);
                    printf("\n");
                    printf("\t��ӰƱ��:%.2f",i);
                    printf("\n\n");
                    l1++;
                }
            }
            fclose(in);//�ر�

            total=l1-1;
            if(total!=0)
            {
                printf("\t��Ϊ���ҵ�%d��������������Ϣ\n\n",total);
                printf("\t�������²�ѯ��������1\t���˳���������2\t\n\t[ ]\b\b");
                i=0;
                scanf("%d",&qw);
                while(!(qw==1||qw==2))
                {
                    printf("\n\t������������������\n\t\n\t[ ]\b\b");
                    scanf("%d",&qw);
                }
            }
            else
            {
                printf("\n\tû���ҵ�������������Ϣ\n");
                printf("\n\n\tPress any key to continue......");
                getch();
                puts("\n\n");
                printf("\t�������²�ѯ��������1\t���˳���������2\t\n\t[ ]\b\b");
                i=0;
                scanf("%d",&qw);
                while(!(qw==1||qw==2))
                {
                    printf("\n\t������������������\n\t\n\t[ ]\b\b");
                    scanf("%d",&qw);
                }
            }
        }
        while(qw==1);
    }
    printf("\n\n\t����������Է�����һ����......");
    getch();
    puts("\n\n");
}
