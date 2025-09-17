# TP1DPBO2425C1

Saya Hawa Dwiafina Azahra dengan NIM 2400336 mengerjakan Tugas Praktikum 1 dalam mata kuliah Desain dan Pemrograman Berorientasi Objek untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.


CPP

Design

1. Class Barang
     atribut (private)
     - string kode → kode barang
     - string nama → nama barang
     - string harga → harga barang
     - string merk → merk barang
     - string garansi → garansi barang
     - int stok → stok barang

2.  method (public)

    A. constructor
     - Barang() → constructor kosong
     - Barang(string kode, string nama, string harga, string merk, string garansi, int stok) → constructor berisi
    
    B. Getter dan Setter
     - getKode() / setKode(string kode)
     - getNama() / setNama(string nama)
     - getHarga() / setHarga(string harga)
     - getMerk() / setMerk(string merk)
     - getGaransi() / setGaransi(string garansi)
     - getStok() / setStok(int stok)

    C. Fungsi CRUD
     - tambahBarang(Barang daftar[], int &jumlah, int kapasitas)
     - tampilkanSemua(Barang daftar[], int jumlah)
     - ubahBarang(Barang daftar[], int jumlah)
     - hapusBarang(Barang daftar[], int &jumlah)
     - searchBarang(Barang daftar[], int jumlah)
     - tampilkan() → tampilkan detail 1 barang
       
    D. Destructor
     - ~Barang()
   

Flow code

1. Inisialisasi
   - Buat array Barang daftar[5] untuk menampung data barang (maksimal 5).
   - Buat variabel jumlah = 0 untuk menghitung jumlah barang yang sudah tersimpan.
   - Buat variabel pilihan untuk menyimpan input menu.
   - Buat objek Barang b agar bisa memanggil fungsi-fungsi class.

2. Mulai Perulangan Menu (while loop)
   - menu akan terus ditampilkan sampai user memilih keluar (while != 6).

3. Menampilkan Menu
    
     === Menu Toko Elektronik ===
     1. Tambah Barang Baru
     2. Tampilkan Semua Barang
     3. Ubah Data Barang
     4. Hapus Barang
     5. Cari Barang
     6. Keluar Program

4. Output yang Dihasilkan Berdasarkan Input User
   
   A. Jika pilihan == 1 → Tambah Barang Baru
   - Panggil b.tambahBarang(daftar, jumlah, 5).
   - Program minta input data barang (kode, nama, harga, merk, garansi, stok).
   - Data disimpan ke array daftar[jumlah].
   - jumlah++ (jumlah barang bertambah).
     
   B. Jika pilihan == 2 → Tampilkan Semua Barang
   - Panggil b.tampilkanSemua(daftar, jumlah).
   - Jika jumlah == 0, tampilkan pesan "Belum ada data barang".
   - Jika ada, loop tampilkan detail setiap barang.
     
   C. Jika pilihan == 3 → Ubah Data Barang
   - Panggil b.ubahBarang(daftar, jumlah).
   - Program minta user input kode barang yang mau diubah.
   - Cari barang berdasarkan kode.
   - Jika ketemu → minta input data baru (nama, harga, merk, garansi, stok), lalu update.
   - Jika tidak ketemu → tampilkan "Barang tidak ditemukan".
     
   D. Jika pilihan == 4 → Hapus Barang
   - Panggil b.hapusBarang(daftar, jumlah).
   - Program minta input kode barang yang mau dihapus.
   - Cari barang berdasarkan kode.
   - Jika ketemu → hapus dengan cara menggeser elemen array ke kiri.
   - jumlah-- (jumlah barang berkurang).
   - Jika tidak ketemu → tampilkan "Barang tidak ditemukan".
     
   E. Jika pilihan == 5 → Cari Barang
   - Panggil b.searchBarang(daftar, jumlah).
   - Program minta input kode barang.
   - Cari barang dengan loop.
   - Jika ketemu → tampilkan detail barang.
   - Jika tidak ketemu → tampilkan pesan "Barang tidak ditemukan".
     
   F. Jika pilihan == 6 → Keluar Program
   - Tampilkan pesan "Terima kasih telah mengunjungi toko ini!".
   - Keluar dari perulangan while.
     
   G. Jika input selain 1–6
   - Tampilkan pesan "Pilihan tidak valid! Silakan pilih angka 1–6".
   - Kembali ke menu.

6. Akhir Program
   - Setelah user memilih 6, loop berhenti.
   - Program selesai dengan return 0;.
  
Dokumentasi
[Video Dokumentasi](Dokumentasi/cpp.mp4)

PYTHON

Design

1. Class Barang
   
   A. atribut private
   - kode barang
   - garansi barang
   - stok barang
  
   B. atribut public
   - nama barang
   - harga barang
   - merk barang

3. Method (public)
   
   A. Constructor
   - _init_(self, kode: str, nama: str, harga: str, merk: str, garansi: str, stok: int)
   - Menginisialisasi atribut sesuai argumen. Konversi: self._kode = str(kode), self._stok = int(stok); yang lain diset sebagai str(...).
     
   B. Getter Setter
   - getKode() / setKode(kode)
   - getNama() / setNama(nama)
   - getHarga() / setHarga(harga)
   - getMerk() / setMerk(merk)
   - getGaransi() / setGaransi(garansi)
   - getStok() / setStok(stok)
     
4. Utility
   - tampilkan() → menampilkan detail barang ke layar
   
Flow code

1. Inisialisasi
   - Program mulai: main() dipanggil.
   - daftar_barang = [None] * 5 → list kapasitas 5; semua None.
   - jumlah_barang = 0.
   - Loop while True: dimulai.

2. Loop Menu (while True)
   - Tampilkan menu 1..6.
   - pilihan = input("Pilih menu: ") (string).
   - Switch pada pilihan:
        - "1" → jalankan blok Tambah Barang.
        - "2" → Tampilkan Semua.
        - "3" → Ubah Barang.
        - "4" → Hapus Barang.
        - "5" → Cari Barang.
        - "6" → Keluar (break).
        - selain di atas → cetak "Pilihan tidak valid."
          
3. Output yang dihasilkan berdasarkan input user
   
   A. Jika pilihan == 1 → Tambah Barang Baru
   - Cek kapasitas: if jumlah_barang < 5.
   - Jika True, minta 6 input user. (Jika stok input bukan angka → int() akan raise ValueError dan crash kecuali ditangani; program asli tidak menangani ini.)
   - Buat objek Barang(...) dengan nilai input (memanggil init => menyimpan ke atribut).
   - Simpan objek di daftar_barang[jumlah_barang].
   - jumlah_barang bertambah 1 (state berubah).
     
   B. Jika pilihan == 2 → Tampilkan Semua Barang
   - Jika jumlah_barang == 0 → pesan "Belum ada data barang."
   - Else → iterasi i = 0 .. jumlah_barang-1 → untuk tiap objek panggil tampilkan() untuk mencetak detail.
     
   C. Jika pilihan == 3 → Ubah Data Barang
   - Minta kode_cari.
   - index = -1.
   - Loop i = 0 .. jumlah_barang-1:
        - Kondisi if index == -1 and daftar_barang[i].getKode() == kode_cari:=> jika index masih -1 dan kode cocok, set index = i.
        - Karena cek index == -1 dipakai, setelah menemukan 1 pencocokan, index tidak akan lagi diubah (meskipun loop tetap jalan sampai akhir). Praktis => menemukan pertama, sama seperti break tapi tanpa menghentikan loop.
   - Setelah loop:
        - Jika index == -1 → tidak ditemukan.
        - Jika ditemukan → input nilai baru → panggil setNama, setHarga, setMerk, setGaransi, setStok pada daftar_barang[index].
     
   D. Jika pilihan == 4 → Hapus Barang
   - Minta kode_cari.
   - Cari index sama persis seperti menu 3.
   - Jika tidak ditemukan → pesan.
   - Jika ditemukan:
        - Geser semua elemen dari index+1..jumlah_barang-1 satu posisi ke kiri.
        - Kosongkan daftar_barang[jumlah_barang-1] = None.
        - Decrement jumlah_barang.
     
   E. Jika pilihan == 5 → Cari Barang
   - Jika tidak ada data → pesan.
   - Else → input kode, cari seperti menu 3/4.
   - Jika ketemu → cetak detail tampilkan().
   - Jika tidak → pesan tidak ditemukan.
     
   F. Jika pilihan == 6 → Keluar Program
   - Tampilkan pesan "Terima kasih telah mengunjungi toko ini!".
   - Keluar dari perulangan while.
     
   G. Jika input selain 1–6
   - print("Terima kasih!") lalu break loop → program selesai.

Dokumentasi
[Video Dokumentasi](Dokumentasi/python.mp4)

JAVA

Design

1. Class barang
   - kode barang
   - nama barang
   - harga barang
   - merk barang
   - garansi barang
   - stok barang

2. method
   
  A. Constructor
   - Barang(String kode, String nama, String harga, String merk, String garansi, int stok) → Membuat objek baru dengan atribut terisi
     
   B. Getter Setter
   - getKode() : String
   - getNama() : String
   - getHarga() : String
   - getMerk() : String
   - getGaransi() : String
   - getStok() : int
   - setKode(String kode)
   - setNama(String nama)
   - setHarga(String harga)
   - setMerk(String merk)
   - setGaransi(String garansi)
   - setStok(int stok)
     
   C. Utility
   - tampilkan() : void

Flow Code

1. Inisialisasi
   - Buat Scanner input
   - Buat array Barang[] daftarBarang = new Barang[5]
   - Set jumlahBarang = 0
   - Deklarasi pilihan untuk menu

2. Loop Menu (while True)
   - Tampilkan menu 1..6.
     1. Tambah Barang
     2. Tampilkan Semua Barang
     3. Ubah Barang
     4. Hapus Barang
     5. Cari Barang
     6. Keluar
          
3. Output yang dihasilkan berdasarkan input user
   
   A. Jika pilihan == 1 → Tambah Barang Baru
   - Jika jumlahBarang < 5:
        - Input data barang (kode, nama, harga, merk, garansi, stok)
        - Buat objek Barang → simpan ke daftarBarang[jumlahBarang]
        - jumlahBarang++
        - Cetak "Barang berhasil ditambahkan"
   - Else → "Data penuh"
     
   B. Jika pilihan == 2 → Tampilkan Semua Barang
   - Jika jumlahBarang == 0 → "Belum ada data barang"
   - Else → loop for (i=0; i<jumlahBarang; i++) → panggil .tampilkan()
     
   C. Jika pilihan == 3 → Ubah Data Barang
   - Input kode barang
   - Cari index dengan loop (equals(kodeCari))
   - Jika tidak ditemukan → "Barang tidak ditemukan"
   - Jika ditemukan:
        - Input data baru (nama, harga, merk, garansi, stok)
        - Update dengan setter
        - Cetak "Barang berhasil diubah"
     
   D. Jika pilihan == 4 → Hapus Barang
   - Input kode barang
   - Cari index barang
   - Jika tidak ditemukan → "Barang tidak ditemukan"
   - Jika ditemukan:
        - Geser array ke kiri mulai dari index ditemukan
        - jumlahBarang--
        - Cetak "Barang berhasil dihapus"
     
   E. Jika pilihan == 5 → Cari Barang
   - Jika jumlahBarang == 0 → "Belum ada data barang"
   - Else:
        - Input kode barang
        - Validasi (tidak boleh kosong)
        - Cari index dengan loop
        - Jika tidak ketemu → "Barang tidak ditemukan"
        - Jika ketemu → cetak detail barang .tampilkan()
     
   F. Jika pilihan == 6 → Keluar Program
   -Keluar dari loop
   Cetak "Terima kasih!"
     
   G. Jika input selain 1–6
   - Cetak "Pilihan tidak valid"

Dokumentasi
[Video Dokumentasi](Dokumentasi/java.mp4)

PHP

Design
1. Class barang
   - kode barang
   - nama barang
   - harga barang
   - merk barang
   - garansi barang
   - stok barang
   - gambar barang

2. method

   A. Consttructor
   - __construct(kode, nama, harga, merk, garansi, stok, gambar)

   B. Getter setter
   - getKode(): string
   - setKode(kode: string): void
   - getNama(): string
   - setNama(nama: string): void
   - getHarga(): string
   - setHarga(harga: string): void
   - getMerk(): string
   - setMerk(merk: string): void
   - getGaransi(): string
   - setGaransi(garansi: string): void
   - getStok(): int
   - setStok(stok: int): void
   - getGambar(): string
   - setGambar(gambar: string): void
     
Flow code

1. Inisialisasi
   - require_once 'Barang.php' → load class.
   - session_start() → aktifkan session.
   - Jika folder foto/ belum ada → buat folder.
   - Jika $_SESSION['barang'] belum ada → inisialisasi array kosong.
          
2. Output yang dihasilkan berdasarkan input user
   
   A. Tambah Barang Baru
   - Cek apakah tombol Tambah ditekan (isset($_POST['tambah'])).
   - Ambil data input form (kode, nama, harga, merk, garansi, stok).
   - Jika ada file gambar diupload:
        - Sanitasi nama file.
        - Simpan ke folder foto/.
   - Buat objek Barang baru dengan data input + path gambar.
   - Simpan objek ke $_SESSION['barang'][].
   - Redirect halaman supaya tidak submit ulang ketika refresh.
   - User mengisi form tambah dan klik Tambah.
   - server menerima $_POST + $_FILES (gambar).
   - jika ada file gambar → sanitasi nama, beri nama unik (timestamp), move_uploaded_file ke foto/.
   - buat objek Barang(...) dan $_SESSION['barang'][] = $barang.
   - redirect ke index untuk mencegah resubmit.
     
   B. Tampilan
   - Form Tambah Barang.
   - Form Search Barang.
   - Tabel daftar barang:
        - No, Gambar, Kode, Nama, Harga, Merk, Garansi, Stok.
        - Tombol Edit & Hapus per barang.
   - Jika tidak ada barang → tampil pesan Barang tidak ditemukan.
     
   C. Ubah Data Barang
   - Masuk ke halaman edit (GET)
        - user klik link Edit pada baris tabel: edit.php?id=<index>.
        - edit.php melakukan session_start() dan memeriksa:
             - jika id tidak diset atau $_SESSION['barang'][$id] tidak ada → tampil pesan "Barang tidak ditemukan" dan exit().
        - jika ada → ambil objek: $barang = $_SESSION['barang'][$id];
        - tampilkan form edit dengan nilai awal (value="<?= $barang->getNama() ?>", dsb.) dan preview gambar (<img src="<?= $barang->getGambar() ?>">).
   - Submit perubahan (POST update)
        - user ubah field dan (opsional) unggah gambar baru, lalu klik Update.
        - server masuk ke blok if (isset($_POST['update'])) { ... }.
        - update atribut objek dari $_POST:
             - $barang->setNama($_POST['nama']); dst.
        - jika ada upload gambar baru ($_FILES['gambar'] && error == 0):
             - buat nama file unik (time() . '_' . basename(...)), pindahkan file ke foto/ (move_uploaded_file) dan $barang->setGambar($gambarPath).
             - Catatan (opsional): kode saat ini tidak menghapus gambar lama — bisa ditambahkan jika ingin membersihkan file lama.
        - simpan kembali ke session: $_SESSION['barang'][$id] = $barang;.
        - redirect ke index.php untuk menampilkan perubahan.
     
   D. Hapus Barang
   - user klik link Hapus.
   - server ambil index dari query string.
   - hapus file gambar terkait (jika ada dan file exists).
   - unset($_SESSION['barang'][$index]) lalu $_SESSION['barang'] = array_values(...) untuk reindex.
   - redirect kembali ke index.
     
   E. Cari Barang
   - user mengisi kata kunci di form search dan submit.
   - server membaca $_POST['search'].
   - loop $_SESSION['barang'], cocokkan getKode() atau getNama() dengan keyword (exact match).
   - hasil disimpan di $hasilSearch dan ditampilkan di tabel; jika tidak ada → tampil pesan "Barang tidak ditemukan".
   - (Jika tidak ada pencarian, tampilkan seluruh $_SESSION['barang'].)

Dokumentasi
[Video Dokumentasi](Dokumentasi/PHP.mp4)
