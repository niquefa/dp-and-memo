import time
import sys

def MI(): return map(int,sys.stdin.readline().strip().split())
def I(): return int(sys.stdin.readline().strip())

MAX = 51;
nCk = [[-1 for i in range(MAX)] for j in range(MAX)]
dp = [[-1 for i in range(MAX)] for j in range(MAX)]
kinds = MAX
b = [0]*MAX

def C(n, k):
  global nCk
  if n == k or k == 0 :
    return 1
  if k > n:
    return 0
  if nCk[n][k] != -1:
    return nCk[n][k];

  nCk[n][k] = C(n - 1,k - 1) + C(n - 1,k)
  return nCk[n][k]

def f(m, t):
  global kinds, dp, b
  if m == 0 :
    return 1
  if t >= kinds:
    return 0

  if dp[m][t] != -1: 
    return dp[m][t]

  buttons_i_can_use = min(m, b[t])

  ans = 0;
  for i in range(buttons_i_can_use+1):
    ans += C(m, i) * f(m - i, t + 1)

  dp[m][t] = ans

  return ans

def main():
  global nCk, dp, b, kinds

  while True:
    m, kinds = MI()
    if m == 0 and kinds == 0:
      break
    for i in range(kinds):
      b[i] = I()

    dp = [[-1 for i in range(MAX)] for j in range(MAX)]
    answer = f(m,0)
    print(answer)
    
if __name__ == "__main__":
    main()
