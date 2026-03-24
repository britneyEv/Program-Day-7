#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct karyawan {
    char nama[50];
    float gajiPokok;
    float bonus;
    float potongan;
    float gajiBersih;
    char kategori[20];
};

int main() {
    int n, i, jmlTinggi = 0;
    float totalGaji = 0;
    struct karyawan *data;

    printf("===== Program Penggajian Karyawan =====\n");
    printf("Masukkan jumlah karyawan = ");
    scanf("%d", &n);

    data = (struct karyawan*) malloc(n * sizeof(struct karyawan));

    for (i = 0; i < n; i++) {
        printf("\nData Karyawan ke-%d\n", i + 1);
        printf("Nama karyawan = ");
        scanf(" %[^\n]", (data + i)->nama);
        printf("Gaji pokok = ");
        scanf("%f", &(data + i)->gajiPokok);
        printf("Bonus = ");
        scanf("%f", &(data + i)->bonus);
        printf("Potongan = ");
        scanf("%f", &(data + i)->potongan);

        (data + i)->gajiBersih = (data + i)->gajiPokok + (data + i)->bonus - (data + i)->potongan;

        if ((data + i)->gajiBersih > 5000000) {
            strcpy((data + i)->kategori, "Tinggi");
            jmlTinggi++;
        } else if ((data + i)->gajiBersih >= 3000000) {
            strcpy((data + i)->kategori, "Sedang");
        } else {
            strcpy((data + i)->kategori, "Rendah");
        }

        totalGaji += (data + i)->gajiBersih;
    }

    printf("\n=== Data Penggajian Karyawan ===\n");
    printf("No\tNama\tGajiPokok\tBonus\t\tPotongan\tGajiBersih\tKategori\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%s\n",
               i + 1,
               (data + i)->nama,
               (data + i)->gajiPokok,
               (data + i)->bonus,
               (data + i)->potongan,
               (data + i)->gajiBersih,
               (data + i)->kategori);
    }

    printf("\nTotal gaji seluruh karyawan = Rp %.2f\n", totalGaji);
    printf("Jumlah kategori tinggi      = %d karyawan\n", jmlTinggi);

    free(data);
    return 0;
}