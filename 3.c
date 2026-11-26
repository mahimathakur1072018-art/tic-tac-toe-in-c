3. PRACTICAL — TIC-TAC-TOE
#include <stdio.h>

void displayBoard(char board[3][3])
{
    printf("\n");

    printf(" %c | %c | %c\n",
           board[0][0], board[0][1], board[0][2]);

    printf("---|---|---\n");

    printf(" %c | %c | %c\n",
           board[1][0], board[1][1], board[1][2]);

    printf("---|---|---\n");

    printf(" %c | %c | %c\n",
           board[2][0], board[2][1], board[2][2]);

    printf("\n");
}

int checkWinner(char board[3][3])
{
    int i;

    /* Check rows */
    for (i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
        {
            return 1;
        }
    }

    /* Check columns */
    for (i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
        {
            return 1;
        }
    }

    /* Check first diagonal */
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
    {
        return 1;
    }

    /* Check second diagonal */
    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
    {
        return 1;
    }

    return 0;
}

int main()
{
    char board[3][3] =
    {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    int choice;
    int row;
    int column;
    int turn;
    int moves;
    char player;
    int gameOver;

    turn = 0;
    moves = 0;
    gameOver = 0;

    printf("===== TIC-TAC-TOE GAME =====\n");

    while (gameOver == 0 && moves < 9)
    {
        displayBoard(board);

        if (turn % 2 == 0)
            player = 'X';
        else
            player = 'O';

        printf("Player %c, enter position (1-9): ", player);
        scanf("%d", &choice);

        if (choice < 1 || choice > 9)
        {
            printf("Invalid position! Try again.\n");
            continue;
        }

        row = (choice - 1) / 3;
        column = (choice - 1) % 3;

        if (board[row][column] == 'X' ||
            board[row][column] == 'O')
        {
            printf("Position already taken! Try again.\n");
            continue;
        }

        board[row][column] = player;

        moves++;

        if (checkWinner(board))
        {
            displayBoard(board);

            printf("Player %c wins!\n", player);

            gameOver = 1;
        }
        else
        {
            turn++;
        }
    }

    if (gameOver == 0)
    {
        displayBoard(board);
        printf("The game is a draw!\n");
    }

    return 0;
}