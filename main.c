#include <stdio.h>

struct chessCell {
    int color; 
    char figure[4];
};

void stringCopy(char* out, char* inp, int len)
{
	for(int i = 0; i<len; ++i)
		{
			out[i] = inp[i];
		}
}

void chessPrint(struct chessCell chessState[8][8])
{
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if ((i + j) % 2 == 0) {
                printf("\e[47m");
            } else {
                printf("\e[100m");
            }
            if (chessState[i][j].color) {
                printf(" \e[30m%s ", chessState[i][j].figure);
            } else {
                printf(" \e[39m%s ", chessState[i][j].figure);
            }
        }
        printf("\e[0m\n");
    }
}
int main(int argc, char const* argv[])
{
    // UNICODE CHESS SYMBOLS
    char pawn[4] = "\u265F";
    char knight[4] = "\u265E";
    char bishop[4] = "\u265D";
    char rook[4] = "\u265C";
    char queen[4] = "\u265B";
    char king[4] = "\u265A";
    char empty[4] = " ";

    struct chessCell chessState[8][8];

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            stringCopy((chessState[i][j]).figure, empty, sizeof empty);
        }
    }
    for (int i = 0; i < 9; i += 7) {
        stringCopy(chessState[i][0].figure, rook, sizeof rook);
        stringCopy(chessState[i][1].figure, knight, sizeof knight);
        stringCopy(chessState[i][2].figure, bishop, sizeof bishop);
        stringCopy(chessState[i][3].figure, queen, sizeof queen);
        stringCopy(chessState[i][4].figure, king, sizeof king);
        stringCopy(chessState[i][5].figure, bishop, sizeof bishop);
        stringCopy(chessState[i][6].figure, knight, sizeof knight);
        stringCopy(chessState[i][7].figure, rook, sizeof rook);
    }
    for (int i = 1; i < 7; i += 5) {
        for (int j = 0; j < 8; ++j) {
            stringCopy(chessState[i][j].figure, pawn, sizeof pawn);
        }
    }
    for (int j = 0; j < 8; ++j) {
        chessState[0][j].color = 0;
        chessState[1][j].color = 0;
        chessState[6][j].color = 1;
        chessState[7][j].color = 1;
    }

    chessPrint(chessState);
    return 0;
}
