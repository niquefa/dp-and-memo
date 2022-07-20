from sys import stdin

INF = 999999999999
r = "theRoadUndefinedAtTheBeginning"
n = -1
def can_move(a,b):
  return (a == 'B' and b == 'R') or (a == 'R' and b == 'G') or (a == 'G' and b == 'B')

def f(k):
  global r, n
  
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
  global r, n

  while True:
    r = stdin.readline().strip()
    if r == '':
      break
    n = len(r)
    ans = f(0)
    print(-1 if ans >= INF else ans)

if __name__ == "__main__":
    main()
