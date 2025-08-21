#include <iostream>
using namespace std;

class Mang {
private:
    int n;
    float VALUE[100];
public:
    Mang() { n = 0; }

    friend istream& operator>>(istream& in, Mang& m) {
        cout << "Nhap kich thuoc mang: ";
        in >> m.n;
        cout << "Nhap " << m.n << " gia tri:\n";
        for (int i = 0; i < m.n; i++)
            in >> m.VALUE[i];
        return in;
    }

    friend ostream& operator<<(ostream& os, Mang m) {
        for (int i = 0; i < m.n; i++)
            os << m.VALUE[i] << " ";
        os << endl;
        return os;
    }

    Mang& operator++() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (VALUE[i] > VALUE[j]) {
                    float temp = VALUE[i];
                    VALUE[i] = VALUE[j];
                    VALUE[j] = temp;
                }
            }
        }
        return *this;
    }

    Mang& operator--() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (VALUE[i] < VALUE[j]) {
                    float temp = VALUE[i];
                    VALUE[i] = VALUE[j];
                    VALUE[j] = temp;
                }
            }
        }
        return *this;
    }
};

int main() {
    Mang m;
    cin >> m;
    ++m;
    cout << "Mang sau khi sap xep tang dan: ";
    cout << m;
    --m;
    cout << "Mang sau khi sap xep giam dan: ";
    cout << m;
    return 0;
}

