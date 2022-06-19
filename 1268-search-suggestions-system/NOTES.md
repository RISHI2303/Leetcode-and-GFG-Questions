**Intuition**

In a sorted list of words,
for any word `A[i]`,
all its sugested words must following this word in the list.

For example, if `A[i]` is a prefix of `A[j],`
`A[i]` must be the prefix of `A[i + 1], A[i + 2], ..., A[j]`

**Explanation**

With this observation,
we can binary search the position of each prefix of search word,
and check if the next 3 words is a valid suggestion.


**Complexity**

Time `O(NlogN)` for sorting
Space `O(logN)` for quick sort.

Time `O(logN)` for each query
Space `O(query)` for each query
where I take word operation as `O(1)`
