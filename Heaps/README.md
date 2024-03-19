# HEAPS
- They are present in ```#include<queue>``` header file.
- Heaps are a CBT (Complete Binary Tree) that come with a Heap Order Property. 
- A CBT is a Binary Tree that is filled at every level except the last level.
- Each node in a CBT is added from left. 
- ### Max-Heap: In a Max-Heap the key present at the root node must be greatest among the keys present at all of it’s children.
- ### Min-Heap: In a Min-Heap the key present at the root node must be minimum among the keys present at all of it’s children.
- Heap that are usually applied in questions that need sorting, convert the time complexity from NlogN to NlogK.

# IDENTIFICATION 
- If the question has mention of "K" and terms like "smallest/largest/minimum/maximum".
- When given "K + Smallest" --> Max Heap : Smallest poocha hai, toh humein bade elements ko pop karna hai. Max heap mei bade elements are on the top.
- When given "K + Largest" --> Min Heap : Largest poocha hai, toh humein chote elements ko pop karna hai. Min heap mei chote elements are on the top. 
- 

# STL 
- Min Heap : 
```priority_queue <int, vector<int>, greater<int>> pq;```

- Max Heap : 
```priority_queue<int> pq;```

