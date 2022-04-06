// #include <bits/stdc++.h>
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRU{
private:
	list<pair<int, int>> ls;
	unordered_map<int, list<pair<int, int>> :: iterator> mp;
	int capacity;
public:	
	LRU(int val) {
		capacity = val;
	}

	int get(int key) {
		if (!mp.count(key))
			return -1;
		
		auto it = mp[key];
		int val = it -> second;
		ls.erase(it);
		mp.erase(key);
		ls.emplace_front(key, val);
		mp[key] = ls.begin();
		return val;
	}

	void put(int key, int val) {
		if (mp.count(key)) {
			ls.erase(mp[key]);
			mp.erase(key);
		}
		if (capacity == ls.size()) {
			mp.erase(ls.back().first);
			ls.pop_back();
		}
		ls.emplace_front(key, val);
		mp[key] = ls.begin();
	}
};

int main() {
	LRU *a = new LRU(5);
	return 0;
};
