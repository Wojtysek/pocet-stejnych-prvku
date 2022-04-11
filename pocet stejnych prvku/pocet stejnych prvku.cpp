#include <stdio.h>

int main() {
	int pocet[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int cisla[10];

	int znak = 0;
	int cislo = 0;

	FILE* soubor = fopen("cisla.txt", "r");

	if (soubor == NULL) {
		printf("Chyba: Soubor nelze otevrit pro cteni.\n");
	}

	while (!feof(soubor)) {
		fscanf(soubor, "%d", &cisla[znak]);
		znak++;
	}
	for (int i = 0; i < 10; i++) {
		cislo = cisla[i];
		pocet[cislo]++;
	}
	for (int i = 0; i < 10; i++) printf("Cislo %d se vyskytuje v souboru %dx\n", i, pocet[i]);


	if (fclose(soubor) == EOF) {
		printf("Chyba: Soubor nelze zavrit.\n");
	}
}