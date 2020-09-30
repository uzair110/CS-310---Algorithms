#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

//Complexity of this algorithm is O(V+E).
//Recurrence: O(V+E)
vector<vector<int>>lights;
int n;

void light_corridor_1(int root_node, int parent_node, bool visited[] ,bool lighting_corridor_1[], vector<vector<int>>lights)
{
    if (root_node == 0)
    {
        lighting_corridor_1[root_node]=true;
        visited[root_node]=true;
    }
    else
    {
        if (visited[root_node]==true)
            return;
        else
            visited[root_node]=true;
        if (lights[root_node].size()==2 && lights[root_node][1]==parent_node) //leafnode
        {
            if (lighting_corridor_1[parent_node]==true)
                return;
            else
            {
                lighting_corridor_1[parent_node]=true;
                return;
            }
        }
        
    }
    if (lighting_corridor_1[parent_node]==true)
    {
        lighting_corridor_1[parent_node]=true;
    }
    else
    {
        lighting_corridor_1[root_node]=true;
    }

    for (int i=1;i<lights[root_node].size();i++)
    {   
        //cout<<"child of "<<root_node<<" is "<< lights[root_node][i];
        //cout<<endl;
        light_corridor_1(lights[root_node][i], root_node, visited, lighting_corridor_1, lights);
    }

}

void light_corridor(int root_node, int parent_node, bool visited[] , bool lighting_corridor[], vector<vector<int>>lights)
{

    //case without root node
    if (root_node == 0)
	{
		lighting_corridor[root_node]=false;
        visited[root_node]=true;
	}
	else
	{
		if (visited[root_node]==true)
			return;
		else
			visited[root_node]=true;
		if (lights[root_node].size()==2 && lights[root_node][1]==parent_node) //leafnode
		{
			if (lighting_corridor[parent_node]==true)
				return;
			else
			{
				lighting_corridor[parent_node]=true;
				return;
			}
		}
        if (lighting_corridor[parent_node]==true)
        {
            lighting_corridor[parent_node]=true;
        }
        else
        {
            lighting_corridor[root_node]=true;
        }
	}
	

	for (int i=1;i<lights[root_node].size();i++)
	{	
		//cout<<"child of "<<root_node<<" is "<< lights[root_node][i];
		//cout<<endl;
		light_corridor(lights[root_node][i], root_node, visited, lighting_corridor, lights);
	}
}

int main(int argc, char** argv)
{
	ifstream file;
	vector<int> cuts;
	
	//cout<<"here3";
	
	string line;
	string ch;
	file.open(argv[1]);
	getline(file, line);
	ch = line.substr(line.find(" ")); //Ignoring spaces and reading value of n
	n = stoi(ch);
	lights.resize(n);	//cout<<n<<endl;
	bool visited[n];
	bool lighting_corridor[n];
    bool lighting_corridor_1[n];
	int i =0;
	while(getline(file,line))
	{
		stringstream ss(line);
		while(ss>>ch)
		{
			if (ch != ":")
			{
				lights[i].push_back(stoi(ch));
			}
		}
		i++;
	}
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}

	for (int i=0;i<n;i++)
	{
		lighting_corridor[i]=false;
	}

	for (int i=0;i<n;i++)
	{
		lighting_corridor_1[i]=false;
	}


	light_corridor(0,0,visited,lighting_corridor,lights);
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
    light_corridor_1(0,0,visited,lighting_corridor_1,lights);
	int c=0;
    int c1=0;
	for (int i=0;i<n;i++)
	{
		if (lighting_corridor[i]){
			c++;
		}
	}
    for (int i=0;i<n;i++)
    {
        if (lighting_corridor_1[i]){
            c1++;
        }
    }
    if (c1 <= c)
    {
	cout<<"Minimum Lights "<<c1<<endl;
	int counter=0;
    cout<<"{";
	for (int i=0;i<n;i++)
	{	
		if (counter==0){
		if (lighting_corridor_1[i]){
			counter++;
			cout<<i;
		}

	}
		else{
			if (lighting_corridor_1[i])
				cout<<", "<<i;
		}
	}
    cout<<"}";
    }
    else
    {
        cout<<"Minimum Lights "<<c<<endl;
    int counter=0;
    cout<<"{";
    for (int i=0;i<n;i++)
    {   
        if (counter==0){
        if (lighting_corridor[i]){
            counter++;
            cout<<i;
        }

    }
        else{
            if (lighting_corridor[i])
                cout<<", "<<i;
        }
    }
    cout<<"}";
    }	



	return 0;
}