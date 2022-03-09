//构建一个matrix模板类，利用行主次序把矩阵映射到一维数组中
#include<iostream>

using namespace std;

template<class T>
class matrix{
public:
    matrix(){
        cout << "use default constructor" << endl;
        raw = 0, col = 0;
    }//默认的构造函数
    matrix(int raw, int col){
        cout << "use parameters constructor" << endl;
        if(raw < 0 || col < 0) cout<< "the matrix is not ok" << endl;
        this -> raw = raw;
        this -> col = col;
        element = new T[raw * col];
    }//含参数的构造函数
    matrix(const matrix<T>& obj){
        cout << "use copy constructor" << endl;
        raw = obj.raw;
        col = obj.col;
        element = new T[raw * col];
        copy(obj.element, obj.element + raw*col, element);
    }//拷贝构造函数
    matrix<T>& operator=(const matrix<T>& obj){
        cout << "use copy givenum" << endl;
        delete [] element;
        raw = obj.raw;
        col = obj.col;
        element = new T[raw * col];
        copy(obj.element, obj.element + raw*col, element);
        return *this;
    }//拷贝赋值函数
    T& operator()(int i, int j) const{
        return element[i*raw + j];
    }//拷贝赋值函数
    ~matrix(){
        delete [] element;
    }

    int getraw(){
        return raw;
    }
    int getcol(){
        return col;
    }
private:
    int raw, col;
    T* element;
};
int main(){
    matrix<int> a;
    matrix<int> b(2,2);
    matrix<int> c = b;
    matrix<int> d(3,3);
    d = b;
    cout<<d(1,1);
    return 0;
}