#include <stdio.h>
#include <stdlib.h>

const char *shift(int *argc, char ***argv)
{
	if (!(*argc)) {
		return "";
	}
	const char *result = *argv[0];
	*argc -= 1;
	*argv += 1;
	return result;
}

size_t my_strlen(const char *s)
{
	size_t n = 0;
	while (*s++ != '\0') {
		++n;
	}
	return n;
}

void my_memcpy(char *dest, char *src, size_t n)
{
	for (int i=0; i<n; ++i) {
		dest[i] = src[i];
	}
}

char *concat(int argc, char **argv)
{
	size_t size = argc*10;
	char *cat = calloc(size, sizeof(char));
	int i = 0;
	int n = 0;
	while (argc > 0){
		const char *arg = shift(&argc, &argv);
		size_t s_arg = my_strlen(arg);
		n += s_arg;
		if (n >= size || s_arg >= size) {
			size *= 2;
			cat = realloc(cat, size);
		}
		my_memcpy(cat+(n-s_arg), (char *)arg, s_arg);
		my_memcpy(cat+n, " ", 1);
		++n;
	}
	return cat;
}

int main(int argc, char **argv)
{
	shift(&argc, &argv); // shift program name;
		
	const char *cmd = concat(argc, argv);
	FILE *file = popen(cmd, "r");
	if (!file) {
		printf("failed to run the following command: %s\n", cmd);
		return 1;
	}
	char c;
	while ((c=fgetc(file)) != EOF){
		putchar(c);
	}
	pclose(file);
	return 0;
}
