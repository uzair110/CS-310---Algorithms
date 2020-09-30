#include <iostream>
#include<fstream>
#include <string>
#include<vector>
#include<iomanip>
#include<sstream>
#include<queue>
#include<bits/stdc++.h>

using namespace std;
//class bipartitie


// add_edge(vector<char> list[], char u, char v)
// {
// 	cout<<"here";
// 	list[u].push_back(v);
// 	cout<<"here1";
// 	list[v].push_back(u);
// 	cout<<"here2";
// }

void printgraph(vector<vector<int>> vec)
{
	//cout<<"in print graph";
	for (int i=0;i<vec.size();i++)
	{
		vec[i].resize(vec[i].size());
		for (int j=0;j<vec[i].size();j++)
		{
			cout<<vec[i][j]<<" ";
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

	if (vec[a][a] == 1)
	{
		cout<<"No";
		return;
	}
	for (int i=0;i<x;i++)
	{
		c_array[i] = "color";
	}
	c_array[a] = "red";
	v2.push_back(a);

	while (!q.empty())
	{
		int b = q.front();
		q.pop();

		for (int j=0;j<x;j++)
		{
			if (vec[b][j] == 1 && c_array[j] == "color")
			{
				if (c_array[b] == "red")
				{
					c_array[j] = "blue";
					v1.push_back(j);

				}
				else if (c_array[b] == "blue")
				{
					c_array[j] = "red";
					//v2.push_back(a);
					v2.push_back(j);
				}
				q.push(j);
			}
			else if (vec[b][j] == 1 && c_array[b] == c_array[j])
			{

				int size0 = v1.size();
				int size11 = v2.size();
				for (int i=0;i<size0;i++)
					cout<<v1[i]<<"->";
				//cout<<endl;
				for (int i=0;i<size11;i++)
					cout<<v2[i]<<"->";
				cout<<endl;

				return;
			}


		}
	}
	int size = v1.size();
	int size1 = v2.size();
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

	//cout<<"here2";
  ifstream myfile ("test21.txt");

  if (myfile.is_open())
  {
  	myfile>>a>>b;
  	//b = (int)b - 48;
 	vector<vector<int>> v;
 	v.resize(b);
 	vector<int> e;

  	for (int i = 0; i < b; i++) {
 		v[i].resize(b);
        for (int j = 0; j < b; j++)
        {
            	v[i][j] = 0;
            	//cout<<v[i][j]<<" ";
        }

        //cout << endl;
    }


  		int num;
  		//int count = 0;

    for(int count=-1;count<b;count++)
    {

    	getline(myfile, line);
    	//cout<<"here count isss1 "<<count;


    	//cout<<f;
    	int s = line.length();
    	v[count].resize(s);
    	//cout<<"length "<<s;
    	for (int i=1;i<s;i++)
    	{

    		    		//cout<<"here";
     		//cout<<"here1";
    		if (line[i] == ':' || line[i] == ' ')
    			{

    				continue;
    			}
    		else{
    			 	num = (int)line[i] - 48;


    			 	v[count][num] = 1;

    			}
    		//cout<<"here3";
    	}
    }
    printgraph(v);
    bipartitite(v, b, 0);
    //cout<<result<<endl;
    myfile.close();
  }


  else cout << "Unable to open file";

	return 0;
}
