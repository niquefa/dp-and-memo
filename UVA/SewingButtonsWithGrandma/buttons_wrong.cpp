#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <inttypes.h>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

//This solution is wrong, long long data type does not support the possible answers to the problems.

#define vat(a,t)         cout<<#a << " :  ";for(int JJ=0;JJ<t;++JJ)cout<<(JJ==0?"[":"")<<a[JJ]<<(JJ==t-1?"]\n":",");

const int MAX =  51;
long long nCk[MAX][MAX];
long long dp[MAX][MAX];
int m , kinds;
int b[MAX];

long long C(const int& n, const int& k) {
  if( n == k || k == 0 )
    return 1;
  if(k > n)
    return 0;
  long long& ans = nCk[n][k];
  if( ans != -1LL )
    return ans;
  return ans = C(n - 1,k - 1) + C(n - 1,k);
}

long long f(int m, int t) {
  if (m == 0)
    return 1;
  if (t >= kinds)
    return 0;

  long long& ans = dp[m][t];

  if (ans != -1LL)
    return ans;

  int buttons_i_can_use = min(m, b[t]);

  ans = 0;
  for (int i = 0; i <= buttons_i_can_use; i++)
    ans += C(m, i) * f(m - i, t + 1);

  return ans;
}

int main(){
  memset(nCk,-1,sizeof(nCk));
  /*
  for( int i = 0; i < MAX; ++i ){
    for( int j = 0; j <= i; ++j)
      cout << C(i,j) << " ";
    cout << endl;
  }
  */
  while( (cin >> m >> kinds) && m != 0 && kinds != 0 ) {
    memset(dp,-1,sizeof(dp));

    for( int i = 0; i < kinds; ++i ) 
      cin >> b[i];

    //cout << " Test Case " << m << " " << kinds << " " << endl;
    //vat(b,kinds)
    cout << f(m,0) << endl;


  }
  return 0;
}