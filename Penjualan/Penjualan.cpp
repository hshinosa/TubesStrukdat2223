#include "Penjualan.h"

void createList_Toko(ListToko &LT){
    first(LT) = Nil;
}
void createList_Barang(ListBarang &LB){
    first(LB) = Nil;
}

address_Toko createElmToko(infotypeToko InfoToko){
    address_Toko P = new ElmToko;
    info(P) = InfoToko;
    next(P) = Nil;
    nextAnak(P) = Nil;

    return P;
}
address_Barang createElmBarang(infotypeBarang InfoBarang){
    address_Barang P = new ElmBarang;
    info(P) = InfoBarang;
    next(P) = Nil;

    return P;
}

address_Relasi createElmRelasi(){
    address_Relasi R = new ElmRelasi;
    nextRelasi(R) = Nil;
    InfoB(R) = Nil;
    return R;
}

void insertToko(ListToko &LT, address_Toko P){
    if (first(LT) == Nil) {
        first(LT) = P;
    } else {
        address_Toko Q = first(LT);
        while (next(Q) != Nil){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void insertBarang(ListBarang &LB, address_Barang P){
    if (first(LB) == Nil) {
        first(LB) = P;
    } else {
        next(P) = first(LB);
        first(LB) = P;
    }
}

void insertRelasi(ListToko &LT, address_Toko P, address_Barang B, address_Relasi R){
    R = createElmRelasi();
    if (nextAnak(P) == Nil){
        nextAnak(P) = R;
        InfoB(R) = B;
    } else {
        address_Relasi Q = nextAnak(P);
        while (nextRelasi(Q) != Nil){
            Q = nextRelasi(Q);
        }
        nextRelasi(Q) = R;
        InfoB(R) = B;
    }
}

void deleteToko(ListToko &LT, address_Toko &P){
    address_Toko Q = first(LT);
    P = Q;
    while (next(P) != Nil){
        Q = P;
        next(P) = P;
    }
    next(Q) = Nil;
}

void deleteBarang(ListBarang &LB, address_Barang &P){
    first(LB) = next(P);
    next(P) = Nil;
}

void deleteRelasi(ListToko &LT, address_Toko P, address_Relasi R, int ID){
    R = findRelasi(LT, P, ID);
    if (R != Nil){
        if (nextAnak(P) == R){
            nextAnak(P) == nextRelasi(R);
            nextRelasi(R) = Nil;
        } else if (nextRelasi(R) == Nil){
            address_Relasi Q = nextAnak(P);
            while (nextRelasi(Q) != R){
                Q = nextRelasi(Q);
            }
            nextRelasi(Q) = Nil;
        } else {
            address_Relasi Prec = nextAnak(P);
            while (nextRelasi(Prec) != R){
                Prec = nextRelasi(Prec);
            }
            nextRelasi(Prec) = nextRelasi(R);
            nextRelasi(R) = Nil;
        }
    }
}

address_Toko findToko(ListToko LT, int ID){
    address_Toko P = first(LT);
    while (P != Nil && info(P).ID != ID) {
        P = next(P);
    }
    return P;
}

address_Barang findBarang(ListBarang LB, int ID){
    address_Barang P = first(LB);
    while (P != Nil && info(P).ID != ID) {
        P = next(P);
    }
    return P;
}

address_Relasi findRelasi(ListToko LT, address_Toko P, int ID){
    address_Relasi R = nextAnak(P);
    while (R != Nil && info(InfoB(R)).ID != ID){
        R = nextRelasi(R);
    }
    return R;
}

void showData(ListToko LT){
  address_Toko P;
  address_Relasi Q;

  if (first(LT) == Nil){
      cout << "Tidak ada toko yang terdaftar" << endl;
  } else{
      P = first(LT);
      while (P != Nil) {
          cout << endl;
          cout << "ID Toko: " << info(P).ID << endl;
          cout << "Nama Toko: " << info(P).Nama << endl;
          cout << "Lokasi Toko: " << info(P).Lokasi << endl;
          cout << endl;
          Q = nextAnak(P);
          if (Q == Nil){
              cout << "Tidak ada barang di toko" << endl;
          } else {
              while (Q != Nil){
                  cout << "Isi barang di toko: " << info(P).Nama << endl;
                  cout << "ID Barang: " << info(InfoB(Q)).ID << endl;
                  cout << "Nama Barang: " << info(InfoB(Q)).NamaBarang << endl;
                  cout << "Harga Barang: " << info(InfoB(Q)).Harga << endl;
                  cout << endl;
                  Q = nextRelasi(Q);
              }
          }
          cout << endl;
          P = next(P);
      }
  }
}

void showBarangDari_Toko(ListToko LT, int IDToko){
    address_Toko p = first(LT);
    address_Relasi relasi = nextAnak(p);

    while (p != NULL) {
      while (relasi != NULL) {
        cout << "ID barang: " << info(InfoB(relasi)).ID << endl;
        cout << "Nama barang: " << info(InfoB(relasi)).NamaBarang << endl;
        cout << "Harga Barang: " << info(InfoB(relasi)).Harga << endl;

        cout << endl;
        relasi = nextRelasi(relasi);
      }
      p = next(p);
    }
}

void showTokoDari_Barang(ListToko LT, int IDBarang){
  address_Toko p = first(LT);
  address_Relasi relasi = nextAnak(p);

  while (p != NULL) {
    while (relasi != NULL) {
      if (IDBarang == info(InfoB(relasi)).ID){
        cout << "ID Toko: " << info(p).ID << endl;
        cout << "Nama Toko: " << info(p).Nama << endl;
        cout << "Lokasi Toko: " << info(p).Lokasi << endl;
      }
      relasi = nextRelasi(relasi);
    }
    p = next(p);
  }
}

int HitungBarangBerdasarkan_Toko(ListToko LT, int IDToko){
  address_Toko p = first(LT);
  address_Relasi relasi = nextAnak(p);
  int jumlah = 0;

  while (p != NULL && info(p).ID != IDToko) {
    p = next(p);
  }

  if (info(p).ID == IDToko){
    while (relasi != NULL) {
      jumlah++;
      relasi = nextRelasi(relasi);
    }
  }
  return jumlah;
}

void showToko_PalingLengkap(ListToko LT){
  address_Toko p = first(LT);
  address_Toko alamat = p;
  int terlengkap = HitungBarangBerdasarkan_Toko(LT,info(p).ID);

  while (p != NULL) {
    p = next(p);
    if (terlengkap < HitungBarangBerdasarkan_Toko(LT,info(p).ID)){
      terlengkap = HitungBarangBerdasarkan_Toko(LT,info(p).ID);
      alamat = p;
    }
  }
  cout << "toko paling lengkap adalah toko " << info(alamat).Nama << endl;
  cout << "dengan jumlah barang yaitu " << terlengkap << endl;
}

void showToko_PalingTidakLengkap(ListToko LT){
  address_Toko p = first(LT);
  address_Toko alamat = p;
  int tersedikit = HitungBarangBerdasarkan_Toko(LT,info(p).ID);
  while (p != NULL) {
    p = next(p);
    if (tersedikit > HitungBarangBerdasarkan_Toko(LT,info(p).ID)){
      tersedikit = HitungBarangBerdasarkan_Toko(LT,info(p).ID);
      alamat = p;
    }
  }
  cout << "toko paling tidak lengkap adalah toko " << info(alamat).Nama << endl;
  cout << "dengan jumlah barang yaitu " << tersedikit << endl;
}
