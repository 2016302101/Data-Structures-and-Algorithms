#include <iostream>
#include <vector>
#include <string>

using namespace std;
int aa = 0;
//ʵ��ǰ׺��Trie��
class Trie {
    vector<Trie*> next; //��¼�ýڵ����һ�����
    bool isEnd; //��¼�õ��Ƿ�Ϊ���һ����
public:
    Trie(){
        next = vector<Trie*>(26, nullptr);
        isEnd = 0;
    } //��ʼ��ǰ׺��

    void insert(string word){
        Trie* node = this;
        for(char& ch: word){
            int u = ch - 'a';
            if(node -> next[u] == nullptr) node -> next[u] = new Trie();
            node = node -> next[u];
        }
        node -> isEnd = 1;
    } //��ǰ׺���в�������

    bool search(string word){
        Trie* node = this;
        for(char& ch: word){
            int u = ch - 'a';
            if(node -> next[u] == nullptr) return 0;
            node = node -> next[u];
        }      
        return node -> isEnd; 
    } //�жϸ��ַ����������Ƿ���ڸ��ַ���

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