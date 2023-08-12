#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
	int num;
	cin >> num;
	vector<int> counts(1000000);
	counts[1] = 0;
	for (int i = 2; i <= num; i++) {
		int _min = 1000000;
		if (i % 3 == 0) {
			_min = min(_min, counts[i / 3] + 1);
		}
		if (i % 2 == 0) {
			_min = min(_min, counts[i / 2] + 1);
		}
		_min = min(_min, counts[i - 1] + 1);

		counts[i] = _min;
	}
	cout << counts[num];
	return 0;
}