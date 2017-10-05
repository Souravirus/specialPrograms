#include<iostream>
#include<string>
using namespace std;
class dog{
	int weight;
	string name;
	
	public:
		void get(){
			cin>>weight;
			cin>>name;
		}
		void display(){
			cout<<weight;
			cout<<name;
		}
};
int main(){

	dog p1,p2;
	p1.get();
	p2=p1;
	p2.display();d
	return 0;
}
