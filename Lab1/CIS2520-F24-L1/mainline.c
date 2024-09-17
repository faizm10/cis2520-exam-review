#include <stdio.h>
#include <string.h> /* for strlen(), strdup() */
#include <stdlib.h> /* for free() */

#include "dataReader.h"


#define	TABLE_MAX	16
#define	LINE_MAX		80


typedef struct DataElement {
	int key;
	char *value;
} DataElement;


/**
 * Load the table of attribute value entries
 */
int
loadDataTable(DataElement *table, int tablemax, char *filename)
{
	FILE *fp = NULL;
	char valuebuffer[LINE_MAX];
	int result;
	int nLoaded = 0;

	fp = fopen(filename, "r");
	if (fp == NULL) {
		perror("Failed to open input file");
		return -1;
	}

	while ((nLoaded < TABLE_MAX) && ((result = drReadDataLine(fp,
			&table[nLoaded].key,
			valuebuffer, LINE_MAX)) > 0)) {

		/*
		 * QUESTION: why do we not just pass the address of the
		 * "value" field in our table?
		 */
		printf("DBG: in \"load\" have content '%d/%s'\n",
				table[nLoaded].key, valuebuffer);
		table[nLoaded].value = strdup(valuebuffer);
		++nLoaded;
	}

	fclose(fp);
	return nLoaded;
}

/**
 * Print the table of attribute/value entries
 */
void
printTable(DataElement *table, int nEntries)
{
	printf("Table of %d entries\n", nEntries);
	for (int i = 0; i < nEntries; i++) {
		printf("   %3d -> '%s'\n", table[i].key, table[i].value);
	}
	printf("<<<<\n");
}


/**
 * Clear out the storage associated with the table
 */
void
clearTable(DataElement *table, int nEntries)
{
	int i;

	/** walk the table */
	for (i = 0; i < nEntries; i++) {
		if (table[i].value != NULL) {
			free(table[i].value);
		}
	}
}

/**
 * Main part of program - reads in each file in turn and prints
 * out the list from the file
 */
int
main(int argc, char **argv)
{
	struct DataElement table[TABLE_MAX];
	int i, nEntries, nTablesLoaded = 0;

	/*
	 * QUESTION: why does this for loop start at 1?  Is this an error?
	 */
	for (i = 1; i < argc; i++) {
		if ((nEntries = loadDataTable(table, TABLE_MAX, argv[i])) < 0) {
			fprintf(stderr, "Failure loading table from %s\n", argv[i]);
			/* 'failure' from main() is any non-zero value */
			return 1;
		}
		nTablesLoaded++;
		printTable(table, nEntries);
		clearTable(table, nEntries);
	}

	if (nTablesLoaded == 0) {
		fprintf(stderr, "No filenames given!\n");
		return 1;
	}

	/* exit with success if we get here */
	return 0;
}

