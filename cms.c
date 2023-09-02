#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void heading();
void main_heading();
void menu();
void user_menu();
void insert();
void display();
void search();
void delete();
void arrival_time();
void user_login();
void login_user();
void main()
{
    
    char name[30];
    int id;
    int ch;
    char username[20];
    char password[20];

    system("CLS");
    system("color 86");
    heading();
    printf("\n\n\t\t\t\t\t  1.) Login as an Admin to check/edit records");
    printf("\n\t\t\t\t\t  2.) Login as a user to view your records");
    printf("\n\n\t\t\t\t\t         Enter your choice (1/2) : ");
    scanf("%d",&ch);
    system("CLS");

    switch(ch)
    {
        case 1:system("CLS");
               heading();
               printf("\n\n\t\t\t\t\t\t][    ADMIN LOGIN PAGE   ][\t\t\t\t");
               printf("\n\n\n\t\t\t\t\tEnter your Username : ");
               scanf("%s",&username);
               printf("\t\t\t\t\tEnter your Password : ");
               scanf("%s",&password);

               if(strcmp(username, "Admin_55")==0)  /*Admin_55 is userid which is fixed since it is admin login and not user login*/
               {
                   if(strcmp(password ,"Cyber@123")==0)  /*Cyber@123 is password which is fixed since it is admin login and not user login*/
                   {
                       system("CLS");
                       main_heading();
                       printf("\n\n\t\t\t\t\t          WELCOME ADMIN!! LOGIN SUCCESSFULL");
                       menu();
                   }
                   else
                   {
                       printf("\t\t\t\t\tIncorrect Password !!! Failed to Login");
                   }
               }
               else
               {
                    printf("\t\t\t\t\tUsername is invalid !! Failed to Login!");
               }

                break;
        case 2:system("CLS");
               heading();
               int cho;
               printf("\n\n\t\t\t\t\t\t1.) Login into your account");
               printf("\n\t\t\t\t\t\t2.) New user? Sign up ");
               printf("\n\t\t\t\t\t\n\t\t\t\t\t\tEnter your Choice (1/2) : ");
               scanf("%d",&cho);

               switch(cho)
               {
                   case 1: printf("\n\n\n\n\t\t\t\t\t\t     ][   USER LOGIN PAGE   ][\t\t\t\t\n");
                           main_heading();
                           login_user();
                           break;
                   case 2: system("CLS");
                            main_heading();
                            user_login();
                            break;

                    default: printf("\n\t\t\t\t\tInvalid Choice!!!");
                             break;

               }
                           
        //default:printf("\n\n\t\t\t\t\tInvalid Choice!!!");
    }
}   
void heading()
{
    printf("\n\t\t\t\t--------------------------------------------------------------\t\t\t\t");
    printf("\n\t\t\t\t||             WELCOME TO CYBER MANAGEMENT SYSTEM           ||\t\t");
    printf("\n\t\t\t\t--------------------------------------------------------------\t\t\t\t\n");
}

void main_heading()
{
    printf("\n\t\t\t\t\t---------------------------------------------------\t\t\t\t");
    printf("\n\t\t\t\t\t||              CYBER MANAGEMENT SYSTEM          ||\t\t");
    printf("\n\t\t\t\t\t---------------------------------------------------\t\t\t\t");
}

void menu()
{
    int choice;
    printf("\n\n\n\t\t\t\t\t\t    ||<--------MENU-------->||");
    printf("\n\n\t\t\t\t\t\t      1.Insert a Record");
    printf("\n\t\t\t\t\t\t      2.Display Records");
    printf("\n\t\t\t\t\t\t      3.Search in Records");
    printf("\n\t\t\t\t\t\t      4.Delete a Record");
    printf("\n\t\t\t\t\t\t      5.Exit");
    printf("\n\n\t\t\t\t\t\t      Enter your choice : ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1: system("CLS");
                insert();
                break;

        case 2: system("CLS");
                main_heading();
                display();
                printf("\n\n\n\t\t\t\t\t\t     Press any key to continue ");
                fflush(stdin);
                getchar();
                menu();

        case 3: system("CLS");
                search();
                printf("\n\n\n\t\t\t\t\t\t   Press any key to continue ");
                fflush(stdin);
                getchar();
                menu();
                break;

        case 4: system("CLS");
                delete();
                break;

        case 5: system("CLS");
                exit(0);
                break;

        default: printf("\n\t\t\t\t\t\t\tINVALID CHOICE !!");
    }
}

void user_menu()
{
    int choice;
    printf("\n\n\n\t\t\t\t\t\t    ||<--------MENU-------->||");
    printf("\n\n\n\t\t\t\t\t\t      1.)View Your Record");
    printf("\n\t\t\t\t\t\t      2.)Exit");
    printf("\n\n\t\t\t\t\t\t      Enter your choice : ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1: system("CLS");
                search();
                printf("\n\n\n\t\t\t\t\t\t       User Safely Exited! ");
                {exit(0);}
                break;

        case 2: system("CLS");
                exit(0);
                break;
        default: printf("\n\t\t\t\t\t\t\tINVALID CHOICE !!");
    }
}

void insert()
{
    time_t mytime;
    struct tm* current_time;
    mytime = time(NULL);
    current_time = localtime(&mytime);
    FILE *fp;
    char name[30];
    int id;
    char choice='y';
    system("CLS");
    fp = fopen("cyber.txt","ab+");

    if(fp==NULL)
    {
        printf("\n\t\t\t\t\tERROR OPENING FILE !!!");
        return;
    }
    fflush(stdin);
    while(choice=='y')
    {
        main_heading();
        printf("\n\n\t\t\t\t\t\t\tENTER NEW USER DATA :");
        printf("\n\n\t\t\t\t\t Enter USER ID : ");
        scanf("%d",&id);
        fflush(stdin);
        printf("\n\n\t\t\t\t\t Enter Name of the user : ");
        scanf("%s",&name);
        fflush(stdin);
        fprintf(fp,"%d %s\t",id,name);
        fprintf(fp,"%02d/%02d/%d %02d:%02d",current_time->tm_mday,current_time->tm_mon+1,current_time->tm_year+1900,current_time->tm_hour,current_time->tm_min);
        fprintf(fp,"\n");
        arrival_time();
        printf("\n\n\t\t\t\t\t USER RECORD HAS BEEN INSERTED SUCCESSFULLY !!");
        
        printf("\n\n\t\t\t\t\t Do you want to add another record ? (y/n) : ");
        scanf("%c",&choice);
        fflush(stdin);
        system("CLS");
        fflush(stdin);
    }
    fclose(fp);
    printf("\n\n\t\t\t\t\t\t     Press any key to continue ");
    getchar();
    menu();
}

void display()
{
    
    int duration,tothr;
    int totmin;
    time_t mytime;
    struct tm* current_time;
    mytime = time(NULL);
    current_time = localtime(&mytime);
    FILE *fp;
    fp = fopen("cyber.txt","rb");
    
    if(fp==NULL)
    {
        printf("\n\t\t\t\t\tERROR OPENING FILE !!!");
        return;
    }
    char name[30];
    int id;
    int mday,mmon,myear,mmin,mhour;
    printf("\n\n\t\t\t\t\t\t    USER DETAILS ARE AS FOLLOWS :\n");
    //printf("\n\t\t\t   ____________________________________________________________________");
    printf("\n\n\t\t\t   User ID\t\tName of the User\tDate\t\tTime\t Duration");
    //printf("\n\t\t\t   ____________________________________________________________________");

    while(fscanf(fp,"%d %s %02d/%02d/%d %02d:%02d",&id,&name,&mday,&mmon,&myear,&mhour,&mmin)!=EOF)
    {
        printf("\n\n\t\t\t    %d \t\t\t%s \t\t\t%02d/%02d/%d \t%02d:%02d",id,name,mday,mmon,myear,mhour,mmin);
        tothr =(((current_time->tm_hour*60)+(current_time->tm_min))-((mhour*60)+mmin));
        duration = tothr/60;
        totmin = tothr-(duration*60);
        printf("\t %dHr:%dMin",duration,totmin);
    }
    fclose(fp);
}
 void search()
{
    system("CLS");
    main_heading();
    int my_id,flag=0;
    int duration,tothr,totmin;
    time_t mytime;
    struct tm* current_time;
    mytime = time(NULL);
    current_time = localtime(&mytime);
    FILE *fp;
    char name[30];
    int id;
    int mday,mmon,myear,mmin,mhour;
    fp = fopen("cyber.txt","rb");
    if(fp==NULL)
    {
        printf("\n\t\t\t\t\tERROR OPENING FILE !!!");
        return;
    }
    printf("\n\n\t\t\t\t\t Enter USER ID to fetch login information : ");
    scanf("%d",&my_id);
    while(fscanf(fp,"%d %s %02d/%02d/%d %02d:%02d",&id,&name,&mday,&mmon,&myear,&mhour,&mmin)!=EOF)
    {
        if(my_id == id)
        {
            flag=1;
            printf("\n\t\t\t\t\t RECORD FOUND SUCCESSFULLY !!");
            printf("\n\n\t\t\t\t\t User_ID : %d",id);
            printf("\n\t\t\t\t\t Name of User : %s",name);
            printf("\n\t\t\t\t\t Login Date And Time : %02d/%02d/%d   %02d:%02d",mday,mmon,myear,mhour,mmin);
            tothr =(((current_time->tm_hour*60)+(current_time->tm_min))-((mhour*60)+mmin));
            duration = tothr/60;
            totmin = tothr-(duration*60);
            printf("\n\t\t\t\t\t Duration : %dHr:%dMin",duration,totmin);
            if(tothr>300)
            {
                printf("\n\n\t\t\t\t\t\t  ALERT!! SUSPICIOUS ACTIVITY, \n\t\t\t\t\t\t   SESSION DURATION TOO LONG!");
            }
            break;
        }
    }    
        fclose(fp);
        if(flag==0)
        {
            printf("\n\t\t\t\t\t\t\tRecord not found !!");
        }
    
}

void delete()
{
    system("CLS");
    main_heading();
    FILE *fp,*ft;
    time_t mytime;
    struct tm* current_time;
    mytime = time(NULL);
    current_time = localtime(&mytime);
    int my_id;
    char name[30];
    int id;
    int mday,mmon,myear,mmin,mhour;
    unsigned flag=0;
    fp = fopen("cyber.txt","rb");
    if(fp==NULL)
    {
        printf("\n\t\t\t\t\tERROR OPENING FILE !!!");
        return;
    }
    printf("\n\n\t\t\t\t\t  |----------- PREVIOUS ENTERED DATA -----------|");
    display();
    printf("\n\n\n\t\t\t\t\t Enter ID of the user which you want to delete : ");
    scanf("%d",&my_id);

    ft = fopen("cyber1.txt","wb");
    if(ft==NULL)
    {
        printf("\n\t\t\t\tERROR OPENING NEW FILE !!");
    }
    while(fscanf(fp,"%d %s %02d/%02d/%d %02d:%02d",&id,&name,&mday,&mmon,&myear,&mhour,&mmin)!=EOF)
    {
        if(my_id!=id)
        {
            flag=1;
            fprintf(ft,"%d %s\t",id,name);
            fprintf(ft,"%02d/%02d/%d %02d:%02d",mday,mmon,myear,mhour,mmin);
            fprintf(ft,"\n");
        }
    }
   if(flag==0)
    {
        printf("\n\t\t\t\tNo Such Record Found!!");
    }
    fclose(fp);
    fclose(ft);
    remove("cyber.txt");
    rename("cyber1.txt","cyber.txt");
    printf("\n\n\n\n\t\t\t\t\t\t    Record Deleted Successfully!!");
    printf("\n\n\t\t\t\t\t\t  |------ Updated  Records ------| ");
    display();
    printf("\n\n\t\t\t\t\t\tPress any key to Continue");
    fflush(stdin);
    getchar();
    system("CLS");
    main_heading();
    menu();
}

void arrival_time()
{
    time_t rawtime;
    struct tm* timeinfo;
    struct tm* dateinfo;
    char buf[80];
    char buffer[80];
    FILE *fp;

    fp = fopen("cyber.txt", "ab+");

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    dateinfo = localtime(&rawtime);

    strftime(buffer, 80, "%I:%M:%S", timeinfo);
    strftime(buf, 80, "%b %d, %Y", dateinfo);
    printf("\n\n\t\t\t\t\t Arrival Time : %s",buffer);
    printf("      Date : %s",buf);
}

void user_login()
{
    char usern[20],pass[20];
    FILE *fp;
    fp=fopen("login.txt","ab+");
    printf("\n\n\t\t\t\t\t\t\t|  CREATE NEW USER   |");
    printf("\n\n\t\t\t\t\t  Enter Username :");
    scanf("%s",&usern);
    printf("\n\t\t\t\t\t  Enter Password : ");
    scanf("%s",&pass);
    fprintf(fp,"%s %s",usern,pass);
    fprintf(fp,"\n");
    system("CLS");
    printf("\n\t\t\t\t\t\t  New User Successfully Created! ");
    user_menu();
    
}

void login_user()
{
    char u_id[20],p[20];
    char usern[20],pass[20];
    FILE *fp;
    fp=fopen("login.txt","rb");
    printf("\n\n\t\t\t\t\t   Username : ");
    scanf("%s",u_id);
    while(fscanf(fp,"%s %s",&usern,&pass)!=EOF)
    {
    if(strcmp(u_id,usern)==0)
        {
            printf("\n\t\t\t\t\t   Password : ");
            scanf("%s",&p);
            if(strcmp(p,pass)==0)
            {
                system("CLS");
                main_heading();
                printf("\n\n\t\t\t\t\tWELCOME USER!! LOGIN SUCCESSFULL!");
                printf("\n\n");
                user_menu();
                printf("\n\n\t\t\t\t\t\t any key to continue ");
                fflush(stdin);
                getchar();
                user_menu();
            }
            else
            {
                printf("\n\t\t\t\t\tIncorrect username or password");
                printf("\n\t\t\t\t\tTRY AGAIN");
                login_user();
            }
        }
        printf("\n\t\t\t\t\t      Incorrect Username!! Please Try    again\n\t\t\t\t\t\t      or create a new user\n");
        user_login();
    }
}
//END
