#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED




void menuPrincipal();

void menuMusicos();

void menuGeneros();

void menuReportes();

void menuConfiguracion();

void menuPrincipal(){

system("color 65");
    int opc;
    int y=0;

    rlutil::hidecursor();

    while(true)
    {

        rlutil::locate(53,10);
        cout<<" MENU PRINCIPAL "<<endl;
        rlutil::locate(45,11);
        cout<<" ------------------------------"<<endl;
        rlutil::locate(53,12);
        cout<<" MENU MUSICOS "<<endl;
        rlutil::locate(53,13);
        cout<<" MENU GENEROS "<<endl;
        rlutil::locate(53,14);
        cout<<" REPORTES "<<endl;
        rlutil::locate(53,15);
        cout<<" CONFIGURACION "<<endl;
        rlutil::locate(53,16);
        cout<<" FIN DEL PROGRAMA "<<endl;

        rlutil::locate(50,12+y);
        cout<<(char)272<<endl;


        switch(rlutil::getkey())
        {
        case 14:
            rlutil::locate(50,12+y);
            cout<<" "<<endl;
            y--;
            if(y<0)
            {
                y=0;
            }
            break;
        case 15:
            rlutil::locate(50,12+y);
            cout<<" "<<endl;
            y++;
            if(y>4)
            {
                y=4;
            }
            break;
        case 1:
            switch(y)
            {
            case 0:
                opc=1;
                break;
            case 1:
                opc=2;
                break;
            case 2:
                opc=3;
                break;
            case 3:
                opc=4;
                break;
            case 4:
                opc=0;
                break;

            default:
                break;
            }
            break;
        default:
            break;
        }


        switch(opc)
        {

        case 1:
            system("cls");
            menuMusicos();
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            menuGeneros();
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            menuReportes();
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            menuConfiguracion();
            system("pause");
            system("cls");
            break;
        case 0:
            return;
            break;

        }
        opc=-1;
    }

}



void menuMusicos(){

system("color 65");
    int opc;
    int y=0;

    rlutil::hidecursor();
    ArchivoMusico objMusico("musicos.dat");

    while(true)
    {

        rlutil::locate(53,10);
        cout<<" MUSICOS "<<endl;
        rlutil::locate(45,11);
        cout<<" ------------------------------"<<endl;
        rlutil::locate(45,12);
        cout<<" AGREGAR MUSICOS "<<endl;
        rlutil::locate(45,13);
        cout<<" LISTAR MUSICO POR DNI "<<endl;
        rlutil::locate(45,14);
        cout<<" LISTAR TODOS LOS MUSICOS "<<endl;
        rlutil::locate(45,15);
        cout<<" MODIFICAR FECHA DE INSCRIPCION "<<endl;
        rlutil::locate(45,16);
        cout<<" ELIMINAR REGISTRO DE MUSICO "<<endl;
        rlutil::locate(45,17);
        cout<<" VOLVER AL MENU PRINCIPAL "<<endl;
        rlutil::locate(43,12+y);
        cout<<(char)272<<endl;


        switch(rlutil::getkey())
        {
        case 14:
            rlutil::locate(43,12+y);
            cout<<" "<<endl;
            y--;
            if(y<0)
            {
                y=0;
            }
            break;
        case 15:
            rlutil::locate(43,12+y);
            cout<<" "<<endl;
            y++;
            if(y>5)
            {
                y=5;
            }
            break;
        case 1:
            switch(y)
            {
            case 0:
                opc=1;
                break;
            case 1:
                opc=2;
                break;
            case 2:
                opc=3;
                break;
            case 3:
                opc=4;
                break;
            case 4:
                opc=5;
                break;
            case 5:
                opc=0;
                break;

            default:
                break;
            }
            break;
        default:
            break;
        }


        switch(opc)
        {

        case 1:
            system("cls");
            objMusico.agregarRegistrosM();
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            objMusico.listarRegistrosPorDNI();
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            objMusico.listarRegistrosM();
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            objMusico.cambioFecha();
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            objMusico.bajaLogicaM();
            system("pause");
            system("cls");
            break;
        case 0:
            return;
            break;

        }
        opc=-1;
    }


}

void menuGeneros(){

system("color 65");
    int opc;
    int y=0;

    rlutil::hidecursor();
    ArchivoGenero objGenero("generos.dat");

    while(true)
    {

        rlutil::locate(53,10);
        cout<<" GENEROS "<<endl;
        rlutil::locate(45,11);
        cout<<" ------------------------------"<<endl;
        rlutil::locate(45,12);
        cout<<" AGREGAR GENERO "<<endl;
        rlutil::locate(45,13);
        cout<<" LISTAR GENERO POR ID "<<endl;
        rlutil::locate(45,14);
        cout<<" LISTAR TODOS LOS GENEROS "<<endl;
        rlutil::locate(45,15);
        cout<<" MODIFICAR AÑO DE ORIGEN "<<endl;
        rlutil::locate(45,16);
        cout<<" ELIMINAR REGISTRO DE GENERO "<<endl;
        rlutil::locate(45,17);
        cout<<" VOLVER AL MENU PRINCIPAL "<<endl;
        rlutil::locate(43,12+y);
        cout<<(char)272<<endl;


        switch(rlutil::getkey())
        {
        case 14:
            rlutil::locate(43,12+y);
            cout<<" "<<endl;
            y--;
            if(y<0)
            {
                y=0;
            }
            break;
        case 15:
            rlutil::locate(43,12+y);
            cout<<" "<<endl;
            y++;
            if(y>5)
            {
                y=5;
            }
            break;
        case 1:
            switch(y)
            {
            case 0:
                opc=1;
                break;
            case 1:
                opc=2;
                break;
            case 2:
                opc=3;
                break;
            case 3:
                opc=4;
                break;
            case 4:
                opc=5;
                break;
            case 5:
                opc=0;
                break;

            default:
                break;
            }
            break;
        default:
            break;
        }


        switch(opc)
        {

        case 1:
            system("cls");
            objGenero.agregarRegistrosG();
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            objGenero.listarRegistrosPorID();
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            objGenero.listarRegistrosG();
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            objGenero.cambioAnio();
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            objGenero.bajaLogicaG();
            system("pause");
            system("cls");
            break;
        case 0:
            return;
            break;

        }
        opc=-1;
    }


}

void menuConfiguracion(){

system("color 65");
    int opc;
    int y=0;

    rlutil::hidecursor();

    while(true)
    {

        rlutil::locate(53,10);
        cout<<" MENU CONFIGURACION "<<endl;
        rlutil::locate(45,11);
        cout<<" ------------------------------------------"<<endl;
        rlutil::locate(45,12);
        cout<<" COPIA DE SEGURIDAD DEL ARCHIVO DE MUSICOS "<<endl;
        rlutil::locate(45,13);
        cout<<" COPIA DE SEGURIDAD DEL ARCHIVO DE GENEROS "<<endl;
        rlutil::locate(45,14);
        cout<<" RESTAURAR EL ARCHIVO DE MUSICOS "<<endl;
        rlutil::locate(45,15);
        cout<<" RESTAURAR EL ARCHIVO DE GENEROS "<<endl;
        rlutil::locate(45,16);
        cout<<" ESTABLECER DATOS DE INICIO "<<endl;
        rlutil::locate(45,17);
        cout<<" VOLVER AL MENU PRINCIPAL "<<endl;
        rlutil::locate(43,12+y);
        cout<<(char)272<<endl;


        switch(rlutil::getkey())
        {
        case 14:
            rlutil::locate(43,12+y);
            cout<<" "<<endl;
            y--;
            if(y<0)
            {
                y=0;
            }
            break;
        case 15:
            rlutil::locate(43,12+y);
            cout<<" "<<endl;
            y++;
            if(y>5)
            {
                y=5;
            }
            break;
        case 1:
            switch(y)
            {
            case 0:
                opc=1;
                break;
            case 1:
                opc=2;
                break;
            case 2:
                opc=3;
                break;
            case 3:
                opc=4;
                break;
            case 4:
                opc=5;
                break;
            case 5:
                opc=0;
                break;

            default:
                break;
            }
            break;
        default:
            break;
        }


        switch(opc)
        {

        case 1:
            system("cls");
            copiaSeguridadM();
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            copiaSeguridadG();
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            restaurarArchivoM();
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            restaurarArchivoG();
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            establecerDatosInicio();
            system("pause");
            system("cls");
            break;
        case 0:
            return;
            break;

        }
        opc=-1;
    }


}


#endif // MENUS_H_INCLUDED
