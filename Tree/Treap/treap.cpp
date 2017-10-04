#include<bits/stdc++.h>
#define mp make_pair
#define FOR(i,n) for(int i=0;i<n;i++)
#define REP(i, a, b) for(int i=a;i<=b;i++)
#define FORb(i, n) for(int i=n-1; i>=0; i--)
#define lli long long int
#define ulli unsigned long long int
#define dout if(debug)cout<<" "
using namespace std;

int debug = 0;

struct TreapNode{
    int key, priority;
    int childcnt;
    TreapNode *left, *right;
};

/*implementation of Right rotation*/
TreapNode *rightRotate(TreapNode *y){
    TreapNode *x = y -> left, *T2 = x -> right;
    x -> right = y;
    y -> left = T2;
    y -> childcnt = 0;

    //I am doing this to change the count of child due to rotation
    if(y -> left != NULL)
        y -> childcnt += y -> left -> childcnt + 1; 
    
    if(y -> right != NULL)
        y -> childcnt += y -> right -> childcnt + 1;

    x -> childcnt = 0;

    if(x -> left != NULL)
        x -> childcnt += x -> left -> childcnt + 1;
    
    if(x -> right != NULL)
        x -> childcnt += x -> right -> childcnt + 1;

    return x;
}

/* implementation of left Rotation*/
TreapNode *leftRotate(TreapNode *x){
    TreapNode *y = x -> right, *T2 = y -> left;
    y -> left = x;
    x -> right = T2;

    x -> childcnt = 0;

    // to change the count of the child due to left rotation
    if(x -> left != NULL)
        x -> childcnt += x -> left -> childcnt + 1;
    
    if(x -> right != NULL)
        x -> childcnt += x -> right -> childcnt + 1;
    
    y -> childcnt = 0;

    if(y -> left != NULL)
        y -> childcnt += y -> left -> childcnt + 1; 
    
    if(y -> right != NULL)
        y -> childcnt += y -> right -> childcnt + 1;


    return y;
}

TreapNode* newNode(int key){
    TreapNode *temp = new TreapNode;
    temp -> key = key;
    temp -> childcnt = 0;
    temp -> priority = rand()%100; 
    temp -> left = temp -> right = NULL;
    return temp;
}

TreapNode *insert(TreapNode* root, int key){

    if(!root){
        return newNode(key);
    }

    if(key < root -> key){
        root -> left = insert(root -> left, key);
        root -> childcnt++ ;

        if(root -> left -> priority > root -> priority){
            root = rightRotate(root);
        }

    }

    else{
        root -> right = insert(root -> right, key);
        root -> childcnt++;

        if(root -> right -> priority > root -> priority){
            root = leftRotate(root);
        }
    }

    return root;
}

/*Recursive implementation of Delete()*/
TreapNode* deleteNode(TreapNode* root, int key){
    
    if(root == NULL)
        return root;

    root -> childcnt--;
    if(key < root -> key)
        root -> left = deleteNode(root -> left, key);

    else if (key > root -> key)
        root -> right = deleteNode(root -> right, key);
    
    //IF KEY IS AT ROOT

    //If left is NULL 
    else if(root -> left == NULL){
        TreapNode *temp = root -> right;
        delete(root);
        root = temp;
    }

    //If right is NULL 
    else if (root -> right == NULL){
        TreapNode *temp = root -> left;
        delete (root);
        root = temp;
    }
   
    // If key is at root and both left and right are not NULL
    else if(root -> left -> priority < root -> right -> priority){
        root = leftRotate(root);
        //At this point there was a huge error by me. Even if I was 
        //decrementing childcnt but when there was a rotation. There was no
        //effect on decrementation. So I had to again decrement it.
        root->childcnt--;
        root -> left = deleteNode(root -> left, key);
    }

    else{
        root = rightRotate(root);
        root->childcnt--;
        root -> right = deleteNode(root -> right, key);
    }

    return root;
}

//This is to count the pos by seeing the child from left and right
int Kpify(TreapNode *curr, int pos, int target){
    int count = pos; 
    //in this we are checking whether the required index is lesser than the
    //no. of child in the left, then we go to left side
    
    if( curr -> left != NULL){
        count += (curr -> left -> childcnt + 1);

        if (target <= count){
            return Kpify(curr -> left, pos, target); 
        }
    }

    count++ ;
   //If required index is equal to no. of current count then return this data 
    if ( target == count )
    {
        return curr -> key;
    }
    
    //Else traverse through the right child
    if (target > count )
    {
        return Kpify(curr -> right, count, target);
    }
}

int countNode(TreapNode *T, int bound){
    if(T == NULL)
        return 0;
    if(T-> key < bound){
        int count = 0;
        if(T-> left != NULL)
            count += (T -> left -> childcnt + 1);
        count++;
        count += countNode(T -> right, bound);
        return count;
    }
    return countNode(T -> left, bound);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    srand(time(NULL));
    int Q;
    cin >> Q;
    
    set<int> myset;
    set<int> :: iterator its;
    TreapNode *root = NULL;
    while(Q--){
       char type;
       cin >> type;
       int num;

       if(type == 'I'){
           cin >> num;
            
           if(myset.find(num) == myset.end()){
               myset.insert(num);
               root = insert(root,  num);
				//inorder(root);
           }
            
       }
        
       else if(type == 'D'){
           cin >> num;
           its = myset.find(num);

           if(its != myset.end()){
               myset.erase(num);
               root = deleteNode(root, num);
				//inorder(root);
           }
       }
        
       else if(type == 'C'){
           cin >> num;
           its = myset.lower_bound(num);
           int v = countNode(root, num);
           cout << v << endl;
       }
        
       else if( type == 'K'){
           cin >> num;

           if(num <=  myset.size() ){
               cout << Kpify(root, 0, num) << endl;
           }
            
           else
               cout << "invalid"<<endl;
       }
    }
	return 0;
}
