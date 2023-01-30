#ifndef Racionales_Lib

typedef struct Q{
    int p ,q;
}Q;
int mcd(int a, int b);
Q Simple_Q(Q q1);
Q Read_Q(int p, int q);
void Write_Q(Q q1);
Q Sum_Q(Q q1, Q q2);
Q Minus_Q(Q q1, Q q2);
Q Prod_Q(Q q1, Q q2);
Q Div_Q(Q q1, Q q2);
Q Square_Q(Q q1);

#define Racionales_Lib
#endif
