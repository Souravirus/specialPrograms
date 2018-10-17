//This is the solution of the Teammate question of snackdown 2019 which used combination.
#include<bits/stdc++.h>
#define mp make_pair
#define lli long long int
#define ll long long int
#define ulli unsigned long long int
#define dout if(debug)cout<<" "
using namespace std;

bool decr(lli a, lli b){
    return (a >= b);
}

lli mod = 1e9+7;

lli factorial[100001];

int debug = 1;

ll power(ll a, ll b, ll mod){
	ll x = 1, y = a;
	while (b > 0){
		if (b%2){
			x = (x*y)%mod;
		}
		y = (y*y)%mod;
		b /= 2;
	}
	return x%mod;
}	
 
ll modular_inverse(ll n, ll mod){
	return power(n, mod-2, mod);
}
 
ll nCr(ll n, ll k, ll mod){
	return (factorial[n]*((modular_inverse(factorial[k], mod)*modular_inverse(factorial[n-k], mod))%mod))%mod;
}

ll nPr(ll n, ll k, ll mod){
	return (factorial[n]*(modular_inverse(factorial[n-k], mod))%mod)%mod;
}

ll pairing(ll n, ll k, ll mod){
	return (factorial[n]*(modular_inverse(factorial[k], mod)*modular_inverse(power(2, k, mod), mod)%mod))%mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    lli T;
    cin >> T;
    factorial[0] = 1;
    factorial[1] = 1;
    for(int i = 2; i <= 100000 ; i++){
        factorial[i] = (i*factorial[i-1])%mod;
    }
    while(T--){
        lli N;
        cin >> N;
        int S[N];

        for(lli i = 0; i < N; i++){
            cin >> S[i]; 
        }

        sort(S, S+N, greater<int>());
        lli ans = 1;
        
        lli count = 1, prev = 0;
        for(lli i = 1; i < N; i++){

            if(S[i] != S[i-1]){
               if(!prev){
                   prev = count;
                   count = 1;
               }
               else{
                    if(prev % 2 == 0){
                       int temp = pairing(prev, prev/2, mod);
                       ans = (ans*temp)%mod;
                       prev = count;
                       count = 1;
                    }

                    else{
                        int temp = pairing((prev-1), (prev-1)/2, mod);
                        ans = (ans*(count*(temp*prev)%mod)%mod)%mod;
                        prev = count-1;
                        count = 1;
                    }
               }
            }
            
            else {
                count++;
            }
        }
        if(prev % 2 == 0){
           int temp = pairing(prev, prev/2, mod);
           ans = (ans*temp)%mod;
           prev = count;
           count = 1;
        }

        else{
            int temp = pairing((prev-1), (prev-1)/2, mod);
            ans = (ans*(count*(temp*prev)%mod)%mod)%mod;
            prev = count-1;
            count = 1;
        }

       int temp = pairing(prev, prev/2, mod);
       ans = (ans*temp)%mod;
       prev = count;

        cout << ans << endl;
    }
	return 0;
}
//Hi there Sourav Sahoo please use lli instead of lli

