#include <iostream> 
#include <string.h>
#include<stack>
#include<queue>
#include<vector>
#include<fstream>
using namespace std; 
 
//My Algorithms runs on BFS, where each vertex and each vertex is visited only one time
// Running time complexity is O(|V|+|E|)

//It calculates indegrees of the vertexes and starts with the vertex with no indegree
//It then removes the first vertex and then its child and run dfs on it until there are 
//no vertices left. It prints the topological sort.

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

void T_sort(int b, vector<vector<int>> v1)
{
	int visited = 0;
	queue<int> q;
	int indegree[b];
	for(int i=0;i<b;i++)
		indegree[i]=0;

	for (int i=0;i<b;i++)
	{	
		//cout<<i<<" ";
		int num = v1[i].size()-1;
		
		for (int j=1;j<v1[i].size();j++)
		{	
			
			indegree[v1[i][j]]++;
			
		}


		

	}


	for (int i=0;i<b;i++)
	{
		if (indegree[i] == 0)
		{	
			//cout<<i<<" ";
			q.push(i);
		}
	}

	std::vector<int> stack;
	std::vector<int> visi;
	queue<int> ss;
	while (!q.empty())
	{
		int a =q.front();
		//cout<<a;
		q.pop();

	
		stack.push_back(a);

		int s = v1[a].size();

		if (s != 0)
		{
			for (int i=0;i<s;i++)
			{
				indegree[v1[a][i]]--;

				if (indegree[v1[a][i]] == 0)
				{	
				
					q.push(v1[a][i]);
				}

			}
		}

		visited++;
	}
		vector<int> mv;


		if (visited != b)
		{	

			cout<<"No";

			for(int i=0;i>stack.size();i--)
			{
				cout<<stack[i]<<" ";
				mv.push_back(stack[i]);
			}

			return;
		}

		cout<<"Yes";
		cout<<endl;
		for (int c=0;c<stack.size()-1;c++)
		{
			cout<<stack[c]<<" ";
		}
		cout<<stack[stack.size()-1];
		return;



	}

int main(int argc, char** argv)
{
	string line;
	char a; 
	int b;
	
  ifstream myfile ("test3.txt");

  if (myfile.is_open())
  {
  	myfile>>a>>b;
 	vector<vector<int>> v;
 	v.resize(b);
       
   		int num;

    for(int count=-1;count<b;count++)
    {
		//cout<<"here2";
    	
    	getline(myfile, line);
   
    	int s = line.length();
    	//cout<<s;
    	for (int i=0;i<s;i++)
    	{	
    		
    		if (line[i] == ':' || line[i] == ' ')
    			{
    				
    				continue;
    			}
    		else{
    			 	//cout<<i<<" ";
    			 	num = (int)line[i] - 48; 
    			 	
    			 	//cout<<num;
    			 	v[count].push_back(num);
    			 	
    			}  	
    		
    	}
    	//cout<<endl;
    }
    //printgraph(v,b);
   	T_sort(b,v);
    myfile.close();
  
}
  else cout << "Unable to open file"; 


	return 0;
}
