// BRUTE FORCE -> PERFORM LINEAR SEARCH. CHECK EACH ELEMENT BY SQUARING & COMPARING WITH TARGET. 
for(int i = 1; i <= n; i++) {
    if( i*i <= n) ans = i;
    else break;
}

//OPTIMIZED = BINARY SEARCH ON ANSWERS

int low = 1, high = n;

while( low <= high) {
    int mid = (high+low)/2;
    if((mid*mid) <= n) {
        low = mid+1;
    }
    else    high = mid-1;
}

return high;