#include <iostream>
#include<fstream>
#include<vector>
#include <bits/stdc++.h>
#include<string>
#include<stack>


using namespace std;

// My Algorithm works with complexity of O(n^2). I have used preferences for days. Team who has reached to a final destination first will get the most preference.

// Least number is equal to most priority.

struct day_num
{
	string loc;
	int day;
};


struct info
{
	int preference;
	int index;
};

bool compare_pref(info &a, info &b)
{
	return (a.preference<b.preference);
}


int main(int argc, char** argv)
{
	ifstream file;
	vector<pair<string, string>> pref;
	vector<vector<string>> location;
	
	string line;
	string ch;
	file.open(argv[1]);
	getline(file, line);
	ch = line.substr(line.find(" ")); //Ignoring spaces and reading value of n
	const int n = stoi(ch);
	string* data = new string[n];
	location.resize(n);
	bool arr[n];
	
	

	int i = 0;
	while(getline(file,line))
	{
		stringstream s(line);
		int x = 0;
		while (s>>ch)
		{
			if (ch != ":")
			{	
				
				location[i].push_back(ch); //storing all the values in vector
				x++;
			}
			
		}
		i++;
	}

	
	int x = location.size();
	vector<info> priority;
	priority.resize(x);

	for (int i=0;i<location.size();i++) //----------------- O(n^2)
	{
		for (int j=location[i].size()-1;j>0;j--)
		{
			if (location[i][j].length() == 2)
			{
					priority[i].preference = j;
					priority[i].index = i;
					break;
				}
				else
				{
					continue;
				}

			}
		}


	sort(priority.begin(), priority.end(), compare_pref); // sorting according to priority.
	
	
	int min = 10000;
	int team;
	for (int i=0;i<x;i++) // -------------- O(n^2)
	{
		team = priority[i].index;

			for (int j=location[team].size()-1;j>0;j--) 
			{
			if (location[team][j].length() == 2)
			{
				int s = location[team][j].length();

				int y = stoi(location[team][j].substr(s-1,1));
				if (arr[y-1] == false){
					arr[y-1] = true;
					pref.push_back(make_pair(location[team][j],location[team][0]));
					
			
					break;
				}
				else
				{
					continue;
				}

			}
		}
		
		
	}



	int counter = 0;
	cout<<"Final Destinations: ";
	for(int i=pref.size()-1;i>=0;i--)
	{
		if (counter == 0)
		{
		cout<<pref[i].first<<" "<<pref[i].second;
		counter++;
		}
		else{
			cout<<", "<<pref[i].first<<" "<<pref[i].second;
		}
	}
	cout<<endl;


	
	




	return 0;
}
