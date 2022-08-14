
#include " iostream "
#include " SudokuLogic.h " 
using namespace std;
#define n 9

int main()
{

cout<<"-------------------------------------------------------------------------------------------------------------------------\n";
cout<<"         🫰🏻  Give your Sudoku problem to me I'll solve it int seconds  !! "<<endl;
cout<<endl<<" * You should give me input as 9 X 9 valid grid    "<<endl;
cout<<endl<<" * Fill 0 where your want to keep cell empty "<<endl;
    // s
    int sudoku[n][n];
   int row=0,col=0;
    cout<<"\nEnter the Sudoku : "<<endl;
    for(row;row<n;row++)
    {
        for(col=0;col<n;col++)
        {
            cin>>sudoku[row][col];
        }
        
    }
    
    cout<<"\n\n\n";
    //printing the sudoku
       bool canBeSolved = solve(sudoku);
       if(!canBeSolved)
         {
             cout<<" 😡Given Sudoku can't be solved😖 !!!";
            exit(1);
         }
    
    cout<<"Solved Sudoku Is : \n\n\n";
    for(int i=0;i<3*n;i++)
                cout<<"_";
                cout<<"\n";
  for(row=0;row<n;row++)
    {
        
        for(col=0;col<n;col++)
        {      
              
            cout<<sudoku[row][col]<<" ";
             if((col+1)%3==0)
             cout<<" | ";
        }
        cout<<endl;
        if((row+1)%3==0)
            {   for(int i=0;i<3*n-1;i++)
                cout<<"_";
                
                cout<<'\n';
            }
              
       
       
     cout<<"-------------------------------------------------------------------------------------------------------------------------\n";   
        
    }
    return 0;
}
