#include <stdio.h>
#include <errno.h>
#include <string.h>
void dump_file(FILE *f) {
	int c;
	while ((c = getc(f)) != EOF || !feof(f)) {
		putchar(c);
	}
}
int main(int argc, char **argv) {
	FILE *f;
	int i, e;
	for (i = 1; i < argc; i++) {
		if (!(f = fopen(argv[i], "r"))) {
			fputs(strerror(errno), stderr);
			e = 1;
		}
	}
	if (e) {
		return 1;
	}
	for (i = 1; i < argc; i++) {
		f = fopen(argv[i], "r");
		dump_file(f);
	}
	return 0;
}
