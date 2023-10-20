Link : https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
/*
Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.
*/

class Solution {
public:
    long maximumSumSubarray(int K, vector<int> &Arr, int N) {
        // Initialize variables
        int start = 0; // Start index of the subarray
        long ans = INT_MIN; // Maximum sum found so far
        long sum = 0; // Current sum of elements in the subarray

        // Iterate over the array
        for (int end = 0; end < N; end++) {
            sum += Arr[end]; // Add the current element to the sum

            // Check if the subarray length is equal to K
            if (end - start + 1 == K) {
                ans = max(ans, sum); // Update the maximum sum if necessary
                sum -= Arr[start]; // Subtract the element at the start index from the sum
                start++; // Move the start index to the right
            }
        }

        return ans; // Return the maximum sum of a subarray of length K
    }
};

// METHOD 2  ===========================================================================================>
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
       int start = 0, end = 0;
        long sum = 0, max_sum = LLONG_MIN; 
        while (end < K) {
            sum += Arr[end++];
        }

        while (end < N) {
            max_sum = max(max_sum, sum);
            sum += Arr[end++] - Arr[start++];
        }

        max_sum = max(max_sum, sum); 
        return max_sum;
    }
};