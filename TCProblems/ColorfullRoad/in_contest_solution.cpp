//Adapted from https://community.topcoder.com/stat?c=problem_solution&rm=319224&rd=15708&pm=12837&cr=22752170
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
 
using namespace std;
  
bool isValid(char a, char b) {
  if(a == 'R' && b == 'G') return true;
  if(a == 'G' && b == 'B') return true;
  if(a == 'B' && b == 'R') return true;
  return false;
}
int getMin(string road) {
  int n = road.length();
  vector <int> dp(n,100000);
  dp[0] = 0;
  for(int i = 1 ; i < n ; i++) {
    for(int j = 0 ; j < i ; j++) {
      if(isValid(road[j], road[i])) {
        dp[i] = min(dp[i], dp[j] + (i-j)*(i-j));
      }
    }
  }
  if(dp[n-1] != 100000) {
    return dp[n-1];
  } else {
    return -1;
  }
}
int main(){
  string road;
  while( cin >> road ){
    cout << getMin(road) << endl;
  }
}
