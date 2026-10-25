#include <iostream>

using namespace std;

// 1. Nhan trong GF(2^4) voi da thuc: x^4 + x + 1 (he so 0x13, so du 0x03)
int nhan_GF4(int a, int b) {
    int kq = 0;
    for (int i = 0; i < 4; i++) {
        // Neu bit cuoi cua b la 1 thi cong (XOR) vao ket qua
        if (b & 1) {
            kq = kq ^ a;
        }
        // Kiem tra neu bit thu 3 (x^3) bang 1 de chia lay du
        int bit_cao = a & 8; // 8 o he nhi phan la 1000

        a = (a << 1) & 15;   // Nhan 2 (dich trai) va giu lai 4 bit (15 la 1111)

        if (bit_cao != 0) {
            a = a ^ 3;       // Chia du cho x + 1 (3 o he nhi phan la 0011)
        }

        b = b >> 1;          // Dich phai b de xet bit tiep theo
    }
    return kq;
}

// 2. Nhan trong GF(2^8) voi da thuc: x^8 + x^4 + x^3 + x + 1 (AES, so du 0x1B)
int nhan_GF8(int a, int b) {
    int kq = 0;
    for (int i = 0; i < 8; i++) {
        // Neu bit cuoi cua b la 1 thi cong (XOR) vao ket qua
        if (b & 1) {
            kq = kq ^ a;
        }

        // Kiem tra neu bit thu 7 (x^7) bang 1
        int bit_cao = a & 128; // 128 o he nhi phan la 10000000

        a = (a << 1) & 255;    // Nhan 2 va giu lai 8 bit (255 la 11111111)

        if (bit_cao != 0) {
            a = a ^ 27;        // Chia du cho x^4 + x^3 + x + 1 (27 la 0x1B)
        }

        b = b >> 1;
    }
    return kq;
}

int main() {
    cout << "=== NHAN DA THUC TRONG TRUONG HUU HAN ===" << endl;

    // Test thu GF(2^4): vi du nhan 11 va 13
    int a4 = 11, b4 = 13;
    cout << "GF(2^4): " << a4 << " * " << b4 << " = " << nhan_GF4(a4, b4) << endl;

    // Test thu GF(2^8): vi du nhan 0x57 va 0x83 (he hex)
    int a8 = 0x57, b8 = 0x83;
    cout << "GF(2^8): 0x" << hex << a8 << " * 0x" << b8 << " = 0x" << nhan_GF8(a8, b8) << endl;

    return 0;
}