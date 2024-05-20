#include<bits/stdc++.h>

using namespace std;

#define red "\033[1;31m*\033[0m ";
#define blue "\033[1;34m*\033[0m ";

bool check(int i, int j, int color, int n, vector<vector<int>>&board){
    //return true on violation

    //consecutive row check
    if(j==0){
        if(board[i][j+1] == color && board[i][j+2] == color){
            return true;
        }
    }
    else if(j==n-1){
        if(board[i][j-1] == color && board[i][j-2] == color){
            return true;
        }
    }
    else if(board[i][j-1] == color && board[i][j+1] == color){
            return true;
    }
    else if(j>1 && board[i][j-1] == color && board[i][j-2] == color){
        return true;
    }
    else if(j<n-2 && board[i][j+1] == color && board[i][j+2] == color){
        return true;
    }


    //consecutive column check
    if(i==0){
        if(board[i+1][j] == color && board[i+2][j] == color){
            return true;
        }
    }
    else if(i==n-1){
        if(board[i-1][j] == color && board[i-2][j] == color){
            return true;
        }
    }
    else if(board[i-1][j] == color && board[i+1][j] == color){
            return true;
    }
    else if(i>1 && board[i-1][j] == color && board[i-2][j] == color){
        return true;
    }
    else if(i<n-2 && board[i+1][j] == color && board[i+2][j] == color){
        return true;
    }
    
    //number of colors in row check
    int count = 0;
    for(int x=0;x<n;x++){
        if(board[i][x] == color){
            count++;
        }
        if(count > n/2){
            return true;
        }
    }

    //number of colors in column check
    count = 0;
    for(int x=0;x<n;x++){
        if(board[x][j] == color){
            count++;
        }
        if(count > n/2){
            return true;
        }
    }


    //Two rows identical check
    set<vector<int>>s;
    vector<int>identical;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            identical.push_back(board[i][j]);
        }
        if(s.find(identical) != s.end()){
            return true;
        }
        s.insert(identical);
        identical.clear();
    }
    
    
    //Two columns identical check
    s.clear();
    identical.clear();
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            identical.push_back(board[i][j]);
        }
        if(s.find(identical) != s.end()){
            return true;
        }
        s.insert(identical);
        identical.clear();
    }
    
    //Cell has no violation
    return false;
}

bool solve(int i, int j, int n, vector<vector<int>>&board){

    int complete_flag = 1;

    //Fill blue
    board[i][j] = 1;
    if(check(i,j,1,n,board) == false){
        int xi,xj;
        
        for(xi=0;xi<n;xi++){
            for(xj=0;xj<n;xj++){
                if(board[xi][xj] == 0){
                    complete_flag = 0;
                    if(solve(xi,xj,n,board) == true){
                        return true;
                    }
                    goto checkpoint1;
                }
            }
        }
        //If complete flag is still up, that means all cells are filled and we have reached a solution
        if(complete_flag == 1){
            return true;
        }
    }
    
    checkpoint1:

    //Fill red
    board[i][j] = 2;
    if(check(i,j,2,n,board) == false){
        int xi,xj;
        for(xi=0;xi<n;xi++){
            for(xj=0;xj<n;xj++){
                if(board[xi][xj] == 0){
                    complete_flag = 1;
                    if(solve(xi,xj,n,board) == true){
                        return true;
                    }
                    goto checkpoint2;
                }
            }
        }
        //If complete flag is still up, that means all cells are filled and we have reached a solution
        if(complete_flag == 1){
            return true;
        }
    }

    checkpoint2:

    
    //Both cases failed, return false
    board[i][j] = 0;
    return false;

}

int main(){
    
    //Enter dimension
    int n;
    cout<<"Enter dimension : ";
    cin>>n;

    //Make the board
    vector<vector<int>>board(n,vector<int>(n,0));

    //Update the board with the given board in the game
    cout<<"Enter board : \n";
    cout<<"Press 1 for Blue, 2 for Red, 0 for blank\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }

    //Print the current board
    cout<<"Current board : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] == 1){
                cout<<blue;
            }
            else if(board[i][j] == 2){
                cout<<red;
            }
            else
                cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }

    //Solve the board
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] == 0){
                solve(i,j,n,board);
                break;
            }
        }
    }

    //Print the solution board
    cout<<"Solved board : "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] == 1){
                cout<<blue;
            }
            else if(board[i][j] == 2){
                cout<<red;
            }
            else
                cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}

/*
1 0 1 0
0 0 0 2
0 0 1 0
0 0 0 0
*/