#include <iostream>
#include <vector>
#include<fstream>
#include "list.cpp"
#include "list.h"
#include <bits/stdc++.h>
using namespace std;



// I have used vectors for all the computation
// I have used a struct and sorted the struct is ascending order wrt to Length/Probability
//Total time complexity = O(n) + On(log(n)) so dominant term is nlogn


struct prob
	{
		int index;
		int length;
		double value1;
		double pb;

	};


vector<prob> MergeSort(vector<prob> nums) // Merge Sort has a complexity of O(nlog(n))
{

	int s_size = nums.size();
	if (s_size <= 1)
		return nums;
	List<prob> d, s;
	//cout<<"here0.3"<<endl;
	vector<prob> v1, v2;
	for (int i=0;i<s_size;i++)
	{
		d.insertAtHead(nums[i]);
		nums.pop_back();
	}
	//cout<<"here1.5"<<endl;
	ListItem<prob> *ptr = d.getHead();
	for (int i=0;i<s_size/2;i++)
	{
		v1.push_back(ptr->value);
		ptr=ptr->next;
	}
	//cout<<"here1.7"<<endl;
	for(int i=s_size/2;i<s_size;i++)
	{
		v2.push_back(ptr->value);
		ptr=ptr->next;
	}
	//cout<<"here1"<<endl;
	v1 = MergeSort(v1);
	//cout<<"here12"<<endl;
	v2 = MergeSort(v2);
	//cout<<"here14"<<endl;

	prob num1, num2;

	while (!v1.empty() && !v2.empty())
	{
		//cout<<"here2"<<endl;
		num1 = v1.front();
		num2 = v2.front();
		//cout<<"here3"<<endl;

		if (num1.value1 < num2.value1)
		{
			
			v1.erase(v1.begin());
			s.insertAtHead(num1);

		}
		else
		{
			//cout<<"here5"<<endl;
			v2.erase(v2.begin());
			s.insertAtHead(num2);
		}
	}

	while (!v1.empty())
	{
		//cout<<"here6"<<endl;
		num1 = v1.front();
		v1.erase(v1.begin());
		s.insertAtHead(num1);
	}
	while (!v2.empty())
	{
		//cout<<"here7"<<endl;
		num2 = v2.front();
		v2.erase(v2.begin());
		s.insertAtHead(num2);
	}

	ptr = s.getTail();
	for (int i=0;i<s_size;i++)
	{
		nums.push_back(ptr->value);
		ptr=ptr->prev;
	}


		//cout<<"here8"<<endl;

	
	return nums;	

}



int main(int argc, char** argv)
{
	ifstream file;
	vector<double> all_numbers;
	string line;
	string ch;
	file.open(argv[1]);
	getline(file, line);
	ch = line.substr(line.find(" ")); //Ignoring spaces and reading value of n
	const int n = stoi(ch);

	while(getline(file,line))
	{
		stringstream s(line);
		while (s>>ch)
		{
			if (ch != "L" && ch != "p")
			{
				all_numbers.push_back(stod(ch)); //storing all the rows and column values in vector

			}
		}
	}

	vector<double> L;
	vector<double> p;
	int sizee = all_numbers.size();
	


	for(int i = 0; i < sizee/2;  i++) // O(n)
	{
		L.push_back(all_numbers[i]); //Storing rows in a different vector 
	}
	//cout<<endl;
	for(int i = sizee/2; i<sizee;i++) // O(n)
	{
		//cout<<all_numbers[i]<<endl;
		p.push_back(all_numbers[i]); //storing columns in a different vector
	}


	
	prob* all_info = new prob[n];

	vector<prob> p_over_l;

	for (int i = 0; i < sizee/2 ;i++) // O(n)
	{
		double a = L[i]/p[i];
		all_info[i].value1 = a;
		all_info[i].index = i;
		all_info[i].length = L[i];
		all_info[i].pb = p[i];

		p_over_l.push_back(all_info[i]);
		//cout<<all_info[i].index+1<<" "<<all_info[i].value1<<" "<<all_info[i].length<<" "<<all_info[i].pb<<endl;
	}

	
	p_over_l = MergeSort(p_over_l); //O(nlog(n))
	
	int counter = 0;


	for (int i=0 ;i<sizee/2;i++) // O(n)
	{
		if (counter == 0){
			cout<<p_over_l[i].index+1;
			counter++;
		}

		else 
		{
			cout<<" "<<p_over_l[i].index+1;
		}

	}

	cout<<endl;

	double sum=0;
	double time=0;

	for (int i=0 ;i<sizee/2;i++) // O(n)
	{
		sum = sum + p_over_l[i].length;
		time = time + p_over_l[i].pb*sum;
	}
	cout<<"Expected Time "<<time;


	return 0;
}