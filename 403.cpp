// Frog Jump
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solutionbad1 {
public:
	int size;
	unordered_map<int, int> mymap;

	bool canCross(vector<int>& stones) {
		size = stones.size();
		for (int i = 1; i < size; ++i) {
			mymap.insert(pair<int, int>(stones[i], i));
		}
		return frogCross(0, 0, stones);
	}

	bool frogCross(int pos, int step, vector<int>& stones) {
		if (pos == size - 1) return true;
		int canreach = stones[pos] + step;
		unordered_map<int, int>::iterator i;
		if ((i = mymap.find(canreach + 1)) != mymap.end()) {
			if (frogCross(i->second, step + 1, stones)) return true;
		}
		if ((i = mymap.find(canreach)) != mymap.end()) {
			if (frogCross(i->second, step, stones)) return true;
		}
		if ((i = mymap.find(canreach - 1)) != mymap.end() && step > 1) {
			if (frogCross(i->second, step - 1, stones)) return true;
		}
		return false;
	}
};


class Solutionbad0 {
public:
	int size;

	bool canCross(vector<int>& stones) {
		size = stones.size();
		return frogCross(0, 0, stones);
	}

	bool frogCross(int pos, int step, vector<int>& stones) {
		if (pos == size - 1) return true;
		int canreach = stones[pos] + step;
		for (int i = pos + 1; i < size; ++i) {
			if (stones[i] < canreach - 1) continue;
			if (stones[i] > canreach + 1) break;
			if (stones[i] == canreach + 1) {
				if (frogCross(i, step + 1, stones)) return true;
			}
			else if (stones[i] == canreach) {
				if (frogCross(i, step, stones)) return true;
			}
			else if (stones[i] == canreach - 1 && step > 1) {
				if (frogCross(i, step - 1, stones)) return true;
			}
		}
		return false;
	}
};

class Solution {
public:
	int size;

	bool canCross(vector<int>& stones) {
		size = stones.size();
		return frogCross(0, 0, stones);
	}

	bool frogCross(int pos, int step, vector<int>& stones) {
		if (pos == size - 1) return true;
		int canreach = stones[pos] + step;
		for (int i = min(pos + step + 1, size - 1); i > pos; --i) {
			if (stones[i] < canreach - 1) break;
			if (stones[i] > canreach + 1) continue;
			if (stones[i] == canreach + 1) {
				if (frogCross(i, step + 1, stones)) return true;
			}
			else if (stones[i] == canreach) {
				if (frogCross(i, step, stones)) return true;
			}
			else if (stones[i] == canreach - 1 && step > 1) {
				if (frogCross(i, step - 1, stones)) return true;
			}
		}
		return false;
	}
};


int main() {
	Solution solve;
	vector<int> stones = {0,1,3,6,7,10};
	cout << solve.canCross(stones) << endl;
}
