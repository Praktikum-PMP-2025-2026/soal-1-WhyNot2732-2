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

void bubblesortKategori(data arr[], int N);

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
        arr[i].nama = (char*)malloc((strlen(tok)+1) * sizeof(char));
        strcpy(arr[i].nama, tok);

        tok = strtok(NULL, " ");
        arr[i].kategori = (char*)malloc((strlen(tok)+1) * sizeof(char));
        strcpy(arr[i].kategori, tok);

        tok = strtok(NULL, " ");
        arr[i].tahun = atoi(tok);

        tok = strtok(NULL, " ");
        arr[i].nilai = atoi(tok);
    }

    bubblesortKategori(arr, N);
    //qsort(arr, N, sizeof(data), compareKategori);
    
    for (int i = 0; i < N; i++)
    {
        printf("%s %s %d %d\n", arr[i].nama, arr[i].kategori, arr[i].tahun, arr[i].nilai);
    }
    
    return 0;
}


void bubblesortKategori(data arr[], int N){
    int status;
    data temp;
    for (int i = 0; i < N-1; i++){
        status = 0;
        for (int j = 0; j < N-i-1; j++)
        {
            if (strcmp(arr[j].kategori, arr[j+1].kategori) > 0)
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                status = 1;
            } else if (strcmp(arr[j].kategori, arr[j+1].kategori) == 0)
            {
                if ((arr[j].tahun - arr[j+1].tahun) == 0)
                {
                    if ((arr[j+1].nilai - arr[j].nilai) == 0)
                    {
                        if ((strcmp(arr[j].nama, arr[j+1].nama)) > 0)
                        {
                            temp = arr[j+1];
                            arr[j+1] = arr[j];
                            arr[j] = temp;
                            status = 1;
                        }
                        
                    }else if ((arr[j+1].nilai - arr[j].nilai) > 0)
                    {
                        temp = arr[j+1];
                        arr[j+1] = arr[j];
                        arr[j] = temp;
                        status = 1;
                    }
                } else if ((arr[j].tahun - arr[j+1].tahun) > 0)
                {
                    temp = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = temp;
                    status = 1;
                }
            }
        }
        if (status ==0)
        {
            break;
        }
    }
}

/*
REFERENSI:
https://www.geeksforgeeks.org/dsa/c-program-sort-array-names-strings/
https://www.geeksforgeeks.org/c/qsort-function-in-c/
https://www.geeksforgeeks.org/c/strcmp-in-c/
https://www.geeksforgeeks.org/dsa/sort-string-characters/
https://www.geeksforgeeks.org/c/fgets-function-in-c/
https://www.geeksforgeeks.org/c/comparator-function-of-qsort-in-c/
https://github.com/4GeeksAcademy/cybersecurity-syllabus/blob/main/07-pentesting-red-team/buffer-overflow.md
https://www.geeksforgeeks.org/cpp/strtok-strtok_r-functions-c-examples/
*/
