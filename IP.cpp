#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

unsigned int Ip_Int (string str);
vector<int> split (string str, char ch);
void print (unsigned int n);

int main() {
	string str = "255.255.255.0";
	unsigned int Ip = Ip_Int(str);
	print(Ip);
	return 0;
};

unsigned int Ip_Int (string str) {
	vector<int> nums;
	nums = split(str, '.');
	unsigned int Ip = 0;
	for (int i = 0; i < 4; ++i) {
		int num = nums[i];
		Ip += num << (24 - i * 8);
	}
	return Ip;
}

vector<int> split (string str, char ch) {
	vector<int> nums;
	string tmp;
	for (auto& c : str) {
		if (c == ch) {
			nums.emplace_back(stoi(tmp));
			tmp = "";
		}
		else
			tmp.push_back(c);
	}
	nums.emplace_back(stoi(tmp));
	return nums;
}

void print (unsigned int n) {
	for (int i = 31; i >= 0; --i) {
		if (n & (1 << i))
			cout << 1;
		else
			cout << 0;
		if (i % 8 == 0)
			cout << ' ';
	}
}