#include <iostream>
#include <string>

using namespace std;

struct SinhVien{
    string account;
    string hoTen;
    string maSV;
};

const int MAX_SINHVIEN = 100;
SinhVien danhSachSinhVien[MAX_SINHVIEN];
int soLuongSinhVien = 0;

void nhapSinhVien(SinhVien& sv) {
    cout << "Nhap thong tin sinh vien:" << endl;
    cout << "Account: ";
    cin >> sv.account;
    cout << "Ho va ten: ";
    cin.ignore();
    getline(cin, sv.hoTen);
    cout << "Ma so sinh vien: ";
    cin >> sv.maSV;
}

void inSinhVien(const SinhVien& sv) {
    cout << "Thong tin sinh vien:" << endl;
    cout << "Account: " << sv.account << endl;
    cout << "Ho va ten: " << sv.hoTen << endl;
    cout << "Ma so sinh vien: " << sv.maSV << endl;
}

void timKiemSinhVien(const string& account) {
    bool timThay = false;
    for (int i = 0; i < soLuongSinhVien; i++) {
        if (danhSachSinhVien[i].account == account) {
            inSinhVien(danhSachSinhVien[i]);
            timThay = true;
        }
    }
    if (!timThay) {
        cout << "Khong tim thay sinh vien." << endl;
    }
}

void xoaSinhVien(const string& maSV) {
    int viTriXoa = -1;
    for (int i = 0; i < soLuongSinhVien; i++) {
        if (danhSachSinhVien[i].maSV == maSV) {
            viTriXoa = i;
            break;
        }
    }
    if (viTriXoa != -1) {
        for (int i = viTriXoa; i < soLuongSinhVien - 1; i++) {
            danhSachSinhVien[i] = danhSachSinhVien[i + 1];
        }
        soLuongSinhVien--;
        cout << "Da xoa sinh vien." << endl;
    }
    else {
        cout << "Khong tim thay sinh vien." << endl;
    }
}

void inDanhSachSinhVien() {
    cout << "Danh sach sinh vien:" << endl;
    for (int i = 0; i < soLuongSinhVien; i++) {
        inSinhVien(danhSachSinhVien[i]);
        cout << "---------------------" << endl;
    }
}

int main() {
    while (true) {
        cout << "---------------------" << endl;
        cout << "Menu:" << endl;
        cout << "1. Nhap thong tin sinh vien" << endl;
        cout << "2. In thong tin sinh vien" << endl;
        cout << "3. Tim kiem sinh vien" << endl;
        cout << "4. Xoa sinh vien" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";

        int luaChon;
        cin >> luaChon;

        if (luaChon == 0) {
            break;
        }
        else if (luaChon == 1) {
            if (soLuongSinhVien < MAX_SINHVIEN) {
                SinhVien sv;
                nhapSinhVien(sv);
                danhSachSinhVien[soLuongSinhVien] = sv;
                soLuongSinhVien++;
            }
            else {
                cout << "Danh sach sinh vien da day." << endl;
            }
        }
        else if (luaChon == 2) {
            inDanhSachSinhVien();
        }
        else if (luaChon == 3) {
            cout << "Nhap account cua sinh vien can tim: ";
            string account;
            cin >> account;
            timKiemSinhVien(account);
        }
        else if (luaChon == 4) {
            cout << "Nhap ma so sinh vien cua sinh vien can xoa: ";
            string maSV;
            cin >> maSV;
            xoaSinhVien(maSV);
            inDanhSachSinhVien();
        }
        else {
            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
        }
    }

    return 0;
}