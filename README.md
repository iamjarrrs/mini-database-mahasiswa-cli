# 💻 Mini Database Mahasiswa (CLI)

![C](https://img.shields.io/badge/language-C-blue)
![CLI](https://img.shields.io/badge/interface-CLI-green)
![Status](https://img.shields.io/badge/status-finished-brightgreen)

A simple CLI-based database system written in **C** that supports query commands similar to SQL.

---

## 👨‍💻 Author
Afit Fajar Rianto

---

## 🚨 SEBELUM ANDA MULAI

📌 **Harap baca dokumentasi query terlebih dahulu:**

## 📖 Documentation

Full query guide available here:  
👉 [QUERY_GUIDE.md](QUERY_GUIDE.md)

Tanpa mengikuti format query yang benar, program tidak akan berjalan dengan baik.

---

## ✨ Features

- Query-based system:
  - `SHOW`
  - `INSERT`
  - `UPDATE`
  - `DELETE`
- Manage data:
  - 👨‍🎓 Mahasiswa
  - 📚 Mata Kuliah (MK)
  - 📝 Nilai
  - 🏫 Prodi
- 🔗 JOIN antar tabel (Mahasiswa + MK + Nilai + Prodi)
- CLI table output (rapi & berwarna)
- File-based storage (`.dat`)
- Sorting otomatis saat insert

---

## 🗄️ Database Structure

- **MAHASISWA**
  - NIM (Primary Key)
  - Nama
  - ID Prodi
  - Kode MK

- **MK**
  - Kode MK (Primary Key)
  - Nama MK
  - SKS

- **NILAI**
  - NIM
  - Kode MK
  - Nilai
  - Grade  
  - *(Composite Key: NIM + Kode MK)*

- **PRODI**
  - ID Prodi (Primary Key)
  - Nama Prodi

---

## 📂 Project Structure

```bash
.
├── data/
│   ├── mahasiswa.dat
│   ├── mk.dat
│   ├── nilai.dat
│   └── prodi.dat
│
├── src/
│   ├── main.c
│   ├── machine.c
│   ├── design.c
│   └── header.h
│
├── preview/
│
├── QUERY_GUIDE.md
└── README.md