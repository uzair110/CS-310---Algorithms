#include <iostream> 
#include<fstream>
#include <bits/stdc++.h>
#include<vector>
#include<queue>
#include <string.h>
#include<string>
#include<utility>
using namespace std; 
  
vector< pair <pair <int,int>, int>> mst;

struct vertex
{
	int neighbor;
	int weight;
};


bool sortweight(const pair <pair <int,int>, int> &p1, const pair <pair <int,int>, int> &p2)
{
	return (p1.second<p2.second);
}


struct mstsets {

	int* age; int* p;
	int size;

	mstsets(int size)
	{
		age = new int[size+1];
		p = new int[size+1];
		this->size = size;

		for (int i=0;i<size;i++)
		{
			age[i] = 0;
			p[i] = i;
		}
	}


	int findparent(int a)
	{
		if ( a != p[a])
		{
			p[a] = findparent(p[a]);
		}
		return p[a];
	}


	void join(int a, int b)
	{
		a=findparent(a);
		b=findparent(b);

		if (age[a] < age[b])
		{
			p[b] = a;
		}
		else 
		{
			p[a]=b;
		}
		if(age[a]==age[b])
			age[b]++;
	}




};

int kruskal(vector<pair <pair <int,int>, int>> g, int size)
{
	int all_w = 0;
	mstsets ms(size);
	vector<pair <pair <int,int>, int>>::iterator i;
	int counter=0;
	cout<<"MST1: ";

	for (int i=0;i<g.size();i++)
	{
		int a = g[i].first.first;
		int b = g[i].first.second;
		int c = g[i].second;//
		int a_a = ms.findparent(a);
		int b_b = ms.findparent(b);


		if (a_a != b_b)
		{
			mst.push_back(make_pair(make_pair(a,b),c));
			if(counter==0)
			{
			cout<<"("<<a<<","<<b<<")";
			counter++;
		}
			else
			{
				cout<<" "<<"("<<a<<","<<b<<")";
			}

			all_w = all_w + g[i].second;

			ms.join(a_a,b_b);
		}


	}

	return all_w;


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
	file.open(argv[1]);
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
						graph[i].push_back(data[x]);
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

	
	int sum = kruskal(krus,n);
	cout<<endl;
	cout<<"Sum MST1: "<<sum<<endl;

	cout<<"Edge Removed: "<<"("<<removed_edge.first<<","<<removed_edge.second<<")"<<endl;

	for (int i=0;i<krus.size();i++)
	{
		if ((krus[i].first.first != removed_edge.first || krus[i].first.second != removed_edge.second) && (krus[i].first.first != removed_edge.second || krus[i].first.second != removed_edge.first) )
			newkrus.push_back(krus[i]);
	}	

	vector<pair <pair <int,int>, int>> newmst;
	newmst.resize(mst.size()-1);
	for(int i=0;i<mst.size();i++)
	{
		if ((mst[i].first.first != removed_edge.first || mst[i].first.second != removed_edge.second) && (mst[i].first.first != removed_edge.second || mst[i].first.second != removed_edge.first) )
			newmst.push_back(mst[i]);
		//cout<<newmst[i].first.first<<newmst[i].second.second<<endl;
	}

	int all_w = 0;
	int counter=0;
	mstsets ms(n);
	cout<<"MST2: ";
	for (int i=0;i<newkrus.size();i++)
	{
		int a = newkrus[i].first.first;
		int b = newkrus[i].first.second;
		int c = newkrus[i].second;

		int a_a = ms.findparent(a);
		int b_b = ms.findparent(b);


		if (a_a != b_b)
		{	
			mst.push_back(make_pair(make_pair(a,b),c));
			if(counter==0)
			{
			cout<<"("<<a<<","<<b<<")";
			counter++;
		}
			else
			{
				cout<<" "<<"("<<a<<","<<b<<")";
			}

			all_w = all_w + newkrus[i].second;

			ms.join(a_a,b_b);
		}


	}
	
	cout<<endl;
	cout<<"Sum MST2: "<<all_w;



	


 //    return 0; 
} 
