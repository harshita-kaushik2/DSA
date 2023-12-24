//METHOD 1 : BRUTE FORCE : o(n^2) 
#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size(); 
    int repeating = -1, missing = -1;

    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] == i) cnt++;
        }

        if (cnt == 2) repeating = i;
        else if (cnt == 0) missing = i;

        if (repeating != -1 && missing != -1)   break;
    }
    return {repeating, missing};
}

int main() {
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}

// METHOD 2 : HASHING

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size(); 
    int hash[n + 1] = {0}; 

    //update the hash array:
    for (int i = 0; i < n; i++)    hash[a[i]]++;    

    //Find the repeating and missing number: O(2M)  SC : O(N)
    int repeating = -1, missing = -1;
    for (int i = 1; i <= n; i++) {      //VERY VERY CAREFUL TO INITIALIZE I=1 AND TRAVERSE TILL I <= N
        if (hash[i] == 2) repeating = i;
        else if (hash[i] == 0) missing = i;

        if (repeating != -1 && missing != -1)   break;
    }
    return {repeating, missing};
}

// METHOD 3 :  MATHS

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    long long n = a.size(); 

    // Find Sn and S2n:
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    long long val1 = S - SN;        //S-Sn = X-Y:

    long long val2 = S2 - S2N;      // S2-S2n = X^2-Y^2:

    val2 = val2 / val1;         //Find X+Y = (X^2-Y^2)/(X-Y):

    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // Here, X-Y = val1 and X+Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}


