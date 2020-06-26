#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

void load();
void welcome();
void gotoxy(int x, int y);
void main_menu();
void swic();
void exiting();
void guest_Username();
void guest_Password();
void Admin_Username();
void Admin_Password();
void clock();
void Admin_Choice();
void cyber_detcoln();
void cyber_detail();
void cyber_info();
void pc_runtime();
void price();
void after_detail();
void calculation();

struct login
{
    char name[50];
    char pass[50];
    
}ln;

struct cyber_detail
{
	char name[50];
	char address[50];
	long long int ph_no;
	char email[50];	
}cd;

int main()
{
	system("color F5");
	load();
	welcome();
	main_menu();

}

void gotoxy(int x, int y)
{

    COORD coord;

    coord.X = x;

    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
void load()
{
	int r,c,q;
	gotoxy(40,4);
	printf("LOADING CYBER SYSTEM...");
	gotoxy(40,5);
	for(r=1; r<=20; r++)
    {
		for(q=0; q<=100000000; q++); //to display the character slowly
		printf("%c",177);
    }
    system("cls");
}

void welcome(int x, int y)
{
	gotoxy(40,2);
	printf("******************************************");
	gotoxy(40,3);
	printf("********  WELCOME TO CYBER NEPAL  ********");
	gotoxy(40,4);
	printf("******************************************");
    gotoxy(45,6);
	printf("Press Any Key To Continue.");
	getch();
	system("cls");
}

void main_menu()
{  
	gotoxy(40,2);
	printf("*******************************");
	gotoxy(40,3);
	printf("********  MENU SCREEN  ********");
	gotoxy(40,4);
	printf("*******************************");
	gotoxy(43,6);
	printf("Enter your choice : ");
	gotoxy(43,7);
    printf("1 : Guest Login");
    gotoxy(43,8);
	printf("2 : Admin Login");
	gotoxy(43,9);
    printf("3 : Leave the Computer\n");
    gotoxy(43,10);
    swic();
}

void guest_Username()
{
	gotoxy(40,2);
	printf("*********  GUEST PORTAL  *********");
	gotoxy(43,3);
	printf("Username : ");
	scanf("%s",&ln.name);
	if(!strcmp(ln.name,"guest")==0)
		{
    		gotoxy(43,4);
    		printf("Invalid Username");
    		getch();
    		system("cls");
    		guest_Username();
    	}
}

void guest_Password()
{
	int i=0;
	char ch;
	gotoxy(40,2);
	printf("*********  GUEST PORTAL  *********");
	gotoxy(43,5);
    printf("Password : ");
      
    while(ch!=13)
    {
    	ch=getch();
    	if(ch!=13 && ch!=8)
    	{
    		putch('*');
    		ln.pass[i] = ch;
    		i++;
    	}
   }    

   	ln.pass[i] = '\0';
      
    if(strcmp(ln.pass,"user")==0)
	{
		system("cls");
	}
    else
    {
        gotoxy(43,6);
        printf("INVALID Password");
        getch();
        system("cls");
        gotoxy(43,6);
        guest_Password();
    }
}

void Admin_Username()
{

	gotoxy(40,2);
	printf("*********  ADMIN PORTAL  *********");
	gotoxy(43,3);
	printf("Username : ");
	scanf("%s",&ln.name);
	if(!strcmp(ln.name,"Admin")==0)
	{
    	gotoxy(43,4);
    	printf("Invalid Username");
   		getch();
		system("cls");
		Admin_Username();
	}
}

void Admin_Password()
{
	char ch;
	int i=0;
	gotoxy(40,2);
	printf("*********  ADMIN PORTAL  *********");
	gotoxy(43,5);
    printf("Password : ");
	while(ch!=13)
    {
    	ch=getch();
    	if(ch!=13 && ch!=8)
    	{
    		putch('*');
    		ln.pass[i] = ch;
    		i++;
    	}
   }    

	ln.pass[i] = '\0';  
	if(strcmp(ln.pass,"Oppa")==0)
	{
		system("cls");
	}
    else
    {
        gotoxy(43,6);
        printf("INVALID Password");
        getch();
        system("cls");
        gotoxy(43,3);
        Admin_Password();
    }
}
void swic()
{
	FILE *fp;
	char choics;
    fflush(stdin);
    choics=getch();
    system("cls");
    gotoxy(40,2);
    printf("*********  LOGIN PORTAL  *********\n\n");
     
    switch(choics)
	{
    	case '1':
        gotoxy(35,7);
        guest_Username();
        guest_Password();
      	clock();
      	exiting();
      	exit(0);
		break;
            
        case '2':
		Admin_Username(); 
		Admin_Password();
		Admin_Choice();
		exit(0);
		break;
		
        case '3':
		exiting();
        exit(0);
        break;
		   
        default :
        gotoxy(40,4);
        printf("Invalid Option : Enter any key for option menu");
        getch();
        system("cls");
        main_menu();
		swic();
	}
	system("cls");
}

void clock()
{
	FILE *clock_ptr;
	int hour, minute, second, hr, mn, sc;
	gotoxy(40,2);
  	printf("*******************************");
  	gotoxy(40,3);
  	printf("*******  TIME SCHEDULE  *******");
  	gotoxy(40,4);
  	printf("*******************************");
  	price();
    gotoxy(40,14);
    printf("Enter the Hour	 : ");
    scanf("%d",&hr);
    gotoxy(40,15);
    printf("Enter the Minute : ");
    scanf("%d",&mn);
    gotoxy(40,16);
    printf("Enter the Second : ");
    scanf("%d",&sc);
    system("cls");
    clock_ptr = fopen("clock_data.txt","a");
	fprintf(clock_ptr,"%d %d %d\n",hr,mn,sc);
	fclose(clock_ptr); 
    hour=hr;
	minute=mn;
	second=sc;
 
    while(1)
    {
		gotoxy(40,1);
		printf("******  TIME COUNTER  ******");
		gotoxy(40,2);
        printf("*****************************");
        gotoxy(40,3);
        printf(" ******  %02d : %02d : %02d ******",hour,minute,second);
        gotoxy(40,4);
        printf("*****************************");
        fflush(stdout);
        
            second--;
 
        if((hour!=0 || minute!=0) && second==0)
		{
			if(minute!=0)
			{
				minute-=1;
            	second=59;
			}
            	
            if(hour!=0 && minute==0)
			{
				if(hour!=0)
				{
					hour--;
					minute=59;
				}
    		}
		}
        
		if(hour==0 && minute==0 && second==0)
        {
        	gotoxy(42,6);
        	printf("Guest Portal Time Overed.");
        	exiting();
        	exit(0);
        	
		}
        sleep(1);
    }
}

void Admin_Choice()
{	gotoxy(40,3);
	printf("*******  Welcome to Admin Portal  *******");
	gotoxy(43,5);
	printf("1 : Excess Cyber Details");
	gotoxy(43,6);
	printf("2 : Back to main menu");
	gotoxy(43,7);
	printf("3 : For Guest Login");
	gotoxy(43,8);
	printf("4 : To Exit the PC");
	char choics;
	fflush(stdin);
	choics=getch();
	system("cls");
     
	switch(choics)
	{
    	case '1':
        cyber_detail();
        break;
        
    	case '2':
    	main_menu();
    	break;
    	
		case '3':
		guest_Username();
        guest_Password();
      	clock();
      	exiting();
      	exit(0);
        break;
        
		case '4':
		exit(0);
		break;
		
		default :
        gotoxy(40,4);
        printf("Invalid Option : Enter any key for option menu");
        getch();
        system("cls");
        Admin_Choice();
        break;
	}
}

void cyber_detail()
{
	gotoxy(40,2);
	printf("*******  CYBER DETAILS  *******");
	gotoxy(43,4);
	printf("1 : Cyber Detail Collection");
	gotoxy(43,5);
	printf("2 : Cyber Info");
	gotoxy(43,6);
	printf("3 : Today's PC Runtime");
	gotoxy(43,7);
	printf("4 : Today's Earning");
	gotoxy(43,8);
	printf("5 : To remove Cyber Detail");
	gotoxy(43,9);
	printf("6 : Back to main menu");
	
	char choics;
	fflush(stdin);
	choics=getch();
	system("cls");
	
	switch(choics)
	{
    	case '1':
        cyber_detcoln();
        after_detail();
        break;
        
    	case '2':
    	cyber_info();
    	after_detail();
    	break;
    	
    	case '3':
		pc_runtime();
    	after_detail();
    	break;
    	
		case '4':
		calculation();
		after_detail();
		break;
		
		case '5':
		remove("Detail.txt");
		gotoxy(43,4);
		printf("Cyber Detail has been Removed.");
		break;
		
		default :
        gotoxy(40,4);
        printf("Invalid Option : Enter any key for option menu");
        getch();
        system("cls");
        main_menu();
        break;
	}
	
}

void cyber_detcoln()
{	
	gotoxy(40,2);
	printf("*******  CYBER DETAIL COLLECTION *******");
	gotoxy(43,4);
	FILE *detail_fptr;
	detail_fptr=fopen("Detail.txt","w");
	fflush(stdin);
	printf("Cyber Name : ");
    gets(cd.name);
	fflush(stdin);
    gotoxy(43,5);
    fflush(stdin);
    printf("Address : ");
    gets(cd.address);
    fflush(stdin);
    gotoxy(43,6);
    fflush(stdin);
    printf("Phone Number : ");
    scanf("%lld",&cd.ph_no);
    gotoxy(43,7);
    fflush(stdin);
    printf("Email : ");
    gets(cd.email);
    fflush(stdin);
    fwrite(&cd,sizeof(cd),1,detail_fptr);
	fclose(detail_fptr);
	gotoxy(43,9);
	printf("Details Collected.");
}
void cyber_info()
{	
	FILE *detail_fptr;
	detail_fptr = fopen("Detail.txt","r");
	if(detail_fptr== NULL)
	{	
		gotoxy(43,2);
		printf("File not found");
	}
	else
	{
		fread(&cd,sizeof(cd),1,detail_fptr);
		gotoxy(43,4);
		printf("Cyber Name : %s\n",cd.name);
		gotoxy(43,5);
		printf("Address : %s\n",cd.address);
		gotoxy(43,6);
		printf("Ph. Number : %lld\n",cd.ph_no);
		gotoxy(43,7);
		printf("Email : %s\n",cd.email);
		fclose(detail_fptr);
	}
}

void pc_runtime()
{
	int i=1,hr,min,sec,total_hr=0,total_min=0,total_sec=0, x=43,y=4;
	FILE *clock_ptr;
	clock_ptr = fopen("clock_data.txt","r");
	gotoxy(48,2);
	printf("*******  Today's PC Runtime  *******");
	while((fscanf(clock_ptr,"%d %d %d",&hr,&min,&sec))!=EOF)
	{
		printf("\n\n\t\t\t\t\t\tUser %d:\t",i);
		printf("\n\n\t\t\t\t\t\t%d HOUR : ",hr);
		printf("%d MIN : ",min);
		printf("%d sec\n",sec);
		total_sec = total_sec+sec;
		total_min = total_min +min;
		total_hr = total_hr +hr;
		i++;
	}
	
	if(total_sec >= 60)
	{
		total_min = total_min+ total_sec/60;
		total_sec = total_sec%60;
		if(total_min >= 60)
		{
			total_hr = total_hr + total_min /60;
			total_min = total_min%60;
		}	
	}
	printf("\n\n\t\t\t\t\t\tTotal PC Runtime : %d HOUR : %d MIN : %d SEC\n",total_hr,total_min,total_sec);
	fclose(clock_ptr);
}
void after_detail()
{
	char choics;
	printf("\n\n\t\t\t\t\t   Press");
	printf("\n\n\t\t\t\t\t   1 : For Return to Admin Menu");
	printf("\n\n\t\t\t\t\t   2 : To exit from Program");
	fflush(stdin);
	choics=getch();
	system("cls");
	
	switch(choics)
	{
    	case '1':
        Admin_Choice();
        break;
        
    	case '2':
    	exit(0);
    	break;
    	
		default :
		printf("\n\n\t\t\t\t\t\t");
		printf("Invalid Choice");
		getch();
		after_detail();
		break;
	}
}
void price()
{	
	gotoxy(40,6);
	printf("TIME");
	gotoxy(40,7);
	printf("-------------------------------");
	gotoxy(40,8);
	printf("30 MIN");
	gotoxy(40,10);
	printf("1 HOUR");
	gotoxy(40,12);
	printf("2 HOUR");
	gotoxy(58,6);
	printf("PRICE");
	gotoxy(58,8);
	printf("50 rupes");
	gotoxy(58,10);
	printf("100 rupes");
	gotoxy(58,12);
	printf("200 rupes");
}

void calculation()
{
	FILE *clock_ptr;
	int i=1,hr,min,sec,total_hr=0,total_min=0,total_sec=0,	Total_price, Grand_Total;
	clock_ptr = fopen("clock_data.txt","r");
	gotoxy(40,4);
	printf("****************************************");
	gotoxy(40,5);
	printf("*********  TOTAL PRICE TO PAY  *********");
	gotoxy(40,6);
	printf("****************************************");
	while((fscanf(clock_ptr,"%d %d %d",&hr,&min,&sec))!=EOF)
	{
		Total_price = (hr * 120)+(min * 2 ) ;
		printf("\n\n\t\t\t\t\t\tUser %d:\t",i);
		printf("\n\n\t\t\t\t\t\t%d HOUR : ",hr);
		printf("%d MIN : ",min);
		printf("%d sec\n",sec);
		printf("\t\t\t\t\t\tTotal Price : Rs. %d",Total_price);
		total_sec = total_sec+sec;
		total_min = total_min +min;
		total_hr = total_hr +hr;
		
		if(clock_ptr== NULL)
		{	
			gotoxy(43,2);
			printf("Todays Earning = Rs. 0");
		}
		else
		{
			Grand_Total = (total_hr * 120)+(total_min * 2 ) ;
			i++;
			
		}
		
	}	
	printf("\n\n\t\t\t\t\t\tGrand Total Amount : Rs. %d",Grand_Total);
	fclose(clock_ptr);
}

void exiting()
{
    int r,q;
    gotoxy(42,8); 
    printf("EXITING CYBER SYSTEM...");
    gotoxy(42,9);
    for(r=1; r<=20; r++)
    {
        for(q=0; q<=100000000; q++); 
        printf("*");
    }
    system("cls");
}
