#include "header.h"


int main() {
    int n = 0, nMK = 0, nNilai = 0, running = 1;
    mahasiswa dataMhs[100];
    mataKuliah dataMk[100];
    nilai dataNilai[100];
    char query[500];
    
    // TAMBAH INI - load data dari file saat startup
    readFileNameMhs(&n, dataMhs, "../data/mahasiswa.dat");
    readFileNameMk(&nMK, dataMk, "../data/mataKuliah.dat");
    readFileNameNilai(&nNilai, dataNilai, "../data/nilai.dat");

    banner();
    desc();
    do {
        printf(">>> ");
        fgets(query, sizeof(query), stdin);
        
        // hapus newline dari fgets
        query[strcspn(query, "\n")] = 0;
        
        // proses input
        parseInput(query, &n, &nMK, &nNilai, dataMhs, dataMk, dataNilai, &running);
        
    } while (running != 0);
    
    return 0;
}
