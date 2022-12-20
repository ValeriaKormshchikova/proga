using namespace std;
#include "mat.h"

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

matrix :: matrix (int m_rows, int m_cols, std::string m_id = "unknown"){

    this->m_rows = m_rows;
    this->m_cols = m_cols;
    this->m_id = m_id;

    m_data = new double* [m_rows];
    for (int i = 0; i < m_rows; i++){
        m_data[i] = new double[m_cols];
        for (int j = 0; j < m_cols; j++){
            m_data[i][j] = 0;
        };

    };
};

void matrix :: print (){
    cout << m_id << " size: " << m_rows << " x " << m_cols << std::endl;
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_cols; j++) {
            cout << m_data[i][j] << " ";
        };
        cout << endl;
    };

};

void matrix :: set_data(int m_rows, int m_cols, double** m_data){

    for (int i = 0; i < m_rows; i++){
        for (int j = 0; j < m_cols; j++){
            this->m_data[i][j] = m_data[i][j];
        };

    };
};

vector multiply(matrix &m, vector v) {
    vector temp(m.m_rows, "mult");
    for (int i=0; i < m.m_rows; i++){
        temp.v_data[i] = 0;
        for (int j = 0; j < m.m_cols; j++){
            temp.v_data[i] = temp.v_data[i] + m.m_data[i][j]*v.v_data[j];
            };
        };
    return temp;
};
