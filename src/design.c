#include "header.h"

// === BANNER ===

void banner(){
    printf("\n");
    printf(BOLD"          SELAMAT DATANG DI PROGRAM MANAJEMEN DATA MAHASISWA\n" RESET);
    printf(CYAN" _____                                                           _____  \n" RESET);
    printf(CYAN"( ___ )---------------------------------------------------------( ___ ) \n" RESET);
    printf(CYAN" |   |"MAGENTA"           _                _                   _          "CYAN"|   |\n" RESET);
    printf(CYAN" |   |"MAGENTA"     __ _ | | __  __ _   __| |  ___  _ __ ___  (_)  ___    "CYAN"|   |\n" RESET);
    printf(CYAN" |   |"MAGENTA"    / _` || |/ / / _` | / _` | / _ \\| '_ ` _ \\ | | / __|   "CYAN"|   |\n" RESET);
    printf(CYAN" |   |"MAGENTA"   | (_| ||   < | (_| || (_| ||  __/| | | | | || || (__    "CYAN"|   |\n" RESET);
    printf(CYAN" |   |"MAGENTA"    \\__,_||_|\\_\\ \\__,_| \\__,_| \\___||_| |_| |_||_| \\___|   "CYAN"|   |\n" RESET);
    printf(CYAN" |___|"MAGENTA"                                                           "CYAN"|___| \n" RESET);
    printf(CYAN"(_____)---------------------------------------------------------(_____) \n" RESET);
}

void desc(){
    printf("            "    "+----------------------------------------------+ \n");
    printf("            "BOLD"|           "BIRU"Copyright"RESET"(c) 2025, "MERAH_T"J4RZZZ"RESET"          | \n");
    printf("            "BOLD"|      Sistem Informasi Akademik Mahasiswa     | \n");
    printf("            "    "|    Type "ORANGE"'SHOW HELP ;'"RESET"  for help.             | \n");
    printf("            "    "|    Type "HIJAU"'SHOW TABLES;'"RESET" to list all tables.   | \n");
    printf("            "    "|    Type "MERAH"'EXIT;'"RESET"        to quit.              | \n");
    printf("            "    "+----------------------------------------------+ \n");
}

void showTabels(){
    printf("            "KUNING_T"+------------------+\n"RESET);
    printf("            "KUNING_T"|       "BIRU BOLD"DATA"RESET"       "KUNING_T"|\n"RESET);
    printf("            "KUNING_T"+------------------+\n"RESET);
    printf("            "KUNING_T"|   "MAGENTA BOLD"1. MAHASISWA"RESET"   "KUNING_T"|\n"RESET);
    printf("            "KUNING_T"|   "KUNING BOLD"2. MK"RESET"          "KUNING_T"|\n"RESET);
    printf("            "KUNING_T"|   "MERAH_T BOLD"3. NILAI"RESET"       "KUNING_T"|\n"RESET);
    printf("            "KUNING_T"|   "HIJAU_T BOLD"4. PRODI"RESET"       "KUNING_T"|\n"RESET);
    printf("            "KUNING_T"+------------------+\n"RESET);
}

void showHelp(){
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                       "HIJAU_T "GUIDE TO RUNNING THE PROGRAM" RESET"                        |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| Program ini adalah sistem database sederhana berbasis bahasa C yang       |\n");
    printf("| digunakan untuk mengelola data:                                           |\n");
    printf("|   - Mahasiswa                                                             |\n");
    printf("|   - Mata Kuliah                                                           |\n");
    printf("|   - Nilai                                                                 |\n");
    printf("|   - Prodi                                                                 |\n");
    printf("|                                                                           |\n");
    printf("| Program menggunakan file .dat sebagai media penyimpanan dan menerima      |\n");
    printf("| input berupa query sederhana (mirip SQL).                                 |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("| FORMAT PERINTAH (QUERY):                                                  |\n");
    printf("|                                                                           |\n");
    printf("| Note: Setiap query WAJIB diakhiri dengan ';'                              |\n");
    printf("|                                                                           |\n");

    printf("| 1. INSERT                                                                 |\n");
    printf("|                                                                           |\n");
    printf("|    MAHASISWA :                                                            |\n");
    printf("|       INSERT MAHASISWA <nim> <nama> <idProdi> <kodeMK>;                   |\n");
    printf("|       Contoh : INSERT MAHASISWA 12345 Fajar D5451 MK001;                  |\n");
    printf("|                                                                           |\n");

    printf("|    MATA KULIAH :                                                          |\n");
    printf("|       INSERT MK <kodeMK> <namaMK> <sks>;                                  |\n");
    printf("|       Contoh : INSERT MK MK001 Algoritma 3;                               |\n");
    printf("|                                                                           |\n");

    printf("|    NILAI :                                                                |\n");
    printf("|       INSERT NILAI <nim> <kodeMK> <nilai> <grade>;                        |\n");
    printf("|       Contoh : INSERT NILAI 12345 MK001 85 A;                             |\n");
    printf("|       Note  : NIM dan Kode MK harus sudah ada                             |\n");
    printf("|                                                                           |\n");

    printf("|    PRODI :                                                                |\n");
    printf("|       INSERT PRODI <idProdi> <namaProdi>;                                 |\n");
    printf("|       Contoh : INSERT PRODI D5451 Informatika;                            |\n");
    printf("|                                                                           |\n");

    printf("+---------------------------------------------------------------------------+\n");
    printf("| 2. SHOW                                                                   |\n");
    printf("|                                                                           |\n");
    printf("|    SHOW MAHASISWA;   --> Menampilkan data mahasiswa                       |\n");
    printf("|    SHOW MK;          --> Menampilkan data mata kuliah                     |\n");
    printf("|    SHOW NILAI;       --> Menampilkan data nilai                           |\n");
    printf("|    SHOW JOIN;        --> Menampilkan hasil join semua tabel               |\n");
    printf("|    SHOW TABLES;      --> Menampilkan daftar tabel                         |\n");
    printf("|                                                                           |\n");

    printf("+---------------------------------------------------------------------------+\n");
    printf("| 3. UPDATE                                                                 |\n");
    printf("|                                                                           |\n");
    printf("|    MAHASISWA :                                                            |\n");
    printf("|       UPDATE MAHASISWA <nim> <namaBaru> <idProdiBaru> <kodeMKBaru>;       |\n");
    printf("|                                                                           |\n");

    printf("|    MATA KULIAH :                                                          |\n");
    printf("|       UPDATE MK <kodeMK> <namaBaru> <sksBaru>;                            |\n");
    printf("|                                                                           |\n");

    printf("|    NILAI :                                                                |\n");
    printf("|       UPDATE NILAI <nim> <kodeMK> <nilaiBaru> <gradeBaru>;                |\n");
    printf("|                                                                           |\n");

    printf("|    PRODI :                                                                |\n");
    printf("|       UPDATE PRODI <idProdi> <namaProdiBaru>;                             |\n");
    printf("|                                                                           |\n");

    printf("+---------------------------------------------------------------------------+\n");
    printf("| 4. DELETE                                                                 |\n");
    printf("|                                                                           |\n");
    printf("|    MAHASISWA : DELETE MAHASISWA <nim>;                                    |\n");
    printf("|    MK        : DELETE MK <kodeMK>;                                        |\n");
    printf("|    NILAI     : DELETE NILAI <nim>;                                        |\n");
    printf("|    PRODI     : DELETE PRODI <idProdi>;                                    |\n");
    printf("|                                                                           |\n");

    printf("+---------------------------------------------------------------------------+\n");
    printf("| 5. EXIT                                                                   |\n");
    printf("|                                                                           |\n");
    printf("|    EXIT;                                                                  |\n");
    printf("|                                                                           |\n");

    printf("+---------------------------------------------------------------------------+\n");
    printf("| CATATAN PENTING :                                                         |\n");
    printf("|                                                                           |\n");
    printf("| - Data otomatis disimpan ke file setelah perubahan                        |\n");
    printf("| - Data disorting berdasarkan:                                             |\n");
    printf("|     - NIM (Mahasiswa)                                                     |\n");
    printf("|     - Kode MK (Mata Kuliah)                                               |\n");
    printf("| - Tidak boleh ada:                                                        |\n");
    printf("|     - NIM duplikat (Mahasiswa)                                            |\n");
    printf("|     - Kode MK duplikat                                                    |\n");
    printf("|     - ID Prodi duplikat                                                   |\n");
    printf("|     - Kombinasi NIM + MK sama pada tabel Nilai                            |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");

    printf("+---------------------------------------------------------------------------+\n");
    printf("| KEKURANGAN PROGRAM :                                                      |\n");
    printf("|                                                                           |\n");
    printf("| - Tidak mendukung nama dengan spasi (karena parsing menggunakan %%s)       |\n");
    printf("| - Belum mendukung query kompleks seperti WHERE atau SELECT tertentu       |\n");
    printf("| - Tidak ada relasi otomatis (cascade delete) antar tabel                  |\n");
    printf("| - Belum ada validasi penuh terhadap relasi data (foreign key sederhana)   |\n");
    printf("| - Pencarian masih menggunakan linear search (kurang efisien)              |\n");
    printf("| - Parsing query masih sederhana (menggunakan sscanf)                      |\n");
    printf("| - Tidak mendukung multi-user / concurrency                                |\n");
    printf("| - Format file masih sederhana dan belum fleksibel                         |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
}