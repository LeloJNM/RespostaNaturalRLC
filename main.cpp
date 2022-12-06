#include <iostream>
#include <math.h>

using namespace std;






int main(){


double R = 0, L = 0, C = 0;
double vC, iL;//condiçoes iniciais
double sigma = 0, omegaZero = 0, omegaD = 0; // relacionados ao tipo de resposta
double s1, s2; //raizes da equação
double iC; //corrente no capacitor no instante t
double a1, a2;
double b1,b2;
double t; //Tempo
int unidade = 0; //notação de engenharia

// adquirindo valores  e as condiçoes iniciais

cout << "Digite o valor de R: ";
cin >> R;
cout << "Digite a unidade de R(dado em potencia de 10): ";
cin >> unidade;
R = R * pow(10, unidade);

cout << "Digite o valor de L: ";
cin >> L;
cout << "Digite a unidade de L(dado em potencia de 10): ";
cin >> unidade;
L = L * pow(10, unidade);

cout << "Digite o valor de C: ";
cin >> C;
cout << "Digite a unidade de C(dado em potencia de 10): ";
cin >> unidade;
C = C * pow(10, unidade);

cout << "digite o valor da tensao no capacitor(vC): ";
cin >> vC;
cout <<"digite a unidade de vC(dado em potencia de 10): ";
cin >> unidade;
vC = vC * pow(10, unidade);

cout << "digite o valor da corrente no indutor(iL): ";
cin >> iL;
cout <<"digite a unidade de iL(dado em potencia de 10): ";
cin >> unidade;
iL = iL * pow(10, unidade);

//calculando sigma, omega zero e omega d


sigma = 1/(2*R*C);
omegaZero = 1/(sqrt(L*C));


double sigmaQuadrado = sigma*sigma;
double omegaZeroQuadrado = omegaZero*omegaZero;


iC = iL - (vC/R); // a soma das correntes é igual a zero, logo a corrente no capacitor é igual a corrente no indutor menos a corrente no resistor

//a1 + a2 = vC a1 + a2 é igual a tensao inicial para um instante t

//calculando os casos de superamortecido para sigma > omegazero, subamortecido quando sigma < omegazero e criticamente amortecido quando sigma = omegazero

double x = iC/C; //Para facilitar no calculo de ic/c que aparece para o calculo de A1 e B1

if (sigma>omegaZero){
    //

    cout << "Aurélio José e João" << endl;
    cout << "Tipo de resposta superamortecido" << endl;
    s1 = -sigma + sqrt((sigmaQuadrado) - (omegaZeroQuadrado));
    s2 = -sigma - sqrt((sigmaQuadrado) - (omegaZeroQuadrado));
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;


    a1 = (x-(s2*vC))/(s1-s2);
    a2 = vC-a1;

    cout << "a1 = " << a1 << endl;
    cout << "a2 = " << a2 << endl;
}
else if (sigma<omegaZero){
    cout << "Aurélio José e João" << endl;
    cout << "Tipo de resposta subamortecido" << endl;

    omegaD = sqrt((omegaZeroQuadrado) - (sigmaQuadrado));

    b1 = vC;
    b2 = (x-(b1*sigma))/omegaD;

    cout << "B1 = " << b1 << endl;
    cout << "B2 = " << b2 << endl;
}
else if (sigma==omegaZero){
    cout << "Aurélio José e João" << endl;
    cout << "Tipo de resposta criticamente amortecido" << endl;

    cout << "A1 = " << a1 << endl;
    cout << "A2 = " << a2 << endl;

}











}