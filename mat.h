using namespace std;
#ifndef MAT_H
#define MAT_H

class vector;
class matrix;

class matrix {
    friend class vector;
    friend vector multiply(matrix &m, vector v);
    int m_rows;
    int m_cols;
    std::string m_id;
    double** m_data;
public:
    matrix(int m_rows, int m_cols, std::string m_id);
    void print();
    void set_data(int m_rows, int m_cols, double** m_data);
};
