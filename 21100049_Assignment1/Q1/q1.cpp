#include <iostream>
#include<fstream>
#include <string>
#include<vector>
#include<iomanip>
#include<sstream>
#include<queue>
#include<bits/stdc++.h>

using namespace std;

//My Algorithms runs on DFS, where each vertex and each vertex is visited only one time
// Running time complexity is O(|V|+|E|)

//I have used vectors of vectors making them an adjacency list.
void printgraph(vector<vector<int>> v, int b)
{
	for (int i=0;i<b;i++){
		
		for(int j=0;j<v[i].size();j++)
		{	
		
			cout<<v[i][j];
		}
		cout<<endl;
	}
}



void bipartitite(vector<vector<int>> vec, int x, int a)
{
	queue<int> q;
	std::vector<int> v1;
	std::vector<int> v2;
	q.push(a);
	string c_array[x];

	
	for (int i=0;i<x;i++)
	{
		c_array[i] = "color"; // Source node color 
	}
	c_array[a] = "red";
	v2.push_back(a);	// pushed into queue

	while (!q.empty())
	{
		int b = q.front();
		q.pop();

		for (int j=1;j<vec[b].size()-1;j++)
		{
			if (c_array[vec[b][j]] == "color")
			{
					//cout<<"here";
				if (c_array[b] == "red")
				{
					c_array[vec[b][j]] = "blue";
					v1.push_back(vec[b][j]);

				}
				else if (c_array[b] == "blue")
				{
					c_array[vec[b][j]] = "red";
					//v2.push_back(a);
					v2.push_back(vec[b][j]);
				}
				q.push(vec[b][j]);
			}
			else if (c_array[b] == c_array[vec[b][j]])
			{

				int size0 = v1.size();
				int size11 = v2.size()-1;
				for (int i=0;i<size0;i++)
					cout<<v1[i]<<"->";
				//cout<<endl;
				for (int i=0;i<size11;i++)
					cout<<v2[i]<<"->";
				cout<<v2[v2.size()];

				return;
			}
			

		}
	}
	int size = v1.size();
	int size1 = v2.size();
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	cout<<"Yes"<<'\n';
	for (int i=0;i<size;i++)
		cout<<v2[i]<<" ";
	cout<<endl;
	for (int i=0;i<size1;i++)
		cout<<v1[i]<<" ";
	cout<<endl;
	return;
}

int main(int argc, char** argv)
{
	string line;
	char a; 
	int b;
	
  ifstream myfile ("test21.txt");

  if (myfile.is_open())
  {
  	myfile>>a>>b;
  	//cout<<b;
  	//b = (int)b - 48;
 	vector<vector<int>> v;
 	v.resize(b);
       
   		int num;

    for(int count=-1;count<b;count++)
    {
		//cout<<"here2";
    	
    	getline(myfile, line);
   
    	int s = line.length();
    	
    	for (int i=0;i<s;i++)
    	{	
    		
    		if (line[i] == ':' || line[i] == ' ')
    			{
    				
    				continue;
    			}
    		else{
    			 	//cout<<i<<" ";
    			 	num = (int)line[i] - 48; 
    			 	//cout<<num<<" ";	
    			 	v[count].push_back(num);
    			 	
    			}  	
    		
    	}
    	//cout<<endl;
    }
 // printgraph(v, b);
    bipartitite(v, b, 0);
    //cout<<result<<endl;
    myfile.close();
  
}
  else cout << "Unable to open file"; 


	return 0;
}
