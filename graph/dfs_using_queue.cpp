//implementation of http://codeforces.com/problemset/problem/893/C
#include<bits/stdc++.h>
#define mp make_pair
#define FOR(i,n) for(int i=0;i<n;i++)
#define REP(i, a, b) for(int i=a;i<=b;i++)
#define FORb(i, n) for(int i=n-1; i>=0; i--)
#define lli long long int
#define ulli unsigned long long int
#define dout if(debug)cout<<" "
using namespace std;
lli debug = 0;
vector<lli> money;
vector<lli> arr;
vector<lli>ans;
vector<vector<lli> >graph;

lli dfs( lli ind){

    dout << "current ind:" << ind << endl;
    lli ret = money[ind];
    arr[ind] = 1;
    queue<lli>Q;
    Q.push(ind);
    while(!Q.empty()){
        lli first = Q.front();
        dout << "current first:" << first << endl;
        ret = std::min(ret, money[first]);
        Q.pop();
        for(lli i = 0; i < graph[first].size(); i++){
            if(arr[graph[first][i]] == 0)
            {
                Q.push(graph[first][i]);
                arr[graph[first][i]] = 1;
            }
        }
    }
    return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    lli N, pair;
    cin >> N >> pair;
    money.resize(N);
    arr.resize(N);
    for(lli i = 0; i < N; i++){
        cin >> money[i];
    }
    graph.resize(N);
    for(lli i = 0; i < N; i++){
        arr[i] = 0;
    }
    for(lli i = 0; i < pair; i++){
        lli first;
        lli second;
        cin >> first; 
        cin >> second;
        graph[first-1].push_back(second-1);
        graph[second-1].push_back(first-1);
    }

    for(lli i = 0; i < N; i++){
        if(arr[i] == 0)
            ans.push_back(dfs(i));
    }

    lli sum = 0;
    for(lli i = 0; i < ans.size(); i++){
        sum+= ans[i];
    }
    cout << sum << endl;
	return 0;
}
