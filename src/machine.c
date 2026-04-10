#include "header.h"

// === PROSEDUR WRITE TO FILE ===
// Prosedur write to Mahasiswa.dat
void writeToFileNameMhs(int n, mahasiswa source[], char fileName[]){
    FILE *fTemp;
    fTemp = fopen(fileName, "w"); // Buka file dengan operator write to file
    
    if (fTemp == NULL){
        printf("Error: tidak bisa membuka file %s\n", fileName);
    return;
    }

    for(int i = 0; i < n; i++){
        fprintf(fTemp, "%s %s %s %s\n", source[i].nim, source[i].nama, source[i].idProdi, source[i].kodeMK); // write data ke dalam file
    }
    fprintf(fTemp, "%s %s %s %s\n", "####", "####", "####", "####"); // write data EOF setelah bikin data dalam file
    fclose(fTemp); // tutup file
}
// Prosedur write to MataKuliah.dat
void writeToFileNameMk(int n, mataKuliah source[], char fileName[]){
    FILE *fTemp;
    fTemp = fopen(fileName, "w"); // Buka file dengan operator write to file

    if (fTemp == NULL){
        printf("Error: tidak bisa membuka file %s\n", fileName);
    return;
    }
    for(int i = 0; i < n; i++){
        fprintf(fTemp, "%s %s %d\n", source[i].kode, source[i].namaMk, source[i].SKS); // write data ke dalam file
    }
    
    fprintf(fTemp, "%s %s %d\n", "####", "####", -999); // write data EOF setelah bikin data dalam file
    fclose(fTemp); // tutup file

}
// Prosedur write to Nilai.dat
void writeToFileNameNilai(int n, nilai source[], char fileName[]){
    FILE *fTemp;
    fTemp = fopen(fileName, "w"); // Buka file dengan operator write to file
    if (fTemp == NULL){
        printf("Error: tidak bisa membuka file %s\n", fileName);
    return;
    }

    for(int i = 0; i < n; i++){
        fprintf(fTemp, "%s %s %.2f %s\n", source[i].nim, source[i].kode, source[i].nilai, source[i].grade); // write data ke dalam file
    }

    fprintf(fTemp, "%s %s %s %.2f %s\n", "####", "####", "####", (float)-999, "####"); // write data EOF setelah bikin data dalam file
    fclose(fTemp); // tutup file
}

// Prosedur write to prodi.dat
void writeFileNameProdi(int n, prodi source[], char fileName[]){
    FILE *ftemp;
    ftemp = fopen(fileName, "w");
    if (ftemp == NULL){
        printf(MERAH_T BOLD"Error: tidak bisa membuka file %s\n"RESET, fileName);
    }
    
    for (int i = 0; i < n; i++){
        fprintf(ftemp, "%s %s\n", source[i].idProdi, source[i].prodi);
    }

    fprintf(ftemp, "%s %s\n", "####", "####");
    fclose(ftemp);
    
}

// === PROSEDUR READ FROM FILE ===
// Prosedur read from Mahasiswa.dat
void readFileNameMhs(int *n, mahasiswa source[], char fileName[]){
    *n = 0;
    FILE *fTemp;
    fTemp = fopen(fileName, "r"); // r untuk operator read file
    if (fTemp == NULL){
        printf("File Tidak Ditemukan\n");
        return;
    }

    int returnVal = fscanf(fTemp, "%s %s %s %s", source[*n].nim, source[*n].nama, source[*n].idProdi, source[*n].kodeMK);
    //untuk scan 3 data pada baris pertama dari isi file


    // cek apakah data yang di scan di atas EOF atau tidak
    if(strcmp(source[*n].nim, "####") == 0 || returnVal == EOF){
        printf("File Kosong\n");
    }else{ // jika bukan EOF
        while(strcmp(source[*n].nim, "####") != 0){ // selama bukan data EOF
            *n = *n + 1; // maju ke indeks penampung berikutnya
            fscanf(fTemp, "%s %s %s %s", source[*n].nim, source[*n].nama, source[*n].idProdi, source[*n].kodeMK); // scan data dan menampungnya dalam array sesuai index ke-*n, kemudian scan data berikutnya
        }
    }

    fclose(fTemp); // tutup file
}
// Prosedur read from MataKuliah.dat
void readFileNameMk(int *n, mataKuliah source[], char fileName[]){
    *n = 0;
    FILE *fTemp;
    fTemp = fopen(fileName, "r"); // r untuk operator read file
    if (fTemp == NULL){
        printf("File Tidak Ditemukan\n");
        return;
    }

    int returnVal = fscanf(fTemp, "%s %s %d", source[*n].kode, source[*n].namaMk, &source[*n].SKS);
    //untuk scan 3 data pada baris pertama dari isi file

    // cek apakah data yang di scan di atas EOF atau tidak
    if(strcmp(source[*n].kode, "####") == 0 || returnVal == EOF){
        printf("File Kosong\n");
    }else{ // jika bukan EOF
        while(strcmp(source[*n].kode, "####") != 0){ // selama bukan data EOF
            *n = *n + 1; // maju ke indeks penampung berikutnya
            fscanf(fTemp, "%s %s %d", source[*n].kode, source[*n].namaMk, &source[*n].SKS); // scan data dan menampungnya dalam array sesuai index ke-*n, kemudian scan data berikutnya
        }
    }

    fclose(fTemp); // tutup file
}
// Prosedur read from Nilai.dat
void readFileNameNilai(int *n, nilai source[], char fileName[]){
    *n = 0;
    FILE *fTemp;
    fTemp = fopen(fileName, "r"); // r untuk operator read file
    if (fTemp == NULL){
        printf("File Tidak Ditemukan\n");
        return;
    }

    int returnVal = fscanf(fTemp, "%s %s %f %s", source[*n].nim, source[*n].kode, &source[*n].nilai, source[*n].grade);
    //untuk scan 3 data pada baris pertama dari isi file

    // cek apakah data yang di scan di atas EOF atau tidak
    if (strcmp(source[*n].nim, "####") == 0 || returnVal == EOF){
        printf("File Kosong\n");
    } else {
        while (strcmp(source[*n].nim, "####") != 0){
            *n = *n + 1;
            fscanf(fTemp, "%s %s %f %s", source[*n].nim, source[*n].kode, &source[*n].nilai, source[*n].grade);
        }
    }
    fclose(fTemp);
}

// Prosedur read from prodi.dat
void readFileNameProdi(int *n, prodi source[], char fileName[]){
    *n = 0;
    FILE *ftemp;
    ftemp = fopen(fileName, "r");
    if (ftemp == NULL){
        printf("File Tidak Ditemukan\n");
        return;
    }
    
    int returnVal = fscanf(ftemp, "%s %s", source[*n].idProdi, source[*n].prodi);

    if (strcmp(source[*n].idProdi, "####") == 0 || returnVal == EOF){
        printf("File Kosong\n");
    } else{
        while (strcmp(source[*n].idProdi, "####") != 0){
            *n = *n + 1;
            fscanf(ftemp, "%s %s", source[*n].idProdi, source[*n].prodi);
        }
        
    }
    fclose(ftemp);
}

/// === PROSEDUR CEK DATA ===
// Prosedur cek ID PRODI
int cekProdi(char *idProdi, char fileName[]){
    FILE *ftemp;
    ftemp = fopen(fileName, "r");

    if (ftemp == NULL){
        return 0;
    }

    char id[10];
    char nama[100];
    int ditemukan = 0;

    while (fscanf(ftemp, "%s %s", id, nama) == 2){
        
        if (strcmp(id, idProdi) == 0){
            ditemukan = 1;
        }

    }

    fclose(ftemp);

    if (ditemukan == 1){
        return 1;
    } else {
        return 0;
    }
}

int cekMK(char *kodeMK, char fileName[]){
    FILE *ftemp;
    ftemp = fopen(fileName, "r");

    if (ftemp == NULL){
        return 0;
    }

    char kode[10];
    char nama[100];
    int sks;
    int ditemukan = 0;

    while (fscanf(ftemp, "%s %s %d", kode, nama, &sks) == 3){
        if (strcmp(kode, kodeMK) == 0){
            ditemukan = 1;
        }
    }

    fclose(ftemp);

    if (ditemukan == 1){
        return 1;
    } else{
        return 0;
    }
    
    
    
}

// === PROSEDUR SHOW DATA ===
// Prosedur show data mahasiswa.dat
void showDataMhs(int *n, mahasiswa source[]){
    if (*n == 0){
        printf("Data kosong\n");
        return;
    }

    #define PRINT_LINE_MHS(w1, w2, w3, w4) \
        printf("+"); \
        for(int _i=0; _i<w1+2; _i++) printf("-"); \
        printf("+"); \
        for(int _i=0; _i<w2+2; _i++) printf("-"); \
        printf("+"); \
        for(int _i=0; _i<w3+2; _i++) printf("-"); \
        printf("+"); \
        for(int _i=0; _i<w4+2; _i++) printf("-"); \
        printf("+\n");

    // cari lebar kolom terpanjang
    int wNim   = strlen("NIM");
    int wNama  = strlen("Nama");
    int wProdi = strlen("ID Prodi");
    int wMK    = strlen("Kode MK");

    for (int i = 0; i < *n; i++){
        if ((int)strlen(source[i].nim) > wNim)
            wNim = strlen(source[i].nim);

        if ((int)strlen(source[i].nama) > wNama)
            wNama = strlen(source[i].nama);

        if ((int)strlen(source[i].idProdi) > wProdi)
            wProdi = strlen(source[i].idProdi);

        if ((int)strlen(source[i].kodeMK) > wMK)
            wMK = strlen(source[i].kodeMK);
    }

    // header
    PRINT_LINE_MHS(wNim, wNama, wProdi, wMK)
    printf("| " BOLD KUNING "%-*s" RESET " | "
                BOLD KUNING "%-*s" RESET " | "
                BOLD KUNING "%-*s" RESET " | "
                BOLD KUNING "%-*s" RESET " |\n",
        wNim, "NIM",
        wNama, "Nama",
        wProdi, "ID Prodi",
        wMK, "Kode MK");

    PRINT_LINE_MHS(wNim, wNama, wProdi, wMK)

    // isi data
    for (int i = 0; i < *n; i++){
        printf("| %-*s | %-*s | %-*s | %-*s |\n",
            wNim,   source[i].nim,
            wNama,  source[i].nama,
            wProdi, source[i].idProdi,
            wMK,    source[i].kodeMK);
    }

    // footer
    PRINT_LINE_MHS(wNim, wNama, wProdi, wMK)

    #undef PRINT_LINE_MHS

    printf(PUTIH "Total: %d mahasiswa\n" RESET, *n);
}
// Prosedur show data MataKuliah.dat
void showDataMk(int *n, mataKuliah source[]){
    if (*n == 0){
        printf("Data kosong\n");
        return;
    }

    #define PRINT_LINE_MK(w1, w2, w3) \
        printf("+"); \
        for(int _i=0;_i<w1+2;_i++) printf("-"); \
        printf("+"); \
        for(int _i=0;_i<w2+2;_i++) printf("-"); \
        printf("+"); \
        for(int _i=0;_i<w3+2;_i++) printf("-"); \
        printf("+\n");

    // cari lebar kolom terpanjang
    int wKode = strlen("Kode");
    int wNama = strlen("Nama MK");
    int wSKS  = strlen("SKS");

    for (int i = 0; i < *n; i++){
        if ((int)strlen(source[i].kode)   > wKode) wKode = strlen(source[i].kode);
        if ((int)strlen(source[i].namaMk) > wNama) wNama = strlen(source[i].namaMk);
    }

    // header
    PRINT_LINE_MK(wKode, wNama, wSKS)
    printf("| " BOLD KUNING "%-*s" RESET " | " BOLD KUNING "%-*s" RESET " | " BOLD KUNING "%-*s" RESET " |\n", wKode, "Kode", wNama, "Nama MK", wSKS, "SKS");
    PRINT_LINE_MK(wKode, wNama, wSKS)

    // isi data
    for (int i = 0; i < *n; i++){
        char sks[10];
        sprintf(sks, "%d", source[i].SKS);
        printf("| %-*s | %-*s | %-*s |\n", wKode, source[i].kode, wNama, source[i].namaMk, wSKS,  sks);
    }

    // footer
    PRINT_LINE_MK(wKode, wNama, wSKS)

    #undef PRINT_LINE_MK

    printf(PUTIH "Total: %d mata kuliah\n" RESET, *n);
}
// Prosedur show data Nilai.dat
void showDataNilai(int *n, nilai source[]){
    if (*n == 0){
        printf("Data kosong\n");
        return;
    }

    #define PRINT_LINE_NILAI(w1, w2, w3, w4) \
        printf("+"); \
        for(int _i=0;_i<(w1)+2;_i++) printf("-"); \
        printf("+"); \
        for(int _i=0;_i<(w2)+2;_i++) printf("-"); \
        printf("+"); \
        for(int _i=0;_i<(w3)+2;_i++) printf("-"); \
        printf("+"); \
        for(int _i=0;_i<(w4)+2;_i++) printf("-"); \
        printf("+\n");

    // cari lebar kolom
    int wNim    = strlen("NIM");
    int wKode   = strlen("Kode");
    int wNilai  = strlen("Nilai");
    int wGrade  = strlen("Grade");

    for (int i = 0; i < *n; i++){
        char bufNilai[20];
        sprintf(bufNilai, "%.2f", source[i].nilai);

        if ((int)strlen(source[i].nim) > wNim)    
            wNim = strlen(source[i].nim);

        if ((int)strlen(source[i].kode) > wKode)   
            wKode = strlen(source[i].kode);

        if ((int)strlen(bufNilai) > wNilai)  
            wNilai = strlen(bufNilai);

        if ((int)strlen(source[i].grade) > wGrade)  
            wGrade = strlen(source[i].grade);
    }

    // header
    PRINT_LINE_NILAI(wNim, wKode, wNilai, wGrade)
    printf("| " BOLD KUNING "%-*s" RESET " | " BOLD KUNING "%-*s" RESET " | " BOLD KUNING "%-*s" RESET " | " BOLD KUNING "%-*s" RESET " |\n",wNim, "NIM", wKode, "Kode", wNilai, "Nilai", wGrade, "Grade");

    PRINT_LINE_NILAI(wNim, wKode, wNilai, wGrade)

    // isi data
    for (int i = 0; i < *n; i++){
        char bufNilai[20];
        sprintf(bufNilai, "%.2f", source[i].nilai);

        printf("| %-*s | %-*s | %-*s | %-*s |\n", wNim, source[i].nim, wKode, source[i].kode, wNilai, bufNilai, wGrade, source[i].grade);
    }

    // footer
    PRINT_LINE_NILAI(wNim, wKode, wNilai, wGrade)

    #undef PRINT_LINE_NILAI
}
// Prosedur Show Data Prodi.dat
void showDataProdi(int *n, prodi source[]){
    if (*n == 0){
        printf("Data kosong\n");
        return;
    }
    
    #define PRINT_LINE_PRODI(w1, w2) \
        printf("+"); \
        for(int _i=0;_i<w1+2;_i++) printf("-"); \
        printf("+"); \
        for(int _i=0;_i<w2+2;_i++) printf("-"); \
        printf("+\n");
    
    int wID = strlen("ID Prodi");
    int wProdi = strlen("Prodi");
    
    for (int i = 0; i < *n; i++){
        if ((int)strlen(source[i].idProdi) > wID){
            wID = strlen(source[i].idProdi);
        }
        if ((int)strlen(source[i].prodi) > wProdi){
            wProdi = strlen(source[i].prodi);
        }
    }
    
    PRINT_LINE_PRODI(wID, wProdi)
    printf("| " BOLD KUNING "%-*s" RESET " | " BOLD KUNING "%-*s" RESET " |\n" ,wID, "ID PRODI", wProdi, "Prodi");
    PRINT_LINE_PRODI(wID, wProdi)
    
    // isi data
    for (int i = 0; i < *n; i++){
        printf("| %-*s | %-*s |\n", wID, source[i].idProdi, wProdi, source[i].prodi);
    }
    PRINT_LINE_PRODI(wID, wProdi)

    #undef PRINT_LINE_PRODI
} 

// === PROSEDUR UPDATE FILE ===
// prosedur update file mahasiswa.dat
void updateFileNameMhs(char *query, int *n, mahasiswa source[]){
    char nimCari[51];
    char command[50], table[50];
    mahasiswa baru;
    int len = sscanf(query, "%s %s %s %s %s %s", command, table, nimCari, baru.nama, baru.idProdi, baru.kodeMK);
    strcpy(baru.nim, nimCari);
    // cek apakah query valid
    if (len < 6){
        printf( MERAH_T BOLD "Error: query tidak valid\n");
        printf("Gunakan: UPDATE <table> <nim> <nama> <prodi>;\n" RESET);
        return;
    }

    int found = -1; // variabel penanda

    for (int i = 0; i < *n; i++){
        if (strcmp(source[i].nim, nimCari) == 0){
            found = i;
        }
    }

    if (found == -1){
        printf( MERAH_T BOLD"NIM %s tidak ditemukan\n" RESET, nimCari);
        return;
    }

    if (cekProdi(baru.idProdi, "../data/prodi.dat") == 0){
        printf(MERAH_T BOLD "Error: ID Prodi %s tidak ditemukan\n" RESET, baru.idProdi);
        return;
    }
    
    if (cekMK(baru.kodeMK, "../data/mataKuliah.dat") == 0){
        printf(MERAH_T BOLD "Error: Kode MK %s tidak ditemukan\n" RESET, baru.kodeMK);
        return;
    }
    
    
    // jika ditemukan, update datanya
    strcpy(source[found].nama, baru.nama);
    strcpy(source[found].idProdi, baru.idProdi);
    strcpy(source[found].kodeMK, baru.kodeMK);

    writeToFileNameMhs(*n, source, "../data/mahasiswa.dat");
    printf( HIJAU_T"Data berhasil diupdate.\n" RESET);
}
// Prosedur update file prodi.dat
void updateFileNameProdi(char *query, int *n, prodi source[]){
    char idCari[MAX];
    char command[MAX], table[MAX];
    prodi new;
        int len = sscanf(query, "%s %s %s %s", command, table, idCari, new.prodi);
    strcpy(new.idProdi, idCari);
    // cek apakah query valid
    if (len < 4){
        printf(MERAH_T BOLD"Error: query tidak valid\n");
        printf("Gunakan: UPDATE <table> <ID Podi> <Prodi>;" RESET);
        return;
    }

    int found = -1; // variabel penanda

    for (int i = 0; i < *n; i++){
        if (strcmp(source[i].idProdi, idCari) == 0){
            found = i;
        }
    }

    if (found == -1){
        printf(MERAH_T BOLD"Kode %s tidak ditemukan\n" RESET, idCari);
        return;
    }

    // jika ditemukan, update datanya
    strcpy(source[found].prodi, new.prodi);

    writeFileNameProdi(*n, source, "../data/prodi.dat");
    printf(HIJAU_T"Data berhasil diupdate.\n" RESET);
    
}

// prosedur update file mata kuliah.dat
void updateFileNameMk(char *query, int *n, mataKuliah source[]){
    char kodeCari[MAX];
    char command[MAX], table[MAX];
    mataKuliah new;
    int len = sscanf(query, "%s %s %s %s %d", command, table, kodeCari, new.namaMk, &new.SKS);
    strcpy(new.kode, kodeCari);
    // cek apakah query valid
    if (len < 5){
        printf(MERAH_T BOLD"Error: query tidak valid\n");
        printf("Gunakan: UPDATE <table> <kodeMK> <namaMK> <sks>;" RESET);
        return;
    }

    int found = -1; // variabel penanda

    for (int i = 0; i < *n; i++){
        if (strcmp(source[i].kode, kodeCari) == 0){
            found = i;
        }
    }

    if (found == -1){
        printf(MERAH_T BOLD"Kode %s tidak ditemukan\n" RESET, kodeCari);
        return;
    }

    // jika ditemukan, update datanya
    strcpy(source[found].namaMk, new.namaMk);
    source[found].SKS = new.SKS;

    writeToFileNameMk(*n, source, "../data/mataKuliah.dat");
    printf(HIJAU_T"Data berhasil diupdate.\n" RESET);
    
}
// prosedur update file nilai.dat
void updateFileNameNilai(char *query, int *n, nilai source[]){
    char nimCari[MAX]; 
    char command[MAX], table[MAX];
    nilai new;
    int len = sscanf(query, "%s %s %s %s %f %s", command, table, nimCari, new.kode, &new.nilai, new.grade);
    // cek apakah query valid
    if (len < 6){
        printf(MERAH_T BOLD"Error: query tidak valid\n");
        printf(MERAH_T BOLD"Gunakan: UPDATE <table> <nim> <namaMK> <kodeMK> <nilai> <grade>;\n" RESET);
        return;
    }

    int found = -1; // variabel penanda 

    for (int i = 0; i < *n; i++){
        if (strcmp(source[i].nim, nimCari) == 0){
            found = i;
        } 
    }

    if (found == -1){
        printf(MERAH_T BOLD"Id %s tidak ditemukan\n" RESET, nimCari);
        return;
    }

    // jika ditemukan, update datanya
    source[found].nilai = new.nilai;

    // update grade otomatis 
    if(new.nilai >= 85){
        strcpy(source[found].grade, "A");
    } else if (new.nilai >= 70) {
        strcpy(source[found].grade, "B");
    } else if (new.nilai >= 55) {
        strcpy(source[found].grade, "C");
    } else if (new.nilai >= 40) {
        strcpy(source[found].grade, "D");
    }else{                      
        strcpy(source[found].grade, "E");
    }

    writeToFileNameNilai(*n, source, "../data/nilai.dat");
    printf(HIJAU_T"Data berhasil diupdate.\n" RESET);
}

// === PROSEDUR INPUT DATA ===
// prosedur input data mahasiswa.dat
void insertMahasiswa(char *query, mahasiswa *source, int *n){
    char command[50], table[50];
    mahasiswa baru;

    int len = sscanf(query, "%s %s %s %s %s %s", command, table, baru.nim, baru.nama, baru.idProdi, baru.kodeMK);

    // cek apakah query valid
    if (len < 6) {
        printf(MERAH_T BOLD"Error: query tidak valid\n" RESET);
        printf(MERAH_T"Gunakan: INSERT <table> <nim> <nama> <prodi> <kodeMK>;\n"RESET);
        return;
    }

    for (int i = 0; i < *n; i++){
        if (strcmp(source[i].nim, baru.nim) == 0){
            printf(MERAH_T BOLD"Error: NIM %s sudah ada\n" RESET, baru.nim);
            return;
        }
    }

    // === SORTING NIM
    int jumlahRek = *n;
    
    // jika array kosong
    if (jumlahRek == 0){
        source[0] = baru;
        (*n)++;
    } else if (strcmp(baru.nim, source[0].nim) < 0){ // jika nim baru lebih kecil{
        for (int i = (jumlahRek - 1); i >= 0; i--){
            source[i + 1] = source[i];
        }
        source[0] = baru;
        (*n)++;
    } else if (strcmp(baru.nim, source[jumlahRek - 1].nim) > 0){
        source[jumlahRek] = baru;
        (*n)++;
    } else{
        int stop = 0;
        int i = 0;
        // cari posisi
        while ((i < jumlahRek) && (stop == 0)){
            if (strcmp(source[i].nim, baru.nim) > 0){
                stop = 1;
            } else{
                i++;
            }
        }
        int j;
        for (j = (jumlahRek - 1); j >= i ; j--){
            source[j + 1] = source[j];
        }

        source[i] = baru;
        (*n)++;
    }
    writeToFileNameMhs(*n, source, "../data/mahasiswa.dat");
    printf(HIJAU_T"Data berhasil disimpan.\n" RESET);
}
// prosedur input data mata kuliah.dat
void insertmataKuliah(char *query, mataKuliah *source, int *n){
    char command[MAX], table[MAX];
    mataKuliah new;
    memset(&new, 0, sizeof(mataKuliah));

    // hapus semicolon di akhir query sebelum sscanf
    query[strcspn(query, ";")] = '\0';
    int len = sscanf(query, "%s %s %s %s %d", command, table, new.kode, new.namaMk, &new.SKS);

    // cek apakah query valid
    if (len < 5){
        printf(MERAH_T BOLD"Error: query tidak valid\n" RESET);
        printf(MERAH_T"Gunakan: INSERT <table> <kodeMK> <namaMK> <SKS>;\n" RESET);
        return;
    }

    // cek duplikat kode MK
    for (int i = 0; i < *n; i++){
        if (strcmp(source[i].kode, new.kode) == 0){
            printf(MERAH_T BOLD"Error: kode MK %s sudah ada\n" RESET, new.kode);
            return;
        }
    }

    int jumlahRek = *n;

    // jika array kosong
    if (jumlahRek == 0){
        source[0] = new;
        (*n)++;
    } else if (strcmp(new.kode, source[0].kode) < 0){
        for (int i = (jumlahRek - 1); i >= 0; i--){
            source[i + 1] = source[i];
        }
        source[0] = new;
        (*n)++;
    } else if (strcmp(new.kode, source[jumlahRek - 1].kode) > 0){
        source[jumlahRek] = new;
        (*n)++;
    } else{
        int stop = 0;
        int i = 0;
        // cari posisi
        while ((i < jumlahRek) && (stop == 0)){
            if (strcmp(source[i].kode, new.kode) > 0){
                stop = 1;
            } else{
                i++;
            }
        }
        int j;
        for (j = (jumlahRek - 1); j >= i ; j--){
            source[j + 1] = source[j];
        }

        source[i] = new;
        (*n)++;
    }

    writeToFileNameMk(*n, source, "../data/mataKuliah.dat");
    printf(HIJAU_T"Data berhasil disimpan.\n"RESET);    
}
// prosedur input data nilai.dat
void insertNilai(char *query, nilai *source, int *n, mataKuliah *sourceMk, int *nMK){
    char command[MAX], table[MAX];
    nilai new;
    memset(&new, 0, sizeof(nilai));

    query[strcspn(query, ";")] = '\0';

    // FORMAT BARU: INSERT NILAI <id> <kode> <nilai> <grade>
    // namaMK tidak perlu diinput, diambil otomatis dari kode
    int len = sscanf(query, "%s %s %s %s %f %s", command, table, new.nim, new.kode, &new.nilai, new.grade);

    if (len < 6 ){
        printf(MERAH_T BOLD"Error: query tidak valid\n" RESET);
        printf(MERAH_T"Gunakan: INSERT NILAI <nim> <MK> <Kode> <nilai> <grade>;\n" RESET);
        return;
    }

    // Cari namaMK dari kode di sourceMk
    int foundMK = -1;
    for (int i = 0; i < *nMK; i++){
        if (strcmp(sourceMk[i].kode, new.kode) == 0){
            foundMK = i;
            break;
        }
    }

    // Kalau kode tidak ditemukan, tolak
    if (foundMK == -1){
        printf(MERAH_T BOLD"Error: kode MK '%s' tidak ditemukan\n"RESET, new.kode);
        return;
    }

    // Cek duplikat id
    for (int i = 0; i < *n; i++){
        if (strcmp(source[i].nim, new.nim) == 0 && strcmp(source[i].kode, new.kode) == 0){
            printf(MERAH_T BOLD"Error: mahasiswa %s sudah punya nilai untuk MK %s\n" RESET, new.nim, new.kode);
            return;
        }
    }

    int jumlahRek = *n;

    // jika array kosong
    if (jumlahRek == 0){
        source[0] = new;
        (*n)++;
    } else if (strcmp(new.nim, source[0].nim) < 0){
        for (int i = (jumlahRek - 1); i >= 0; i--){
            source[i + 1] = source[i];
        }
        source[0] = new;
        (*n)++;
    } else if (strcmp(new.nim, source[jumlahRek - 1].nim) > 0){
        source[jumlahRek] = new;
        (*n)++;
    } else{
        int stop = 0;
        int i = 0;
        // cari posisi
        while ((i < jumlahRek) && (stop == 0)){
            if (strcmp(source[i].nim, new.nim) > 0){
                stop = 1;
            } else{
                i++;
            }
        }
        int j;
        for (j = (jumlahRek - 1); j >= i ; j--){
            source[j + 1] = source[j];
        }

        source[i] = new;
        (*n)++;
    }

    writeToFileNameNilai(*n, source, "../data/nilai.dat");
    printf(HIJAU_T"Data berhasil disimpan.\n"RESET);
}
// Prosedur input data prodi
void insertProdi(char *query, prodi *source, int *n){
    char command[MAX], table[MAX];
    prodi new;
    memset(&new, 0, sizeof(prodi));

    // hapus semicolon di akhir query sebelum sscanf
    query[strcspn(query, ";")] = '\0';
    int len = sscanf(query, "%s %s %s %s", command, table, new.idProdi, new.prodi);

    // cek apakah query valid
    if (len < 4){
        printf(MERAH_T BOLD"Error: query tidak valid\n" RESET);
        printf(MERAH_T"Gunakan: INSERT <table> <idPrdi> <Prodi>;\n" RESET);
        return;
    }

    // cek duplikat id Prodi
    for (int i = 0; i < *n; i++){
        if (strcmp(source[i].idProdi, new.idProdi) == 0){
            printf(MERAH_T BOLD"Error: ID Prodi %s sudah ada\n" RESET, new.idProdi);
            return;
        }
    }

    int jumlahRek = *n;

    // jika array kosong
    if (jumlahRek == 0){
        source[0] = new;
        (*n)++;
    } else if (strcmp(new.idProdi, source[0].idProdi) < 0){
        for (int i = (jumlahRek - 1); i >= 0; i--){
            source[i + 1] = source[i];
        }
        source[0] = new;
        (*n)++;
    } else if (strcmp(new.idProdi, source[jumlahRek - 1].idProdi) > 0){
        source[jumlahRek] = new;
        (*n)++;
    } else{
        int stop = 0;
        int i = 0;
        // cari posisi
        while ((i < jumlahRek) && (stop == 0)){
            if (strcmp(source[i].idProdi, new.idProdi) > 0){
                stop = 1;
            } else{
                i++;
            }
        }
        int j;
        for (j = (jumlahRek - 1); j >= i ; j--){
            source[j + 1] = source[j];
        }

        source[i] = new;
        (*n)++;
    }

    writeFileNameProdi(*n, source, "../data/prodi.dat");
    printf(HIJAU_T"Data berhasil disimpan.\n"RESET);
}

// === PROSEDUR DELETE DATA ===
// prosedur delete data mahasiswa.dat
void deleteMahasiswa(char *query, int *n ,mahasiswa *source){
    char command[50], table[50];
    char nimCari[50];

    int len = sscanf(query, "%s %s %s", command, table, nimCari);

    // cek apakah query valid
    if (len < 3) {
        printf("Error: query tidak valid\n");
        printf("Gunakan: DELETE <table> <nim>;\n");
        return;
    }

    int found = -1;
    for (int i = 0; i < *n; i++){
        if (strcmp(source[i].nim, nimCari) == 0){
            found = i;
        }
    }

    if (found == -1){
        printf("NIM %s tidak ditemukan\n", nimCari);
        return;
    }

    for (int i = found; i < *n - 1; i++){
        strcpy(source[i].nim, source[i+1].nim);
        strcpy(source[i].nama, source[i+1].nama);
        strcpy(source[i].idProdi, source[i+1].idProdi);
    }
    
    (*n)--;
    writeToFileNameMhs(*n, source, "../data/mahasiswa.dat");
    printf(MERAH_T "Data dengan NIM %s berhasil dihapus.\n" RESET, nimCari);
}
// prosedur delete data mata kuliah.dat
void deleteMataKuliah(char *query, int *n ,mataKuliah *source){
    char command[50], table[50];
    char kodeCari[50];

    int len = sscanf(query, "%s %s %s", command, table, kodeCari);

    // cek apakah query valid
    if (len < 3) {
        printf(MERAH_T BOLD"Error: query tidak valid\n");
        printf("Gunakan: DELETE <table> <kodeMK>;\n" RESET);
        return;
    }

    int found = -1;
    for (int i = 0; i < *n; i++){
        if (strcmp(source[i].kode, kodeCari) == 0){
            found = i;
        }
    }

    if (found == -1){
        printf(MERAH_T BOLD"Kode %s tidak ditemukan\n" RESET, kodeCari);
        return;
    }

    for (int i = found; i < *n - 1; i++){
        strcpy(source[i].kode, source[i+1].kode);
        strcpy(source[i].namaMk, source[i+1].namaMk);
        source[i].SKS = source[i+1].SKS;
    }
    
    (*n)--;
    writeToFileNameMk(*n, source, "../data/mataKuliah.dat");
    printf(MERAH_T BOLD"Data dengan Kode %s berhasil dihapus.\n" RESET, kodeCari);
}

void deleteProdi(char *query, int *n, prodi *source){
    char command[50], table[50];
    char idCari[50];
    int len = sscanf(query, "%s %s %s", command, table, idCari);

    // cek apakah query vlid
    if (len < 3){
        printf(MERAH_T BOLD"Error : query tidak valid\n");
        printf("Gunakan: DELETE <table> <idProdi>;\n" RESET);
        return;
    }

    int found = -1;
    for (int i = 0; i < *n; i++){
        if (strcmp(source[i].idProdi, idCari) == 0){
            found = i;
        }
        
    }
    
    if (found == -1){
        printf(MERAH_T BOLD"ID Prodi %s tidak ditemukan\n"RESET, idCari);
        return;
    }
    
    for (int i = found; i < *n - 1; i++){
        strcpy(source[i].idProdi, source[i+1].idProdi);
        strcpy(source[i].prodi, source[i+1].prodi);
    }
    (*n)--;
    writeFileNameProdi(*n, source, "../data/prodi.dat");
    printf(MERAH_T BOLD"Data dengan id Prodi %s berhasil dihapus.\n"RESET, idCari);
}

void deleteNilai(char *query, int *n ,nilai *source){
    char command[50], table[50];
    char nimCari[50];  
    int len = sscanf(query, "%s %s %s", command, table, nimCari);
    
    // cek apakah query valid
    if (len < 3) {
        printf(MERAH_T BOLD"Error: query tidak valid\n");
        printf("Gunakan: DELETE <table> <id>;\n" RESET);
        return;
    }

    int found = -1;
    for (int i = 0; i < *n; i++){
        if (strcmp(source[i].nim, nimCari) == 0){
            found = i;
        }
    }

    if (found == -1){
        printf(MERAH_T BOLD"NIM %s tidak ditemukan\n" RESET, nimCari);
        return;
    }

    for (int i = found; i < *n - 1; i++){
        strcpy(source[i].nim, source[i+1].nim);
        strcpy(source[i].kode, source[i+1].kode);   
        source[i].nilai = source[i+1].nilai;
        strcpy(source[i].grade, source[i+1].grade);  
    }
    
    (*n)--;
    writeToFileNameNilai(*n, source, "../data/nilai.dat");
    printf(MERAH_T BOLD"Data dengan Id %s berhasil dihapus.\n" RESET, nimCari);
}

/// === JOIN ===
void showJoin(mahasiswa m[], int nMhs, prodi p[], int nProdi, mataKuliah mk[], int nMK, nilai ni[], int nNilai){
    if (nMhs == 0){
        printf("Data kosong\n");
        return;
    }

    // === MACRO GARIS ===
    #define PRINT_LINE_JOIN(w1,w2,w3,w4,w5,w6,w7) \
        printf("+"); \
        for(int _i=0; _i<w1+2; _i++) printf("-"); \
        printf("+"); \
        for(int _i=0; _i<w2+2; _i++) printf("-"); \
        printf("+"); \
        for(int _i=0; _i<w3+2; _i++) printf("-"); \
        printf("+"); \
        for(int _i=0; _i<w4+2; _i++) printf("-"); \
        printf("+"); \
        for(int _i=0; _i<w5+2; _i++) printf("-"); \
        printf("+"); \
        for(int _i=0; _i<w6+2; _i++) printf("-"); \
        printf("+"); \
        for(int _i=0; _i<w7+2; _i++) printf("-"); \
        printf("+\n");

    // === LEBAR KOLOM ===
    int wNim   = strlen("NIM");
    int wNama  = strlen("Nama");
    int wProdi = strlen("Prodi");
    int wMK    = strlen("Mata Kuliah");
    int wSKS   = strlen("SKS");
    int wNilai = strlen("Nilai");
    int wGrade = strlen("Grade");

    // === HITUNG LEBAR DINAMIS ===
    for (int i = 0; i < nMhs; i++){

        char namaProdi[100] = "-";
        char namaMK[100] = "-";
        char nilaiStr[20] = "-";
        char grade[10] = "-";
        char sksStr[10] = "-";

        // cari prodi
        for (int j = 0; j < nProdi; j++){
            if (strcmp(m[i].idProdi, p[j].idProdi) == 0){
                strcpy(namaProdi, p[j].prodi);
                break;
            }
        }

        // cari MK
        int sks = 0;
        for (int j = 0; j < nMK; j++){
            if (strcmp(m[i].kodeMK, mk[j].kode) == 0){
                strcpy(namaMK, mk[j].namaMk);
                sks = mk[j].SKS;
                sprintf(sksStr, "%d", sks);
                break;
            }
        }

        // cari nilai
        for (int j = 0; j < nNilai; j++){
            if (strcmp(m[i].nim, ni[j].nim) == 0 &&
                strcmp(m[i].kodeMK, ni[j].kode) == 0){
                sprintf(nilaiStr, "%.2f", ni[j].nilai);
                strcpy(grade, ni[j].grade);
                break;
            }
        }

        // update width
        if ((int)strlen(m[i].nim) > wNim) wNim = strlen(m[i].nim);
        if ((int)strlen(m[i].nama) > wNama) wNama = strlen(m[i].nama);
        if ((int)strlen(namaProdi) > wProdi) wProdi = strlen(namaProdi);
        if ((int)strlen(namaMK) > wMK) wMK = strlen(namaMK);
        if ((int)strlen(sksStr) > wSKS) wSKS = strlen(sksStr);
        if ((int)strlen(nilaiStr) > wNilai) wNilai = strlen(nilaiStr);
        if ((int)strlen(grade) > wGrade) wGrade = strlen(grade);
    }

    // === HEADER ===
    PRINT_LINE_JOIN(wNim,wNama,wProdi,wMK,wSKS,wNilai,wGrade)
    printf("| " BOLD KUNING "%-*s" RESET 
        " | " BOLD KUNING "%-*s" RESET 
        " | " BOLD KUNING "%-*s" RESET 
        " | " BOLD KUNING "%-*s" RESET
        " | " BOLD KUNING "%-*s" RESET 
        " | " BOLD KUNING "%-*s" RESET
        " | " BOLD KUNING "%-*s" RESET
        " |\n",
        wNim, "NIM",
        wNama, "Nama",
        wProdi, "Prodi",
        wMK, "Mata Kuliah",
        wSKS, "SKS",
        wNilai, "Nilai",
        wGrade, "Grade");
    PRINT_LINE_JOIN(wNim,wNama,wProdi,wMK,wSKS,wNilai,wGrade)

    // === DATA ===
    for (int i = 0; i < nMhs; i++){

        char namaProdi[100] = "-";
        char namaMK[100] = "-";
        char nilaiStr[20] = "-";
        char grade[10] = "-";
        char sksStr[10] = "-";

        // cari prodi
        for (int j = 0; j < nProdi; j++){
            if (strcmp(m[i].idProdi, p[j].idProdi) == 0){
                strcpy(namaProdi, p[j].prodi);
                break;
            }
        }

        // cari MK
        int sks = 0;
        for (int j = 0; j < nMK; j++){
            if (strcmp(m[i].kodeMK, mk[j].kode) == 0){
                strcpy(namaMK, mk[j].namaMk);
                sks = mk[j].SKS;
                sprintf(sksStr, "%d", sks);
                break;
            }
        }

        // cari nilai
        for (int j = 0; j < nNilai; j++){
            if (strcmp(m[i].nim, ni[j].nim) == 0 &&
                strcmp(m[i].kodeMK, ni[j].kode) == 0){
                sprintf(nilaiStr, "%.2f", ni[j].nilai);
                strcpy(grade, ni[j].grade);
                break;
            }
        }

        printf("| %-*s | %-*s | %-*s | %-*s | %-*s | %-*s | %-*s |\n",
            wNim, m[i].nim,
            wNama, m[i].nama,
            wProdi, namaProdi,
            wMK, namaMK,
            wSKS, sksStr,
            wNilai, nilaiStr,
            wGrade, grade
        );
    }

    // === FOOTER ===
    PRINT_LINE_JOIN(wNim,wNama,wProdi,wMK,wSKS,wNilai,wGrade)

    #undef PRINT_LINE_JOIN
}

// === PROSEDUR PARSE INPUT ===
void parseInput(char query[], int *n, int *nMK, int *nNilai, int *nProdi, mahasiswa source[], mataKuliah sourceMk[], nilai sourceNilai[], prodi sourceProdi[], int *running) {
    char command[20];
    char table[50];
    int cekPenutup = 0;

    // cek apakah query diakhiri ;
    for (int i = 0; i < strlen(query) && cekPenutup == 0; i++){
        if (query[i] == ';'){
            cekPenutup = 1;
            query[i] = '\0';
        }
    }

    if (cekPenutup == 0){
        printf(MERAH_T BOLD"Error: query harus diakhiri ';'\n"RESET);
        return;
    }
    
    // ambil command
    sscanf(query, "%s", command);
    for (int i = 0; i < strlen(command); i++){
        command[i] = toupper(command[i]);
    }
    
    // === EXIT ===
    if (strcmp(command, "EXIT") == 0){
        *running = 0;
        return;

    // === INSERT ===
    } else if (strcmp(command, "INSERT") == 0){
        // ambil nama table
        sscanf(query, "%s %s", command, table);
        for (int i = 0; i < strlen(table); i++){
            table[i] = toupper(table[i]);
        }
        
        // === INSERT MAHASISWA ===
        if (strcmp(table, "MAHASISWA") == 0){
            insertMahasiswa(query, source, n);
        } // === INSERT MATA KULIAH === 
        else if (strcmp(table, "MK") == 0){
            insertmataKuliah(query, sourceMk, nMK);
        } // === INSERT NILAI === 
        else if (strcmp(table, "NILAI") == 0){
            insertNilai(query, sourceNilai, nNilai, sourceMk, nMK);
        } /// === INSERT PRODI
        else if (strcmp(table, "PRODI") == 0){
            insertProdi(query, sourceProdi, nProdi);
        }
        
        else{
            printf(MERAH_T BOLD "Unknown table: %s\n", table);
            printf("Gunakan: INSERT <table>;\n" RESET);
            return;
        }
    
    // === SHOW ===
    } else if (strcmp(command, "SHOW") == 0){
        // ambil nama table
        sscanf(query, "%s %s", command, table);
        for (int i = 0; i < strlen(table); i++){
            table[i] = toupper(table[i]);
        }

        // === SHOW MAHASISWA ===
        if (strcmp(table, "MAHASISWA") == 0){
            showDataMhs(n, source);
        } // === SHOW MATA KULIAH ===
        else if (strcmp(table, "MK") == 0){
            showDataMk(nMK, sourceMk);
        } // === SHOW NILAI ===
        else if (strcmp(table, "NILAI") == 0){
            showDataNilai(nNilai, sourceNilai);
        } // === SHOW TABLES ===
        else if (strcmp(table, "TABLES") == 0){
            showTabels();
        } // === SHOW HELP ===
        else if (strcmp(table, "HELP") == 0){
            showHelp();
        } // === SHOW PRODI ===
        else if (strcmp(table, "PRODI") == 0){
            showDataProdi(nProdi, sourceProdi);
        } // === SHOW JOIN ===
        else if (strcmp(table, "JOIN") == 0){
        showJoin(source, *n, sourceProdi, *nProdi, sourceMk, *nMK, sourceNilai, *nNilai);
        }
        
        else{
            printf(MERAH_T BOLD"Unknown table: %s\n", table);
            printf("Gunakan: SHOW <table>;\n" RESET);
            return;
        }
    } else if (strcmp(command, "UPDATE") == 0){
        // ambil nama table
        sscanf(query, "%s %s", command, table);
        for (int i = 0; i < strlen(table); i++){
            table[i] = toupper(table[i]);
        }

        // === UPDATE MAHASISWA ===
        if (strcmp(table, "MAHASISWA") == 0){
            updateFileNameMhs(query, n, source);
            
        } // === UPDATE MATA KULIAH ===
        else if (strcmp(table, "MK") == 0){
            updateFileNameMk(query, nMK, sourceMk);
        } // === UPDATE NILAI ===
        else if (strcmp(table, "NILAI") == 0){
            updateFileNameNilai(query, nNilai, sourceNilai);
        } // === UPDATE PRODI===
        else if (strcmp(table, "PRODI") == 0){
            updateFileNameProdi(query, nProdi, sourceProdi);
        }
        
        else{
            printf("Unknown table: %s\n", table);
            printf("Gunakan: UPDATE <table>;\n");
            return;
        }
    } else if (strcmp(command, "DELETE") == 0){
        // ambil nama table
        sscanf(query, "%s %s", command, table);
        for (int i = 0; i < strlen(table); i++){
            table[i] = toupper(table[i]);
        }

        // === DELETE MAHASISWA ===
        if (strcmp(table, "MAHASISWA") == 0){
            deleteMahasiswa(query, n, source);
        } // === DELETE MATA KULIAH === 
        else if (strcmp(table, "MK") == 0){
            deleteMataKuliah(query, nMK, sourceMk);
        } // === DELETE NILAI === 
        else if (strcmp(table, "NILAI") == 0){
            deleteNilai(query, nNilai, sourceNilai);
        } // === DELETE PRODI ===
        else if (strcmp(table, "PRODI") == 0){
            deleteProdi(query, nProdi, sourceProdi);
        }
        
        else{
            printf("Unknown table: %s\n", table);
            printf("Gunakan: DELETE <table>;\n");
            return;
        }
        
    } else{
        printf("Unknown command: %s\n", command);
    }
}
