#include <stdio.h>
#include <stdlib.h>

struct listrik {
    float kwh;
    float tarif;
    float total;
    char kategori[20];
};

int main() {
    int n, i, jmlHemat = 0;
    float totalPendapatan = 0;
    struct listrik *data;

    printf("===== Program Pembayaran Listrik =====\n");
    printf("Masukkan jumlah pelanggan = ");
    scanf("%d", &n);

    data = (struct listrik*) malloc(n * sizeof(struct listrik));

    for (i = 0; i < n; i++) {
        printf("\nData Pelanggan ke-%d\n", i + 1);
        printf("Pemakaian kWh = ");
        scanf("%f", &(data + i)->kwh);
        printf("Tarif per kWh = ");
        scanf("%f", &(data + i)->tarif);

        (data + i)->total = (data + i)->kwh * (data + i)->tarif;

        if ((data + i)->kwh < 100) {
            sprintf((data + i)->kategori, "Hemat");
            jmlHemat++;
        } else if ((data + i)->kwh <= 300) {
            sprintf((data + i)->kategori, "Normal");
        } else {
            sprintf((data + i)->kategori, "Boros");
        }

        totalPendapatan += (data + i)->total;
    }

    printf("\n=== Tagihan Listrik ===\n");
    printf("No\tkWh\tTarif\tTotal\tKategori\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%.2f\t%.2f\t%.2f\t%s\n",
               i + 1,
               (data + i)->kwh,
               (data + i)->tarif,
               (data + i)->total,
               (data + i)->kategori);
    }

    printf("\nTotal pendapatan listrik = Rp %.2f\n", totalPendapatan);
    printf("Jumlah pelanggan hemat   = %d orang\n", jmlHemat);

    free(data);
    return 0;
}