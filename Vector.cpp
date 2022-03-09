/**
 * 建立一个简单的vector模板类
 * gl 2021.6.13
 */
#include<iostream>
#include<vector>
#include<cstring>
#include<array>
#include<algorithm> 

using namespace std;
template<typename T>//模板类
class vectorList{
private:
    T* my_array; //定义一个数组
    int size; //数组的当前长度
    int capacity; //数组的容量
public:
    vectorList(): capacity(0), size(0){ cout << "use default constructor" << endl; }//构造函数,如果没有定义构造函数，会默认构建一个构造函数
    vectorList(int n){
        cout << "use parameters constructor" << endl;
        my_array = new T[n];
        capacity = n;
        size = n;
    }//含参数构造函数，如果定义了构造函数，就必须赋值，否则报错，如果想使用默认构造函数，必须写一个
    vectorList(const vectorList<T>& obj){
        cout << "use copy constructor" << endl;
        size = obj.Size();
        capacity = obj.Capacity();
        my_array = new T[capacity];
        for(int k = 0; k < size; ++k) my_array[k] = obj[k]; 
    }//拷贝构造函数。如果没有构建copy构造函数，会默认构建一个。注意这个const，如果对象定义为const对象，该对象只能访问被const修饰的成员（包括const变量和const成员函数）因为非 const 成员可能会修改对象的数据（编译器也会这样假设），C++禁止这样做
    
    vectorList<T>& operator=(const vectorList<T>& obj){
        cout << "use copy givenum" << endl;
        vectorList<T> clone = obj;
        swap(*this, clone);
        return *this;
    }//拷贝赋值函数,对已经存在的对象进行拷贝赋值,深拷贝

    vectorList(vectorList<T>&& obj){
        cout << "use move constructor" << endl;
        size = obj.Size();
        obj.size = 0;
        capacity = obj.Capacity();
        obj.capacity = 0;
        my_array = obj.my_array;
        obj.my_array = nullptr;
    }//移动构造函数，将右值引用赋值给this

    vectorList<T>& operator=(vectorList<T>&& obj){
        cout << "use move givenum" << endl;
        swap(*this, obj);
        return *this;
    }//移动赋值函数

    ~vectorList(){
        delete [] my_array;
        cout << "delete space" << endl;
    }//析构函数
    T& operator[](int index) const{
        return my_array[index];
    }//运算符重载，实现索引获得元素
    // void reserve(int newcapacity){
    //     if(newcapacity <= capacity) return;
    //     T* newarray = new T[newcapacity]; 
    //     for(int k = 0; k < capacity; ++i)
    //         newarray[k] = array[k];
    //     capacity = newcapacity;
    //     swap(newarray, array);
    //     delete [] newarray;
    // }//扩容该容器
    // void resize(int newsize){
    //     if(newsize > capacity) reverse(2 * newsize);
    //     size = newsize;
    // } 
    friend void swap(vectorList<T>& lhs, vectorList<T>& rhs) {
        swap(lhs.size, rhs.size);
        swap(lhs.capacity, rhs.capacity);
        swap(lhs.my_array, rhs.my_array);
    }
    bool empty() const{
        return size == 0;
    }
    int Size() const{
        return size;
    }
    int Capacity() const{
        return capacity;
    }

};

int main(){
    vectorList<int> a(5);
    vectorList<int> b ;
    
    // b = a;
    // swap(a, b);
    // cout<<a.empty()<<' '<<a.Size()<<endl;
    // cout<<b.empty()<<' '<<b.Size()<<endl;
    
    return 0;

};

