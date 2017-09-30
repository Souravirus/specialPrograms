#include <iostream>
 
using namespace std;
 
// Sort an array of size n using Bubble Sort. 
void BubbleSort (int arr[], int n)
{
	int i, j;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n-i-1; ++j)
		{
			// Comparing values and swapping them if value at j > j+1.
			if (arr[j] > arr[j+1])
			{
				arr[j] = arr[j]+arr[j+1];
				arr[j+1] = arr[j]-arr[j + 1];
				arr[j] = arr[j]-arr[j + 1];
			}
		}
	}	
}	
 
int main()
{
	int n, i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
 
	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}
 
	BubbleSort(arr, n);
 
	// Display the sorted data.
	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
        cout<<"->"<<arr[i];
 
	return 0;
}
