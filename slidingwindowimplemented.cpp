#include <bits/stdc++.h>
using namespace std;

void minSubarraySize(int arr[], int x, int n){
    int sum = 0, minLength = n+1, ans = INT_MAX;
    
    int start = 0, end = 0;
    while(end < n){
        while(sum <= x and end < n){
            sum += arr[end++];
        }
        while(sum > x and start < n){
            minLength = min(end - start, minLength);
            sum -= arr[start++];
        }
    }
    cout << "Minimum Size subarray with sum > " << x << " has length equal to "
     << minLength << endl;
}

int main(){
    // int arr[] = {1, 4, 45, 6, 19};
    // int x = 51, n = 5;
    int n, x;
    cin >> n >> x;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    minSubarraySize(arr, x, n);
}
