#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <fstream>
#include <Windows.h>
using namespace std;
void manouno(int gio[], int cru[])
{
  int app, app3;
  srand(time(0));
  for (int i = 0; i < 2; i++)
  {
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
