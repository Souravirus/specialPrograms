#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<time.h>
using namespace std;
const int n=3, m=9;
const int LOW=0, HIGH=2;
int me=1, bot=-1;
struct tictac
{
	int board[n][n];
	void printBoard();
	int wincheck(int board[n][n]);
	int alpha[m][m];
	pair<int, int>movegen(int board[n][n], int alpha[m][m],int nota);
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
/*pair<int, int>notatoSir(int i)
{
	pair<int, int>move;
	move.first=i/3;
	move.second=i%3;
	return move;
}*/
pair<int, int>tictac::movegen(int board[n][n],int alpha[m][m], int nota)
{
	
	pair<int, int>move;

	//Action for two lines Xs
	for(int i=0;i<3;i++)
	{
		cout<<"hello1";
		if(board[i][0]==-1&& board[i][1]==-1)
		{
			if(board[i][2]==0)
			{
				move.first=i;move.second=2;
				return move;
			}
		}
		else if(board[i][0]==-1 && board[i][2]==-1)
		{
			if(board[i][1]==0)
			{
				move.first=i;move.second=1;
				return move;
			}
		}
		else if(board[i][1]==-1 && board[i][2]==-1)
		{
			if(board[i][0]==0)
			{
				move.first=i;move.second=0;
				return move;
			}
		}
	}
	
	for(int j=0;j<3;j++)
	{
		cout<<"hello2";
		if(board[0][j]==-1&& board[1][j]==-1)
		{
			if(board[2][j]==0)
			{
				move.first=2; move.second=j;
				return move;
			}
		}
		else if(board[0][j]==-1&& board[2][j]==-1)
		{
			if(board[1][j]==0)
			{
				move.first=1; move.second=j;
				return move;
			}
		}
		else if(board[1][j]==-1 && board[2][j]==-1)
		{
			if(board[0][j]==0)
			{
				move.first=0; move.second=j;
				return move;
			}
		}
	}
	cout<<"hello3";
	if(board[0][0]==-1&& board[1][1]==-1)
	{
		if(board[2][2]==0)
		{
			move.first=2; move.second=2;
			return move;
		}

	}
	if(board[0][0]==-1 && board[2][2]==-1)
	{
		if(board[1][1]==0){
			move.first=1; move.second=1;
			return move;
		}
	}
	if(board[1][1]==-1 && board[2][2]==-1)
	{
		if(board[0][0]==0)
		{
			move.first=0;move.second=0;
			return move;
		}
	}
	if(board[2][0]==-1 && board[1][1]==-1)
	{
		if(board[0][2]==0)
		{
			move.first=0; move.second=2;
			return move;
		}
	}
	if(board[1][1]==-1 && board[0][2]==-1)
	{
		if(board[2][0]==0){
			move.first=2; move.second=0;
			return move;
		}
	}
	if(board[2][0]==-1 && board[0][2]==-1)
	{
		if(board[1][1]==0)
		{
			move.first=1; move.second=1;
			return move;
		}
	}
	//action for two line 0s
	for(int i=0;i<3;i++)
	{
		cout<<"hello1";
		if(board[i][0]==1&& board[i][1]==1)
		{
			if(board[i][2]==0)
			{
				move.first=i;move.second=2;
				return move;
			}
		}
		else if(board[i][0]==1 && board[i][2]==1)
		{
			if(board[i][1]==0)
			{
				move.first=i;move.second=1;
				return move;
			}
		}
		else if(board[i][1]==1 && board[i][2]==1)
		{
			if(board[i][0]==0)
			{
				move.first=i;move.second=0;
				return move;
			}
		}
	}
	
	for(int j=0;j<3;j++)
	{
		cout<<"hello2";
		if(board[0][j]==1&& board[1][j]==1)
		{
			if(board[2][j]==0)
			{
				move.first=2; move.second=j;
				return move;
			}
		}
		else if(board[0][j]==1&& board[2][j]==1)
		{
			if(board[1][j]==0)
			{
				move.first=1; move.second=j;
				return move;
			}
		}
		else if(board[1][j]==1 && board[2][j]==1)
		{
			if(board[0][j]==0)
			{
				move.first=0; move.second=j;
				return move;
			}
		}
	}
	cout<<"hello3";
	if(board[0][0]==1&& board[1][1]==1)
	{
		if(board[2][2]==0)
		{
			move.first=2; move.second=2;
			return move;
		}

	}
	if(board[0][0]==1 && board[2][2]==1)
	{
		if(board[1][1]==0){
			move.first=1; move.second=1;
			return move;
		}
	}
	if(board[1][1]==1 && board[2][2]==1)
	{
		if(board[0][0]==0)
		{
			move.first=0;move.second=0;
			return move;
		}
	}
	if(board[2][0]==1 && board[1][1]==1)
	{
		if(board[0][2]==0)
		{
			move.first=0; move.second=2;
			return move;
		}
	}
	if(board[1][1]==1 && board[0][2]==1)
	{
		if(board[2][0]==0){
			move.first=2; move.second=0;
			return move;
		}
	}
	if(board[2][0]==1 && board[0][2]==1)
	{
		if(board[1][1]==0)
		{
			move.first=1; move.second=1;
			return move;
		}
	}
//The condition for the best place to tick
	for(int i=0;i<m;i++)
	{
		if(alpha[nota][i]==1)
		{
			move.first=i/3;
			move.second=i%3;
			if(board[move.first][move.second]==0)
				return move; 
		}
	}
//The condition where it don't have any two xs or 0s
		cout<<"HELOO";
		time_t seconds;
		time(&seconds);
		srand((unsigned int)seconds);
		do
		{
			move.first=rand()%(HIGH - LOW+1)+LOW;move.second=rand()%(HIGH - LOW +1)+LOW;
		}while(board[move.first][move.second]!=0);
	//	int multi=move.first*3+move.second;
		//alpha[nota][multi]=1;
		//cout<<board[move.first][move.second];
		return move;

}
int main()
{
	tictac tt;
	int n;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			tt.alpha[i][j]=0;
		}
	}
	char ch;
	int nota;
	do
	{
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
			cout<<"Can you please enter the position according to Sourav's notation";
			cin>>nota;
		}
		else // bot turn
		{
			cout<<"Bot's move: \n";
			move=tt.movegen(tt.board,tt.alpha,nota);
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
					if(result == me)
					{
						 cout<<"You WON\n";
						for(int i=0;i<9;i++)
							tt.alpha[nota][i]=0;
					}
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
	cout<<"Do you want to play more to make me learn";
	cin>>ch;
	}while(ch=='y');
	return 0;
}


