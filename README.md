# Sudoku_Solver
## PHY 504 Final Project: A code that solves Sudoku puzzles

A sudoku board is composed of a 9 by 9 grid of cells that can take values
from 1 to 9. The board is subdivided into 9 3x3 boxes. The rules of the 
puzzle are that in each box, column and row there must exist all numbers 
1 to 9, but only once each. 

The principle of this solver is that if a number is required in a given box,
column or row, and it is forbiden from the 8 other cells in that group,
then that value must go in that cell.


## Building
If your pwd is Sudoku_Solver, entering `make` in the terminal will build the solve and guess applications and a driver. 
To build in debug mode enter `make DEBUG=TRUE`. In debug mode the driver is exercised automaticaly. It can also be exercised by `make testing DEBUG=TRUE`.


## Using the Program
After compiling, the program can be run by `./solve.o`. The program can be provided 
with the name of a board file on the command line. If no file is given, the user
is prompted to give one. After this the solver will run until the board is solved 
or it is found that the algorithm can not solve the board. 

Some problems that can not be solved by `./solve.o` can be solved by `./guess.o`. Providing files to the program works the same as above.
The number of guesses to make can be chosen from 1 to 4 by entering that number after the file name on the command line.



## Example Boards
The board.dat file contains the following puzzle. It comes from https://en.wikipedia.org/wiki/Sudoku<br/>
![Alt text](https://upload.wikimedia.org/wikipedia/commons/thumb/e/e0/Sudoku_Puzzle_by_L2G-20050714_standardized_layout.svg/250px-Sudoku_Puzzle_by_L2G-20050714_standardized_layout.svg.png "Example") <br/>
The program can be verified by running `./solve boards/board.dat` which should produce the following soloution<br/>
![Alt text](https://upload.wikimedia.org/wikipedia/commons/thumb/1/12/Sudoku_Puzzle_by_L2G-20050714_solution_standardized_layout.svg/250px-Sudoku_Puzzle_by_L2G-20050714_solution_standardized_layout.svg.png "Solved")

The medium.dat, hard.dat and veryhard.dat boards come from https://www.websudoku.com/


## Limitations
Some Sudoku puzzles do not provide enough information for this algorithm to work.
These can be solved by guessing but `./solve.o` does not do this.
french.dat is an example of a board that can not be solved by this program on its own. french1.dat and french2.dat
are the same as french.dat but with one uknown cell value in each of them guessed. In this case
both guesses lead to the same soloution. However the guess in french3.dat leads to
a different soloution.

If a board is not solveable by `./solve.o`, it will quit if it does not solve any
new cells in one complete iteration

This image of a 1985 predecesor to Sudoku which comes from https://en.wikipedia.org/wiki/Sudoku is the source of french.dat<br/>
![Alt text](https://upload.wikimedia.org/wikipedia/commons/6/6f/Sudoku.jpg "French")<br/>

Some boards not solveable by `./solve.o` are solveable by `./guess.o`, for example hard.dat and french.dat. However not all boards can
be solved by`./guess`. veryhard.dat is one example.

## Writing Boards
A properly formated board is a 9 by 9 grid of comma seperated characters with no spaces or lines outside of the grid. 
A single underscore should be used to represent an unknown value. For example, the text of board.dat is:

`5,3,_,_,7,_,_,_,_`<br/>
`6,_,_,1,9,5,_,_,_`<br/>
`_,9,8,_,_,_,_,6,_`<br/>
`8,_,_,_,6,_,_,_,3`<br/>
`4,_,_,8,_,3,_,_,1`<br/>
`7,_,_,_,2,_,_,_,6`<br/>
`_,6,_,_,_,_,2,8,_`<br/>
`_,_,_,4,1,9,_,_,5`<br/>
`_,_,_,_,8,_,_,7,9`<br/>



## class overview
* The  *cell* class describes the location and value of a cell on the game board.
It provides methods for finding out what values are needed in the rows columns
and 3X3 boxes that a cell is in, and which values are forbiden from the cell.
The cell class also contains a method for solving individual cells. If a value is
required in all 3 of the cell's row, column and box and it is forbiden from all 
other cells in any of the row, column or box, then this value is output 


* The *Board* class contains the values of the 81 cells on the game board stored as a vector.
Boards can be read in from properly formated text files. The value of the elements of the board at position `_pos` can be edited using inline `void set(int _pos,char _val) {nums[_pos]=_val;}`. This is useful if you want to add some guesses to a board to try to make it possible for the program to solve.


* The *solver* class has methods for solving the full board. It uses the solver from
the cell class and loops over all 81 cells. There is one solver that will keep
iterating until either the board is solved or it is determined that the algorithm
can not solve it. There is a diferent solver that only preforms one iteration of
solving.

* The *guess* class guesses from the values needed by a cell's row, column and box, without requiring that it be needed by 
all 3 as in the *cell* class. Applying guess to itself allows making multiple guesses. After guessing a soloution is attempted.
If no solution is found the program restarts and a new guess is made

