#include <iostream>
using namespace std;

class vector {
	int size;
	std::string id;
	double* data;
public:
	vector(int size2, std::string id);
	void print();
};

vector :: vector(int size, std::string id = "unknown"){
	this->size = size;
	this->id = id;

	data = new double [size];
	for (int i = 0; i<size; i++){
		data[i] = 0.01;
	}

}
void vector :: print(){
	cout << size << std::endl;
	for (int i = 0; i<size; i++){
		cout << " " << data[i] << std::endl;
	}
}

int main(){
	cout << "hello, cat!" << std::endl;
	int i, j, k, l, m, n;
	vector v(5, "first vector");
	vector u(7, "second vector");

	v.print();
	u.print();

	return 0;
}
