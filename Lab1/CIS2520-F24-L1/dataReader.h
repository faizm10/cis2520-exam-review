#ifndef	__KEY_VALUE_PARSER_HEADER__
#define	__KEY_VALUE_PARSER_HEADER__

/**
 * Read in an data element from the file.
 */
int drReadDataLine(
			FILE *dataFP,
			int *key,
			char *value,
			int maxlinelen
		);

#endif /* __KEY_VALUE_PARSER_HEADER__ */
