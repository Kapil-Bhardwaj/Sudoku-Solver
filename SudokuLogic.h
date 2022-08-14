#include<iostream>
using namespace std;

bool isSafe(int row,int col, int val, int board[][9])
{
    for(int i=0;i<9;i++)
    {
        // chek for the row - if the val exist the in the row then not safe to put
         if(board[row][i] == val)
         return false;
         
         // check for column - if the val exist the in the column then not safe to put
         
         if(board[i][col] == val)
         return false;
         
        // Now check the safety for 3*3 grid
        
       if(board[3*(row/3) + i/3][3*(col/3)+ i%3 ]==val)
            return false;
        
        
    }
    // Out of Loop it means safe to put the value
    return true;
    
}


bool solve(int board[][9])
{     
    for(int i=0;i<9;i++) // loop to traverse row
    {
        for(int j=0;j<9;j++) // loop to traverse column
        {
             // chek if sudoku cell if empty - then put value(1-9) and search for the possible solution
             if(board[i][j]==0)
             {
                 // cell is empty
                   for(int val=1;val<=9;val++) // loop to chek the possible value for solution
                   {
                        // chek if the value is safe to chek
                       if(isSafe(i,j,val,board))
                        {
                             // value is safe to put
                              board[i][j]=val;
                              
                              // recursive Called  
                             bool  isPossibleSolution = solve(board);
                               
                               if(isPossibleSolution)
                               {
                                   return true;
                               }else
                               {
                                   // backTrack
                                      board[i][j]=0;
                               }
                       }
                   }
               // if all the possible values 1-9 are cheked and found not to safe that means sudoku can't be solved
                   return false;
             }
        }
    }
 cout<<"🎉🎉 Hurry Sudoku Solved Sucessfuly🎉🎉 "<<endl;
    return true;
}
