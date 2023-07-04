const int MAX = 200100;
const int MAX_M = 20002;
int dp[MAX];
int n, m;
int f(int k) {
  if ( k <= 0 || k > MAX_M ) return oo;
  if ( k == m )
    return 0;
  int &ans = dp[k];

  if ( ans != -1 ) return ans;
  ans = oo;
  ans = 1 + min(f(k-1), f(k*2));
  return ans;
}
int main() {
  cin >> n >> m;
  mone(dp);
  cout << f(n) << endl;
}

