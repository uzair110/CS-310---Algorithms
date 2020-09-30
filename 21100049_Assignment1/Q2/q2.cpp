#include <iostream>
#include <vector>
#include<fstream>
#include<queue>
#include<stack>
using namespace std;

//Complexity s 

void printgraph(vector<vector<int>> v, int b)
{
	for (int i=0;i<b;i++){
		//cout<<i<<" ";
		for(int j=0;j<v[i].size();j++)
		{
			//cout<<v[i].size();
			cout<<v[i][j];
			//cout<<v[i][j];
		}
		cout<<endl;
	}
}

	int t = 0;
	int c =0;
queue<int> dfs(int a, bool vis[], int anc[], int lval[], int dtime[], vector<vector<int>> v)
{
	vis[a] = true;
	dtime[a] = t++;
	lval[a] = t++;
	queue<int> q1;
	queue<int> q2;

        //cout<<"here1";
		for(int j=1;j<v[a].size()-1;j++)
		{
			if (vis[v[a][j]] == false)
			{
                //cout<<"here2";
				anc[v[a][j]] = a;
				dfs(v[a][j], vis, anc, lval, dtime, v);
				lval[a] = min(lval[a],lval[v[a][j]]);
				//dtime[visv[i][j]] = d++;


                //cout<<"here3";
				if (lval[v[a][j]] > dtime[a])
				{
				    c++;
				    q1.push(a); //small
				    q1.push(v[a][j]);//big
                    //cout<<"("<<a<<","<<v[a][j]<<")";
				}
				//cout<<endl;
			}
			else if (v[a][j] != anc[a])
					lval[a] = min(lval[a],dtime[v[a][j]]);
			
		}
			return q1;
		



		// while(!q1.empty() && !q2.empty())
		// {
		// 	int x = q1.front();
		// 	q1.pop();
		// 	int y = q2.front();
		// 	q2.pop();
		// 	//cout<<c<<endl;
		// 	cout<<"("<<x<<","<<y<<")";
		// 	cout<<endl;
		// }
		
	}


void isConnected(vector<vector<int>> v2, int x)
{
	bool vstd[x];
	int ancestor[x];
	int lowval[x];
	int disctime[x];
	queue<int> q1;
	std::vector<int> v1;
	//cout<<"here";
	for (int i=0;i<x;i++)
	{
		ancestor[i] = -1;
		lowval[i]=0;
		disctime[i]=0;
		vstd[i]= false;
	}

	

	for (int i=0;i<x;i++)
	{
		if (vstd[i]==false)
			q1=dfs(i,vstd,ancestor,lowval,disctime, v2);
	}

	//cout<<q1.size()/2<<endl;
	while (!q1.empty())
	{
		int x = q1.front();
		q1.pop();
		v1.push_back(x);
		//cout<<x<<endl;
	}


	cout<<v1.size()/2<<endl;

	 for (int i = 0; i < v1.size()/2; ++i)
	{
	 	cout<<"("<<v1[i*2]<<","<<v1[i*2+1]<<")"<<endl;
	 }



}



struct graph
{
	int vertex;
	vector<int> edges;
};

int main(int argc, char** argv)
{

string line;
	char a;
	int b;


  ifstream myfile ("test12.txt");

  if (myfile.is_open())
  {
  	myfile>>a>>b;
  	//b = (int)b - 48;
 	vector<vector<int>> v;
 	v.resize(b);
 	vector<int> e;



  		int num;
  		int num2;


    for(int count=-1;count<b;count++)
    {

    	getline(myfile, line);

    	int s = line.length();
    	//cout<<"length"<<s;
    	//v[count].resize(s);
    	//cout<<count<<" ";

    	for (int i=0;i<s;i++)
    	{

    		if (line[i] == ':' || line[i] == ' ')
    			{

    				continue;
    			}

    		// else if ((line[i] != ':' || line[i] != ' ') && (line[i+1] != ':' || line[i+1] != ' '))
    		// 	{
    		// 		num = (int)line[i] - 48;
    		// 		num2 = (int)line[i] - 48;

    		// 		num = (num*10)+num2;
    		// 		v[count].push_back(num);
    		// 	}
    		else{
    			 	num = (int)line[i] - 48;

    			 	v[count].push_back(num);


    			}

    	}
    }


    myfile.close();
    //printgraph(v,b);
    isConnected(v, b);



}
  else cout << "Unable to open file";
	return 0;
}



	// string x = argv[0];
	// vector<int> v;
	// v.push_back(0);
	// v.push_back(1);
	// v.push_back(2);
	// v.push_back(5);

	// cout<<v.size()/2<<endl;
	// for (int i = 0; i < v.size()/2; ++i)
	// {
	// 	cout<<"("<<v[i*2]<<","<<v[i*2+1]<<")"<<endl;
	// }


