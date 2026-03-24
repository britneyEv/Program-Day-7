#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct rental {
    char jenisKendaraan[30];
    int lamaSewa;
    float tarifPerHari;
    float totalBayar;
    char kategori[20];
};

int main() {
    int n, i, jmlLama = 0;
    float totalPendapatan = 0;
    struct rental *data;

    printf("===== Program Rental Kendaraan =====\n");
    printf("Masukkan jumlah penyewa = ");
    scanf("%d", &n);

    data = (struct rental*) malloc(n * sizeof(struct rental));

    for (i = 0; i < n; i++) {
        printf("\nData Penyewa ke-%d\n", i + 1);
        printf("Jenis kendaraan = ");
        scanf(" %[^\n]", (data + i)->jenisKendaraan);
        printf("Lama sewa (hari) = ");
        scanf("%d", &(data + i)->lamaSewa);
        printf("Tarif per hari = ");
        scanf("%f", &(data + i)->tarifPerHari);

        (data + i)->totalBayar = (data + i)->lamaSewa * (data + i)->tarifPerHari;

        if ((data + i)->lamaSewa <= 2) {
            strcpy((data + i)->kategori, "Singkat");
        } else if ((data + i)->lamaSewa <= 5) {
            strcpy((data + i)->kategori, "Sedang");
        } else {
            strcpy((data + i)->kategori, "Lama");
            jmlLama++;
        }

        totalPendapatan += (data + i)->totalBayar;
    }

    printf("\n=== Data Rental Kendaraan ===\n");
    printf("No\tKendaraan\tLama\tTarif\t\tTotal\t\tKategori\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%s\t\t%d\t%.2f\t\t%.2f\t\t%s\n",
               i + 1,
               (data + i)->jenisKendaraan,
               (data + i)->lamaSewa,
               (data + i)->tarifPerHari,
               (data + i)->totalBayar,
               (data + i)->kategori);
    }

    printf("\nTotal pendapatan rental = Rp %.2f\n", totalPendapatan);
    printf("Jumlah sewa kategori lama = %d penyewa\n", jmlLama);

    free(data);
    return 0;
}
