/*****
source code sortieren_strukturarray_teilloesung.c
date 15.10.2016
author Pius Senn
StrukturArray
sortieren, Beispielloesung
Daten aus File lesen
Daten nach Namen oder Preis sortieren
Daten ausgeben
*****/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Konstanten
#define STRINGLAENGE_NAMEN 31
#define MAX_BUECHER 10

// DatenStruktur fuer einen Datensatz
struct buch_t {
  char name[STRINGLAENGE_NAMEN];
  double preis;
};

// FunktionsPrototypen
int menu(void);
int leseDatei(struct buch_t[], const char *);
void zeigeTabelle(struct buch_t[], int);

/***** Hauptprogramm *****/
int main(void) {
struct buch_t tabelle[MAX_BUECHER]; // Array mit Datensaetzen (array of
struct)
int wahl; // Menuewahl des Users
int anzahl; // Anzahl Datensaetze, 0 = File nicht
vorhanden (oder leer)
char filename[] = "buecher.txt"; // DateiName

do {
  wahl = menu();
  switch (wahl) {
  case 1:
    anzahl = leseDatei(tabelle, filename);
    if (!anzahl) {
      printf("ERROR: File konnte nicht geoeffnet werden: %s\n", filename);
}
break;

  case 2:
  zeigeTabelle(tabelle, anzahl);
  break;

  case 3:
  // Funktionsaufruf, um nach Namen aufsteigend zu sortieren
  break;
  
  case 4:
  // Funktionsaufruf, um nach Preis aufsteigend zu sortieren
  break;

  case 5:
  break;

  default:
    printf("Falsche Eingabe!\n");
  }
  printf("\n\n");
  
  } while (wahl != 5);
  
  return 0;
}

/***** Funktion menu() *****
Ausgabe der Menuepunkte
Einlesen der Wahl des Users
Rueckgabewert Wahl des Users
******/

int menu(void) {
  int wahl; // Menuewahl des Users
  
  // Titel ausgeben
  printf("BuecherSortieren\n");
  printf("*****************\n\n");
  printf("1 Daten einlesen\n");
  printf("2 Tabelle anzeigen\n");
  printf("3 Tabelle sortieren aufsteigend nach Namen\n");
  printf("4 Tabelle sortieren aufsteigend nach Preis\n");
  printf("5 Programm verlassen\n");
  printf("\nIhre Wahl: ");
  scanf("%d", &wahl);
  return wahl;
}

/***** Funktion leseDatei() *****
Daten von der Datei in das Array einlesen
Parameter:
- Array
- Filename

Rueckgabewert
- Anzahl gelesene Datensaetze, 0 = File nicht vorhanden
******/

int leseDatei(struct buch_t tabelle[], const char * filename) {
  FILE * myFile = NULL; // Dateipointer
  int index = 0; // Zaehler fuer die Buecher
  myFile = fopen(filename, "r");
  // File vorhanden?
  if (!myFile) {
    return 0;
  }

  // Daten lesen
  do {
    fscanf(myFile, "%[^\t]\t%lf\n", tabelle[index].name, &tabelle
    [index].preis);
    index++;
    } while (!feof(myFile));
  fclose(myFile);
  
  // Anzahl gelesene Datensaetze zurueckgeben
  return index;
 }

/***** Funktion zeigeTabelle() *****
BuecherTabelle auf Konsole ausgeben.
Parameter:
- Array
- Anzahl
- Eintraege im Array
******/
void zeigeTabelle(struct buch_t tabelle[], int anzahl) {
  int index; // Schleifenzaehler
  
  // Titel ausgeben
  printf("\n\nBuecher\n");
  printf("\n");
  
  // Daten ausgeben
  for (index = 0; index < anzahl; index++) {
    printf("%*s\t%5.2lf\n", STRINGLAENGE_NAMEN, tabelle[index].name, tabelle [index].preis);
  }
  printf("\n");
}
