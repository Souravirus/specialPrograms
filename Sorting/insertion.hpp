#include <bits/stdc++.h>
using namespace std;

/*Descrition: function will (insertion) sort an array of ints
* Complexity: O(n^2)
*/
void insertion_sort(int length, int v[]){
	int j, temp;
	
	for(int i=0;i<length;i++){
		j = i;
		
		/*larger int is swapped with smaller int*/
		while(j>0 && v[j] < v[j-1]){
			swap(v[j], v[j-1]);
			j--;
		}
	}
}
