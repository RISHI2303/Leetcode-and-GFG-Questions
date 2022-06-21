**Explanation**
Heap heap store k height difference that we need to use ladders.
Each move, if the height difference d > 0,
we push d into the priority queue pq.
If the size of queue exceed ladders,
it means we have to use bricks for one move.
Then we pop out the smallest difference, and reduce bricks.
If bricks < 0, we can't make this move, then we return current index i.
If we can reach the last building, we return A.length - 1.
​
​
**Complexity**
Time O(NlogK)
Space O(K)