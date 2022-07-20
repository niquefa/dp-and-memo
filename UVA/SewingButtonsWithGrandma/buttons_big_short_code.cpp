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

#define vat(a,t)         cout<<#a << " :  ";for(int JJ=0;JJ<t;++JJ)cout<<(JJ==0?"[":"")<<a[JJ]<<(JJ==t-1?"]\n":",");

///////BEGIN BIG INT/////////
// Taken from: https://www.geeksforgeeks.org/bigint-big-integers-in-c-with-example/ 

using namespace std;

class BigInt{
	string digits;
public:

	//Constructors:
	BigInt(unsigned long long n = 0);
	BigInt(string &);
	BigInt(const char *);
	BigInt(BigInt &);

	//Helper Functions:
	friend bool Null(const BigInt &);
	friend int Length(const BigInt &);
	int operator[](const int)const;

			/* * * * Operator Overloading * * * */

	//Direct assignment
	BigInt &operator=(const BigInt &);

	//Post/Pre - Incrementation
	BigInt &operator++();
	BigInt operator++(int temp);
	BigInt &operator--();
	BigInt operator--(int temp);

	//Addition and Subtraction
	friend BigInt &operator+=(BigInt &, const BigInt &);
	friend BigInt operator+(const BigInt &, const BigInt &);
	friend BigInt operator-(const BigInt &, const BigInt &);
	friend BigInt &operator-=(BigInt &, const BigInt &);

	//Comparison operators
	friend bool operator==(const BigInt &, const BigInt &);
	friend bool operator!=(const BigInt &, const BigInt &);

	friend bool operator>(const BigInt &, const BigInt &);
	friend bool operator>=(const BigInt &, const BigInt &);
	friend bool operator<(const BigInt &, const BigInt &);
	friend bool operator<=(const BigInt &, const BigInt &);

	//Multiplication and Division
	friend BigInt &operator*=(BigInt &, const BigInt &);
	friend BigInt operator*(const BigInt &, const BigInt &);
	

	//Read and Write
	friend ostream &operator<<(ostream &,const BigInt &);
	friend istream &operator>>(istream &, BigInt &);
};

bool Null(const BigInt& a){
	if(a.digits.size() == 1 && a.digits[0] == 0)
		return true;
	return false;
}
int Length(const BigInt & a){
	return a.digits.size();
}
int BigInt::operator[](const int index)const{
	if(digits.size() <= index || index < 0)
		throw("ERROR");
	return digits[index];
}
BigInt::BigInt(const char *s){
	digits = "";
	for (int i = strlen(s) - 1; i >= 0;i--)
	{
		if(!isdigit(s[i]))
			throw("ERROR");
		digits.push_back(s[i] - '0');
	}
}
BigInt::BigInt(string & s){
	digits = "";
	int n = s.size();
	for (int i = n - 1; i >= 0;i--){
		if(!isdigit(s[i]))
			throw("ERROR");
		digits.push_back(s[i] - '0');
	}
}
BigInt::BigInt(unsigned long long nr){
	do{
		digits.push_back(nr % 10);
		nr /= 10;
	} while (nr);
}
BigInt::BigInt(BigInt & a){
	digits = a.digits;
}

bool operator==(const BigInt &a, const BigInt &b){
	return a.digits == b.digits;
}
bool operator!=(const BigInt & a,const BigInt &b){
	return !(a == b);
}

BigInt &BigInt::operator=(const BigInt &a){
	digits = a.digits;
	return *this;
}

BigInt &operator+=(BigInt &a,const BigInt& b){
	int t = 0, s, i;
	int n = Length(a), m = Length(b);
	if(m > n)
		a.digits.append(m - n, 0);
	n = Length(a);
	for (i = 0; i < n;i++){
		if(i < m)
			s = (a.digits[i] + b.digits[i]) + t;
		else
			s = a.digits[i] + t;
		t = s / 10;
		a.digits[i] = (s % 10);
	}
	if(t)
		a.digits.push_back(t);
	return a;
}
BigInt operator+(const BigInt &a, const BigInt &b){
	BigInt temp;
	temp = a;
	temp += b;
	return temp;
}

BigInt &operator*=(BigInt &a, const BigInt &b)
{
	if(Null(a) || Null(b)){
		a = BigInt();
		return a;
	}
	int n = a.digits.size(), m = b.digits.size();
	vector<int> v(n + m, 0);
	for (int i = 0; i < n;i++)
		for (int j = 0; j < m;j++){
			v[i + j] += (a.digits[i] ) * (b.digits[j]);
		}
	n += m;
	a.digits.resize(v.size());
	for (int s, i = 0, t = 0; i < n; i++)
	{
		s = t + v[i];
		v[i] = s % 10;
		t = s / 10;
		a.digits[i] = v[i] ;
	}
	for (int i = n - 1; i >= 1 && !v[i];i--)
			a.digits.pop_back();
	return a;
}
BigInt operator*(const BigInt&a,const BigInt&b){
	BigInt temp;
	temp = a;
	temp *= b;
	return temp;
}

ostream &operator<<(ostream &out,const BigInt &a){
	for (int i = a.digits.size() - 1; i >= 0;i--)
		cout << (short)a.digits[i];
	return cout;
}
///////END BIG INT/////////

const int MAX =  51;
long long nCk[MAX][MAX];
BigInt dp[MAX][MAX];
bool already_calculated[MAX][MAX];
BigInt ONE("1");
BigInt ZERO("0");
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

BigInt f(int m, int t) {
  if (m == 0)
    return ONE;
  if (t >= kinds)
    return ZERO;

  if (already_calculated[m][t])
    return dp[m][t];

  int buttons_i_can_use = min(m, b[t]);

  BigInt ans("0");
  for (int i = 0; i <= buttons_i_can_use; i++){
    BigInt combination(C(m,i));
    ans += combination * f(m - i, t + 1);
  }
   

  already_calculated[m][t] = true;
  dp[m][t] = ans;
  return ans;
}
void fill_dp() {
  for( int i = 0; i < MAX; ++i )
    for( int j = 0; j < MAX; ++j ) {
      already_calculated[i][j] = false;
    }
}

int main(){
  memset(nCk,-1,sizeof(nCk));

  while( (cin >> m >> kinds) && m != 0 && kinds != 0 ) {
    fill_dp();

    for( int i = 0; i < kinds; ++i ) 
      cin >> b[i];

    cout << f(m,0) << endl;
  }
  return 0;
}