//Nama  : Ananda Rachmawati Purwanto
//NIM   : 24060123130061
//Lab   : A1


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define IdxMax 100
#define IdxMin 1
#define JamMax 23
#define JamMin 0
#define MntMax 59
#define MntMin 0

typedef struct {
    int Jam; // Jam 0-23
    int Mnt; // Menit 0-59
}WAKTU;

typedef struct {
    int   NoKrt[IdxMax + 1]; // Nomor kereta, nOkRT untuk penomoran kereta secara dinamis, No untuk searching NoKrt
    char  KtBrk[IdxMax + 1][20]; // Kota berangkat, maks 19 huruf termasuk spasi
    char  KtTuj[IdxMax + 1][20]; // Kota tujuan
    WAKTU JmBrk[IdxMax + 1]; // Jam berangkat
    WAKTU JmDtg[IdxMax + 1]; // Jam kedatangan
    int   Tarif[IdxMax + 1]; // Harga tiket dalam rupiah
    int   N; // Index efektif tabel kereta
}KERETA;

/***********************************************OPERATOR********************************************/
// FIX!!!
void BinSearchNoKereta(KERETA* T, int No, bool *Found, int *IX){
    //Kamus Lokal
    int Atas, Bawah, Tengah;
    //Algoritma
    Atas = 1; Bawah = (*T).N, *Found = false;
    while(Atas <= Bawah && *Found != true){
        Tengah=(Atas+Bawah)/2;
        if(No == (*T).NoKrt[Tengah]){
            *Found = true;
            *IX = Tengah;
        }
        else if(No < (*T).NoKrt[Tengah]){
            Bawah = Tengah - 1;
        }
        else{
            Atas = Tengah + 1;
        }
    }
}

/******************************************Menu Administrator***************************************/
// 1 FIX!!!
void InisialisasiTabelKERETA(KERETA* T){
    //Kamus Lokal
    //ALgoritma
    (*T).N = 0; // Insialisasi banyak kereta, awalnya tidak ada kereta sama sekali
}
// 2 ONWORK!!!
void AddKERETA(KERETA* T, int* nOkRT){
    //Kamus Lokal
    //Algoritma
    // Jika banyak keretanya < 100, maka masih bisa menambahkan kereta baru
    if((*T).N < IdxMax){
        (*T).N++;
        (*nOkRT)++;
        (*T).NoKrt[(*T).N] = *nOkRT;
        printf(">_< Kota berangkat: "); scanf (" %s",&(*T).KtBrk[(*T).N]);
        printf(">_< Kota tujuan: ");    scanf ("%s", &(*T).KtTuj[(*T).N]);
        printf(">_< Jam berangkat: ");  scanf (" %d",&(*T).JmBrk[(*T).N].Jam);
        printf(">_< Menit: "); scanf ("%d", &(*T).JmBrk[(*T).N].Mnt);
        printf(">_< Jam kedatangan: "); scanf ("%d", &(*T).JmDtg[(*T).N].Jam);
        printf(">_< Menit: "); scanf ("%d", &(*T).JmDtg[(*T).N].Mnt);
        printf(">_< Tarif: ");          scanf ("%d", &(*T).Tarif[(*T).N]);
        printf(">_< Menambahkan jadwal kereta.................\n");
        printf(">_< Telah ditambahkan jadwal kereta:\nNo %d, Kota Berangkat: %s, Kota Tujuan: %s, Jam Berangkat: %02d:%02d, Jam Tiba: %02d:%02d, Tarif: %d\n",
            T->NoKrt[(*T).N], T->KtBrk[(*T).N], T->KtTuj[(*T).N], T->JmBrk[(*T).N].Jam, T->JmBrk[(*T).N].Mnt, T->JmDtg[(*T).N].Jam, T->JmDtg[(*T).N].Mnt, T->Tarif[(*T).N]);
    }
    else{
        printf(">_< Tabel jadwal kereta penuh!\n");
    }
}
// 3 ONWORK
void DelKERETA(KERETA* T, int No){
    //Kamus Lokal
    int  i, IX;
    bool Found;
    //Algoritma
    BinSearchNoKereta(T,No,&Found,&IX);
    if(Found){
        T->N--;
        for(i = IX; i <= T->N; i++){
            T->NoKrt[i] = T->NoKrt[i + 1];
            strcpy(T->KtBrk[i], T->KtBrk[i + 1]);
            strcpy(T->KtTuj[i], T->KtTuj[i + 1]);
            T->JmBrk[i] = T->JmBrk[i + 1];
            T->JmDtg[i] = T->JmDtg[i + 1];
            T->Tarif[i] = T->Tarif[i + 1];
            printf(">_< Kereta dengan nomor %d telah dihapus\n", No);
        }
    }
    else{
        printf(">_< Kereta dengan nomor %d tidak ada\n", No);
    }

}
// 4 ONWORK!!!
void GantiJadwalKERETA(KERETA* T, int No){
    //Kamus Lokal
    int  IX;
    bool Found;
    //Algoritma
    BinSearchNoKereta(T,No,&Found,&IX);
    if(Found){
        printf(">_< Jadwal lama: %02d:%02d - %02d:%02d\n",
            T->JmBrk[IX].Jam, T->JmBrk[IX].Mnt, T->JmDtg[IX].Jam, T->JmDtg[IX].Mnt);
        printf(">_< Jadwal baru:\nJam berangkat: ");
        scanf (" %d", &(*T).JmBrk[IX].Jam);
        printf("Menit: ");
        scanf ("%d", &(*T).JmBrk[IX].Mnt);
        printf("Jam kedatangan: ");
        scanf ("%d", &(*T).JmDtg[IX].Jam);
        printf("Menit: ");
        scanf ("%d", &(*T).JmDtg[IX].Mnt);
        printf(">_< Jadwal baru: %02d:%02d - %02d:%02d\n",
            T->JmBrk[IX].Jam, T->JmBrk[IX].Mnt, T->JmDtg[IX].Jam, T->JmDtg[IX].Mnt);
    }
    else{
        printf(">_< Kereta dengan nomor %d tidak ada\n", No);
    }
}

/*********************************************Menu Pengguna*****************************************/
// 1 ONWORK
// Tujuannya KotaX, outputnya No kereta & biayanya
void TujuanX(KERETA* T){
    //Kamus Lokal
    char KotaX[20];
    int i;
    //Algoritma
    printf("@_@ Masukkan kota: ");
    scanf (" %s", &KotaX);
    printf("Menampilkan semua kereta yang tujuannya %s dan biayanya\n", KotaX);
    for(i = IdxMin; i <= T->N; i++){
        if (strcmp(T->KtTuj[i], KotaX) == 0){
            printf("Kereta No %d, biaya: %d\n", T->NoKrt[i], T->Tarif[i]);
        }
    }
}
// 2 ONWORK, output kurang
// Berangkat sebelum pukul Y, output kereta
void BerangkatSebelumJamY(KERETA* T){
    //Kamus Lokal
    int   i;
    WAKTU JamY;
    //Algoritma
    printf("@_@ Masukkan pukul:\nJam: ");
    scanf (" %d",&JamY.Jam);
    printf("Menit: ");
    scanf ("%d", &JamY.Mnt);
    printf("Menampilkan semua kereta yang berangkat sebelum jam %02d:%02d\n", JamY.Jam, JamY.Mnt);
    for(i = IdxMin; i <= T->N; i++){
        if (T->JmBrk[i].Jam < JamY.Jam || (T->JmBrk[i].Jam == JamY.Jam && T->JmBrk[i].Mnt < JamY.Mnt)){
            printf("Kereta No %d, Kota Berangkat: %s, Kota Tujuan: %s, Jam Berangkat: %02d:%02d\n",
                T->NoKrt[i], T->KtBrk[i], T->KtTuj[i], T->JmBrk[i].Jam, T->JmBrk[i].Mnt);
        }
    }
}
// 3 ONWORK
// Berangkat KotaX menuju KotaY, output kereta & jam berangkat
void DariKotaXkeKotaY(KERETA* T){
    //Kamus Lokal
    int  i;
    char KotaX[20], KotaY[20];
    //Algoritma
    printf("@_@ Masukkan kota berangkat: ");
    scanf (" %s",&KotaX);
    printf("@_@ Masukkan kota tujuan: ");
    scanf ("%s", &KotaY);
    printf("Menampilkan semua kereta yang berangkat dari kota %s menuju kota %s\n", KotaX, KotaY);
    for (i = IdxMin; i <= T->N; i++){
        if (strcmp(T->KtBrk[i], KotaX) == 0 && strcmp(T->KtTuj[i], KotaY) == 0){
            printf("Kereta No %d, Jam Berangkat: %02d:%02d\n", T->NoKrt[i], T->JmBrk[i].Jam, T->JmBrk[i].Mnt);
        }
    }
}
// 4 ONWORK, output kurang
// Kereta pertama berangkat sebelum jam 9 dari kota X, output kereta
void Kereta1stBerangkatSebelumJam9DariKotaX(KERETA* T){
    //Kamus
    int   i;
    WAKTU earliest = {JamMax, MntMax}; // Set to max possible time
    int   I1st = 0; // Index letak kereta tercepat, ada kemungkinan tidak ada jadi harus diinisialisasi
    char  KotaX[20];
    //Algoritma
    printf("@_@ Masukkan kota berangkat: ");
    scanf (" %s", &KotaX);
    for(i = IdxMin; i <= T->N; i++){
        if(T->JmBrk[i].Jam < 9 && strcmp(T->KtBrk[i], KotaX) == 0){
            if(T->JmBrk[i].Jam < earliest.Jam || (T->JmBrk[i].Jam == earliest.Jam && T->JmBrk[i].Mnt < earliest.Mnt)){
                earliest = T->JmBrk[i];
                I1st = i;
            }
        }
    }
    if(I1st != 0){
        printf("Kereta pertama yang berangkat sebelum jam 9 dari kota %s: No kereta %d, Jam Berangkat: %02d:%02d\n",
            KotaX, T->NoKrt[I1st], earliest.Jam, earliest.Mnt);
    }
    else{
        printf("Tidak ada kereta yang berangkat sebelum jam 9 dari kota %s.\n", KotaX);
    }
}
// 5 ONWORK, output kurang
// Kereta terakhir dari kota X ke kota Y, output kereta
void KeretaLastDariKotaXkeKotaY(KERETA* T){
    //Kamus Lokal
    int   i;
    WAKTU latest = {JamMin, MntMin}; // Set to min possible time
    int   ILast = 0;
    char  KotaX[20], KotaY[20];
    //Algoritma
    printf("@_@ Masukkan kota berangkat: ");
    scanf (" %s",&KotaX);
    printf("@_@ Masukkan kota tujuan: ");
    scanf ("%s", &KotaY);
    printf("Mencari kereta pertama yang berangkat dari kota %s menuju kota %s\n", KotaX, KotaY);
    for(i = IdxMin; i <= T->N; i++){
        if(strcmp(T->KtTuj[i], KotaX) == 0 && strcmp(T->KtBrk[i], KotaY) == 0){
            if(T->JmBrk[i].Jam > latest.Jam || (T->JmBrk[i].Jam == latest.Jam && T->JmBrk[i].Mnt > latest.Mnt)){
                latest = T->JmBrk[i];
                ILast = i;
            }
        }
    }
    if(ILast != 0){
        printf("Kereta terakhir yang berangkat dari kota %s ke kota %s: No kereta %d, Jam Berangkat: %02d:%02d\n",
            KotaY, KotaX, T->NoKrt[ILast], latest.Jam, latest.Mnt);
    }
    else{
        printf("Tidak ada kereta yang berangkat dari kota %s ke kota %s.\n", KotaY, KotaX);
    }
}
// 6 ONWORK, output kurang
// Kereta termahal & termurah dari kota X ke kota Y
void TermahalTermurahDariXkeY(KERETA* T){
    //Kamus Lokal
    int i;
    int BMax = 0, BMin = 1000000;
    int IBMax = 0, IBMin = 0;
    char KotaX[20], KotaY[20];
    //Algoritma
    printf("@_@ Masukkan kota berangkat: ");
    scanf (" %s",&KotaX);
    printf("@_@ Masukkan kota tujuan: ");
    scanf ("%s", &KotaY);
    printf("Mencari kereta termahal & termurah yang berangkat dari kota %s menuju kota %s\n", KotaX, KotaY);
    for(i = IdxMin; i <= T->N; i++){
        if(strcmp(T->KtBrk[i], KotaX) == 0 && strcmp(T->KtTuj[i], KotaY) == 0){
            if(T->Tarif[i] > BMax){
                BMax = T->Tarif[i];
                IBMax = i;
            }
            if(T->Tarif[i] < BMin){
                BMin = T->Tarif[i];
                IBMin = i;
            }
        }
    }

    if(IBMax != 0){
        printf("Kereta termahal: %d, Tarif: %d\n", T->NoKrt[IBMax], BMax);
    }
    else{
        printf("Tidak ada kereta yang berangkat dari kota %s ke kota %s\n", KotaX, KotaY);
    }

    if(IBMin != 0){
        printf("Kereta termurah: %d, Tarif: %d\n", T->NoKrt[IBMin], BMin);
    }
    else{
        printf("Tidak ada kereta yang berangkat dari kota %s ke kota %s\n", KotaX, KotaY);
    }
}
// 7 ONWORK, output kurang
// Tercepat dari Kota X ke Kota Y, output kereta
void TercepatDariXkeY(KERETA* T){
    // Kamus Lokal
    int  i, MinTime = 0, duration, IKereta = 0;; // Dalam menit
    char KotaX[20], KotaY[20];
    // Algoritma
    printf("@_@ Masukkan kota berangkat: ");
    scanf (" %s",&KotaX);
    printf("@_@ Masukkan kota tujuan: ");
    scanf ("%s", &KotaY);
    printf("Mencari kereta tercepat..............\n");
    for(i = IdxMin; i < T->N; i++){
        if(strcmp(T->KtBrk[i], KotaX) == 0 && strcmp(T->KtTuj[i], KotaY) == 0){
            duration = (T->JmDtg[i].Jam - T->JmBrk[i].Jam) * 60 + (T->JmDtg[i].Mnt - T->JmBrk[i].Mnt);
            if(duration < MinTime){
                MinTime = duration;
                IKereta = i;
            }
        }
    }
    if(IKereta != 0){
        printf("Kereta tercepat dari kota %s ke kota %s: %d, Durasi: %d menit\n", KotaX, KotaY, T->NoKrt[IKereta], MinTime);
    }
    else{
        printf("Tidak ada kereta yang berangkat dari kota %s ke kota %s.\n", KotaX, KotaY);
    }
}
// 8 ONWORK
//
void DariXkeYBerangkatJam7sd12(KERETA* T){
    // Kamus Lokal
    int  i;
    char KotaX[20], KotaY[20];
    // Algoritma
    printf("@_@ Masukkan kota berangkat: ");
    scanf (" %s",&KotaX);
    printf("@_@ Masukkan kota tujuan: ");
    scanf ("%s", &KotaY);
    printf("Menampilkan kereta yang memenuhi..............\n");
    for(i = IdxMin; i <= T->N; i++){
        if(strcmp(T->KtBrk[i], KotaX) == 0 && strcmp(T->KtTuj[i], KotaY) == 0 && T->JmBrk[i].Jam >= 7 && T->JmBrk[i].Jam < 12) {
            printf("Kereta %d, Kota Berangkat: %s, Kota Tujuan: %s, Jam Berangkat: %02d:%02d\n",
                T->NoKrt[i], T->KtBrk[i], T->KtTuj[i], T->JmBrk[i].Jam, T->JmBrk[i].Mnt);
        }
    }
}
// 9 ONWORK
// Berangkat dari kota Z ke kota Y
void DariZkeYSebelumJam18(KERETA* T){
    // Kamus Lokal
    int i;
    char KotaZ[20], KotaY[20];
    // Algoritma
    printf("@_@ Masukkan kota berangkat: ");
    scanf (" %s",&KotaZ);
    printf("@_@ Masukkan kota tujuan: ");
    scanf ("%s", &KotaY);
    printf("Menampilkan kereta yang memenuhi..............\n");
    for(i = IdxMin; i <= T->N; i++){
        if(strcmp(T->KtTuj[i], KotaY) == 0 && strcmp(T->KtBrk[i], KotaZ) == 0 && T->JmDtg[i].Jam < 18) {
            printf("Kereta %d, Kota Berangkat: %s, Kota Tujuan: %s, Jam Tiba: %02d:%02d\n",
                T->NoKrt[i], T->KtBrk[i], T->KtTuj[i], T->JmDtg[i].Jam, T->JmDtg[i].Mnt);
        }
    }
}
// 10 ONWORK
// Routing
bool CompareWaktu(WAKTU a, WAKTU b){
    // Kamus Lokal
    // Algoritma
    return (a.Jam < b.Jam || (a.Jam == b.Jam && a.Mnt < b.Mnt));
}

void PrintRoute(KERETA* T, int* route, int routesize){
    // Kamus Lokal
    // Algoritma
    printf("Rute ditemukan:\n");
    for (int i = 0; i < routesize ; i++){
        int idx = route[i];
        printf("Kereta %d: %s -> %s, Berangkat: %02d:%02d, Tiba: %02d:%02d\n",
               T->NoKrt[idx], T->KtBrk[idx], T->KtTuj[idx],
               T->JmBrk[idx].Jam, T->JmBrk[idx].Mnt,
               T->JmDtg[idx].Jam, T->JmDtg[idx].Mnt);
    }
    printf("\n");
}

void FindAllRoutes(KERETA* T, char* KotaX, char* KotaY, int* route, int routesize, bool* visited, WAKTU Kedatangan){
    // Kamus Lokal
    int i;
    // Algoritma
    // Jika kota saat ini adalah kota tujuan, cetak rute
    if(strcmp(KotaX, KotaY) == 0){
        PrintRoute(T, route, routesize);
        return;
    }
    // Cari semua kereta yang berangkat dari kota saat ini
    for(i = IdxMin; i <= T->N; i++){
        if(strcmp(T->KtBrk[i], KotaX) == 0 && !visited[i] && CompareWaktu(Kedatangan, T->JmBrk[i])){
            // CompareWaktu(Kedatangan, T->JmBrk[i]) = (Kedatangan.Jam < T->JmBrk[i].Jam || Kedatangan.Jam == T->JmBrk[i].Jam && Kedatangan.Mnt < T->JmBrk[i].Mnt)
            // Tandai kereta sebagai bagian dari rute dan sebagai sudah dikunjungi
            route[routesize] = i;
            visited[i] = true;
            routesize++;
            // Rekursi untuk kota berikutnya dalam rute
            FindAllRoutes(T, T->KtTuj[i], KotaY, route, routesize, visited, T->JmDtg[i]);
            // Batalkan penandaan (backtrack)
            routesize--;
            visited[i] = false;
        }
    }
}

void DariXkeYRouting(KERETA* T){
    // Kamus Lokal
    char  KotaX[20], KotaY[20];
    int   route[IdxMax + 1], routesize = 0;
    bool  visited[IdxMax + 1] = {false};
    WAKTU initialTime = {JamMin, MntMin}; // Awal waktu dari kota keberangkatan

    // Algoritma
    printf("@_@ Masukkan kota berangkat: ");
    scanf("%s", KotaX);
    printf("@_@ Masukkan kota tujuan: ");
    scanf("%s", KotaY);

    printf("Mencari semua rute dari kota %s ke kota %s...\n", KotaX, KotaY);

    FindAllRoutes(T, KotaX, KotaY, route, routesize, visited, initialTime);
}
// 11
void KeretaAgenPerjalanan(KERETA* T){
    //Kamus Lokal
    int i;
    //Algoritma
    for (i = IdxMin; i <= T->N; i++) {
        printf("Kereta %d, Kota Berangkat: %s, Kota Tujuan: %s, Jam Berangkat: %02d:%02d, Jam Tiba: %02d:%02d, Tarif: %d\n",
               T->NoKrt[i], T->KtBrk[i], T->KtTuj[i], T->JmBrk[i].Jam, T->JmBrk[i].Mnt, T->JmDtg[i].Jam, T->JmDtg[i].Mnt, T->Tarif[i]);
    }
}

/******************************************Menu Administrator***************************************/
// 5 ONWORK
void InfoKERETA(KERETA* T){
    //Kamus Lokal
    char  Menu[20];
    //Algoritma
    printf("************************************Pilihan Menu**************************************\n");
    printf("1   Semua kereta api yang kota tujuannya adalah kota X dan biayanya\n");
    printf("2   Semua kereta api yang berangkat sebelum jam Y\n");
    printf("3   Semua kereta api dan jam berangkatnya, dari kota X menuju kota Y\n");
    printf("4   Kereta api pertama yang berangkat sebelum jam 9 pagi dari kota X\n");
    printf("5   Kereta api terakhir untuk menuju kota X dari kota Y\n");
    printf("6   Kereta termahal dan termurah untuk berangkat dari kota X menuju kota Y\n");
    printf("7   Kereta yang paling cepat sampai dari kota X ke kota Y\n");
    printf("8   Kereta api dari kota X menuju kota Y yang berangkat antara jam 7 pagi s/d 12 siang\n");
    printf("9   Kereta api yang tiba di kota Y dari kota Z sebelum jam 18.00\n");
    printf("10  Semua kereta api dari kota X untuk menuju kota Y\n");
    printf("11  Semua kereta api yang ada untuk dibuat agen perjalanan.\n");
    printf("Q   Keluar dari Menu\n");
    printf("**************************************************************************************\n");
    strcpy(Menu, "0"); // Inisialisasi Menu, pilihan 0 tidak ada di Menu
    while(strcmp(Menu, "Q") != 0){
        printf("@_@ Menu yang dipilih: ");
        scanf (" %s", &Menu);
        if     (strcmp(Menu, "1") == 0){
            printf("Menampilkan semua kereta api yang kota tujuannya adalah kota X dan biayanya\n");
            TujuanX(T);
        }
        else if(strcmp(Menu, "2") == 0){
            printf("Menampilkan semua kereta api yang berangkat sebelum jam Y\n");
            BerangkatSebelumJamY(T);
        }
        else if(strcmp(Menu, "3") == 0){
            printf("Menampilkan semua kereta api dan jam berangkatnya, dari kota X menuju kota Y\n");
            DariKotaXkeKotaY(T);
        }
        else if(strcmp(Menu, "4") == 0){
            printf("Menampilkan kereta api pertama yang berangkat sebelum jam 9 pagi dari kota X\n");
            Kereta1stBerangkatSebelumJam9DariKotaX(T);
        }
        else if(strcmp(Menu, "5") == 0){
            printf("Menampilkan ereta api terakhir untuk menuju kota X dari kota Y\n");
            KeretaLastDariKotaXkeKotaY(T);
        }
        else if(strcmp(Menu, "6") == 0){
            printf("Menampilkan kereta termahal dan termurah untuk berangkat dari kota X menuju kota Y\n");
            TermahalTermurahDariXkeY(T);
        }
        else if(strcmp(Menu, "7") == 0){
            printf("Menampilkan kereta yang paling cepat sampai dari kota X ke kota Y\n");
            TercepatDariXkeY(T);
        }
        else if(strcmp(Menu, "8") == 0){
            printf("Menampilkan semua kereta api dari kota X menuju kota Y yang berangkat antara jam 7 pagi s/d 12 siang\n");
            DariXkeYBerangkatJam7sd12(T);
        }
        else if(strcmp(Menu, "9") == 0){
            printf("Menampilkan kereta api yang tiba di kota Y dari kota Z sebelum jam 18.00\n");
            DariZkeYSebelumJam18(T);
        }
        else if(strcmp(Menu, "10") == 0){
            printf("Menampilkan semua rute kereta api dari kota X untuk menuju kota Y\n");
            DariXkeYRouting(T);
        }
        else if(strcmp(Menu, "11") == 0){
            printf("List semua jadwal kereta api:\n");
            KeretaAgenPerjalanan(T);
        }
        else if(strcmp(Menu, "Q") == 0){
            printf("Keluar dari Menu Pengguna\n");
        }
        else{
            printf("Tidak ada pilihan menu %s\n", Menu);
        }
    }
}
// Prosedur Tambahan
void MenuAdmin(KERETA* T, int* nOkRT){
    //Kamus Lokal
    char  Menu[20];
    int   No /*Untuk pencarian nomor kereta*/;
    //Algoritma
    printf("*****************************>_< Administrator Menu >_<*******************************\n");
    printf("No  *****************************>_< Deskripsi >_<************************************\n");
    printf("1   Menginisialisasi Tabel Jadwal Kereta Api\n");
    printf("2   Menambahkan sebuah nomor kereta baru dan semua atributnya\n");
    printf("3   Menghapus sebuah nomor kereta\n");
    printf("4   Mengganti jadwal sebuah nomor kereta\n");
    printf("5   Info kereta api\n");
    printf("Q   Keluar dari sistem\n");
    printf(">_<********************************************************************************>_<\n");
    strcpy(Menu, "0");
    while(strcmp(Menu, "Q") != 0){
        printf(">_< Menu yang dipilih: ");
        scanf (" %s", &Menu);
        if(strcmp(Menu, "1") == 0){
            printf(">_< Menginisialisasi Tabel Jadwal Kereta Api\n");
            InisialisasiTabelKERETA(T);
            printf(">_< Tabel Jadwal Kereta Api sudah diinisialisasi\n");
        }
        else if(strcmp(Menu, "2") == 0){
            printf(">_< Menambahkan sebuah nomor kereta baru dan semua atributnya\n");
            AddKERETA(T,nOkRT);
        }
        else if(strcmp(Menu, "3") == 0){
            printf(">_< Menghapus sebuah nomor jadwal kereta\n>_< No kereta yang akan dihapus: ");
            scanf (" %d", &No);
            DelKERETA(T,No);
        }
        else if(strcmp(Menu, "4") == 0){
            printf(">_< Mengganti jadwal kereta\n>_< No kereta yang akan diganti jadwalnya: ");
            scanf (" %d", &No);
            GantiJadwalKERETA(T,No);
        }
        else if(strcmp(Menu, "5") == 0){
            InfoKERETA(T);
            printf(">_< Kembali ke Menu Admin\n");
        }
        else if(strcmp(Menu, "Q") == 0){
            printf(">_< Keluar dari menu admin.............\n");
        }
        else{
            printf(">_< Tidakk ada pilihan menu %s\n", Menu);
        }
    }
}

/*********************************************Program Utama*****************************************/
int main(){
    //Kamus
    KERETA T;
    char   Password[10], TempPass[10]; // Password maksimal 9 digit termasuk spasi
    char   Menu = '0';
    int    nOkRT = 0; // Nomor kereta pertama = 1 dan nomor kereta selanjutnya akan bertambah
    //Algoritma
    strcpy(Password, "123456789");
    while(Menu != 'Q'){
        printf("Pilihan Menu:\n1 Pengguna\n2 Admin\nQ Matikan mesin\nMasukkan pilihan: ");
        scanf(" %c", &Menu);
        if     (Menu == '1'){
            InfoKERETA(&T);
        }
        else if(Menu == '2'){
            printf("Masukkan Password: ");
            scanf (" %s", &TempPass);
            if(strcmp(TempPass, Password) == 0){
                MenuAdmin(&T, &nOkRT);
            }
            else{
                printf("Password salah");
            }
        }
        else if(Menu == 'Q'){
            printf("Mematikan mesin.....");
        }
        else{
            printf("Tidak ada pilihan %c", Menu);
        }
    }
    return 0;
}
