#include <iostream>
#include <string.h>
using namespace std;

class Nguoi {
private:
    char Hoten[50];
    int Tuoi;
public:
    void Nhap();
    void Xuat();
    int getTuoi() { return Tuoi; }
    void setTuoi(int t) { Tuoi = t; }
};

void Nguoi::Nhap() {
    cout << "Nhap ho ten: "; fflush(stdin); gets(Hoten);
    cout << "Nhap tuoi: "; cin >> Tuoi;
}

void Nguoi::Xuat() {
    cout << "Ho ten: " << Hoten << endl;
    cout << "Tuoi: " << Tuoi << endl;
}

class BenhVien {
private:
    char Tenbenhvien[50];
    char Diachi[100];
    char Giamdoc[50];
public:
    void Nhap();
    void Xuat();
};

void BenhVien::Nhap() {
    cout << "Nhap ten benh vien: "; fflush(stdin); gets(Tenbenhvien);
    cout << "Nhap dia chi benh vien: "; fflush(stdin); gets(Diachi);
    cout << "Nhap giam doc benh vien: "; fflush(stdin); gets(Giamdoc);
}

void BenhVien::Xuat() {
    cout << "Ten benh vien: " << Tenbenhvien << endl;
    cout << "Dia chi benh vien: " << Diachi << endl;
    cout << "Giam doc benh vien: " << Giamdoc << endl;
}

class BenhNhan {
private:
    char MaBN[10];
    char TienSu[100];
    char ChanDoan[100];
    BenhVien bv;
    Nguoi nguoi;
public:
    void Nhap();
    void Xuat();
    Nguoi& getNguoi() { return nguoi; }
    char* getMaBN() { return MaBN; }
};

void BenhNhan::Nhap() {
    cout << "Nhap ma benh nhan: "; fflush(stdin); gets(MaBN);
    cout << "Nhap tien su benh nhan: "; fflush(stdin); gets(TienSu);
    cout << "Nhap chan doan benh nhan: "; fflush(stdin); gets(ChanDoan);
    bv.Nhap();
    nguoi.Nhap();
}

void BenhNhan::Xuat() {
    cout << "Ma benh nhan: " << MaBN << endl;
    cout << "Tien su: " << TienSu << endl;
    cout << "Chan doan: " << ChanDoan << endl;
    bv.Xuat();
    nguoi.Xuat();
}

int main() {
    const int MAX = 100;
    int n;
    cout << "Nhap so luong benh nhan (max 100): "; cin >> n;
    if (n > MAX) n = MAX;
    BenhNhan ds[MAX];

    for (int i = 0; i < n; i++) {
        cout << "\n Nhap thong tin benh nhan thu " << i + 1 << ":\n";
        ds[i].Nhap();
    }

    cout << "\n Danh sach benh nhan vua nhap:\n";
    for (int i = 0; i < n; i++) {
        cout << "\n Benh nhan thu " << i + 1 << ":\n";
        ds[i].Xuat();
    }

    int countTren30 = 0;
    for (int i = 0; i < n; i++) {
        if (ds[i].getNguoi().getTuoi() > 30)
            countTren30++;
    }
    cout << "\n So benh nhan co tuoi lon hon 30: " << countTren30 << endl;

    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].getMaBN(), "BN01") == 0) {
            ds[i].getNguoi().setTuoi(20);
            cout << "\n Da sua tuoi benh nhan co ma BN01 thanh 20.\n";
            break;
        }
    }

    cout << "\n Danh sach benh nhan sau khi sua:\n";
    for (int i = 0; i < n; i++) {
        cout << "\n Benh nhan thu " << i + 1 << ":\n";
        ds[i].Xuat();
    }
    return 0;
}

