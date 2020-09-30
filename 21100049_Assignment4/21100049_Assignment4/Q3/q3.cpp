#include <iostream> 
#include <string.h>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

// Time Complexity = O(mlogm)
// Recurrence = min(rod_cutting(n, all m))

vector<int> rod_cutting(int size, std::vector<int> ruler_cut)
{
	vector<int> sum;
	int minimum = 1000000;
	int cost;
	if (ruler_cut.size()==0)
	{
		sum.push_back(0);
		return sum;
	}
	if (ruler_cut.size()==1)
	{
		sum.push_back(size);
		sum.push_back(ruler_cut[0]);
		return sum;
			
	}

	for (int i=0; i<ruler_cut.size();i++)
	{
		vector<int> after_cut;
		vector<int> before_cut;
		int j =0;
		while(j<ruler_cut.size())
		{
			if (j != i)
			{
				if (ruler_cut[i] > ruler_cut[j])
				{
					before_cut.push_back(ruler_cut[j]);
				}
				else
				{
					after_cut.push_back(ruler_cut[j]-ruler_cut[i]);
				}
			}
			j++;
		}


		vector<int> right_cut=rod_cutting(ruler_cut[i], before_cut);
		vector<int> left_cut=rod_cutting(size-ruler_cut[i], after_cut);
		cost = right_cut[0] + left_cut[0] + size;

		if (cost < minimum)
		{
			vector<int> new_cut;
			minimum = cost;
			new_cut.push_back(cost);
			new_cut.push_back(ruler_cut[i]);
			for(int x=1;x<right_cut.size();x++)
			{
				new_cut.push_back(right_cut[x]);
			}
			for(int y=1;y<left_cut.size();y++)
			{
				new_cut.push_back(left_cut[y]+ruler_cut[i]);
			}
			sum=new_cut;

		}
	}
	return sum;
}
  
int main(int argc, char** argv) 
{ 
	//Answering Format
	//Grader is not Endline or Space Sensitive
	ifstream file;
	vector<int> cuts;
	//cout<<"here3";
	
	string line;
	string ch;
	file.open(argv[1]);
	getline(file, line);
	ch = line.substr(line.find(" ")); //Ignoring spaces and reading value of n
	const int n = stoi(ch);
	//cout<<n<<endl;
	getline(file,line);
	stringstream s(line);
	while(s>>ch)
	{	
		if (ch != "m")
			cuts.push_back(stoi(ch));
	}

	std::vector<int> min_cost = rod_cutting(n,cuts);
	// string ans;
	// ans +="Optimal cut ordering: 5 3 10     \n";
	// ans +="Least Cost: 30 \n\n";
	string ans = "Optimal cut ordering: ";
   	for(int i=1;i<min_cost.size();i++)
   		ans += to_string(min_cost[i]) + " ";
   	ans += "\n";
   	ans += "Least cost: " + to_string(min_cost[0]) + "\n";
   	cout<<ans;
    return 0; 
} 
