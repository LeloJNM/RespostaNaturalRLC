#include <iostream>
#include <math.h>
#include<bits/stdc++.h>

using namespace std;

/*/ double ajustarUnidade(double i){
    if(i>=1000 && i <= 999999.99){
        return i/1000 + "k";
    }else if(i>=1000000 && i<= 999999999){
        return i/1000000 + "M";
    }else if(i>=1000000000 && i<= 999999999999){
        return i/1000000000 + "G";
    }else if (i<=0 && i>= 0.001){
        return i*1000 + "m";
    }else if (i<=0.000001 && i>= 0.000000001){
        return i*1000000 + "u";
    }else if (i<=0.0000001 && i>= 0.000000001){
*/
int main(){


double R = 0, L = 0, C = 0;
double vC, iL;//condiçoes iniciais
double sigma = 0, omegaZero = 0, omegaD = 0; // relacionados ao tipo de resposta
double s1, s2; //raizes da equação
double iC; //corrente no capacitor no instante t
double a1, a2;
double b1,b2;
double tm, vtm;
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
    
    cout << "O valor de sigma é: " << fixed << setprecision(3) << sigma << "Hz" << endl;
    cout << "O valor de omega zero é: " << fixed << setprecision(3) << omegaZero << "rad/s" << endl;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;


    a1 = (x-(s2*vC))/(s1-s2);
    a2 = vC-a1;

    tm = (log10((-(a2*s2))/(a1*s1))/log10(2.71828))/(s1-s2);
    vtm = a1*exp(s1*tm) + a2*exp(s2*tm);

    cout << "O valor de a1 é: " << a1 << endl;
    cout << "O valor de a2 é: " << a2 << endl;
    cout << "O valor de tm é: " << fixed << setprecision(10) << tm << "s" << endl;
    cout << "O valor de vtm é: " << vtm << "V" << endl;
}
else if (sigma<omegaZero){
    cout << "Aurélio José e João" << endl;
    cout << "Tipo de resposta subamortecido" << endl;

    omegaD = sqrt((omegaZeroQuadrado) - (sigmaQuadrado));

    b1 = vC;
    b2 = (x-(b1*sigma))/omegaD;

    double y = (b2*omegaD - sigma*b1)/(b1*omegaD + sigma*b2);
    tm = atan(y)/omegaD;
    while (tm<0){
        tm += M_PI/omegaD;
    }
    vtm = exp(-sigma * tm) * (b1 * cos(omegaZero *tm) + (b2*sin(omegaZero * tm)));

    cout << "O valor de sigma é: " << fixed << setprecision(3) << sigma << "Hz" << endl;
    cout << "O valor de omega zero é: " << fixed << setprecision(3) << omegaZero << "rad/s" << endl;
    cout << "O valor de omega d é: " << omegaD << "rad/s" << endl;
    cout << "O valor de B1 é: " << b1 << endl;
    cout << "O valor de B2 é: " << b2 << endl;
    cout << "O valor de tm é: " << fixed << setprecision(10) << tm << "s" << endl;
    cout << "O valor de vtm é:" << vtm << endl;
}
else if (sigma==omegaZero){
    cout << "Aurélio José e João" << endl;
    cout << "Tipo de resposta criticamente amortecido" << endl;


    s1 = -sigma;
    s2 = -sigma;

    cout << "O valor de s1 é: " << s1 << endl;
    cout << "O valor de s2 é: " << s2 << endl;

    a1 = x + (sigma*vC);
    a2 = vC;

    tm = (((-a2 * sigma) / a1) + 1) / sigma;
    vtm = (a1 * tm + a2) * (exp(-sigma * tm));

    cout << "O valor de sigma é: " << fixed << setprecision(3) << sigma << "Hz" << endl;
    cout << "O valor de omega zero é: " << fixed << setprecision(3) << omegaZero << "rad/s" << endl;
    cout << "O valor de A1 é: " << a1 << endl;
    cout << "O valor de A2 é: " << a2 << endl;
    cout << "O valor de tm é: " << fixed << setprecision(10) << tm << "s" << endl;
    cout << "O valor de vtm é:" << vtm << endl;

    }
}