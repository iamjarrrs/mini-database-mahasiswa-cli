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
    // printf("            "    "|    Type "ORANGE"'HELP ;'"RESET"       for help.             | \n");
    // printf("            "    "|    Type "HIJAU"'SHOW TABLES;'"RESET" to list all tables.   | \n");
    // printf("            "    "|    Type "MERAH"'EXIT;'"RESET"        to quit.              | \n");
    printf("            "    "+----------------------------------------------+ \n");
}

void showTabels(){
    printf("            "KUNING_T"+------------------+\n"RESET);
    printf("            "KUNING_T"|       "BIRU BOLD"DATA"RESET"       "KUNING_T"|\n"RESET);
    printf("            "KUNING_T"+------------------+\n"RESET);
    printf("            "KUNING_T"|   "MAGENTA BOLD"1. MAHASISWA"RESET"   "KUNING_T"|\n"RESET);
    printf("            "KUNING_T"|   "KUNING BOLD"2. MK"RESET"          "KUNING_T"|\n"RESET);
    printf("            "KUNING_T"|   "MERAH_T BOLD"3. NILAI"RESET"       "KUNING_T"|\n"RESET);
    printf("            "KUNING_T"+------------------+\n"RESET);
}

void showHelp(){

}