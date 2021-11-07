// dijkstra's algorithm without using priority queue
// In terms of a directed given graph, find single source shortest path 
#include<iostream>
#include<vector>

#define max 100001
using namespace std;
struct edge {
	long long weight;
	int index;
};
int main() {
	int n;
	cin >> n;
	long long M = n * max;
	vector< vector< edge> > g(n);
	vector<long long> d(n);
	for (int i = 0; i < n; i++) {
		int u, k;
		cin >> u >> k;
		for (int i = 0; i < k; i++) {
			int v, c;
			cin >> v >> c;
			edge temp;
			temp.weight = c;
			temp.index = v;
			g[u].push_back(temp);
		}
	}
	d[0] = 0;
	vector<int> S;
	S.push_back(0);
	vector<bool> in(n, false);
	in[0] = true;
	while (S.size() < n) {
		int minp;
		int mint;
		long long min = max * n;
		for (int i = 0; i < S.size(); i++) {
			for (int j = 0; j < g[S[i]].size(); j++) {
				if (in[g[S[i]][j].index])continue;
				if (min > d[S[i]] + g[S[i]][j].weight) {
					min = d[S[i]] + g[S[i]][j].weight;
					minp = S[i];
					mint = j;
				}
			}
		}
		S.push_back(g[minp][mint].index);
		in[g[minp][mint].index] = true;
		d[g[minp][mint].index] = d[minp] + g[minp][mint].weight;

	}
	
	for (int i = 0; i < n; i++) {
		cout << i << d[i] << endl;
	}
	return 0;
}