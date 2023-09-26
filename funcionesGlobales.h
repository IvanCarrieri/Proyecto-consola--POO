#ifndef FUNCIONES3_H_INCLUDED
#define FUNCIONES3_H_INCLUDED

void copiaSeguridadM();

void copiaSeguridadG();

void restaurarArchivoM();

void restaurarArchivoG();

void establecerDatosInicio();

void guitarra();

void copiaSeguridadM(){
    Musico obj;
    FILE *pMusico, *pBackup;

    pMusico=fopen("musicos.dat", "rb");
    if(pMusico==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

    pBackup=fopen("musicos.bkp", "wb");
    if(pBackup==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(pMusico);
        return;
    }

    while(fread(&obj, sizeof (Musico),1,pMusico)==1){
        fwrite(&obj, sizeof (Musico), 1, pBackup);
    }
    fclose(pMusico);
    fclose(pBackup);

    cout<<"Copia de seguridad realizada con éxito"<<endl;
}


void copiaSeguridadG(){
    Genero obj;
    FILE *pGenero, *pBackup;

    pGenero=fopen("generos.dat", "rb");
    if(pGenero==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

    pBackup=fopen("generos.bkp", "wb");
    if(pBackup==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(pGenero);
        return;
    }

    while(fread(&obj, sizeof (Genero),1,pGenero)==1){
        fwrite(&obj, sizeof (Genero), 1, pBackup);
    }
    fclose(pGenero);
    fclose(pBackup);

    cout<<"Copia de seguridad realizada con éxito"<<endl;
}


void restaurarArchivoM(){
    Musico obj;
    FILE *pMusico, *pBackup;

    pBackup=fopen("musicos.bkp", "rb");
    if(pBackup==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

    pMusico=fopen("musicos.dat", "wb");
    if(pMusico==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(pBackup);
        return;
    }

    while(fread(&obj, sizeof (Musico),1,pBackup)==1){
        fwrite(&obj, sizeof (Musico), 1, pMusico);
    }
    fclose(pMusico);
    fclose(pBackup);

    cout<<"Restauración realizada con éxito"<<endl;
}



void restaurarArchivoG(){
    Genero obj;
    FILE *pGenero, *pBackup;

    pBackup=fopen("generos.bkp", "rb");
    if(pBackup==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

    pGenero=fopen("generos.dat", "wb");
    if(pGenero==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(pBackup);
        return;
    }

    while(fread(&obj, sizeof (Genero),1,pBackup)==1){
        fwrite(&obj, sizeof (Genero), 1, pGenero);
    }
    fclose(pGenero);
    fclose(pBackup);

    cout<<"Restauración realizada con éxito"<<endl;
}

void establecerDatosInicio(){

    Musico obj;
    FILE *pMusico, *pMinicio;

    pMinicio=fopen("musicosinicio.dat", "rb");
    if(pMinicio==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

    pMusico=fopen("musicos.dat", "wb");
    if(pMusico==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(pMinicio);
        return;
    }

    while(fread(&obj, sizeof (Musico),1,pMinicio)==1){
        fwrite(&obj, sizeof (Musico), 1, pMusico);
    }
    fclose(pMusico);
    fclose(pMinicio);


    Genero obj2;
    FILE *pGenero, *pGinicio;

    pGinicio=fopen("generosinicio.dat", "rb");
    if(pGinicio==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

    pGenero=fopen("generos.dat", "wb");
    if(pGenero==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(pGinicio);
        return;
    }

    while(fread(&obj2, sizeof (Genero),1,pGinicio)==1){
        fwrite(&obj2, sizeof (Genero), 1, pGenero);
    }
    fclose(pGenero);
    fclose(pGinicio);

    cout<<"Datos de inicio establecidos con éxito"<<endl;

}






#endif // FUNCIONES3_H_INCLUDED
