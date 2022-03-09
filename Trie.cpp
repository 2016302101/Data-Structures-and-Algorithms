#include <iostream>
#include <vector>
#include <string>

using namespace std;
int aa = 0;
//实现前缀树Trie类
class Trie {
    vector<Trie*> next; //记录该节点的下一个情况
    bool isEnd; //记录该点是否为最后一个点
public:
    Trie(){
        next = vector<Trie*>(26, nullptr);
        isEnd = 0;
    } //初始化前缀树

    void insert(string word){
        Trie* node = this;
        for(char& ch: word){
            int u = ch - 'a';
            if(node -> next[u] == nullptr) node -> next[u] = new Trie();
            node = node -> next[u];
        }
        node -> isEnd = 1;
    } //向前缀树中插入数据

    bool search(string word){
        Trie* node = this;
        for(char& ch: word){
            int u = ch - 'a';
            if(node -> next[u] == nullptr) return 0;
            node = node -> next[u];
        }      
        return node -> isEnd; 
    } //判断该字符串集合中是否存在该字符串

    bool startsWith(string word){
        Trie* node = this;
        for(char& ch: word){
            int u = ch - 'a';
            if(node -> next[u] == nullptr) return 0;
            node = node -> next[u];
        }      
        return 1; 
    }
};

int main(){
    Trie* test = new Trie();
    test->insert("apple");
    cout<< test -> search("apple") <<endl;
    cout<< test -> search("app") <<endl;
    cout<< test -> startsWith("app") <<endl;
    test->insert("app");
    cout<< test -> search("app") <<endl;
    return 0;
}