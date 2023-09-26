# include<iostream>
# include<cstdlib>
# include<cstring>
# include<ctime>

using namespace std;

#include "locale.h"
#include "rlutil.h"
#include "clasefecha.h"
#include "clasemusico.h"
#include "clasegenero.h"
#include "claseArchivoMusico.h"
#include "claseArchivoGenero.h"
#include "funcionesGlobales.h"
#include "reportes.h"
#include "menus.h"

int main()
{
    setlocale(LC_ALL, "spanish");
    system( "Title Iván Carrieri" );
    rlutil::locate(45,5);
    cout<<"(Usar cursor y enter para selección)";




    menuPrincipal();

    cout<<endl;


    return 0;
}
