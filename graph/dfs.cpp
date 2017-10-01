#include <bits/stdc++.h>
using namespace std;

int N = 3; // number of vertices
vector<vector<int>> W(N, vector<int>(N, 0)); // assume all connect to 0
vector<int> V; // visited flag

void dfs(int i)
{
	if (!V[i])
	{
		V[i] = true;
		for_each(W[i].begin(), W[i].end(), dfs);
	}
}

bool check_graph_connected()
{
    int start_vertex = 0;
    V = vector<int>(N, false);
    dfs(start_vertex);
    return (find(V.begin(), V.end(), 0) == V.end());
}

int main()
{
    int a, b;
    cout << "Please keep entering edges from two vertices\n";
    cout << "Note that available vertices are: 0 - " << N - 1 << "\n";
    while (cin >> a >> b)
    {
        W[a].push_back(b);
        W[b].push_back(a);
    }
    if (check_graph_connected())
        cout << "Graph is connected" << endl;
    else
        cout << "Graph is not connected" << endl;
    return 0;
}
