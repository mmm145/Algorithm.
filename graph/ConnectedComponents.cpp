// it would be better to use list as a data structure when n is 
#include<iostream>
#include<vector>
#include<stack>
#define white 0
#define gray 1
#define black 2

using namespace std;
int n;
bool connected(vector<vector<int> > g, vector<int> state,int s, int t) {
	stack<int> dfs;
	dfs.push(s);
	state[s] = gray;
	while (!dfs.empty()) {
		int current = dfs.top();
		for (int i : g[current]) {
			if (state[i])continue;
			if (i == t) return true;
			dfs.push(i);
			state[i] = gray;
			break;
		}
		if (current == dfs.top()) {
			dfs.pop();
			state[current] = black;
		}
	}
	return false;
}
int main() {

	int m;
	cin >> n;
	cin >> m;
	vector<vector<int> > g(n);
	for (int i = 0; i < m; i++) {
		int s, t;
		cin >> s >> t;
		g[s].push_back(t);
		g[t].push_back(s);
	}
	int q;
	cin >> q;
	while (q > 0) {
		int s, t;
		cin >> s >> t;
		vector< int > state(n, white);
		if (connected(g,state, s, t))cout << "yes" << endl;
		else cout << "no" << endl;
		q--;
	}
	return 0;
}