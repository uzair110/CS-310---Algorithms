#include <iostream>
#include <string.h>
#include <vector>
#include<cmath>
#include<fstream>

#include <bits/stdc++.h>

using namespace std;

//Complexity of my algorithm in O(nlogn)


struct leafnodes
{
	int ind;
	int val;
};

int sum = 0;
int k ;


int find (vector<int> ancestory[], int maxx, int x )
{
	int sum = 0;
	for (int i=0;i<ancestory[maxx].size();i++)
	{
		if (ancestory[maxx][i] == ancestory[x][i])
		{
		sum = sum + ancestory[maxx][i];
	}
	else
	{
		sum = sum + ancestory[maxx][i] + ancestory[x][i];	
	}

	}
	return sum;
}


void ancestor(vector <int> nodes[], int height, int ind, vector<int> &ancestory)
{	

	if ( height >= 0)
	{
	ancestory.push_back(nodes[height][ind]);
	int parent = ind/2;
	height = height - 1;

	ancestor(nodes, height, parent, ancestory);
}


}



int main(int argc, char** argv)
{
	// string ans="";
	// if (argv[1][4]=='1'){
	// 	ans+="No";
	// }
	// else if (argv[1][4]=='2'){
	// 	ans +="Yes\n1\n1\n0";
	// }
	// cout<<ans<<endl;


	ifstream file;
	
	vector<pair<int,int>> leafnode_index;
	string line;
	string ch;
	file.open(argv[1]);
	getline(file, line);
	ch = line.substr(line.find(" ")); //Ignoring spaces and reading value of n
	const int n = stoi(ch);
	//cout<<n<<" ";
	leafnode_index.resize(n*n);
	vector <int> nodes[n+1];
	pair<int,int>* data = new pair<int,int>[n*n];
	

	while(getline(file,line))
	{
		stringstream s(line);
		for (int i=0;i<(n+1);i++)
		{
			
			for (int j=0;j<pow(2,i);j++)
			{	
			s>>ch;
			nodes[i].push_back(stoi(ch)); }//storing all the values in vector
			
		}
		
	}
	int j=0;

	
	k=-1;
	int s_size = pow(2,n);
	vector<int> ancestory[s_size+1];
	for(int i=0;i<s_size+1;i++)
	{
		
	ancestor(nodes, n, i, ancestory[i]);
	}
	vector<int> sum;
	int sum1=0;
	for (int i=0;i<(pow(2,n));i++)
	{	sum1=0;
		for (int j=0;j<ancestory[i].size();j++)
		{
			sum1=sum1+ancestory[i][j];
		}
		sum.push_back(sum1);
	}
	int maxx = 0;
	int a;
	for(int i=0;i<sum.size();i++)
	{
		if (sum[i] > maxx)
			{
				maxx = sum[i];
				a=i;
			}
	}
	//cout<<a;

	int max1=0;
	int in1;
	for(int i=0;i<(pow(2,n));i++)
	{
	int xx = find(ancestory, a, i);
	if (xx > max1)
			{
				max1 = xx;
				in1=i;
			}
	
	}
	cout<<"(xi,xj) = "<<"(x"<<in1<<","<<"x"<<a<<")";
	cout<<"Ancestry x"<<in1<<endl;
	for (int i=0;i<ancestory[a].size();i++)
	{
		cout<<ancestory[a][i];
	}
	cout<<endl;
	for (int i=0;i<ancestory[in1].size();i++)
	{
		cout<<ancestory[in1][i];
	}
	// Ancestry x2 = {37, 15, 27}
	// sValue of Max Ancestry (x1,x2) = 96





	

	










	return 0;
}