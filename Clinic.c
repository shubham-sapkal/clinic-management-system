#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

struct patient
{
	char name[20], gender[6], complaint[50], diagnosis[20], prescription[20];
	int age,appointment;
	struct patient *next;
};


int count=0, d=1;


struct patient *start=NULL;

struct patient *new_patient(struct patient *start);
struct patient *display(struct patient *start);
struct patient *display_pre(struct patient *start);
struct patient *insert_app(struct patient *start);


int genereateApp();

void doctor();
void Appointer();
void check_user(char username[10], char password[10]);
struct patient *next_ap(struct patient *start);



void main()
{
	char password[10], username[10], ch;
	int i, option;

	system("cls");

	printf("Enter User name: ");
	scanf("%s",username);

	printf("Enter the password : ");

	for(i=0;i<7;i++)
	{
		ch = getch();
		password[i] = ch;
		ch = '*' ;
		printf("%c",ch);
	}

	password[i] = '\0';

	check_user(username, password);

	getch();

}

// Increasing number of appointment
int genereateApp()
{
	return count++;
}

// Addition new Patient as node
struct patient *new_patient(struct patient *start)
{
	int age,n,val, y;
	char name[20], gender[6], diagnosis[20],complaint[50],temp;
	struct patient *new_node, *ptr;
	new_node=(struct patient *)malloc(sizeof(struct patient));

	system("cls");
	printf("\nEnter Age: ");
	scanf("%d",&age);
	
	printf("\nEnter Name: ");
	while ((getchar()) != '\n');
	scanf("%s",name);

	printf("\nPress the desired key for Gender\n 1. Male\t 2. Female\t 3. Other: ");
	scanf("%d",&n);
	if(n==1)
		strcpy(gender,"Male");
	else if(n==2)
		strcpy(gender,"Female");
	else
		strcpy(gender,"Other");

	printf("\nPatient's Complaint: ");
	scanf("%s",&complaint);

	new_node=(struct patient *)malloc(sizeof(struct patient));
	strcpy(new_node->name,name);
	strcpy(new_node->gender,gender);
	strcpy(new_node->complaint,complaint);
	new_node->age=age;

	printf("\nPress 1. To insert the person in the appointment list else press 2: ");
	scanf("%d",&y);
	if(y==1) {
		val=genereateApp();
		new_node->appointment=val;   
	}
	else{
		new_node->appointment=0;
	}



	if(start==NULL)
	{
		new_node->next=NULL;
		start=new_node;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
			ptr=ptr->next;

		ptr->next=new_node;
		new_node->next=NULL;

	}




	return start;
}

struct patient *display(struct patient *start)
{
	struct patient *ptr;
	int i=1;
	ptr=start;
	while(ptr!=NULL)
	{
	    printf("\n\nPatient %d",i);
	    if(ptr->appointment!=0)
		{
		    printf("\nAppointment : %d",ptr->appointment);
		}
		printf("\nName: %s",ptr->name);
		printf("\nAge: %d",ptr->age);
		printf("\nGender: %s",ptr->gender);
		printf("\nComplaint: %s",ptr->complaint);
		printf("\nDiagnosis: %s",ptr->diagnosis);


		ptr=ptr->next;
		i++;

	}

    printf("\n\nEnter Any key to move next ... ");
    getch();

	return start;
}

struct patient *display_pre(struct patient *start)
{

	struct patient *ptr;
	int i,n;
	ptr=start;
	printf("Enter appointment No. ");
	scanf("%d",&n);
	if(n<=count)
	{
		while(ptr!=NULL)
		{
			if(ptr->appointment==n)
			{
				printf("%s\t",ptr->prescription);
				break;
			}

		}


	}
	else
	{
		printf("\nINVALID NUMBER\n");
	}

    printf("\n\nEnter Any key to move next ...");
    getch();

	return start;
}


struct patient *insert_app(struct patient *start)
{
	struct patient *ptr;
	char name1[20];
	int val;
	int flag=0;
	printf("Enter the name of the Patient who wants the appointment: ");
	scanf("%s",name1);
	ptr=start;
	while(ptr!=NULL)
	{

		if(strcmp(ptr->name,name1)==0)
		{

			val=genereateApp();
			printf("%d",val);
			ptr->appointment=val;
			flag=1;
			break;
		}
		ptr=ptr->next;
	}
	if(flag==0)
	{
	    printf("\nName Not Found\n");
	}

	return start;
}





struct patient *next_ap(struct patient *start)
{
	struct patient *ptr;
	int p,pre,z;


	ptr=start;

	while(ptr!=NULL)
	{
		if(ptr->appointment==d)
		{
			printf("Name: %s",ptr->name);
			printf("\nAge: %d",ptr->age);
			printf("\nGender: %s",ptr->gender);
			printf("\nComplaint: %s",ptr->complaint);
			printf("\nEnter Diagnosis: ");
			scanf("%s",ptr->diagnosis);
		    printf("Enter Prescription: ");
			scanf("%s",ptr->prescription);
			
			break;

		}
		ptr=ptr->next;

	}
	d++;


	return start;
}


void check_user(char username[10], char password[10])
{
    int n;

	if(strcmp(username, "shubham") == 0  )
    {
	    if(strcmp(password, "default") == 0)
	    {
		   printf("\nWELCOME DR. Shubham\n");
		   doctor();
	    }
    }
    else if(strcmp(username, "Appointer") == 0 )
    {
	    if(strcmp(password, "default") == 0)
	    {
		    printf("\nWELCOME Appointor");
		    Appointer();
	    }

    }
    else
    {
        printf("\nPassword or User ID entered is invalid");
        printf("\nPress 1 to Try AGAIN or press 2 to exit: ");
        scanf("%d",&n);
        if(n==1)
        {
         	main();
        }
        else
        {
         	exit(0);
        }
    }

}


// Login section


// Doctor Login function and works 
void doctor()
{
	int choice;
    system("cls");
	printf(" Welcome !!  DR. Shubham\n");

	do{
        system("cls");
        printf("\n1. View Next Patient\n");
        printf("2. Display Details of the Patient\n");
        printf("3. Log Out\n");
        printf("4. Exit\n");


        printf("\nEnter Your Option: ");
        scanf("%d",&choice);

            switch(choice)
            {
                case 1:
                    start=next_ap(start);
                    break;
                case 2:
                    start=display(start);
                    break;
                case 3:
                    main();
                    break;
                case 4:
                    exit(1);
                    break;
                default:
                    printf("Invalid Choice");
                    system("cls");
                    doctor();
            }
	}while(choice!=4);


}


// A Appointer gives appointment to the Patients 
void Appointer()
{
	int choice;
	do{

    system("cls");
	printf("\n1. Add new Patient\n");
	printf("2. Display Details of the Patient\n");
	printf("3. Assign appointment to existing Patient\n");
	printf("4. Display PRESCRIPTION\n");
	printf("5. Log Out\n");
	printf("6. Exit\n");
	printf("7. patients name\n ");


	printf("\nEnter Your Option: ");
	scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				start=new_patient(start);
				break;
			case 2:
				start=display(start);
				break;
			case 3:
				start=insert_app(start);
				break;
			case 4:
				start=display_pre(start);
				break;
			case 5:
				main();
				break;
			case 6:
				exit(0);
				break;
			case 7 : 
				printf("name = %s",start->name);
				getch();

		}
	}while(choice!=6);
}