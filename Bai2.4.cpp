#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

class MAY {
private:
    char MaMay[20];
    char KieuMay[30];
    char TinhTrang[50];

public:
    void NHAP();
    void XUAT();
};

class QUANLY {
private:
    char MaQL[20];
    char HoTen[50];

public:
    void NHAP();
    void XUAT();
};

class PHONGMAY {
private:
    char MaPhong[20];
    char TenPhong[30];
    float DienTich;
    QUANLY x;
    MAY *y;
    int n;

public:
    void NHAP();
    void XUAT();
};

void MAY::NHAP() {
    cout << "Nhap ma may: ";        fflush(stdin);         gets(MaMay);
    cout << "Nhap kieu may: ";      fflush(stdin);         gets(KieuMay);
    cout << "Nhap tinh trang: ";    fflush(stdin);         gets(TinhTrang);
}   

void MAY::XUAT() {
    cout << left << setw(15) << MaMay << setw(20) << KieuMay << setw(25) << TinhTrang << endl;
}

void QUANLY::NHAP() {
    cout << "Nhap ma quan ly: "; fflush(stdin); gets(MaQL);
    cout << "Nhap ho ten quan ly: "; fflush(stdin); gets(HoTen);
}

void QUANLY::XUAT() {
    cout << "Ma quan ly: " << MaQL << endl;
    cout << "Ho ten : " << HoTen << endl;
}

void PHONGMAY::NHAP() {
    cout << "Nhap ma phong: ";              fflush(stdin);          gets(MaPhong);
    cout << "Nhap ten phong: ";             fflush(stdin);          gets(TenPhong);
    cout << "Nhap dien tich: ";                                     cin >> DienTich;
    cout << "\n--- Nhap thong tin quan ly ---\n";
    x.NHAP();
    cout << "\nNhap so luong may: ";                                cin >> n;
    y = new MAY[n];
    for (int i = 0; i < n; i++) 
    {
        y[i].NHAP();
    }
}

void PHONGMAY::XUAT() {
    cout << "\n=============== THONG TIN PHONG MAY ===============\n";
    cout << "Ma phong : " << MaPhong << endl;
    cout << "Ten phong: " << TenPhong << endl;
    cout << "Dien tich: " << DienTich << " m2" << endl;
    cout << "\n--- Thong tin quan ly ---\n";
    x.XUAT();
    cout << "\n--- Danh sach may ---\n";
    cout << left << setw(15) << "Ma May"
         << setw(20) << "Kieu May"
         << setw(25) << "Tinh Trang" << endl;
    for (int i = 0; i < n; i++) {
        y[i].XUAT();
    }
}

int main() {
    PHONGMAY p;
    p.NHAP();
    p.XUAT();
    return 0;
}
