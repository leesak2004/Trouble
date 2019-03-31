#include <iostream>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	long long int t, n;
	long long int st, et;
	long long int wait, finish, totr;
	long long int i, j;
	
	cin >> t;
	for (i = 0; i < t; i++)
	{
		cin >> n;
		wait = finish = totr = 0;
		for (j = 0; j < n; j++)
		{
			cin >> st >> et;
			if (st < finish)
			{
				totr += finish - st + et;
				wait += finish - st;
				finish += et;
			}
			else
			{
				totr += et;
				finish = st + et;
			}
		}
		cout << wait / n << " " << totr / n << endl;
	}
}
