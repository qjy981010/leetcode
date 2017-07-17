#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//优先队列实现，超过27%
class MedianFinder {
public:
	priority_queue<int> maxheap;
	priority_queue< int, vector<int>, greater<int> > minheap;

	MedianFinder(){};
	
	void addNum(int num) {
		if (maxheap.empty() || num <= maxheap.top()) {
			maxheap.push(num);
		}
		else {
			minheap.push(num);
		}
		if (minheap.size() > maxheap.size()) {
			maxheap.push(minheap.top());
			minheap.pop();
		}
		if (maxheap.size() - minheap.size() > 1) {
			minheap.push(maxheap.top());
			maxheap.pop();
		}
	}

	double findMedian() {
		if (maxheap.size() == minheap.size()) {
			return (maxheap.top() + minheap.top()) / 2.0;
		}
		else return (double)maxheap.top();
	}
};


/*BST实现，将每个节点左右两边的节点数记下，方便查找，击败16%
class MedianFinder {
public:
	struct node {
		node* left = nullptr;
		node* right = nullptr;
		int val;
		int leftnum = 0;
		int rightnum = 0;
		node(int num) {val = num;}
	};
	node* root;
	int size = 0;

	MedianFinder() {}

	void addNum(int num) {
		if (!size) root = new node(num);
		else {
			node* it = root;
			for (;;) {
				if (num > it->val) {
					it->rightnum++;
					if (it->right) it = it->right;
					else {
						it->right = new node(num);
						break;
					}
				}
				else {
					it->leftnum++;
					if (it->left) it = it->left;
					else {
						it->left = new node(num);
						break;
					}
				}
			}
		}
		++size;
	}

	double findMedian() {
		int n = size >> 1;
		int j = size & 1;
		int smaller = 0;
		node* parent;
		for (node* it = root; ;) {
			if (it->leftnum + smaller > n) {
				parent = it;
				it = it->left;
			}
			else if (it->leftnum + smaller < n) {
				smaller += it->leftnum + 1;
				parent = it;
				it = it->right;
			}
			else {
				if (j) return (double)it->val;
				else if (it->left) {
					node* tempit = it->left;
					while (tempit->right) tempit = tempit->right;
					return (tempit->val + it->val) / 2.0;
				}
				else return (parent->val + it->val) / 2.0;
			}

			if (smaller == n) {
				while (it->left) it = it->left;
				if (j) return it->val;
				return (it->val + parent->val) / 2.0;
			}
		}
	}
};
*/

/*排序后取中位数，超时
class MedianFinder {
public:
	vector<int> v;
	int size = 0;

	MedianFinder() {}
    
    void addNum(int num) {
		int begin = 0, end = size - 1, target;
		if (!size) {
			v.push_back(num);
			++size;
			return;
		}
		if (v[begin] >= num) {
			v.insert(v.begin(), num);
			++size;
			return;
		}
		while (end - begin > 1) {
			if (v[(end+begin)>>1] > num) {
				end = (end+begin)>>1;
			}
			else if (v[(end+begin)>>1] < num) {
				begin = (end+begin)>>1;
			}
			else {
				target = (end+begin)>>1;
			}
		}
		target = num < v[end] ? begin : end;
		v.push_back(*v.begin());
		for (int i = size - 2; i > target; --i) {
			v[i+1] = v[i];
		}
		v[target+1] = num;
		++size;
    }
    
    double findMedian() {
		if (size & 1) return (double)v[size >> 1];
		else return (v[size>>1] + v[(size>>1)-1]) / 2.0;
    }
};
*/

int main() {
	MedianFinder* obj = new MedianFinder();
	(*obj).addNum(6);
	(*obj).addNum(10);
	(*obj).addNum(2);
	(*obj).addNum(6);
	cout << (*obj).findMedian() << endl;
	(*obj).addNum(5);
	cout << (*obj).findMedian() << endl;
	(*obj).addNum(0);
	cout << (*obj).findMedian() << endl;
	(*obj).addNum(6);
	cout << (*obj).findMedian() << endl;
	(*obj).addNum(3);
	cout << (*obj).findMedian() << endl;
	(*obj).addNum(1);
	cout << (*obj).findMedian() << endl;
	(*obj).addNum(0);
	cout << (*obj).findMedian() << endl;
	(*obj).addNum(0);
	cout << (*obj).findMedian() << endl;
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
