import time
import sys
 
def MI(): return map(int,sys.stdin.readline().strip().split())
def I(): return int(sys.stdin.readline().strip())
 
MAX = 100001;
dp = [-1 for i in range(MAX)]
c = MAX * [0]
 
def f(i): #TLE
  global dp, c
  if i == 0 :
    return 0
  if i == 1 :
    return c[1]
  if dp[i] != -1:
    return dp[i]
 
  ans = max( f(i-1), f(i-2) + c[i]*i)
 
  dp[i] = ans
 
  return ans
 
 
def main():
  global c
  I()
  a = MI()
  max_n = 0
  for x in a: 
    c[x] += 1
    max_n = max(max_n, x)
 
  #TLE for the call f(dp(max_n))
  
  dp = [0 for i in range(max_n + 1)]
  dp[1] = c[1]
  for i in range(2, max_n + 1):
    dp[i] = max(dp[i - 1], i * c[i] + dp[i - 2])
  
  print(dp[max_n])
 
    
if __name__ == "__main__":
    main()