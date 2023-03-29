#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
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
int main()
{
  const int n = 10;
  int gio[n] = {10, 10, 0, 0, 0, 0, 0, 0, 0, 0}, cru[n] = {4, 10, 0, 0, 0, 0, 0, 0, 0, 0}, punt = 100, credit = 1000;
  string name = "monfo", contr;
  divisione(gio, cru, punt, credit, name, contr);
  return 0;
}
