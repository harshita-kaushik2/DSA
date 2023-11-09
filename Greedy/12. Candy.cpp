#include <bits/stdc++.h>
using namespace std;

vector<int> candyStore (int candies[], int n, int k) {
    sort(candies, candies+n);

    int mini = 0;
    int buy = 0;
    int free_candy = n-1;
    while(buy <= free_candy) {
        mini += candies[buy];
        buy++;
        free_candy = free_candy - k;
    }

    int maxi = 0;
    buy = n-1;
    free_candy = 0;
    while(free_candy <= buy) {
        maxi += candies[buy];
        buy--;
        free_candy = free_candy + k;
    }

    vector<int> ans;
    ans.push_back(mini);
    ans.push_back(maxi);

    return ans;
}

int main () {

}