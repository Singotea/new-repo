#include <stdio.h>
#include <stdlib.h>
const size_t BUFFER_LEN = 512;
int main(void) {
	char buffer[512];
	char *pS[3] = { NULL };
	char *pbuffer = buffer;
	size_t index = 0;
// adsdaasdsadas
	printf("\n Enter 3 massages less than %u characters. \n",BUFFER_LEN-2);
	for (int i = 0; i < 3; i++) {
		printf("\n Enter %s message \n", i > 0 ? "another" : "a");
		pS[i] = &buffer[index];
		for (; index < BUFFER_LEN; index++) {
			if ((*(pbuffer + index) = getchar()) == '\n') {
				*(pbuffer + index++) = '\0';
				break;
			}
			if ((index == BUFFER_LEN) && ((*(pbuffer + index - 1) != '\0') || (i < 2))) {
				printf("\n too much for space in it \n");
				return 1;
			}
		}

	}
	printf("\n The String You Entered Are: \n\n");
	for (int i = 0; i < 3; i++) {
		printf("%s\n", pS[i]);
	}
	printf("\n The Buffer has %d characters unused. \n", BUFFER_LEN - index);
	system("pause");
	return 0;

}