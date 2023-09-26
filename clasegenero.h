#ifndef CLASEGENERO_H_INCLUDED
#define CLASEGENERO_H_INCLUDED

void cargarCadena(char *pal, int tam);

int anioActual();

int anioActual()
{
    time_t tiempo_actual = time(NULL);
    struct tm *fecha_actual = localtime(&tiempo_actual);
    return fecha_actual->tm_year + 1900;
}

class Genero
{
private:
    int id;
    char Gnombre[30];
    int pOrigen;
    int aOrigen;
    bool estado;
public:
    int getId()
    {
        return id;
    }
    const char* getGNombre()
    {
        return Gnombre;
    }
    int getPOrigen()
    {
        return pOrigen;
    }
    int getAOrigen()
    {
        return aOrigen;
    }
    bool getEstado()
    {
        return estado;
    }

    void setId(const int i)
    {
        id=i;
    }
    void setGNombre(const char *n)
    {
        strcpy(Gnombre, n);
    }
    void setPOrigen(int p)
    {
        while (p<1 || p>100)
        {
            cout<<"No es una eleccion valida, ingrese nuevamente: ";
            cin>>p;
        }
        pOrigen=p;
    }
    void setAOrigen(int a)
    {
        while (a<1500 || a>anioActual())
        {
            cout<<"No es un año valido, ingrese nuevamente: ";
            cin>>a;
        }
        aOrigen=a;
    }
    void setEstado(const bool e)
    {
        estado=e;
    }

    void Cargar(int id);
    void Mostrar();

};

void Genero::Cargar(int id)
{
    int aux;
    setId(id);
    cout<<"Nombre: ";
    cargarCadena(Gnombre, 29);
    cout<<"País de origen, del 1 al 100: ";
    cin>>aux;
    setPOrigen(aux);
    cout<<"Año de origen, entre 1500 y la actualidad: ";
    cin>>aux;
    setAOrigen(aux);
    setEstado(true);
    system("cls");

}

void Genero::Mostrar()
{
    if(estado==true)
    {
        cout<<"ID del género musical: ";
        cout<<getId()<<endl;
        cout<<"Nombre del género musical: ";
        cout<<getGNombre()<<endl;
        cout<<"País de origen: ";
        cout<<getPOrigen()<<endl;
        cout<<"Año de origen: ";
        cout<<getAOrigen()<<endl;

    }
}


#endif // CLASEGENERO_H_INCLUDED
