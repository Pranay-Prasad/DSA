#include<bits/stdc++.h>
using namespace std;
int Binary(int arr[],int n,int key)
{
	// Binary search
	// n = size of array 
	// key =  key value to find
    int s = 0; //start point 
    int e = n; // end point
    while (s <= e)
    {
        int mid = (s+e)/2; // mid index
        if (arr[mid] == key) // comparing mid index value with key value
        {
            return mid; // if found return the index
        }
        else if (arr[mid] > key)
        {
            e = mid-1; // if the key value is small shift end point to mid-1
        }
        else
        {
            s = mid+1;//if the key value is greater shift start to the mid + 1
        }
    }
    return -1;//if not found return -1;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int  i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<Binary(arr,n,key)<<endl;
    return 0;
}
