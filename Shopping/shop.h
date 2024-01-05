#ifndef SHOP_H_INCLUDED
#define SHOP_H_INCLUDED
#include <iostream>
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define nextAnak(P) P->nextAnak
#define nextRelasi(P) P->nextRelasi
#define InfoB(P) P->InfoB
#define Nil NULL

using namespace std;

struct Toko{
    int ID;
    string Nama;
    string Lokasi;
};

struct Barang{
    int ID;
    string NamaBarang;
    int Harga;
};

typedef Toko infotypeToko;
typedef Barang infotypeBarang;
typedef struct ElmToko *address_Toko;
typedef struct ElmBarang *address_Barang;
typedef struct ElmRelasi *address_Relasi;

struct ElmRelasi{
    address_Relasi nextRelasi;
    address_Barang InfoB;
};

struct ElmToko{
    infotypeToko info;
    address_Toko next;
    address_Relasi nextAnak;
};

struct ElmBarang{
    infotypeBarang info;
    address_Barang next;
    address_Barang prev;
};

struct ListToko{
    address_Toko first;
};

struct ListBarang{
    address_Barang first;
    address_Barang last;
};

void createList_Toko(ListToko &LT);
void createList_Barang(ListBarang &LB);
address_Toko createElmToko(infotypeToko InfoToko);
address_Barang createElmBarang(infotypeBarang InfoBarang);
address_Relasi createElmRelasi();
void insertToko(ListToko &LT, address_Toko P);
void insertBarang(ListBarang &LB, address_Barang P);
void insertRelasi(ListToko &LT, address_Toko P, address_Barang B, address_Relasi R);
void deleteToko(ListToko &LT, address_Toko &P);
void deleteBarangYangDiList(ListBarang &LB, address_Barang &P);
void deleteRelasi(ListToko &LT, address_Toko P, address_Relasi &R, int ID);
address_Toko findToko(ListToko LT, int ID);
address_Barang findBarang(ListBarang LB, int ID);
address_Relasi findRelasi(ListToko LT, address_Toko P, int ID);
void showData(ListToko LT);
void showsemuabarang(ListBarang LB);
void showBarangDari_Toko(ListToko LT, int IDToko);
void showTokoDari_Barang(ListToko LT, int IDBarang);
void showToko_PalingLengkap(ListToko LT);
void showToko_PalingTidakLengkap(ListToko LT);
int HitungBarangBerdasarkan_Toko(ListToko LT, address_Toko P);
void menu(int &masukan);

#endif // SHOP_H_INCLUDED
