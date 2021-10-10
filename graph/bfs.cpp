#include<iostream>
#include<queue>
#define max 200
#define white 0
#define gray 1
#define black 2
using namespace std;
int M[max][max];
int d[max];
int state[max];
int main() {
	/* 
	 input ex)
	 4
	 1 2 2 4
	 2 1 4
	 3 0
	 4 1 3
	 */
	int n;// the number of vertex
	cin >> n;

	// initialization 
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)M[i][j] = 0;
	for (int i = 0; i < n; i++) {
		d[i] = -1;
		state[i] = white;
	}
	//storing the information of graph into M[][]
	for (int i = 0; i < n; i++) {
		int u, k;
		cin >> u >> k;
		for (int j = 0; j < k; j++) {
			int v;
			cin >> v;
			M[u - 1][v - 1] = 1;
		}
	}
	queue<int> que;
	que.push(0);
	d[0] = 0;
	state[0] = gray;
	while (!que.empty()) {
		int current = que.front();
		que.pop();
		state[current] = black;
		for (int i = 0; i < n; i++) {
			if (!M[current][i])continue;
			if (state[i])continue;
			d[i] = d[current] + 1;
			state[i] = gray;
			que.push(i);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << i + 1 << " " << d[i] << endl;
	}
	// output is the shortest distance between each node and node 1.
	return 0;
}