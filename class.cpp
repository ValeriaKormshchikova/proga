#include <iostream>
using namespace std;

class vector {
	int size;
	std::string id;
	double* data;
	friend class matrix;
public:
	vector(int size, std::string id);
	~vector();
	void print();
	void set_data(double* data);
	friend vector operator + (vector a, vector b);
};

vector :: vector(int size, std::string id = "unknown"){
	this->size = size;
	this->id = id;

	data = new double [size];
	for (int i = 0; i<size; i++){
		data[i] = 0.01;
	}
};

vector :: ~vector() {
	delete[] data;
};

void vector :: print(){
	cout << size << std::endl;
	for (int i = 0; i<size; i++){
		cout << " " << data[i] << std::endl;
	}
};

void vector :: set_data(double* data){
	this->data = data;
};

vector vector::operator + (vector a, vector b){
	vector v(a.size);
	for (i = 0; i < a.size; i++){
		v.data[i] = a.data[i] + b.data[i];
	}
	return v;
};

class matrix{
	int nx, ny;
	std::string id;
	double** data;
public:
	matrix(int nx, int ny, std::string id);
	~matrix();
	void print();
 	void set_data(double** data);
};

matrix :: matrix(int nx, int ny, std::string id = "unknown"){
	this->nx = nx;
	this->ny = ny;
	this->id = id;

	data = new double* [nx];
	for (int i = 0; i<nx; i++){
		data[i] = new double[ny];
		for (int j = 0; j<ny; j++){
			data[i][j] = 0.01;
		}
	}
};

void matrix :: print(){
	cout << nx << ", " << ny << std::endl;
	for (int i = 0; i<nx; i++){
		for (int j = 0; i<ny; i++){
			cout << " " << data[i][j] << std::endl;
		}
	}
};

matrix :: ~matrix() {
	delete[] data;
};

void matrix :: set_data(double** data){
	this->data = data;
};

int main(){
	cout << "hello, cat!" << std::endl;
	int i, j, k, l, m, n;
	vector v(5, "first vector");
	vector u(7, "second vector");

	v.print();
	u.print();

	double* a = new double[5];
	for (i = 0; i<5; i++){
		a[i] = i*0.5;
	}
	v.set_data(a);

	v.print();

	return 0;
}
