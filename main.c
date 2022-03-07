#include "ejemplo/apostador.h"
#include "ejemplo/crupier.h"
#include "ejemplo/apostador.c"
#include "ejemplo/crupier.c"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    Crupier* robert= CRUPIER_create("Robert");
    Apostador* sara= APOSTADOR_create("Sara");
    Apostador* emma= APOSTADOR_create("Emma");

    sara->apostar(sara, 5,  robert);
    emma->apostar(emma, 5,  robert);

    robert->lanzar(robert);

	sara->destroy(sara);
	emma->destroy(emma);
    robert->destroy(robert);

	return 0;
}