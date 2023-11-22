#include <stdio.h>

struct database {
    char nama[105];
    char nim[10];
    int age;
    char postalcode[10];
    char pob[105];
    char dob[105];
    char hs[105];
    int siblings;
    int height;
    char bank[10];
} mahasiswa;

int main() {
    int tc;
    int age, siblings, height;

    scanf("%d", &tc);

    for (int t = 0; t < tc; t++) {
        scanf(" %[^\n]", mahasiswa.nama);
        scanf("%s", mahasiswa.nim);
        scanf("%d", &age);
        scanf("%s", mahasiswa.postalcode);
        scanf(" %[^\n]", mahasiswa.pob);
        scanf(" %[^\n]", mahasiswa.dob);
        scanf(" %[^\n]", mahasiswa.hs);
        scanf("%d", &siblings);
        scanf("%d", &height);
        scanf("%s", mahasiswa.bank);

        printf("Mahasiswa ke-%d:\n", t + 1);
        printf("Nama: %s\n", mahasiswa.nama);
        printf("NIM: %s\n", mahasiswa.nim);
        printf("Umur: %d\n", age);
        printf("Kode Pos: %s\n", mahasiswa.postalcode);
        printf("Tempat Lahir: %s\n", mahasiswa.pob);
        printf("Tanggal Lahir: %s\n", mahasiswa.dob);
        printf("Almamater SMA: %s\n", mahasiswa.hs);
        printf("Jumlah Saudara Kandung: %d\n", siblings);
        printf("Tinggi Badan: %d\n", height);
        printf("NOMOR REKENING: %s\n", mahasiswa.bank);
    }

    return 0;
}
