#include<iostream>
#include<vector>
#define w 0
#define gr 1
#define b 2
#define N 100
using namespace std;
int state[N] = {w};
int n;
int g[N][N];
int d[N], f[N];
int t = 0;
void dfs(int u) {
	state[u] = gr;
	t++;
	d[u] = t;
	for (int i = 0; i < n; i++) {
		if (!g[u][i])continue;
		if (state[i])continue;
		dfs(i);
	}
	t++;
	f[u] = t; 
	state[u] = b;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)g[i][j] = 0;
	for (int i = 0; i < n; i++) {
		int u, k;
		cin >> u >> k;
		u--;
		k;
		for (int j = 0; j < k; j++) {
			int c;
			cin >> c;
			c--;
			g[u][c] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (!state[i])dfs(i);
	}
	for (int i = 0; i < n; i++) {
		cout << i + 1 << " " << d[i] << " " << f[i] << endl;
	}

}