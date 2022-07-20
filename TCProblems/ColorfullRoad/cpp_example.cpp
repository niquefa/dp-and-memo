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
void print_vector(const vector<int>& x){
  cout << "Printing vector of size " << x.size() << endl;
  for( int i = 0; i < x.size(); i++){
    cout << i << " " << x[i] << endl; 
  }
}
void f(vector<int> b){
  b.push_back(5);
  print_vector(b);
}
int main() {
  vector<int> a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a.erase(a.begin()+2);
  //sort(a.begin(),a.end());
  //fill(a.begin(),a.end(),99);
  //f(a);
  print_vector(a);

  return 0;
}
