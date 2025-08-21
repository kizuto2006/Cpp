#include <iostream>
#include <string.h>
using namespace std;

class Khoa {
public:
    char Makhoa[10];
    char Tenkhoa[30];
    char Truongkhoa[30];
};

class Ban {
public:
    char Maban[10];
    char Tenban[30];
    char Ngaythanhlap[15];
};

class Truong {
private:
    char Matruong[10];
    char Tentruong[30];
    char Diachi[100];
public:
    void Nhap();
    void Xuat();
    Khoa x[100];
    Ban y[100];
    int n, m;

    void NhapDS();
    void XuatDS();
    void XoaKhoaTheoMa(char makhoa[]);
};

void Truong::Nhap() {
    cout << "Nhap ma truong: "; fflush(stdin); gets(Matruong);
    cout << "Nhap ten truong: "; fflush(stdin); gets(Tentruong);
    cout << "Nhap dia chi truong: "; fflush(stdin); gets(Diachi);
}

void Truong::Xuat() {
    cout << "Ma truong: " << Matruong << endl;
    cout << "Ten truong: " << Tentruong << endl;
    cout << "Dia chi truong: " << Diachi << endl;
}

void Truong::NhapDS() {
    cout << "Nhap so luong khoa (max 100): "; cin >> n;
    if (n > 100) n = 100;
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin khoa thu " << i + 1 << ":\n";
        cout << "Ma khoa: "; fflush(stdin); gets(x[i].Makhoa);
        cout << "Ten khoa: "; fflush(stdin); gets(x[i].Tenkhoa);
        cout << "Truong khoa: "; fflush(stdin); gets(x[i].Truongkhoa);
    }
    cout << "Nhap so luong ban (max 100): "; cin >> m;
    if (m > 100) m = 100;
    for (int i = 0; i < m; i++) {
        cout << "Nhap thong tin ban thu " << i + 1 << ":\n";
        cout << "Ma ban: "; fflush(stdin); gets(y[i].Maban);
        cout << "Ten ban: "; fflush(stdin); gets(y[i].Tenban);
        cout << "Ngay thanh lap: "; fflush(stdin); gets(y[i].Ngaythanhlap);
    }
}

void Truong::XuatDS() {
    cout << "\nThong tin Truong:\n";
    Xuat();
    cout << "\nDanh sach Khoa:\n";
    for (int i = 0; i < n; i++) {
        cout << "Khoa thu " << i + 1 << ":\n";
        cout << "Ma khoa: " << x[i].Makhoa << endl;
        cout << "Ten khoa: " << x[i].Tenkhoa << endl;
        cout << "Truong khoa: " << x[i].Truongkhoa << endl;
    }
    cout << "\nDanh sach Ban:\n";
    for (int i = 0; i < m; i++) {
        cout << "Ban thu " << i + 1 << ":\n";
        cout << "Ma ban: " << y[i].Maban << endl;
        cout << "Ten ban: " << y[i].Tenban << endl;
        cout << "Ngay thanh lap: " << y[i].Ngaythanhlap << endl;
    }
}

void Truong::XoaKhoaTheoMa(char makhoa[]) {
    int vt = -1;
    for (int i = 0; i < n; i++) {
        if (strcmp(x[i].Makhoa, makhoa) == 0) {
            vt = i;
            break;
        }
    }
    if (vt != -1) {
        for (int i = vt; i < n - 1; i++) {
            x[i] = x[i + 1];
        }
        n--;
    }
}

int main() {
    Truong t;
    t.Nhap();
    t.NhapDS();
    t.XoaKhoaTheoMa("KH01");
    t.XuatDS();
    return 0;
}

