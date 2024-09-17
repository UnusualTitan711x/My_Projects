#include <stdio.h>

char grid[10];
char P1 = 'X';
char P2 = 'O';
int finished = 0;

void ShowGrid();
void ShowGridPositions();
void FillGrid();
void Play(char p, int pos);

int IsAvailable(int pos);
int AreSame(int x, int y, int z, char p);
int HasWon(char p);

int main()
{
    char player1name[25], player2name[25];
    int plr1_turn, plr2_turn;
    int turnsCount = 0;
    int blankSpaces = 9;

    printf("Player 1 name (X): ");
    scanf("%s", player1name);
    printf("Player 2 name (0): ");
    scanf("%s", player2name);

    printf("The following grid shows the different positions to play.\n");
    printf("You type in the number corresponding to the position you want to play in.\n");

    ShowGridPositions();
    FillGrid();

    while (!finished)
    {

        if((turnsCount%2) == 0) // Player 1
        {
            do
            {
                printf("%s's turn: ", player1name);
                scanf("%d", &plr1_turn);
            } while (IsAvailable(plr1_turn));
            
            printf("\n");

            Play(P1, plr1_turn);

            blankSpaces--;
            turnsCount++;
            
            ShowGrid();
            
            if(HasWon(P1))
            {
                printf("%s won!\n", player1name);
                finished = 1;
                break;
            }
            else if (blankSpaces == 0)  
            {
                printf("TIE!\n");
                finished = 1;
                break;
            }
            
        }

        if((turnsCount%2) == 1) // Player 2
        {
            do
            {
                printf("%s's turn: ", player2name);
                scanf("%d", &plr2_turn);
            } while (IsAvailable(plr2_turn));
            
            printf("\n");
            
            Play(P2, plr2_turn);
            
            blankSpaces--;
            turnsCount++;
            
            ShowGrid();

            if(HasWon(P2))
            {
                printf("%s won!\n", player2name);
                finished = 1;
                break;
            }
            else if (blankSpaces == 0)  
            {
                printf("TIE!\n");
                finished = 1;
                break;
            }
        }             
    }
    
}

void ShowGrid()
{
    printf(" %c | %c | %c \n", grid[1], grid[2], grid[3]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", grid[4], grid[5], grid[6]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", grid[7], grid[8], grid[9]);
}

void ShowGridPositions()
{
    printf(" 1 | 2 | 3 \n");
    printf("---+---+---\n");
    printf(" 4 | 5 | 6 \n");
    printf("---+---+---\n");
    printf(" 7 | 8 | 9 \n");
}

void FillGrid()
{
    for(int i = 0; i < 10; i++)
    {
        grid[i] = ' ';
    }
}

int AreSame(int x, int y, int z, char p)
{
    if(grid[x] == p && grid[y] == p && grid[z] == p) 
        return 1;
    return 0;
}

int HasWon(char p)
{
    if(
        AreSame(1,2,3,p) ||
        AreSame(4,5,6,p) ||
        AreSame(7,8,9,p) ||
        AreSame(1,5,7,p) ||
        AreSame(2,5,8,p) ||
        AreSame(3,6,9,p) ||
        AreSame(1,5,9,p) ||
        AreSame(3,5,7,p) 
    )
    {
        return 1;
    }
    else return 0;
}

void Play(char p, int pos)
{
    grid[pos] = p;
}

int IsAvailable(int pos)
{
    if(grid[pos] != ' ') return 1;
    else return 0;
}