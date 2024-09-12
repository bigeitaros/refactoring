#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define EMPTY '\0'
#define PLAYER_MARK 'o'
#define ROBOT_MARK 'x'

void displayBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != EMPTY) 
                printf("%c", board[i][j]);
            else 
                printf(" ");
            if (j < BOARD_SIZE - 1) 
                printf("|");
        }
        printf("\n");
    }
}

int checkWin(char board[BOARD_SIZE][BOARD_SIZE], char mark) {
    // 行と列のチェック
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) return 1; // 行
        if (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark) return 1; // 列
    }
    // 対角線のチェック
    if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) return 1; // 対角線
    if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark) return 1; // 逆対角線
    return 0;
}

int isBoardFull(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) return 0;
        }
    }
    return 1;
}

void playerMove(char board[BOARD_SIZE][BOARD_SIZE]) {
    int x, y;
    do {
        printf("座標を指定してください (x y): ");
        scanf("%d %d", &x, &y);
    } while (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE || board[x][y] != EMPTY);
    board[x][y] = PLAYER_MARK;
}

int preventPlayerWin(char board[BOARD_SIZE][BOARD_SIZE]) {
    // プレイヤーがリーチしているかをチェックし、その場合に防御する
    for (int i = 0; i < BOARD_SIZE; i++) {
        // 行のチェック
        if (board[i][0] == PLAYER_MARK && board[i][1] == PLAYER_MARK && board[i][2] == EMPTY) {
            board[i][2] = ROBOT_MARK;
            return 1;
        }
        if (board[i][0] == PLAYER_MARK && board[i][2] == PLAYER_MARK && board[i][1] == EMPTY) {
            board[i][1] = ROBOT_MARK;
            return 1;
        }
        if (board[i][1] == PLAYER_MARK && board[i][2] == PLAYER_MARK && board[i][0] == EMPTY) {
            board[i][0] = ROBOT_MARK;
            return 1;
        }
        // 列のチェック
        if (board[0][i] == PLAYER_MARK && board[1][i] == PLAYER_MARK && board[2][i] == EMPTY) {
            board[2][i] = ROBOT_MARK;
            return 1;
        }
        if (board[0][i] == PLAYER_MARK && board[2][i] == PLAYER_MARK && board[1][i] == EMPTY) {
            board[1][i] = ROBOT_MARK;
            return 1;
        }
        if (board[1][i] == PLAYER_MARK && board[2][i] == PLAYER_MARK && board[0][i] == EMPTY) {
            board[0][i] = ROBOT_MARK;
            return 1;
        }
    }
    // 対角線のチェック
    if (board[0][0] == PLAYER_MARK && board[1][1] == PLAYER_MARK && board[2][2] == EMPTY) {
        board[2][2] = ROBOT_MARK;
        return 1;
    }
    if (board[0][0] == PLAYER_MARK && board[2][2] == PLAYER_MARK && board[1][1] == EMPTY) {
        board[1][1] = ROBOT_MARK;
        return 1;
    }
    if (board[1][1] == PLAYER_MARK && board[2][2] == PLAYER_MARK && board[0][0] == EMPTY) {
        board[0][0] = ROBOT_MARK;
        return 1;
    }
    if (board[0][2] == PLAYER_MARK && board[1][1] == PLAYER_MARK && board[2][0] == EMPTY) {
        board[2][0] = ROBOT_MARK;
        return 1;
    }
    if (board[0][2] == PLAYER_MARK && board[2][0] == PLAYER_MARK && board[1][1] == EMPTY) {
        board[1][1] = ROBOT_MARK;
        return 1;
    }
    if (board[1][1] == PLAYER_MARK && board[2][0] == PLAYER_MARK && board[0][2] == EMPTY) {
        board[0][2] = ROBOT_MARK;
        return 1;
    }
    return 0;
}

void robotMove(char board[BOARD_SIZE][BOARD_SIZE]) {
    // プレイヤーがリーチしている場合は防ぐ
    if (preventPlayerWin(board)) return;

    // リーチしていない場合はランダムに配置
    int robox, roboy;
    do {
        robox = rand() % BOARD_SIZE;
        roboy = rand() % BOARD_SIZE;
    } while (board[robox][roboy] != EMPTY);
    board[robox][roboy] = ROBOT_MARK;
    printf("ロボットのターン: %d %d\n", robox, roboy);
}

    int main() {
        char board[BOARD_SIZE][BOARD_SIZE] = {};
        int turnCounter = 0;

        srand((unsigned int)time(NULL));
        printf("三目並べのプログラムです。\n");

        do {
            displayBoard(board);
            playerMove(board);
            
            if (checkWin(board, PLAYER_MARK)) {
                printf("You win!\n");
                break;
            }
            
            turnCounter++;
            if (isBoardFull(board)) {
                printf("Draw!\n");
                break;
            }
            
            robotMove(board);
            
            if (checkWin(board, ROBOT_MARK)) {
                printf("You lose!\n");
                break;
            }

            turnCounter++;
            if (isBoardFull(board)) {
                printf("Draw!\n");
                break;
            }
        } while (1);

        displayBoard(board);
        return 0;
    }
