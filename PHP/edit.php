<?php
require_once 'Barang.php';
session_start();

if (!isset($_GET['id']) || !isset($_SESSION['barang'][$_GET['id']])) {
    echo "Barang tidak ditemukan.";
    exit();
}

$id = $_GET['id'];
$barang = $_SESSION['barang'][$id];

// Handle Update
if (isset($_POST['update'])) {
    $barang->setNama($_POST['nama']);
    $barang->setHarga($_POST['harga']);
    $barang->setMerk($_POST['merk']);
    $barang->setGaransi($_POST['garansi']);
    $barang->setStok($_POST['stok']);

    if (isset($_FILES['gambar']) && $_FILES['gambar']['error'] == 0) {
        $namaFile = time() . '_' . basename($_FILES['gambar']['name']);
        $gambarPath = 'foto/' . $namaFile;
        move_uploaded_file($_FILES['gambar']['tmp_name'], $gambarPath);
        $barang->setGambar($gambarPath);
    }

    $_SESSION['barang'][$id] = $barang;
    header("Location: index.php");
    exit();
}
?>

<!-- HTML -->
<h2>Edit Barang</h2>
<form method="POST" enctype="multipart/form-data">
    Nama: <input type="text" name="nama" value="<?= $barang->getNama() ?>" required><br>
    Harga: <input type="text" name="harga" value="<?= $barang->getHarga() ?>" required><br>
    Merk: <input type="text" name="merk" value="<?= $barang->getMerk() ?>" required><br>
    Garansi: <input type="text" name="garansi" value="<?= $barang->getGaransi() ?>" required><br>
    Stok: <input type="number" name="stok" value="<?= $barang->getStok() ?>" required><br>
    Gambar: <input type="file" name="gambar"><br>
    <img src="<?= $barang->getGambar() ?>" width="100"><br>
    <button type="submit" name="update">Update</button>
</form>
