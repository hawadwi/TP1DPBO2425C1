import java.util.Scanner;

public class Barang {
   private String kode;
   private String nama;
   private String harga;
   private String merk;
   private String garansi;
   private int stok;

   public Barang(String kode, String nama, String harga, String merk, String garansi, int stok) {
      this.kode = kode;
      this.nama = nama;
      this.harga = harga;
      this.merk = merk;
      this.garansi = garansi;
      this.stok = stok;
   }

   public String getKode() {
      return this.kode;
   }

   public void setKode(String kode) {
      this.kode = kode;
   }

   public String getNama() {
      return this.nama;
   }

   public void setNama(String nama) {
      this.nama = nama;
   }

   public String getHarga() {
      return this.harga;
   }

   public void setHarga(String harga) {
      this.harga = harga;
   }

   public String getMerk() {
      return this.merk;
   }

   public void setMerk(String merk) {
      this.merk = merk;
   }

   public String getGaransi() {
      return this.garansi;
   }

   public void setGaransi(String garansi) {
      this.garansi = garansi;
   }

   public int getStok() {
      return this.stok;
   }

   public void setStok(int stok) {
      this.stok = stok;
   }

   public void tampilkan() {
        System.out.println("Kode    : " + getKode());
        System.out.println("Nama    : " + getNama());
        System.out.println("Harga   : " + getHarga());
        System.out.println("Merk    : " + getMerk());
        System.out.println("Garansi : " + getGaransi());
        System.out.println("Stok    : " + getStok());
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Barang[] daftarBarang = new Barang[5];
        int jumlahBarang = 0;
        int pilihan;

        do {
            System.out.println("\nMenu Toko Elektronik");
            System.out.println("1. Tambah Barang");
            System.out.println("2. Tampilkan Semua Barang");
            System.out.println("3. Ubah Barang");
            System.out.println("4. Hapus Barang");
            System.out.println("5. Cari Barang");
            System.out.println("6. Keluar");
            System.out.print("Pilih menu: ");
            pilihan = input.nextInt();
            input.nextLine();

            if (pilihan == 1) {
                if (jumlahBarang < 5) {
                    System.out.print("Kode    : ");
                    String kode = input.nextLine();
                    System.out.print("Nama    : ");
                    String nama = input.nextLine();
                    System.out.print("Harga   : ");
                    String harga = input.nextLine();
                    System.out.print("Merk    : ");
                    String merk = input.nextLine();
                    System.out.print("Garansi : ");
                    String garansi = input.nextLine();
                    System.out.print("Stok    : ");
                    int stok = input.nextInt();
                    input.nextLine();

                    daftarBarang[jumlahBarang] = new Barang(kode, nama, harga, merk, garansi, stok);
                    jumlahBarang++;
                    System.out.println("Barang berhasil ditambahkan.");
                } else {
                    System.out.println("Data penuh, tidak bisa menambah barang.");
                }
            } else if (pilihan == 2) {
                if (jumlahBarang == 0) {
                    System.out.println("Belum ada data barang.");
                } else {
                    for (int i = 0; i < jumlahBarang; i++) {
                        System.out.println("\nBarang ke-" + (i + 1));
                        daftarBarang[i].tampilkan();
                    }
                }
            } else if (pilihan == 3) {
                System.out.print("Masukkan kode barang yang ingin diubah: ");
                String kodeCari = input.nextLine();
                int index = -1;

                for (int i = 0; i < jumlahBarang && index == -1; i++) {
                    if (daftarBarang[i].getKode().equals(kodeCari)) {
                        index = i;
                    }
                }

                if (index == -1) {
                    System.out.println("Barang tidak ditemukan.");
                } else {
                    System.out.print("Nama baru    : ");
                    String nama = input.nextLine();
                    System.out.print("Harga baru   : ");
                    String harga = input.nextLine();
                    System.out.print("Merk baru    : ");
                    String merk = input.nextLine();
                    System.out.print("Garansi baru : ");
                    String garansi = input.nextLine();
                    System.out.print("Stok baru    : ");
                    int stok = input.nextInt();
                    input.nextLine();

                    daftarBarang[index].setNama(nama);
                    daftarBarang[index].setHarga(harga);
                    daftarBarang[index].setMerk(merk);
                    daftarBarang[index].setGaransi(garansi);
                    daftarBarang[index].setStok(stok);

                    System.out.println("Barang berhasil diubah.");
                }
            } else if (pilihan == 4) {
                System.out.print("Masukkan kode barang yang ingin dihapus: ");
                String kodeCari = input.nextLine();
                int index = -1;

                for (int i = 0; i < jumlahBarang && index == -1; i++) {
                    if (daftarBarang[i].getKode().equals(kodeCari)) {
                        index = i;
                    }
                }

                if (index == -1) {
                    System.out.println("Barang tidak ditemukan.");
                } else {
                    for (int i = index; i < jumlahBarang - 1; i++) {
                        daftarBarang[i] = daftarBarang[i + 1];
                    }
                    daftarBarang[jumlahBarang - 1] = null;
                    jumlahBarang--;
                    System.out.println("Barang berhasil dihapus.");
                }
            } else if (pilihan == 5) {
                if (jumlahBarang == 0) {
                    System.out.println("Belum ada data barang untuk dicari.");
                } else {
                    System.out.print("Masukkan kode barang yang ingin dicari: ");
                    String kodeCari = input.nextLine().trim(); // trim untuk menghilangkan spasi
                    
                    // Validasi input tidak boleh kosong
                    if (kodeCari.isEmpty()) {
                        System.out.println("Kode barang tidak boleh kosong!");
                    } else {
                        int index = -1;
                        
                        // Pencarian satu objek spesifik berdasarkan kode (case sensitive)
                        for (int i = 0; i < jumlahBarang && index == -1; i++) {
                            if (daftarBarang[i].getKode().equals(kodeCari)) {
                                index = i;
                            }
                        }
                        
                        if (index == -1) {
                            System.out.println("Barang dengan kode '" + kodeCari + "' tidak ditemukan.");
                            System.out.println("Pastikan kode yang dimasukkan benar dan sesuai dengan data yang ada.");
                        } else {
                            // Menampilkan detail lengkap objek yang ditemukan
                            System.out.println("\n" + "=".repeat(40));
                            System.out.println("Barang ditemukan:");
                            daftarBarang[index].tampilkan();
                            System.out.println("Pencarian berhasil! Objek dengan kode '" + kodeCari + "' telah ditemukan.");
                        }
                    }
                }
            } else if (pilihan != 6) {
                System.out.println("Pilihan tidak valid.");
            }
        } while (pilihan != 6);

        System.out.println("Terima kasih!");
        input.close();
    }
}
