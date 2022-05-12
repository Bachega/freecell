#include "jogo.h"

int main(int argc, char* argv[]) {
    int i = 0;
    if(argc == 2) i=1;
    jogo(i, argv);
    system("cls");
	return 0;
}
