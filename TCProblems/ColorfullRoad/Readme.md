# ColorfulRoad
Problem URL:

https://community.topcoder.com/stat?c=problem_statement&pm=12837&rd=15708&rm=319249&cr=23221647

# Problem Statement
    	
There is a one-dimensional road. The road is separated into N consecutive parts. The parts are numbered 0 through N-1, in order. Ciel is going to walk from part 0 to part N-1.

Ciel also noticed that each part of the road has a color: either red, green, or blue. Part 0 is red.

Ciel is going to perform a sequence of steps. Each step must lead in the positive direction. That is, if her current part is i, the next step will take her to one of the parts i+1 through N-1, inclusive. Her steps can be arbitrarily long. However, longer steps are harder: a step of length j costs j*j energy.

Additionally, Ciel wants to step on colors in a specific order: red, green, blue, red, green, blue, ... That is, she starts on the red part 0, makes a step to a green part, from there to a blue part, and so on, always repeating red, green, and blue in a cycle. Note that the final part N-1 also has some color and thus Ciel must reach it in a corresponding step.

You are given a String road containing N elements. For each i, element i of road is the color of part i: 'R' represents red, 'G' green, and 'B' blue. If Ciel can reach part N-1 in the way described above, return the smallest possible total cost of doing so. Otherwise, return -1.
   
 
Constraints
-	road will contain between 2 and 15 characters, inclusive.
-	Each character of road will be either 'R' or 'G' or 'B'.
-	The first character of road will be 'R'.
 
# Examples
	
"RGGGB"
Solution: 8
The optimum solution is to step part 0 -> part 2 -> part 4. The total cost is 2*2 + 2*2 = 8.
    	
"RGBRGBRGB"
Solution: 8
The optimum solution is to make steps of length 1. It costs 1*1 = 1 per each step, so the total cost is 8.
    	
"RBBGGGRR"
Solution: -1
It is impossible to reach the destination.	
    	
"RBRRBGGGBBBBR"
Solution: 50	
    	
"RG"
Solution: 1
    	
"RBRGBGBGGBGRGGG"
Returns: 52

The input in the file colorfullroad.in consist of a test case by line, for testing the problem solution in topcoder, follow topcoder's standards. For teaching, training or learning purposes you can use the input files.



# Recurrence relation

## Functions and definitions

n: The size of the road. We assume index start at 0 and end at n-1.

## can_move(r_k, r_i) 

Boolean function that returns true if we can move from position k to position i with the condition that k < i.

## cost of single move

(i-k)*(i-k): Cost of moving from position k to position i, also with the condition that k < i.

## Recurrence relation

f(k) : Minimum cost of going from position k up to position n-1 always moving right and always following the color pattern R->G->B->R->G->B...

### Base case

f(n-1) = 0. 

### General case

f(k) = min{ (i-k)*(i-k) + f(i) where k < i < n and can_move(r_k,r_i) is true}