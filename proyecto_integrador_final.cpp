// ASERET S25018140
#include <string>
#include <iostream>
#include <limits>

using namespace std;

int contadorP = 0; 
int tamanoP = 100; 

struct Producto {
    string nombre;
    float precio;
    int cantidad;
};

Producto productoLista[100] = {}; 

//-------------------------------------------------------------------------------------
// 1. Registrar productos
//-------------------------------------------------------------------------------------
void registrarP() {

    int cantidadP = 0;

    cout << "Escribe la cantidad de productos a registrar: ";

    while (!(cin >> cantidadP) || cantidadP <= 0 || cantidadP > 100) {
        cout << "Entrada invalida. Debe ser un numero entre 1 y 100: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int i = 0; i < cantidadP; i++) {
        cout << endl;
        cout << "Producto[" << contadorP + 1 << "]" << endl;

        cout << "Nombre: ";
        cin >> productoLista[contadorP].nombre;

        cout << "Precio: ";
        while (!(cin >> productoLista[contadorP].precio)) {
            cout << "Precio invalido. Debe ser un numero.\nIngrese nuevamente: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Cantidad: ";
        while (!(cin >> productoLista[contadorP].cantidad)) {
            cout << "Cantidad invalida. Debe ser un numero.\nIngrese nuevamente: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        contadorP++; 
    }

    cout << "Los productos han sido registrados exitosamente :)" << endl;
}

//-------------------------------------------------------------------------------------
// 2. Mostrar productos
//-------------------------------------------------------------------------------------
void mostrarP() {
    if (contadorP == 0) {
        cout << "No hay productos registrados..." << endl;
        return;
    }

    cout << "===== LISTA DE PRODUCTOS =====" << endl;
    cout << "Nombre\tPrecio\tCantidad" << endl;
    cout << "------------------------" << endl;

    for(int i = 0; i < contadorP; i++) { 
        cout << productoLista[i].nombre << "\t" << productoLista[i].precio << "\t" << productoLista[i].cantidad << endl;
    }
    cout << endl;
}

//-------------------------------------------------------------------------------------
// 3. Ordenar productos por precio.
// 3.1. Ordenado por BURBUJA.
//-------------------------------------------------------------------------------------
void ordenarPBurbuja() { 
    if (contadorP == 0) {
        cout << "No hay productos para ordenar." << endl;
        return;
    }

    int i, j;
    Producto temp;
    Producto arr[100] = {};

    for(i = 0; i < contadorP; i++) { 
        arr[i] = productoLista[i];
    }

    for(i = 0; i < contadorP - 1; i++) { 
        for(j = 0; j < contadorP - i - 1; j++) { 
            if(arr[j].precio > arr[j + 1].precio) { 
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << endl;
    cout << "===== Precio de productos ordenado por burbuja =====" << endl;

    for(int i = 0; i < contadorP; i++) { 
        cout << "Nombre del producto: " << arr[i].nombre << endl;
        cout << "Precio: " << arr[i].precio << endl;
        cout << "Cantidad: " << arr[i].cantidad << endl;
    }  
}

//-------------------------------------------------------------------------------------
// 3.2. Ordenado por SELECCION.
//-------------------------------------------------------------------------------------
void ordenarPSeleccion() { 

    for(int i = 0; i < contadorP - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < contadorP; j++) {
            if(productoLista[j].precio < productoLista[minIndex].precio){
                minIndex = j;
            }
        }
        if(minIndex != i) {
            Producto temp = productoLista[i];
            productoLista[i] = productoLista[minIndex];
            productoLista[minIndex] = temp;
        }
    }

    cout << endl;
    cout << "===== Precio de productos ordenado por seleccion =====" << endl;

    for(int i = 0; i < contadorP; i++) { 
        cout << "Nombre del producto: " << productoLista[i].nombre << endl;
        cout << "Precio: " << productoLista[i].precio << endl;
        cout << "Cantidad: " << productoLista[i].cantidad << endl;
    }        
}

//-------------------------------------------------------------------------------------
// 3.3. Ordenado por INSERCIÓN.
//-------------------------------------------------------------------------------------
void ordenarPInsercion() {
    for(int i = 1; i < contadorP; i++){
        Producto key = productoLista[i];
        int j = i - 1;
        while(j >= 0 && productoLista[j].precio > key.precio){
            productoLista[j + 1] = productoLista[j];
            j--;
        }
        productoLista[j + 1] = key;
    }
    cout << endl;
    cout << "===== Precio de productos ordenados por insercion =====" << endl;
  
    for(int i = 0; i < contadorP; i++) { 
        cout << "Nombre del producto: " << productoLista[i].nombre << endl;
        cout << "Precio: " << productoLista[i].precio << endl;
        cout << "Cantidad: " << productoLista[i].cantidad << endl;
    }
}

//-------------------------------------------------------------------------------------
// 4. Buscar un producto por nombre.
//-------------------------------------------------------------------------------------
void buscarP() { 

    string productoBuscado;

    cout << "Escriba el producto que quiera buscar: ";
    cin >> productoBuscado;

    bool encontrado = false;
    for(int i = 0; i < contadorP; i++){
        if(productoLista[i].nombre == productoBuscado){
            cout << endl;
            cout << "Producto encontrado es: " << endl;
            cout << "Producto: "<< productoLista[i].nombre << endl; 
            cout << "Precio: " << productoLista[i].precio << endl;
            cout << "Cantidad: " << productoLista[i].cantidad << endl;
            encontrado = true;
            break;
        }
    }
    cout << endl;
    if(!encontrado){
        cout << "Upss! El producto no existe." << endl;
        cout << endl;
    }
}

//-------------------------------------------------------------------------------------
// 5. Actualizar información de un PRODUCTO seleccionado.
//-------------------------------------------------------------------------------------
void actualizarP() {
    if (contadorP == 0) {
        cout << "No hay productos para actualizar." << endl;
        return;
    }

    cout << "Ingrese el Indice del producto que quiere actualizar (1 a " << contadorP << "): ";
    int numIndice;
   
    while(!(cin >> numIndice)) {
        cout << endl;
        cout << "Upss! Se debe ingresar un numero, no un caracter." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  

        cout<<"Plis, selecione una opcion adecuada: ";
    }

    if(numIndice < 1 || numIndice > contadorP){ 
        cout << endl;
        cout << "Error en el indice. Seleccione uno de nuevo: ";
        cin >> numIndice;
    }
    
    numIndice--; 
    cout << "Opciones para actualizar." << endl;
    cout << "1. Precio" << endl;
    cout << "2. Cantidad" << endl;
    int opcion;
    cout << "Opcion: ";
    cin >> opcion;

    while(opcion < 1 || opcion > 2) { 
        cout<<endl;
        cout<<"Upss! Esa opcion no existe en el menu." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        cout << "Ingrese una opcion valida: ";
        cin >> opcion;            
    }

    switch(opcion){
        case 1:
            cout << "Actualizar precio: ";
            while(!(cin >> productoLista[numIndice].precio)) { 
                cout  <<endl;
                cout << "Upss! El precio debe ser un numero." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Ingrese un precio valido: ";
            }
            cout << "Producto actualizado de manera correcta :)" << endl;
            break;

        case 2:
            cout << "Actualizar cantidad: ";
            while(!(cin >> productoLista[numIndice].cantidad)) { 
                cout << endl;
                cout << "Upss! No debe de contener letras." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ingresa una cantidad valida: ";
            }
            cout << "Producto actualizado correctamente :)" << endl;
            cout << endl;
            break;
    }
}

//-------------------------------------------------------------------------------------
// 6. Reporte FINAL.
//-------------------------------------------------------------------------------------
void reporteFinal() {
    cout << " ====REPORTE FINAL DE PRODUCTOS==== " << endl;
    cout << "Total de productos registrados: " << contadorP << endl;
    float valorTotal = 0;
    for(int i = 0; i < contadorP; i++){
        valorTotal += productoLista[i].precio * productoLista[i].cantidad;
    }
    cout << "Valor total del inventario: $" <<valorTotal<< endl;

    cout << "Producto con mayor cantidad: ";
    int maxCantidadIndex = 0;
    for(int i = 1; i < contadorP; i++){
        if(productoLista[i].cantidad > productoLista[maxCantidadIndex].cantidad){
            maxCantidadIndex = i;
        }
    }

    cout << "Nombre: " << productoLista[maxCantidadIndex].nombre 
         << " (" << productoLista[maxCantidadIndex].cantidad << ")" << endl;

    cout << endl;
}

//-------------------------------------------------------------------------------------
// Función principal.
//-------------------------------------------------------------------------------------
int main() {

    int opcion;

    do {
    cout << endl;
    cout << "====SISTEMA BASICO DE GESTION DE PRODUCTOS====" << endl;
    cout << "1. Registrar productos" << endl;
    cout << "2. Mostrar productos" << endl;
    cout << "3. Ordenar productos" << endl;
    cout << "4. Buscar producto" << endl;
    cout << "5. Actualizar producto" << endl;
    cout << "6. Generar reporte final" << endl;
    cout << "7. Salir" << endl;

    cout<<"Seleccione una opcion: ";

    while(!(cin >> opcion)) { 
        cout << "Upss! Deberia ser un numero, no un caracter." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << endl;
        cout << "Intenta de nuevo. Selecciona una opcion correcta: ";
    }
    cout << endl;

        switch (opcion) {
            case 1:
                registrarP();
                break;

            case 2:
                mostrarP();
                break;

            case 3:
                cout <<"Seleccione metodo de ordenamiento." << endl;
                cout <<  "1. Burbuja" << endl;
                cout << "2. Seleccion" << endl;
                cout << "3. Insercion" << endl;

                int opcion2;
                cout << "Opcion: ";
                while(!(cin >> opcion2)) { 
                    cout << endl;
                    cout << "Upss! Deberia ser un numero, no un caracter." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Intenta de nuevo. Selecciona una opcion correcta: ";
                }
                while(opcion2 < 1 || opcion2 > 3) { 
                    cout << endl;
                    cout << "Upss! Esa opcion no existe en el menu." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  
                    cout << "Selecione una opcion correcta: ";
                    cin >> opcion2;            
                }

                if (opcion2 == 1) {
                    ordenarPBurbuja();

                } else if (opcion2 == 2) {
                    ordenarPSeleccion();

                } else if (opcion2 == 3) {
                    ordenarPInsercion();
                }
                break;

            case 4:
                buscarP();
                break;

            case 5:
                actualizarP();
                break;

            case 6:
                reporteFinal();
                break;

            case 7:
                cout<<"Saliendooo... Graciasss"<<endl;
                cout<<endl;

                break;
            default:
                cout<<endl;

                cout << "Upss! No se puede, intenta de nuevo: " << endl;
                cout << endl;         
        }
    } while(opcion !=7);
    return 0;
}
