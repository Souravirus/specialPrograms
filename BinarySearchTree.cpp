#include<iostream>
using namespace std;
struct BST{
	int data;
	struct BST *right;
	struct BST *left;
	
};
struct BST *boot=NULL;
void insert(struct BST *root,int data){
	cout<<"Hel";
	struct BST *temp;
	struct BST *n;
	n=new BST;
	
	n->left=NULL;
	n->data=data;
	n->right=NULL;
	if(boot==NULL){
		boot=n;
		cout<<boot->data;
	}
	else {
		temp=root;
		while(temp!=NULL){
		cout<<"Hell Im in while loop\n";
			if(temp->data>data){
				if(temp->left==NULL)
					{temp->left=n;
					cout<<"I have entered the left element of the temp";}
				temp=temp->left;
				
			}
			else if(temp->data<data){
				if(temp->right==NULL)
					{temp->right=n;
					cout<<"I have entered the right element of the temp";}
				temp=temp->right;
				
			}			
		}
	}
	delete n;	
}
/*struct BST *search(struct BST *root,int data){
	struct BST *temp;
	temp=root;
	while(temp!=NULL){
		if(temp->data==data){
			return temp;
		}
		else if(temp->data<data){
			temp=temp->right;
		}
		else{
			temp=temp->left;
		}
	}
}*/
void treeTraversal(struct BST *root){
	if(root){
		
		treeTraversal(root->left);
		treeTraversal(root->right);
		cout<<root->data<<"\n";
	}
}

int main(){
	int ch,data;
	
	do{
		cout<<"\nPress:\n1.for inserting an element\n2.for viewing an element\n3.for finding an element\n4.for deleting an element\n5.for exiting\n";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter the data u want to enter";
				cin>>data;
				insert(boot,data);
				break;
			case 2:	
				treeTraversal(boot);
				break;
			case 3:
				
				break;
			case 4:
				break;
			case 5:
				break;
			default:
				cout<<"Enter a correct choice";
				
		}
	}while(ch!=5);
}

