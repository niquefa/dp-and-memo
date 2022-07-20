#Global
#visited = [False]*n
#dp = [0]*n

# In f(k)
#  if visited[k] :
#    return dp[k]
# Solve problem  
#  dp[k] = answer
#  visited[k] = True

# In Main 
#  global r, n, visited, dp
#  New case:
#    visited = [False]*n
#    dp = [0]*n


import time
from sys import stdin
d = {}
INF = 999999999999
r = "theRoadUndefinedAtTheBeginningtheRoadUndefinedAtTheBeginningtheRoadUndefinedAtTheBeginning"
n = len(r)
visited = [False]*n # visited[k]==true if f(k) was calculated already
dp = [0]*n #f(k) = dp[k]

def can_move(a,b):
  return (a == 'B' and b == 'R') or (a == 'R' and b == 'G') or (a == 'G' and b == 'B')

def f(k):
  global r, n, d
  d[k] = 1 if k not in d else d[k] + 1
  # Base case
  if k == n-1:
    return 0
  if visited[k]:
    return dp[k]

  answer = INF

  # General case
  for i in range(k+1, n):
    if can_move(r[k], r[i]):
      candidate_energy = ((i-k)**2) + f(i)
      if candidate_energy < answer:
        answer = candidate_energy
  dp[k] = answer
  visited[k] = True
  return answer

def main():
  start_time = time.time()
  global r, n, d, visited, dp

  while True:
    r = stdin.readline().strip()
    if r == '':
      break
    n = len(r)
    print(" With input: "+r+" r length "+str(len(r)))
    visited = [False]*n
    dp = [0]*n
    ans = f(0)
    print(-1 if ans >= INF else ans)
  print(d)
  print("Times f function was called "+str(sum(d.values())))
  print("--- %s seconds ---" % (time.time() - start_time))

if __name__ == "__main__":
    main()
