#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

class MusicoG
{
private:

    char apellido[30];
    char email[30];
    char telefono[30];

public:
    const char* getApellido()
    {
        return apellido;
    }
    const char* getEmail()
    {
        return email;
    }
    const char* getTelefono()
    {
        return telefono;
    }

    void setApellido(const char *a)
    {
        strcpy(apellido, a);
    }
    void setEmail(const char *e)
    {
        strcpy(email, e);
    }
    void setTelefono(const char *t)
    {
        strcpy(telefono, t);
    }

    void Mostrar();

};

void MusicoG::Mostrar()
{
    cout<<"Apellido: ";
    cout<<getApellido()<<endl;
    cout<<"Email: ";
    cout<<getEmail()<<endl;
    cout<<"Telefono: ";
    cout<<getTelefono()<<endl;

}


void menuReportes();

void listarMusicosNoPiano();

void anioOrigenMayorCant();

void musicosGuitarra();


void listarMusicosNoPiano(){

    Musico obj;
    FILE *pM;



    pM=fopen("musicos.dat","rb");
    if(pM==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

    cout<<"Los musicos que no tocan el piano son:"<<endl;

    while(fread(&obj, sizeof (Musico),1,pM)==1){
        if(obj.getInstrumento()!=3){
            cout<<"DNI: " <<obj.getDni()<<endl;
            cout<<"Nombre: " <<obj.getNombre()<<endl;
            cout<<"Apellido: " <<obj.getApellido()<<endl;
            cout<<"telefono: " <<obj.getTelefono()<<endl;
            cout<<endl;

        }
    }
    fclose(pM);

}


void anioOrigenMayorCant(){
    int anioOrigen[100]={};
    Genero obj;
    FILE *pG;
    int i, maximo=0;
    bool hay=false;


    pG=fopen("generos.dat","rb");
    if(pG==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }


    while(fread(&obj, sizeof (Genero),1,pG)==1){
        if(obj.getAOrigen()>=2000){
            hay=true;
            anioOrigen[obj.getAOrigen()-2000]++;
        }

    }

    fclose(pG);

    if(hay==true){

        for(i=0;i<100;i++){
            if(anioOrigen[i]>anioOrigen[maximo]){
            maximo=i;
            }
        }

        cout<<"El año de origen de este siglo, con mas generos musicales es: "<<maximo+2000<<endl;
    }
    else{
        cout<<"No hay generos con año de origen en el presente siglo"<<endl;
    }


}




void musicosGuitarra(){

    Musico obj;
    MusicoG obj2;

    FILE *pM, *pMg;

    pM=fopen("musicos.dat", "rb");
    if(pM==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return ;
    }
    pMg=fopen("instrumentos.dat", "wb");
    if(pMg==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(pM);
        return;
    }

    while(fread(&obj, sizeof (Musico),1,pM)==1){
        if(obj.getInstrumento()==1)
        {
            obj2.setApellido(obj.getApellido());
            obj2.setEmail(obj.getEmail());
            obj2.setTelefono(obj.getEmail());
            fwrite(&obj2, sizeof (MusicoG), 1, pMg);
        }
    }

    cout<<"Archivo generado con éxito"<<endl;

    fclose(pM);
    fclose(pMg);


}




void menuReportes(){

system("color 65");
    int opc;
    int y=0;

    rlutil::hidecursor();

    while(true)
    {

        rlutil::locate(53,10);
        cout<<" MENU REPORTES "<<endl;
        rlutil::locate(45,11);
        cout<<" -----------------------------------------------------"<<endl;
        rlutil::locate(45,12);
        cout<<" LISTAR MUSICOS QUE NO TOCAN PIANO "<<endl;
        rlutil::locate(45,13);
        cout<<" AÑO DE ORIGEN EN SIGLO XXI CON MAS GENEROS MUSICALES "<<endl;
        rlutil::locate(45,14);
        cout<<" GENERAR ARCHIVO DE MUSICOS GUITARRA "<<endl;
        rlutil::locate(45,15);
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
            if(y>3)
            {
                y=3;
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
            listarMusicosNoPiano();
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            anioOrigenMayorCant();;
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            musicosGuitarra();
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


#endif // REPORTES_H_INCLUDED
