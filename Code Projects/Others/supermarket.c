#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item
{
    char name[20];
    int qty;
    int price;
}item;

item NewItem(char name[], int qty, int price);

int main()
{
    item biscuit = NewItem("Biscuit", 0, 50);
    int done = 0;
    int choice;

    printf(" %s, %d, %d.\n", biscuit.name, biscuit.price, biscuit.qty); 

    printf("Welcome to <name> Supermarket.\n");
    printf("Here are the available products.\n");
    printf("Item\tUnit Ptice.\n");
    printf("1. ParleG\t25F\n2. Juice\t350F\n3. Mambo\t200F\n4. Chips\t100F\n");
    printf("You have 1000F to buy any items you want in the store.\n");

    do
    {
        do
        {
            printf("What do you want to buy? \n");
            scanf("%d", &choice);
        } while (choice > 5 || choice < 1);
        
    } while (!done);
    
}

item NewItem(char name[], int qty, int price)
{
    item i;
    strcpy(i.name, name);
    i.price = price;
    i.qty = qty;

    return i;
}