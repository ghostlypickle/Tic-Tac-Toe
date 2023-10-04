#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

void move(char* board, unsigned short position, const bool player){
    if(position < 1 || position > 9 || board[position - 1] == 'X' || board[position - 1] == 'O'){
        do{
            printf("Invalid position, enter a new one:\n");
            int new_position;
            scanf("%u", &new_position);
            position = new_position;

        } while (position < 1 || position > 9 || board[position] == 'X' || board[position] == 'O');
    }
    char symbol = player ? 'X' : 'O';
    board[position - 1] = symbol;
}

void print_board(char* board){
    printf("  %c |  %c | %c\n",board[0],board[1],board[2]);
    printf("    |    |    \n");
    printf("----|----|----\n");
    printf("    |    |    \n");
    printf("  %c |  %c | %c\n",board[3],board[4],board[5]);
    printf("    |    |    \n");
    printf("----|----|----\n");
    printf("  %c |  %c | %c\n",board[6],board[7],board[8]);
    printf("    |    |    \n");
}

bool check_for_win(char* board, bool player){
    char type = player ? 'X' : 'O';
    for (size_t i = 2; i < 9; i += 3) {
        if (board[i - 2] == type && board[i - 1] == type && board[i] == type) {
            return true;
        }
    }

    for (size_t i = 0; i < 3; ++i) {
        if (board[i] == type && board[i + 3] == type && board[i + 6] == type) {
            return true;
        }
    }

    if (board[0] == type && board[4] == type && board[8] == type) {
        return true;
    }

    if (board[2] == type && board[4] == type && board[6] == type) {
        return true;
    }

    return false;
}

void rules()
{
    printf("\tTic-Tac-Toe\n\n");
    printf("Welcome to the most played 2D game and a sort of fun using X and O\n\n");
    printf("Rules:-\n");
    printf("\n1:Each player will be entering the number to put respective X or O in the desired position");
    printf("\n2:Player who gets a combination of 3 same characters either diagonal or horizontally or \n  vertically will be declared as the winner");
    printf("\n3:When choosing the position in which you want to put X or O you must declare the row and column of that position\n");
}

bool is_board_full(char* board){
    for(size_t i = 1; i <= 9; ++i){
        if(board[i - 1] == '0' + i) return false;
    }

    return true;
}

int main() {
    rules();
    char* board = (char*) malloc(sizeof(char) * 9);
    for(size_t i = 1; i <= 9; ++i){
        board[i - 1] = '0' + i;
    }
    while(!is_board_full(board)){
        print_board(board);
        printf("Player 1 chooses position : ");
        size_t position1;
        scanf("%u", &position1);
        printf("\n");
        move(board,position1,false);
        print_board(board);
        if(check_for_win(board,false)){
            printf("Player 1 wins!!!\n");
            break;
        }

        print_board(board);
        printf("Player 2 chooses position : ");
        size_t position2;
        scanf("%u", &position2);
        printf("\n");
        move(board,position2,true);
        print_board(board);
        if(check_for_win(board,true)){
            printf("Player 2 wins!!!\n");
            break;
        }
    }

    if(check_for_win(board,false) == false && check_for_win(board,true) == false){
        printf("Stalemate\n");
    }
    free(board);

    return 0;
}
