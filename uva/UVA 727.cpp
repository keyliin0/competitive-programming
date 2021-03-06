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

int n;
char E[] = { '+', '-', '*', '/' , '(' , ')' };

int pr(char c) {
	if (c == '+' || c == '-') return 1;
	if (c == '*' || c == '/') return 2;
	return -oo;
}

int main() {
	cin >> n;
	cin.ignore();
	cin.ignore();
	int cnt = 0;
	while (n--) {
		stack<char> st;
		string s;
		if (cnt) cout << endl;
		cnt++;
		while (1) {
			getline(cin, s);
			if (s.size() == 0 || !cin)
				break;
			bool digit = 1;
			loop(i, 0, 5)
				if (s[0] == E[i])
					digit = 0;
			if (digit) {
				cout << s;
				continue;
			}
			if (s[0] == '(') st.push('(');
			else if (s[0] == ')') {
				while (st.top() != '(') {
					cout << st.top();
					st.pop();
				}
				st.pop();
			}
			else {
				while (st.size() >= 1 && pr(st.top()) >= pr(s[0])) {
					cout << st.top();
					st.pop();
				}
				st.push(s[0]);
			}
		}
		while (!st.empty()) {
			cout << st.top();
			st.pop();
		}
		cout << endl;
	}
}