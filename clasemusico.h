#ifndef CLASEMUSICO_H_INCLUDED
#define CLASEMUSICO_H_INCLUDED

void cargarCadena(char *pal, int tam);



void cargarCadena(char *pal,int tam){

    int i;
    fflush(stdin);
    for(i=0;i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

class Musico
{
private:
    int dni;
    char nombre[30];
    char apellido[30];
    char email[30];
    char telefono[30];
    int claustro;
    int instrumento;
    int tipomusica;
    Fecha fechainscripcion;
    float matricula;
    bool estado;
public:

    int getDni()
    {
        return dni;
    }
    const char* getNombre()
    {
        return nombre;
    }
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
    int getClaustro()
    {
        return claustro;
    }
    int getInstrumento()
    {
        return instrumento;
    }
    int getTipomusica()
    {
        return tipomusica;
    }
    Fecha getFechainscripcion()
    {
        return fechainscripcion;
    }
    float getMatricula()
    {
        return matricula;
    }
    bool getEstado()
    {
        return estado;
    }

    void setDni(const int d)
    {
        dni=d;
    }
    void setNombre(const char *n)
    {
        strcpy(nombre, n);
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
    void setClaustro(int c)
    {
        while (c<1 || c>4)
        {
            cout<<"No es una eleccion valida, ingrese nuevamente: ";
            cin>>c;
        }
        claustro=c;
    }
    void setInstrumento(int i)
    {
        while (i<1 || i>15)
        {
            cout<<"No es una eleccion valida, ingrese nuevamente: ";
            cin>>i;
        }
        instrumento=i;

    }
    void setTipomusica(int t)
    {
        while (t<1 || t>10)
        {
            cout<<"No es una eleccion valida, ingrese nuevamente: ";
            cin>>t;
        }
        tipomusica=t;
    }
    void setFechainscripcion(Fecha f)
    {
        fechainscripcion=f;
    }
    void setMatricula(float m)
    {
        while (m<0)
        {
            cout<<"No es un ingreso valido, ingrese nuevamente el importe: ";
            cin>>m;
        }
        matricula=m;
    }
    void setEstado(const bool e)
    {
        estado=e;
    }

    void Cargar(int d);
    void Mostrar();

};

void Musico::Cargar(int d)
{
    int aux;

    float aux2;
    setDni(d);
    cout<<"Nombre: ";
    cargarCadena(nombre, 29);
    cout<<"Apellido: ";
    cargarCadena(apellido, 29);
    cout<<"Correo electronico: ";
    cargarCadena(email, 29);
    cout<<"Telefono: ";
    cargarCadena(telefono, 29);
    cout<<"Claustro al cual pertenece, del 1 al 4: ";
    cin>>aux;
    setClaustro(aux);
    cout<<"Instrumento principal, del 1 al 15: ";
    cin>>aux;
    setInstrumento(aux);
    cout<<"Tipo de musica, del 1 al 10: ";
    cin>>aux;
    setTipomusica(aux);
    fechainscripcion.Cargar();
    cout<<"Importe de la matricula: ";
    cin>>aux2;
    setMatricula(aux2);
    setEstado(true);
    system("cls");

}



void Musico::Mostrar()
{
    if(estado==true)
    {
        cout<<"DNI: ";
        cout<<getDni()<<endl;
        cout<<"Nombre: ";
        cout<<getNombre()<<endl;
        cout<<"Apellido: ";
        cout<<getApellido()<<endl;
        cout<<"Email: ";
        cout<<getEmail()<<endl;
        cout<<"Telefono: ";
        cout<<getTelefono()<<endl;
        cout<<"Claustro: ";
        cout<<getClaustro()<<endl;
        cout<<"Intrumento: ";
        cout<<getInstrumento()<<endl;
        cout<<"Tipo de musica: ";
        cout<<getTipomusica()<<endl;
        cout<<"Fecha de inscripcion: ";
        fechainscripcion.Mostrar();
        cout<<"Matricula: ";
        cout<<getMatricula()<<endl;
    }
}




#endif // CLASEMUSICO_H_INCLUDED
