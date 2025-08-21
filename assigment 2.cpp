#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
class nguoi
{
	protected:
		char hoten[100];
		int D,M,Y;
		char que[100];
	public:
		void nhap();
		void xuat();
};
class sv : public nguoi
{
		int masv;
		char nganh[100];
		int khoa;
	public:
		void nhap();
		void xuat();
friend class lp;
};
class lp
{
	private:
		char malp[100];
		char tenLH[100];
		int DM,MM,YM;
		int n;
		char gv[100];
		sv a[100];
	public:
		void nhap();
		void xuat();
		void svkhoa11();
		void sapxep();
};
void sv::nhap()
{
	cout<<"\n ho ten : ";		fflush(stdin);		gets(hoten);
	cout<<"\n ngay sinh: ";							cin>>D;
	cout<<"\n thang sinh: ";						cin>>M;
	cout<<"\n nam sinh: ";							cin>>Y;
	cout<<"\n que: ";			fflush(stdin);		gets(que);
	
	cout<<"ma sv: ";							cin>>masv;
	cout<<"nganh: ";		fflush(stdin);		gets(nganh);
	cout<<"khoa: ";								cin>>khoa;
}
void sv::xuat()
{
	cout<<hoten;
	cout<<setw(10)<<D<<"/"<<M<<"/"<<Y;
	cout<<setw(10)<<que;
	cout<<setw(10)<<masv;
	cout<<setw(10)<<nganh;
	cout<<setw(10)<<khoa<<endl;
}
void lp::nhap()
{
	cout<<"\n ma lop: ";		fflush(stdin);		gets(malp);
	cout<<"\n ten lop: ";		fflush(stdin);		gets(tenLH);
	cout<<"\n ngay mo: ";							cin>>DM;
	cout<<"\n thang mo: ";							cin>>MM;
	cout<<"\n nam mo: ";							cin>>YM;
	cout<<"\n giao vien: ";		fflush(stdin);		gets(gv);
	cout<<"\n nhap so sinh vien trong lop: ";		cin>>n;
	for(int i;i<n;i++)
	{
		cout<<"thong tin sinh vien "<<i+1<<endl;
		a[i].nhap();
	}
}
void lp::xuat()
{
	cout<<"\n ma lop: "<<malp;
	cout<<"\n ten lop: "<<tenLH;
	cout<<"\n ngay mo: "<<DM<<"/"<<MM<<"/"<<YM<<endl;
	cout<<"\n giao vien: "<<gv;
	cout<<"\n so sinh vien trong lop: "<<n<<endl;
	cout<<setw(5)<<"ho ten ";
	cout<<setw(10)<<"ngay sinh ";
	cout<<setw(10)<<"que ";
	cout<<setw(10)<<"ma sv ";
	cout<<setw(10)<<"nganh ";
	cout<<setw(10)<<"khoa "<<endl;
		for(int i;i<n;i++)
	{
		a[i].xuat();
	}
}
void lp::svkhoa11()
{
	int dem=0;
	for(int i=0;i<n;i++)
	{
		if(a[i].khoa == 11)
		{
			dem++;
		}
		
	}
	if(dem==0)
	{	
		cout<<"\n khong co sv khoa 11: "<<endl;
	}
	else
	{
		cout<<"\n so sv khoa 11: "<<dem<<endl;
		cout<<"\n ====thong tin sv khoa 11===="<<endl;
			{
				cout<<setw(5)<<"ho ten ";
				cout<<setw(10)<<"ngay sinh ";
				cout<<setw(10)<<"que ";
				cout<<setw(10)<<"ma sv ";
				cout<<setw(10)<<"nganh ";
				cout<<setw(10)<<"khoa "<<endl;
			}
			for(int i=0;i<n;i++)
			{
				if(a[i].khoa == 11)
				{
			
					a[i].xuat();
				}
	}
}
}
void lp::sapxep()
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i].khoa > a[j].khoa)
			{
				sv tam = a[i];
				a[i] = a[j];
				a[j] = tam;
			}
		}
	}
 } 
int main()
{
	lp b;
	b.nhap();
	cout<<"\n =====thong tin lop hoc la========";
	b.xuat();
	b.svkhoa11();
	b.sapxep();
	cout<<"\n =======thong tin sau khi sap xep======== "<<endl;
	b.xuat();	
}
