#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
class NSX
{
    private :
        int MaNsx[10];
        char TenNsx[50];
        char DiaChi[100];
    public :
        void Nhap();
        void Xuat();
};

class Hang
{
    private :
        int MaHang[10];
        char TenHang[50];
        NSX x;  
    public :
        void Nhap();  
        void Xuat();
};

void NSX::Nhap()
{
    cout << "\n Nhap ma NSX : ";                            cin >> MaNSX;
    cout << "\n Nhap ten NSX : ";           fflush(stdin);  gets(TenNSX);
    cout << "\n Nhap dia chi NSX : ";       fflush(stdin);  gets(DiaChi);
}

void NSX::Xuat()
{
    cout << "\n Ma NSX: " << MaNSX << endl;
    cout << "\n Ten NSX: " << TenNSX << endl;
    cout << "\n Dia chi NSX: " << DiaChi << endl;
}

void Hang::Nhap()
{
    cout << "\n Ma hang : ";                   cin << MaHang;
    cout << "\n Ho va ten : "; fflush(stdin);  gets(TenHang);
    x.Nhap();
}

void Hang::Xuat()
{
    cout << "\n Ma hang : " << MaHang << endl;
    cout << "\n Ten hang : " << TenHang << endl;
    x.Xuat();
}
int main()
{
    Hang a;
    a.Nhap();
    a.Xuat();
}



