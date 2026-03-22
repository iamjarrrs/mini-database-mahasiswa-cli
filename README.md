# 💻 Mini Database Mahasiswa (CLI)

![C](https://img.shields.io/badge/language-C-blue)
![CLI](https://img.shields.io/badge/interface-CLI-green)
![Status](https://img.shields.io/badge/status-finished-brightgreen)

A simple CLI-based database system written in **C** that supports query commands similar to SQL.

```md
## 👨‍💻 Author
Afit Fajar Rianto
```

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
  - SHOW
  - INSERT
  - UPDATE
  - DELETE
- Manage data:
  - 👨‍🎓 Mahasiswa
  - 📚 Mata Kuliah (MK)
  - 📝 Nilai
- CLI table output
- File-based storage (`.dat`)

---

```md
## 🗄️ Database Structure

- **MAHASISWA** → menyimpan data mahasiswa (NIM, Nama, Prodi)
- **MK** → menyimpan data mata kuliah (Kode, Nama, SKS)
- **NILAI** → menyimpan nilai mahasiswa (NIM, Kode MK, Nilai, Grade)
``` 
---

## 📂 Project Structure
```bash
.
├── data/
│   ├── mahasiswa.dat
│   ├── mk.dat
│   └── nilai.dat
│
├── src/
│   ├── main.c
│   ├── machine.c
│   ├── design.c
│   └── header.h
├── preview/
│   
├── QUERY_GUIDE.md
└── README.md 
```
--- 

## 🚀 How to Run 
### Compile
```bash
gcc src/main.c src/machine.c src/design.c -o app 

```

---

## 📸 Preview

### 🔍 Show Data
![Show Mahasiswa](preview/SHOW%20MAHASISWA.png)

### ➕ Insert Data
![Insert Mahasiswa](preview/INSERT%20MAHASISWA.png)

### ✏️ Update Data
![Update Mahasiswa](preview/UPDATE%20MAHASISWA.png)

### ❌ Delete Data
![Delete Mahasiswa](preview/DELETE%20Mahasiswa.png)

---

## ⚠️ Limitations
- Tidak menggunakan database nyata (masih file `.dat`)
- Belum mendukung query kompleks (WHERE, JOIN, dll)
- Case-sensitive input

---
## 🚀 Future Improvements
- Add WHERE (search query)
- Add sorting data
- Improve CLI UI
---