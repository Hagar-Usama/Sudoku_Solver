#include <iostream>
#include <cstdio>
using namespace std;


#define BLANK '_'
#define DIMENSION 9
class Sudoku{
	
	public:
	Sudoku();
	void print_board();
	
	
	private:
	char board[DIMENSION][DIMENSION];
	
	
	};

Sudoku::Sudoku(){
	
	for(int i=0 ; i<DIMENSION ; i++){
		
		for(int j=0 ; j<DIMENSION ; j++)
			
			board[i][j] = '_';
		
		}
	
	
	};


void Sudoku::print_board(){
	cout<<"-------------------------------------"<<endl;
	for (int i =0 ; i<DIMENSION ; i++){
		
		for(int j=0 ; j<DIMENSION ; j++)
		{
			printf("| %c ",board[i][j]);
			
			}
		cout<<"|"<<endl;
		cout<<"-------------------------------------"<<endl;
		}
	
	
	}
int main(){

Sudoku s;
s.print_board();

return 0;
}
