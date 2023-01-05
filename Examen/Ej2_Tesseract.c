/*Draw a line from current point to 
point(x,y) using lineto() function*/


//#include <graphics.h>
//#include <conio.h>
 
#include <graphics.h>
main()
{
   int gd = DETECT, gm;
 
   //init graphics
   initgraph(&gd, &gm, "C:/TURBOC3/BGI");
   /*
   if you are using turboc2 use below line to init graphics:
   initgraph(&gd, &gm, "C:/TC/BGI");
   */

   //draw a line
   lineto(100,200); //will dra a line to point(100,200)

   getch();
   closegraph();
   return 0;
}