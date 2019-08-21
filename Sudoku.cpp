#include <iostream>
#include <cstdio>
using namespace std;


#define BLANK '_'
#define DIMENSION 9
#define BOX_SIZE  3
class Sudoku{
	
	public:
	Sudoku();
	void print_board();
        void fill_board();
        void try2();


	private:
        char board[DIMENSION][DIMENSION] = {

            { '_', '_', '4',   '_', '_', '_',   '_', '6', '7' },
            { '3', '_', '_',   '4', '7', '_',   '_', '_', '5' },
            { '1', '5', '_',   '8', '2', '_',   '_', '_', '3' },
            { '_', '_', '6',   '_', '_', '_',   '_', '3', '1' },
            { '8', '_', '2',   '1', '_', '5',   '6', '_', '4' },
            { '4', '1', '_',   '_', '_', '_',   '9', '_', '_' },
            { '7', '_', '_',   '_', '8', '_',   '_', '4', '6' },
            { '6', '_', '_',   '_', '1', '2',   '_', '_', '_' },
            { '9', '3', '_',   '_', '_', '_',   '7', '1', '_' }
        };

        bool occurs_in_row(int row , char val);
        bool occurs_in_col(int col , char val);
        bool occurs_in_box(int srow , int scol,char val);
        bool try_it();
	};

bool Sudoku::try_it(){return true;}
void Sudoku::try2(){if(try_it()) cout<<"Hello from Here";}

bool Sudoku::occurs_in_row(int row, char val){

    for(int col = 0 ; col <DIMENSION ; col++)
        if(board[row][col] == val) return true;
    return false;
}

bool Sudoku::occurs_in_col(int col, char val){

    for(int row = 0; row <DIMENSION ; row++)
        if(board[row][col] == val) return true;
    return false;
}

bool Sudoku::occurs_in_box(int srow , int scol , char val){

    for(int row = 0 ; row <BOX_SIZE ; row++)
        for(int col = 0; col < BOX_SIZE ; col++)
            if(board[row + srow][col + scol] == val) return true;

    return false;
}

Sudoku::Sudoku(){
	
/*
    board[][] = {

        { '_', '_', '4',   '_', '_', '_',   '_', '6', '7' },
        { '3', '_', '_',   '4', '7', '_',   '_', '_', '5' },
        { '1', '5', '_',   '8', '2', '_',   '_', '_', '3' },
        { '_', '_', '6',   '_', '_', '_',   '_', '3', '1' },
        { '8', '_', '2',   '1', '_', '5',   '6', '_', '4' },
        { '4', '1', '_',   '_', '_', '_',   '9', '_', '_' },
        { '7', '_', '_',   '_', '8', '_',   '_', '4', '6' },
        { '6', '_', '_',   '_', '1', '2',   '_', '_', '_' },
        { '9', '3', '_',   '_', '_', '_',   '7', '1', '_' }
    };
*/


/*
    for(int i=0 ; i<DIMENSION ; i++){

                for(int j=0 ; j<DIMENSION ; j++)

                        board[i][j] = '_';
    }
*/

    }


	


void Sudoku::fill_board(){
    for(int i=0 ; i<DIMENSION ; i++){

            for(int j=0 ; j<DIMENSION ; j++)

                   cin>> board[i][j] ;

            }



}


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

//s.fill_board();
s.print_board();
s.try2();

return 0;
}
