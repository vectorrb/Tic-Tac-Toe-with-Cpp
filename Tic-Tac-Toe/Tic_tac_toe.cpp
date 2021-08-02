//Tic Tac Toe
#include<iostream>
#include<windows.h>
#define endl "\n"
using namespace std;

//reg add HKEY_CURRENT_USER\Console /v VirtualTerminalLevel /t REG_DWORD /d 0x00000001 /f

//undo
//reg add HKEY_CURRENT_USER\Console /v VirtualTerminalLevel /t REG_DWORD /d 0x00000000 /f

void printboard(char gameboard[7][14]){
	for(int i = 0; i < 7; i++){
		cout << "  ";
		for(int j = 0; j < 14; j++){
			if(gameboard[i][j] == 'X'){
				cout << "\u001b[31m"<< gameboard[i][j] <<"\u001b[0m";
			} else if(gameboard[i][j] == 'O'){
				cout << "\u001b[33m"<< gameboard[i][j] <<"\u001b[0m";
			}
			else{
				cout << "\u001b[1m"<< gameboard[i][j] <<"\u001b[0m";
			}
			
		}cout <<endl; 
	}
}

void enter_position(char gameboard[7][14], int pos, int player){
	char s;
	if(player == 1) s = 'X';
	if(player == 2) s = 'O';
	switch(pos){
		case 1: gameboard[1][3] = s;
			break;
		case 2: gameboard[1][7] = s;
			break;
		case 3: gameboard[1][11] = s;
			break;
		case 4: gameboard[3][3] = s;
			break;
		case 5: gameboard[3][7] = s;
			break;
		case 6: gameboard[3][11] = s;
			break;
		case 7: gameboard[5][3] = s;
			break;
		case 8: gameboard[5][7] = s;
			break;
		case 9: gameboard[5][11] = s;
			break;
	}
}
int checkwhowon(int pos_log[], int player_log[]){
	int win_positions[8][3] = {
	{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{3,5,7}};
	for(int i = 0; i < 8; i++){
		if(pos_log[win_positions[i][0] - 1] & pos_log[win_positions[i][1] - 1] & pos_log[win_positions[i][2] - 1]){
			if(player_log[win_positions[i][0] - 1] & player_log[win_positions[i][1] - 1] & player_log[win_positions[i][2] - 1]){
				return(player_log[win_positions[i][0] - 1]);
			}
		}
			
	}
	return 0;
}

void declare(int win){
	if(win == 1) cout << "\u001b[7m  Player 1 won!  \u001b[0m";
	if(win == 2) cout << "\u001b[7m  Player 2 won!  \u001b[0m";
}
int main(){
	cout << " Welcome To TIC TAC TOE\n";
	//+ - + - + - + starting from row 1, alternate 4 times
	//|   |    |  | starting from row 2, alternate 3 times
//	print_basic_m_of_ttt();
	char gameboard[7][14] = {
	{' ','+',' ','-',' ','+',' ','-',' ','+',' ','-',' ','+'},
	{' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},
	{' ','+',' ','-',' ','+',' ','-',' ','+',' ','-',' ','+'},
	{' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},
	{' ','+',' ','-',' ','+',' ','-',' ','+',' ','-',' ','+'},
	{' ','|',' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','|'},
	{' ','+',' ','-',' ','+',' ','-',' ','+',' ','-',' ','+'},
	};
	gameboard[1][3] = '1';
	gameboard[1][7] = '2';
	gameboard[1][11] = '3';
	gameboard[3][3] = '4';
	gameboard[3][7] = '5';
	gameboard[3][11] = '6';
	gameboard[5][3] = '7';
	gameboard[5][7] = '8';
	gameboard[5][11] = '9';
	printboard(gameboard);
	
	
	int pos, flag = 1;
	int player = 0, plays = 0, win = 0;
	int pos_log[9] = {0};
	int player_log[9] = {0};
	while(plays<9 && win==0){
//		cout <<"\n Plays = " << plays << endl;
		if(win==0){
		cout << "Enter the position for player 1(X): ";
		player = 1;
		
		while(flag){
			cin >> pos;
			if(pos_log[pos-1] == 1) {
			cout << "Position Already Taken please enter another position: ";
			flag = 1;
			} else{
				enter_position(gameboard,pos,player);
				pos_log[pos-1] = 1;
				player_log[pos-1] = player; 
				flag = 0;
			}
		} flag = 1;
		
		printboard(gameboard);
		plays++;
		win = checkwhowon(pos_log, player_log);
		declare(win);
		}
		
		if(win==0 && plays<=8){
			cout << "Enter the position for player 2(O): ";
		player = 2;
		
		while(flag){
			cin >> pos;
			if(pos_log[pos-1] == 1) {
			cout << "Position Already Taken please enter another position: ";
			flag = 1;
			} else{
				enter_position(gameboard,pos,player);
				pos_log[pos-1] = 1;
				player_log[pos-1] = player; 
				flag = 0;
				}
			} flag = 1;
			
			printboard(gameboard);
			plays++;
			win = checkwhowon(pos_log, player_log);
			declare(win);
			
		}
		
	}
	
	if(win == 0){
		cout << "\nIt is a Tie\n";
	}
	

}
