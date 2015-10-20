// AUTHOR : RAHUL GURNANI
#include <bits/stdc++.h>
using namespace std;
// the function infix_to_postfix returns the infix to postfix converted stirng I have not considered brackets
string infix_to_postfix(string expr)
{
	string postfix_expr;
	stack<char> operators;
	map<char, int> priority;
	priority['-'] = 1;
	priority['+'] = 1;
	priority['/'] = 2;
	priority['*'] = 2;
	int l = expr.length();
	for(int i=0; i<l; i++)
	{
		if( priority[expr[i]] == 0 )
			postfix_expr.push_back(expr[i]);
		else
		{
			if(operators.empty() || priority[operators.top()]<priority[expr[i]])
				operators.push(expr[i]);
			else
			{
				while(!operators.empty() && priority[operators.top()]>=priority[expr[i]])
				{
					postfix_expr.push_back(operators.top());
					operators.pop();
				}
				operators.push(expr[i]);
			}
			
		}
	}
	while(!operators.empty())
	{
		postfix_expr.push_back(operators.top());
		operators.pop();
	}
	return postfix_expr;
}
int main()
{
	
	string expr = "2+3*9*10+100";
	string postfix_expr = infix_to_postfix(expr);
	cout << expr << endl;
	cout << postfix_expr << endl;
	return 0;
}