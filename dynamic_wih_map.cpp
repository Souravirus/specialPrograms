#include<bits/stdc++.h>
#define ulli unsigned long long int
using namespace std;

map<ulli,ulli> m;

ulli coin(ulli N){
	if(N<12)
		return N;
	if(m.find(N)==m.end())//not in map
	{
		ulli temp=max(N,coin(N/2) + coin(N/3) +coin(N/4));
		m[N]=temp;
	}
	return m[N];
	
}


int main(){
	int T, N, num;
	while(cin>>num){
		ulli ans=coin(num);
		cout<<ans<<endl;
	}
	return 0;
}
