#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void citire_tastatura(int v[], int* n) {
    printf("Cate elemente are vectorul? ");
    scanf("%d", n);

    printf("Introdu %d elemente:\n", *n);
    for (int i = 0; i < *n; i++) {
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }
}

void afisare_vector(int v[], int n) {
    printf("Vectorul are %d elemente:\n", n);
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void citire_fisier(int v[], int* n) {
    FILE* f = fopen("input.txt", "r");
    if (f == NULL) {
        printf("Eroare la deschiderea fisierului input.txt\n");
        exit(1);
    }

    fscanf(f, "%d", n);
    for (int i = 0; i < *n; i++) {
        fscanf(f, "%d", &v[i]);
    }

    fclose(f);
    printf("Vectorul a fost citit din fisier cu succes.\n");
}

void scriere_fisier(int v[], int n) {
    FILE* f = fopen("output.txt", "w");
    if (f == NULL) {
        printf("Eroare la deschiderea fisierului output.txt\n");
        exit(1);
    }

    fprintf(f, "%d\n", n);
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d ", v[i]);
    }

    fclose(f);
    printf("Vectorul a fost scris in fisierul output.txt.\n");
}

void inserare(int v[], int* n, int poz, int val) {
    if (poz < 0 || poz > *n || *n >= MAX) {
        printf("Pozitie invalida sau vectorul e plin.\n");
        return;
    }

    for (int i = *n; i > poz; i--) {
        v[i] = v[i - 1];
    }

    v[poz] = val;
    (*n)++;
    printf("Elementul %d a fost inserat pe pozitia %d.\n", val, poz);
}

void stergere(int v[], int* n, int poz) {
    if (poz < 0 || poz >= *n) {
        printf("Pozitie invalida.\n");
        return;
    }

    for (int i = poz; i < *n - 1; i++) {
        v[i] = v[i + 1];
    }

    (*n)--;
    printf("Elementul de pe pozitia %d a fost sters.\n", poz);
}

int cauta(int v[], int n, int val) {
    for (int i = 0; i < n; i++) {
        if (v[i] == val) return i;
    }
    return -1;
}

//int main() {
//    int v[MAX], n = 0, opt;
//
//    do {
//        printf("\n=== MENIU VECTOR ===\n");
//        printf("1. Citire de la tastatura\n");
//        printf("2. Citire din fisier\n");
//        printf("3. Afisare vector\n");
//        printf("4. Inserare element\n");
//        printf("5. Stergere element\n");
//        printf("6. Cautare element\n");
//        printf("7. Scriere in fisier\n");
//        printf("0. Iesire\n");
//        printf("Alege optiunea: ");
//        scanf("%d", &opt);
//
//        switch (opt) {
//        case 1: citire_tastatura(v, &n); break;
//        case 2: citire_fisier(v, &n); break;
//        case 3: afisare_vector(v, n); break;
//        case 4: {
//            int val, poz;
//            printf("Valoare de inserat: ");
//            scanf("%d", &val);
//            printf("Pozitie: ");
//            scanf("%d", &poz);
//            inserare(v, &n, poz, val);
//            break;
//        }
//        case 5: {
//            int poz;
//            printf("Pozitie de sters: ");
//            scanf("%d", &poz);
//            stergere(v, &n, poz);
//            break;
//        }
//        case 6: {
//            int val;
//            printf("Valoare de cautat: ");
//            scanf("%d", &val);
//            int poz = cauta(v, n, val);
//            if (poz != -1)
//                printf("Element gasit pe pozitia %d.\n", poz);
//            else
//                printf("Elementul nu a fost gasit.\n");
//            break;
//        }
//        case 7: scriere_fisier(v, n); break;
//        case 0: printf("Iesire din program.\n"); break;
//        default: printf("Optiune invalida.\n");
//        }
//    } while (opt != 0);
//
//    return 0;
//}
