Sliding Window identification : 

1. Dependency on contiguous elements: The problem's conditions or constraints are based on contiguous elements within the data. 
For example, finding the longest increasing subarray or the minimum window substring that contains all specified characters. 
Sliding window cannot be broken into pieces, ki aadhi window idhar hai aur aadhi udhar. So whenever there is an operation required on contiguous elements, 
Sliding Window can be thought of as a solution.

2. Overlapping subproblems: The problem exhibits overlapping subproblems, where the solution for one subarray or substring can be reused to solve the next adjacent
subarray or substring. The sliding window technique enables you to efficiently track the necessary information and update it incrementally as you slide the window.

3. Window optimization: The problem requires finding the optimal or most efficient subarray, subsequence, or substring that satisfies certain conditions. 
The sliding window method allows you to define a "window" that tracks the relevant portion of the data, updating it dynamically to optimize for the desired criteria.



Sliding Window problems can be of two types : 

A. Fixed size window
B. Varible size window (Window optimization problems)


