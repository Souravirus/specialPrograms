/*
   Program which perform queries of two types:
   type1 p v :- this update preform a[p]+=v
   type2 p x y :- output a[x] + a[x + 1] ..... + a[y] after pth type1 queries
   L[id] :- index of left child
   R[id] :- index of right child
   root[i] :- root of the segment tree after ith iteration of type1
   next_free_index :- gives the next available free index which serves as the index of left and right tree
*/
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define rep(i,a,b) for(i=(ll)a;i<(ll)b;i++)
#define revrep(i,a,b) for(i=(ll)a;i>=(ll)b;i--)
#define strep(it,v) for(it=v.begin();it!=v.end_();++it)
#define ii pair<ll,ll>
#define MP make_pair
#define pb push_back
#define f first
#define se second
#define ll long long int
#define vi vector<ll>
ll modexp(ll a,ll b){ ll res = 1; while(b > 0){  if(b & 1) res = (res * a);  a = (a * a);  b/=2;  }  return res; }
#define rs resize
long long readLI(){  register char c;  for(c = getchar(); !(c>='0' && c<='9'); c = getchar());  register long long a=c-'0';
    for(c = getchar(); c>='0' && c<='9'; c = getchar())
        a = (a<<3)+(a<<1)+c-'0';
    return a;
}
const int N = 200009;
int n,i,next_free_index = 1;
int up,q,type,x,y,p,v;
int a[N];
int tree[N],root[N],L[N],R[N];
void build(int id,int l,int r){
    if(r == l){
       tree[id] = a[l];
       return;
    }
    int mid = (l + r)/2;
    L[id] = next_free_index++;
    R[id] = next_free_index++;
    build(L[id],l,mid);
    build(R[id],mid+1,r);
    tree[id] = tree[L[id]] + tree[R[id]];
}
int update(int p,int value,int id,int l,int r){
    int ID = next_free_index++;   // index of the node in new version of segment tree
    if(r == l){
       tree[ID] = (a[p] += value);
       return ID;
    }
    int mid = (l + r)/2;
    L[ID] = L[id]; R[ID] = R[id];      // in case of not updating the interval of left child or right child
    if(p <= mid) L[ID] = update(p,value,L[ID],l,mid);
    else
      R[ID] = update(p,value,R[ID],mid+1,r);
    tree[ID] = tree[L[ID]] + tree[R[ID]];
    return ID;
}
int query(int x,int y,int id,int l,int r){
    if(y < l or x > r) return 0;
    if(x <= l and r <= y) return tree[id];
    int mid = (l + r)/2;
    return query(x,y,L[id],l,mid) + query(x,y,R[id],mid+1,r);
}
int main()
{
   std::ios_base::sync_with_stdio(false); cin.tie(NULL);
   cin>>n>>up>>q;
   rep(i,0,n) cin>>a[i];
   build(0,0,n-1);
   rep(i,1,up + 1){
       cin>>p>>v;
       root[i] = update(p - 1,v,root[i - 1],0,n-1);
   }
   rep(i,0,q){
       cin>>p>>x>>y;
       cout<<query(x - 1,y - 1,root[p],0,n - 1)<<endl;
   }
   return 0;
}
