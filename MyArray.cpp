#include "MyArray.h"
#include <cstring>

MyArray::MyArray(int size) : N(size) {
    p = (size > 0) ? new int[size]() : nullptr;
}

MyArray::MyArray(const MyArray& other) : N(other.N) {
    p = (N > 0) ? new int[N]() : nullptr;
    if (p && other.p) {
        memcpy(p, other.p, N * sizeof(int));
    }
}

MyArray::~MyArray() {
    delete[] p;
    p = nullptr;
    N = 0;
}

MyArray MyArray::merge(const MyArray& other) {
    MyArray res(N + other.N);
    if (p) memcpy(res.p, p, N * sizeof(int));
    if (other.p) memcpy(res.p + N, other.p, other.N * sizeof(int));
    return res;
}

MyArray MyArray::add(const MyArray& other) {
    int minSize = (N < other.N) ? N : other.N;
    MyArray res(minSize);
    for (int i = 0; i < minSize; ++i) {
        res.p[i] = p[i] + other.p[i];
    }
    return res;
}

MyArray MyArray::subtract(const MyArray& other) {
    int minSize = (N < other.N) ? N : other.N;
    MyArray res(minSize);
    for (int i = 0; i < minSize; ++i) {
        res.p[i] = p[i] - other.p[i];
    }
    return res;
}

MyArray MyArray::multiply(const MyArray& other) {
    int minSize = (N < other.N) ? N : other.N;
    MyArray res(minSize);
    for (int i = 0; i < minSize; ++i) {
        res.p[i] = p[i] * other.p[i];
    }
    return res;
}

MyArray MyArray::divide(const MyArray& other) {
    int minSize = (N < other.N) ? N : other.N;
    MyArray res(minSize);
    for (int i = 0; i < minSize; ++i) {
        res.p[i] = (other.p[i] != 0) ? (p[i] / other.p[i]) : 0;
    }
    return res;
}

int MyArray::getSize() const {
    return N;
}

int MyArray::getElement(int index) const {
    return (index >= 0 && index < N) ? p[index] : 0;
}

void MyArray::setElement(int index, int value) {
    if (index >= 0 && index < N && p) {
        p[index] = value;
    }
}