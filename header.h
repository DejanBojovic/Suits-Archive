#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

// struktura svakog odela
typedef struct {
    char naziv[30];
    char zemljaPorekla[30];
    int velicina;
    int cena;
    int brojNaStanju;

} Odelo;

void ucitavanjeIzFajla(Odelo odela[], int *n);
void unosOdela(Odelo odela[], int *n);
void ispisJednogOdela(Odelo odela[], int n);
void ispisSvihOdela(Odelo odela[], int n);
void sacuvajOdela(Odelo odela[], int n);
void Menu();
void pretragaTekstualnihPolja(Odelo odela[], int n);
void sortiranjePoCeni(Odelo odela[], int n);
void brisanjeOdela(Odelo odela[], int n);

#endif // HEADER_H_INCLUDED
