//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int mid, int r)
    {
         // Your code here
         int n1 = l,n2 = mid+1;
         vector<int>temp;
         while(n1<=mid && n2<=r)
         {
             if(arr[n1]>arr[n2]){
                 temp.push_back(arr[n2++]);
             }
             else temp.push_back(arr[n1++]);
         }
         
         while(n1<=mid) temp.push_back(arr[n1++]);
         while(n2<=r) temp.push_back(arr[n2++]);
         
         for(int i=l;i<=r;i++)
         {
             arr[i] = temp[i-l];
         }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        // cout<<l<<" "<<r<<endl;
        if(l >= r) return ;
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends