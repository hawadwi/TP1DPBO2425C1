<?php
class Barang{
    // Properti untuk menyimpan data barang
    private string $kode;
    private string $nama;
    private string $harga;
    private string $merk;
    private string $garansi;
    private int $stok;
    private string $gambar;

    // Konstruktor untuk inisialisasi data barang saat objek dibuat
    public function __construct(string $kode, string $nama, string $harga, string $merk, string $garansi, int $stok, string $gambar){
        $this->kode = $kode;
        $this->nama = $nama;
        $this->harga = $harga;
        $this->merk = $merk;
        $this->garansi = $garansi;
        $this->stok = $stok;
        $this->gambar = $gambar;
    }

    // Getter dan Setter untuk kode
    public function getKode(): string {
        return $this->kode;
    }
    public function setKode(string $kode): void{
        $this->kode = $kode;
    }

    // Getter dan Setter untuk nama
    public function getNama(): string {
        return $this->nama;
    }
    public function setNama(string $nama): void{
        $this->nama = $nama;
    }

    // Getter dan Setter untuk harga
    public function getHarga(): string {
        return $this->harga;
    }
    public function setHarga(string $harga): void{
        $this->harga = $harga;
    }

    // Getter dan Setter untuk merk
    public function getMerk(): string {
        return $this->merk;
    }
    public function setMerk(string $merk): void{
        $this->merk = $merk;
    }

    // Getter dan Setter untuk garansi
    public function getGaransi(): string {
        return $this->garansi;
    }
    public function setGaransi(string $garansi): void{
        $this->garansi = $garansi;
    }

    // Getter dan Setter untuk stok
    public function getStok(): int {
        return $this->stok;
    }
    public function setStok(int $stok): void{
        $this->stok = $stok;
    }

    // Getter dan Setter untuk gambar
    public function getGambar(): string {
        return $this->gambar;
    }
    public function setGambar(string $gambar): void {
        $this->gambar = $gambar;
    }
}
?>
