#include <stdio.h>
#include <stdlib.h>

int tile = 0;
int board[100][100];

void chessBoard(int tr,int tc,int dr,int dc,int size);
//棋盘覆盖 

int main(){
	int r, c;
	memset(board,0,sizeof(board));
	chessBoard(0,0,0,0,4);
	for(r = 0; r < 4; r++){
		for(c = 0; c < 4; c++){
			printf("%2d ",board[r][c]);
		}
		printf("\n");
	}
	return 0;
}

void chessBoard(int tr,int tc,int dr,int dc,int size)//tr,tc表示当前棋盘的左上角的行标和列标，size棋盘大小，dr,dc特殊方格的位置 
{
	int s,t;
	if (size == 1) {
		return;
	}
	t = ++tile;
	s = size/2;
	
	//覆盖左上角棋盘
	if (dr < tr+s && dc < tc+s){//	特殊方格在左上角棋盘中 
		chessBoard(tr,tc,dr,dc,s);
	}else{
		board[tr+s-1][tc+s-1] = t;
		chessBoard(tr,tc,tr+s-1,tc+s-1,s);
	}
	
	//覆盖右上角棋盘
	if (dr < tr+s && dc >= tc+s){
		chessBoard(tr,tc+s,dr,dc,s);
	} else{
		board[tr+s-1][tc+s] = t;
		chessBoard(tr,tc+s,tr+s-1,tc+s,s);
	}
	
	//覆盖左下角棋盘
	if (dr >= tr+s && dc < tc+s){
		chessBoard(tr+s,tc,dr,dc,s);
	} else{
		board[tr+s][tc+s-1] = t;
		chessBoard(tr+s,tc,tr+s,tc+s-1,s);
	}
	
	//覆盖右下角棋盘
	if (dr >= tr+s && dc >= tc+s){
		chessBoard(tr+s,tc+s,dr,dc,s);
	} else{
		board[tr+s][tc+s] = t;
		chessBoard(tr+s,tc+s,tr+s,tc+s,s);
	} 
}
