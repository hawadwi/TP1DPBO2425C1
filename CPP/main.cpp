#include <bits/stdc++.h>
#include "Barang.cpp"

using namespace std;

int main(){

    Barang daftar[5];
    int jumlah = 0;  // Variabel untuk menghitung berapa barang yang sudah diinput
    int pilihan;
    
    // Karena method-method di class Barang bukan static, jadi butuh object untuk memanggilnya
    Barang b; 

    pilihan = 0; // Inisialisasi pilihan agar while loop bisa jalan
    while (pilihan != 6) {  // Mengubah dari 5 ke 6 karena ada menu search baru
        // Menampilkan menu utama toko elektronik
        cout << "\n=== Menu Toko Elektronik ===\n";
        cout << "1. Tambah Barang Baru\n";
        cout << "2. Tampilkan Semua Barang\n";
        cout << "3. Ubah Data Barang\n";
        cout << "4. Hapus Barang\n";
        cout << "5. Cari Barang \n";  
        cout << "6. Keluar Program\n";       
        cout << "Pilih menu (1-6): ";
        cin >> pilihan;

        if (pilihan == 1) {
            // Memanggil fungsi untuk menambah barang baru
            b.tambahBarang(daftar, jumlah, 5);
        } else if (pilihan == 2) {
            // Menampilkan semua barang yang ada di toko
            b.tampilkanSemua(daftar, jumlah);
        } else if (pilihan == 3) {
            // Mengubah data barang yang sudah ada
            b.ubahBarang(daftar, jumlah);
        } else if (pilihan == 4) {
            // Menghapus barang dari daftar
            b.hapusBarang(daftar, jumlah);
        } else if (pilihan == 5) {
            // Fungsi ini akan mencari barang berdasarkan kode yang diinput user
            b.searchBarang(daftar, jumlah);
        } else if (pilihan == 6) {  // Mengubah dari 5 ke 6
            cout << "\nTerima kasih telah mengunjungi toko ini!\n";
        } else {
            // Jika user input angka selain 1-6, tampilkan pesan error
            cout << "Pilihan tidak valid! Silakan pilih angka 1-6.\n";
        }
    }

    return 0;
}