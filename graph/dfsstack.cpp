#include<iostream>
#include<stack>
#define white 0
#define gray 1
#define black 2
#define Max 100
using namespace std;
int n;
int M[Max][Max];
int state[Max] = { 0 }, d[Max] = { 0 }, f[Max] = { 0 };
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)M[i][j] = 0;
	for (int i = 0; i < n; i++) {
		int u, k;
		cin >> u >> k;
		for (int j = 0; j < k; j++) {
			int v;
			cin >> v;
			M[u-1][v-1] = 1;
		}
	}

	stack<int> dfs;
	int t = 0;
	for (int i = 0; i < n; i++) {
		if (dfs.empty()&&!state[i]) {
			dfs.push(i);
			t++;
			d[i] = t;
			state[i] = gray;
		}
		while (!dfs.empty()) {
			int current = dfs.top();
			for (int i = 0; i < n; i++){
				if (state[i])continue;
				else if (!M[current][i])continue;
				else {
					t++;
					d[i] = t;
					dfs.push(i);
					state[i] = gray;
					break;
				}
			}
			if (current==dfs.top()) {
				t++;
				f[current] = t;
				dfs.pop();
				state[current] = black;
			}

		}
	}
	for (int i = 0; i < n; i++) {
		cout << i + 1 << " " << d[i] << " " << f[i] << endl;
	}
	return 0;
}

