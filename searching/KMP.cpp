#include<iostream>
#include<string.h>
using namespace std;
int len=0;
long * lookuptable(char F[],long lf){
	long i=0,j=1,c=0,*p,a[300000];
	while(j<lf){
		a[0]=0;
		if(F[i]==F[j])
		{
			a[j]=c;
			c++;
			i++;
			
		}
		else
		{
			a[j]=0;
			c=0;
			i=0;
		}
		j++;
	}
	p=a;
	return p;
}
long * KMP(char S[],long ls, char F[], long lf){
	long int *p,*q,a[300000]={0},c=0,c1=0;
	p=lookuptable(F,lf);
	for(int i=0;i<ls;i++)
	{
		if(S[i]==F[c]){
			c++;
			if(c==lf)
			{a[c1]=i-lf+1;
			c=0;
			c1++;
			i=i-lf+1;
			}
			
		}
		else
		{
			if(c!=0){
				c=*(p+c);
				i--;
				}
		}
	}
	a[c1]=(-2);
	q=a;
	return q;		
}
long int lookup2(long int *p, long int lf)
{	
	int i=0;
	long b[300000]={0};
	while(i<len)
	{
		if(*(p+i+1)-*(p+i)<lf)
		{
			b[i]=0;
		}
	}


}
int main()
{
	int T;
	long ls,lf;
	char S[300000],F[300000];
	cin>>T;
	long int *p;
	long long int n;
	while(T--)
	{
		cin>>S;
		cin>>F;
		ls=strlen(S);
		lf=strlen(F);
		p=KMP(S,ls,F,lf);
		while(*(p+i)!=-2){
			len++
		}
		int i=0;
		lookup2(p,lf);
	}
	return 0;
}

