
#include <bits/stdc++.h>
using namespace std;

void findpath(int graph[][5], int n)
{

	vector<int> numofadj;

	for (int i = 0; i < n; i++)
		numofadj.push_back(accumulate(graph[i],
									graph[i] + 5, 0));

	int startpoint = 0, numofodd = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (numofadj[i] % 2 == 1)
		{
			numofodd++;
			startpoint = i;
		}
	}

	if (numofodd > 2)
	{
		cout << "No Solution" << endl;
		return;
	}

	stack<int> stack;
	vector<int> path;
	int cur = startpoint;

	while (!stack.empty() || accumulate(graph[cur], graph[cur] + 5, 0) != 0)
	{
		if (accumulate(graph[cur],
					graph[cur] + 5, 0) == 0)
		{
			path.push_back(cur);
			cur = stack.top();
			stack.pop();
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (graph[cur][i] == 1)
				{
					stack.push(cur);
					graph[cur][i] = 0;
					graph[i][cur] = 0;
					cur = i;
					break;
				}
			}
		}
	}

	for (vector<int>::size_type i=0; i<path.size(); i++) cout << path[i] << " -> ";
	cout << cur << endl;
}

int main()
{
	int n;

	int graph3[][5] = {{0, 1, 0, 0, 1},
					{1, 0, 1, 1, 1},
					{0, 1, 0, 1, 0},
					{0, 1, 1, 0, 1},
					{1, 1, 0, 1, 0}};
	n = sizeof(graph3) / sizeof(graph3[0]);
	findpath(graph3, n);

	return 0;
}
