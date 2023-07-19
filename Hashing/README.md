# Hashing
A good hash function should have the following properties:
1.  Efficiently computable.  
2.  Should uniformly distribute the keys (Each table position is equally likely for each.
3.  Should minimize collisions.
4.  Should have a low load factor(number of items in the table divided by the size of the table).

### Collision 
The situation where the newly inserted key maps to an already occupied. There are mainly two methods to handle collision: 

#### 1) Separate Chaining
The idea is to make each cell of the hash table point to a linked list of records that have the same hash function value. Chaining is simple but requires additional memory outside the table.