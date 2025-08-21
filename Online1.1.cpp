#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

class N
{
	private:
		char ma[100];
		char ten[100];
		char T[100];
		char diachi[100];
	public:
		void nhap();
		void xuat();
	friend void sua_ten(N &n,char &T);		
};
void N::nhap()
{
	cout<<"\n Nhap ma Ncc: ";				fflush(stdin);			gets(ma);
	cout<<"\n Nhap ten Ncc: ";				fflush(stdin);			gets(ten);
	cout<<"\n Nhap dia chi Ncc: ";			fflush(stdin);			gets(diachi);
}
void N::xuat()
{
	cout<<"Ma NCC: "<<ma<<setw(30)<<"Ten NCC: "<<ten<<endl
		<<"Dia chi: "<<diachi<<endl; 
}
void sua_ten(N &n,char &T)
{
	strcpy(n.ten,n.T);
}

class H
{
	private :
		char ten[100];
		float gia;
		int sl;
	public :
		void nhap();
		void xuat();	
	friend class P;	
};
void H::nhap()
{
	cout<<"\n -Nhap ten hang: ";		fflush(stdin);			gets(ten);
	cout<<"\n -Nhap gia hang: ";								cin>>gia;
	cout<<"\n -Nhap so luong: ";								cin>>sl;
}
void H::xuat()
{
	cout<<ten<<setw(20)<<gia<<setw(20)<<sl<<setw(20)<<(static_cast<float>(sl)*gia)<<endl;
}

class P
{
	private :
		char mp[100];
		int d,m,y;
		H h[100];
		N n;
		int l;
	public :
		void nhap();
		void xuat();
	friend void loc(P p);	
};
void P::nhap()
{
	cout<<"\n Nhap ma phieu: ";			fflush(stdin);			gets(mp);
	cout<<"\n Nhap ngay lap: "<<endl
		<<"\n -Nhap ngay: ";										cin>>d;
	cout<<"\n -Nhap thang: ";										cin>>m;
	cout<<"\n -Nhap nam: ";											cin>>y;
	n.nhap();
	cout<<"\n Nhap so loai hang: ";									cin>>l;
	for(int i=0;i<l;i++)
	{
		cout<<"Nhap loai thu "<<i+1<<endl;
		h[i].	nhap();
	}
}
void P::xuat()
{
	cout<<setw(30)<<"PHIEU NHAP HANG"<<endl;
	cout<<"Ma phieu: "<<mp<<setw(20)<<"Ngay lap: "<<d<<"/"<<m<<"/"<<y<<endl;
	n.xuat();
	cout<<"----------------------------------------------------------------------------------"<<endl;
	cout<<"Ten"<<setw(20)<<"Don gia"<<setw(20)<<"So luong"<<setw(20)<<"Thanh tien"<<endl;
	for(int i=0;i<l;i++)
	{
		h[i].xuat();
	}
}

void loc(P p)
{
	cout<<"Ten"<<setw(20)<<"Don gia"<<setw(20)<<"So luong"<<setw(20)<<"Thanh tien"<<endl;
	for(int i=0;i<p.l;i++)
	{
		if(h[i].sl>10)
		{
			h[i].xuat();
		}
	}
}

int main()
{
	P p;
	N n;
	p.nhap();
	p.xuat();
	sua_ten(n,"Samsung");
	p.loc();
}
