#include<iostream>
using namespace std;

//size of the sudoku grid
#define N 9

//  Function to print the sudoku grid
void printGrid(int grid[N][N]) {
    for(int row = 0; row < N; row++){
        for(int col = 0; col < N; col++) 
        cout << grid[row][col] << " ";
        cout << endl;

    }
}
//Function to check if it is safe to place a number in the given row and column
bool isSafe (int grid[N][N], int row, int col, int num) {
    //check if the number is not already present in the row
    for(int x = 0; x < N; x++)
       if(grid[row][x] == num)
       return false;

//check if the number is not already present in the column
    for(int x = 0; x < N; x++)
       if(grid[x][col] == num)
       return false;

//check if the number is not already present in the 3*3 grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
       for(int j = 0; j<3; j++)
        if(grid[i + startRow][j + startCol] == num)
       return false;

return true;

}
//Function to solve the sudoku puzzle using backtracking
bool solveSudoku(int grid[N][N]) {
    int row, col;

    //Find an unassigned cell
    bool found = false;
    for(row = 0; row<N; row++) {
        for(col =0; col<N; col++){
            if(grid[row][col] == 0) {
            found = true;
            break;
        }
    }
    if(found)
    break;
}

//if no unassigned cell is found 
if(!found)
return true;

//Try different numbers in the unassigned cell
for(int num = 1; num <= 9; num++) {
    if(isSafe(grid, row, col, num)) {
        //Assign the number and recursively try to solve the puzzle
        grid[row][col] = num;
        if(solveSudoku(grid))
            return true;
        //Assign the number dosen't lead to a solution,backtracking 
        grid[row][col] = 0;

    }
}
//if no number can can be placed in the current cell,backtrack
return false;
}

//Main Function
int main(){
    int grid[N][N] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    if(solveSudoku(grid) == true)
        printGrid(grid);
    else
        cout <<"No solution exists";
    return 0;
}