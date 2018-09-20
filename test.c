#include <stdio.h>
#include <stdlib.h>
#include "screen_lib.h"



int main(int argc, char** argv)
{
	clear_scr();
    plot_scr(4,5);
    affiche_scr();
    line(3,3,20,50);
    circle(30,25,10);
    save_P1();
return EXIT_SUCCESS;
}
