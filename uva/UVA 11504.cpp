/*
	its clear that we only need to push nodes with in degree = 0
	since cycles can cause a problem we must remove them with SCC 

*/
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
int oo = 1e5;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

int n, m, idx[N], low[N], T;
vector<vector<int> > g;
vector<int> S;
bool vis[N];
int compID[N], sz[N], cmp;
bool in[N];

void DFS(int u) {
	idx[u] = low[u] = ++T;
	S.push_back(u);
	vis[u] = true;
	for (int i = 0; i < g[u].size(); ++i) {
		int v = g[u][i];
		if (idx[v] == 0)
			DFS(v);
		if (vis[v])
			low[u] = min(low[u], low[v]);
	}
	if (idx[u] == low[u]) {
		while (true) {
			int v = S.back();
			S.pop_back();
			vis[v] = false;
			compID[v] = cmp;
			sz[cmp]++;
			if (v == u)
				break;
		}
		++cmp;
	}
}

int main() {
	int test;
	scanf("%d",&test);
	while (test--) {
		S.clear();
		memset(vis, 0, sizeof vis);
		memset(sz, 0, sizeof sz);
		memset(in, 0, sizeof in);
		memset(idx, 0, sizeof idx);
		memset(low, 0, sizeof low);
		S.clear();
		T = 0;
		cmp = 0;
		scanf("%d%d",&n,&m);
		g.clear();
		g.resize(n + 1);
		loop(i, 1, m) {
			int a, b;
			scanf("%d%d",&a,&b);
			g[a].push_back(b);
		}
		loop(i, 1, n)
			if(!idx[i]) DFS(i);
		loop(i, 1, n) {
			for (auto v : g[i]) {
				if (compID[i] != compID[v])
					in[compID[v]] = 1;
			}
		}
		int ans = 0;
		loop(i, 0, cmp - 1)
			if (!in[i])
				ans++;
		printf("%d\n",ans);
	}
}