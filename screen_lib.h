#ifndef SCREEN_LIB_H
#define SCREEN_LIB_H  


#define SCREEN_Y 100
#define SCREEN_X 200


void affiche_scr();
void clear_scr();

void plot_scr(unsigned int x, unsigned int y);
void locate_scr(unsigned int x, unsigned int y, char *s);

void line_horiz_scr(unsigned int x, unsigned int y, unsigned int l);
void line_vert_scr(unsigned int x, unsigned int y, unsigned int l);
int save_P1(void);
void line(int x0, int y0, int x1, int y1);
void circle (int xm, int ym, int r);

#endif
