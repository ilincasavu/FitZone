#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct membrii
{   char nume[30], prenume[30], nrtel[11];
    char tabel_clase[50];
}m[100];

struct angajati
{   char nume[30];
    char prenume[30];
    char nr_telefon[11];
    char post[30];
    int salariu;
}a[20];

struct clase
{   char nume[20], echipament[30];
    char dificultate[20];
    int pret;
    char ora[11];
}c[15];

struct locatie
{char adresa[100];
}l[10];

 void tab()
 {
     int i;
     cout<<endl<<endl;
     for(i=0; i<78; i++)
        cout<<" ";
 }

 void tab1()
 {
     int i;
     for(i=0; i<58; i++)
        cout<<" ";
 }

 void centrare()
 {
     int i;
     for(i=0; i<70; i++)
        cout<<" ";
 }

void angajati(int&n)
{   ifstream g("angajati.in");
    n=0;
    while(g>>a[n].nume>>a[n].prenume>>a[n].nr_telefon>>a[n].post>>a[n].salariu)
        n++;
}

void sal_ang(int n)
{    char nume[30],prenume[30];
     int i,gasit=0, j;
     cout<<endl<<endl;
     tab1();
     cout<<"ANGAJATI IN BAZA DE DATE:"<<endl<<endl;
     for(i=0;i<n;i++)
     {
         tab1();
         cout<<a[i].nume<<" "<<a[i].prenume<<endl;
     }
     cout<<endl;
     tab1();
     cout<<"INTRODU NUMELE SI PRENUMELE ANGAJATULUI:  ";
     cin>>nume>>prenume;
     for(i=0;i<n;i++)
     {if(stricmp(a[i].nume,nume)==0 && stricmp(a[i].prenume,prenume)==0)
        {
            tab1();
            cout<<"Salariul angajatului introdus este: "<<a[i].salariu<<" lei"; gasit=1;}
     }
     if(gasit==0)
     {
         cout<<endl;
         tab1();
         cout<<"Persoana "<<nume<<" "<<prenume<<" nu este angajat.";
     }
     cout<<endl<<endl;
    tab1();
    cout<<"Apasati 0 pentru a reveni la meniu ";
}

void locatii(int&nrl)
{
    ifstream i("locatii.in");
    nrl=0;
    while(i.get(l[nrl].adresa,100))
        {nrl++; i.get();}
}

void a_locatii(int &nrl)
{
    int i, j;
    for(i=0; i<70; i++)
        cout<<" ";
    cout<<"ORASELE IN CARE PUTETI GASI O SALA DE FITNESS SUNT:";
    cout<<endl<<endl;
    cout<<endl;
    for(i=0; i<nrl; i++)
    {
        for(j=0; j<78; j++)
            cout<<" ";
        cout<<l[i].adresa<<endl<<endl;
    }

}

void nr_locatii(int &nrl)
{
    char orasul[30];
    int i, ok=0, j;
    cout<<endl;
    tab1();
    cout<<"ORASELE SUNT:"<<endl<<endl;
    tab1();
    cout<<"Bucuresti"<<endl;
    tab1();
    cout<<"Craiova"<<endl;
    tab1();
    cout<<"Iasi"<<endl<<endl;
    tab1();
    cout<<"INTRODU ORAS:";
    cin>>orasul;
    cout<<endl;
    for(i=0; i<nrl;i++)
    {
         if(strstr(l[i].adresa,orasul)==l[i].adresa)
         {
             ok++;
             tab1();
             cout<<l[i].adresa<<endl;
         }
    }
    if(ok==0)
    {
        tab1();
        cout<<"Nu exista o sala in locatia introdusa";
    }
    cout<<endl<<endl;
    tab1();
    cout<<"Apasati 0 pentru a reveni la meniu ";
}

void citire_clase(int &nrc)
{
    ifstream h("clase.in");
    nrc=0;
    while(h>>c[nrc].nume>>c[nrc].dificultate>>c[nrc].pret>>c[nrc].ora>>c[nrc].echipament)
         nrc++;
}


void a_clase(int n)
 {
     int i, j;
     cout<<endl;
     tab1();
     cout<<"Clasele disponibile sunt:"<<endl<<endl;
     for(i=0;i<n;i++)
     {
         tab1();
         cout<<c[i].nume<<endl;
         tab1();
         cout<<"Dificultate: "<<c[i].dificultate<<endl;
         tab1();
         cout<<"In fiecare zi intre orele: "<<c[i].ora<<endl;
         tab1();
         cout<<endl;
     }

 }

void echipament()
{
    int i, j, ok=0;
    char clasa[20];
    tab1();
    cout<<"Ce clasa te intereseaza? ";
    cin>>clasa;
    for(i=0;i<5;i++)
    {
        if(stricmp(clasa,c[i].nume)==0)
        {
            ok=1;
            tab1();
            cout<<"Ai nevoie de: "<<c[i].echipament<<endl;
        }
    }
    if(ok==0)
    {
        cout<<endl;
       tab1();
        cout<<"Clasa introdusa nu exista.";
    }
    cout<<endl<<endl;
    tab1();
    cout<<"Apasati 0 pentru a reveni la meniu ";
 }

void membrii(int &n)
{
    ifstream f("membrii.in");
    n=0;
    while(f>>m[n].nume>>m[n].prenume>>m[n].nrtel>>m[n].tabel_clase)
        n++;

}

void a_mem(int n)
{
    int i, j;
    cout<<endl;
    tab1();
    cout<<"Membrii inregistrati sunt:"<<endl<<endl<<endl;
    for(i=0; i<n; i++)
    {
        tab1();
            cout<<m[i].nume<<" "<<m[i].prenume<<endl;
            tab1();
            cout<<"Date de contact: "<<m[i].nrtel<<endl;
            tab1();
            cout<<"Clasele la care e inscris: "<<m[i].tabel_clase<<endl;
            cout<<endl;

    }
    cout<<endl<<endl;
    tab1();
    cout<<"Apasati 0 pentru a reveni la meniu ";

}

void info_mem(int n)
{
    int ok=0, i, j;
    char clasa[10];
    cout<<endl;
    tab1();
    cout<<"Clasele disponibile sunt:"<<endl<<endl;
    for(int i=0; i<5; i++)
    {
        tab1();
        cout<<c[i].nume<<endl;
    }

    cout<<endl;
    tab1();
    cout<<"Introduceti clasa despre care vreti sa aflati informatii despre membri: ";
    cin>>clasa;
    cout<<endl;
    for(i=0; i<n; i++)
        if(strstr(m[i].tabel_clase, clasa)!=NULL)
        {
            ok=1;
            tab1();
            cout<<m[i].nume<<" "<<m[i].prenume<<endl;
            tab1();
            cout<<"Date de contact: "<<m[i].nrtel<<endl;
            cout<<endl;
            }
    if(ok==0)
    {
       tab1();
        cout<<"Nu exista clasa introdusa.";
    }
    cout<<endl<<endl;
    tab1();
    cout<<"Apasati 0 pentru a reveni la meniu ";
}

void clasa_cost()
{
    int ok=0, j;
    char clasa[20];
    cout<<endl;
    tab1();
    cout<<"Clase disponibile: ";
    cout<<endl<<endl;
    for(int i=0;i<5;i++)
    {
        tab1();
        cout<<c[i].nume<<endl;
    }
    cout<<endl;
    tab1();
    cout<<"Introduce clasa: ";
    cin>>clasa;
    cout<<endl;
    for(int i=0;i<5;i++)
    {
            if(stricmp(clasa,c[i].nume)==0)
            {
                tab1();
                cout<<"Pretul este: "<<c[i].pret<<" lei/sedinta"<<endl;
                ok=1;
            }
    }
    if(ok==0)
    {
        tab1();
        cout<<"Nu exista clasa."<<endl;
    }
    cout<<endl<<endl;
    tab1();
    cout<<"Apasati 0 pentru a reveni la meniu ";

}

void c_dificult(int n)
{
       int i, ok=0, j;
       char nivel[20];
       cout<<endl<<endl;
       tab1();
       cout<<"Alegeti un nivel de dificultate: usor, mediu, dificil"<<endl<<endl;
       tab1();
       cout<<"Introduceti nivelul: ";
       cin>>nivel;
       cout<<endl;
       for(i=0; i<n; i++)
       {
           if(stricmp(nivel, c[i].dificultate)==0)
           {
               tab1();
               cout<<c[i].nume<<endl;
                ok=1;
           }
       }
       if(ok==0)
       {
           tab1();
           cout<<"Nu este nicio clasa disponibila cu acest nivel";
       }
       cout<<endl<<endl;
    tab1();
    cout<<"Apasati 0 pentru a reveni la meniu ";
}

void elim_m(int &nrm)
{
    char nume[30],prenume[30];
    int i,j,ok=0;
    cout<<endl<<endl;
    tab1();
    cout<<"Membrii nostri sunt:"<<endl<<endl;
    for(i=0;i<nrm;i++)
    {
        tab1();
        cout<<m[i].nume<<" "<<m[i].prenume<<endl;
    }
    cout<<endl;
    tab1();
    cout<<"Introdu numele si prenumele membrului pe care vrei sa il elimini: ";
    cin>>nume>>prenume;
    for(i=0;i<nrm && ok==0;i++)
        if(stricmp(nume,m[i].nume)==0 && stricmp(prenume,m[i].prenume)==0)ok=1;
    if(ok==0)
    {
        cout<<endl;
        tab1();
        cout<<"Membrul nu exista."<<endl;
    }
    else
     {
      for(j=i-1;j<nrm-1;j++)
       {
           strcpy(m[j].nume,m[j+1].nume);
           strcpy(m[j].prenume,m[j+1].prenume);
           strcpy(m[j].nrtel,m[j+1].nrtel);
           strcpy(m[j].tabel_clase,m[j+1].tabel_clase);
       }
       nrm--;
       cout<<endl;
       tab1();
       cout<<"Membrul a fost eliminat cu succes."<<endl;
     }
     cout<<endl<<endl;
    tab1();
    cout<<"Apasati 0 pentru a reveni la meniu ";
}

void elim_a(int &nra)
{
    char nume[30],prenume[30];
    int i,j,ok=0;
    cout<<endl<<endl;
    tab1();
    cout<<"Angajatii nostri sunt:"<<endl<<endl;
    for(i=0;i<nra;i++)
    {
        tab1();
        cout<<a[i].nume<<" "<<a[i].prenume<<endl;
    }
    cout<<endl;
    tab1();
    cout<<"Introdu numele si prenumele angajatului pe care vrei sa il elimini: ";
    cin>>nume>>prenume;
    for(i=0;i<nra && ok==0;i++)
        if(stricmp(nume,a[i].nume)==0 && stricmp(prenume,a[i].prenume)==0)ok=1;
    if(ok==0)
    {
        cout<<endl;
        tab1();
        cout<<"Angajatul nu exista."<<endl;
    }
    else
     {
      for(j=i-1;j<nra-1;j++)
       {
           strcpy(a[j].nume,a[j+1].nume);
           strcpy(a[j].prenume,a[j+1].prenume);
           strcpy(a[j].nr_telefon,a[j+1].nr_telefon);
           strcpy(a[j].post,a[j+1].post);
           a[j].salariu=a[j+1].salariu;
       }
       nra--;
       cout<<endl;
        tab1();
       cout<<"Angajatul a fost eliminat cu succes."<<endl;
     }
     cout<<endl<<endl;
    tab1();
    cout<<"Apasati 0 pentru a reveni la meniu ";
  }

void cautare_a(int &nra)
 { int i,ok=0, j;
   char nume[30],prenume[30],nrtel[11];
   cout<<endl;
   tab1();
   cout<<"Introdu numele si prenumele: "<<endl;
   cin>>nume>>prenume;
   cout<<endl;
   tab1();
   cout<<"Introdu numarul de telefon: "<<endl;
   cin>>nrtel;
   cout<<endl;
   for(i=0;i<nra && ok==0;i++)
   {
       if(stricmp(nume,a[i].nume)==0 && stricmp(prenume,a[i].prenume)==0 && stricmp(nrtel,a[i].nr_telefon)==0)
       {
           ok=1;
           cout<<endl;
           tab1();
           cout<<"Angajatul a fost gasit cu succes."<<endl;
           cout<<endl;
           tab1();
           cout<<a[i].nume<<" "<<a[i].prenume<<" este "<<a[i].post<<"."<<endl;
           cout<<endl;
           tab1();
           cout<<"Date de contact: "<<a[i].nr_telefon;
       }
   }
   if(ok==0)
   {
       cout<<endl;
       tab1();
       cout<<"Angajatul nu a fost gasit.";
   }
   cout<<endl<<endl;
    tab1();
    cout<<"Apasati 0 pentru a reveni la meniu ";
 }

 void cautare_m(int &nrm)
 { int i,ok=0, j;
   char nume[30],prenume[30],nrtel[11];
   cout<<endl;
   tab1();
   cout<<"Introdu numele si prenumele: ";
   cin>>nume>>prenume;
   cout<<endl;
   tab1();
   cout<<"Introdu numarul de telefon: ";
   cin>>nrtel;
   cout<<endl;
   for(i=0;i<nrm && ok==0;i++)
   {
       if(stricmp(nume,m[i].nume)==0 && stricmp(prenume,m[i].prenume)==0 && stricmp(nrtel,m[i].nrtel)==0)
       {
           ok=1;
           cout<<endl;
           tab1();
           cout<<"Membrul a fost gasit cu succes."<<endl;
           cout<<endl;
           tab1();
           cout<<m[i].nume<<" "<<m[i].prenume<<" participa la: "<<m[i].tabel_clase<<"."<<endl;
           cout<<endl;
           tab1();
           cout<<"Date de contact: "<<m[i].nrtel;
       }
   }
   if(ok==0)
   {
       cout<<endl;
       tab1();
       cout<<"Membrul nu a fost gasit.";
   }
   cout<<endl<<endl;
    tab1();
    cout<<"Apasati 0 pentru a reveni la meniu ";
 }

 void sort_sal(int n)
 {
     int i, j, var;
     char aux[100];
     for(i=0; i<n-1; i++)
     {
         for(j=i+1; j<n; j++)
         {
             if(a[i].salariu>a[j].salariu)
             {
                 strcpy(aux, a[i].nume);
                 strcpy(a[i].nume, a[j].nume);
                 strcpy(a[j].nume, aux);
                 strcpy(aux, a[i].prenume);
                 strcpy(a[i].prenume, a[j].prenume);
                 strcpy(a[j].prenume, aux);
                 strcpy(aux, a[i].nr_telefon);
                 strcpy(a[i].nr_telefon, a[j].nr_telefon);
                 strcpy(a[j].nr_telefon, aux);
                 strcpy(aux, a[i].post);
                 strcpy(a[i].post, a[j].post);
                 strcpy(a[j].post, aux);
                 var=a[i].salariu;
                 a[i].salariu=a[j].salariu;
                 a[j].salariu=var;
             }
         }
     }
     for(i=0; i<n; i++)
     {
        cout<<endl;
        tab1();
        cout<<a[i].nume<<" "<<a[i].prenume<<" "<<a[i].nr_telefon<<" "<<a[i].post<<" "<<a[i].salariu<<"lei"<<endl;
     }
   cout<<endl<<endl;
    tab1();
    cout<<"Apasati 0 pentru a reveni la meniu ";
 }

 void crono_clas(int n)
 {
     int i, j,var;
     char aux[100];
     for(i=0; i<n-1; i++)
     {
         for(j=i+1; j<n; j++)
         { if(strncmp(c[i].ora,c[j].ora,2)>0)

             {
                 strcpy(aux, c[i].nume);
                 strcpy(c[i].nume, c[j].nume);
                 strcpy(c[j].nume, aux);
                 strcpy(aux, c[i].dificultate);
                 strcpy(c[i].dificultate, c[j].dificultate);
                 strcpy(c[j].dificultate, aux);
                 strcpy(aux, c[i].echipament);
                 strcpy(c[i].echipament, c[j].echipament);
                 strcpy(c[j].echipament, aux);
                 strcpy(aux, c[i].ora);
                 strcpy(c[i].ora, c[j].ora);
                 strcpy(c[j].ora, aux);
                 var=c[i].pret;
                 c[i].pret=c[j].pret;
                 c[j].pret=var;
             }
         }
     }
     for(i=0; i<n; i++)
     {
        cout<<endl;
       tab1();
        cout<<c[i].nume<<" ("<<c[i].dificultate<<")"<<endl;
        tab1();
        cout<<"Intre orele: "<<c[i].ora<<", "<<c[i].pret<<" lei/sedinta"<<endl;
        tab1();
        cout<<"Echipament necesar: "<<c[i].echipament<<endl;
     }
   cout<<endl<<endl;
    tab1();
    cout<<"Apasati 0 pentru a reveni la meniu ";
 }

 void intro_a(int &nra)
 {   int i,ok,gresit=0, j;
     cout<<endl;
    tab1();
     cout<<"Introdu un nou angajat in baza de date"<<endl;
     char nume[30],prenume[30],nrtel[11],post[20];
     int sal;
     cout<<endl;
     tab1();
     cout<<"Introdu numele: ";
     do{
         if(gresit==1)
         {
             cout<<endl;
             tab1();
             cout<<"Invalid! Introdu din nou: ";
         }
         ok=1;gresit=0;
         cin>>nume;
         for(i=0;i<strlen(nume) && ok==1;i++)
         {
            if((nume[i]>'z' || nume[i]<'a') && (nume[i]>'Z' || nume[i]<'A'))
            {ok=0; gresit=1;}
         }
      }while(ok==0);
      cout<<endl;
    gresit=0;
    cout<<endl;
    tab1();
    cout<<"Introdu prenumele:";
    do{
         if(gresit==1)
         {
             cout<<endl;
            tab1();
             cout<<"Invalid! Introdu din nou: ";
         }
         ok=1;gresit=0;
         cin>>prenume;
         for(i=0;i<strlen(prenume) && ok==1;i++)
         {
            if((prenume[i]>'z' || prenume[i]<'a') && (prenume[i]>'Z' || prenume[i]<'A'))
            {ok=0;gresit=1;}
         }
      }while(ok==0);
      cout<<endl;

    gresit=0;
    cout<<endl;
    tab1();
    cout<<"Introdu numarul de telefon: ";
    do{
         if(gresit==1)
         {
             cout<<endl;
               tab1();
             cout<<"Invalid! Introdu din nou: ";
         }
         ok=1;gresit=0;
         cin>>nrtel;
         if(strchr(nrtel,'0')!=nrtel || strlen(nrtel)!=10)
         {ok=0; gresit=1;}
         for(i=1;i<strlen(nrtel) && ok==1;i++)
         {
            if(nrtel[i]<'0' || nrtel[i]>'9')
            {ok=0;gresit=1;}
         }
      }while(ok==0);
      cout<<endl;
       gresit=0;
       cout<<endl;
       tab1();
    cout<<"Introdu postul: ";
    do{
         if(gresit==1)
         {
             cout<<endl;
             tab1();
             cout<<"Invalid! Introdu din nou: ";
         }
         ok=1;gresit=0;
         cin>>post;
         for(i=0;i<strlen(post) && ok==1;i++)
         {
            if((post[i]>'z' || post[i]<'a') && (post[i]>'Z' || post[i]<'A'))
            {ok=0;gresit=1;}
         }
         }
      while(ok==0);
      cout<<endl;
    cout<<endl;
   tab1();
    cout<<"Introdu salariul(suma):";
    cin>>sal;
    cout<<endl;
    strcpy(a[nra].nume,nume);
    strcpy(a[nra].prenume,prenume);
    strcpy(a[nra].nr_telefon,nrtel);
    strcpy(a[nra].post,post);
    a[nra].salariu=sal;
    nra++;
    cout<<endl;
   tab1();
    cout<<"Angajatul a fost adaugat cu succes."<<endl;
    cout<<endl;
   tab1();
    cout<<"Apasati 0 pentru a reveni la meniu ";
 }


void intro_m(int &nrm)
 {   int i,ok,gresit=0, j;
     cout<<endl;
     tab1();
     cout<<"Introdu un nou membru in baza de date"<<endl;
     char nume[30],prenume[30],nrtel[11],clase[30];
     cout<<endl;
     tab1();
     cout<<"Introdu numele: ";
     do{
         if(gresit==1)
         {
             cout<<endl;
             tab1();
             cout<<"Invalid! Introdu din nou: ";
         }
         ok=1;gresit=0;
         cin>>nume;
         for(i=0;i<strlen(nume) && ok==1;i++)
         {
            if((nume[i]>'z' || nume[i]<'a') && (nume[i]>'Z' || nume[i]<'A'))
            {ok=0; gresit=1;}
         }
      }while(ok==0);
      cout<<endl;
    gresit=0;
    cout<<endl;
    tab1();
    cout<<"Introdu prenumele:";
    do{
         if(gresit==1)
         {
             cout<<endl;
            tab1();
             cout<<"Invalid! Introdu din nou: ";
         }
         ok=1;gresit=0;
         cin>>prenume;
         for(i=0;i<strlen(prenume) && ok==1;i++)
         {
            if((prenume[i]>'z' || prenume[i]<'a') && (prenume[i]>'Z' || prenume[i]<'A'))
            {ok=0;gresit=1;}
         }
      }while(ok==0);
      cout<<endl;

    gresit=0;
    cout<<endl;
    tab1();
    cout<<"Introdu numarul de telefon: ";
    do{
         if(gresit==1)
         {
             cout<<endl;
              tab1();
             cout<<"Invalid! Introdu din nou: ";
         }
         ok=1;gresit=0;
         cin>>nrtel;
         if(strchr(nrtel,'0')!=nrtel || strlen(nrtel)!=10)
          {ok=0; gresit=1;}
         for(i=1;i<strlen(nrtel) && ok==1;i++)
         {
            if(nrtel[i]<'0' || nrtel[i]>'9')
            {ok=0;gresit=1;}
         }
      }while(ok==0);
      cout<<endl;
       gresit=0;
       cout<<endl;
       tab1();
    cout<<"Introdu clasele la care este inscris(fara spatii intre virgula): ";
    do{  cin.get();
         if(gresit==1)
         {
             cout<<endl;
             tab1();
             cout<<"Invalid! Introdu din nou: ";
         }
         ok=1;gresit=0;
         cin.get(clase,30);
         for(i=0;i<strlen(clase) && ok==1;i++)
         {
            if((clase[i]>'z' || clase[i]<'a') && (clase[i]>'Z' || clase[i]<'A'))
                if(clase[i]!=',')
                 {ok=0;gresit=1;}
         }
         }
      while(ok==0);
      cout<<endl;
    strcpy(m[nrm].nume,nume);
    strcpy(m[nrm].prenume,prenume);
    strcpy(m[nrm].nrtel,nrtel);
    strcpy(m[nrm].tabel_clase,clase);
    nrm++;
    cout<<endl;
   tab1();
    cout<<"Membrul a fost adaugat cu succes."<<endl;
    cout<<endl;
   tab1();
    cout<<"Apasati 0 pentru a reveni la meniu ";
 }

int main()
{  system("Color 75");
    int tasta, nra, nrm, nrc, nrl, i, ok=1;
   angajati(nra);
   citire_clase(nrc);
   locatii(nrl);
   membrii(nrm);
      do
{
    while(ok==1)
    {
    system("CLS");
      for(i=0; i<9; i++)
        cout<<endl;
      centrare();
      cout<<"Bun venit la sala de fitness FitZone!"<<endl;
      tab();
      cout<<"Functii angajat(1)"<<endl;
      tab();
      cout<<"Functii membru(2)"<<endl;
      tab();
      cout<<"Clase(3)"<<endl;
      tab();
      cout<<"Locatii(4)"<<endl;
      tab();
      cout<<"EXIT(0)";
      cout<<endl<<endl;
      centrare();
      cout<<"Introduceti numarul corespunzator comenzii dorite:  ";
      cin>>tasta;
      switch(tasta)
      {
          //system("CLS")
          case 1:{
                do{
                    system("CLS");
                    system("Color 75");
                    cout<<endl<<endl<<endl;
                    tab1();
                    cout<<"Alege operatia"<<endl<<endl;
                    tab1();
                    cout<<"Afiseaza salariul angajatului cu numele introdus(1)"<<endl<<endl;
                    tab1();
                    cout<<"Sa se elimine un angajat introdus(2)"<<endl<<endl;
                    tab1();
                    cout<<"Afiseaza toti membrii(3)"<<endl<<endl;
                    tab1();
                    cout<<"Afiseaza informatii despre membrii care participa la o anumita clasa(4)"<<endl<<endl;
                    tab1();
                    cout<<"Sa se elimine un membru introdus(5)"<<endl<<endl;
                    tab1();
                    cout<<"Introducere angajat nou(6)"<<endl<<endl;
                    tab1();
                    cout<<"Sa se afiseze angajatii in functie de salariul cel mai mic(7)"<<endl<<endl;
                    tab1();
                    cout<<"Cautare angajat(8)"<<endl<<endl;
                    tab1();
                    cout<<"Cautare membru(9)"<<endl<<endl;
                    tab1();
                    cout<<"EXIT(0)"<<endl<<endl;
                    tab1();
                    cout<<"Introduceti numarul corespunzator comenzii dorite:";
                    cin>>tasta;
                    switch(tasta)
                    {
                        case 1:{sal_ang(nra); getche(); break;}
                        case 2:{elim_a(nra);  getche(); break;}
                        case 3:{a_mem(nrm); getche(); break;}
                        case 4:{info_mem(nrm);  getche(); break;}
                        case 5:{elim_m(nrm);  getche(); break;}
                        case 6:{intro_a(nra);  getche(); break;}
                        case 7:{sort_sal(nra); getche(); break;}
                        case 8:{cautare_a(nra);  getche(); break;}
                        case 9:{cautare_m(nrm);  getche(); break;}
                        cout<<endl;
                    }
                }while(tasta!=0);
                getche(); break;
          }
          case 2:{
                do{
                    system("CLS");
                    system("Color 75");
                    cout<<endl<<endl<<endl;
                    tab1();
                    cout<<"Alege operatia"<<endl<<endl;
                    tab1();
                    cout<<"Afiseaza echipamentul necesar pentru clasa introdusa(1)"<<endl<<endl;
                    tab1();
                    cout<<"Afiseaza informatii despre locatiile disponibile din orasul introdus(2)"<<endl<<endl;
                    tab1();
                    cout<<"Afiseaza toate clasele cu nivelul de dificultate introdus(3)"<<endl<<endl;
                    tab1();
                    cout<<"Afiseaza clasele in ordine cronologica(4)"<<endl<<endl;
                    tab1();
                    cout<<"Afiseaza costul unei anumite clase(5)"<<endl<<endl;
                    tab1();
                    cout<<"Introducere membru nou(6)"<<endl<<endl;
                    tab1();
                    cout<<"EXIT(0)"<<endl<<endl;
                    tab1();
                    cout<<"Introduceti numarul corespunzator comenzii dorite:";
                    cin>>tasta;
                    switch(tasta)
                    {
                        case 1:{a_clase(nrc); echipament(); getche(); break;}
                        case 2:{nr_locatii(nrl); getche(); break;}
                        case 3:{c_dificult(nrc); getche(); break;}
                        case 4:{crono_clas(nrc); getche(); break;}
                        case 5:{clasa_cost(); getche(); break;}
                        case 6:{intro_m(nrm); getche(); break;}
                        cout<<endl;
                    }
                }while(tasta!=0);
                getche(); break;
          }
          case 3:{
                    system("CLS");
                    system("Color 75");
                    do{ system("CLS");
                        cout<<endl<<endl<<endl<<endl;
                        centrare();
                        cout<<"Alege operatia"<<endl<<endl;
                        centrare();
                        cout<<"Afiseaza toate clasele(1)"<<endl<<endl;
                        centrare();
                        cout<<"EXIT(0)"<<endl<<endl;
                        centrare();
                        cout<<"Introduceti numarul corespunzator comenzii dorite: ";
                        cin>>tasta;
                        switch(tasta)
                        {
                            case 1:{ a_clase(nrc); getche(); break;}
                            cout<<endl;
                        }
                    }while(tasta!=0);
                    getche(); break;
          }
          case 4:{
                do{
                    system("CLS");
                    system("Color 75");
                    cout<<endl<<endl<<endl<<endl;
                    centrare();
                    cout<<"Alege operatia"<<endl<<endl;
                    centrare();
                    cout<<"Locatii disponibile(1)"<<endl<<endl;
                    centrare();
                    cout<<"EXIT(0)"<<endl<<endl;
                    centrare();
                    cout<<"Introduceti numarul corespunzator comenzii dorite:  ";
                    cin>>tasta;
                    cout<<endl<<endl;
                    switch(tasta)
                    {
                        case 1:{a_locatii(nrl);getche(); break;}
                        cout<<endl;
                    }
                }while(tasta!=0);
                getche(); break;
          }
          case 5:{ok=0;getche();break;}
      }
      cout<<endl;
    }
}while(tasta!=0);
    return 0;
}
