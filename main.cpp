#include <iostream>
#include <math.h>

using namespace std;
 

 



int main(){


float R = 0, L = 0, C = 0;
float vC, iL;//condiçoes iniciais
float sigma = 0, omegaZero = 0, omegaD = 0; // relacionados ao tipo de resposta
int unidade = 0; 
float s1, s2; //raizes da equação 
float iC; //corrente no capacitor
float vL; //tensão no indutor
float a1, a2;
float t; //Tempo

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
omegaD = sqrt((omegaZero*omegaZero) - (sigma*sigma));

iC = -iL; // sabe-se que a corrente no capacitor é o inverso da corrente no indutor

//a1 + a2 = tensao inicial

//calculando os casos de superamortecido para sigma > omegazero, subamortecido quando sigma < omegazero e criticamente amortecido quando sigma = omegazero

if (sigma>omegaZero){
    cout << "Aurélio José e João" << endl;
    cout << "Este circuito é superamortecido" << endl;
    s1 = -sigma + sqrt((sigma*sigma) - (omegaZero*omegaZero));
    s2 = -sigma - sqrt((sigma*sigma) - (omegaZero*omegaZero));
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    a2 = ((s1*vC)-vL) / (s1-s2);
    a1 = vC - a2;
    cout << "a1 = " << a1 << endl;
    cout << "a2 = " << a2 << endl;
    cout << "Resposta: " << vC*exp(s1*t) + iL*exp(s2*t) << endl;
}
else if (sigma<omegaZero){
    cout << "Aurélio José e João" << endl;
    cout << "Resposta exponencial crescente subamortecido" << endl;
    s1 = -sigma + sqrt((sigma*sigma) - (omegaZero*omegaZero));
    s2 = -sigma - sqrt((sigma*sigma) - (omegaZero*omegaZero));
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;

    cout << "Resposta: " << vC*exp(s1*t) + iL*exp(s2*t) << endl;
}
else if (sigma==omegaZero){
    cout << "Aurélio José e João" << endl;
    cout << "Resposta exponencial criticamente amortecido" << endl;
    s1 = -sigma + sqrt((sigma*sigma) - (omegaZero*omegaZero));
    s2 = -sigma - sqrt((sigma*sigma) - (omegaZero*omegaZero));
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "Resposta: " << vC*exp(s1*t) + iL*exp(s1*t) << endl;
}











}