#include <iostream>
#include <math.h>

using namespace std;
 

int main(){


float R = 0, L = 0, C = 0;
float sigma = 0, omegaZero = 0, omegaD = 0;
int unidade = 0;

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

cout << "Digite o valor de sigma: ";
cin >> sigma;
cout << "Digite a unidade de sigma: ";
cin >> unidade;
sigma = sigma * pow(10, unidade);

cout << "Digite o valor de omegaZero: ";
cin >> omegaZero;
cout << "Digite a unidade de omegaZero: ";
cin >> unidade;
omegaZero = omegaZero * pow(10, unidade);

cout << "Digite o valor de omegaD: ";
cin >> omegaD;
cout << "Digite a unidade de omegaD: ";
cin >> unidade;
omegaD = omegaD * pow(10, unidade);


cout << ""




}