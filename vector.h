using namespace std;

#include <iostream>
#ifndef VECTOR_H
#define VECTOR_H


class matrix;
class vector {
    friend class matrix;
    friend vector operator + (vector a, vector b);
    friend vector multiply(matrix &m, vector v);
    friend vector solver(matrix &a, vector b);
    int v_size;
    std::string v_id;
    double* v_data;
public:
    vector(int v_size, std::string v_id);
    void print();
    void set_data(int v_size, double* v_data);
};
#endif
