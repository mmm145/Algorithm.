#include<iostream>
#include<fstream>
#include<vector>
#define max 100
using namespace std;
bool verify(vector<int> a) {
	for (int i = 0; i < a.size()-1; i++) {
		if (a[i] > a[i + 1])return false;
	}
	return true;
}
int main() {
	// this program get information of numbers from txt file
	ifstream fin("input.txt");
	
	vector<int> before;
	int n;
	int i = 0;
	while (fin >> n) {
		before.push_back(n);
	}
	fin.close();

	cout << "Array before sorting:" << endl;
	for (int i = 0; i < before.size(); i++) {
		if (i)cout << " ";
		cout << before[i];
	}
	int counter[max] = {0};
	vector<int> after(before.size());
	for (int i = 0; i < before.size(); i++) {
		counter[before[i]]++;
	}
	for (int i = 0; i < max-1; i++) {
		counter[i + 1] += counter[i];
	}
	for (int i = 0; i < before.size(); i++) {
		after[counter[before[i]] - 1] = before[i];
		counter[before[i]]--;
	}
	cout << endl << endl << "Array after sorting: " << endl;
	for (int i = 0; i < after.size(); i++) {
		if (i)cout << " ";
		cout << after[i];
	}

	if (verify(after))cout<<endl << "valid" << endl;
	else cout<<endl << "not valid" << endl;
}
