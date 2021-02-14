#include<stdio.h>
#include<windows.h>//gotoxy
#include<conio.h>//getch,delay
#include<ctype.h>//toypper
#include<string.h>//strcmp,strlen
#include<stdlib.h>

char ans=0;
int ok,b,valid=0;
void WelcomeScreen(void);
void MainMenu(void);
void LoginScreen(void);
void Add_rec(void);
void func_list(void);
void Search_rec(void);
void Edit_rec(void);
void Dlt_rec(void);
void ex_it(void);
void Title(void);

void gotoxy(short x,short y){
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

//list of global variable
struct patient{
	int age;
	char Gender;
	char First_Name[20];
	char Last_Name[20];
	char Contact_no[15];
	char Address[30];
	char Email[30];
	char Doctor[20];
	char Problem[20];
};
struct patient p,temp_c;

main(void){
	WelcomeScreen();
	Title();
	LoginScreen();
}

//welcomescreen
void WelcomeScreen(void){
	printf("\n\n\n\n\n\n\n\t\t\t#########################################");
	printf("\n\t\t\t#\t\tWelcome To\t\t#");
	printf("\n\t\t\t#  BENGALI HOSPITAL MANAGEMENT SYSTEM   #");
	printf("\n\t\t\t#########################################");
	printf("\n\n\n\n\n\n\nPress any key to continue...");
	getch();
	system("cls");//clear screen
}
//title
void Title(void){
	printf("\n\n\t\t-----------------------------------------------------------------");
	printf("\n\t\t\t\t            BENGALI HOSPITAL             ");
	printf("\n\t\t-----------------------------------------------------------------");
	

}

//login screen
void LoginScreen(void){
	
	int e=0;
	char Username[15];
	char Password[15];
	char orginal_Username[25]="Tirtharaj";
	char orginal_Password[25]="721301";
	
	do{
		printf("\n\n\n\t\t\tEnter your Username and Password :)");
		printf("\n\n\n\t\t\t\tCorrect USERNAME : Tirtharaj");
		printf("\n\t\t\t\tCorrect PASSWORD : 721301");


		printf("\n\n\n\t\t\t\tUSERNAME :");
		scanf("%s",&Username);
		printf("\n\n\n\t\t\t\tPASSWORD :");
		scanf("%s",&Password);
		
		if(strcmp(Username,orginal_Username)==0 && strcmp(Password,orginal_Password)==0 ){
				printf("\n\n\n\t\t\t ...Login Successful...");
				getch();
				MainMenu();
				break;
		}
		else{
			printf("\n\n\n\t\t\t Password in incorrect :( Try again :)");
			e++;
			getch();
		}
	}while(e<=2);
	
	if(e>2){
		printf("\n\n\n\n\nYou have cross the limit. You can`t  login :( :(");
		getch();
		ex_it();
	}
	system("cls");
}
//mainmenu
void MainMenu(void){
	system("cls");
	int choose;
	Title();
	printf("\n\n\n\n\n\t\t\t\t1. Add Patient Record\n");
	printf("\n\t\t\t\t2. List Patient Record\n");
	printf("\n\t\t\t\t3. Sreach Patient Record\n");
	printf("\n\t\t\t\t4. Edit Patient Record\n");
	printf("\n\t\t\t\t5. Delete Patient Record\n");
	printf("\n\t\t\t\t6. Exit\n");
	printf("\n\n\n\n\t\t\t\tChoose from 1 to 6 ");
	scanf("%i",&choose);
	
	switch(choose){
		case 1:
			Add_rec();
			break;
		case 2:
			func_list();
			break;
		case 3:
			Search_rec();
			break;
		case 4:
			Edit_rec();
			break;
		case 5:
			Dlt_rec();
			break;
		case 6:
			ex_it();
			break;	
		default:
			printf("\t\t\t Invalid Entry. Please enter a right option");
			getch();			
			MainMenu();									
	}

}

//exit
void ex_it(void){
	system("cls");
	Title();
	printf("\n\n\n\n\n\t\t\t Thank You for visiting :) ");
	getch();
	
}
 
 //add record
void Add_rec(void){
	system("cls");
	Title();
	char ans;
	FILE*ek;
	ek=fopen("Record2.dat","a");
	printf("\n\n\t\t\t!!!!!!!!!!!!!!!!!!Add Patient Record!!!!!!!!!!!!!!!!!!!!\n");
	//first name
	A:
	printf("\n\t\t\tFirst Name : ");
	scanf(" %s",p.First_Name);
	p.First_Name[0]=toupper(p.First_Name[0]);
	if(strlen(p.First_Name)>20 || strlen(p.First_Name)<2){
		printf("\n\t Invalid :( \t The Max Range is 20 and Min Range is 2");
		goto A;
	}
	else{
		for(b=0;b<strlen(p.First_Name);b++){
			if(isalpha(p.First_Name[b])){
				valid=1;
			}
			else{
				valid=0;
				break;
			}
		}
		if(!valid){
			printf("\n\t\t First Name contain invalid character :( Enter Again :)");
			goto A;
		}
	}
	//last name
	B:
	printf("\n\t\t\tLast Name : ");
	scanf(" %s",p.Last_Name);
	p.Last_Name[0]=toupper(p.Last_Name[0]);
	if(strlen(p.Last_Name)>20 || strlen(p.Last_Name)<2){
		printf("\n\t Invalid :( \t The Max Range is 20 and Min Range is 2");
		goto B;
	}
	else{
		for(b=0;b<strlen(p.Last_Name);b++){
			if(isalpha(p.Last_Name[b])){
				valid=1;
			}
			else{
				valid=0;
				break;
			}
		}
		if(!valid){
			printf("\n\t\t Last Name contain invalid character :( Enter Again :)");
			goto B;
		}
	}
	//gender
	do{
		
		printf("\n\t\t\tGender[F/M] : ");
		scanf(" %c",&p.Gender);
		if(toupper(p.Gender)== 'M' || toupper(p.Gender)== 'F'){
			ok=1;
		}else{
			ok=0;
		}
		if(!ok){
			printf("\n\t\t Gender contain invalid character :( Enter Again :)");
		}
	}while(!ok);
	//age
	printf("\n\t\t\tAge : ");
	scanf("%i",&p.age);
	//	address
	do{
		C:
		printf("\n\t\t\tAddress : ");
		scanf(" %s",p.Address);
		p.Address[0]=toupper(p.Address[0]);
		if(strlen(p.Address)>20 || strlen(p.Address)<3){
			printf("\n\t Invalid :( \t The Max Range is 20 and Min Range is 3");
			goto C; 
		}
	}while(!valid);
	//contact info
	
	D:
	printf("\n\t\t\tContact Number : ");
	scanf(" %s",p.Contact_no);
	if(strlen(p.Contact_no)!=10){
		printf("\n\t Invalid :( \t Contact must contain 10 digits");
		goto D;
	}
	else{
		for(b=0;b<strlen(p.Contact_no);b++){
			if(!isalpha(p.Contact_no[b])){
				valid=1;
			}
			else{
				valid=0;
				break;
			}
		}
		if(!valid){
			printf("\n\t\t Contact contain invalid digits :( Enter Again :)");
			goto D;
		}
	}
	//Email
	
	do{
		printf("\n\t\t\tEmail :");
		scanf(" %s",p.Email);
		if(strlen(p.Email)>30 || strlen(p.Email)<8){
			printf("\n\t Invalid :( \t The Max Range for Email is 30 and Min Range is 8");

		}
		
	}while(strlen(p.Email)>30 || strlen(p.Email)<8);
	
	//problem
	E:
	printf("\n\t\t\tProblem : ");
	scanf(" %s",p.Problem);
	p.Problem[0] = toupper(p.Problem[0]);
	if(strlen(p.Problem)>15 ||strlen(p.Problem)<3){
		printf("\n\t Invalid :( \t The Max Range for Problem is 15 and Min Range is 3");
		goto D;
	}
	else{
		for(b=0;b<strlen(p.Problem);b++){
			if(isalpha(p.Problem[b])){
				valid=1;
			}
			else{
				valid=0;
				break;
			}
		}
		if(!valid){
			printf("\n\t\t Problem contain invalid character :( Enter Again :)");
			goto E;
		}
	}	
	//prescribed doctor
	F:
	printf("\n\t\t\tPrescribed Doctor : ");
	scanf(" %s",p.Doctor);
	p.Doctor[0] = toupper(p.Doctor[0]);
	if(strlen(p.Doctor)>30 ||strlen(p.Doctor)<3){
		printf("\n\t Invalid :( \t The Max Range for Doctor is 30 and Min Range is 3");
		goto F;
	}
	else{
		for(b=0;b<strlen(p.Doctor);b++){
			if(isalpha(p.Doctor[b])){
				valid=1;
			}
			else{
				valid=0;
				break;
			}
		}
		if(!valid){
			printf("\n\t\t Doctor contain invalid character :( Enter Again :)");
			goto F;
		}
	}
	fprintf(ek,"%s %s %c %i %s %s %s %s %s\n",p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
	printf("\n\n\t\t\t.... Information Record Successfully ....");
	fclose(ek);
		getch();

	sd:
	printf("\n\n\t\t\tDo you want to add moer[Y/N]? ");
	scanf(" %c",&ans);
	if(toupper(ans) == 'Y'){
		Add_rec();
	}	
	else if(toupper(ans) == 'N'){
		printf("\n\t\tThank You :) :)");
		getch();
		MainMenu();
	}	
	else{
		printf("\n\t\tInvalid Input \n");
		goto sd;
	}
	
		
} 

//show list
void func_list(){
	int row;
	system("cls");
	Title();
	FILE *ek;
	ek=fopen("Record2.dat","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!!!List Patient Record!!!!!!!!!!!!!!!!!");
		gotoxy(1,15);
		printf("Full Name");
		gotoxy(20,15);
		printf("Gender");
		gotoxy(32,15);
		printf("Age");
		gotoxy(37,15);
		printf("Address");
		gotoxy(49,15);
		printf("Contact No.");
		gotoxy(64,15);
		printf("Email");
		gotoxy(88,15);
		printf("Problem");
		gotoxy(98,15);
		printf("Prescribed Doctor\n");
		printf("========================================================================================================================\n");
		row=18;
		while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n",p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor)!= EOF){
			gotoxy(1,row);
			printf("%s %s",p.First_Name,p.Last_Name);
			gotoxy(20,row);
			printf("%c",p.Gender);
			gotoxy(32,row);
			printf("%i",p.age);
			gotoxy(37,row);
			printf("%s",p.Address);
			gotoxy(49,row);
			printf("%s",p.Contact_no);
			gotoxy(64,row);
			printf("%s",p.Email);
			gotoxy(88,row);
			printf("%s",p.Problem);
			gotoxy(98,row);
			printf("%s",p.Doctor);	
			row++;
		}
		fclose(ek);
		getch();
		MainMenu();
}


//search list
void Search_rec(){
	char name[20];
	system("cls");
	Title();
	FILE *ek;
	ek=fopen("Record2.dat","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!!!Search Patient Record!!!!!!!!!!!!!!!!!");
	printf("\n\nEnter Patient to be viewed: ");
	scanf("%s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	
		while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n",p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor)!= EOF){
			if(strcmp(p.First_Name,name) == 0)
			{
				gotoxy(1,15);
				printf("Full Name");
				gotoxy(20,15);
				printf("Gender");
				gotoxy(32,15);
				printf("Age");
				gotoxy(37,15);
				printf("Address");
				gotoxy(49,15);
				printf("Contact No.");
				gotoxy(64,15);
				printf("Email");
				gotoxy(88,15);
				printf("Problem");
				gotoxy(98,15);
				printf("Prescribed Doctor\n");
				printf("========================================================================================================================\n");
				
				gotoxy(1,18);
				printf("%s %s",p.First_Name,p.Last_Name);
				gotoxy(20,18);
				printf("%c",p.Gender);
				gotoxy(32,18);
				printf("%i",p.age);
				gotoxy(37,18);
				printf("%s",p.Address);
				gotoxy(49,18);
				printf("%s",p.Contact_no);
				gotoxy(64,18);
				printf("%s",p.Email);
				gotoxy(88,18);
				printf("%s",p.Problem);
				gotoxy(98,18);
				printf("%s",p.Doctor);	
				break;
			}
			
		}
		if(strcmp(p.First_Name,name) != 0){
			gotoxy(5,10);
			printf("Record not found");
			getch();
		}
		fclose(ek);
		L:
			getch();
			printf("\n\n\t\t\tDo you want view more[Y/N] ");
			scanf("%c",&ans);
			if(toupper(ans) == 'Y'){
				Search_rec();
			}
			else if(toupper(ans) == 'N'){
				printf("\n\t\t Thank You :)");
				getch();
				MainMenu();
			}
			else{
				printf("\n\t\t Invalid Input.\n");
				goto L;
			}
}

//edit record
void Edit_rec(){
	FILE *ek,*ft;
	int i,b,valid=0;
	char ch;
	char name[20];
	system("cls");
	Title();
	ft=fopen("temp2.dat","w+");
	ek=fopen("Record2.dat","r");
	if(ek == NULL){
		printf("\n\t Can`t open files !!");
		getch();
		MainMenu();
	}
	printf("\n\n\t\t\t!!!!!!!!!!!!!!!Search Patient Record!!!!!!!!!!!!!!!!!");
	gotoxy(12,13);
	printf("Enter the First name of Patient : ");
	scanf("%s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	gotoxy(12,15);
	if(ft==NULL){
		printf("\nCan not open file");
		getch();
		MainMenu();
	}
	while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n",p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor)!= EOF){
		if(strcmp(p.First_Name,name) == 0){
			valid=1;
			gotoxy(25,17);
			printf("***Exiting Record****");
//			gotoxy(10,19);
			printf("\n%s \t%s \t%c \t%i \t%s \t%s \t%s \t%s \t%s\n",p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
			gotoxy(12,22);
			printf("Enter New First Name : ");
			scanf("%s",p.First_Name);
			gotoxy(12,24);
			printf("Enter New Last Name : ");
			scanf("%s",p.Last_Name);
			gotoxy(12,26);
			printf("Enter New Gender : ");
			scanf(" %c",&p.Gender);
			p.Gender=toupper(p.Gender);
			gotoxy(12,28);
			printf("Enter New Age : ");
			scanf("%i",&p.age);
			gotoxy(12,30);
			printf("Enter New Address : ");
			scanf("%s",p.Address);
			p.Address[0]=toupper(p.Address[0]);
			gotoxy(12,32);
			printf("Enter New Contact No. : ");
			scanf("%s",p.Contact_no);
			gotoxy(12,34);
			printf("Enter New Email : ");
			scanf("%s",p.Email);
			gotoxy(12,36);
			printf("Enter Priblem : ");
			scanf("%s",p.Problem);
			p.Problem[0]=toupper(p.Problem[0]);
			gotoxy(12,38);
			printf("Enter Doctor : ");
			scanf("%s",p.Doctor);
			p.Doctor[0]=toupper(p.Doctor[0]);
			printf("\nPress U for Updating operation: ");
			ch=getch();
			if(ch == 'u' || ch=='U'){
				fprintf(ft,"\n%s \t%s \t%c \t%i \t%s \t%s \t%s \t%s \t%s\n",p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
				printf("\n\n\t\t\tPatient record updated successfully....");
				
			}
		}
		else{
			fprintf(ft,"\n%s \t%s \t%c \t%i \t%s \t%s \t%s \t%s \t%s\n",p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
			
		}
	}
	
	if(!valid){
		printf("\n\t\tNo Record Found...");
		
	}
	fclose(ft);
	fclose(ek);
	remove("Record2.dat");
	rename("temp2.dat","Record2.dat");
	getch();
	MainMenu();

	
}
//gelete record
void Dlt_rec(){
	FILE *ek,*ft;
	int found=0;
	char name[20];
	system("cls");
	Title();
	ft=fopen("temp_file2.dat","w+");
	ek=fopen("Record2.dat","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!!!Delete Patient Record!!!!!!!!!!!!!!!!!");
	gotoxy(12,8);
	printf("Enter the First name of Patient to delete : ");
	
	fflush(stdin);
	gets(name);
	name[0]=toupper(name[0]);
	while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n",p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor)!= EOF)
	{
		if(strcmp(p.First_Name,name) != 0){
			fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);

		}
		else
		{
			printf("%s %s %c %i %s %s %s %s %s\n",p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
			found=1;
		}

	}
	if(found == 0){
		printf("\n\n\t\t\tRecord not found");
		getch();
		MainMenu();
	}
	else{
		fclose(ft);
		fclose(ek);
		remove("Record2.dat");
		rename("temp_file2.dat","Record2.dat");
		printf("\n\n\t\t\tRecord deleted successfully....");
		getch();
		MainMenu();
	}

	
}





