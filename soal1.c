/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 3
 *   Hari dan Tanggal    : Rabu, 29 April 2026
 *   Nama (NIM)          : R. Damar Prawiro Kusumo Sudradjat (13224109)
 *   Nama File           : soal1.c
 *   Deskripsi           : Membuat sistem arsip artefak yang dapat mengurutkan berdasarkan data artefak yang dimasukkan
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
    char *nama;
    char *kategori;
    int tahun;
    int nilai;
} data;

int compareKategori(const void *a, const void *b);
int compareTahun(const void *a, const void *b);

int main()
{
    int N;
    char *input;
    input = (char *)malloc(100 * sizeof(char));
    fgets(input, 100, stdin);
    char* tok;
    tok = strtok(input, " ");
    N = atoi(tok);
    data arr[N];

    for (int i = 0; i < N; i++)
    {
        tok = strtok(NULL, " ");
        arr[i].nama = (char*)malloc(strlen(tok) * sizeof(char));
        strcpy(arr[i].nama, tok);

        tok = strtok(NULL, " ");
        arr[i].kategori = (char*)malloc(strlen(tok) * sizeof(char));
        strcpy(arr[i].kategori, tok);

        tok = strtok(NULL, " ");
        arr[i].tahun = atoi(tok);

        tok = strtok(NULL, " ");
        arr[i].nilai = atoi(tok);
    }

    qsort(arr, N, sizeof(data), compareTahun);
    qsort(arr, N, sizeof(data), compareKategori);
    
    for (int i = 0; i < N; i++)
    {
        printf("%s %s %d %d\n", arr[i].nama, arr[i].kategori, arr[i].tahun, arr[i].nilai);
    }
    
    return 0;
}

int compareKategori(const void *a, const void *b){
    return strcmp(((data *)a)->kategori, ((data *)b)->kategori);
}

int compareTahun(const void *a, const void *b){
    return ((data *)a)->tahun - ((data *)b)->tahun;
}
