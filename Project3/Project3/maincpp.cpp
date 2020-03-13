#include <iostream>
#include <vector>
#include <string>
#include <utility>// pair
using namespace std;
bool checkstr(string &str)
{
	vector<char> vect;
	const pair<const char, const char> bracket1('(',')');
	const pair<const char, const char> bracket2('[', ']');
	const pair<const char, const char> bracket3('{', '}');
	int i = 0;
	for (char a : str)
	{
		if (a == '(' || a == '{' || a == '[') vect.push_back(a);
		switch (a)
		{
			case ')':
			{
				if (vect.size() > 0)
				{
					if (*(vect.end() - 1) == bracket1.first) vect.erase(vect.end() - 1);
					else return false;
					break;
				}
				else
				{
					return false;
					break;
				}
			}
			case ']':
			{
				if (vect.size() > 0)
				{
					if (*(vect.end() - 1) == bracket2.first) vect.erase(vect.end() - 1);
					else return false;
					break;
				}
				else
				{
					return false;
					break;
				}
			}
			case '}':
			{
				if (vect.size() > 0)
				{
					if (*(vect.end() - 1) == bracket3.first) vect.erase(vect.end() - 1);
					else return false;
					break;
				}
				else
				{
					return false;
					break;
				}
			}
		}
		i++;
		if (vect.size() == 0 && i == str.size()) return true;
	}
	
}
int main()
{
	string str1;
	cin >> str1;
	if(checkstr(str1)) cout << "Correct";
	else cout << "Wrong";
	return 0;
}