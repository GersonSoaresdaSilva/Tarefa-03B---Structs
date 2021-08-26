/*Ler o valor correspondente ao salário mensal (variável SM) de um trabalhador e também o valor do percentual de reajuste (variável PR) a ser atribuído. Apresentar o valor do novo salário (variável NS).*/

#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

int const n = 4;
int pos = -1;

typedef struct salario tabsal;
struct salario
{
  double salarioSM [n];
  double reajustePR [n];
  double salarioNS [n];  
};
tabsal tabNovo;

double lerSalario ();
double lerPercentual ();
void regNovo ();
void exibir ();
void controle ();

int main() 
{
  setlocale (LC_ALL, "Portuguese");
  controle();  
  return 0;
}

double lerSalario ()
{
  double salAtual;
  cout << "\nInforme o Salário Mensal.: ";
  cin >> salAtual;
  return salAtual;
}

double lerPercentual ()
{
  double percSal;
  cout << "\nInforme o percentual de aumento.: ";
  cin >> percSal;
  cout << "\n------------------------------------------------------";
  return percSal;
}

void regNovo ()
{
  pos ++;
  double sal_, reajuste_, salnovo_;   
  
  if (pos > n - 1)
  {
    system ("clear");
    cout << "Limite de Dados foi atingido!" << endl;
    system ("sleep 3");
    return;
  }
  
  
  sal_ = lerSalario();
  tabNovo.salarioSM [pos] = sal_;

  reajuste_ = lerPercentual();
  tabNovo.reajustePR [pos] = reajuste_;
  
  salnovo_ = sal_ * (1 + reajuste_ / 100);  
  tabNovo.salarioNS [pos] = salnovo_;
  cout << pos;
}

void exibir ()
{
  double salSM, perPR, salNV;
  system ("clear");
  cout << "\n\n*** Resultados ***";
  for (int i = 0; i <= n - 1; i++)
  {
    salSM = tabNovo.salarioSM [i];
    perPR = tabNovo.reajustePR [i];
    salNV = tabNovo.salarioNS [i];
    
    cout << "\n - Salário Informado.......: " << salSM;
    cout << "\n - Percentual de Reajuste .: " << perPR;
    cout << "\n - Salário Reajustado......: " << salNV;
    cout << "\n------------------------------------------------------";
  } 
  system ("sleep 5");
  return ;
}

void controle ()
{
  int opc;
  while (true)
  {
  system ("clear");
  cout << "\n\n*** Menu de Controle ***";
  cout << "\n1 - Ler Valores.:";
  cout << "\n2 - Exibir......:";
  cout << "\n3 - Sair........:" << endl;
  cout << "--- Opção.: ";
  cin >> opc;
    
    switch (opc) 
    {
      case 1: regNovo(); break;
      case 2: exibir (); break;
      case 3: exit (0); break;
    }
  }
}