import time
import sys

def MI(): return map(int,sys.stdin.readline().strip().split())
def I(): return int(sys.stdin.readline().strip())

MAX = 55;
nCk = [[-1 for i in range(MAX)] for j in range(MAX)]
dp = [[-1 for i in range(MAX)] for j in range(MAX)]
kinds = MAX
b = [0]*MAX

def C(n, k):
  global nCk
  if k == 0 or n == k :
    return 1
  if k > n :
    return 0

  if nCk[n][k] != -1:
    return nCk[n][k]

  ans = C(n-1,k-1) + C(n-1,k)

  nCk[n][k] = ans

  return ans

def f(m, t):
  global kinds, dp, b
  
  if m == 0:
    return 1
  if t >= kinds:
    return 0

  if dp[m][t] != -1:
    return dp[m][t]

  buttons_to_use = min(m,b[t])
  ans = 0

  for i in range(buttons_to_use+1):
    ans += C(m, i) * f(m-i,t+1)

  dp[m][t] = ans

  return ans

def main():
  global nCk, dp, b, kinds

  #for i in range(MAX):
  #  for j in range(0,i+1,1):
  #    print(str(C(i,j))+" ",end="")
  #  print()

  while True:
    m, kinds = MI()
    if m == 0 and kinds == 0:
      break
    for i in range(kinds):
      b[i] = I()
    #print(str(m)+" "+str(kinds)+" "+str(b)  )

    dp = [[-1 for i in range(MAX)] for j in range(MAX)]
    answer = f(m,0)
    print(answer)
    
if __name__ == "__main__":
    main()
