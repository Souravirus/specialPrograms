#include <iostream>
#include <stdio.h>
#include <climits>

using namespace std;

const int n = 3;
int me = 1, bot = -1;
// me - O , bot = X
struct tictac
{
	int board[n][n];
	void printBoard();
	int wincheck(int board[n][n]);
	pair<int,int> movegen (int board[n][n],int turn);
	int minimax(int board[n][n], int turn, int depth);
	int ctfill(int board[n][n]);
	int evaluation(int board[n][n], int depth);
};

void tictac::printBoard()
{
	cout<<"BOARD: \n\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(board[i][j] == me) cout<<" O ";
			else if(board[i][j] == bot) cout<<" X ";
			else cout<<"   ";
			if(j != n-1) cout<<"|";
		}
		if(i!=n-1) cout<<"\n------------\n";
	}
	cout<<"\n";
}

int tictac::wincheck(int board[n][n])
{
	if(board[0][0]==me && board[0][1]==me && board[0][2]==me) return me;
    else if(board[1][0]==me && board[1][1]==me && board[1][2]==me) return me;
    else if(board[2][0]==me && board[2][1]==me && board[2][2]==me) return me;
    else if(board[0][0]==me && board[1][0]==me && board[2][0]==me) return me;
    else if(board[0][1]==me && board[1][1]==me && board[2][1]==me) return me;
    else if(board[0][2]==me && board[1][2]==me && board[2][2]==me) return me;
    else if(board[0][0]==me && board[1][1]==me && board[2][2]==me) return me;
    else if(board[0][2]==me && board[1][1]==me && board[2][0]==me) return me;
    
    
    else if(board[0][0]==bot && board[0][1]==bot && board[0][2]==bot) return bot;
    else if(board[1][0]==bot && board[1][1]==bot && board[1][2]==bot) return bot;
    else if(board[2][0]==bot && board[2][1]==bot && board[2][2]==bot) return bot;
    else if(board[0][0]==bot && board[1][0]==bot && board[2][0]==bot) return bot;
    else if(board[0][1]==bot && board[1][1]==bot && board[2][1]==bot) return bot;
    else if(board[0][2]==bot && board[1][2]==bot && board[2][2]==bot) return bot;
    else if(board[0][0]==bot && board[1][1]==bot && board[2][2]==bot) return bot;
    else if(board[0][2]==bot && board[1][1]==bot && board[2][0]==bot) return bot;
    
    else return 0;
}
int tictac::evaluation(int board[n][n], int depth)
{
	int result=wincheck(board);
	if(result==bot) return 10-depth;
	else if(result==me) return depth-10;
	else return 0;
}
pair<int,int> tictac::movegen(int board[n][n],int turn)
{
	int maxScore=INT_MIN;
	pair<int,int> move;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(board[i][j]==0)
			{
				board[i][j]=turn;
				//assign some value to the moves 
				int tempScore=minimax(board, - turn, 1);
				cout<<tempScore<<endl;
				if(tempScore>maxScore)
				{
					maxScore=tempScore;
					move.first=i; move.second=j;
				}
				board[i][j]=0;			
			}
		}	
	}
	return move;
}
int tictac:: ctfill(int board[n][n])
{
	int ct=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(board[i][j] !=0)ct++;
		}
	}
	return ct;
}
int tictac::minimax(int board[n][n], int turn, int depth)
{
	int result=wincheck(board),fillcount=ctfill(board);
	if(result !=0)//someone has won the game
	{
		return evaluation(board, depth);
		//assign some value
		
	}
	else if(fillcount==9) return 0;
	 //board id filled return 0
	 int maxScore=INT_MIN , minScore=INT_MAX ;
	 for(int i=0;i<n;i++)
	 {
	 	for(int j=0;j<n;j++)
	 	{
	 		if(board[i][j]==0)
	 		{
	 			board[i][j]=turn;
	 			int tempScore=minimax(board, -turn, depth+1) ;
	 			if(tempScore>maxScore) maxScore=tempScore;
	 			if(tempScore<minScore)minScore=tempScore;
	 			board[i][j]=0;
	 		}
	 	}
	 }
	 if(turn==bot) return maxScore;
	 else return minScore;
}
int main()
{
	tictac tt;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			tt.board[i][j] = 0;
		}
	}
	int turn = me;
	int ipos, jpos, countfill = 0;
	pair<int, int> move;
	tt.printBoard();
	while(1)
	{
		if(turn == me)
		{
			cout<<"Enter the position to mark: \n";
			cin >> ipos >> jpos;
		}
		else // bot turn
		{
			cout<<"Bot's move: \n";
			move=tt.movegen(tt.board, turn);
			ipos=move.first; jpos=move.second;
			// perfrom bot moves
		}
		if( (ipos>=0 && ipos<n) && (jpos>=0 && jpos<n))
		{
			if(tt.board[ipos][jpos] == 0)
			{
				tt.board[ipos][jpos] = turn;
				// if win condition comes, then end the game.
				int result = tt.wincheck(tt.board);
				turn*=-1;
				countfill++;
				tt.printBoard();
				if(result!= 0)
				{
					if(result == me) cout<<"You WON\n";
					else cout<<"The bot wins\n";
					break;
				}
				else if(countfill == 9)
				{
					cout<<"GAME DRAWN\n";
					break;
				}	
			}
			else cout<<"position not empty, move again\n";
		}
		else cout<<"Invalid move, move again\n";
	}
	return 0;
}
