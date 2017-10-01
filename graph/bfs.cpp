#include <bits/stdc++.h>
using namespace std; 
vector<int> V; 

void bfs(int i, vector<list<int>> &W)
{
	queue<int> q;
	q.push(i);
	V[i] = true;
	while(!q.empty())
	{
		int front = q.front();
		q.pop();
		for (auto &it : W[front])
		{
			if (!V[it])
			{
				V[it] = true;
				q.push(it);
			}
		}
	}
}

int main()
{
    int N;
	cout << "Please enter how many vertices: " << endl;
	cin >> N;
	vector<list<int>> W(N); // make lot of adjacency list
	V = vector<int>(N, false); // initialize all to be false
	
	int a, b;
	cout << "Keep entering edges" << endl;
	while (cin >> a >> b)
	{
		W[a].push_back(b);
	}

	bfs(0, W); // bfs
	if (find(V.begin(), V.end(), 0) == V.end())
		cout << "Graph is connected" << endl;
	else
		cout << "Graph is not connected" << endl;
	return 0;
}
