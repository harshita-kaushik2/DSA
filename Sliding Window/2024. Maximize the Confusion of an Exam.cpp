https://leetcode.com/problems/maximize-the-confusion-of-an-exam/
/*
A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse the students by maximizing the number of consecutive questions with the same answer 
(multiple trues or multiple falses in a row).

You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an integer k, the maximum number of times you may perform the following operation:
Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').
Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.

Example 1:
Input: answerKey = "TTFF", k = 2
Output: 4
Explanation: We can replace both the 'F's with 'T's to make answerKey = "TTTT".
There are four consecutive 'T's.

Example 2:
Input: answerKey = "TFFT", k = 1
Output: 3
Explanation: We can replace the first 'T' with an 'F' to make answerKey = "FFFT".
Alternatively, we can replace the second 'T' with an 'F' to make answerKey = "TFFF".
In both cases, there are three consecutive 'F's.
*/

class Solution {
public:
    // Helper function to find the longest substring with at most 'key' occurrences of character 'c'
    int solve(string s, int key, char c) {
        int start = 0, end = 0; // Pointers to track the current window
        int count = 0; // Count of occurrences of character 'c' within the window
        int ans = 0; // Length of the longest substring
        int size = s.size(); // Size of the input string 's'

        while (end < size) {
            // Expand the window while count is within the limit
            while (end < size && count <= key) {
                if (s[end] == c)
                    count++; // Increment count if character 'c' is encountered
                if (count <= key)
                    ans = max(ans, end - start + 1); // Update ans if current window is longer
                end++; // Move the end pointer to the right
            }

            // Shrink the window if count exceeds the limit
            while (start <= end && count > key) {
                if (s[start] == c)
                    count--; // Decrement count if character 'c' is encountered
                start++; // Move the start pointer to the right
            }
        }

        return ans; // Return the length of the longest substring with at most 'key' occurrences of 'c'
    }

    // Function to find the maximum length of consecutive 'T' or 'F' answers
    int maxConsecutiveAnswers(string answerKey, int k) {
        // Find the longest substring of consecutive 'T' with at most 'k' flips to 'F'
        int ans1 = solve(answerKey, k, 'T');
        // Find the longest substring of consecutive 'F' with at most 'k' flips to 'T'
        int ans2 = solve(answerKey, k, 'F');
        // Return the maximum length among the two cases
        return max(ans1, ans2);
    }
};