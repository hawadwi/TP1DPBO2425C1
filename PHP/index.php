<?php
require_once 'Barang.php'; 
session_start();            

// Buat folder foto jika belum ada (untuk simpan gambar upload)
if (!is_dir('foto')) {
    mkdir('foto', 0777, true);
}

// Inisialisasi session barang (array kosong pertama kali dijalankan)
if (!isset($_SESSION['barang'])) {
    $_SESSION['barang'] = [];
}

/* ================================
   PROSES TAMBAH BARANG BARU
   ================================ */
if (isset($_POST['tambah'])) {
    // Ambil data dari form input
    $kode = $_POST['kode'];
    $nama = $_POST['nama'];
    $harga = $_POST['harga'];
    $merk = $_POST['merk'];
    $garansi = $_POST['garansi'];
    $stok = intval($_POST['stok']);

    // Proses upload gambar (jika ada)
    $gambarPath = '';
    if (isset($_FILES['gambar']) && $_FILES['gambar']['error'] == 0) {
        $namaFile = basename($_FILES['gambar']['name']);
        // Sanitasi nama file agar aman
        $namaFile = preg_replace('/[^a-zA-Z0-9\.\-_]/', '', $namaFile);
        // Simpan gambar di folder foto dengan nama unik (timestamp)
        $gambarPath = 'foto/' . time() . '_' . $namaFile;
        move_uploaded_file($_FILES['gambar']['tmp_name'], $gambarPath);
    }

    // Buat objek Barang baru dan simpan ke session
    $barang = new Barang($kode, $nama, $harga, $merk, $garansi, $stok, $gambarPath);
    $_SESSION['barang'][] = $barang;

    // Redirect untuk mencegah submit ulang saat refresh
    header("Location: " . $_SERVER['PHP_SELF']);
    exit;
}

/* ================================
   PROSES HAPUS BARANG
   ================================ */
if (isset($_GET['hapus'])) {
    $index = intval($_GET['hapus']); // ambil index barang dari query string

    if (isset($_SESSION['barang'][$index])) {
        // Hapus file gambar barang juga jika ada
        $barangToDelete = $_SESSION['barang'][$index];
        $gambarToDelete = $barangToDelete->getGambar();
        if ($gambarToDelete && file_exists($gambarToDelete)) {
            unlink($gambarToDelete);
        }

        // Hapus barang dari array session
        unset($_SESSION['barang'][$index]);
        // Reindex array agar tidak ada "lubang"
        $_SESSION['barang'] = array_values($_SESSION['barang']);
    }

    // Redirect kembali ke index.php
    header("Location: " . $_SERVER['PHP_SELF']);
    exit;
}

/* ================================
   PROSES SEARCH BARANG
   ================================ */
$hasilSearch = [];
if (isset($_POST['search'])) {
    $keyword = trim($_POST['search']); // kata kunci dari input

    // Cari berdasarkan KODE atau NAMA barang (harus sama persis)
    foreach ($_SESSION['barang'] as $b) {
        if ($b->getKode() === $keyword || $b->getNama() === $keyword) {
            $hasilSearch[] = $b;
        }
    }
} else {
    // Jika tidak melakukan search, tampilkan semua barang
    $hasilSearch = $_SESSION['barang'];
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Toko Elektronik</title>
</head>
<body>
    <h1>Tambah Barang</h1>
    <!-- Form Tambah Barang -->
    <form method="POST" enctype="multipart/form-data">
        <label>Kode:</label><br>
        <input type="text" name="kode" required><br>
        <label>Nama:</label><br>
        <input type="text" name="nama" required><br>
        <label>Harga:</label><br>
        <input type="text" name="harga" required><br>
        <label>Merk:</label><br>
        <input type="text" name="merk" required><br>
        <label>Garansi:</label><br>
        <input type="text" name="garansi" required><br>
        <label>Stok:</label><br>
        <input type="number" name="stok" required><br>
        <label>Gambar:</label><br>
        <input type="file" name="gambar" accept="image/*" required><br><br>
        <button type="submit" name="tambah">Tambah</button>
    </form>

    <!-- Bagian Daftar Barang -->
    <section id="barang" class="barang_section layout_padding-bottom">
        <div class="container">
            <div class="heading_container heading_center">
                <h2 style="text-align: center;">Daftar Barang Elektronik</h2>
            </div>

            <!-- Form Search -->
            <form method="POST" enctype="multipart/form-data" action=""> 
                <input type="text" name="search" placeholder="Masukkan kode atau nama barang">
                <button type="submit">Search</button>
            </form>

            <!-- Tabel Hasil Search / Semua Barang -->
            <?php if (count($hasilSearch) > 0): ?>
                <table border="1" cellpadding="8" cellspacing="0" style="width: 70%; margin: auto; text-align: center;">
                    <thead>
                        <tr>
                            <th>No</th>
                            <th>Gambar</th>
                            <th>Kode</th>
                            <th>Nama</th>
                            <th>Harga</th>
                            <th>Merk</th>
                            <th>Garansi</th>
                            <th>Stok</th>
                            <th>Aksi</th>
                        </tr>
                    </thead>
                    <tbody>
                        <?php foreach ($hasilSearch as $i => $b): ?>
                            <tr>
                                <td><?= $i + 1 ?></td>
                                <td>
                                    <?php if ($b->getGambar() && file_exists($b->getGambar())): ?>
                                        <img src="<?= $b->getGambar(); ?>" alt="<?= htmlspecialchars($b->getNama()); ?>" style="width: 100px; height: auto;">
                                    <?php else: ?>
                                        Tidak ada gambar
                                    <?php endif; ?>
                                </td>
                                <td><?= htmlspecialchars($b->getKode()); ?></td>
                                <td><?= htmlspecialchars($b->getNama()); ?></td>
                                <td>Rp <?= htmlspecialchars($b->getHarga()); ?></td>
                                <td><?= htmlspecialchars($b->getMerk()); ?></td>
                                <td><?= htmlspecialchars($b->getGaransi()); ?></td>
                                <td><?= htmlspecialchars($b->getStok()); ?></td>
                                <td>
                                    <!-- Aksi Edit dan Hapus -->
                                    <a href="edit.php?id=<?= $i ?>">Edit</a> |
                                    <a href="?hapus=<?= $i ?>" onclick="return confirm('Yakin ingin hapus?')">Hapus</a>
                                </td>
                            </tr>
                        <?php endforeach; ?>
                    </tbody>
                </table>
            <?php else: ?>
                <p class="text-center">Barang tidak ditemukan.</p>
            <?php endif; ?>
        </div>
    </section>
</body>
</html>
