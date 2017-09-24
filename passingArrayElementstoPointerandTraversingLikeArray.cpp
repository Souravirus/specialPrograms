#include<iostream>
using namespace std;
int main(){
	int a[]={12, 13, 15, 30};
	int *p=&a;
	for(int i=0;i<4;i++)
	{
		cout<<*(p+i)<<endl;
		cout<<p[i];
	}
	return 0;

}
