#ifndef Gaussianos_Lib

typedef struct G{
    int a, b;
}G;
G Read_G(int a, int b);
void Write_G(G g1);
G Sum_G(G g1, G g2);
G Minus_G(G g1, G g2);
G Prod_G(G g1, G g2);

#define Gaussianlos_Lib
#endif
