#include <stdio.h>
#include <stdlib.h>
//Defining struct to hold various variables.
struct customers_info 
{
	char tc_id[12];
	char name[50];
	char surname[50];
	int  account_number;
	double account_balance;
	int currency;
};
int customer_count=0;
struct customers_info customers[5000];

//Function prototype
void menu();
void new_customer();
void update_account();
void account_closure();
void account_inquiry();
void account_listing();
void transfer_money();
void save_customers();
void load_customers();
int main()
{
	load_customers(); 
	int checkexit=1;
	do
	{
	int opnumber;
	menu();
	printf("\nPlease enter the number (1-6) for the operation you want to perform:");
	scanf("%d",&opnumber);
	switch(opnumber)
	{
		case 0: checkexit=0; break;
		case 1: new_customer(); save_customers(); break;
		case 2: update_account(); save_customers(); break;
		case 3: account_closure(); save_customers(); break;
		case 4: account_inquiry(); save_customers(); break;
		case 5: account_listing(); save_customers(); break;
		case 6: transfer_money();  save_customers();break;
		default: printf("\nInvalid value.\n\n"); break;
	}
	
	
}while(checkexit!=0);

	return 0;
}
//The menu function for users to choose.
void menu()
{
	printf("\n1.Create New Customer Account\n");
	printf("2.Account Update\n");
	printf("3.Account Closure\n");
	printf("4.Account Inquiry\n");
	printf("5.Account Listing\n");
	printf("6.Money Transfer\n");
	printf("Press 0 to exit\n");	
}
//The new_customer function obtains information from the user and allows to open a new account.
void new_customer()
{
	FILE *file;
	int check;
	int currency1;
	int exitcheck=1;
	while(exitcheck!=0)
	{
		if(customer_count<=5000)
		{
		printf("\nPlease enter your name:");
		scanf("%s",customers[customer_count].name);
		printf("Please enter your surname:");
		scanf("%s",customers[customer_count].surname);
		printf("Please enter your TC ID number:");
		scanf("%s",customers[customer_count].tc_id);
		printf("Please enter a new 8 digit account number:");
		scanf("%d",&customers[customer_count].account_number);
		printf("Please enter your account balance:");
		scanf("%lf",&customers[customer_count].account_balance);
		printf("1.TRY\n");
		printf("2.USD\n");
		printf("3.EUR\n");
		printf("Please choose your currency!(1-3):");
		scanf("%d",&currency1);
		switch(currency1)
		{
			case 1: customers[customer_count].currency=1; break;
			case 2: customers[customer_count].currency=2; break;
			case 3:	customers[customer_count].currency=3; break;
		}
		printf("\nYou have successfully created a new account.\n");
		printf("\nPress'0'to return menu or Press '1' to create account receipt:");
		scanf("%d",&check);
				switch(check)
				{
				case 0: exitcheck=0; break;
				case 1: file=fopen("account_receipt.txt","a");
				if(file==NULL)
				{
				printf("\nError opening file.\n");
				exitcheck=0;
				break;
				}
				//Writing receipt for creating account.
				if(customers[customer_count].currency==1)
				{
				fprintf(file,"Name:%s Surname:%s TC ID:%s Account Number:%d Account Balance:%.3lf Currency:TRY\n",customers[customer_count].name,customers[customer_count].surname,customers[customer_count].tc_id,customers[customer_count].account_number,customers[customer_count].account_balance);			
				}
				if(customers[customer_count].currency==2)
				{
				fprintf(file,"Name:%s Surname:%s TC ID:%s Account Number:%d Account Balance:%.3lf Currency:USD\n",customers[customer_count].name,customers[customer_count].surname,customers[customer_count].tc_id,customers[customer_count].account_number,customers[customer_count].account_balance);
		    		
				}
				if(customers[customer_count].currency==3)
				{
				fprintf(file,"Name:%s Surname:%s TC ID:%s Account Number:%d Account Balance:%.3lf Currency:EUR\n",customers[customer_count].name,customers[customer_count].surname,customers[customer_count].tc_id,customers[customer_count].account_number,customers[customer_count].account_balance);
		    				
				}
				fclose(file);
				printf("\nAccount receipt created successfully.\n");
				exitcheck=0;
	 			break;	 						
				default: printf("\nInvalid value."); break;							 	
				}
				while(check!=0 && check!=1)
				{
					printf("\n\nYou are returning to the menu!\n");
					exitcheck=0;
				}

	customer_count++;
	
	}	
	}
}
//The update_function allows user to update their information.
void update_account()
{
	int currency1;
	int i;
	int checknumber;
	int exitcheck2=1;
	int checkcorrect=1;
	while(exitcheck2!=0)
	{
	printf("\nPlease enter your account number:");
	scanf("%d",&checknumber);
	for(i=0;i<=customer_count;i++)
	{
		if(customers[i].account_number==checknumber){
		printf("\nPlease enter new name:");
		scanf("%s",customers[i].name);
		printf("Please enter new surname:");
		scanf("%s",customers[i].surname);
		printf("Please enter new TC ID number:");
		scanf("%s",customers[i].tc_id);
		printf("Please enter a new 8 digit account number:");
		scanf("%d",&customers[i].account_number);
		printf("Please enter new account balance:");
		scanf("%lf",&customers[i].account_balance);
		printf("1.TRY\n");
		printf("2.USD\n");
		printf("3.EUR\n");
		printf("Please choose your new currency(1-3):");
		scanf("%d",&currency1);
		switch(currency1){
			case 1: customers[i].currency=1; break;
			case 2: customers[i].currency=2; break;
			case 3:	customers[i].currency=3; break;
		}
		printf("\nYou have successfully updated your account information.\n");
		checkcorrect=0;	
		printf("\nPress '0' to return menu:");
		scanf("%d",&exitcheck2);
		break;	
		}	
	}
	//The situation of entering the user account number incorrectly.
	if(checkcorrect!=0)
	{
		printf("\nYou entered it incorrectly\n");
		printf("\nPress '0' to return menu or Press '1' to try again:");
		scanf("%d",&exitcheck2);
	}
}
}
//The account_closure function allows users to close their accounts.
void account_closure()
{
	FILE *file;
	int check;
	int exitcheck3=1;
	int checkcorrect3=0;
	int checknumber2;
	int i,j;
	while(exitcheck3!=0)
	{
		printf("\nPlease enter the number of the account you want to close:");
		scanf("%d",&checknumber2);
		for(i=0;i<=customer_count;i++){
			if(checknumber2==customers[i].account_number){
			printf("\nAccount was closed successfully.\n");
			printf("\nPress '0' to return menu or Press '1' to create account closing receipt:");
			scanf("%d",&check);
			switch (check){
				case 0: exitcheck3=0; break;
				case 1: file=fopen("account_closing_receipt.txt","a");
						if(file==NULL){
						printf("\nError opening file.\n");
						exitcheck3=0;
						break;
						}
						//Writing receipt for closing account.
						fprintf(file,"Name:%s Surname:%s Account Number:%d || Account was closed successfully.\n",customers[i].name,customers[i].surname,customers[i].account_number);
						printf("\nClosing receipt created successfully.\n");
						exitcheck3=0;
						break;		
			}
				for(j=i;j<=customer_count;j++)
				{
					 customers[j]=customers[j+1];
			
		}
		
			checkcorrect3=1;
			customer_count--;
		}

		}
	//The situation of entering the user account number incorrectly.
	if(checkcorrect3==0)
	{
      printf("\nThis account is not found!\n");
      printf("\nPress '0' to return menu or Press '1' to try again:");
      scanf("%d",&exitcheck3);
	}
	}

	
}
//The account_inquiry function shows account details for a user. 
void account_inquiry()
{
	int checkcorrect2=1;
	int exitcheck4=1;
	int i;
	int checknumber3;
	while(exitcheck4!=0)
	{
		printf("\nPlease enter your account number:");
		scanf("%d",&checknumber3);
		for(i=0;i<=customer_count;i++)
		{
			if(checknumber3==customers[i].account_number){
				printf("\nName:%s\n",customers[i].name);
				printf("Surname:%s\n",customers[i].surname);
				printf("TC ID:%s\n",customers[i].tc_id);
				printf("Account Number:%d\n",customers[i].account_number);
				printf("Account Balance:%.3lf\n",customers[i].account_balance);
			if(customers[i].currency==1)
			{
				printf("Currency:TRY\n");
			}
			if(customers[i].currency==2)
			{
				printf("Currency:USD\n");
			}
			if(customers[i].currency==3)
			{
				printf("Currency:EUR\n");
			}
				printf("\nPress '0' to return menu:");
				scanf("%d",&exitcheck4);
				checkcorrect2=0;
			}
			}
		//The situation of entering the user account number incorrectly.	
		if(checkcorrect2!=0)
		{
				printf("\nThis account is not found!\n\n");
				printf("Press '0' to return menu or Press '1'to try again:");
				scanf("%d",&exitcheck4);
		}		
		}	
	}
	//The account_listing function allows listing of users in the bank.
	void account_listing()
	{
		
		int i;
		int exitcheck5=1;
		while(exitcheck5!=0)
		{
		for(i=0;i<customer_count;i++){
			printf("\n");
			printf("    %d.	Name:%s\n",i+1,customers[i].name);
			printf("	Surname:%s\n",customers[i].surname);
			printf("	TC ID:%s\n",customers[i].tc_id);
			printf("	Account Number:%d\n",customers[i].account_number);
			printf("	Account Balance:%.3lf\n",customers[i].account_balance);
			if(customers[i].currency==1)
			{
				printf("	Currency:TRY\n");
			}
			if(customers[i].currency==2)
			{
				printf("	Currency:USD\n");
			}
			if(customers[i].currency==3)
			{
				printf("	Currency:EUR\n");
			}
	}
		printf("\nPress '0' to return menu or Press '1' to see list again:");
		scanf("%d",&exitcheck5);
		//The situation is user does not press 0 or 1.
		while(exitcheck5!=0 && exitcheck5!=1)
		{
			printf("Invalid value.Press '0' to return menu or Press '1' to see list again:");
			scanf("%d",&exitcheck5);
		}	
	
	}
}
//The transfer_money function allows users to transfer money to each other.
void transfer_money()
{
	FILE *file1;
	int check;
	int checkcorrect1=0;
	int checkcorrect=0;
	int exitcheck=1;
	double transfermoney;
	int checknumber;
	int checknumber1;
	int i,j;
	while(exitcheck!=0){
	
	printf("\nPlease enter your account number:");
	scanf("%d",&checknumber);
	for(i=0;i<=customer_count;i++)
	{
		if(checknumber==customers[i].account_number)
		{
			checkcorrect1=1;
			printf("\nAccount Information\n\n");
			printf("Name:%s\n",customers[i].name);
			printf("Surname:%s\n",customers[i].surname);
			printf("Account Balance:%.3lf\n",customers[i].account_balance);
			if(customers[i].currency==1)
			{
		    	printf("Currency:TRY\n\n");
			}
			if(customers[i].currency==2)
			{
				printf("Currency:USD\n\n");
			}
			if(customers[i].currency==3)
			{
				printf("Currency:EUR\n\n");
			}
			printf("Please enter the account number of the account to which the money will be sent:");
			scanf("%d",&checknumber1);
			printf("\nPlease enter the amount of money.(You can send whatever your currency is.):");
			scanf("%lf",&transfermoney);
			if(transfermoney<=customers[i].account_balance){
			
			for(j=0;j<=customer_count;j++)
			{
				if(checknumber1==customers[j].account_number)
					{
					customers[i].account_balance=customers[i].account_balance-transfermoney;
					if(customers[j].currency==1)
					{
						
						switch(customers[i].currency)
						{
						case 1: customers[j].account_balance=customers[j].account_balance+transfermoney; break;	
						case 2:	customers[j].account_balance=customers[j].account_balance+(35.16*transfermoney); break;
						case 3: customers[j].account_balance=customers[j].account_balance+(36.63*transfermoney); break;		
						}
						
					}
					if(customers[j].currency==2)
					{
						switch(customers[i].currency)
						{
						case 1: customers[j].account_balance=customers[j].account_balance+(transfermoney/35.16); break;	
						case 2:	customers[j].account_balance=customers[j].account_balance+transfermoney; break;
						case 3: customers[j].account_balance=customers[j].account_balance+(1.04*transfermoney); break;		
						}
						
					}
					if(customers[j].currency==3)
					{
						switch(customers[i].currency)
						{
						case 1: customers[j].account_balance=customers[j].account_balance+(transfermoney/36.63); break;	
						case 2:	customers[j].account_balance=customers[j].account_balance+(transfermoney/1.04); break;
						case 3: customers[j].account_balance=customers[j].account_balance+transfermoney; break;		
						}
					}
					checkcorrect=1;
					printf("\nThe money was sent successfully!\n");
					printf("\nPress '0' to return menu or Press '1' to create money transfer receipt:");
					scanf("%d",&check);
					switch(check)
					{
					case 0: exitcheck=0; break;
					case 1: file1=fopen("transfer_money.txt","a");
							if(file1==NULL)
							{
								printf("Error opening file.\n");
								exitcheck=0;
								break;
							}
							//Writing money transfer receipt.
							if(customers[i].currency==1)
							{
		    				fprintf(file1,"Transferred money:%.3lf TRY from %s %s to %s %s||Remaining amount:%.3lf TRY\n",transfermoney,customers[i].name,customers[i].surname,customers[j].name,customers[j].surname,customers[i].account_balance);
							}
							if(customers[i].currency==2)
							{
							fprintf(file1,"Transferred money:%.3lf USD from %s %s to %s %s||Remaining amount:%.3lf USD\n",transfermoney,customers[i].name,customers[i].surname,customers[j].name,customers[j].surname,customers[i].account_balance);
							}
							if(customers[i].currency==3)
							{
							fprintf(file1,"Transferred money:%.3lf EUR from %s %s to %s %s||Remaining amount:%.3lf EUR\n",transfermoney,customers[i].name,customers[i].surname,customers[j].name,customers[j].surname,customers[i].account_balance);
							}
							fclose(file1);
							printf("\nMoney transfer receipt created successfully.\n");
							exitcheck=0;
	 						break;
					default: printf("\nInvalid value.\n"); break;	
								 	
					}
					while(exitcheck!=0 && exitcheck!=1)
					{
							printf("\n\nYou are returning to the menu!\n");
							exitcheck=0;
					}
					
				}
			}
				
				
				
			}
			//The situation of entering the user account number incorrectly or money is not enough.
			if(checkcorrect==0)
				{
					printf("\nThe account you want to send money that is not exist or your money is not enough please check!\n");
					printf("\nPress '0' to return menu:");
					scanf("%d",&exitcheck);
					
					while(exitcheck!=0)
					{
						printf("Invalid value.Press '0' to return menu:");
						scanf("%d",&exitcheck);
					}
				}	
			
		}

			}
			//The situation of entering the user account number incorrectly.
			if(checkcorrect1==0)
			{
			printf("\nThis account is not found!\n");
			printf("\nPress '0' to return menu or Press '1'to try again:");
			scanf("%d",&exitcheck);
			}
	
			}
		}

//The save_customers function saves all customer information to a text file.		
void save_customers() 
{
	int i;
    FILE *file=fopen("customers.txt","w");
    if(file==NULL) 
	{
        printf("Error opening file.\n");
        return;
    }

    for(i=0;i<customer_count;i++) 
	{
        fprintf(file,"%s %s %s %d %3lf %d\n",customers[i].name,customers[i].surname,customers[i].tc_id,customers[i].account_number,customers[i].account_balance,customers[i].currency);
    }
    fclose(file);
}
//The load_customers function loads customer information from a text file.
void load_customers()
{
	FILE *file=fopen("customers.txt","r");
    if(file==NULL) 
	{ 
        return;
    }

    while(fscanf(file,"%s %s %s %d %lf %d",customers[customer_count].name,customers[customer_count].surname,customers[customer_count].tc_id,&customers[customer_count].account_number,&customers[customer_count].account_balance,&customers[customer_count].currency) == 6) {
        customer_count++;
        if(customer_count>=5000)
		{
            break;
        }
    }

    fclose(file);
}










