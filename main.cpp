#include <iostream>
#include <math.h>

using namespace std;
 

 



int main(){


float R = 0, L = 0, C = 0;
float vC, iL;, //condiçoes iniciais
float sigma = 0, omegaZero = 0, omegaD = 0; // relacionados ao tipo de resposta
int unidade = 0; 
float s1, s2; //raizes da equação 


cout << "Digite o valor de R: ";
cin >> R;
cout << "Digite a unidade de R: ";
cin >> unidade;
R = R * pow(10, unidade);

cout << "Digite o valor de L: ";
cin >> L;
cout << "Digite a unidade de L: ";
cin >> unidade;
L = L * pow(10, unidade);

cout << "Digite o valor de C: ";
cin >> C;
cout << "Digite a unidade de C: ";
cin >> unidade;
C = C * pow(10, unidade);

sigma = 1/(2*R*C);
omegaZero = 1/(sqrt(L*C));
omegaD = sqrt((omegaZero*omegaZero) - (sigma*sigma));

if (sigma>omegaZero){
    cout << "Aurélio José e João"; << endl;
    cout << "Este circuito é superamortecido" << endl;
    s1 = -sigma + sqrt((sigma*sigma) - (omegaZero*omegaZero));
    s2 = -sigma - sqrt((sigma*sigma) - (omegaZero*omegaZero));
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;

    cout << "Resposta: " << vC*exp(s1*t) + iL*exp(s2*t) << endl;
}
else if (sigma<omegaZero){
    cout << "Aurélio José e João"; << endl;
    cout << "Resposta exponencial crescente subamortecido" << endl;
    s1 = -sigma + sqrt((sigma*sigma) - (omegaZero*omegaZero));
    s2 = -sigma - sqrt((sigma*sigma) - (omegaZero*omegaZero));
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;

    cout << "Resposta: " << vC*exp(s1*t) + iL*exp(s2*t) << endl;
}
else if (sigma==omegaZero){
    cout << "Aurélio José e João"; << endl;
    cout << "Resposta exponencial criticamente amortecido" << endl;
    s1 = -sigma + sqrt((sigma*sigma) - (omegaZero*omegaZero));
    s2 = -sigma - sqrt((sigma*sigma) - (omegaZero*omegaZero));
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "Resposta: " << vC*exp(s1*t) + iL*exp(s1*t) << endl;
}











}