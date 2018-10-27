#include <bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define X real()
#define Y imag()
#define cp(a,b)    ( (conj(a)*(b)).imag() )
#define length(a) (hypot((a).imag(), (a).real()))
typedef complex<double> point;
typedef long long ll;
typedef unsigned long long ull;
double PI = 3.141592653589793;
const double EPS = 1e-9;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
const int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

ll t[26], prefix[N];
map<ll, int> freq[26];
string s;


int main() {
	io;
	loop(i, 0, 25) {
		cin >> t[i];
	}
	cin >> s;
	prefix[0] = t[s[0] - 'a'];
	loop(i, 1, s.size() - 1) {
		prefix[i] = t[s[i] - 'a'] + prefix[i - 1];
		freq[s[i] - 'a'][prefix[i - 1]]++;
	}
	ll ans = freq[s[0] - 'a'][prefix[0]];
	loop(i, 1, s.size() - 1) {
		freq[s[i] - 'a'][prefix[i - 1]]--;
		ans += freq[s[i] - 'a'][prefix[i]];
	}
	cout << ans;
}