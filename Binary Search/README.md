Time COmplexity = O( log n base 2)
# Recursive Binary Search
```cpp
int binarySearch(int arr[], int target) {
    int n = int n = sizeof(arr) / sizeof(arr[0]);
    int l = 0, r = n - 1;

    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)  return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
```

# Lower Bound : Smallest index such that  ```cpp  arr[ind] >= n ```

```cpp
int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] >= x) {                // maybe an answer
            ans = mid;
            high = mid - 1;                //look for smaller index on the left
        }
        else {
            low = mid + 1;                 // look on the right
        }
    }
    return ans;
}
```

lb = lower_bound ( arr.begin(), arr.end(), target );     //This returns the pointer to that index. 

lb = lower_bound ( arr.begin(), arr.end(), target ) - arr.begin();   //returns index

# Upper Bound : Smallest index such that ```cpp arr[ind] > n ```

ub = upper_bound ( arr.begin(), arr.end(), target ) - arr.begin();   //returns index

# Ceil of a Number = Exactly same as lower bound of a number
Smallest element in array >= target             // value and not the index

# Floor of a Number
Largest element in the array <= target          // value and not the index

 ```cpp
 int findFloor(int arr[], int n, int x) {
	int low = 0, high = n - 1;
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] <= x) {    	    // maybe an answer
			ans = arr[mid];
			low = mid + 1;              //look for smaller index on the left
		}
		else {
			high = mid - 1;             // look on the right
		}
	}
	return ans;
}
 ```


