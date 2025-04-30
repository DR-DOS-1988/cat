#include <stdio.h>
void dump_file(FILE *f) {
	int c;
	while ((c = getc(f)) != EOF || (!feof(f) && !ferror(f))) {
		putchar(c);
	}
}

int main(int argc, char **argv) {
	FILE *f;
	int i;
	for (i = 1; i < argc; i++) {
		char *arg = argv[i];
		if (!(f = fopen(arg, "r"))) {
			fprintf(stderr, "cat: %s: ", arg);
			perror("");
			continue;
		}
		dump_file(f);
		fclose(f);
	}
	return 0;
}
