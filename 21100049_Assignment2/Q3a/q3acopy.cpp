#include <iostream> 
#include<fstream>
#include <bits/stdc++.h>
#include<vector>
#include<queue>
#include <string.h>
#include<string>
#include<utility>
using namespace std; 



struct vertex
{
	int neighbor;
	int weight;
};


bool sortweight(const pair <pair <int,int>, int> &p1, const pair <pair <int,int>, int> &p2)
{
	return (p1.second<p2.second);
}


int main(int argc, char** argv) 
{ 
   ifstream file;
	vector<double> all_numbers;
	vector< vector<vertex> > graph;
	vector<pair <pair <int,int>, int>> krus;
	vector<pair <pair <int,int>, int>> newkrus;
	string line;
	string ch;
	file.open("test23a.txt");
	getline(file, line);
	ch = line.substr(line.find(" ")); //Ignoring spaces and reading value of n
	int n = stoi(ch);
	vertex* data = new vertex[n];
	graph.resize(n);
	int i=0;
	while(getline(file,line))
	{
		
		int pos;
		int dest;
		int w;
		char ext;
		char bin;
		istringstream ss(line);
		int x=0;
		while (ss>>ch)
		{
			if (ch != ":") //ignoring colon
			{
				if (ch.length() == 1) // for single vertex
				{
					pos = stoi(ch);
					//cout<<pos<<" ";
					
				}
				if (ch.length() == 3) // for group of vertex and weight (eg 2;3 1;3)
				{
					istringstream sc(ch);
					{
						sc>>dest;
						sc>>bin;
						sc>>w;
						data[x].neighbor = dest;
						data[x].weight = w;
						//graph[i].push_back(data[x]);
						krus.push_back(make_pair(make_pair(i,dest),w));
		
						x++;
						

					}
				}
			
			}
		}
		//cout<<endl;
		i++;	
	}
	getline(file,line); //reading the edge to be removed.
	char bin;
	int f,s;
	pair <int,int> removed_edge;
	istringstream r_e(line);
	r_e>>bin;
	r_e>>f;
	r_e>>bin;
	r_e>>s;
	r_e>>bin;
	removed_edge.first = f;
	removed_edge.second = s;

	sort(krus.begin(),krus.end(),sortweight);



	for (int i=0;i<krus.size();i++)
	{
		cout<<krus[i].first.first<<" "<<krus[i].first.second<<" "<<krus[i].second<<endl;
	}

}