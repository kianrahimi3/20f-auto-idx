//
// Created by kianr on 9/17/2020.
//

#ifndef INC_20F_AUTO_IDX_DSVECTOR_H
#define INC_20F_AUTO_IDX_DSVECTOR_H

template<class T>

class DSVector {


public:
    DSVector();
    DSVector(const DSVector&);
    void push_back(const T& val);       //add at end of vector
//    void push(int data, int index); //add at any point of vector
    T& operator[] (int);

    void resize(int);

private:
    T *x;
    int cap;
    int length;
};

//constructor
template <class T>
DSVector<T>::DSVector() {
    length = 0;
    cap = 5;
    x = new T[cap];
}

template <class T>
DSVector<T>::DSVector(const DSVector&) {
    length = this->length;
    cap = this->length;
    x = this->x;
}

template <class T>
void DSVector<T>::push_back(const T &val) {
    x[length] = val;
    length++;
}

template <class T>
T& DSVector<T>::operator[](int val) {
    return x[val];
}

template <class T>
void DSVector<T>::resize(int size) {
    int *temp = new int[size];

    for(int i = 0; i < size; i++) {
        temp[i] = x[i];
    }
    delete[] x;
    cap = size;
    x = temp;
}

#endif //INC_20F_AUTO_IDX_DSVECTOR_H
