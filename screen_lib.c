#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "screen_lib.h"


char screen[SCREEN_X][SCREEN_Y];



void affiche_scr()
{
    int x,y;
	for(y = 0; y < SCREEN_Y; y++)
    {
		for(x = 0; x < SCREEN_X; x++)
        {
		printf("%c",screen[x][y]);
        }
        printf("\n");
	}
return;
}

void clear_scr()
{
    int x,y;
	for(y = 0; y < SCREEN_Y; y++)
    {
		for(x = 0; x < SCREEN_X; x++)
        {
		screen[x][y]='0';
        }
	}
return;
}


void plot_scr(unsigned int x, unsigned int y){

    if ((x<0)|| (x>SCREEN_X) || (y<0) || (y>SCREEN_Y)) 
		return; /* evite de taper en dehors du tableau */
	screen[x][y] = '1';
return;
}



void line_horiz_scr(unsigned int x, unsigned int y, unsigned int l)
    {
        
	return;
    }

void line_vert_scr(unsigned int x,unsigned int y, unsigned int l)
    {
	
	return;        
    }
    
int save_P1(void)
    {
        int x,y;
        FILE * stream; 


        stream = fopen ("imageP1.pbm","w");
        
        if (stream == NULL)  /*STOP */
        {
            printf("Erreur d'ouverture du fichier !\n");
            return EXIT_FAILURE;
        }
        
        fprintf(stream,"P1\n");
        fprintf(stream,"%d %d\n",SCREEN_X,SCREEN_Y);

        for(y = 0; y < SCREEN_Y; y++)
        {
            for(x = 0; x < SCREEN_X; x++)
            {
            fprintf(stream,"%c ",screen[x][y]);
            }
            fprintf(stream,"\n");
        }
    return EXIT_SUCCESS;
    }
    
    
void line(int x0, int y0, int x1, int y1) 
    {
 
  int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
  int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
  int err = (dx>dy ? dx : -dy)/2, e2;
 
  for(;;){
    plot_scr(x0,y0);
    if (x0==x1 && y0==y1) break;
    e2 = err;
    if (e2 >-dx) { err -= dy; x0 += sx; }
    if (e2 < dy) { err += dx; y0 += sy; }
  }
}

void circle (int xm, int ym, int r)
{
   int x = -r, y = 0, err = 2-2*r; /* II. Quadrant */ 
   do {
      plot_scr (xm-x, ym+y); /*   I. Quadrant */
      plot_scr (xm-y, ym-x); /*  II. Quadrant */
      plot_scr (xm+x, ym-y); /* III. Quadrant */
      plot_scr (xm+y, ym+x); /*  IV. Quadrant */
      r = err;
      if (r >  x) err += ++x*2+1; /* e_xy+e_x > 0 */
      if (r <= y) err += ++y*2+1; /* e_xy+e_y < 0 */
   } while (x < 0);
}

