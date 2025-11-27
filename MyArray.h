#ifndef MYARRAY_H
#define MYARRAY_H

class MyArray {
private:
    int* p;
    int N;
public:
    MyArray(int size = 0);
    MyArray(const MyArray& other);
    ~MyArray();
    MyArray merge(const MyArray& other);
    MyArray add(const MyArray& other);
    MyArray subtract(const MyArray& other);
    MyArray multiply(const MyArray& other);
    MyArray divide(const MyArray& other);
    int getSize() const;
    int getElement(int index) const;
    void setElement(int index, int value);
};

#endif