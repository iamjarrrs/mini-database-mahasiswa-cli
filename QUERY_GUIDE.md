# 📘 QUERY USAGE GUIDE

## ⚠️ Aturan Umum
- Semua query **harus diakhiri dengan tanda `;`**
- Tabel yang tersedia:
  - `MAHASISWA`
  - `MK`
  - `NILAI`
- Gunakan `_` (underscore) untuk menggantikan spasi
- Penulisan huruf besar/kecil **berpengaruh** 

---

## 🔍 SHOW

Menampilkan seluruh data pada tabel.

### Format
    SHOW <TABLES> ;
### Contoh
    SHOW MAHASISWA;
    SHOW MK;
    SHOW NILAI;

---

## ❌ DELETE

Menghapus data berdasarkan key tertentu.

### Format
    DELETE MAHASISWA <NIM> ;
    DELETE MK <KODE_MK>;
    DELETE NILAI <NIM>;
### Contoh
    DELETE MAHASISWA 2501001;
    DELETE MATAKULIAH MK001;
    DELETE NILAI 2501001 MK001;

---

## ➕ INSERT

Menambahkan data ke dalam tabel.

### Format
    INSERT <MAHASISWA> <NIM> <NAMA> <PRODI> ;
    INSERT <MK> <KODE_MK> <NAMA_MK> <SKS>;
    INSERT <NILAI> <NIM> <NILAI> <GRADE>;
### Contoh
    UPDATE MAHASISWA 2501001 Andi_Putra Hukum;
    UPDATE MATAKULIAH MK001 Algoritma_Lanjut 3;
    UPDATE NILAI 2501001 MK001 90.00 A;

---

## ✏️ UPDATE

Mengubah data yang sudah ada.

### Format
    UPDATE MAHASISWA <NIM> <NAMA_BARU> <PRODI_BARU>; 
    UPDATE MK <KODE_MK> <MK> <SKS>;
    UPDATE NILAI <NIM> <KODE_MK> <NILAI> <GRADE>
### Contoh
    UPDATE MAHASISWA 2501001 Andi_Putra Hukum;
    UPDATE MATAKULIAH MK001 Algoritma_Lanjut 3;
    UPDATE NILAI 2501001 MK001 90.00 A;

---

## 📌 Ketentuan UPDATE

### MAHASISWA
- Primary key: `NIM`
- Jika NIM tidak ditemukan → update gagal
- Jika hanya ingin mengubah satu data:
  - Ubah **nama saja** → isi prodi lama
  - Ubah **prodi saja** → isi nama lama

---

### MK
- Primary key: `KODE_MK`
- Jika kode tidak ditemukan → update gagal

---

### NILAI
- Menggunakan kombinasi `NIM` dan `KODE_MK`
- Data harus sudah ada sebelum di-update

---

### Contoh
- UPDATE MAHASISWA 2501001 Andi_Putra Hukum;
- UPDATE MK MK001 Algoritma_lanjut 3;
- UPDATE NILAI 2501001 MK001 90.00 A;

---

## 💡 Tips
- Gunakan `SHOW` sebelum melakukan `UPDATE` atau `DELETE`
- Pastikan jumlah parameter sesuai:
  - **MAHASISWA** → NIM Nama Prodi
  - **MK** → Kode Nama SKS
  - **NILAI** → NIM Kode Nilai Grade
- Query tanpa `;` **tidak akan diproses**