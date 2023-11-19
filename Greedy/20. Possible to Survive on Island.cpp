bool possible(int S, int M, int N) {
    int sundays = S/7;
    int buyDays = S - S/7;
    int ans = 0;
    int totalFoodNeeded = S*M;
    if (totalFoodNeeded % N == 0)   ans = totalFoodNeeded/N;
    else    ans = totalFoodNeeded/N + 1;

    if(ans <= buyDays)  return true;
    else    return false;
}