#include <stdio.h>
#include <stdlib.h> /* for malloc()/free() */
#include <string.h> /* for strlen(), strdup() */
#include <ctype.h> /* for isprint() */

#include "dataReader.h"

#define	DELIMITER_CHAR	':'


/* forward references */
static char *stripNonPrinting(char *s);


/**
 * Read in an attribute/value pair from a file
 *
 * QUESTION: where does the memory come from that is being
 * managed in this function.  Is it from the STACK or the HEAP?
 * Where does it get allocated?  Where does it get deallocated?
 */
int
drReadDataLine(
			FILE *dataFP,
			int *key,
			char *value,
			int maxlinelen
		)
{
	char line[maxlinelen]; /* allocate a local array on the stack */
	char *delimiterPosition = NULL, *cleanedValue = NULL;

	/** read the file until empty */
	if (fgets(line, maxlinelen, dataFP) == NULL) {
		return 0;
	}

	/** print what we read for debugging
	 *
	 * QUESTION: there is no newline at the end of this printf
	 * format, but there is a newline in the output.  Where does
	 * the newline come from?
	 */
	printf("DBG: in \"read\" read line:\n    %s", line);


	/** find the delimiter */
	delimiterPosition = strchr(line, DELIMITER_CHAR);
	if (delimiterPosition == NULL) {
		/**
		 * You can "continue" a string in C by simply having
		 * two double-quoted strings right after each other,
		 * so this call really has a single long string argument
		 * as the (concatenated) second argument.
		 */
		fprintf(stderr,
				"Error: Input line does not contain"
				"delimiter char '%c': '%s'\n",
				DELIMITER_CHAR, line);
		return -1;
	}

	/**
	 * At this point, the string starting one character
	 * _after_ the delimiter is our value, and the string
	 * up to the delimiter is our integer key.  If we
	 * cut the string here, sscanf will give us the key,
	 * and we can compute the value as simply this position
	 * plus one
	 */
	*delimiterPosition = '\0';

	if (sscanf(line, "%d", key) != 1) {
		fprintf(stderr, "Error: cannot parse integer key from '%s'\n", line);
		return -1;
	}

	/**
	 * use the line from one character after the delimiter
	 * as the value we want to keep -- after cleaning up
	 * that portion of the line by removing any non-printable
	 * or 'blank' characters from beginning and end of the string
	 */
	cleanedValue = stripNonPrinting(&delimiterPosition[1]);
	printf("DBG: in \"read\" - 'clean' value is '%s'\n", cleanedValue);

	/**
	 * QUESTION: is this the right way to assign this?
	 */
	value = cleanedValue;

	printf("DBG: in \"read\" - key/value are '%d/%s'\n",
			*key, value);

	return 1;
}

/**
 * Return true (i.e.; nonzero) for characters we want to keep,
 * determined by isprint() and checks for tab and space.
 *
 * Tab and space must be checked for separately, as isprint()
 * considers these "printable" characters.
 *
 * "Wrapping" a function like this to modify its functionality
 * is a great way to make code more readable and collect all
 * of the "fixes" in one place.
 */
static int
dataCharacter(char c)
{
	/* if a blank or a tab, return false */
	if ((c == ' ') || (c == '\t'))	return 0;

	/* otherwise, return  isprint() */
	return ( isprint(c) );

}

/**
 * Strip any non-printing characters from the beginning and end of
 * the provided string
 *
 * N.B.: this function modifies the string in place to achieve this
 */
static char *
stripNonPrinting(char *s)
{
	int i;

	/** first walk up the string until we come to a printable byte */
	while ( ( *s != '\0' ) && ( ! dataCharacter(*s) )) {
		s++;
	}

	/** walk backwards from end, wiping out all non-printing character */

	i = strlen(s);
	while ((i >=0) && ( ! dataCharacter(s[i]) ) ) {
		s[i--] = 0;
	}

	return s;
}

