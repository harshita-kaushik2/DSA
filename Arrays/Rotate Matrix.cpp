/*
https://leetcode.com/problems/rotate-image/
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
*/

/*
BRUTE FORCE => Create an extra 2D matrix. Usmei har element ko map kar ke dekho you will end up with a conversion relation.
*/

int ans[n][n];
for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        ans[j][n-1-i] = matrix[i][j];
    }
}

/*
IN-PLACE REPLACEMENT => By observation we see that, if we find the transpose of the matrix and then reverse each row we end up with clockwise rotated matrix.
1. Transpose
2. Rotate each row
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Transpose the matrix
        for(int i=0; i<n; i++)
            for(int j=0; j<i; j++)      //most crucial step. If you do not j<i you swap it again leading to same initial matrix.
                swap(matrix[i][j], matrix[j][i]);

        // Reverse each row of the matrix
        for(int i=0; i<n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};