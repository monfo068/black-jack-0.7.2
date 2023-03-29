#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <fstream>
#include <Windows.h>
#include "funz.cpp"
using namespace std;
// problemi con divisione poi allegro rendere tutto piu bello e commentare 

void divisione(int gio[], int cru[], int punt, int &credit, string name, string &contr)
{
  const int n = 10;
  int gio2[n] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, app = 0, app2 = 0, app3 = 2, app4 = 2, so = 0, so2 = 0, sc = 0, yu = 2, mae = 0, it = 0;
  string scelta = " ", scelta2 = " ";
  gio2[0] = gio[1];
  gio[1] = 0;
  srand(time(0));
  app = rand() % 3;
  if ((app == 0) || (app == 2))
  {
    app2 = rand() % 10 + 2;
    gio[1] = app2;
  }
  if (app == 1)
  {
    gio[1] = 10;
  }
  app = rand() % 3;
  if ((app == 0) || (app == 2))
  {
    app2 = rand() % 10 + 2;
    gio2[1] = app2;
  }
  if (app == 1)
  {
    gio2[1] = 10;
  }
  so = gio[0] + gio[1];
  so2 = gio2[0] + gio2[1];
  do
  {
    cout << "mano 1:";
    for (int i = 0; i < 10; i++)
    {
      if (gio[i] != 0)
      {
        cout << gio[i] << " ";
      }
    }
    cout << " somma=" << so << endl;
    cout << "mano 1 vuoi pescare? scrivi [y]es o [n]ot: ";
    cin >> scelta;
    if (scelta != "n")
    {
      app = rand() % 3;
      if ((app == 0) || (app == 2))
      {
        app2 = rand() % 10 + 2;
        gio[app3] = app2;
        so += app2;
      }
      if (app == 1)
      {
        gio[app3] = 10;
        so += 10;
      }
    }
    app3++;
  } while ((scelta != "n") && (so < 22));
  if (so > 21)
  {
    cout << "hai sballato con la prima mano" << endl;
    credit -= punt;
    cout << "fish=" << credit << endl;
  }
  do
  {
    cout << "mano 2:";
    for (int i = 0; i < 10; i++)
    {
      if (gio2[i] != 0)
      {
        cout << gio2[i] << " ";
      }
    }
    cout << " somma=" << so2 << endl;
    cout << "mano 2 vuoi pescare? scrivi [y]es o [n]ot: ";
    cin >> scelta2;
    srand(time(0));
    if (scelta2 != "n")
    {
      app = rand() % 3;
      if ((app == 0) || (app == 2))
      {
        app2 = rand() % 10 + 2;
        gio2[app4] = app2;
        so2 += app2;
      }
      if (app == 1)
      {
        gio2[app4] = 10;
        so2 += 10;
      }
    }
    app4++;
  } while ((scelta2 != "n") && (so2 < 22));
  if (so2 > 21)
  {
    cout << "hai sballato con la seconda mano" << endl;
    credit -= punt;
    cout << "fish=" << credit << endl;
  }
  if ((so > 21) && (so2 > 21))
  {
    cout << "hai sballato con entrabbe le mani" << endl;
    cout << "fish=" << credit << endl;
  }
  if ((so < 22) || (so2 < 22))
  {
    cout << "crupier mano:";
    for (int i = 0; i < 2; i++)
    {
      cout << cru[i] << " ";
    }
    cout << endl;
    sc = cru[0] + cru[1];
    while (sc <= 16)
    {
      mae = rand() % 10 + 2;
      cru[yu] = mae;
      sc += mae;
      cout << "mano crupier:";
      for (int i = 0; i < 10; i++)
      {
        if (cru[i] != 0)
        {
          cout << cru[i] << " ";
        }
      }
      yu++;
      cout << "il crupier ha " << sc << endl;
    }
    if (sc < 22)
    {
      if ((sc > so) || (sc == so))
      {
        cout << name << " hai perso!! con la prima mano " << endl;
        credit -= punt;
      }
      else
      {
        cout << name << " hai vinto!! con la prima mano " << endl;
        credit += punt;
      }
    }
    else
    {
      cout << name << " hai vinto con la prima mano!! il crupier ha sballato!!" << endl;
      credit += punt;
      it++;
    }
  }
  if (so2 < 22)
  {
    if (sc < 22)
    {
      if ((sc > so2) || (sc == so2))
      {
        cout << name << " hai perso!! con la seconda mano " << endl;
        credit -= punt;
      }
      else
      {
        cout << name << " hai vinto!! con la seconda mano " << endl;
        credit += punt;
      }
    }
    if (it == 1)
    {
      cout << name << " hai vinto con la seconda mano!!  il crupier ha sballato!!" << endl;
      credit += punt;
    }
  }
  cout << endl
       << "vuoi continuare? scrivi [y]es o [n]ot ";
  cin >> contr;
  cout << endl
       << "hai " << credit << " fish" << endl;
}

void reg()
{
  srand(time(0));
  const int n = 10;
  int gio[n] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, cru[n] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, punt = 0, credit = 0;
  string name, contr = "", div = "y";
  creditoper(credit);
  nam(name, credit);
  if (credit > 0)
  {
    do
    {
      do
      {
        if (punt > credit)
        {
         cout << "dottore non puo puntare piu di quanto ha, non deve diventare ludopatico!!" << endl;
        }
        cout << "quanto vuoi puntare: ";
        cin >> punt;
      } while (punt > credit);
      manouno(gio, cru);
      if (((gio[0] + gio[1]) == 21)&&(contr!="n"))
      {
        blackjack(cru, credit, punt, contr);
      }
      if ((gio[0] == gio[1])&&(contr!="n"))
      {
        cout << gio[0] << " " << gio[1] << endl
             << "somma carte=" << gio[0] + gio[1] << endl;
        cout << "vuoi dividere? [y]es o [n]o ";
        cin >> div;
        if (div == "y")
        {
          credit -= punt;
          divisione(gio, cru, punt, credit, name, contr);
        }
      }
      if ((((gio[0] + gio[1]) != 21) || (div != "y"))&&(contr!="n"))
      {
        giocate(gio, cru, punt, credit, name, contr);
      }
      ofstream documento("file/credito.txt");
      documento << credit;
      documento.close();
    } while (contr != "n"); 
  }
}

int main()
{
  int a = 0;
  cout << "1) GIOCA " << endl
       << "2) REGOLE" << endl;
  do
  {
    cin >> a;
  } while ((a != 1) && (a != 2));
  if (a == 1)
  {
    reg();
  }
  if (a == 2)
  {
    regole();
    cout << "Ora sei pronto a giocare" << endl;
    reg();
  }
  cout << endl ; 
  system("pause"); 
  return 0;
}