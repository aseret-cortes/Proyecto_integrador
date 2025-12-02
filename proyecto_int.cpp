#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int contadorProductos = 0; // Contador de productos registrados
int tamanoProducto = 100; // Tamaño máximo del arreglo de productos
struct Producto{
    string nombre;
    float precio;
    int cantidad;
};
Producto productoLista[100] = {}; // Arreglo para almacenar los productos

// 1. Registrar productos.
void registrarProductos(){ // Función para registrar productos
    int cantidadProductos = 0;
    int conteo = 1;
    cout << "Ingrese el numero de productos que quiere registrar (max. 100): ";
    cin >> cantidadProductos;
    int totalRegistro = contadorProductos + cantidadProductos; // Total de productos a registrar
    if(contadorProductos < tamanoProducto){
        for(int i = contadorProductos; i < totalRegistro; i++){
            if(contadorProductos >= 100){
                cout <<"Son muchos productos. Se alcanzo el limite de productos."<<endl;
                break;
            }
            cout << "Producto[" << conteo << "]" << endl; // Mostrar número de producto
            while(true){
                cout << "Nombre: ";
                cin >> productoLista[i].nombre;
                if(productoLista[i].nombre == ""){
                    cout << "El nombre no puede estar vacio. Ingresa un nombre correcto." <<endl;
                    continue; // Verificar que el nombre no esté vacío
                }
                if(productoLista[i].nombre == "\n"){
                    cout << "El nombre no puede tener saltos de lineas." <<endl;
                    continue; // Verificar que el nombre no tenga saltos de línea
                }
                break;
            }
            while(true){ // Validar que el precio sea mayor a 0
                cout << "Precio: ";
                cin >> productoLista[i].precio;
                if(productoLista[i].precio <= 0){
                    cout << "El precio debe ser mayor a 0" <<endl;
                    }
                else{
                    break;
                }
            }
            while(true){ // Validar que la cantidad sea mayor a 0
                cout << "Cantidad: ";
                cin >> productoLista[i].cantidad;
                if(productoLista[i].cantidad <= 0){
                    cout << "La cantidad debe ser mayor a 0" <<endl;
                    }
                else{
                    break;
                }
            }
            cout << "\n"<<endl; // Salto de línea para mejor lectura
            contadorProductos+=1;
            conteo++;
        }
    }
    else
    {
        cout <<"Limite de productos ha sido alcanzado"<<endl; // Mensaje si se alcanza el límite de productos
    }
}
// 2. Mostrar la lista de productos.
char tab = '\t';
void mostrarProductos(){ // Función para mostrar los productos registrados
    cout <<"===== LISTA DE PRODUCTOS =====" <<endl;
    cout <<"Nombre" << tab << "Precio" << tab << "Cantidad"<<endl;
    cout <<"-------------------------------------"<<endl;
    for(int i=0;i < tamanoProducto;i++){
        if(productoLista[i].nombre != "" && productoLista[i].precio != 0.0)
        if(productoLista[i].cantidad != 0){
            cout << productoLista[i].nombre << tab <<productoLista[i].precio << tab <<productoLista[i].cantidad<<endl;
        }
    }
}
// 3. Ordenarlos por precio, nombre o cantidad utilizando métodos de ordenamiento básicos.


// 3.1. Metodo de ordenamiento de tipo burbuja
void ordenarBurbuja(){ // Función para ordenar productos por precio usando el método de burbuja
    int i,j;
    Producto aux; // Variable auxiliar para el intercambio
    Producto arreglo[100] = {};
    for(int i=0;i < tamanoProducto;i++){ // Copiar productos al arreglo auxiliar
        arreglo[i] = productoLista[i];
    }
    for(i=0;i<tamanoProducto - 1;i++){ // Algoritmo de burbuja
        for(j=0;j<tamanoProducto - 1 - i;j++){
            if(arreglo[j].precio > arreglo[j+1].precio){
                aux = arreglo[j];
                arreglo[j] = arreglo[j+1];
                arreglo[j+1] = aux;
            }
        }
    }
    for(int i=0;i < tamanoProducto;i++){ // Mostrar productos ordenados
        if(arreglo[i].nombre != "" && arreglo[i].precio != 0.0)
        if(arreglo[i].cantidad != 0){
            cout << "Nombre: "<< arreglo[i].nombre <<endl;
            cout << "Precio: "<< arreglo[i].precio <<endl;
            cout << "Cantidad: " <<arreglo[i].cantidad<<endl;
        }
    }
}

// 3.2. Metodo de ordenamiento de tipo selección
void ordenarSeleccion(){ // Función para ordenar productos por precio usando el método de selección
    int i,j,min; // Variables para los índices
    Producto aux;
    Producto arreglo[100] = {};
    for(int i=0;i < tamanoProducto;i++){ // Copiar productos al arreglo auxiliar
        arreglo[i] = productoLista[i];
    }
    for(i=0;i<tamanoProducto;i++){ // Algoritmo de selección
        min = i;
        for(j=i+1;j<tamanoProducto;j++){ // Buscar el índice del elemento mínimo
            if(arreglo[j].precio < arreglo[min].precio){
                min = j;
            }
        }
        aux = arreglo[i];
        arreglo[i] = arreglo[min];
        arreglo[min] = aux;
    }
    for(int i=0;i < tamanoProducto;i++){ // Mostrar productos ordenados
        if(arreglo[i].nombre != "" && arreglo[i].precio != 0.0)
        if(arreglo[i].cantidad != 0){
            cout << "Nombre: "<< arreglo[i].nombre <<endl;
            cout << "Precio: "<< arreglo[i].precio <<endl;
            cout << "Cantidad: " <<arreglo[i].cantidad<<endl;
        }
    }
}

//3.3. Metodo de ordenamiento de tipo inserción
void ordenarInsercion(){ // Función para ordenar productos por precio usando el método de inserción
    int i,pos;
    Producto aux;
    Producto arreglo[100] = {};
    for(int i=0;i < tamanoProducto;i++){
        arreglo[i] = productoLista[i];
    }
    for(i=0;i<tamanoProducto;i++){ // Algoritmo de inserción
        pos = i;
        aux = arreglo[i];
        while((pos>0) && (arreglo[pos - 1].precio > aux.precio)){
            arreglo[pos] = arreglo[pos -1];
            pos--;
        }
        arreglo[pos] = aux;
    }
    for(int i=0;i < tamanoProducto;i++){ // Mostrar productos ordenados
        if(arreglo[i].nombre != "" && arreglo[i].precio != 0.0)
        if(arreglo[i].cantidad != 0){
            cout << "Nombre: "<< arreglo[i].nombre <<endl;
            cout << "Precio: "<< arreglo[i].precio <<endl;
            cout << "Cantidad: " <<arreglo[i].cantidad<<endl;
        }
    }
}

/// 4.-Actualizar información de un producto seleccionado.
void actualizarProducto(){ // Función para actualizar el precio o cantidad de un producto
    int i = 0;
    int opcion = 0;
    while(true){
        cout << "Ingrese el indice del producto a actualizar (el indice 0 es el primer producto): ";
        cin >> i;
        if(i >= tamanoProducto){
        cout << "Esa posicion no existe. Intente de nuevo." <<endl;
        }
        else{
            break;
        }
    }
    cout << "Escribe lo que desea actualizar:"<<endl;
    cout << "1. Precio"<<endl;
    cout << "2. Cantidad"<<endl;
    cout << "Seleciona la opcion: ";
    cin >> opcion;
    
    switch(opcion){ // Actualizar según la opción seleccionada
        case 1:
        while(true){
            cout << "Nuevo precio:"<<endl;
            cin >> productoLista[i].precio;
            if(productoLista[i].precio <= 0){
                cout << "El precio debe ser mayor a 0" <<endl;
            }
            else{
                break;
            }
        }
            break;
        case 2:
        while(true){ // Actualizar cantidad
            cout << "Ingrese la nueva cantidad: ";
            cin >> productoLista[i].cantidad;
            if(productoLista[i].cantidad <= 0){ // Validar que la cantidad sea mayor a 0
                cout << "Erroro. La cantidad debe ser mayor a 0."<<endl;
            }
            else{
                break;
            }
        }
            break;
        default:
            break;
    }
}

///5.-Buscar un producto por nombre.
void buscarProducto(){ // Función para buscar un producto por nombre
    string busqueda;
    cout << "Ingrese el nombre que quiere buscar: ";
    cin >> busqueda;
    cout << "El producto ha sido encontrado" <<endl;
    for(int i=0;i < tamanoProducto;i++){ // Buscar el producto en la lista
        if(productoLista[i].nombre == busqueda){
            cout << "Nombre: " << productoLista[i].nombre <<endl;
            cout << "Precio: " << productoLista[i].precio <<endl;
            cout << "Cantidad: " << productoLista[i].cantidad <<endl;
            break;
        }
    }
}

//6. Reporte Final
void reporteFinal(){ // Función para generar un reporte final de los productos
    int totalProductos = 0;
    double totalPrecio = 0.0;
    string productoMayor = "";
    int mayorCantidad = 0;
        for(int i=0;i < tamanoProducto;i++){
        if(productoLista[i].nombre != "" && productoLista[i].precio != 0.0) // Contar productos y sumar precios
        if(productoLista[i].cantidad != 0){
            totalProductos++;
            totalPrecio+=productoLista[i].precio;
        }
        productoMayor = productoLista[0].nombre;
        mayorCantidad = productoLista[0].cantidad;
        for(int i=1;i < tamanoProducto;i++){
        if(productoLista[i].nombre != "" && productoLista[i].precio != 0.0)
        if(productoLista[i].cantidad != 0){
            if(productoLista[i].cantidad > mayorCantidad){
                productoMayor = productoLista[i].nombre;
                mayorCantidad = productoLista[i].cantidad;
            }
        }
        }
        }
    cout << "===== REPORTE FINAL ====="<<endl;
    cout << "Total de productos registrados: "<< totalProductos << endl;
    cout << "Valor total en inventario: "<< " $ "<< totalPrecio << endl;
    cout << "Producto con mayor cantidad:"<< productoMayor << "(" << mayorCantidad << ")"<<endl;
}


int main()
{
    int opcion = 0;
    while(true){ // Menú principal
        cout << "===== SISTEMA BASICO DE GESTION DE PRODUCTOS ====="<<endl;
        cout << "1. Registrar productos" <<endl;
        cout << "2. Mostrar productos   "<<endl;
        cout << "3. Ordenar productos   "<<endl;
        cout << "4. Buscar producto     "<<endl;
        cout << "5. Actualizar producto" <<endl;
        cout << "6. Generar reporte final"<<endl;
        cout << "7. Salir"<<endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch(opcion){ // Ejecutar función según la opción seleccionada
            case 1:{
                registrarProductos();
                continue;
            }
            case 2:{
                mostrarProductos();
                continue;
            }
            case 3:{
                int opcionOrden = 0; // Submenú para seleccionar el método de ordenamiento
                cout << "Seleccione metodo de ordenamiento:"<<endl;
                cout << "1. Burbuja"<<endl;
                cout << "2. Seleccion"<<endl;
                cout << "3. Insercion"<<endl;
                cout << "Opcion: ";
                cin >> opcionOrden;
                switch(opcionOrden){ // Ejecutar el método de ordenamiento seleccionado
                    case 1:
                        ordenarBurbuja();
                        continue;
                    case 2:
                        ordenarSeleccion();
                        continue;
                    case 3:
                        ordenarInsercion();
                        continue;
                    default:
                        continue;
                }
                continue;
            }
            case 4:{
                buscarProducto();
                continue;
            }
            case 5:{
                actualizarProducto();
                continue;
            }
            case 6:{
                reporteFinal();
                continue;
            }
            case 7:{
                cout << "Saliendo del programa..." <<endl; //Termianar el programa 
                break;
            }
        }
    }
    return 0;
}