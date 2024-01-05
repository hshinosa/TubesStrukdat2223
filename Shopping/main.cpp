#include <iostream>
#include "shop.h"

using namespace std;

int main() {
    ListToko LT;
    ListBarang LB;
    address_Toko P;
    address_Barang Q;
    Toko t;
    Barang b;
    int masukan;
    int IDbarang;
    int IDtoko;
    int i;
    address_Relasi r;

    createList_Toko(LT);
    createList_Barang(LB);

    cout << "------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "||          SELAMAT DATANG DI APLIKASI PENJUALAN          ||" << endl;
    cout << "||                        ^_^                             ||" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << endl;

    do {
        menu(masukan);

        switch (masukan) {
            case 1:
                do {
                    cout << endl;
                    cout << "Masukkan ID Toko: ";
                    cin >> t.ID;
                    cout << "Masukkan Nama Toko: ";
                    cin >> t.Nama;
                    cout << "Masukkan Lokasi Toko: ";
                    cin >> t.Lokasi;
                    insertToko(LT, createElmToko(t));
                    cout << "Data toko berhasil disimpan ^-^" << endl;

                    cout << "===============================" << endl;
                    cout << "Apakah Anda ingin menambah data toko lagi?" << endl;
                    cout << "1. Ya" << endl;
                    cout << "2. Tidak (Kembali ke menu utama)" << endl;
                    cout << "Silahkan ketik nomor yang ingin anda pilih ^_^ : ";
                    cin >> masukan;
                    cout << endl;
                } while (masukan == 1);
                for (i = 1; i < 20; i++){
                    cout << endl;
                }
                break;

            case 2:
                do {
                    cout << endl;
                    cout << "Masukkan ID Barang: ";
                    cin >> b.ID;
                    cout << "Masukkan Nama Barang: ";
                    cin >> b.NamaBarang;
                    cout << "Masukkan Harga Barang: ";
                    cin >> b.Harga;
                    insertBarang(LB, createElmBarang(b));
                    cout << "Data barang berhasil disimpan ^-^" << endl;
                    cout << endl;
                    cout << "=================================" << endl;
                    cout << "Apakah Anda ingin menambah data barang lagi?" << endl;
                    cout << "1. Ya" << endl;
                    cout << "2. Tidak (Kembali ke menu utama)" << endl;
                    cout << "Silahkan ketik nomor yang ingin anda pilih ^_^ : : ";
                    cin >> masukan;
                    cout << endl;
                } while (masukan == 1);
                for (i = 1; i < 20; i++){
                    cout << endl;
                }
                break;

            case 3:
                do {
                    cout << "Sebelum itu pastikan data toko dan data barangnya sudah kamu input ya ^-^" << endl;
                    cout << "Masukkan ID toko yang ingin ditambahkan barang: ";
                    cin >> IDtoko;
                    cout << "Masukkan ID barang yang akan ditambahkan ke toko: ";
                    cin >> IDbarang;

                    P = findToko(LT, IDtoko);
                    Q = findBarang(LB, IDbarang);

                    if (P != NULL && Q != NULL) {
                        insertRelasi(LT, P, Q, r);
                        cout << "Data berhasil disimpan ^-^" << endl;
                    } else {
                        cout << "ID toko atau barang tidak valid. Mohon cek kembali data toko dan data barang." << endl;
                    }

                    cout << "==========================" << endl;
                    cout << "Masih ingin menambah data barang dalam toko? " << endl;
                    cout << "1. Iya" << endl;
                    cout << "2. Kembali ke menu" << endl;
                    cout << "Silahkan ketik nomor yang ingin anda pilih ^_^ : ";
                    cin >> masukan;
                } while (masukan == 1);
                for (i = 1; i < 20; i++){
                    cout << endl;
                }
                break;

            case 4:
                cout << "Data apa yang ingin anda hapus?" << endl;
                cout << "1. Data toko" << endl;
                cout << "2. Data barang" << endl;
                cout << "3. Data barang yang dijual di sebuah toko" << endl;
                cout << "4. Kembali ke menu utama" << endl;
                cout << "Silahkan masukkan nomor yang ingin anda pilih ^-^: ";
                cin >> masukan;

                switch (masukan) {
                    case 1:
                        do {
                            cout << endl;
                            showData(LT);
                            cout << endl;
                            cout << "Masukkan ID toko yang ingin anda hapus (atau masukkan 0 untuk kembali ke menu utama): ";
                            cin >> IDtoko;

                            if (IDtoko != 0) {
                                P = findToko(LT, IDtoko);

                                if (P != Nil) {
                                    deleteToko(LT, P);
                                    cout << "==== Data berhasil dihapus ^-^ ====" << endl;
                                } else {
                                    cout << "Toko tidak ditemukan. Silakan coba lagi." << endl;
                                }
                            }

                        } while (IDtoko != 0 && P == Nil);
                        break;

                    case 2:
                        do {
                            showsemuabarang(LB);
                            cout << "Masukkan ID barang yang ingin anda hapus (atau masukkan 0 untuk kembali ke menu utama): ";
                            cin >> IDbarang;

                            if (IDbarang != 0) {
                                Q = findBarang(LB, IDbarang);

                                if (Q != Nil) {
                                    P = first(LT);
                                    while (P != Nil){
                                        deleteRelasi(LT, P, r, info(Q).ID);
                                        P = next(P);
                                    }
                                    deleteBarangYangDiList(LB, Q);
                                    cout << "==== Data berhasil dihapus ^-^ ====" << endl;
                                    cout << endl;
                                } else {
                                    cout << "Barang tidak ditemukan. Silakan coba lagi." << endl;
                                }
                            }

                        } while (IDbarang != 0 && Q == Nil);
                        break;

                    case 3:
                        do {
                            cout << endl;
                            showData(LT);
                            cout << endl;
                            cout << "Masukkan ID toko yang ingin anda hapus (atau masukkan 0 untuk kembali ke menu utama): ";
                            cin >> IDtoko;

                            if (IDtoko != 0) {
                                P = findToko(LT, IDtoko);

                                if (P != Nil) {
                                    cout << "Masukkan ID barang yang dijual toko tersebut dan ingin anda hapus: ";
                                    cin >> IDbarang;
                                    r = findRelasi(LT, P, IDbarang);

                                    if (r != Nil) {
                                        deleteRelasi(LT, P, r, IDbarang);
                                        cout << "==== Data berhasil dihapus ^-^ ====" << endl;
                                    } else {
                                        cout << "Barang tidak ditemukan di toko tersebut. Silakan coba lagi." << endl;
                                    }
                                } else {
                                    cout << "Toko tidak ditemukan. Silakan coba lagi." << endl;
                                }
                            }

                        } while (IDtoko != 0 || r == Nil);
                        break;

                    case 4:
                        break;

                    default:
                        cout << "Pilihan tidak valid" << endl;
                        cout << "Silahkan masukkan nomor yang ingin anda pilih ^-^: ";
                        cin >> masukan;
                        cout << endl;
                }
                for (i = 1; i < 20; i++){
                    cout << endl;
                }
                break;

            case 5:
                for (i = 1; i < 20; i++){
                    cout << endl;
                }
                cout << "Berikut semua list toko beserta barang yang dijual" << endl;
                cout << "===================================================" << endl;
                showData(LT);
                cout << endl;
                break;

            case 6:
                for (i = 1; i < 20; i++){
                    cout << endl;
                }
                showsemuabarang(LB);
                cout << "Dari semua barang di atas, barang mana yang ingin anda cari?" << endl;
                cout << "Silahkan masukkan nomor id barang yang ingin anda cari: ";
                cin >> IDbarang;
                Q = findBarang(LB, IDbarang);
                if (Q != NULL) {
                    cout << endl;
                    cout << "Berikut toko-toko yang menjual barang tersebut" << endl;
                    showTokoDari_Barang(LT, IDbarang);
                } else {
                    cout << endl;
                    cout << "Tidak ada toko yang memiliki barang dengan ID tersebut" << endl;
                }
                cout << endl;
                break;

            case 7:
                for (i = 1; i < 20; i++){
                    cout << endl;
                }
                showToko_PalingLengkap(LT);
                break;

            case 8:
                for (i = 1; i < 20; i++){
                    cout << endl;
                }
                showToko_PalingTidakLengkap(LT);
                break;

            default:
                if (masukan != 9) {
                    cout << "Pilihan tidak valid" << endl;
                }
        }

    } while (masukan != 9);
    cout << endl;
    cout << "Terima kasih telah menggunakan aplikasi ini ^_^";
    cout << endl;

    return 0;
}
