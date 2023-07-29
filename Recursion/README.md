# Recursion on Subsequences
It is all about take or not take. Time Complexity : (2^N) x N

```cpp
f(ind, []) {
    if(ind >= n){
        print ([]);
        return;
    }
    [].add(arr[i]);
    f(ind+1,[]) // case : take
    [].remove(arr[i]);
    f(ind+1,[])
}
```