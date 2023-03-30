#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <fstream>
#include <Windows.h>
using namespace std;
// problemi con divisione(forse l'ho risolto) poi allegro rendere tutto piu bello, mettere la message box 
void manouno(int gio[], int cru[])
{
  int app, app3;
  for (int i = 0; i < 2; i++)
  {
    srand(time(0));
    app3 = rand() % 3;
    if (app3 == 0)
    {
      gio[i] = 10;
    }
    if ((app3 == 1) || (app3 == 2))
    {
      app = rand() % 10 + 2;
      gio[i] = app;
    }
    //
    app3 = rand() % 3;
    if (app3 == 0)
    {
      cru[i] = 10;
    }
    if ((app3 == 1) || (app3 == 2))
    {
      app = rand() % 10 + 2;
      cru[i] = app;
    }
    //
    app3 = rand() % 3;
    if (app3 == 0)
    {
      gio[i] = 10;
    }
    if ((app3 == 1) || (app3 == 2))
    {
      app = rand() % 10 + 2;
      gio[i] = app;
    }
    //
    app3 = rand() % 3;
    if (app3 == 0)
    {
      cru[i] = 10;
    }
    if ((app3 == 1) || (app3 == 2))
    {
      app = rand() % 10 + 2;
      cru[i] = app;
    }
  }
}

void blackjack(int cru[], int &credit, int &punt, string &contr)
{
  cout << "blackjack" << endl;
  if ((cru[0] + cru[1]) == 21)
  {
    cout << endl
         << "pareggio";
  }
  else
  {
    cout << "Hai vinto" << endl;
    credit += punt + punt;
  }
  cout << endl
       << "vuoi continuare? scrivi [y]es o [n]ot ";
  cin >> contr;
  cout << endl
       << "hai " << credit << " fish" << endl;
}
void giocate(int gio[], int cru[], int &punt, int &credit, string name, string &contr)
{
  int so = gio[0] + gio[1], sc = cru[0] + cru[1], controllo = 0, a = 0, app2 = 2, mae = 0, yu = 2;
  string pesca = "y";
  cout << name << " le tue carte sono " << gio[0] << " " << gio[1] << endl
       << "somma delle tue carte " << gio[0] + gio[1] << endl
       << "carta croupier " << cru[0] << endl;
  srand(time(0));
  do
  {
    cout << endl
         << "vuoi pescare? scrivi [y]es o [n]ot ";
    cin >> pesca;
    if (pesca == "y")
    {
      for (int i = app2; i < app2 + 1; i++)
      {
        a = rand() % 10 + 2;
        if ((so > 21) && (a == 11))
        {
          gio[i] = 1;
        }
        else
        {
          gio[i] = a;
          so += gio[i];
        }
      }
      cout << "carte: ";
      for (int i = 0; i < app2 + 1; i++)
      {
        cout << gio[i] << " ";
      }
      cout << endl
           << "somma delle carte=" << so;
      if (so > 21)
      {
        controllo = 10;
        if (controllo == 10)
        {
          cout << endl
               << name << " hai sballato!!";
          credit -= punt;
          pesca = "n";
        }
      }
      app2++;
    }
  } while (pesca != "n");
  if (controllo != 10)
  {
    cout << "crupier mano:";
    for (int i = 0; i < 10; i++)
    {
      if (cru[i] != 0)
      {
        cout << cru[i] << " ";
      }
    }
    cout << endl;
    while (sc <= 16)
    {
      mae = rand() % 10 + 2;
      cru[yu] = mae;
      sc += mae;
      cru[yu] = mae;
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
      for (int i = 0; i < 10; i++)
      {
        if (sc > 22)
        {
          if (cru[i] == 11)
          {
            cru[i] = 1;
          }
        }
      }
    }
    if (sc < 22)
    {
      if ((sc > so) || (sc == so))
      {
        cout << name << " hai perso!!";
        credit -= punt;
      }
      else
      {
        cout << name << " hai vinto!!";
        credit += punt;
      }
    }
    else
    {
      cout << name << " hai vinto!! il crupier ha sballato!! ";
      credit += punt;
    }
  }
  cout << endl
       << "vuoi continuare? scrivi [y]es o [n]ot ";
  cin >> contr;
  cout << endl
       << "hai " << credit << " fish" << endl;
}
void creditoper(int &credit)
{
  ifstream ducumento("file/credito.txt");
  while (ducumento >> credit)
  {
  }
}
void nam(string &name, int credit)
{
  string app;
  ifstream ducumento("file/name.txt");
  while (ducumento >> name)
  {
  }
  cout << "vuoi continuare il game come " << name << " con " << credit << " fish "
       << "[y]es o [n]o" << endl;
  cin >> app;
  if (app != "n")
  {
    cout << "ok puoi continuare" << endl;
  }
  else
  {
    cout << "sei sicuro? scrivi [y]es se vuoi confermare se no [n]o" << endl;
    cin >> app;
    if (app == "y")
    {
      cout << "come ti vuoi chiamare " << endl;
      cin >> name;
      ofstream documento("file/name.txt");
      documento << name;
      documento.close();
      int app3 = 10000;
      ofstream ciao("file/credito.txt");
      ciao << app3;
      ciao.close();
    }
    cout << "ti chiami " << name << " e hai 10000 fish ";
  }
}
void regole()
{
  system("start www.pokerstars.it/casino/how-to-play/blackjack/rules");
}
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
      if ((gio[0] == 11) && (gio[1] == 11))
      {
        manouno(gio, cru);
      }
      if (((gio[0] + gio[1]) == 21) && (contr != "n"))
      {
        blackjack(cru, credit, punt, contr);
      }
      if ((gio[0] == gio[1]) && (contr != "n"))
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
      if ((((gio[0] + gio[1]) != 21) || (div != "y")) && (contr != "n"))
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
  cout << endl;
  Sleep(3000);
  return 0;
}