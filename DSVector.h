//
// Created by kianr on 9/17/2020.
//

#ifndef INC_20F_AUTO_IDX_DSVECTOR_H
#define INC_20F_AUTO_IDX_DSVECTOR_H

#include <iostream>
using namespace std;

template<class T>

class DSVector {


public:
    DSVector<T>() {
        length = 0;
        cap = 10;
        x = new T[cap];
    };
    DSVector(const DSVector& vec) {
        length = vec.length;
        cap = vec.cap;

        x = new T[cap];

        for(int i = 0; i < length; i++) {
            x[i] = vec.x[i];
        }
    };
    ~DSVector() {
        delete [] x;
    }

    void friend swap(DSVector& first, DSVector& second) {
        swap(first.length, second.length);
        swap(first.cap, second.cap);
        swap(first.x, second.x);
    }




    DSVector<T>& operator=(DSVector<T> & vec) {
        swap(*this, vec);

        return *this;
    };

    bool operator==(const DSVector<T> &vec) {
        if(size() != vec.size()) {
            return false;
        }
        for(int i = 0; i < size(); i++) {
            if(x[i] != vec.x[i])
                return false;
        }
        return true;
    }

    bool operator!=(const DSVector<T> &vec) {
        return !(*this == vec);
    }

    friend ostream& operator<<(ostream& out, const DSVector& output) {
        //out << "<";

        for(int i = 0; i < output.length; i++) {
            out << output.x[i] << " ";
        }
        //  out << ">" << endl;

        return out;
    }

    void add(T& input, int index) {
        if(index >= length || index < 0)
            //return nothing
            return;
        if(length == 1)
            length = 0;
        else {
            for(int i = 0; i < length - 1; i++)
                x[i] = x[i+1];
        }
    };
    void push_back(T val);       //add at end of vector

    T& operator[] (int index);

    void resize() {
        cap = cap * 2;
        T* temp = new T[cap];

        for(int i = 0; i < length; i++) {
            temp[i] = x[i];
        }
        delete [] x;
        x = temp;
    };
    int size() {
        return length;
    };




private:
    T *x;
    int cap;
    int length;

};

template <class T>
void DSVector<T>::push_back(T val) {
    if(length == cap)
        resize();
    x[length] = val;
    length++;
}

template <class T>
T& DSVector<T>::operator[](int index) {
    if(index >= length) {
        cout << "Error: Array index out of bounds" << endl;
        exit(0);
    }
    //error handling == try and catch

    return x[index];
}
/*
///work with resize
template <class T>
void DSVector<T>::resize() {
    int size = length;
    T *temp = new T[size * 2];

    for(int i = 0; i < size; i++) {
        temp[i] = x[i];
    }
    delete[] x;
    cap = size * 2;
    x = temp;
   // length = size + 1;
}

template <class T>
int DSVector<T>::size() {
    return length;
}
*/

#endif //INC_20F_AUTO_IDX_DSVECTOR_H
