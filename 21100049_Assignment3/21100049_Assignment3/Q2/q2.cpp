#include <iostream>
#include <vector>
#include<fstream>

#include <bits/stdc++.h>

using namespace std;



//The complexity of my algorithm in O(nlogn) since I have used merge sort which has a complexity if O(nlogn)
//I have vectors of pairs, which are saving days and corresponding values of immune cells.
//This algorithm makes use of Divide and Conquer method which makes its complexity O(nlogn).

struct day_cells
{
	int day;
	int value;
};



int counter= 0;
vector<pair<int,int>> info;


void merge(vector<int> all_numbers, int l, int m, int r) // -------- O(nlogn)
{ 
	
    int a;
    int b;
    int c;
    int a1 = m-l+1; 
    int b1= r-m; 
    int L[a1];

    int R[b1];
    
    for (a = 0; a < a1; a++) {


        L[a] = all_numbers[l + a]; 
    }
    
    for (b = 0; b < b1; b++) {
        R[b] = all_numbers[m + 1+ b]; 
    }
  
    
    a = 0; 
    b = 0; 
    c = l; 

    while (a < a1 && b < b1) 
    { 
        if (L[a] <= R[b]) 
        { 
            //all_numbers[k] = L[i]; 
            a++; 
        } 
        else
        { 
            all_numbers[c] = R[b]; 
            if (R[b] < L[a]/2)
            {
            	counter++;
            	info.push_back(make_pair(m+1+b,l+a));
            }
            
            b++; 
        } 
       
       c++; 
    } 
  
   
    while (a < a1) 
    { 
        a++; 
        c++; 
    }
    
    while (b < b1) 
    {   
        b++; 
        c++; 
    } 
} 
  

void mergesort(vector<int> all_numbers, int Left, int right) 
{ 
    if (Left < right) 
    { 
        
        int middle = (Left+right)/2; 

        mergesort(all_numbers, Left, middle); 
        mergesort(all_numbers, middle+1, right); 
  
        merge(all_numbers, Left, middle, right); 
    } 
} 

int main(int argc, char** argv)
{
	ifstream file;
	//cout<<"here3";
	vector<int> all_numbers;
	
	string line;
	string ch;
	file.open(argv[1]);
	getline(file, line);
	ch = line.substr(line.find(" ")); //Ignoring spaces and reading value of n
	const int n = stoi(ch);
	day_cells* data = new day_cells[n];
	//cout<<"here";

	while(getline(file,line))
	{
		stringstream s(line);
		int x  = 0;
		while (s>>ch)
		{		
				
				data[x].day = x;
				data[x].value = stoi(ch);
				all_numbers.push_back(stoi(ch)); //storing all the values in vector
				x++;

		}

	}
	int s = all_numbers.size()-1;
	//vector<day_cells> half_numbers(all_numbers.size());
	//half_numbers.resize(s+1);
	//cout<<"here";

	mergesort(all_numbers, 0, all_numbers.size()-1);
	// 

	cout<<"Failed Trials "<<counter<<endl;
	for(int i = 0; i<info.size(); i++)
	{
		
			cout << "(" << info[i].first << "," << info[i].second << ")" ;
			cout << endl;
	}

	
	
	return 0;
}

