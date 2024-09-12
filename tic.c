#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int counter = 0;
	int flag = 0;
	int flag1 = 0;
	int flag2 = 0;
	int x;
	int y;
	char input;
	char board[3][3] = {};
	printf("三目並べのプログラムです．");
	printf("打つ場所はxy座標で決めます");
	printf("座標は以下のようになっています．\n");
	printf("(0,0) (0,1) (0,2)\n");
	printf("(1,0) (1,1) (1,2)\n");
	printf("(2,0) (2,1) (2,2)\n");
	srand((unsigned int)time(NULL));
	do
	{
		while (flag == 0)
		{
			while (flag1 == 0)
			{
				printf("座標を指定してください");
				scanf("%d %d", &x, &y);
				printf("%d %d", x, y);
				if (x >= 0 && x <= 2 && y >= 0 && y <= 2 && board[x][y] != 'o' && board[x][y] != 'x')
					flag1 = 1;
			}
			board[x][y] = 'o';
			flag = 1;
		}
		flag = 0;
		flag1 = 0;
		if(board[0][0] == 'o' && board[0][1] == 'o' && board[0][2] == 'o'){
			printf("you win\n");
			counter = 5;
		}
		if(board[1][0] == 'o' && board[1][1] == 'o' && board[1][2] == 'o'){
			printf("you win\n");
			counter = 5;
		}
		if(board[0][1] == 'o' && board[1][1] == 'o' && board[2][1] == 'o'){
			printf("you win\n");
			counter = 5;
		}
		else if(board[0][0] == 'o' && board[1][0] == 'o' && board[2][0] == 'o'){
			printf("you win\n");
			counter = 5;
		}
		else if(board[2][0] == 'o' && board[2][1] == 'o' && board[2][2] == 'o'){
			printf("you win\n");
			counter = 5;
		}
		else if(board[0][2] == 'o' && board[1][2] == 'o' && board[2][2] == 'o'){
			printf("you win\n");
			counter = 5;
		}
		else if(board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o'){
			printf("you win\n");
			counter = 5;
		}
		else if(board[0][2] == 'o' && board[1][1] == 'o' && board[2][0] == 'o'){
			printf("you win\n");
			counter = 5;
		}
		else;
		if(counter == 4){
			printf("draw\n");
			printf("%d",counter);
			counter = 5;
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] != '\0')
					printf("%c,", board[i][j]);
				else if (j <= 1)
					printf(" ,");
			}
			printf("\n");
		}
		counter++;
		int robox;
		int roboy;
		if(counter != 6){ //magic number
		while (flag2 == 0)
		{
			robox = rand() % 3;
			roboy = rand() % 3;
			if(board[0][0] == 'o' && board[0][1] == 'o' && board[0][2] == '\0'){
			robox = 0;
			roboy = 2;
			}
			else if(board[0][0] == 'o' && board[0][2] == 'o' && board[0][1] == '\0'){
			robox = 0;
			roboy = 1;
			}
			else if(board[0][2] == 'o' && board[0][1] == 'o' && board[0][0] == '\0'){
			robox = 0;
			roboy = 0;
			}
			else if(board[1][0] == 'o' && board[1][1] == 'o' && board[1][2] == '\0'){
			robox = 1;
			roboy = 2;
			}
			else if(board[1][0] == 'o' && board[1][2] == 'o' && board[1][1] == '\0'){
			robox = 1;
			roboy = 1;
			}
			else if(board[1][2] == 'o' && board[1][1] == 'o' && board[1][0] == '\0'){
			robox = 1;
			roboy = 0;
			}
			else if(board[2][0] == 'o' && board[2][1] == 'o' && board[2][2] == '\0'){
			robox = 2;
			roboy = 2;
			}
			else if(board[2][0] == 'o' && board[2][2] == 'o' && board[2][1] == '\0'){
			robox = 2;
			roboy = 1;
			}
			else if(board[2][2] == 'o' && board[2][1] == 'o' && board[2][0] == '\0'){
			robox = 2;
			roboy = 0;
			}
			else if(board[0][0] == 'o' && board[1][0] == 'o' && board[2][0] == '\0'){
			robox = 2;
			roboy = 0;
			}
			else if(board[0][0] == 'o' && board[2][0] == 'o' && board[1][0] == '\0'){
			robox = 1;
			roboy = 0;
			}
			else if(board[2][0] == 'o' && board[1][0] == 'o' && board[0][0] == '\0'){
			robox = 0;
			roboy = 0;
			}
			else if(board[0][1] == 'o' && board[1][1] == 'o' && board[2][1] == '\0'){
			robox = 2;
			roboy = 1;
			}
			else if(board[0][1] == 'o' && board[2][1] == 'o' && board[1][1] == '\0'){
			robox = 1;
			roboy = 1;
			}
			else if(board[2][1] == 'o' && board[1][1] == 'o' && board[0][1] == '\0'){
			robox = 0;
			roboy = 1;
			}
			else if(board[0][2] == 'o' && board[1][2] == 'o' && board[2][2] == '\0'){
			robox = 2;
			roboy = 2;
			}
			else if(board[0][2] == 'o' && board[2][2] == 'o' && board[1][2] == '\0'){
			robox = 1;
			roboy = 2;
			}
			else if(board[2][2] == 'o' && board[1][2] == 'o' && board[0][2] == '\0'){
			robox = 0;
			roboy = 2;
			}
			else if(board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == '\0'){
			robox = 2;
			roboy = 2;
			}
			else if(board[0][0] == 'o' && board[2][2] == 'o' && board[1][1] == '\0'){
			robox = 1;
			roboy = 1;
			}
			else if(board[2][2] == 'o' && board[1][1] == 'o' && board[0][0] == '\0'){
			robox = 0;
			roboy = 0;
			}
			else if(board[0][2] == 'o' && board[1][1] == 'o' && board[2][0] == '\0'){
			robox = 2;
			roboy = 0;
			}
			else if(board[0][2] == 'o' && board[2][2] == 'o' && board[1][1] == '\0'){
			robox = 1;
			roboy = 1;
			}
			else if(board[2][0] == 'o' && board[1][1] == 'o' && board[0][2] == '\0'){
			robox = 0;
			roboy = 2;
			}
			else;
			if (board[robox][roboy] == '\0')
			{
				printf("robot select turn;%d %d\n",robox,roboy);
				board[robox][roboy] = 'x';
				flag2 = 1;
			}
			else;
		}
		flag2 = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] != '\0')
					printf("%c,", board[i][j]);
				else if (j <= 1)
					printf(" ,");
			}
			printf("\n");
		}
			if(board[0][0] == 'x' && board[0][1] == 'x' && board[0][2] == 'x'){
			printf("you lose\n");
			counter = 5;
		}
		if(board[1][0] == 'x' && board[1][1] == 'x' && board[1][2] == 'x'){
			printf("you lose\n");
			counter = 5;
		}
		if(board[0][1] == 'x' && board[1][1] == 'x' && board[2][1] == 'x'){
			printf("you lose\n");
			counter = 5;
		}
		else if(board[0][0] == 'x' && board[1][0] == 'x' && board[2][0] == 'x'){
			printf("you lose\n");
			counter = 5;
		}
		else if(board[2][0] == 'x' && board[2][1] == 'x' && board[2][2] == 'x'){
			printf("you lose\n");
			counter = 5;
		}
		else if(board[0][2] == 'x' && board[1][2] == 'x' && board[2][2] == 'x'){
			printf("you lose\n");
			counter = 5;
		}
		else if(board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x'){
			printf("you lose\n");
			counter = 5;
		}
		else if(board[0][2] == 'x' && board[1][1] == 'x' && board[2][0] == 'x'){
			printf("you lose\n");
			counter = 5;
		}
		else;
		}
	} while (counter < 5);

}