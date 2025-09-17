from Barang import Barang

def main():
    
    # Contoh penggunaan
    daftar_barang = [None] * 5
    jumlah_barang = 0

    while True:
        print("\nMenu Toko Elektronik")
        print("1. Tambah Barang")
        print("2. Tampilkan Semua Barang")
        print("3. Ubah Barang")
        print("4. Hapus Barang")
        print("5. Cari Barang")
        print("6. Keluar")

        pilihan = input("Pilih menu: ")

        if pilihan == "1":
            if jumlah_barang < 5:
                kode = input("Kode    : ")
                nama = input("Nama    : ")
                harga = input("Harga   : ")
                merk = input("Merk    : ")
                garansi = input("Garansi : ")
                stok = int(input("Stok    : "))

                daftar_barang[jumlah_barang] = Barang(kode, nama, harga, merk, garansi, stok)
                jumlah_barang += 1
                print("Barang berhasil ditambahkan.")
            else:
                print("Data penuh, tidak bisa menambah barang.")

        elif pilihan == "2":
            if jumlah_barang == 0:
                print("Belum ada data barang.")
            else:
                for i in range(jumlah_barang):
                    print(f"\nBarang ke-{i+1}")
                    daftar_barang[i].tampilkan()

        elif pilihan == "3":
            kode_cari = input("Masukkan kode barang yang ingin diubah: ")
            index = -1
            for i in range(jumlah_barang):
                if index == -1 and daftar_barang[i].getKode() == kode_cari:
                    index = i

            if index == -1:
                print("Barang tidak ditemukan.")
            else:
                nama = input("Nama baru    : ")
                harga = input("Harga baru   : ")
                merk = input("Merk baru    : ")
                garansi = input("Garansi baru : ")
                stok = int(input("Stok baru    : "))

                daftar_barang[index].setNama(nama)
                daftar_barang[index].setHarga(harga)
                daftar_barang[index].setMerk(merk)
                daftar_barang[index].setGaransi(garansi)
                daftar_barang[index].setStok(stok)

                print("Barang berhasil diubah.")

        elif pilihan == "4":
            kode_cari = input("Masukkan kode barang yang ingin dihapus: ")
            index = -1
            for i in range(jumlah_barang):
                if index == -1 and daftar_barang[i].getKode() == kode_cari:
                    index = i

            if index == -1:
                print("Barang tidak ditemukan.")
            else:
                for i in range(index, jumlah_barang - 1):
                    daftar_barang[i] = daftar_barang[i + 1]
                daftar_barang[jumlah_barang - 1] = None
                jumlah_barang -= 1
                print("Barang berhasil dihapus.")

        elif pilihan == "5":
            if jumlah_barang == 0:
                print("Belum ada data barang untuk dicari.")
            else:
                kode_cari = input("Masukkan kode barang yang ingin dicari: ")
                index = -1
                # Algoritma pencarian sederhana tanpa break, sama seperti menu ubah dan hapus
                for i in range(jumlah_barang):
                    if index == -1 and daftar_barang[i].getKode() == kode_cari:
                        index = i

                if index == -1:
                    print("Barang dengan kode tersebut tidak ditemukan.")
                else:
                    print("\n" + "="*40)
                    print("         HASIL PENCARIAN")
                    print("="*40)
                    daftar_barang[index].tampilkan()
                    print("="*40)
                    print("Barang berhasil ditemukan!")

        elif pilihan == "6":
            print("Terima kasih!")
            break

        else:
            print("Pilihan tidak valid.")


if __name__ == "__main__":
    main()

