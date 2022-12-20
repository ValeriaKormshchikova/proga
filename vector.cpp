using namespace std;
#include "vector.h"
#include "matrix.h"

//class vector;
class matrix;

vector :: vector (int v_size, std::string v_id = "unknown"){
    this->v_size = v_size;
    this->v_id = v_id;

    v_data = new double [v_size];
    for (int i = 0; i < v_size; i++){
        v_data[i]=0;
    };
};

void vector :: print(){
    cout << v_id << " size: " << v_size << std::endl;
    for (int i = 0; i < v_size; i++){
        cout << v_data[i] << std::endl;
    };
};

void vector :: set_data (int v_size, double* v_data){
    for (int i = 0; i < v_size; i++){
        this->v_data[i]=v_data[i];
    };
};

vector operator + (vector a, vector b){
    vector temp(a.v_size, "sum");
    for (int i=0; i < a.v_size; i++){
        temp.v_data[i] = a.v_data[i]+b.v_data[i];
    };
    return temp;
};


// vector multiply(matrix &m, vector v) {
//     vector temp(m.m_rows, "mult");
//     for (int i=0; i < m.m_rows; i++){
//         temp.v_data[i] = 0;
//         for (int j = 0; j < m.m_cols; j++){
//             temp.v_data[i] = temp.v_data[i] + m.m_data[i][j]*v.v_data[j];
//             };
//         };
//     return temp;
// };
