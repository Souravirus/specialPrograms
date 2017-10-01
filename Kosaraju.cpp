//Kosaraju's Algorithm for Strongly Connected Components
#include <bits/stdc++.h>
#define FOR(i,n) for(size_t i=0;i<n;++i)
#define endl '\n'
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;

ll gcd(ll a , ll b){return a==0?b:gcd(b%a,a);}

stack <int> topsort;

//0 state stands for second pass of DFS, 1 is the first pass of DFS
void dfs_util(int vertex, vector<vector<int>> adj, bool visited[],int state){
	if(!visited[vertex]){
		if(state==0) cout<<vertex<<" ";
		visited[vertex] = true;
		for(auto &x:adj[vertex])
			dfs_util(x,adj,visited,state);
		if(state==1){
		topsort.push(vertex); }
	}
}

int main(){
	//adj is the adjacency matrix, adjt is its transpose
	vector <vector<int>> adj,adjt;
	int e, v, i,a,b;
	//Kosaraju algorithm for finding out the Strongly Connected Components
	//Assuming vertices bare from 1 to V. For 0 to V-1, modify the code.
	cin>>e>>v;
	bool visited[v+1] = {false};
	adj.resize(v+1);
	adjt.resize(v+1);
	FOR(i,e){
		cin>>a>>b;
		adj[a].pb(b);
		adjt[b].pb(a);
	}
	FOR(i,v){
		dfs_util(i+1,adj,visited,1);
	}
	FOR(i,v){
		visited[i+1] = false;
	}
	cout<<"SCC are - \n";
	while(!topsort.empty()){
		if(!visited[topsort.top()]){
			dfs_util(topsort.top(),adjt,visited,0);
			cout<<endl;
		}
		topsort.pop();
	}
	return 0;
}