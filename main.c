#include <stdio.h>
#include <errno.h>
#include <string.h>
void dump_file(FILE *f) {
	int c;
	while ((c = getc(f)) != EOF || (!feof(f) && !ferror(f))) {
		putchar(c);
	}
}

int main(int argc, char **argv) {
	FILE *f;
	int i, e = 0;
	for (i = 1; i < argc; i++) {
		char *arg = argv[i];
		if (!(f = fopen(arg, "r"))) {
			fprintf(stderr, "cat: %s: %s\n", arg, strerror(errno));
			e = 1;
			continue;
		}
		fclose(f);
	}
	if (e) {
		return 1;
	}
	for (i = 1; i < argc; i++) {
		f = fopen(argv[i], "r");
		dump_file(f);
		fclose(f);
	}
	return 0;
}
