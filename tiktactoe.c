#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Global Variables
#define PLAYER1 1
#define PLAYER2 2
char boardArr[10] = {'0','1','2','3','4','5','6','7','8','9'}; // Use position 1 - 9
int choice;
char player;
bool gameover = 0;

// Function Prototypes
void drawBoard();
void drawCurrentBoard();
bool checkForWin();
void markBoard(char);
void refreshBoard(); // clears system and redraws current board state
void drawHeader();
int askNumber();


int main(){
    drawHeader();
    drawBoard();
    
    // mark variable
    char mark;

    // Player 1 goes first
    player = PLAYER1;

    while (1){
        choice = askNumber();
        mark = (player == PLAYER1) ? 'X' : 'O';
        markBoard(mark);
        
        // refresh the board
        refreshBoard();

        // Check if a player has won
        gameover = checkForWin();
        if (gameover == 1){
            printf("\nGame over, Player %d wins \n", player);
            break;
        }

        // Change turns
        player = (player == PLAYER1) ? PLAYER2 : PLAYER1;  
    }

    printf("\n\n"); 
    return 0;
}

void drawBoard(){ 
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", boardArr[1], boardArr[2], boardArr[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", boardArr[4], boardArr[5], boardArr[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", boardArr[7], boardArr[8], boardArr[9]);
    printf("     |     |     \n");

}

void drawHeader(){
    printf("\n\tTic Tac Toe \t\n\n");
    printf("Player 1 (X) - Player 2(O)\n\n");

}

int askNumber(){
    printf("\nPlayer %d, enter a number: ", player); 
    int Number; 
    scanf("%d", &Number);

    // Check if number in bounds
    while (Number > 9 || Number < 1){
        refreshBoard();
        printf("\nInvalid number Player %d, try again: ", player);
        scanf("%d",&Number);
    }
    // Check for illegal mark
    while(boardArr[Number] == 'X' || boardArr[Number] == 'O'){
        refreshBoard();
        printf("\nInvalid number Player %d, try again: ", player);
        scanf("%d",&Number);
    }

    return Number;
}

void markBoard(char mark){
    // Mark the board
    boardArr[choice] = mark;
    
}

void refreshBoard(){
    system("clear");
    drawHeader();
    drawBoard(); 
}

bool checkForWin(){
    if (boardArr[1] == 'X' && boardArr[2] == 'X' && boardArr[3] == 'X'){
       return 1; 
    }
    else if (boardArr[4] == 'X' && boardArr[5] == 'X' && boardArr[6] == 'X'){
       return 1; 
    }
    else if (boardArr[7] == 'X' && boardArr[8] == 'X' && boardArr[9] == 'X'){
       return 1; 
    }
    else if (boardArr[1] == 'X' && boardArr[4] == 'X' && boardArr[7] == 'X'){
       return 1; 
    }
    else if (boardArr[2] == 'X' && boardArr[5] == 'X' && boardArr[8] == 'X'){
       return 1; 
    }
    else if (boardArr[1] == 'X' && boardArr[5] == 'X' && boardArr[9] == 'X'){
       return 1; 
    }
    else if (boardArr[7] == 'X' && boardArr[5] == 'X' && boardArr[3] == 'X'){
       return 1; 
    }
    else if (boardArr[3] == 'X' && boardArr[6] == 'X' && boardArr[9] == 'X'){
       return 1; 
    }
    else if (boardArr[1] == 'O' && boardArr[2] == 'O' && boardArr[3] == 'O'){
       return 1; 
    }
    else if (boardArr[4] == 'O' && boardArr[5] == 'O' && boardArr[6] == 'O'){
       return 1; 
    }
    else if (boardArr[7] == 'O' && boardArr[8] == 'O' && boardArr[9] == 'O'){
       return 1; 
    }
    else if (boardArr[1] == 'O' && boardArr[4] == 'O' && boardArr[7] == 'O'){
       return 1; 
    }
    else if (boardArr[2] == 'O' && boardArr[5] == 'O' && boardArr[8] == 'O'){
       return 1; 
    }
    else if (boardArr[1] == 'O' && boardArr[5] == 'O' && boardArr[9] == 'O'){
       return 1; 
    }
    else if (boardArr[7] == 'O' && boardArr[5] == 'O' && boardArr[3] == 'O'){
       return 1; 
    }
    else if (boardArr[3] == 'O' && boardArr[6] == 'O' && boardArr[9] == 'O'){
       return 1; 
    }
    else{
        return 0;
    }
}


