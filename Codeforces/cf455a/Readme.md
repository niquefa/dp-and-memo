
# 456C - Boredom / 455A - Boredom
  
# URL
https://codeforces.com/blog/entry/13336

# Sample Output 

# Example analysis

## First example:

## Second example

## Third example

# More complex example:

# Examples of solution function:
Solution will be f(n): The maximum number of points using numbers 1 to n.

We need a frequency table c.
c(i) + times number i appears in the input data.
```
f(0) = 0 will be the naive base case
f(1) = c(1) Will be the second base case

f(i) = max( f(i-1), f(i-2) + c(i)*i)
```
Basically if we include the "i" we will not include i-1 but we may include i-2; So by choosing "i", we will get as our next decision to choose whether or not to include i-2, because we discarded i-1 as it is stated in the problem statement.

For example, for the input data

```
9
1 2 1 3 2 2 2 2 3
```

We will have:
```
c = {1=>2, 2=>5, 3=>2}

f(i) = max( f(i-1), f(i-2) + c(i)*i )
f(3) = max( f(2), f(1) + c(3)*3 ) 
f(3) = max( f(2), f(1) + 2*3 )
f(3) = max( f(2), f(1) + 6 )
f(3) = max( f(2), 2 + 6 )
f(3) = max( f(2), 8 )

f(2) = max( f(1), f(0) + c(2)*2 )
f(2) = max( f(1), f(0) + 5*2 )
f(2) = max( 2, 0 + 10 )
f(2) = 10

f(3) = max(10, 8)
f(3) = 10
```

# Trying to understand the recursive function we must create
