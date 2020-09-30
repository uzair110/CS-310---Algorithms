#include <iostream>
#include <fstream>
#include<string>
#include <bits/stdc++.h>
using namespace std;



int main(int argc, char** argv)
{

	ifstream file;
	vector<int> r_c_numbers;
	string line;
	string ch;
	file.open(argv[1]);
	getline(file, line);
	ch = line.substr(line.find(" ")); //Ignoring spaces and reading value of n
	const int n = stoi(ch);

	while(getline(file,line))
	{
		stringstream s(line);
		while (s>>ch)
		{
			if (ch != "Row" && ch != "Col")
			{

				r_c_numbers.push_back(stoi(ch)); //storing all the rows and column values in vector
			}
		}
	}

	vector<int> rows;
	vector<int> columns;
	int sizee = r_c_numbers.size();
	for(int i = 0; i < sizee/2;  i++)
	{
		//cout<<r_c_numbers[i];
		rows.push_back(r_c_numbers[i]); //Storing rows in a different vector 
	}
	//cout<<endl;
	for(int i = sizee/2; i<sizee;i++)
		columns.push_back(r_c_numbers[i]); //storing columns in a different vector

	

	 int** Darray = new int*[n];
	 for (int i=0;i<n;i++)
	 {
	 	Darray[i] = new int[n]; //declaring a 2D array for visualization purposes
	 }

	//Initialising array
	 for (int i=0;i<n;i++)
	 {
	 	for (int j=0;j<n;j++)
	 	{
	 		Darray[i][j] = 0;
	 	}
	 }

	
	//Algorithm starts here --------- Complexity O(n^2)
	 for (int i=0;i<n;i++) // O(n+1) == O(n)
	 {
	 	int counter=0;
	 	int j=0;
	 	
	 	while (counter < rows[i])  // O(n) worst case when all n values are filled.
	 	{
	 	
	 		if (columns[j] != 0 && j < n)
	 		{
	 			Darray[i][j] = 1;
	 			counter++;
	 			columns[j]--;
	 			j++;
	 		}
	 		else
	 		{
	 			j++;
	 			if (j > n)
	 			{
	 				cout<<"Not Possible\n";
	 				return 0;
	 			}
	 		}
	 	}
	 
	 } // Algorithm ends here

	  
	 bool check = false;
	 for (int i=0;i<n;i++)
	 {
	 	if (columns[i] != 0)
	 	{
	 		cout<<"Not Possible\n";
	 		check = true;
	 		return 0;
	 	}
	 }
	 string ans = "";
	 if (check == false)
	 {
		for (int i=0;i<n;i++)
		 {
		 	int counter = 0;
		 	for (int j=0;j<n;j++)
		 	{
		 		if (Darray[i][j] == 1)
		 		{
		 			if (counter == 0){
		 				cout <<"("<<i+1<<","<<j+1<<")";
		 				counter++;		 				
		 			}else{
		 				cout <<" ("<<i+1<<","<<j+1<<")";		 				
		 			}
		 		}
		 	}
		 cout<<"\n";
		 }
	 }

	// string ans ="";
	// if (argv[1][4]=='1'){
	// 	ans+="(5,1) (5,2) (5,3)\n";
	// 	ans+="(4,1) (4,2) (4,3)\n";
	// 	ans+="(3,3)\n";
	// 	ans+="(2,3) (2,4) (2,5)\n";
	// 	ans+="(1,2) (1,4) (1,5)\n";
	// }
	// else if (argv[1][4]=='2'){
	// 	ans+="Not Possible\n";
	// }
	// cout<<ans;
	return 0;
}