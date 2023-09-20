#include<bits/stdc++.h>
using namespace std;

int solve_dp(int table[][50],int row, int col)
{

    cout<<"Your DP table"<<endl;

    int DP_Table[row][col];

    DP_Table[0][0] = table[0][0];

    // col zero and row 1,2,3....n
    for(int i=1; i<row; i++)
    {
        DP_Table[i][0] = table[i][0]+DP_Table[i-1][0];
    }
    // row zero and col 1,2,3....n
    for(int j=1; j<col; j++)
    {
        DP_Table[0][j] = table[0][j]+DP_Table[0][j-1];
    }

    for(int i=1; i<row; i++)
    {

        for(int j=1; j<col; j++)
        {
            int minmum = min(DP_Table[i-1][j],DP_Table[i][j-1]);
            DP_Table[i][j] = table[i][j] + minmum;

        }
    }

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout<<DP_Table[i][j]<<"\t";

        }
        cout<<endl;
        cout<<endl;
    }

    return DP_Table[row-1][col-1];
}

 // Greedy
    int solve_greedy(int table[][50], int row, int col) {

        cout<<endl;
        cout<<endl;

        cout<<"Your Greedy table"<<endl;

        int greedyTable[row][col];

        greedyTable[0][0] = table[0][0];

        //  the first row
        for (int i = 1; i < row; i++) {
            greedyTable[i][0] = table[i][0] + greedyTable[i - 1][0];
        }

        //  the first column
        for (int j = 1; j < col; j++) {
            greedyTable[0][j] = table[0][j] + greedyTable[0][j - 1];
        }

        //  greedy table
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                int minimum = min(greedyTable[i - 1][j], greedyTable[i][j - 1]);
                greedyTable[i][j] = table[i][j] + minimum;
            }
        }

        for(int i=0; i<row; i++)
      {
        for(int j=0; j<col; j++)
        {
            cout<<greedyTable[i][j]<<"\t";

        }
        cout<<endl;
        cout<<endl;
      }


    return greedyTable[row - 1][col - 1];
}

int main()
{
    int row,col;
    cout<<"Enter total number of row = "<<endl;
    cin>>row;

    cout<<"Enter total number of column = "<<endl;
    cin>>col;

    // input table
    int table[50][50];

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cin>>table[i][j];
        }
        cout<<endl;
    }

    //Show table
    cout<<"Your given table\n"<<endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout<<table[i][j]<<"\t";
        }
        cout<<endl;
        cout<<endl;
    }

    int path_cost_dp = solve_dp(table,row,col);

    cout<<"Minimum path cost using dp= "<<path_cost_dp<<endl;

     int path_cost_greedy = solve_greedy(table,row,col);
     cout<<"Minimum path cost using greedy = "<<path_cost_greedy<<endl;

    return 0;
}
