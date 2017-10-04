/* This programs generates the prime factorization of 
a number in O(log n) with preprocessing using a sieve.
The main idea is to compute smallest prime of every composite number
using the sieve and then use that array to generate prime factors.*/
#include <iostream>
#define MAXN 10000000 //10^7
using namespace std;

long long smallestPrime[MAXN];
bool isNotPrime[MAXN];

void sieve()
{
  for(long long i=2; i<MAXN; i+=2){
    smallestPrime[i] = 2; //smallest prime of all even numbers is 2.
  }
  for(long long i=3; i<MAXN; i+=2){
    if(!isNotPrime[i]){
      smallestPrime[i] = i;
      for(long long j=i; j*i<MAXN; j+=2){
        if(!isNotPrime[j*i]){ 
          isNotPrime[j*i] = true;
          smallestPrime[j*i] = i;
        }
      }
    }
  }
}
int main()
{
  sieve();
  long long n = 123456;
  while(n!=1){
    cout<<smallestPrime[n]<<" ";
    n/=smallestPrime[n];
  }
  cout<<endl;
  return 0;
}