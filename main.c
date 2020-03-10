#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main()
{
    int n = 0; // broj odela - clanova niza struktura
    Odelo odela[100]; // niz struktura u koji se upisuju sva odela iz fajla
    ucitavanjeIzFajla(odela, &n); // pri pokretanju prgrama i pre beskonacnog menija se pokrece funkcija koja upisuje sva odela u niz struktura i daje ih nam na raspolaganje

    // beskonacni meni sa svim opcijama
    while(1) {

        int option;
        Menu();
        printf("Odaberi opciju: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                unosOdela(odela, &n);
                break;
            case 2:
                ispisJednogOdela(odela, n);
                break;
            case 3:
                ispisSvihOdela(odela, n);
                break;
            case 4:
                sacuvajOdela(odela, n);
                printf("Sacuvano u fajl!");
                return 0;
            case 5:
                pretragaTekstualnihPolja(odela, n);
                break;
            case 6:
                sortiranjePoCeni(odela, n);
                break;
            case 7:
                brisanjeOdela(odela, n);
                n--;
                break;
            default:
                printf("Unesi neku od validnih opcija!");
                break;
        }

    }

    return 0;
}
