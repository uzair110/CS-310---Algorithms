#include <iostream> 
#include <string.h>
#include<fstream>
#include <bits/stdc++.h>
using namespace std; 

// The complexity of my algorithm is O(n^2) since it is a grid.



int c = 0;

string ans;

void tile(int startrow, int midrow, int startcol, int midcol, int row, int col, int** Darray)
{
    


    
    if (row<midrow && col < midcol)

    {    

        
        ans=ans+to_string(c)+" ("+to_string(midrow-1)+","+to_string(midcol)+")"+" ("+to_string(midrow)+","+to_string(midcol-1)+")"+" ("+to_string(midrow)+","+to_string(midcol)+")\n";
        Darray[midrow-1][midcol] = c;
        Darray[midrow][midcol-1] = c;
        Darray[midrow][midcol] = c;
        c++;

        if (midrow - startrow != 1)
        {
            tile(startrow, (startrow + midrow)/2, startcol, (startcol+midcol)/2, row, col,Darray);
            tile(startrow, (startrow + midrow)/2, midcol, (midcol - startcol)/2 + midcol, midrow-1, midcol,Darray);
            tile(midrow, (midrow - startrow)/2+midrow, startcol, (startcol+midcol)/2, midrow, midcol-1,Darray);
            tile(midrow, (midrow - startrow)/2+midrow, midcol, ((midcol-startcol)/2)+midcol, midrow, midcol,Darray);

        }
    }
    else if (row<midrow && col>=midcol)
    {
        
        ans=ans+to_string(c)+" ("+to_string(midrow-1)+","+to_string(midcol-1)+")"+" ("+to_string(midrow)+","+to_string(midcol-1)+")"+" ("+to_string(midrow)+","+to_string(midcol)+")\n";
        Darray[midrow-1][midcol-1] = c;
        Darray[midrow][midcol-1] = c;
        Darray[midrow][midcol] = c;
        c++;

        if (midrow - startrow != 1)
        {
            tile(startrow, (startrow+midrow)/2, startcol, (startcol+midcol)/2, midrow-1, midcol-1, Darray);
           tile(startrow, (startrow+midrow)/2, midcol, ((midcol-startcol)/2)+midcol, row, col,Darray);
            tile(midrow, (midrow-startrow)/2+midrow, startcol, (startcol+midcol)/2, midrow, midcol-1,Darray);
            tile(midrow, (midrow-startrow)/2+midrow, midcol, (midcol-startcol)/2+midcol, midrow, midcol,Darray);
                

        }


    }
    else if (row>=midrow && col < midcol)
    {
        
         ans=ans+to_string(c)+" ("+to_string(midrow-1)+","+to_string(midcol-1)+")"+" ("+to_string(midrow-1)+","+to_string(midcol)+")"+" ("+to_string(midrow)+","+to_string(midcol)+")\n";
        Darray[midrow-1][midcol-1] = c;
        Darray[midrow-1][midcol] = c;
        Darray[midrow][midcol] = c;
         c++;

        if (midrow - startrow != 1)
        {
            tile(startrow, (startrow+midrow)/2, startcol, (startcol+midcol)/2, midrow-1, midcol-1,Darray);
            tile(startrow, (startrow+midrow)/2, midcol, (midcol-startcol)/2+midcol, midrow-1, midcol,Darray);
            tile(midrow, (midrow-startrow)/2+midrow, startcol, (startcol+midcol)/2, row, col,Darray);
            tile(midrow, (midrow-startrow)/2+midrow, midcol, (midcol-startcol)/2+midcol, midrow, midcol,Darray);
        }
    }
    else if (row>=midrow && col >=midcol)
    {
        
        ans=ans+to_string(c)+" ("+to_string(midrow-1)+","+to_string(midcol-1)+")"+" ("+to_string(midrow-1)+","+to_string(midcol)+")"+" ("+to_string(midrow)+","+to_string(midcol-1)+")\n";
        Darray[midrow-1][midcol-1] = c;
        Darray[midrow-1][midcol] = c;
        Darray[midrow][midcol-1] = c;
        c++;

        if (midrow - startrow != 1)
        {
            tile(startrow, (startrow+midrow)/2, startcol, (startcol+midcol)/2, midrow-1, midcol-1, Darray);
            tile(startrow, (startrow+midrow)/2, midcol, (midcol-startcol)/2+midcol, midrow-1, midcol,Darray);
            tile(midrow, (midrow-startrow)/2+midrow, startcol, (startcol+midcol)/2, midrow, midrow-1,Darray);
            tile(midrow, (midrow-startrow)/2+midrow, midcol, (midcol-startcol)/2+midcol, row, col,Darray);

        }
    }


return;





}

int main(int argc, char** argv) 
{ 
    
    ifstream file;

    string line;
    string ch;
    file.open(argv[1]);
    getline(file, line);
    ch = line.substr(line.find(" ")); //Ignoring spaces and reading value of n
    const int n = stoi(ch);

    char bin;
    file>>bin;
    int c1;
    file>>c1;
    //c1 = stoi(c1);
    file>>bin;
    int c2;
    file>>c2;
   // c2 = stoi(c2);
    file>>bin;
    int** Darray;
    Darray = new int*[n];
     for (int i=0;i<n;i++)
     {
        Darray[i] = new int[n]; //declaring a 2D array for visualization purposes
     }

     

     Darray[c1][c2] = -1;

     



    tile(0, n/2,0,n/2,c1,c2, Darray);

   cout<<ans;

  


    //string ans = boomerang();
    //cout<<ans;

    return 0; 
} 
