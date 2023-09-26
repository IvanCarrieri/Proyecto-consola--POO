#ifndef CLASEARCHIVOMUSICO_H_INCLUDED
#define CLASEARCHIVOMUSICO_H_INCLUDED

class ArchivoMusico{
private:
    char nombre[30];
public:
    ArchivoMusico(const char *n){
        strcpy(nombre, n);
    }

    int buscarRegistroM(int dni);
    void agregarRegistrosM();
    Musico leerRegistroM(int pos);
    int contarRegistrosM();
    void listarRegistrosPorDNI();
    void listarRegistrosM();
    void cambioFecha();
    void sobreEscribirRegistroM(const Musico obj, int pos);
    void bajaLogicaM();

};




int ArchivoMusico::buscarRegistroM(int dni){
    Musico obj;
    FILE *pMusico;
    int pos=0;
    pMusico=fopen(nombre, "rb");
    if(pMusico==NULL){
        return -2;
    }
    while(fread(&obj, sizeof (Musico),1,pMusico)==1){
        if (obj.getDni()==dni){
            fclose(pMusico);
            return pos;
        }
        pos++;
    }
    fclose(pMusico);
    return -1;
}




void ArchivoMusico::agregarRegistrosM(){
    Musico obj;
    FILE *pMusico;

    pMusico=fopen(nombre,"ab");

    if(pMusico==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }
    else{
        cout<<"ARCHIVO CREADO"<<endl;
    }
    cout<<"FICHA DE INSCRIPCION"<<endl;
    cout<<"Ingrese los datos solicitados a continuación:"<<endl;
    int dni;
    cout<<"DNI ";
    cin>>dni;
    if (buscarRegistroM(dni)>0){
        cout<<"Ese dni ya existe en el archivo"<<endl;
        return;
    }

    obj.Cargar(dni);

    fwrite(&obj, sizeof (Musico), 1, pMusico);

    fclose(pMusico);
}



Musico ArchivoMusico::leerRegistroM(int pos){
    Musico obj;
    FILE *pMusico;
    if (pos<0){
        obj.setDni(-3);
        return obj;
    }
    pMusico=fopen(nombre, "rb");
    if(pMusico==NULL){
        return obj;
    }
    fseek(pMusico, sizeof (Musico) * pos, 0);
    int aux=fread(&obj, sizeof (Musico), 1, pMusico);
    fclose(pMusico);
    if(aux==0){
        obj.setDni(-1);
    }
    return obj;
}



int ArchivoMusico::contarRegistrosM(){
    int tam;
    int cant;
    FILE *pMusico;

    pMusico=fopen(nombre,"rb");
    if(pMusico==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return -1;
    }
    fseek(pMusico,0,2);
    tam=ftell(pMusico);
    fclose(pMusico);
    cant=tam/sizeof(Musico);
    return cant;

}



void ArchivoMusico::listarRegistrosPorDNI(){
    Musico obj;
    int DNI;
    int pos;
    cout<<"Ingrese el DNI a buscar: ";
    cin>>DNI;

    pos=buscarRegistroM(DNI);
    if(pos==-1){
        cout<<"No existe músico con ese DNI"<<endl;
        return;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return;
    }
    obj=leerRegistroM(pos);
    if(obj.getDni()>0){
        obj.Mostrar();
    }
    else if(obj.getDni()==-3||obj.getDni()==-1){
        cout<<"DNI no encontrado"<<endl;
    }

}



void ArchivoMusico::listarRegistrosM(){

    Musico obj;
    FILE *pMusico;
    int cantRegistros;

    cantRegistros=contarRegistrosM();



    if(cantRegistros==0){
        cout<<"El archivo no tiene registros"<<endl;

        return;
    }
    else{
        if(cantRegistros==-1){
            cout<<"EL ARCHIVO NO EXISTE O NO SE PUDO ABRIR"<<endl;
            return;
        }
        else{
            cout<<"Hay "<<cantRegistros<<" registro/s en el archivo"<<endl<<endl;
        }
    }

    pMusico=fopen(nombre,"rb");
    if(pMusico==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

    while(fread(&obj, sizeof (Musico),1,pMusico)==1){
        obj.Mostrar();
        cout<<endl;
    }
    fclose(pMusico);

}




void ArchivoMusico::cambioFecha(){
    Musico obj;
    Fecha obj2;
    int DNI;
    int pos;
    cout<<"Ingrese el DNI de musico: ";
    cin>>DNI;

    pos=buscarRegistroM(DNI);
    if(pos==-1){
        cout<<"No existe músico con ese DNI"<<endl;
        return;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return;
    }
    obj=leerRegistroM(pos);


    if(obj.getDni()>0){
        FILE *pMusico;

        pMusico=fopen(nombre,"rb+");

        if(pMusico==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
        }

        fseek(pMusico, sizeof obj * pos, 0);

        obj2.Cargar();
        obj.setFechainscripcion(obj2);

        fwrite(&obj,sizeof (Musico),1,pMusico);

        fclose(pMusico);
        cout<<"Fecha de inscripcion cambiada con exito"<<endl;
    }
    else if(obj.getDni()==-3||obj.getDni()==-1){
        cout<<"DNI no encontrado"<<endl;
    }
}




void ArchivoMusico::sobreEscribirRegistroM(const Musico obj, int pos){
    FILE *pMusico;
    pMusico=fopen(nombre,"rb+");
    if(pMusico==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

    fseek(pMusico, sizeof (Musico) * pos, 0);


    fwrite(&obj,sizeof (Musico),1,pMusico);

    fclose(pMusico);

    cout<<"Baja realizada"<<endl;

}



void ArchivoMusico::bajaLogicaM(){
    Musico obj;
    int DNI;
    int pos;
    cout<<"Ingrese el DNI del musico a borrar: ";
    cin>>DNI;

    pos=buscarRegistroM(DNI);
    if(pos==-1){
        cout<<"No existe musico con ese DNI"<<endl;
        return;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return;
    }

    obj=leerRegistroM(pos);
    if(obj.getEstado()==false){
        cout<<"EL musico ya esta dado de baja"<<endl;
        return;
    }

    obj.setEstado(false);

    sobreEscribirRegistroM(obj, pos);
}



#endif // CLASEARCHIVOMUSICO_H_INCLUDED
