#include <iostream>
using namespace std;

template <class T>
class Matrix {
private:
    int rows, cols;
    T data[100][100];
public:
    Matrix() { rows = cols = 0; }

    friend istream& operator>>(istream& in, Matrix<T>& m) {
        cout << "Nhap so hang, cot: ";
        in >> m.rows >> m.cols;
        cout << "Nhap ma tran:\n";
        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                in >> m.data[i][j];
            }
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, Matrix<T> m) {
        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                out << m.data[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }

    Matrix<T> transpose() {
        Matrix<T> temp;
        temp.rows = cols;
        temp.cols = rows;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                temp.data[j][i] = data[i][j];
            }
        }
        return temp;
    }
};

int main() {
    Matrix<double> md;
    cout << "Nhap ma tran so thuc:\n";
    cin >> md;
    cout << "Ma tran vua nhap:\n" << md;
    cout << "Ma tran chuyen vi:\n" << md.transpose();

    Matrix<long> ml;
    cout << "Nhap ma tran so nguyen:\n";
    cin >> ml;
    cout << "Ma tran vua nhap:\n" << ml;
    cout << "Ma tran chuyen vi:\n" << ml.transpose();

    return 0;
}

