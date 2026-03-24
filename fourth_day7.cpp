#include <stdio.h>
#include <stdlib.h>

struct tabungan {
    int bulanKe;
    float setoran;
    float persenBunga;
    float penarikan;
    float bungaRupiah;
    float saldoAkhir;
};

int main() {
    int n, i;
    float saldoAwal, saldoSebelumnya;
    float totalSetoran = 0, totalPenarikan = 0, totalBunga = 0;
    struct tabungan *data;

    printf("===== Program Tabungan Bank Perbulan =====\n");
    printf("Masukkan jumlah bulan = ");
    scanf("%d", &n);

    data = (struct tabungan*) malloc(n * sizeof(struct tabungan));

    printf("Masukkan saldo awal = ");
    scanf("%f", &saldoAwal);

    saldoSebelumnya = saldoAwal;

    for (i = 0; i < n; i++) {
        (data + i)->bulanKe = i + 1;

        printf("\nData Bulan ke-%d\n", i + 1);
        printf("Setoran = ");
        scanf("%f", &(data + i)->setoran);
        printf("Bunga (%%) = ");
        scanf("%f", &(data + i)->persenBunga);
        printf("Penarikan = ");
        scanf("%f", &(data + i)->penarikan);

        (data + i)->bungaRupiah = (saldoSebelumnya + (data + i)->setoran) * ((data + i)->persenBunga / 100.0);
        (data + i)->saldoAkhir = saldoSebelumnya + (data + i)->setoran + (data + i)->bungaRupiah - (data + i)->penarikan;

        totalSetoran += (data + i)->setoran;
        totalPenarikan += (data + i)->penarikan;
        totalBunga += (data + i)->bungaRupiah;

        saldoSebelumnya = (data + i)->saldoAkhir;
    }

    printf("\n=== Data Tabungan ===\n");
    printf("Saldo awal = Rp %.2f\n\n", saldoAwal);
    printf("Bulan\tSetoran\t\tBunga%%\tPenarikan\tBunga Rp\tSaldo Akhir\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%.2f\t%.2f\t%.2f\t\t%.2f\t\t%.2f\n",
               (data + i)->bulanKe,
               (data + i)->setoran,
               (data + i)->persenBunga,
               (data + i)->penarikan,
               (data + i)->bungaRupiah,
               (data + i)->saldoAkhir);
    }

    printf("\n=== Total Keseluruhan ===\n");
    printf("Total setoran      = Rp%.2f\n", totalSetoran);
    printf("Total penarikan    = Rp%.2f\n", totalPenarikan);
    printf("Total bunga        = Rp%.2f\n", totalBunga);
    printf("Saldo akhir total  = Rp%.2f\n", (data + n - 1)->saldoAkhir);

    free(data);
    return 0;
}