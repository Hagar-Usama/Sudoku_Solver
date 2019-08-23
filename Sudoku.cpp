#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;


#define BLANK '_'
#define DIMENSION 9
#define BOX_SIZE  3

class Sudoku{
	
	public:
	Sudoku();
	void print_board();
        void fill_board();
        bool solve();
        void write_problem();
        void write_answer();
        void load_problem();
        //char** get_board();


	private:
        char board[DIMENSION][DIMENSION];

        bool occurs_in_row(int row , char val);
        bool occurs_in_col(int col , char val);
        bool occurs_in_box(int srow , int scol,char val);
        bool isLegal(int row , int col, char val);
        pair<int,int> get_empty_cell();
        void write_in_file(const char* filename);


	};

void Sudoku::write_problem(){write_in_file("problem.txt");}
void Sudoku::write_answer(){write_in_file("answer.txt");}
void Sudoku::load_problem(){

       FILE *fp;
       //int size;

       fp = fopen("problem.txt","r");
       if(fp == NULL) {
          perror("Error");
          exit(1);
       }

       /** the following 2 statements are just to get the size of board
        * which is not activated
        **/
        //size = fgetc(fp);
        fgetc(fp); fgetc(fp);

/** getdelim(char **lineptr, size_t *n, int delim, FILE *stream);**/
/** ssize_t getline(char **lineptr, size_t *n, FILE *stream);**/

        int len = DIMENSION * 2 -1;
        char* line = (char *)calloc(DIMENSION*2+1, sizeof(char));

        for(int i=0 ; i< DIMENSION ; i++){

            getline((char**)&line, (size_t *)&len, (FILE *)fp);

            for(int col=0 ; col < 2*DIMENSION+1 ; col+=2){
                     board[i][col/2] = line[col];
            }

        }

    fclose(fp);


}
void Sudoku::write_in_file(const char* filename){

    FILE *fptr;
    fptr = fopen(filename,"w");
       if(fptr == NULL)
       {
          perror("Error");
          exit(1);
       }

       fprintf(fptr,"%d\n",DIMENSION);


       for(int row=0; row<DIMENSION ; row++){
           for(int col = 0; col<DIMENSION; col++)
               fprintf(fptr,"%c ",board[row][col]);
           fprintf(fptr,"\n");

       }
       fclose(fptr);

}

bool Sudoku::solve(){

    if(get_empty_cell() == std::make_pair(DIMENSION,DIMENSION)) return true;

    pair<int,int> coordinate = get_empty_cell();


    for(int i='1' ; i<='9'; i++){

        if(isLegal(coordinate.first , coordinate.second , i))
          { board[coordinate.first][coordinate.second] = i;
            if(solve())
               return true;

            board[coordinate.first][coordinate.second] = BLANK;

          }



    }

    return false;
}
pair<int,int> Sudoku::get_empty_cell(){

    for(int row =0 ; row < DIMENSION ; row++)
       for(int col = 0; col < DIMENSION ; col++)
           if(board[row][col] == BLANK)
               return std::make_pair(row,col);

    return std::make_pair(DIMENSION,DIMENSION);
}

bool Sudoku::isLegal(int row, int col, char val){
    return    !occurs_in_row(row , val)
           && !occurs_in_col(col , val)
           && !occurs_in_box(row - row%3 , col - col%3 , val);
}

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




 //Initializing the board as blank
    for(int i=0 ; i<DIMENSION ; i++){

                for(int j=0 ; j<DIMENSION ; j++)

                        board[i][j] = '_';
    }

  }


	


void Sudoku::fill_board(){
    for(int i=0 ; i<DIMENSION ; i++){

            for(int j=0 ; j<DIMENSION ; j++)

                   cin>> board[i][j] ;

            }



}


void Sudoku::print_board(){
        //cout<<"-------------------------------------"<<endl;
    cout<<endl;
        for (int i =0 ; i<DIMENSION ; i++){
            if(i %3 ==0) cout<<"========================================="<<endl;
            else         cout<<"-----------------------------------------"<<endl;


		for(int j=0 ; j<DIMENSION ; j++)
		{
                        if(j %3 ==0) printf("|");
			printf("| %c ",board[i][j]);

			
			}
                cout<<"||"<<endl;
                }
	
        cout<<"========================================="<<endl;

	}


int main(){

Sudoku s;

s.load_problem();
s.print_board();

s.solve();
s.print_board();
s.write_answer();


return 0;
}
