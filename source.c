#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// ispisivanje menija
void Menu() {

    printf("1.Dodaj novo odelo\n");
    printf("2.Ispisi uneto odelo\n");
    printf("3.Ispisi sva odela\n");
    printf("4.Sacuvaj u fajl i izadji\n");
    printf("5.Pretraga po tekstualnim poljima\n");
    printf("6.Sortiranje odela od najjeftinijeg do najskupljeg\n");
    printf("7.Brisanje odela iz niza\n\n");

}

// ucitavanje svih odela u niz struktura
void ucitavanjeIzFajla(Odelo odela[], int *n) {

    FILE* file = fopen("odela.txt", "r");

    if(file == NULL) {
        printf("Greska pri ucitavanju!");
        return;
    }

    int i = 0;

    while(!feof(file)) {
        fgets(odela[i].naziv, 30, file);
        fgets(odela[i].zemljaPorekla, 30, file);
        fscanf(file, "%d", &odela[i].velicina);
        fscanf(file, "%d", &odela[i].cena);
        fscanf(file, "%d", &odela[i].brojNaStanju);
        fgetc(file);

        strtok(odela[i].naziv, "\n");
        strtok(odela[i].zemljaPorekla, "\n");

        i++;
    }

    *n = i - 1;

    fclose(file);

}

void unosOdela(Odelo odela[], int *n) {

    int i = *n;

    getchar();
    printf("Uneti naziv: ");
    gets(odela[i].naziv);
    printf("Uneti zemlju porekla: ");
    gets(odela[i].zemljaPorekla);
    printf("Uneti velicinu 1 - S, 2 - M, 3 - L, 4 - XL: ");
    scanf("%d", &odela[i].velicina);
    printf("Uneti cenu: ");
    scanf("%d", &odela[i].cena);
    printf("Uneti broj na stanju: ");
    scanf("%d", &odela[i].brojNaStanju);

    getchar();

    printf("\n");
    *n = i + 1;


}

void ispisJednogOdela(Odelo odela[], int n) {
    int i = n - 1;

    printf("Naziv: %s\n", odela[i].naziv);
    printf("Zemlja porekla: %s\n", odela[i].zemljaPorekla);
    printf("Velicina: %d\n", odela[i].velicina);
    printf("Cena: %d\n", odela[i].cena);
    printf("Broj na stanju: %d\n\n", odela[i].brojNaStanju);

}

void ispisSvihOdela(Odelo odela[], int n) {

    if(n == 0) {
        printf("Ne postoje odela!");
        return;
    }

    int i;

    for(i = 0; i < n; i++) {
        printf("(-%d-)\n", i+1);
        printf("Naziv: %s\n", odela[i].naziv);
        printf("Zemlja porekla: %s\n", odela[i].zemljaPorekla);
        printf("Velicina: %d\n", odela[i].velicina);
        printf("Cena: %d\n", odela[i].cena);
        printf("Broj na stanju: %d\n\n", odela[i].brojNaStanju);
    }
}

void sacuvajOdela(Odelo odela[], int n) {
    FILE* file = fopen("odela.txt", "w");

    int i;
    for(i = 0; i < n; i++) {
        fprintf(file, "%s\n", odela[i].naziv);
        fprintf(file, "%s\n", odela[i].zemljaPorekla);
        fprintf(file, "%d\n", odela[i].velicina);
        fprintf(file, "%d\n", odela[i].cena);
        fprintf(file, "%d\n", odela[i].brojNaStanju);
    }

    fclose(file);
}

void pretragaTekstualnihPolja(Odelo odela[], int n) {
    int i;

    printf("Unesi neku rec:");
    char rec[30];
    getchar();
    gets(rec);

    int flag  = 0;

    for(i = 0; i < n; i++) {
        if(strstr(odela[i].naziv, rec) != NULL || strstr(odela[i].zemljaPorekla, rec) != NULL) {
            ispisJednogOdela(odela, i+1);
            flag = 1;
        }
    }

    if(flag == 0) {
        printf("Ne postoji nijedan!\n\n");
    }

}

void sortiranjePoCeni(Odelo odela[], int n) {
    int i;
    int j;
    Odelo temp;

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(odela[j].cena > odela[j+1].cena) {
                temp = odela[j];
                odela[j] = odela[j+1];
                odela[j+1] = temp;
            }
        }
    }

    ispisSvihOdela(odela, n);

}

// u ovoj funkcijii se brise odelo sa rednim brojem - dokument se otvara sa "w" da bi na pocetku bio prazan jer su sva odela ionako u nizu struktura. Nakon toga se sve opet upisuje u fajl samo se preskace odelo sa datim rednim brojem.
void brisanjeOdela(Odelo odela[], int n) {
    ispisSvihOdela(odela, n);
    printf("Odaberite broj odela: ");
    int num;
    scanf("%d", &num);

    FILE* file = fopen("odela.txt", "w");
    int i;

    for(i = 0; i < n; i++) {
        if(i == num - 1) {
            continue;
        } else {
            fprintf(file, "%s\n", odela[i].naziv);
            fprintf(file, "%s\n", odela[i].zemljaPorekla);
            fprintf(file, "%d\n", odela[i].velicina);
            fprintf(file, "%d\n", odela[i].cena);
            fprintf(file, "%d\n", odela[i].brojNaStanju);
        }
    }

    fclose(file);
    ucitavanjeIzFajla(odela, &n);

}












