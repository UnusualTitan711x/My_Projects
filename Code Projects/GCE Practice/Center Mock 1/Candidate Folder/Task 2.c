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
        
        printf("----------------------------------------------\n\n");
        printf("1. CFA 5000 F\t\t2. CFA 50000 F\n");
        printf("3. CFA 10000 F\t\t4. CFA 100000 F\n");
        printf("5. CFA 20000 F\t\t6. CFA 150000 F\n");
        printf("7. CFA 40000 F\t\t8. OTHER AMOUNT\n\n");
        printf("-----------------------------------------------\n");
        printf("CHOOSE AMOUNT: ");
        scanf("%d", &op);

    }
	else
	{
		//INSERT FRENCH VERSION OF WITHDRAWAL MENU
        printf("----------------------------------------------\n\n");
        printf("1. CFA 5000 F\t\t2. CFA 50000 F\n");
        printf("3. CFA 10000 F\t\t4. CFA 100000 F\n");
        printf("5. CFA 20000 F\t\t6. CFA 150000 F\n");
        printf("7. CFA 40000 F\t\t8. AUTRE MONTANT\n\n");
        printf("-----------------------------------------------\n");
        printf("CHOISSISEZ UN MONTANT: ");
        scanf("%d", &op);
	}
	
	system("cls");
	
	switch(op)
	{
		//INSERT VARIOUS CASES FOR AMOUNT ENTERED OR CHOOSEN
		case 1:
            amt = 5000;
            break;
        case 2:
            amt = 50000;
            break;
        case 3:
            amt = 10000;
            break;
        case 4:
            amt = 100000;
            break;
        case 5:
            amt = 20000;
            break;
        case 6:
            amt = 150000;
            break;
        case 7:
            amt = 40000;
            break;
        case 8:
            if(language == 1)
            {
                printf("Please Enter an Amount: ");
                scanf("%d", &amt);
            }
            else
            {
                printf("Entrez un montant: ");
                scanf("%d", &amt);
            }
            break;
        default:
            printf("Incorrect entry.\n");
			system("pause");	
	}

	//check the amount entered if superior to account balance
	
	if (!iscorrectamt(amt))
	{
		if (language == 1)
		{
			printf("Sorry, Insufficient Funds.\n");
			system("pause");
		}
		else
		{
			printf("Desole, Solde Insuffisant.\n");
			system("pause");
		}	
		Display();
	}
	else
	{
		//withdraw the money
		for (i=0;i<5;i++)
		{
			//GET THE POSITION OF THE CUSTOMER'S NAME AND ACCOUNT NO USING A CONDITIONAL STATEMENT 
			//if pin equal to any pin in the Account array
            if(Account[i][1] == pin)
			{
				//ASSIGN THE NEW BALANCE WHICH IS AVAILABLE BALANCE - AMT - FEE
				Account[i][2] = Account[i][2] - amt - fee;

				//ASSIGN ACCOUNT NO TO card
                card = Account[i][0];
				
				//ASSIGN CUSTOMER'S NAME TO CustomerName 
				strcpy(CustomerName, Customer[i]);
			}
				
		}
		if (language == 1)
			printf("\nDo you want a receipt?(Yes/No):");
		else
			printf("\nVoulez vous un recu?(Oui/Non):");

		scanf("%s",ans);
		//if ans == "Yes" or "Oui" print the follows transaction receipt
		if(strcmpi(ans,"Yes") == 0 || strcmpi(ans, "Oui") == 0)
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
				system("pause");
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
				system("pause");
			}
			
		}			
		else
			printf("\n   THANKS FOR YOUR VISIT\n");
			system("pause");
	}	
}

int Display()
{
	if(language == 1)
	{
		printf("--------- OPERATIONS ----------\n");	
		printf(" 1. CASH WITHDRAWAL\n");
		printf(" 2. BALANCE INQUIRY\n");
		printf(" 3. CANCEL\n");
		printf("-------------------------------\n");
		printf("Which operation do you want to do?\n");
		scanf("%d", &op);
	}
	else if(language == 2)
	{
		printf("--------- OPERATIONS ----------\n");	
		printf(" 1. RETRAIT\n");
		printf(" 2. SOLDE\n");
		printf(" 3. ANNULER\n");
		printf("-------------------------------\n");
		printf("Quel operation voulez vous faire?\n");
		scanf("%d", &op);
	}

	switch(op)
	{
		case 1:
			Withdraw();
			break;
		case 2: 
			PrintBalance();
			break;
		case 3:
			if(language == 1) printf("THANK YOU FOR YOUR VISIT.\n");
			else printf("THANK YOU FOR YOUR VISIT.\n");
			break;
		default:
			if(language == 1) printf("Incorrect.\n");
			else printf("Incorrecte.\n");
			Display();
	}
	
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
	system("cls");

	printf("Please Enter PIN: ");
	scanf("%d", &pin);
	countPin = countPin - 1;

	while (!iscorrectpin() && countPin > 0)
	{
		printf("Incorrect Pin. You have %d attempts(s) left.\n", countPin);
		printf("Please Enter PIN: ");
		scanf("%d", &pin);
		countPin--;
	}
	
	if(iscorrectpin())
	{
		system("cls");
		Display();
	}
	else 
	{
		printf("Your card has been blocked. Contact bank for more details");
		system("pause");
	}	
}

void French()
{
	system("cls");

	printf("Entrez votre PIN s'il vous plait: ");
	scanf("%d", &pin);
	countPin--;

	while (!iscorrectpin() && countPin > 0)
	{
		printf("Pin Incorrecte. Vous avez %d essaie(s).\n", countPin);
		printf("Entrez votre PIN s'il vous plait: ");
		scanf("%d", &pin);
		countPin--;
	}
	
	if(iscorrectpin())
	{
		system("cls");
		Display();
	}
	else 
	{
		printf("Votre carte a ete bloque. Contactez votre banque pour plus de details");
		system("pause");
	}
}

int PrintBalance()
{
	if(language == 1)
    {
        printf("------------------------------------\n");
        printf("\t\tYOUR BALANCE IS %d FCFA\n", Account[j][2]);
        printf("------------------------------------\n");
        printf("Do you want to do another operation?(Yes/No): ");
        scanf("%s", ans);

        if(strcmpi(ans, "Yes") == 0) Display();
        else printf("Thank you for your visit.\n");
    }
    else
    {
        // for french
    }
}

int GetBalance()
{
	for (i = 0; i < 5; i++)
    {
        if(pin == Account[i][1])
        {
            return Account[i][2];
        }
    }
    
    
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
	printf("------ WELCOME ------\n");
	printf(" 1. ENGLISH\n");
	printf(" 2. FRENCH\n");
	printf("---------------------\n\n");
	printf("SELECT LANGUAGE: ");

	scanf("%d", &language);

	switch (language)
	{
	case 1:
		English();
		break;
	case 2:
		French();
		break;
	default:
		break;
	}

	
	return 0;
}
