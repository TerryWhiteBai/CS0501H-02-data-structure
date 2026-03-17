#ifndef _myvector_h
#define _myvector_h
#include <utility>

template<typename T>
class Vector{
    private:
    int _size;
    int _capcity;
    T* _data;
    void expand();

    public:
    Vector(int c = 3):_size(0), _capcity(c){
        _data = new T[_capcity];
    };
    
    
    Vector(const Vector& other):_size(other._size), _capcity(other._capcity){
        _data = new T[_capcity];
        for(int i = 0; i < _size; ++i){
            _data[i] = other._data[i];
        }
    }
    
    Vector& operator=(const Vector& other){
        if(this != &other){
            delete [] _data;
            _size = other._size;
            _capcity = other._capcity;
            _data = new T[_capcity];
            for(int i = 0; i < _size; ++i){
                _data[i] = other._data[i];
            }
        }
        return *this;
    }

    int size(){return _size;};

    void reverse(){
        for(int i = 0; i<=_size/2; ++i){
            std::swap(_data[i],_data[_size-1-i]);
        }
    };
    
    T& operator[](int i){return _data[i];};
    void print();
    void insert(int i, T v);
    void append(T v);
    void del(int i);
    int find_val(T v);
    ~Vector(){delete [] _data;};


};


template <typename T>
void Vector<T>::print(){
    std::cout<< "[";
    for (int i = 0; i < _size; ++i) {
        if(i != 0 ) std::cout<< ',';
        std::cout << _data[i];
    }
    std::cout << "]\n";
}

template <typename T> void Vector<T>::expand(){
    if(_size < _capcity) return;
    T* olddata = _data;
    T* newdata = new T[_capcity *= 2];
    for(int i = 0; i < _size; ++i){
        newdata[i] = olddata[i];
    }
    _data = newdata;
    delete [] olddata;
}

template <typename T> void Vector<T>::insert(int i, T v){
    if(i<0 || i>_size) return;
    if(_size == _capcity) expand();
    for(int s = _size; s > i; --s){
        _data[s] =  _data[s-1];
    }
    _data[i] = v; ++_size;
}

template <typename T> void Vector<T>::append(T v){
    insert(_size, v);
}

template <typename T> void Vector<T>::del(int i){
    if(i<0 || i>=_size) return;
    for(int index = i; index < _size-1; ++index){
        _data[index] = _data[index+1];
    }
    --_size;
}

template <typename T> int Vector<T>::find_val(T v){
    int result = -1;
    for(int i = 0; i < _size; ++i){
        if(_data[i] == v){result = i; break;}
    }
    return result;
}

#endif