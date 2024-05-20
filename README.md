# 0h h1

## About the project
This project is a solver for the 0h h1 game. It uses DFS to explore all solutions and finds the first matching solution. The code is written in c++.

## About the Game
0h h1 is a little logic game by Q42. It was created my Martin Kool. The game can be found at [0hh1](https://0hh1.com/).

## RULES:

- Three adjacent tiles of the same color in a row or column is not allowed. 
- Rows and columns have an equal number of each color
- No two rows and no two columns are same

## Working of code
The code first expects the dimension of the board. Then you are supposed to enter the board where entries are 0,1,2 space separated. For blue you press 1, for red you press 2, for blank you press 0. You can adjust the color by assuming the numbers and mapping them to your color.

## Execution
To compile : g++ 0hh1.cpp -o 0hh1
To run : ./0hh1
