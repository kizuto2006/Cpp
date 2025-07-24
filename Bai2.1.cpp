#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
class date
{
	private:
		int D;
		int M;
		int Y;
	public:
		void nhap();
		void xuat();	
};
class nhansu
{
	private:
		int mans;
		char hoten[40];
		date ns;
	public:
		void nhap();
		void xuat();
};
void date::nhap()
{
	cout << "\n nhap ngay sinh :";           cin >> D;
	cout << "\n nhap thang sinh :";          cin >> M;
	cout << "\n nhap nam sinh :";            cin >> Y;
}
void date::xuat()
{
	cout << "Ngay thang nam sinh la : " << D << "/" << M<< "/" << Y << endl;
}
void nhansu::nhap()
{
	cout << "\n Nhap ma nhan su : ";                    cin>>mans;
	cout << "\n Nhap ten nhan su : ";   fflush(stdin);  gets(hoten);
	ns.nhap();	
}
void nhansu::xuat()
{
	cout << "\n Ma nhan su : " << mans;
	cout << "\n Ten: " << hoten << endl;
	ns.xuat();								
}
int main()
{
	nhansu a;
	a.nhap();
	a.xuat();
}