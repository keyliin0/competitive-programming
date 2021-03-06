#include<bits/stdc++.h>
using namespace std;
#define loop(i,b,e) for(int i=b;i<=e;i++)
#define loop2(i,e,b) for(int i=e;i>=b;i--)
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define X real()
#define Y imag()
#define cp(a,b)    ( (conj(a)*(b)).imag() )
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define length(a) (hypot((a).imag(), (a).real()))
#define rotateO(p,ang) ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define logg2  0.30102999566398119521373889472449L
typedef complex<double> point;
typedef long long ll;
typedef unsigned long long ull;
double PI = 3.141592653589793;
const double EPS = 1e-6;
const int N = 1e6 + 5;
const ll mod = 1e9 + 7;
int oo = 1e9;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n;
ll cst[100005][3];
int in[N];
vector<vector<int> > g;
ll curr;
int M[] = { 0,1,2 };

void dfs(int u,int m,int p = -1) {
	curr += cst[u][M[m]];
	for (auto v : g[u]) {
		if (v != p)
			dfs(v, (m + 1) % 3, u);
	}
}

int ANS[N];

void dfs2(int u, int m, int p = -1) {
	ANS[u] = M[m];
	for (auto v : g[u]) {
		if (v != p)
			dfs2(v, (m + 1) % 3, u);
	}
}

int main() {
	scanf("%d",&n);
	g.resize(n + 1);
	loop(j, 0, 2) {
		loop(i, 1, n)
			scanf("%lld", &cst[i][j]);
	}
	loop(i, 1, n - 1) {
		int a, b;
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
		in[a]++;
		in[b]++;
		if (in[a] >= 3 || in[b] >= 3) {
			printf("-1");
			return 0;
		}
	}
	int best = -1;
	ll ans = 1e18;
	int start;
	loop(i, 1, n) {
		if (in[i] == 1)
			start = i;
	}
	do {
		curr = 0;
		dfs(start, 0);
		if (curr < ans) {
			ans = curr;
			dfs2(start, 0);
		}
	} while (next_permutation(M, M + 3));
	printf("%lld\n",ans);
	loop(i, 1, n)
		printf("%d ",ANS[i] + 1);
}
 