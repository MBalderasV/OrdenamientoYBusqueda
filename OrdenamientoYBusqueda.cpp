// OrdenamientoYBusqueda.cpp
// Proyecto educativo: Algoritmos de Ordenamiento y Búsqueda en C++
// Demuestra la implementación de diversos algoritmos fundamentales

#include <iostream>
#include <iomanip>
#include <ctime>
#include "OrdenamientoDirecto.h"
#include "OrdenamientoLogaritmico.h"
#include "Busqueda.h"
#include "Utilidades.h"

using namespace std;

void DemostrarOrdenamientoDirecto()
{
    cout << "\n========================================" << endl;
    cout << "ALGORITMOS DE ORDENAMIENTO DIRECTO" << endl;
    cout << "========================================\n" << endl;

    const int n = 10;
    int arrOriginal[n];
    int arrTemp[n];

    Utilidades::GenerarArrayAleatorio(arrOriginal, n, 10, 99);

    // Bubble Sort
    cout << "1. BUBBLE SORT (Intercambio)" << endl;
    cout << "   Complejidad: O(n²)" << endl;
    Utilidades::CopiarArray(arrOriginal, arrTemp, n);
    Utilidades::ImprimirArray(arrTemp, n, "   Antes:  ");
    Utilidades::BubbleSortConContador(arrTemp, n);
    Utilidades::ImprimirArray(arrTemp, n, "   Despues: ");
    cout << "   Comparaciones: " << Utilidades::comparacionesGlobales
         << ", Intercambios: " << Utilidades::intercambiosGlobales << "\n" << endl;

    // Insertion Sort
    cout << "2. INSERTION SORT (Inserción)" << endl;
    cout << "   Complejidad: O(n²)" << endl;
    Utilidades::CopiarArray(arrOriginal, arrTemp, n);
    Utilidades::ImprimirArray(arrTemp, n, "   Antes:  ");
    OrdenamientoDirecto::InsertionSort(arrTemp, n);
    Utilidades::ImprimirArray(arrTemp, n, "   Despues: ");
    cout << "   Útil para datos parcialmente ordenados\n" << endl;

    // Selection Sort
    cout << "3. SELECTION SORT (Selección)" << endl;
    cout << "   Complejidad: O(n²)" << endl;
    Utilidades::CopiarArray(arrOriginal, arrTemp, n);
    Utilidades::ImprimirArray(arrTemp, n, "   Antes:  ");
    OrdenamientoDirecto::SelectionSort(arrTemp, n);
    Utilidades::ImprimirArray(arrTemp, n, "   Despues: ");
    cout << "   Número de intercambios minimizado\n" << endl;
}

void DemostrarOrdenamientoLogaritmico()
{
    cout << "\n========================================" << endl;
    cout << "ALGORITMOS DE ORDENAMIENTO LOGARITMICO" << endl;
    cout << "========================================\n" << endl;

    const int n = 12;
    int arrOriginal[n];
    int arrTemp[n];

    Utilidades::GenerarArrayAleatorio(arrOriginal, n, 10, 99);

    // Shell Sort
    cout << "1. SHELL SORT" << endl;
    cout << "   Complejidad: O(n log n) a O(n²)" << endl;
    Utilidades::CopiarArray(arrOriginal, arrTemp, n);
    Utilidades::ImprimirArray(arrTemp, n, "   Antes:  ");
    OrdenamientoLogaritmico::ShellSort(arrTemp, n);
    Utilidades::ImprimirArray(arrTemp, n, "   Despues: ");
    cout << "   Extensión eficiente de Insertion Sort\n" << endl;

    // Quick Sort
    cout << "2. QUICK SORT" << endl;
    cout << "   Complejidad: O(n log n) promedio, O(n²) peor caso" << endl;
    Utilidades::CopiarArray(arrOriginal, arrTemp, n);
    Utilidades::ImprimirArray(arrTemp, n, "   Antes:  ");
    OrdenamientoLogaritmico::QuickSort(arrTemp, n);
    Utilidades::ImprimirArray(arrTemp, n, "   Despues: ");
    cout << "   Algoritmo divide y conquista muy eficiente\n" << endl;

    // Heap Sort
    cout << "3. HEAP SORT" << endl;
    cout << "   Complejidad: O(n log n) garantizado" << endl;
    Utilidades::CopiarArray(arrOriginal, arrTemp, n);
    Utilidades::ImprimirArray(arrTemp, n, "   Antes:  ");
    OrdenamientoLogaritmico::HeapSort(arrTemp, n);
    Utilidades::ImprimirArray(arrTemp, n, "   Despues: ");
    cout << "   Rendimiento consistente en todos los casos\n" << endl;
}

void DemostrarBusqueda()
{
    cout << "\n========================================" << endl;
    cout << "ALGORITMOS DE BUSQUEDA" << endl;
    cout << "========================================\n" << endl;

    const int n = 15;
    int arr[n];
    Utilidades::GenerarArrayAleatorio(arr, n, 10, 99);
    OrdenamientoLogaritmico::QuickSort(arr, n);

    cout << "Array disponible para búsqueda (ordenado): ";
    Utilidades::ImprimirArray(arr, n);
    cout << endl;

    // Búsqueda Secuencial
    cout << "1. BUSQUEDA SECUENCIAL" << endl;
    cout << "   Complejidad: O(n)" << endl;
    cout << "   No requiere array ordenado\n";
    int objetivo1 = arr[5];
    int posicion = Busqueda::BusquedaSecuencial(arr, n, objetivo1);
    if (posicion != -1)
    {
        cout << "   Elemento " << objetivo1 << " encontrado en posición: " << posicion << "\n" << endl;
    }
    else
    {
        cout << "   Elemento no encontrado\n" << endl;
    }

    // Búsqueda Binaria
    cout << "2. BUSQUEDA BINARIA" << endl;
    cout << "   Complejidad: O(log n)" << endl;
    cout << "   Requiere array ordenado\n";
    int objetivo2 = arr[n - 3];
    posicion = Busqueda::BusquedaBinaria(arr, n, objetivo2);
    if (posicion != -1)
    {
        cout << "   Elemento " << objetivo2 << " encontrado en posición: " << posicion << "\n" << endl;
    }
    else
    {
        cout << "   Elemento no encontrado\n" << endl;
    }

    // Árbol de Búsqueda Binaria
    cout << "3. ARBOL DE BUSQUEDA BINARIA (ABB)" << endl;
    cout << "   Complejidad: O(log n) promedio, O(n) peor caso\n";
    Busqueda::ArbolBusquedaBinaria<int> arbol;

    cout << "   Insertando elementos: ";
    for (int i = 0; i < n; i++)
    {
        arbol.Insertar(arr[i]);
        cout << arr[i] << " ";
    }
    cout << "\n\n   Recorrido Inorden del árbol: ";
    arbol.RecorridoInorden();
    cout << "\n";

    int objetivo3 = arr[7];
    if (arbol.Buscar(objetivo3))
    {
        cout << "\n   Elemento " << objetivo3 << " encontrado en el árbol\n" << endl;
    }
    else
    {
        cout << "\n   Elemento no encontrado en el árbol\n" << endl;
    }
}

void MostrarMenu()
{
    cout << "\n=====================================" << endl;
    cout << "ALGORITMOS DE ORDENAMIENTO Y BUSQUEDA" << endl;
    cout << "=====================================" << endl;
    cout << "\n1. Ordenamiento Directo" << endl;
    cout << "2. Ordenamiento Logaritmico" << endl;
    cout << "3. Algoritmos de Busqueda" << endl;
    cout << "4. Ejecutar todo" << endl;
    cout << "5. Salir" << endl;
    cout << "\nSeleccione una opción: ";
}

int main()
{
    srand(static_cast<unsigned>(time(0)));
    int opcion;

    do
    {
        MostrarMenu();
        cin >> opcion;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada inválida. Intente de nuevo.\n" << endl;
            continue;
        }

        switch (opcion)
        {
        case 1:
            DemostrarOrdenamientoDirecto();
            break;
        case 2:
            DemostrarOrdenamientoLogaritmico();
            break;
        case 3:
            DemostrarBusqueda();
            break;
        case 4:
            DemostrarOrdenamientoDirecto();
            DemostrarOrdenamientoLogaritmico();
            DemostrarBusqueda();
            break;
        case 5:
            cout << "\n¡Hasta luego!" << endl;
            break;
        default:
            cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);

    return 0;
}
