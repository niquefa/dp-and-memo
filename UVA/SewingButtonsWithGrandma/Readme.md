
# Sewing Buttons with Grandma 
  
# URL
https://onlinejudge.org/contests/285-318a0d96/12316.html

After so many years of studying math in the Academy of Colombian Mathematics (ACM) in the tropic, Eloi has finally decided to visit his grandmother for the winter in the north hemisphere. ``Buttons and patches and the cold wind blowing, the days pass quickly when I am sewing'' she says - Eloi now remembers how grandma quilts have love in every stitch. As a matter of fact, he has decided to learn the useful handicraft art of sewing buttons with grandma.

Eloi has realized that there is an interesting mathematical puzzle related to the task of sewing buttons to the front of a shirt. Given a collection of n1 buttons of color b1, n2 buttons of color b2, ..., bk buttons of color ck, and a shirt with m front buttonholes, in how many ways the buttonholes can be assigned m buttons from the n1 + ... + nk buttons?

# Input 
The input consists of several test cases. The first line of each test case contains two integers *m* and *k* separated by a blank ( 1 <= *m* <= 50, 1 <= *k* <= 50). Then *k* lines follow each containing an integer ni with 1 <= *b[i]* <= 50. The last test case is followed by a line containing two zeros.

# Output 
The output consists of one line per test case containing the number of ways the m buttonholes can be assigned m buttons from the b1 + ... + bk buttons, assuming that the colors c1,..., ck are pairwise distinct.

# Sample Input 
1 3
3
1
1
3 2
4
2
3 2
1
1
0 0
# Sample Output 
3
7
0

# Example analysis

## First example:
1 3
3
1
1

One slot for button, three options of the same color, the answer is 3

## Second example
3 2
4
2

Four buttons of a color, and two of other color, let's say buttons {x,x,x,x,y,y} we should assign to three slots, there are 7 ways:
x,x,x
x,x,y
x,y,x
x,y,y
y,x,x
y,x,y
y,y,x


## Third example
3 2
1
1

Three slots for buttons, only two buttons available, is impossible to assign buttons to the slots.

# More complex example:
3 5
2
1
4
2
3
m = 3
kinds = 5
2 de color x
1 de color y
4 de color z
2 de color w
3 de color u

{x,x,y,z,z,z,z,w,w,u,u,u}
Examples:

x,x,w
u,u,w
u,z,y
y,z,u
x,x,y
y,x,x
u,z,z

Stage 0: I select buttons of color x and assign them:
  Option 1: Select 0 buttons of color x
  Option 2: Select 1 button of color x
  Option 3: Select 2 buttons of color x

Stage 1: I select buttons of color y and assign them:
  Option 1: Select 0 buttons of color y
  Option 2: Select 1 button of color y
  
Stage 2: I select buttons of color z and assign them:
  Option 1: Select 0 buttons of color z
  Option 2: Select 1 button of color z
  Option 3: Select 2 buttons of color z
  Option 4: Select 3 buttons of color z
  Option 5: Select 4 buttons of color z

Stage 3: I select buttons of color w and assign them:
  Option 1: Select 0 buttons of color w
  Option 2: Select 1 button of color w
  Option 3: Select 2 buttons of color w

Stage 4: I select buttons of color u and assign them:
  Option 1: Select 0 buttons of color u
  Option 2: Select 1 button of color u
  Option 3: Select 2 buttons of color u
  Option 4: Select 3 buttons of color u

# Examples of solution function:
f(m,t): Ways to assign m slots left starting from stage t. 
Solution will be f(m,0). *This is the one we are going to see in the solutions in this repository*.

Another: 
f(m,t): Ways to assign m slots left using the last t types of buttons.
Solution will be f(m,k)

Another: 
f(i,t): Ways to assign from i to m slots left using the last k types of buttons.
Solution will be f(0,k)

Another: 
f(m,s): Ways to assign m slots left using buttons from the set s. Example of s: {x,y}
Solution will be f(m,{x,y,z,w,u})

Lets check this option: f(m,t): Ways to assign m slots left starting from stage t. Solution will be f(m,0)

# Trying to understand the recursive function we must create

when t = 0. we have b[0].   1<=b[0]<=50
We can choose between 0 and min(m,b[0]) buttons of color b[0]

C(m,0) * f(m,t+1) = 1 * f(m,1)
+
C(m,1) * f(m-1,t+1) = m * f(m-1,1)
+
C(m,2) * f(m-2,t+1) = C(m,2) * f(m-2,1)
Partial solution: X[0]

when t = 1. we have b[1].   1<=b[1]<=50
We can choose between 0 and min(m,b[1]) buttons of color b[1]
Partial solution: X[1]
C(m,0) * f(m,t+1) = 1 * f(m,2)
+
C(m,1) * f(m-1,t+1) = m * f(m-1,2)
+
C(m,2) * f(m-2,t+1) = C(m,2) * f(m-2,2)
+
C(m,3) * f(m-3,t+1) = 1 * f(m-3,2)

when t = 2. we have b[2].   1<=b[2]<=50
We can choose between 0 and min(m,b[2]) buttons of color b[2]
Partial solution: X[2]
C(m,0) * f(m,t+1) = 1 * f(m,3)
+
C(m,1) * f(m-1,t+1) = m * f(m-1,3)
+
C(m,2) * f(m-2,t+1) = C(m,2) * f(m-2,3)
+
C(m,3) * f(m-3,t+1) = 1 * f(m-3,3)

when t = 3. we have b[3].   1<=b[3]<=50
We can choose between 0 and min(m,b[3]) buttons of color b[3]
Partial solution: X[3]

