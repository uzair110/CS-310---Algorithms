#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;

void handle_line(string line, vector<vector<int> > &arr){
	char* c_line = new char[line.size()+1]; 
	strcpy(c_line, line.c_str());			//make copy of line 
	
	char* token = strtok(c_line, "C;:, "); 	//removing all C colons commas and spaces
	int pos  = stoi(token);					//first token is the origin node	

	token = strtok(NULL, "C;:, ");
	while(token!=NULL){
		arr[pos].push_back(stoi(token));	//rest nodes are dest nodes for that origin node
		token = strtok(NULL, "C;:, ");
	}
}

void read_file(string fname){
	ifstream file;
	file.open(fname);
	
	string line = "";
	getline(file, line);
	
	int num_nodes = stoi(line.substr(line.find(' ')));	//read value of n
	vector< vector<int> > graph(num_nodes);
	
	while(!file.eof())
	{
		getline(file, line);
		handle_line(line, graph);		
	}

	for (int i = 0; i < graph.size(); ++i) 				//print the adjacency list
	{
		cout<<i<<" : ";
		for (int j = 0; j < graph[i].size(); ++j)
		{
			cout<<graph[i][j]<< " ";
		}
		cout<<endl;
	}
}

int main()
{
	read_file("test13a.txt");	
	return 0;
}