#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

class NG 
{
	private:
	    char ht[50];
	    int ds,ms,ys;
	    char qq[50];
	public:
	    void Nhap();
	    void Xuat();
};
void NG::Nhap() 
{
    cout << "Nhap ho ten: ";	fflush(stdin);	gets(ht);
    cout << "Nhap ngay sinh: ";					cin>>ds;
    cout << "Nhap thang sinh: ";				cin>>ms;
    cout << "Nhap nam sinh: ";					cin>>ys;
    cout << "Nhap que quan: "; 	fflush(stdin);	gets(qq);
}
void NG::Xuat() 
{
    cout << ht << setw(15)
		 << "Ngay sinh: " << ds << "/" << ms << "/" << ys << endl
         << setw(20) << qq;
}

class SV : public NG
{
	private:
	    char MaSV[20];
	    char Nganh[30];
	    int KhoaHoc;
	    NG ng;
	public:
	    void Nhap();
	    void Xuat();
	    int getKhoaHoc();
	friend class LOPHOC;
};
void SV::Nhap() 
{
    ng.Nhap();
    fflush(stdin);
    cout << "Nhap Ma SV: "; gets(MaSV);
    cout << "Nhap Nganh: "; gets(Nganh);
    cout << "Nhap Khoa hoc: "; cin >> KhoaHoc;
}
void SV::Xuat() 
{
    ng.Xuat();
    cout << setw(10) << MaSV
         << setw(20) << Nganh
         << setw(10) << KhoaHoc << endl;
}

int SV::getKhoaHoc() 
{
    return KhoaHoc;
}

class LOPHOC 
{
	private:
	    char MaLH[20]; 
		char TenLH[30];
		int dm,mm,ym;
	    char TenGV[50];
	    SV x[100];
	    int n;
	public:
	    void Nhap();
	    void Xuat();
	    int DemSVKhoa11();
	    void SapXepTangDan();
};
void LOPHOC::Nhap() 
{
    cout << "Ma lop hoc: "; fflush(stdin);	gets(MaLH);
    cout << "Ten lop hoc: ";fflush(stdin); 	gets(TenLH);
    cout << "Ngay mo: ";					cin>>dm;
    cout << "Thang mo: ";					cin>>mm;
    cout << "Nam mo: ";						cin>>ym;
    cout << "Ten giao vien: ";fflush(stdin);gets(TenGV);
    cout << "So luong sinh vien: "; 		cin >> n;
    for (int i = 0; i < n; i++) 
	{
        cout << "Nhap thong tin sinh vien thu " << i + 1 << ":\n";
        x[i].Nhap();
    }
}
void LOPHOC::Xuat() 
{
    cout << "Ma lop hoc: " << MaLH << endl;
    cout << "Ten lop hoc: " << TenLH << endl;
    cout << "Ngay mo: " << dm << "/" << mm << "/" << ym << endl;
    cout << "Giao vien: " << TenGV << endl;
    cout << setw(20) << "Ho ten"
         << setw(15) << "Ngay sinh"
         << setw(20) << "Que quan"
         << setw(10) << "Ma SV"
         << setw(20) << "Nganh"
         << setw(10) << "Khoa" << endl;
    for (int i = 0; i < n; i++) 
	{
        x[i].Xuat();
    }
}

int LOPHOC::DemSVKhoa11() 
{
    int count = 0;
    for (int i = 0; i < n; i++) 
	{
        if (x[i].KhoaHoc == 11)
            count++;
    }
    return count;
}

void LOPHOC::SapXepTangDan() 
{
    for (int i = 0; i < n - 1; i++) 
	{
        for (int j = i + 1; j < n; j++) 
		{
            if (x[i].KhoaHoc > x[j].KhoaHoc) 
			{
                swap(x[i], x[j]);
            }
        }
    }
}

int main() 
{
    LOPHOC lh;
    lh.Nhap();
    lh.Xuat();
    cout << "So sinh vien khoa 11: " << lh.DemSVKhoa11() << endl;
    cout << "======================================================================================================" << endl;
    cout << "Lop hoc sau sap xep la:" << endl;
    lh.SapXepTangDan();
    lh.Xuat();
    return 0;
}

