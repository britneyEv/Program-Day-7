#include <stdio.h>
#include <stdlib.h>

struct pasien {
    float berat;
    float tinggi;
    float bmi;
    char kategori[20];
};

int main() {
    int n, i;
    int jmlNormal = 0;
    float totalBMI = 0, rataBMI;
    struct pasien *data;

    printf("===== Program Cek Kesehatan BMI =====\n");
    printf("Masukkan jumlah pasien = ");
    scanf("%d", &n);

    data = (struct pasien*) malloc(n * sizeof(struct pasien));

    for (i = 0; i < n; i++) {
        printf("\nData Pasien ke-%d\n", i + 1);
        printf("Berat badan (kg) = ");
        scanf("%f", &(data + i)->berat);
        printf("Tinggi badan (m) = ");
        scanf("%f", &(data + i)->tinggi);

        (data + i)->bmi = (data + i)->berat / ((data + i)->tinggi * (data + i)->tinggi);

        if ((data + i)->bmi < 18.5) {
            sprintf((data + i)->kategori, "Kurus");
        } else if ((data + i)->bmi < 25) {
            sprintf((data + i)->kategori, "Normal");
            jmlNormal++;
        } else if ((data + i)->bmi < 30) {
            sprintf((data + i)->kategori, "Gemuk");
        } else {
            sprintf((data + i)->kategori, "Obesitas");
        }

        totalBMI += (data + i)->bmi;
    }

    rataBMI = totalBMI / n;

    printf("\n=== Hasil Cek ===\n");
    printf("No\tBerat\tTinggi\tBMI\tKategori\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%.2f\t%.2f\t%.2f\t%s\n",
               i + 1,
               (data + i)->berat,
               (data + i)->tinggi,
               (data + i)->bmi,
               (data + i)->kategori);
    }

    printf("\nTotal BMI pasien    = %.2f\n", totalBMI);
    printf("Rata-rata BMI       = %.2f\n", rataBMI);
    printf("Jumlah BMI Normal   = %d orang\n", jmlNormal);

    free(data);
    return 0;
}