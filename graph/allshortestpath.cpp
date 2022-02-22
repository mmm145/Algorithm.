// allshortestpath.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<algorithm>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define nil 30000000
using namespace std;
int main()
{
	int v, e;
	cin >> v >> e;
	vector < vector<long long> >g(v,vector<long long> (v));
	rep(i, v) {
		rep(j, v) {
			g[i][j] = nil;
		}
	}
	rep(i,e) {
		int s, t;
		long long d;
		cin >> s >> t >> d;
		g[s][t] = d;
	}
	vector< vector< int> > a(v, vector<int>(v));
	rep(i, v) {
		rep(j, v) {
			if (i == j)a[i][j] = 0;
			else a[i][j] = g[i][j];
			
		}
	}
	for (int k = 0; k < v; k++) {
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
				
			}
		}
	}
	int n = 0;
	rep(i, v)if (a[i][i] < 0)n = 1;
	if (!n) {
		rep(i, v) {
			rep(j, v) {
				if (a[i][j] >= nil)cout << "INF ";
				else cout << a[i][j]<<" ";
			}
			cout << endl;
		}
	}
	else cout << "NEGATIVE CYCLE" << endl;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
