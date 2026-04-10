#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 51

// Warna teks
#define RESET   "\033[0m"
#define BOLD    "\033[1m"

// Warna biasa
#define HITAM   "\033[30m"
#define MERAH   "\033[31m"
#define HIJAU   "\033[32m"
#define KUNING  "\033[33m"
#define BIRU    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define PUTIH   "\033[37m"
#define ORANGE  "\033[38;5;208m"

// Warna terang
#define MERAH_T   "\033[91m"
#define HIJAU_T   "\033[92m"
#define KUNING_T  "\033[93m"
#define BIRU_T    "\033[94m"
#define MAGENTA_T "\033[95m"
#define CYAN_T    "\033[96m"
#define PUTIH_T   "\033[97m"

// Warna background
#define BG_HITAM   "\033[40m"
#define BG_MERAH   "\033[41m"
#define BG_HIJAU   "\033[42m"
#define BG_KUNING  "\033[43m"
#define BG_BIRU    "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN    "\033[46m"
#define BG_PUTIH   "\033[47m"

// === DEFINISI GLOBAL VARIABLE ===
/* typedef struct mahasiswa; */
typedef struct{
    char nim[10];
    char nama[50];
    char kodeMK[50];
    char idProdi[10];
} mahasiswa;

/* typedef struct mataKuliah; */
typedef struct {
    char kode[10];
    char namaMk[50];
    int SKS;
} mataKuliah;

typedef struct{
    char nim[10]; 
    char kode[10]; 
    float nilai;
    char grade[3];
} nilai;

typedef struct {
    char idProdi[10];
    char prodi[50];
} prodi;



// fungsi cetak garis
#define PRINT_LINE(l, r, mid, w1, w2, w3, w4) \
    printf("%s", l); \
    for(int _i=0;_i<w1+2;_i++) printf("\xe2\x94\x80"); \
    printf("%s", mid); \
    for(int _i=0;_i<w2+2;_i++) printf("\xe2\x94\x80"); \
    printf("%s", mid); \
    for(int _i=0;_i<w3+2;_i++) printf("\xe2\x94\x80"); \
    printf("%s", mid); \
    for(int _i=0;_i<w4+2;_i++) printf("\xe2\x94\x80"); \
    printf("%s\n", r);

// === BANNER ===
void banner();
void desc();
void showTabels();
void showHelp();

// === PROSEDUR WRITE TO FILE ===
void writeToFileNameMhs(int n, mahasiswa source[], char fileName[]);
void writeToFileNameMk(int n, mataKuliah source[], char fileName[]);
void writeToFileNameNilai(int n, nilai source[], char fileName[]);
void writeFileNameProdi(int n, prodi source[], char fileName[]);

// === PROSEDUR READ FROM FILE ===
void readFileNameMhs(int *n, mahasiswa source[], char fileName[]);
void readFileNameMk(int *n, mataKuliah source[], char fileName[]);
void readFileNameNilai(int *n, nilai source[], char fileName[]);
void readFileNameProdi(int *n, prodi source[], char fileName[]);

// === PROSEDUR SHOW DATA ===
void showDataMhs(int *n, mahasiswa source[]);
void showDataMk(int *n, mataKuliah source[]);
void showDataNilai(int *n, nilai source[]);
void showDataProdi(int *n, prodi source[]);

// === PROSEDUR UPDATE FILE ===
void updateFileNameMhs(char *query, int *n, mahasiswa source[]);
void updateFileNameMk(char *query, int *n, mataKuliah source[]);
void updateFileNameNilai(char *query, int *n, nilai source[]);
void updateFileNameProdi(char *query, int *n, prodi source[]);

// === PROSEDUR DELETE FILE ===
void deleteMahasiswa(char *query, int *n ,mahasiswa *source);
void deleteMataKuliah(char *query, int *n ,mataKuliah *source);
void deleteNilai(char *query, int *n ,nilai *source);
void deleteProdi(char *query, int *n, prodi *source);

// === PROSEDUR INPUT DATA ===
void insertMahasiswa(char *query, mahasiswa *source, int *n);
void insertmataKuliah(char *query, mataKuliah *source, int *n);
void insertNilai(char *query, nilai *source, int *n, mataKuliah *sourceMk, int *nMK);
void insertProdi(char *query, prodi *source, int *n);

// === PROSEDUR PARSE INPUT ===
void parseInput(char query[], int *n, int *nMK, int *nNilai, int *nProdi, mahasiswa source[], mataKuliah sourceMk[], nilai sourceNilai[], prodi sourceProdi[], int *running);
// === Fungsi cek data ===
int cekMK(char *kodeMK, char fileName[]);
int cekProdi(char *idProdi, char fileName[]);

// === PROSEDUR JOIN ===
void showJoin(mahasiswa m[], int nMhs, prodi p[], int nProdi, mataKuliah mk[], int nMK, nilai ni[], int nNilai);