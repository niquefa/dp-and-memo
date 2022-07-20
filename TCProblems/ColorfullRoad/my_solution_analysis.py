#Global
#d = {}

#in f(k)
#global d
#d[k] = 1 if k not in d else d[k] + 1

#in main
#start_time = time.time()
#print("--- %s seconds ---" % (time.time() - start_time))
import time
from sys import stdin
d = {}
INF = 999999999999
r = "theRoadUndefinedAtTheBeginning"
n = -1
def can_move(a,b):
  return (a == 'B' and b == 'R') or (a == 'R' and b == 'G') or (a == 'G' and b == 'B')

def f(k):
  global r, n, d
  d[k] = 1 if k not in d else d[k] + 1
  # Base case
  if k == n-1:
    return 0
  answer = INF

  # General case
  for i in range(k+1, n):
    if can_move(r[k], r[i]):
      candidate_energy = ((i-k)**2) + f(i)
      if candidate_energy < answer:
        answer = candidate_energy
  return answer

def main():
  start_time = time.time()
  global r, n, d

  while True:
    r = stdin.readline().strip()
    if r == '':
      break
    n = len(r)
    print(" With input: "+r+" r length "+str(len(r)))
    ans = f(0)
    print(-1 if ans >= INF else ans)
  print(d)
  print("Times f function was called "+str(sum(d.values())))
  print("--- %s seconds ---" % (time.time() - start_time))

if __name__ == "__main__":
    main()
