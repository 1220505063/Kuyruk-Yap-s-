#include <stdio.h>
#include <stdlib.h>

struct dugum {
    int veri;
    struct dugum *sonraki;
};

typedef struct dugum Dugum;

void ekle(Dugum **kuyruk, int veri) {
    Dugum *yeniDugum = (Dugum*) malloc(sizeof(Dugum));
    yeniDugum->veri = veri;
    yeniDugum->sonraki = NULL;
    if (*kuyruk == NULL) {
        *kuyruk = yeniDugum;
        return;
    }
    Dugum *sonDugum = *kuyruk;
    while (sonDugum->sonraki != NULL) {
        sonDugum = sonDugum->sonraki;
    }
    sonDugum->sonraki = yeniDugum;
}

int sil(Dugum **kuyruk) {
    if (*kuyruk == NULL) {
        printf("Kuyruk bos\n");
        return -1;
    }
    int veri = (*kuyruk)->veri;
    Dugum *oncekiDugum = *kuyruk;
    *kuyruk = (*kuyruk)->sonraki;
    free(oncekiDugum);
    return veri;
}

void goruntule(Dugum **kuyruk) {
    if (*kuyruk == NULL) {
        printf("Kuyruk bos\n");
        return;
    }
    Dugum *dugum = *kuyruk;
    while (dugum != NULL) {
        printf("%d ", dugum->veri);
        dugum = dugum->sonraki;
    }
    printf("\n");
}

int main() {
    Dugum *kuyruk = NULL;
    int secim, veri;
    do {
        printf("Kuyruk uzerinde islem yapmak icin:\n");
        printf("1. Ekle\n");
        printf("2. Sil\n");
        printf("3. Goruntule\n");
        printf("4. Cikis\n");
        printf("Secim yapin: ");
        scanf("%d", &secim);
        switch (secim) {
            case 1:
                printf("Kuyruga eklenecek veri: ");
                scanf("%d", &veri);
                ekle(&kuyruk, veri);
                break;
            case 2:
                printf("Silinen veri: %d\n", sil(&kuyruk));
                break;
            case 3:
                goruntule(&kuyruk);
                break;
            case 4:
                exit(0);
            default:
                printf("Hatali secim!\n");
        }
    } while (1);
    return 0;
}

