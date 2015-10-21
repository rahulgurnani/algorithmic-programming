// AUTHOR: RAHUL GURNANI
// 
// small code to depict if the given string s1 and s2 are rotation of one another or not
#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s1, s2;
	cin >> s1;
	cin >> s2;
	string s3 = s1 + s1;
	if(s3.find(s2) == string::npos)
		cout << "not a rotation" << endl;
	else
		cout << "is  a rotation" << endl;
	return 0;
}