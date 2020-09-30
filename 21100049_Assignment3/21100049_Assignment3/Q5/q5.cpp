#include <iostream>
#include<fstream>
#include<vector>
#include <bits/stdc++.h>
#include<string>
#include<stack>

using namespace std;

//The complexity for this algorithm is O(nlogn) since I have used merge sort which has a complexity of O(nlogn).
//I have used the default sorting function for sorting and again divide and conquer method for counting frequencies.



struct info
{
	int day;
	int value;
};

int index_1;

bool compare_pref(info &a, info &b)
{
	return (a.value<b.value);
}

bool compare_day(info &a, info &b)
{
	return (a.day<b.day);
}

string decode(int photo1, int photo2)
{
	if (photo1 == photo2)
	{
		return "Y";
	}
	else
	{
		return "N";
	}
}

int maxx = 0;

void dominant_helper(vector<info> &all_numbers, int a, int b, vector<int> &frequency)
{

	string answer = decode(all_numbers[a].value, all_numbers[b].value);
	if (answer == "Y")
	{
		frequency[all_numbers[a].value] += (b-a+1);
	}
	else
	{
		int mid = (a+b)/2;
		dominant_helper(all_numbers, a, mid, frequency);
		dominant_helper(all_numbers, mid+1, b, frequency);
	}

	for (int i=0;i<frequency.size();i++)
	{
		//cout<<frequency[i];
		if (frequency[i] > maxx)
		{
			maxx = frequency[i];
			index_1=i;
		}
	}
	//cout<<maxx;

}

void dominant(vector<info> all_numbers)
{
	vector<int> frequency;
	int s = all_numbers.size();
	frequency.resize(all_numbers[s-1].value+1);

	dominant_helper(all_numbers, 0, s-1, frequency);

}
int main(int argc, char** argv)
{
	ifstream file;
	vector<pair<string, string>> pref;
	vector<vector<string>> location;
	vector<info> all_numbers;
	
	string line;
	string ch;
	file.open(argv[1]);
	getline(file, line);
	ch = line.substr(line.find(" ")); //Ignoring spaces and reading value of n
	const int n = stoi(ch);
	getline(file, line);
	ch = line.substr(line.find(" ")); //Ignoring spaces and reading value of n
	const int m = stoi(ch);
	info* data = new info[n];
	location.resize(n);
	while(getline(file,line))
	{
		stringstream s(line);
		int x  = 0;
		while (s>>ch)
		{		
				
				data[x].day = x;
				data[x].value = stoi(ch);
				all_numbers.push_back(data[x]); //storing all the values in vector
				x++;

		}

	}

	//int d  = mergesort(all_numbers, 0, all_numbers.size()-1);
	sort(all_numbers.begin(), all_numbers.end(), compare_pref);


	dominant(all_numbers);
	int dominant_value = maxx;
	
	string indices;
	//cout<<dominant_value<<endl;
	sort(all_numbers.begin(), all_numbers.end(), compare_day);


	
	for (int i=0;i<all_numbers.size();i++)
	{
		
		if(all_numbers[i].value==index_1){

			indices = indices + " " +  to_string(all_numbers[i].day);
		}
	}


	string ans;

	if(dominant_value > n/2)
	{
		ans += "Success";
		ans += "\n";
		ans += "Dominant Species Count " + to_string(dominant_value);
		ans += "\n";
		ans += "Dominant Species Indices" + indices;
	}
	else
	{
		ans = "Failure";
	}
	cout<<ans<<endl;



	
	



	return 0;
}
