#include "shoP.h"

void createList_Toko(ListToko &LT) {
    first(LT) = Nil;
}

void createList_Barang(ListBarang &LB) {
    first(LB) = Nil;
}

address_Toko createElmToko(infotypeToko InfoToko) {
    address_Toko P = new ElmToko;
    info(P) = InfoToko;
    next(P) = Nil;
    nextAnak(P) = Nil;

    return P;
}

address_Barang createElmBarang(infotypeBarang InfoBarang) {
    address_Barang P = new ElmBarang;
    info(P) = InfoBarang;
    next(P) = Nil;

    return P;
}

address_Relasi createElmRelasi() {
    address_Relasi R = new ElmRelasi;
    nextRelasi(R) = Nil;
    InfoB(R) = Nil;
    return R;
}

void insertToko(ListToko &LT, address_Toko P) {
    if (first(LT) == Nil) {
        first(LT) = P;
    } else {
        address_Toko Q = first(LT);
        while (next(Q) != Nil) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void insertBarang(ListBarang &LB, address_Barang P) {
    if (first(LB) == Nil) {
        first(LB) = P;
        last(LB) = P;
    } else {
        next(P) = first(LB);
        prev(first(LB)) = P;
        first(LB) = P;
    }
}

void insertRelasi(ListToko &LT, address_Toko P, address_Barang B, address_Relasi R) {
    R = createElmRelasi();
    if (nextAnak(P) == Nil) {
        nextAnak(P) = R;
        InfoB(R) = B;
    } else {
        address_Relasi Q = nextAnak(P);
        while (nextRelasi(Q) != Nil) {
            Q = nextRelasi(Q);
        }
        nextRelasi(Q) = R;
        InfoB(R) = B;
    }
}

void deleteToko(ListToko &LT, address_Toko &P) {
    if (first(LT) == Nil && P == Nil) {
        cout << "Tidak ada toko yang sesuai" << endl;
        return;
    }
    if (P == LT.first) {
        LT.first = P->next;
        P->next = NULL;
        delete P;
    } else {
        address_Toko Q = LT.first;
        if (P->next == NULL) {
            while (Q->next != P) {
                Q = Q->next;
            }
            Q->next = NULL;
            delete P;
        } else {
            Q = Q->next;
            while (Q != NULL && Q->next != P) {
                Q = Q->next;
            }
            if (Q != NULL) {
                Q->next = P->next;
                P->next = NULL;
                delete P;
            }
        }
    }
    cout << "==== data berhasil dihapus ^-^ ====" << endl;
}

void deleteBarangYangDiList(ListBarang &LB, address_Barang &P) {
    address_Barang Q;
    if (first(LB) == Nil && last(LB) == Nil && P == Nil) {
        cout << "Tidak ada barang yang sesuai" << endl;
        return;
    }
    if (P == first(LB) && P == last(LB)) {
        first(LB) = Nil;
        last(LB) = Nil;
    } else if (P == first(LB)) {
        first(LB) = next(P);
        prev(first(LB)) = Nil;
        next(P) = Nil;
    } else if (P == last(LB)) {
        Q = prev(P);
        last(LB) = Q;
        next(Q) = Nil;
        prev(P) = Nil;
    } else {
        Q = prev(P);
        next(Q) = next(P);
        prev(next(P)) = Q;
        next(P) = Nil;
        prev(P) = Nil;
    }
    cout << "==== data berhasil dihapus ^-^ ====" << endl;
}


void deleteRelasi(ListToko &LT, address_Toko P, address_Relasi &R, int ID) {
    R = findRelasi(LT, P, ID);
    if (R != Nil) {
        if (nextAnak(P) == R) {
            nextAnak(P) = nextRelasi(R);
            nextRelasi(R) = Nil;
            delete R;
        } else if (nextRelasi(R) == Nil) {
            address_Relasi Q = nextAnak(P);
            while (nextRelasi(Q) != R) {
                Q = nextRelasi(Q);
            }
            nextRelasi(Q) = Nil;
            delete R;
        } else {
            address_Relasi Prec = nextAnak(P);
            while (nextRelasi(Prec) != R) {
                Prec = nextRelasi(Prec);
            }
            nextRelasi(Prec) = nextRelasi(R);
            nextRelasi(R) = Nil;
            delete R;
        }
        cout << "==== Data berhasil dihapus ^-^ ====" << endl;
    } else {
        cout << "Relasi tidak ditemukan." << endl;
    }
}


address_Toko findToko(ListToko LT, int ID) {
    address_Toko P = first(LT);
    while (P != Nil && info(P).ID != ID) {
        P = next(P);
    }
    return P;
}

address_Barang findBarang(ListBarang LB, int ID) {
    address_Barang P = first(LB);
    while (P != Nil && info(P).ID != ID) {
        P = next(P);
    }
    return P;
}

address_Relasi findRelasi(ListToko LT, address_Toko P, int ID) {
    address_Relasi R = nextAnak(P);
    while (R != Nil && info(InfoB(R)).ID != ID) {
        R = nextRelasi(R);
    }
    return R;
}

void showData(ListToko LT) {
    address_Toko P;
    address_Relasi Q;

    if (first(LT) == Nil) {
        cout << "Tidak ada toko yang terdaftar" << endl;
    } else {
        P = first(LT);
        while (P != Nil) {
            cout << endl;
            cout << "ID Toko: " << info(P).ID << endl;
            cout << "Nama Toko: " << info(P).Nama << endl;
            cout << "Lokasi Toko: " << info(P).Lokasi << endl;
            cout << endl;
            Q = nextAnak(P);
            if (Q == Nil) {
                cout << "Tidak ada barang di toko " << info(P).Nama << endl << endl;
            } else {
                cout << "Isi barang di toko " << info(P).Nama << ":" << endl;
                while (Q != Nil) {
                    cout << "ID Barang: " << info(InfoB(Q)).ID << endl;
                    cout << "Nama Barang: " << info(InfoB(Q)).NamaBarang << endl;
                    cout << "Harga Barang: " << info(InfoB(Q)).Harga << endl;
                    cout << endl;
                    Q = nextRelasi(Q);
                }
            }
            P = next(P);
        }
    }
}

void showsemuabarang(ListBarang LB) {
    address_Barang P = first(LB);
    while (P != Nil) {
        cout << "ID Barang: " << info(P).ID << endl;
        cout << "Nama Barang: " << info(P).NamaBarang << endl;
        cout << "Harga: " << info(P).Harga << endl;
        cout << endl;

        if (P == last(LB)) {
            return;
        }
        P = next(P);
    }
}

void showBarangDari_Toko(ListToko LT, int IDToko) {
    address_Toko P = findToko(LT, IDToko);

    if (P != NULL) {
        address_Relasi R = nextAnak(P);

        while (R != NULL) {
            if (InfoB(R) != NULL){
                R = nextRelasi(R);
            }
            cout << "ID barang: " << info(InfoB(R)).ID << endl;
            cout << "Nama barang: " << info(InfoB(R)).NamaBarang << endl;
            cout << "Harga Barang: " << info(InfoB(R)).Harga << endl;

            cout << endl;
            R = nextRelasi(R);
        }
    }
}

void showTokoDari_Barang(ListToko LT, int IDBarang) {
    address_Toko P = first(LT);
    address_Relasi R;

    while (P != NULL) {
        R = nextAnak(P);

        while (R != NULL) {
            if (info(InfoB(R)).ID == IDBarang) {
                cout << "ID Toko: " << info(P).ID << endl;
                cout << "Nama Toko: " << info(P).Nama << endl;
                cout << "Lokasi Toko: " << info(P).Lokasi << endl;
            }
            R = nextRelasi(R);
        }
        P = next(P);
    }
}

int HitungBarangBerdasarkan_Toko(ListToko LT, address_Toko P) {
    address_Relasi R = nextAnak(P);
    int jumlah = 0;
    if (R == Nil) {
        return jumlah;
    } else {
        while (R != Nil) {
            jumlah++;
            R = nextRelasi(R);
        }
        return jumlah;
    }
}

void showToko_PalingLengkap(ListToko LT) {
    address_Toko P;
    address_Toko Q;
    address_Relasi R;
    int jumlahTerbesar = 0;
    int i;
    int temp;

    P = first(LT);

    while (P != Nil) {
        temp = HitungBarangBerdasarkan_Toko(LT, P);
        if (temp > jumlahTerbesar) {
            Q = P;
            jumlahTerbesar = temp;
        }
        P = next(P);
    }

    if (jumlahTerbesar > 0) {
        cout << "Toko dengan barang Paling lengkap yaitu Pada toko " << info(Q).Nama << " dengan jumlah barang " << jumlahTerbesar << endl;
        cout << "Barang - barang dari toko: " << info(Q).Nama << endl;

        R = nextAnak(Q);

        while (R != NULL) {
            cout << "Barang ke: " << i << endl;
            cout << "ID barang: " << info(InfoB(R)).ID << endl;
            cout << "Nama barang: " << info(InfoB(R)).NamaBarang << endl;
            cout << "Harga barang: " << info(InfoB(R)).Harga << endl;
            R = nextRelasi(R);
            i++;
            cout << endl;
        }
    } else {
        cout << "Tidak ada barang di toko manapun" << endl;
        cout << endl;
    }
}

void showToko_PalingTidakLengkap(ListToko LT) {
    address_Toko P;
    address_Toko Q;
    address_Relasi R;
    int jumlahTerkecil = HitungBarangBerdasarkan_Toko(LT,LT.first);
    int temp = 0;
    int i = 1;

    P = first(LT);

    while (P != Nil) {
        temp = HitungBarangBerdasarkan_Toko(LT, P);
        if (temp < jumlahTerkecil) {
            Q = P;
            jumlahTerkecil = temp;
        }
        P = next(P);
    }

    if (jumlahTerkecil > -1) {
        cout << endl;
        if (jumlahTerkecil == 0) {
            cout << "Toko dengan barang Paling sedikit yaitu Pada toko " << info(Q).Nama << " tidak memiliki barang sama sekali" << endl;
        } else {
            cout << "Toko dengan barang Paling sedikit yaitu Pada toko " << info(Q).Nama << " dengan jumlah barang " << jumlahTerkecil << endl;
            cout << "Barang - barang dari toko: " << info(Q).Nama << endl;

            R = nextAnak(Q);

            while (R != NULL) {
                cout << "Barang ke: " << i << endl;
                cout << "ID barang: " << info(InfoB(R)).ID << endl;
                cout << "Nama barang: " << info(InfoB(R)).NamaBarang << endl;
                cout << "Harga barang: " << info(InfoB(R)).Harga << endl;
                R = nextRelasi(R);
                i++;
                cout << endl;
            }
            cout << endl;
        }
    } else {
        cout << "Tidak ada barang di toko manapun" << endl;
        cout << endl;
    }
}

void menu(int &masukan) {
    cout << "Menu Utama" << endl;
    cout << endl;
    cout << "1. Tambah data toko" << endl;
    cout << "2. Tambah data barang" << endl;
    cout << "3. Tambah barang yang ada di toko" << endl;
    cout << "4. Hapus data" << endl;
    cout << "5. Tampilkan seluruh list toko beserta barang yang dijual" << endl;
    cout << "6. Tampilkan list toko yang menjual barang tertentu" << endl;
    cout << "7. Tampilkan data toko yang Paling lengkap barang yang dijual" << endl;
    cout << "8. Tampilkan data toko yang Paling sedikit barang yang dijual" << endl;
    cout << "9. Keluar dari aplikasi" << endl;
    cout << endl;
    cout << "Silahkan ketik nomor yang ingin anda pilih ^_^ : ";

    cin >> masukan;
}
