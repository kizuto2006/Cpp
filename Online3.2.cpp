#include <iostream>
using namespace std;

class TamGiac {
private:
    double a, b, c;
public:
    TamGiac() { a = b = c = 0; }

    friend istream& operator>>(istream& in, TamGiac& tg) {
        cout << "Nhap 3 canh tam giac: ";
        in >> tg.a >> tg.b >> tg.c;
        return in;
    }

    friend ostream& operator<<(ostream& out, TamGiac tg) {
        double chuvi = tg.a + tg.b + tg.c;
        out << "Ba canh tam giac: " << tg.a << " " << tg.b << " " << tg.c << endl;
        out << "Chu vi tam giac: " << chuvi << endl;
        return out;
    }

    operator double() {
        return a + b + c;
    }
};

int main() {
    TamGiac P, Q;
    cout << "Nhap tam giac P:\n";
    cin >> P;
    cout << "Nhap tam giac Q:\n";
    cin >> Q;

    cout << "Thong tin tam giac P:\n" << P;
    cout << "Thong tin tam giac Q:\n" << Q;

    cout << "Chu vi tam giac P: " << (double)P << endl;
    cout << "Chu vi tam giac Q: " << (double)Q << endl;

    return 0;
}

