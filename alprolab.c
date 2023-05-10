void cariBuku(struct Buku *buku, int jumlahBuku) {
    if (jumlahBuku > 0) {
        char judul[100];
        printf("Masukkan judul buku yang ingin dicari: ");
        fgets(judul, sizeof(judul), stdin);
        strtok(judul, "\n");

        int found = 0;
        for (int i = 0; i < jumlahBuku; i++) {
            if (strcmp(buku[i].judul, judul) == 0) {
                printf("Buku dengan judul '%s' ditemukan!\n", judul);
                printf("Judul: %s\n", buku[i].judul);
                printf("Pengarang: %s\n", buku[i].pengarang);
                printf("Tahun Terbit: %d\n", buku[i].tahun);
                printf("Status: %s\n", buku[i].dipinjam == 0 ? "Tersedia" : "Dipinjam");
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Buku dengan judul '%s' tidak ditemukan.\n", judul);
        }
    } else {
        printf("Belum ada buku yang tersedia.\n");
    }
}

void kembalikanBuku(struct Buku *buku, int jumlahBuku) {
    if (jumlahBuku > 0) {
        char judul[100];
        printf("Masukkan judul buku yang akan dikembalikan: ");
        fgets(judul, sizeof(judul), stdin);
        strtok(judul, "\n");

        int found = 0;
        for (int i = 0; i < jumlahBuku; i++) {
            if (strcmp(buku[i].judul, judul) == 0) {
                if (buku[i].dipinjam == 1) {
                    buku[i].dipinjam = 0; // Set status buku sudah dikembalikan
                    printf("Buku dengan judul '%s' berhasil dikembalikan!\n", judul);
                } else {
                    printf("Buku dengan judul '%s' belum dipinjam.\n", judul);
                }
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Buku dengan judul '%s' tidak ditemukan.\n", judul);
        }
    } else {
        printf("Belum ada buku yang tersedia.\n");
    }
}

int main() {
    struct Buku *buku = NULL;
    int jumlahBuku = 0;
    int pilihan;

    do {
        printf("\n\n========================================\n");
        printf(" SELAMAT DATANG DI PERPUSTAKAAN ILMU\n");
        printf("Bacalah buku,karena buku jendela dunia\n");
        printf("========================================\n");
        printf("Menu:\n");
        printf("1. Cari Buku\n");
        printf("2. Tambah Buku\n");
        printf("3. Pinjam Buku\n");
        printf("4. Kembalikan Buku\n");
        printf("5. Keluar dari halaman\n");
        printf("========================================\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        getchar(); // Menggunakan getchar() untuk membersihkan newline karakter dari buffer

        switch (pilihan) {
            case 1:
                tampilkanBuku(buku, jumlahBuku);
                cariBuku(buku, jumlahBuku);
                break;
            case 2:
                tambahBuku(&buku, &jumlahBuku);
                break;
            case 3:
                pinjamBuku(buku, jumlahBuku);
                break;
            case 4:
                kembalikanBuku(buku, jumlahBuku);
                break;
            case 5:
                printf("Terima kasih telah mengunjungi perpustakaan kami. Sampai jumpa!\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan pilih angka 1-5 sesuai menu.\n");
                break;
        }
    } while (pilihan != 5);

    // Dealokasi memory yang digunakan untuk array buku
    if (buku != NULL) {
        free(buku);
    }

    return 0;
}
