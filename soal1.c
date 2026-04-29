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
void bubblesort(data arr[], int N);

int main(){
    int N;
    char input[1000];
    fgets(input, 1000, stdin);
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
    bubblesort(arr, N);
    //qsort(arr, N, sizeof(data), compareKategori);
    
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

void bubblesort(data arr[], int N){
    int status;
    char *temp;
    for (int i = 0; i < N-1; i++)
    {
        status = 0;
        for (int j = 0; j < N-i-1; j++)
        {
            if (strcmp(arr[j].kategori, arr[j+1].kategori) > 0)
            {
                temp = (char *)malloc(strlen(arr[j+1].kategori)*sizeof(char));
                strcpy(temp, arr[j+1].kategori);
                arr[j+1].kategori = realloc(arr[j+1].kategori, strlen(arr[j].kategori)*sizeof(char));
                strcpy(arr[j+1].kategori, arr[j].kategori);
                arr[j].kategori = realloc(arr[j].kategori, strlen(temp)*sizeof(char));
                strcpy(arr[j].kategori, temp);
                status = 1;
            }
            
        }
        if (status ==0)
        {
            break;
        }
        
    }
    
}
