#include <iostream>
#include <string.h>
using namespace std;

class NSX {
private:
    char TenNSX[50];
    char DiaChi[100];
public:
    void Nhap();
    void Xuat();
};

void NSX::Nhap() {
    cout << "Nhap ten NSX: "; fflush(stdin); gets(TenNSX);
    cout << "Nhap dia chi NSX: "; fflush(stdin); gets(DiaChi);
}

void NSX::Xuat() {
    cout << "Ten NSX: " << TenNSX << endl;
    cout << "Dia chi NSX: " << DiaChi << endl;
}

class Date {
private:
    int D, M, Y;
public:
    void Nhap();
    void Xuat();
};

void Date::Nhap() {
    cout << "Nhap ngay: "; cin >> D;
    cout << "Nhap thang: "; cin >> M;
    cout << "Nhap nam: "; cin >> Y;
}

void Date::Xuat() {
    cout << "Ngay: " << D << "/" << M << "/" << Y << endl;
}

class Hang {
private:
    char TenHang[50];
    NSX x;
    float Dongia;
public:
    void Nhap();
    void Xuat();
    NSX& getNSX() { return x; }
};

void Hang::Nhap() {
    cout << "Nhap ten hang: "; fflush(stdin); gets(TenHang);
    x.Nhap();
    cout << "Nhap don gia: "; cin >> Dongia;
}

void Hang::Xuat() {
    cout << "Ten hang: " << TenHang << endl;
    x.Xuat();
    cout << "Don gia: " << Dongia << endl;
}

class Tivi {
private:
    float Kichthuoc;
    Date NgayNhap;
    Hang y;
public:
    void Nhap();
    void Xuat();
};

void Tivi::Nhap() {
    cout << "Nhap kich thuoc: "; cin >> Kichthuoc;
    NgayNhap.Nhap();
    y.Nhap();
}

void Tivi::Xuat() {
    cout << "Kich thuoc: " << Kichthuoc << endl;
    NgayNhap.Xuat();
    y.Xuat();
}

int main() {
    Tivi t;
    t.Nhap();
    cout << "\nThong tin Tivi vua nhap:\n";
    t.Xuat();
    return 0;
}

