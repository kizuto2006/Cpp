#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

class HANG {
private:
    char MaHang[10];
    char TenHang[100];
    int DonGia;

public:
    void NHAP();
    void XUAT();
    friend class PHIEU;
};

class PHIEU {
private:
    char MaPhieu[30];
    HANG x[100];
    int n;

public:
    void NHAP();
    void XUAT();
};

void HANG::NHAP() {
    cout << "Nhap ma hang: ";            fflush(stdin);         gets(MaHang); 
    cout << "Nhap ten hang: ";           fflush(stdin);         gets(TenHang);
    cout << "Nhap don gia: ";                                   cin >> DonGia;
}
void HANG::XUAT() {
    cout << setw(15) << MaHang << setw(15) << TenHang  << setw(15) << DonGia << endl;
}
void PHIEU::NHAP() {
    cout << "\n Nhap ma phieu: ";          fflush(stdin);          gets(MaPhieu);
    cout << "\nNhap so mat hang: ";                               cin >> n;
    for (int i = 0; i < n; i++) 
    {
        x[i].NHAP();
    }
}
void PHIEU::XUAT() {
    cout << "\n Ma phieu: " << MaPhieu << endl;
    cout << "\n Danh sach mat hang : ";
    cout << setw(15) << "Ma Hang" << setw(15) << "Ten Hang"<< setw(15) << "Don Gia" << endl;
    for (int i = 0; i < n; i++) 
    {
        x[i].XUAT();
    }
}
int main() {
    PHIEU p;
    p.NHAP();
    p.XUAT();
    return 0;
}
