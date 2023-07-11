# Dynamic Programming
Remember these 3 general steps that have to be applied while creating a solution using DP : 

1. Represent the problem in terms of index
2. Do all possible stuffs on that index according to the problem statement.
3. Sum of all stuffs (to count all ways) or min/max as per question.

## Fibonacci Number using DP :
### Recrurrence -> Memoization
- Create a dp[n+1] array initialized to -1.
- Whenever we want to find the answer of a particular value (say n), we first check whether the answer is already calculated using the dp array(i.e dp[n]!= -1 ). If yes, simply return the value from the dp array.
- If not, then we are finding the answer for the given value for the first time, we will use the recursive relation as usual but before returning from the function, we will set dp[n] to the solution we get.

```
int f(int n, vector<int>& dp){
    if(n<=1) return n;
    
    if(dp[n]!= -1) return dp[n];        //Step 2
    return dp[n]= f(n-1,dp) + f(n-2,dp);        //Step 3
}
int main() {
  int n=5;
  vector<int> dp(n+1,-1);       //Step 1
  cout<<f(n,dp);
  return 0;
}
```
### Memoization -> Tabulation
- Declare a dp[] array of size n+1.
- First initialize the base condition values, i.e i=0 and i=1 of the dp array as 0 and 1 respectively.
- Set an iterative loop that traverses the array( from index 2 to n) and for every index set its value as dp[i-1] + dp[i-2]. 
```
int main() {
  int n=5;
  vector<int> dp(n+1,-1);          //Step 1
  
  dp[0]= 0;                         //Step 2
  dp[1]= 1;
  
  for(int i=2; i<=n; i++)
      dp[i] = dp[i-1]+ dp[i-2];     //Step 3
  cout<<dp[n];
  return 0;
}
```
### Tabulation -> Space Optimization 
- Each iteration’s cur_i and prev becomes the next iteration’s prev and prev2 respectively.
- Therefore after calculating cur_i, if we update prev and prev2 according to the next step, we will always get the answer. 
- After the iterative loop has ended we can simply return prev as our answer.
```
int main() {
  int n=5;
  int prev2 = 0, prev = 1;      
  
  for(int i=2; i<=n; i++){
      int cur_i = prev2+ prev;
      prev2 = prev;
      prev= cur_i;
  }
  cout<<prev;
  return 0;
}
```
## 2. Frog Jump
Energy lost in jumping from i to jth stair = abs(HEIGHT[j-1] - HEIGHT[i-1]). Can jump to i+1 or i+2. Min energy to reach Nth stair ? 

Greedy fails. Why ? Try it for the input : []