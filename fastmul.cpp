#include <iostream>
#include <vector>
using namespace std;

//�õݹ��˼��ʵ�ֿ������
long mul_1(int x, int y){
    if(y == 0) return 0;
    long ans = 0;
    if((y & 1) == 1) ans += x;
    return ans + mul_1(x + x, y >> 1);
}

//�õ�����˼��ʵ�ֿ������ �;�������ݵ�˼������
long mul_2(int x, int y){
    long ans = 0;
    while(y){
        if((y & 1) == 1) ans += x;
        y >>= 1;
        x += x;
    }
    return ans;
}

//�����������
vector<vector<int>> mul_matrix(vector<vector<int>>& a, vector<vector<int>>& b){
    int raw_a = a.size();
    int col_a = a[0].size();
    int raw_b = b.size();
    int col_b = b[0].size();
    if(col_a != raw_b){
        cout<<"���������޷����"; 
        return {};
    }
    vector<vector<int>> ans(raw_a, vector<int>(col_b));
    for(int i = 0; i < raw_a; ++i)
        for(int j = 0; j < col_b; ++j)
            for(int k = 0; k < col_a; ++k){
                ans[i][j] += a[i][k] * b[k][j];
            }
    return ans;
}

//�õ�����˼��ʵ�־��������
vector<vector<int>> mul_3(vector<vector<int>>& a, int k){
    if(k == 1) return a;
    int m = a.size();
    vector<vector<int>> ans(m, vector<int>(m));
    for(int i = 0; i < m; ++i) ans[i][i] = 1; 
    if((k & 1) == 1) ans = a;
    vector<vector<int>> tmp = mul_3(a, k - 1);
    return mul_matrix(ans, tmp);
}

//�õ����ķ���ʵ�־��������
vector<vector<int>> mul_4(vector<vector<int>>& a, int k){
    int m = a.size();
    vector<vector<int>> ans(m, vector<int>(m));
    for(int i = 0; i < m; ++i) ans[i][i] = 1; 
    while(k){
        if((k & 1) == 1) ans = mul_matrix(ans, a);
        k >>= 1;
        a = mul_matrix(a, a);
    }
    return ans;
}  

int main(){
    int num1 = mul_1(3, 4);
    int num2 = mul_2(3, 4);
    vector<vector<int>> a = {{1, 1}, {1, 1}};
    vector<vector<int>> b = mul_matrix(a, a);
    vector<vector<int>> c = mul_3(a, 2);
    vector<vector<int>> d = mul_4(a, 2);
    return 0;
};