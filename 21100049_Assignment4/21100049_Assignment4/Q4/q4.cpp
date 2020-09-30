#include <iostream>
#include <string.h>
#include <fstream>
#include<vector>
using namespace std;


//Recurrence Relation: 
//Time Complexity: LenghtA * LengthB where A and B are two string.
//This algorithm is performed iteratively.
//It makes use of a grid.

string ans = "VALID\n";
string ans1 = "";
vector<pair <int,char> >strings;
bool interleaved(string A, string B, string C)
{
	if (A.length()+B.length() != C.length())
		return false;

	bool sub_strings[A.length()+1][B.length()+1];

	for (int i=0;i<=A.length();i++)
		{
			for(int j=0;j<=B.length();j++)
			{
				sub_strings[i][j] = false;
			}
		}

	//sub_strings[0][0]=true; // empty string equal
		char forA;
		char forB;
	for (int i=0;i<=A.length();i++)
		{
			for(int j=0;j<=B.length();j++)
			{

				if (i==0 && j==0)
					sub_strings[i][j]=true;
				else if (i==0)
				{
					if (C[j-1]==B[j-1])
					{
						sub_strings[i][j] = sub_strings[i][j-1];
						if (forB != B[j-1])
							//strings.push_back(make_pair(2, B[j-1]));
						forB = B[j-1];
					}
					
				}
				else if (j==0)
				{
					if (C[i-1]==A[i-1])
					{
						sub_strings[i][j] = sub_strings[i-1][j];
						if(forA != A[i-1])
							ans += A[i-1];
							strings.push_back(make_pair(1, A[i-1]));
						forA = A[i-1];
					}
				}
				else if (A[i-1] == C[i+j-1] && B[j-1] != C[i+j-1]) 
				{
					
                	sub_strings[i][j] = sub_strings[i-1][j]; 
          			if (forA != A[i-1])
                		strings.push_back(make_pair(1, A[i-1]));
                	forA = A[i-1];
				}
                else if (A[i-1] != C[i+j-1] && B[j-1] == C[i+j-1]) 
                {
                	
                	sub_strings[i][j] = sub_strings[i][j-1];
                	if (forB != B[i-1])
                		strings.push_back(make_pair(2, B[j-1]));
                	forB = B[j-1];
                }
                else if (A[i-1] == C[i+j-1] && B[j-1] == C[i+j-1]) 
                {
        			
                	sub_strings[i][j] = (sub_strings[i-1][j] || sub_strings[i][j-1]);
                	if (forB != B[i-1])
                		strings.push_back(make_pair(2, B[j-1]));
                	forB = B[j-1];
                }


			}

			
		}

	return sub_strings[A.length()][B.length()];


}




int main(int argc, char** argv)
{
	ifstream file;
	//cout<<"here3";
	
	string line;
	string ch;
	string A, B, C;
	file.open(argv[1]);
	file>>A;
	file>>B;
	file>>C;
	vector<char> s1;
	std::vector<char> s2;

	bool found = interleaved(A, B, C);

	if (!found)
		cout<<"INVALID"<<endl;
	else{
		//cout<<ans<<endl;
		cout<<"VALID\n";
		int counter = 0;
		for (int i=0;i<strings.size();i++)
		{
			if (strings[i].first == 1)
				s1.push_back(strings[i].second);
			if (strings[i].first == 2)
				s2.push_back(strings[i].second);
	}

	int i = 0;
	int j = 0;
	if (s1.size() > s2.size())
	{
	cout<<1<<":";
	for (int i=0;i<s2.size();i++)
		{
			cout<<s1[i];
		}
		cout<<"\n";
		cout<<2<<":";
	for(j=0;j<s2.size();j++)
	{
		cout<<s2[j];
	}
		cout<<"\n";
		cout<<1<<":";
	for (int k = j ; k < s1.size();k++)
	{
		cout<<s1[k];
	}
	cout<<"\n";

}
	else
	{	
		cout<<1<<":";
		for (int i=0;i<s1.size();i++)
		{
			cout<<s1[i];
		}
		cout<<"\n";
		cout<<2<<":";
	for(j=0;j<s1.size();j++)
	{
		cout<<s2[j];
	}
	cout<<"\n";
	cout<<1<<":";
	for (int k = j ; k < s2.size();k++)
	{
		cout<<s1[k];
	}
	cout<<"\n";

	}
}


	return 0;
}