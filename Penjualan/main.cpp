#include <iostream>
#include "Penjualan.h"

using namespace std;

int main()
{
    ListToko LT;
    ListBarang LB;
    address_Toko P;
    address_Relasi R;
    address_Barang Q;
    infotypeToko T;
    infotypeBarang B;

    createList_Toko(LT);
    createList_Barang(LB);

    cout << "ID toko: ";
    cin >> T.ID;
    cout << "Nama toko: ";
    cin >> T.Nama;
    cout << "Lokasi toko: ";
    cin >> T.Lokasi;

    P = createElmToko(T);
    insertToko(LT,P);

    cout << "ID barang: ";
    cin >> B.ID;
    cout << "Nama barang: ";
    cin >> B.NamaBarang;
    cout << "Harga barang: ";
    cin >> B.Harga;

    Q = createElmBarang(B);
    insertBarang(LB,Q);

    insertRelasi(LT, P, Q, R);

    cout << "ID toko: ";
    cin >> T.ID;
    cout << "Nama toko: ";
    cin >> T.Nama;
    cout << "Lokasi toko: ";
    cin >> T.Lokasi;

    P = createElmToko(T);
    insertToko(LT,P);

    showData(LT);



    return 0;
}
