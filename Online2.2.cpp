#include <iostream>
#include <string.h>
using namespace std;

class School {
private:
    char Name[50];
    char Date[20];
public:
    void input();
    void output();
    char* getName() { return Name; }
    void setName(char newName[50]) { strcpy(Name, newName); }
};

void School::input() {
    cout << "Nhap ten truong: "; fflush(stdin); gets(Name);
    cout << "Nhap ngay thanh lap truong: "; fflush(stdin); gets(Date);
}

void School::output() {
    cout << "Ten truong: " << Name << endl;
    cout << "Ngay thanh lap: " << Date << endl;
}

class Faculty {
private:
    char Name[50];
    char Date[20];
    School x;
public:
    void input();
    void output();
    School& getSchool() { return x; }
};

void Faculty::input() {
    cout << "Nhap ten khoa: "; fflush(stdin); gets(Name);
    cout << "Nhap ngay thanh lap khoa: "; fflush(stdin); gets(Date);
    x.input();
}

void Faculty::output() {
    cout << "Ten khoa: " << Name << endl;
    cout << "Ngay thanh lap khoa: " << Date << endl;
    x.output();
}

class Person {
private:
    char Name[50];
    char Birth[20];
    char Address[100];
public:
    void input();
    void output();
};

void Person::input() {
    cout << "Nhap ho ten: "; fflush(stdin); gets(Name);
    cout << "Nhap ngay sinh: "; fflush(stdin); gets(Birth);
    cout << "Nhap dia chi: "; fflush(stdin); gets(Address);
}

void Person::output() {
    cout << "Ho ten: " << Name << endl;
    cout << "Ngay sinh: " << Birth << endl;
    cout << "Dia chi: " << Address << endl;
}

class Student : public Person {
private:
    Faculty y;
    char Class[30];
    float Score;
public:
    void input();
    void output();
    Faculty& getFaculty() { return y; }
};

void Student::input() {
    Person::input();
    y.input();
    cout << "Nhap lop: "; fflush(stdin); gets(Class);
    cout << "Nhap diem: "; cin >> Score;
}

void Student::output() {
    Person::output();
    y.output();
    cout << "Lop: " << Class << endl;
    cout << "Diem: " << Score << endl;
}

int main() {
    Student s;
    cout << "=== Nhap thong tin sinh vien ===\n";
    s.input();

    cout << "\n=== Thong tin sinh vien vua nhap ===\n";
    s.output();

    char newName[50] = "DHCNHN";
    s.getFaculty().getSchool().setName(newName);

    cout << "\n=== Thong tin sinh vien sau khi sua ten truong ===\n";
    s.output();

    return 0;
}

