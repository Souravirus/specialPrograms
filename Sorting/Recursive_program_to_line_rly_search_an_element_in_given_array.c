#include<iostream>
 
/* Recursive function to search x in arr[l..r] */
int recSearch(int arr[], int l, int r, int x)
{
     if (r < l)
        return -1;
     if (arr[l] == x)
        return l;
     return recSearch(arr, l+1, r, x);
}
 
int main()
{
    int arr[] = {12, 34, 54, 2, 3}, i;
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 3;
    int index = recSearch(arr, 0, n-1, x);
    if (index != -1)
       cout<<"Element"<< x<<" is present at index"<< index;
    else
        cout<<"Element"<< x<<" is not present";
    return 0;
}
