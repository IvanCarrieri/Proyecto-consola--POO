#ifndef CLASEARCHIVOGENERO_H_INCLUDED
#define CLASEARCHIVOGENERO_H_INCLUDED

class ArchivoGenero{
private:
    char nombre[30];
public:
    ArchivoGenero(const char *n){
        strcpy(nombre, n);
    }

    void agregarRegistrosG();
    int buscarRegistroG(int id);
    Genero leerRegistroG(int pos);
    void listarRegistrosPorID();
    void listarRegistrosG();
    int contarRegistrosG();
    void cambioAnio();
    void sobreEscribirRegistroG(const Genero obj, int pos);
    void bajaLogicaG();

};

void ArchivoGenero::agregarRegistrosG()
{
    Genero obj;
    FILE *pGenero;
    int id;


    pGenero=fopen(nombre,"ab");

    if(pGenero==NULL)
    {
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }
    else
    {
        cout<<"ARCHIVO CREADO"<<endl;
    }
    cout<<"GENEROS"<<endl;
    cout<<"Ingrese los datos solicitados a continuación:"<<endl;

    id=contarRegistrosG();

    obj.Cargar(id+1);

    fwrite(&obj, sizeof (Genero), 1, pGenero);

    fclose(pGenero);
}

int ArchivoGenero::buscarRegistroG(int id)
{
    Genero obj;
    FILE *pGenero;
    int pos=0;
    pGenero=fopen(nombre, "rb");
    if(pGenero==NULL)
    {
        return -2;
    }
    while(fread(&obj, sizeof (Genero),1,pGenero)==1)
    {
        if (obj.getId()==id)
        {
            fclose(pGenero);
            return pos;
        }
        pos++;
    }
    fclose(pGenero);
    return -1;
}

Genero ArchivoGenero::leerRegistroG(int pos)
{
    Genero obj;
    FILE *pGenero;
    int aux;
    if (pos<0)
    {
        obj.setId(-3);
        return obj;
    }
    pGenero=fopen(nombre, "rb");
    if(pGenero==NULL)
    {
        return obj;
    }
    fseek(pGenero, sizeof (Genero) * pos, 0);

    aux=fread(&obj, sizeof (Genero), 1, pGenero);

    fclose(pGenero);
    if(aux==0)
    {
        obj.setId(-1);
    }
    return obj;
}


void ArchivoGenero::listarRegistrosPorID()
{
    Genero obj;
    int ID;
    int pos;
    cout<<"Ingrese el ID del registro a buscar ";
    cin>>ID;

    pos=buscarRegistroG(ID);

    if(pos==-1)
    {
        cout<<"No existe género con ese ID"<<endl;
        return;
    }
    if(pos==-2)
    {
        cout<<"NO SE PUEDE ABRIR EL ARCHIVO"<<endl;
        return;
    }

    obj=leerRegistroG(pos);

    if(obj.getId()>0)
    {
        obj.Mostrar();
    }

    else if(obj.getId()==-3||obj.getId()==-1)
    {
        cout<<"ID no encontrado"<<endl;

    }
}

void ArchivoGenero::listarRegistrosG()
{
    Genero obj;
    FILE *pGenero;
    int cantRegistros;

    cantRegistros=contarRegistrosG();

    if(cantRegistros==0)
    {
        cout<<"El archivo no tiene registros"<<endl;

        return;
    }
    else
    {
        if(cantRegistros==-1)
        {
            cout<<"EL ARCHIVO NO EXISTE O NO SE PUDO ABRIR"<<endl;
            return;
        }
        else
        {
            cout<<"Hay "<<cantRegistros<<" registro/s en el archivo"<<endl<<endl;
        }
    }

    pGenero=fopen(nombre,"rb");

    if(pGenero==NULL)
    {
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }
    while(fread(&obj, sizeof(Genero),1,pGenero)==1)
    {
        obj.Mostrar();
        cout<<endl;
    }
    fclose(pGenero);
}


int ArchivoGenero::contarRegistrosG()
{
    int tam;
    int cant;
    FILE *pGenero;

    pGenero=fopen(nombre,"rb");
    if(pGenero==NULL)
    {
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return -1;
    }
    fseek(pGenero,0,2);
    tam=ftell(pGenero);
    fclose(pGenero);
    cant=tam/sizeof(Genero);
    return cant;
}



void ArchivoGenero::cambioAnio()
{
    Genero obj;
    FILE *pGenero;
    int pos;
    int id;
    int anio;

    cout<<"Ingrese el ID a modificar ";
    cin>>id;

    pos=buscarRegistroG(id);
    if(pos==-1)
    {
        cout<<"No existe género con ese ID"<<endl;
        return;
    }
    if(pos==-2)
    {
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return;
    }

    obj=leerRegistroG(pos);

    if(obj.getId()>0)
    {

        pGenero=fopen(nombre,"rb+");
        if(pGenero==NULL)
        {
            cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
            return;
        }
        fseek(pGenero, sizeof(Genero)*pos,0);

        cout<<"Ingrese el año de origen ";
        cin>>anio;

        obj.setAOrigen(anio);

        fwrite(&obj, sizeof(Genero),1,pGenero);

        fclose(pGenero);

        cout<<"Año de origen cambiado con éxito"<<endl;

    }
    else if(obj.getId()==-3||obj.getId()==-1)
    {
        cout<<"ID no encontrado"<<endl;

    }

}

void ArchivoGenero::sobreEscribirRegistroG(const Genero obj, int pos)
{

    FILE *pGenero;
    pGenero=fopen(nombre,"rb+");
    if(pGenero==NULL)
    {
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

    fseek(pGenero, sizeof (Genero) * pos, 0);


    fwrite(&obj,sizeof (Genero),1,pGenero);

    fclose(pGenero);

    cout<<"Baja realizada"<<endl;

}



void ArchivoGenero::bajaLogicaG()
{
    Genero obj;
    int pos;
    int id;

    cout<<"Ingrese el ID a eliminar ";
    cin>>id;

    pos=buscarRegistroG(id);

    if(pos==-1)
    {
        cout<<"No existe género con ese ID"<<endl;
        return;
    }
    if(pos==-2)
    {
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return;
    }

    obj=leerRegistroG(pos);

    if(obj.getEstado()==false)
    {
        cout<<"El genero ya esta dado de baja"<<endl;
        return;
    }

    obj.setEstado(false);

    sobreEscribirRegistroG(obj, pos);




}

#endif // CLASEARCHIVOGENERO_H_INCLUDED
