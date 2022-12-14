using namespace std;
using namespace std;

#include "vector.h"
#include "matrix.h"
#include <iostream>

class vector;
class matrix;


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

vector solver(matrix &a, vector b) {
    matrix alpha(a.m_rows, a.m_cols, "1");
    for (int i = 0; i < a.m_rows; i++){
        for (int j = 0; j < a.m_cols; j++){
            if (i != j){
                alpha.m_data[i][j] = a.m_data[i][j]/a.m_data[i][i];
            }
            else {
                alpha.m_data[i][j] = a.m_data[i][j];
            };
        };
    };
    vector beta(b.v_size, "1");
    for (int i = 0; i < b.v_size; i++){
        beta.v_data[i] = b.v_data[i]/a.m_data[i][i];
    };
    vector x(b.v_size, "2");
    for (int i = 0; i<100; i++){
        x = beta + multiply(alpha, x);
        x.print();
    };
    return x;
}


int main(){
    cout << "Hello world!" << endl;
    vector v1(5, "first vector!");
    matrix m1(3, 5, "first matrix!");
    double data1d[] = {1,2,3,4,5};
    v1.set_data(5, data1d);
    v1.print();

    double** data2d;
    data2d = new double* [3];
    for (int i=0; i<3; i++){
        data2d[i] = new double[5];
        for (int j=0; j<5; j++){
            data2d[i][j]=i;
        };
    };
    m1.set_data(3, 5, data2d);
    m1.print();

    cout << "lets sum v1 + v1. ";
    vector v2 = v1 + v1;
    v2.print();

    cout << "lets multiply m1 * v1. ";
    vector v3 = multiply(m1, v1);
    v3.print();

    double data_1d[] = {1, 2, 3};
    double** data_2d;
    data2d = new double* [3];
    for (int i=0; i<3; i++){
        data2d[i] = new double[3];
        for (int j=0; j<3; j++){
            if (i < j){
                data2d[i][j]=0;
            }
            else{ data2d[i][j]=i+j;}
        };
    };

    vector x(3, "mao");
    vector b(3, "gao");
    b.set_data(3, data_1d);
    matrix a(3, 3, "ma");
    a.set_data(3, 3, data_2d);
    x = solver(a, b);

    cout << "Bye world!" << endl;
    return 0;
};
