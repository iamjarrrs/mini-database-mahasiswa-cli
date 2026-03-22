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
        fprintf(fTemp, "%s %s %s\n", source[i].nim, source[i].nama, source[i].prodi); // write data ke dalam file
    }
    fprintf(fTemp, "%s %s %s\n", "####", "####", "####"); // write data EOF setelah bikin data dalam file
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

    int returnVal = fscanf(fTemp, "%s %s %s", source[*n].nim, source[*n].nama, source[*n].prodi);
    //untuk scan 3 data pada baris pertama dari isi file


    // cek apakah data yang di scan di atas EOF atau tidak
    if(strcmp(source[*n].nim, "####") == 0 || returnVal == EOF){
        printf("File Kosong\n");
    }else{ // jika bukan EOF
        while(strcmp(source[*n].nim, "####") != 0){ // selama bukan data EOF
            *n = *n + 1; // maju ke indeks penampung berikutnya
            fscanf(fTemp, "%s %s %s", source[*n].nim, source[*n].nama, source[*n].prodi); // scan data dan menampungnya dalam array sesuai index ke-*n, kemudian scan data berikutnya
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

// === PROSEDUR SHOW DATA ===
// Prosedur show data mahasiswa.dat
void showDataMhs(int *n, mahasiswa source[]){
    if (*n == 0){
        printf("Data kosong\n");
        return;
    }

    #define PRINT_LINE_MHS(w1, w2, w3) \
        printf("+"); \
        for(int _i=0;_i<w1+2;_i++) printf("-"); \
        printf("+"); \
        for(int _i=0;_i<w2+2;_i++) printf("-"); \
        printf("+"); \
        for(int _i=0;_i<w3+2;_i++) printf("-"); \
        printf("+\n");

    // cari lebar kolom terpanjang
    int wNim   = strlen("NIM");
    int wNama  = strlen("Nama");
    int wProdi = strlen("Prodi");

    for (int i = 0; i < *n; i++){
        if ((int)strlen(source[i].nim)   > wNim)   wNim   = strlen(source[i].nim);
        if ((int)strlen(source[i].nama)  > wNama)  wNama  = strlen(source[i].nama);
        if ((int)strlen(source[i].prodi) > wProdi) wProdi = strlen(source[i].prodi);
    }

    // header
    PRINT_LINE_MHS(wNim, wNama, wProdi)
    printf("| " BOLD KUNING "%-*s" RESET " | " BOLD KUNING "%-*s" RESET " | " BOLD KUNING "%-*s" RESET " |\n", wNim, "NIM", wNama, "Nama", wProdi, "Prodi");
    PRINT_LINE_MHS(wNim, wNama, wProdi)

    // isi data
    for (int i = 0; i < *n; i++){
        printf("| %-*s | %-*s | %-*s |\n", wNim,   source[i].nim, wNama,  source[i].nama, wProdi, source[i].prodi);
    }

    // footer
    PRINT_LINE_MHS(wNim, wNama, wProdi)

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

// === PROSEDUR UPDATE FILE ===
// prosedur update file mahasiswa.dat
void updateFileNameMhs(char *query, int *n, mahasiswa source[]){
    char nimCari[51];
    char command[50], table[50];
    mahasiswa baru;
    int len = sscanf(query, "%s %s %s %s %s", command, table, nimCari, baru.nama, baru.prodi);
    strcpy(baru.nim, nimCari);
    // cek apakah query valid
    if (len < 5){
        printf( MERAH_T "Error: query tidak valid\n");
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
        printf( MERAH_T "NIM %s tidak ditemukan\n" RESET, nimCari);
        return;
    }
    
    // jika ditemukan, update datanya
    strcpy(source[found].nama, baru.nama);
    strcpy(source[found].prodi, baru.prodi);

    writeToFileNameMhs(*n, source, "../data/mahasiswa.dat");
    printf( HIJAU_T"Data berhasil diupdate.\n" RESET);
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
        printf(MERAH_T"Error: query tidak valid\n");
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
        printf(MERAH_T"Kode %s tidak ditemukan\n" RESET, kodeCari);
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
        printf(MERAH_T"Error: query tidak valid\n");
        printf("Gunakan: UPDATE <table> <nim> <namaMK> <kodeMK> <nilai> <grade>;\n" RESET);
        return;
    }

    int found = -1; // variabel penanda 

    for (int i = 0; i < *n; i++){
        if (strcmp(source[i].nim, nimCari) == 0){
            found = i;
        } 
    }

    if (found == -1){
        printf(MERAH_T"Id %s tidak ditemukan\n" RESET, nimCari);
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

    int len = sscanf(query, "%s %s %s %s %s", command, table, baru.nim, baru.nama, baru.prodi);

    // cek apakah query valid
    if (len < 5 && len >= 5) {
        printf(MERAH_T"Error: query tidak valid\n" RESET);
        printf(MERAH_T"Gunakan: INSERT <table> <nim> <nama> <prodi>;\n"RESET);
        return;
    }

    for (int i = 0; i < *n; i++){
        if (strcmp(source[i].nim, baru.nim) == 0){
            printf(MERAH_T"Error: NIM %s sudah ada\n" RESET, baru.nim);
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
        printf(MERAH_T"Error: query tidak valid\n" RESET);
        printf(MERAH_T"Gunakan: INSERT <table> <kodeMK> <namaMK> <SKS>;\n" RESET);
        return;
    }

    // cek duplikat kode MK
    for (int i = 0; i < *n; i++){
        if (strcmp(source[i].kode, new.kode) == 0){
            printf(MERAH_T"Error: kode MK %s sudah ada\n" RESET, new.kode);
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
        printf(MERAH_T"Error: query tidak valid\n" RESET);
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
        strcpy(source[i].prodi, source[i+1].prodi);
    }
    
    (*n)--;
    writeToFileNameMhs(*n, source, "../data/mahasiswa.dat");
    printf("Data dengan NIM %s berhasil dihapus.\n", nimCari);
}
// prosedur delete data mata kuliah.dat
void deleteMataKuliah(char *query, int *n ,mataKuliah *source){
    char command[50], table[50];
    char kodeCari[50];

    int len = sscanf(query, "%s %s %s", command, table, kodeCari);

    // cek apakah query valid
    if (len < 3) {
        printf("Error: query tidak valid\n");
        printf("Gunakan: DELETE <table> <kodeMK>;\n");
        return;
    }

    int found = -1;
    for (int i = 0; i < *n; i++){
        if (strcmp(source[i].kode, kodeCari) == 0){
            found = i;
        }
    }

    if (found == -1){
        printf("Kode %s tidak ditemukan\n", kodeCari);
        return;
    }

    for (int i = found; i < *n - 1; i++){
        strcpy(source[i].kode, source[i+1].kode);
        strcpy(source[i].namaMk, source[i+1].namaMk);
        source[i].SKS = source[i+1].SKS;
    }
    
    (*n)--;
    writeToFileNameMk(*n, source, "../data/mataKuliah.dat");
    printf("Data dengan Kode %s berhasil dihapus.\n", kodeCari);
}
void deleteNilai(char *query, int *n ,nilai *source){
    char command[50], table[50];
    char nimCari[50];  
    int len = sscanf(query, "%s %s %s", command, table, nimCari);
    
    // cek apakah query valid
    if (len < 3) {
        printf("Error: query tidak valid\n");
        printf("Gunakan: DELETE <table> <id>;\n");
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
        strcpy(source[i].kode, source[i+1].kode);   
        source[i].nilai = source[i+1].nilai;
        strcpy(source[i].grade, source[i+1].grade);  
    }
    
    (*n)--;
    writeToFileNameNilai(*n, source, "../data/nilai.dat");
    printf("Data dengan Id %s berhasil dihapus.\n", nimCari);
}

// === PROSEDUR PARSE INPUT ===
void parseInput(char query[], int *n, int *nMK, int *nNilai, mahasiswa source[], mataKuliah sourceMk[], nilai sourceNilai[], int *running) {
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
        }else if (strcmp(table, "TABLES") == 0){
            showTabels();
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
