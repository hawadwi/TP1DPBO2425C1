#include <bits/stdc++.h>

using namespace std;

/* Class untuk menyimpan data barang di toko Semua data barang 
disimpan dalam variabel private supaya aman */
class Barang
{
private:
    // Data-data barang yang disimpan sebagai private
    // Kenapa private? Supaya tidak bisa diubah sembarangan dari luar class
    string kode;     // Kode unik barang
    string nama;     // Nama barang
    string harga;    // Harga barang 
    string merk;     // Merk barang
    string garansi;  // Lama garansi
    int stok;        // Jumlah barang yang tersedia

public:
    // Constructor kosong - bikin objek barang dengan data kosong
    // Dipake kalau mau bikin array barang tapi belum tau isinya, karena datanya di isi oleh user
    Barang() {
        kode = "";
        nama = "";
        harga = "";
        merk = "";
        garansi = "";
        stok = 0;
    }

    // Constructor lengkap - langsung isi semua data barang sekaligus
    // Dipake kalau udah tau semua data barangnya
    Barang(string kode, string nama, string harga, string merk, string garansi, int stok){
        this->kode = kode;
        this->nama = nama;
        this->harga = harga;
        this->merk = merk;
        this->garansi = garansi;
        this->stok = stok;
    }

    // Getter dan Setter - cara aman untuk akses data private
    // Getter untuk ambil data, Setter untuk ubah data
    string getKode(){
        return kode;
    }

    void setKode(string kode){
        this->kode = kode;
    }

    string getNama(){
        return nama;
    }

    void setNama(string nama){
        this->nama = nama;
    }

    string getHarga(){
        return harga;
    }

    void setHarga(string harga){
        this->harga = harga;
    }

    string getMerk(){
        return merk;
    }

    void setMerk(string merk){
        this->merk = merk;
    }

    string getGaransi(){
        return garansi;
    }

    void setGaransi(string garansi){
        this->garansi = garansi;
    }

    int getStok(){
        return stok;
    }

    void setStok(int stok){
        this->stok = stok;
    }

    // Method untuk nampilin semua data barang ke layar
    // Dipake kalau mau liat detail barang
    void tampilkan() {
            cout << "Kode: " << kode << endl;
            cout << "Nama: " << nama << endl;
            cout << "Harga: " << harga << endl;
            cout << "Merk: " << merk << endl;
            cout << "Garansi: " << garansi << endl;
            cout << "Stok: " << stok << endl;
    }

    // Method untuk nambah barang baru ke dalam array
    // Parameter: array barang, jumlah barang saat ini, kapasitas maksimal array
    void tambahBarang(Barang daftar[], int &jumlah, int kapasitas) {
        string kode, nama, harga, merk, garansi;
        int stok;
        
        // Cek dulu apakah array masih ada tempat atau udah penuh
        if (jumlah >= kapasitas) {
            cout << "Data penuh.\n";
            return;
        }

        cout << "\n=== PETUNJUK INPUT ===\n";
        cout << "Karena tidak bisa pakai spasi, gunakan underscore (_) untuk 2 kata atau lebih\n";
        cout << "Contoh: Samsung_Galaxy, Laptop_Gaming, dll\n";
        cout << "=====================\n\n";

        // Minta user input semua data barang
        cout << "Kode : ";
        cin >> kode;
        cout << "Nama : ";
        cin >> nama;
        cout << "Harga : ";
        cin >> harga;
        cout << "Merk : ";
        cin >> merk;
        cout << "Garansi : ";
        cin >> garansi;
        cout << "Stok: ";
        cin >> stok;

        // Bikin objek barang baru dengan data yang diinput, terus masukin ke array
        daftar[jumlah] = Barang(kode, nama, harga, merk, garansi, stok);
        jumlah++; // Tambah jumlah barang

        cout << "Barang berhasil ditambahkan.\n";
    }

    // Method untuk nampilin semua barang yang ada di array
    void tampilkanSemua(Barang daftar[], int jumlah) {
        // Kalau belum ada barang sama sekali, kasih tau user
        if (jumlah == 0) {
            cout << "Belum ada data barang.\n";
            return;
        }

        // Loop untuk nampilin semua barang satu per satu
        for (int i = 0; i < jumlah; i++) {
            cout << "\nBarang ke-" << (i + 1) << ":\n";
            daftar[i].tampilkan();
        }
    }

    // Method untuk ubah data barang yang udah ada
    // Cara kerjanya: cari barang berdasarkan kode, kalau ketemu baru diubah
    void ubahBarang(Barang daftar[], int jumlah) {
        string cariKode, nama, harga, merk, garansi;
        int stok;
        
        cout << "Masukkan kode barang yang ingin diubah: ";
        cin >> cariKode;

        // Pakai while loop dengan 2 kondisi: belum sampai akhir array DAN belum ketemu
        int i = 0, ketemu = 0;
        while (i < jumlah && ketemu == 0) {
            if (daftar[i].getKode() == cariKode) {
                ketemu = 1; // Tandai kalau udah ketemu, loop akan berhenti
            } else {
                i++; // Kalau belum ketemu, lanjut ke barang berikutnya
            }
        }

        // Kalau setelah loop selesai masih belum ketemu, berarti barang tidak ada
        if (ketemu == 0) {
            cout << "Barang tidak ditemukan.\n";
            return;
        }

        cout << "\n=== PETUNJUK INPUT ===\n";
        cout << "Gunakan underscore (_) untuk 2 kata atau lebih\n";
        cout << "Contoh: Samsung_Galaxy, Laptop_Gaming, dll\n";
        cout << "=====================\n\n";

        // Kalau ketemu, minta input data baru dari user
        cout << "Nama baru : ";
        cin >> nama;
        cout << "Harga baru : ";
        cin >> harga;
        cout << "Merk baru : ";
        cin >> merk;
        cout << "Garansi baru : ";
        cin >> garansi;
        cout << "Stok baru : ";
        cin >> stok;

        // Update data barang di posisi yang ketemu tadi
        daftar[i].setNama(nama);
        daftar[i].setHarga(harga);
        daftar[i].setMerk(merk);
        daftar[i].setGaransi(garansi);
        daftar[i].setStok(stok);

        cout << "Data berhasil diubah.\n";
    }

    // Method untuk hapus barang dari array berdasarkan kode
    // Cara kerjanya: cari barang, kalau ketemu hapus dengan menggeser array
    void hapusBarang(Barang daftar[], int &jumlah) {
        string cariKode;
        
        cout << "Masukkan kode barang yang ingin dihapus: ";
        cin >> cariKode;

        // Pakai while loop dengan 2 kondisi: belum sampai akhir array DAN belum ketemu
        int i = 0, ketemu = 0;
        while (i < jumlah && ketemu == 0) {
            if (daftar[i].getKode() == cariKode) {
                ketemu = 1; // Tandai kalau udah ketemu, loop akan berhenti
            } else {
                i++; // Kalau belum ketemu, lanjut ke barang berikutnya
            }
        }

        // Kalau setelah loop selesai masih belum ketemu, berarti barang tidak ada
        if (ketemu == 0) {
            cout << "Barang tidak ditemukan.\n";
            return;
        }

        // Kalau ketemu, geser semua barang setelahnya ke kiri untuk hapus barang
        // Ini seperti nutup lubang di array dengan menggeser elemen-elemen
        for (int j = i; j < jumlah - 1; j++) {
            daftar[j] = daftar[j + 1];
        }
        
        jumlah--; // Kurangi jumlah barang karena udah dihapus satu
        cout << "Barang berhasil dihapus.\n";
    }

    // Method untuk cari barang berdasarkan kode dan nampilin detailnya
    void searchBarang(Barang daftar[], int jumlah) {
        string cariKode;
        
        // Petunjuk penggunaan underscore untuk search
        cout << "\n=== PETUNJUK PENCARIAN ===\n";
        cout << "Gunakan underscore (_) jika kode barang mengandung 2 kata atau lebih\n";
        cout << "Contoh: Samsung_Galaxy, Laptop_Gaming, dll\n";
        cout << "========================\n\n";
        
        cout << "Masukkan kode barang yang dicari: ";
        cin >> cariKode;

        // Validasi input kosong atau hanya spasi
        if (cariKode.empty()) {
            cout << "Kode barang tidak boleh kosong!\n";
            return;
        }

        // Cek dulu apakah ada data barang
        if (jumlah == 0) {
            cout << "Belum ada data barang untuk dicari.\n";
            return;
        }

        // Pakai while loop dengan 2 kondisi: belum sampai akhir array DAN belum ketemu
        int i = 0, ketemu = 0;
        while (i < jumlah && ketemu == 0) {
            if (daftar[i].getKode() == cariKode) {
                ketemu = 1; // Tandai kalau udah ketemu, loop akan berhenti
            } else {
                i++; // Kalau belum ketemu, lanjut ke barang berikutnya
            }
        }

        // Tampilkan hasil pencarian
        if (ketemu == 1) {
            cout << "\n" << string(50, '=') << "\n";
            cout << "           BARANG DITEMUKAN!\n";
            cout << string(50, '=') << "\n";
            daftar[i].tampilkan();
            cout << string(50, '=') << "\n";
            cout << "Pencarian berhasil!\n";
        } else {
            cout << "\nBarang dengan kode '" << cariKode << "' tidak ditemukan.\n";
            cout << "Pastikan kode yang dimasukkan benar.\n";
        }
    }


    // Destructor - dipanggil otomatis waktu objek dihapus dari memory
    ~Barang(){}
};
