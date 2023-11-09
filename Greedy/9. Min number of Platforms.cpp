//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;
    public:
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	int i = 1, j = 0;
    	int count = 1, maxi = 1;
    	while(i < n && j < n) {
    	    if(arr[i] <= dep[j]) {
    	        count++;
    	        i++;
    	    }
    	    else{ 
    	        count--;
    	        j++;
    	    }
    	    maxi = max(maxi, count);
    	}
    	return maxi;
    }
};