# Sudoku Solver
[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)

> This program is designed to solve Sudoku game even with a blank board
# Introduction (working on)
# How it Works
* the program has 2 txt files problem.txt and answer.txt, all you have to do is to write the problem in the first file (with a certain format) and get the answer in the other file.
* Backtracking method is used here instead of generating all possibilties and then check which one is valid

How to run
-----------
##### You have either two ways to run the program
*  first : compile the cpp file as the following (copy to the terminal):
```sh 
$ g++ -Wall -o Sudoku Sudoku.cpp
$ ./Sudoku
```
![Compile_terminal](https://github.com/Hagar-Usama/Sudoku_Solver/blob/master/screenshots/compile_in_terminal.png)


* Second : run the script "shell_run" by just clicking on it and selecting execute (if required)
 ![execute](https://github.com/Hagar-Usama/Sudoku_Solver/blob/master/screenshots/execute_shell.png)
    - make sure in the file properties (is executable is checked)   
    ![run_script](https://github.com/Hagar-Usama/Sudoku_Solver/blob/master/screenshots/shell_config.png)

 

You can also:
  * Use any IDE to run the program if you wish
    - [Code::Blocks](http://www.codeblocks.org/)
    - [Geany](https://www.geany.org/)
    - [Visual Studio Code](https://code.visualstudio.com/)
 
  
Todos / What's next
---


 - Checking text file validity using Regular Expressions
 - Provide GUI interface
 - Provide interactive interface in CMD/Terminal

License
----
- GNU General Public License v3.0

Screenshots
----
![Compile_terminal](https://github.com/Hagar-Usama/Sudoku_Solver/blob/master/screenshots/compile_in_terminal.png)

![sample_run](https://github.com/Hagar-Usama/Sudoku_Solver/blob/master/screenshots/problem%26answer.png)
