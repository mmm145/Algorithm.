#include<iostream>
#include<vector>
#define Max 200
using namespace std;
int n;
int A[Max][Max];
bool state[Max] = {false};
int parentof[Max];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}
	int sum = 0;
	vector<int> S;
	S.push_back(0);
	parentof[0] = -1;
	state[0] = true;
	while (S.size() < n) {
		int min = 3000;
		int index = 0;
		int parent = 0;
		for (int i = 0; i < S.size(); i++) {
			int p = S[i];
			for (int j = 0; j < n; j++) {
				if (A[p][j] == -1)continue;
				if (state[j])continue;
				if (A[p][j] < min) {
					index = j;
					min = A[p][j];
					parent = p;
				}
			}
		}
		sum += min;
		S.push_back(index);
		state[index] = true;
		parentof[index] = parent;
	}
	cout << sum << endl;
}