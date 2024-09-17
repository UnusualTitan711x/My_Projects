#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

const int fee = 150;
int op, language, pin, acc, amt, AccNo, i, j;
long long card;
char addressATM[30]="ATM No 2 MENDONG YAOUNDE CM";
long long Account[5][3]={{1001774536873456,1101,55000},{1001763422348675,2451,1145500},{1001765523663458,6555,55500},{1001760023956445,2311,12454},{1001754400856749,4410,452370}};
char Customer[5][20]={"NGANFOR JESPA","NGALA MELVIN","PAUL IGAHA","HELENE AYUK","NGALAME YVONNE"};
char Tel[5][20]={"+237679376440","+237651146555","+234777777775","+123423567894","+237651237878"},phone[20];
bool valid = false;
char ans[3];
char CustomerName[20];
int countPin = 3;
int TransNo, No;

bool iscorrectamt(int amt)
{
	//check if the amount entered is not more than the balance
	//balance = GetBalance(pin);
	if (amt > GetBalance())
	{
		return false;
	}
	else
		return true;
}

void Withdraw()
{
	time_t t;
	time(&t);
	TransNo = (rand() % 999999) + 100000;
	No = (rand() % 999) + 100;
	
	if (language == 1)
	{
		//INSERT ENGLISH VERSION OF THE MENU AS SHOWN IN THE DIAGRAM FOR WITHDRWAL
	}
	else
	{
		//INSERT FRENCH VERSION OF WITHDRAWAL MENU
	}
	
	system("cls");
	
	switch(op)
	{
		//INSERT VARIOUS CASES FOR AMOUNT ENTERED OR CHOOSEN
		
		
	}
	//check the amount entered if superior to account balance
	
	if (!iscorrectamt(amt))
	{
		if (language == 1)
			printf("Sorry, Insufficient Funds.\n");
		else
			printf("Desole, Solde Insuffisant.\n");
			
		Display();
	}
	else
	{
		//withdraw the money
		for (i=0;i<5;i++)
		{
			//GET THE POSITION OF THE CUSTOMER'S NAME AND ACCOUNT NO USING A CONDITIONAL STATEMENT 
			//if pin equal to any pin in the Account array
			{
				//ASSIGN THE NEW BALANCE WHICH IS AVAILABLE BALANCE - AMT - FEE
				
				//ASSIGN ACCOUNT NO TO card
				
				//ASSIGN CUSTOMER'S NAME TO CustomerName 
				
			}
				
		}
		if (language == 1)
			printf("\nDo you want a receipt?(Yes/No):");
		else
			printf("\nVoulez vous un recu?(Oui/Non):");
		scanf("%s",ans);
		//if ans == "Yes" or "Oui" print the follows transaction receipt
		if(strcmp(ans,"Yes"))
		{
			system("cls");
			if (language == 1)
			{
				printf("\n----------------------------------------------------------\n");
				printf("\n\t\t   ATM TRANSACTION\n");
				printf("\n----------------------------------------------------------\n");
				printf("\tTERMINAL #\t\t%d\n",TransNo);
				printf("\tSEQNUM #\t\t%d\n",No);
				printf("\tDATE\t\t\t%s\n",ctime(&t));
				printf("\t%s\n\n",addressATM);
				printf("\tCARD NUMBER\t\tXXXXXXXXXXXX%lld\n",card%10000);
				printf("\tCUSTOMER NAME\t\t%s\n\n",CustomerName);
				printf("\tAMOUNT REQUESTED\t%d XAF\n",amt);
				printf("\tFEE\t\t\t%d XAF\n",fee);
				printf("\tACCOUNT BALANCE\t\t%d XAF\n",GetBalance(pin));
				printf("\n      PLEASE RETAIN OR DISPOSE OF THOUGHTFULLY\n");
				printf("\n----------------------------------------------------------\n");
			}
			else
			{
				printf("\n----------------------------------------------------------\n");
				printf("\n\t\t  OPERATION GAB\n");
				printf("\n----------------------------------------------------------\n");
				printf("\tTERMINAL #\t\t%d\n",TransNo);
				printf("\tSEQNUM #\t\t%d\n",No);
				printf("\tDATE\t\t\t%s\n",ctime(&t));
				printf("\t%s\n\n",addressATM);
				printf("\tNUMERO CARTE\t\tXXXXXXXXXXXX%lld\n",card%10000);
				printf("\tNOM CLIENT\t\t%s\n\n",CustomerName);
				printf("\tMONTANT RETRAIT\t\t%d XAF\n",amt);
				printf("\tFRAIS\t\t\t%d XAF\n",fee);
				printf("\tSOLDE\t\t\t%d XAF\n",GetBalance(pin));
				printf("\n      SVP, VOUS POUVEZ GARDE LE RECU OU LE DISPOSE\n");
				printf("\n----------------------------------------------------------\n");
			}
			
		}			
		else
			printf("\n   THANKS FOR YOUR VISIT\n");
	}	
}

int Display()
{

	
}

bool iscorrectpin()
{
	for (i=0;i<5;i++)
	{
		if (pin == Account[i][1])
		{
			j = i;
			valid = true;
		}
	}
	return valid;
}

void English()
{
	
}

void French()
{
	
}

int PrintBalance()
{
	
}

int GetBalance()
{
	
}

bool iscorrectacc(int accno)
{
	for (i=0;i<5;i++)
	{
		if (accno == Account[i][0])
		{
			j = i;
			valid = true;
		}	
	}
	return valid;
}

int main ()
{
	srand(time(0));
	
	//INSERT LANGUAGE MENU HERE 
		

	
	return 0;
}
