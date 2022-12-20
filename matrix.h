using namespace std;

#include <iostream>
#ifndef MATRIX_H
#define MATRIX_H

class vector;
//class matrix;

class matrix {
    friend class vector;
    friend vector multiply(matrix &m, vector v);
    friend vector solver(matrix &a, vector b);
    int m_rows;
    int m_cols;
    std::string m_id;
    double** m_data;
public:
    matrix(int m_rows, int m_cols, std::string m_id);
    void print();
    void set_data(int m_rows, int m_cols, double** m_data);
};
#endif
