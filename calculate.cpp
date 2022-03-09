#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>

using namespace std;

// ����Ϊ�ַ�����ֻ�����򵥵����ֵļӼ����ţ����Ϊ����Ľ��
int calculate1(string s);

// ����Ϊ�ַ������������ֵļӼ��˳����ţ����Ϊ����Ľ��
int calculate2(string s);

// ����Ϊ�ַ������������ֵļӼ��˳����ţ����Ϊ����Ľ��
int calculate2(string s);

// ���ռ������ĸ�������
int helper(string s, int& pos);
// ����Ϊ�ַ������������ֵļӼ��˳������ŷ��ţ����Ϊ����Ľ��
int calculate3(string s);

int main() {
    string str1 = "1 + 1";
    string str2 = "2 -3 *4 +5";
    string str3 = "1*(2+3)";
    int ans1 = calculate1(str1);
    int ans2 = calculate2(str2);
    int ans3 = calculate3(str3);
    return 0;
}

int calculate1(string s) {
    stack<int> stk;
    int num = 0;
    char sign = '+';
    for (int i = 0; i < s.size(); ++i) {
        char ch = s[i];
        if (ch <= '9' && ch >= '0')
            num = 10 * num + (ch - '0');
        if (((ch > '9' || ch < '0') && ch != ' ') || i == s.size() - 1) {
            switch (sign) {
            case '+':
                stk.push(num);    
                break;  
            case '-':
                stk.push(-num);   
                break;
            }
            sign = ch;
            num = 0;
        }
    }
    int ans = 0;
    while (!stk.empty()) {
        ans += stk.top();
        stk.pop();
    }
    return ans;
}

int calculate2(string s) {
    stack<int> stk;
    int num = 0;
    char sign = '+';
    for (int i = 0; i < s.size(); ++i) {
        char ch = s[i];
        if (ch <= '9' && ch >= '0')
            num = 10 * num + (ch - '0');
        if (ch > '9' || ch < '0' || i == s.size() - 1){
            switch (sign) {
                int pre;
                case '+':
                    stk.push(num);    
                    break;  
                case '-':
                    stk.push(-num);   
                    break;
                case '*':
                    pre = stk.top();
                    stk.pop();
                    stk.push(pre * num);    
                    break;  
                case '/':
                    pre = stk.top();
                    stk.pop();
                    stk.push(pre / num);   
                    break;
            }
            sign = ch;
            num = 0;
        }
    }
    int ans = 0;
    while (!stk.empty()) {
        ans += stk.top();
        stk.pop();
    }
    return ans;
}

int calculate3(string s) {
    int pos = 0;
    return helper(s, pos);
}

int helper(string s, int& pos) {
    stack<int> stk;
    int num = 0;
    char sign = '+';
    for (; pos < s.size(); ++pos) {
        char ch = s[pos];
        if (ch == '(') {
            ++pos;
            num = helper(s, pos);
        }
        if (ch <= '9' && ch >= '0')
            num = 10 * num + (ch - '0');
        if (ch > '9' || ch < '0' || pos == s.size() - 1){
            switch (sign) {
                int pre;
                case '+':
                    stk.push(num);    
                    break;  
                case '-':
                    stk.push(-num);   
                    break;
                case '*':
                    pre = stk.top();
                    stk.pop();
                    stk.push(pre * num);    
                    break;  
                case '/':
                    pre = stk.top();
                    stk.pop();
                    stk.push(pre / num);   
                    break;
            }
            if (ch == ')')
                break;
            sign = ch;
            num = 0;
        }
    }
    int ans = 0;
    while (!stk.empty()) {
        ans += stk.top();
        stk.pop();
    }
    return ans;
}