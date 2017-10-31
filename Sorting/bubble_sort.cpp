#include <iostream>
 
using namespace std;

// Function to sort an array of size n using Bubble Sort Algorithm.
void BubbleSort (int arr[], int n)
{
    int i, k;
    for (i = 0; i < n; ++i)
    {
	bool swap = 0;
        for (k = 0; k < n-i-1; ++k)
	{
	    // Comparing values and swapping them if value at k > k+1.
	    if (arr[k] > arr[k+1])
	    {
                swap(arr[k],arr[k+1]);
	`	swap=1;
            }
	}

	if(!swap)
		break;
    }	
}	
 
int main()
{
    int n, j;
    cout<<"\nEnter the number of the data element to be sorted: "; 
    cin>>n; // Takes input of size of the array to be sorted.
 
    int arr[n];
    for(j = 0; j < n; j++)
    {
        cout<<"Enter element "<<j+1<<": "; //Takes input of array element.
	cin>>arr[j];
    }
 
    BubbleSort(arr, n); // Calls BubbleSort function.
 
    // Displays the sorted array.
    cout<<"\nSorted Data ";
	
    for (j = 0; j < n; j++)
    	cout<<"-->"<<arr[j];    // Outputs the final sorted array based on the data element value.
 
    return 0;
}