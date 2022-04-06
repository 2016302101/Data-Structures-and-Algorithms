// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

// template <typename T>
class MAXPQ{
private:
	vector<int> nums;
	int capacity;
	int size;

	void exch(int i, int j) {
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}

	void swim(int k) {
		while (parent(k) <= 1 && less(parent(k), k)) {
			exch(parent(k), k);
			k = parent(k);
		}
	}

	void sink(int k) {
		while (left(k) <= capacity) {
			int next = left(k);
			if (right(k) <= capacity && less(left(k), right(k)))
				next = right(k);
			if (less(next, k))
				break;
			k = next;
		}
	}

	bool less(int i, int j) {
		return nums[i] < nums[j];
	}

	int left(int k) {
		return k << 1;
	}

	int right(int k) {
		return k << 1 + 1;
	}

	int parent(int k) {
		return k >> 1;
	}
public:	
	MAXPQ(int cap = 10) {
		capacity = cap;
		size = 0;
		nums = vector<int> (cap + 1);
	}

	void push(int num) {
		++size;
		nums[size] = num;
		swim(size);
	}

	void pop() {
		exch(1, size);
		sink(1);
		nums[size] = 0;
		--size;
	}

	int top() {
		return nums[1];
	}

	bool empty() {
		return size == 0;
	}
};

int main() {
	
	return 0;
};
