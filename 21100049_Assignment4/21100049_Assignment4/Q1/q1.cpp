#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
 
using namespace std;
//Recurrence relation : max((revenue_high[no_of_week] + Max_Revenue(no_of_week-2)), (revenue_low[no_of_week] + Max_Revenue(no_of_week-1)));
//Time Complexity: O(n), since we have used memoization.
//Vectors and arrays have been implemented.

vector<int> revenue_high;
std::vector<int> revenue_low;
vector<int> memo;
int x;
std::vector<string> outcomes;


struct info
{
	int value;
	int week;
};

info* data;

int Max_Revenue(int no_of_week)
{
	//cout<<no_of_week<<" ";
	if (memo[no_of_week] < 0 )
	{
		//cout<<" "<<revenue_high[5]<<" ";
		int high_revenue = revenue_high[no_of_week] + Max_Revenue(no_of_week-2);
		int low_revenue = revenue_low[no_of_week] + Max_Revenue(no_of_week-1);
		// cout<<high_revenue<<" "<<low_revenue;
		// cout<<endl;
		memo[no_of_week] = max((revenue_high[no_of_week] + Max_Revenue(no_of_week-2)), (revenue_low[no_of_week] + Max_Revenue(no_of_week-1)));
		if (high_revenue > low_revenue)
		{
		//cout<<no_of_week<<endl;
		outcomes[no_of_week]="high";
		}
		else
		{
			outcomes[no_of_week]="low";
		}

	}

	return memo[no_of_week];
}

void Parse_date(string filename)
{
	ifstream file;
	//cout<<"here3";
	
	string line;
	string ch;
	file.open(filename);
	getline(file, line);
	ch = line.substr(line.find(" ")); //Ignoring spaces and reading value of n
	const int n = stoi(ch);
	memo.resize(n);
	data = new info[n+1];
	outcomes.resize(n);

	getline(file,line);
	stringstream s(line);
	for (int i=0 ; i < n+1; i++)
		{
			s>>ch;
			if (ch != "RH")
			{
				revenue_high.push_back(stoi(ch));
			}
		}

	getline(file, line);
	stringstream ss(line);
	for (int i=0 ; i < n+1; i++)
		{
			ss>>ch;
			if (ch != "RL")
			{
				revenue_low.push_back(stoi(ch));
			}
		}

	memo[0]=max(revenue_high[0],revenue_low[0]);
	if (revenue_high[0] > revenue_low[0])
	{
		outcomes[0]="high";
	}

	for (int i=1;i<n;i++)
	{
		memo[i]=-1;
	}

	x = Max_Revenue(n-1);


}



int main(int argc, char** argv)
{
	
	Parse_date(argv[1]);
	for(int i=outcomes.size()-1;i>=0;i--)
	{

		if (outcomes[i]=="high")
		{
			outcomes[i-1]="priming";

		}
	}
	

	for(int i=0;i<outcomes.size();i++)
	{	
		cout<<"Week "<<i+1<<" : ";
		if (outcomes[i]=="high")
		{
			cout<<"High"<<" "<<revenue_high[i]<<endl;
		}
		else if (outcomes[i]=="low")
		{
			cout<<"Low"<<" "<<revenue_low[i]<<endl;
		}
		else
		{
			cout<<"Priming"<<endl;
		}
	}
	cout<<"Total Revenue : "<<x<<endl;


	return 0;
}