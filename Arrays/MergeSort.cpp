#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r){
	
	int i, j, k;
	int n1 =  m-l+1;
	int n2 = r-m;
	
	int L[n1], R[n2];
	
/* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int left, int right)
{
	if(left < right){
		int mid = (left+right)/2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid+1, right);

		merge(arr, left, mid, right);
	}
	else
		return;
}
int main() {
	// your code goes here
	
	int arr[] = {1,2,4,20,18,15,13,19,23,12,5,6};
	int len = sizeof(arr)/sizeof(arr[0]);
	
	for(int i=0;i<len;i++)
		cout<<" "<<arr[i]<<" ";
	cout<<endl;
	mergeSort(arr, 0, len-1);	
	cout<<endl;
	for(int i=0;i<len;i++)
		cout<<" "<<arr[i]<<" ";
	return 0;
}
