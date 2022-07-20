#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <sstream>
#include <utility>
#include <cctype>
#include <numeric>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <bitset>
#include <limits>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <functional>
#include <inttypes.h>
#include <fstream>
using namespace std;

bool can_move(char a,char b){
  return (a == 'B' && b == 'R') || (a == 'R' && b == 'G') || (a == 'G' && b == 'B');
}
const long long INF = 9999999999999;
const int MAX = 51;

//vector<bool> visited(MAX,false);
bool visited[MAX];

//vector<long long> dp(MAX,INF);
long long dp[MAX];

string r;
int n;

long long f(int k) {
  if (k == n-1)
    return 0;
  if (visited[k])
    return dp[k];

  long long answer = INF;

  for( int i = k+1; i < n; ++i )
    if (can_move(r[k], r[i])){
      long long candidate_energy = ((i-k)*(i-k)) + f(i);
      if (candidate_energy < answer)
        answer = candidate_energy;
    }

  dp[k] = answer;
  visited[k] = true;
  return answer;
}
void init_memo(){
  memset(visited,false,sizeof(visited));
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  while( cin >> r ) { 
    n = r.size();
    init_memo();
    long long ans = f(0);
    cout << (ans >= INF ? -1 : ans) << endl;
  }

  return 0;
}
