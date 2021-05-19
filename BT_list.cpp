#include <iostream>
using namespace std;

typedef struct sv
{
    int maSV;
    float diemthi;
    sv *next;
} SV;

int main()
{
    int N;
    SV *temp, *sinhvien[N];
    cout << "nhap so luong sinh vien: ";
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        sinhvien[i] = new SV;
        cout << "Nhap ma so sinh vien: ";
        cin >> sinhvien[i]->maSV;
        cout << "Nhap diem thi: ";
        cin >> sinhvien[i]->diemthi;
    }
    sinhvien[N-1]->next = NULL;
    for(int i = 0; i < N-1; i++)
    {
        sinhvien[i]->next = sinhvien[i+1];
    }
    cout << "  MSSV   Diem"<<endl;
    for(int i = 0; i < N; i++){
        cout << sinhvien[i]->maSV << "    " <<sinhvien[i]->diemthi << endl; 
    }
}