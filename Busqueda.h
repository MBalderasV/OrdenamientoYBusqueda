#pragma once

class Busqueda
{
private:
    // Nodo para árbol de búsqueda binaria
    template<typename T>
    struct NodoABB
    {
        T dato;
        NodoABB* izq;
        NodoABB* der;

        NodoABB(T valor) : dato(valor), izq(nullptr), der(nullptr) {}
    };

    // Función auxiliar recursiva para insertar en ABB
    template<typename T>
    static NodoABB<T>* InsertarRecursivo(NodoABB<T>* nodo, T valor)
    {
        if (nodo == nullptr)
        {
            return new NodoABB<T>(valor);
        }

        if (valor < nodo->dato)
        {
            nodo->izq = InsertarRecursivo(nodo->izq, valor);
        }
        else if (valor > nodo->dato)
        {
            nodo->der = InsertarRecursivo(nodo->der, valor);
        }
        return nodo;
    }

    // Función auxiliar recursiva para buscar en ABB
    template<typename T>
    static NodoABB<T>* BuscarRecursivo(NodoABB<T>* nodo, T valor)
    {
        if (nodo == nullptr)
        {
            return nullptr;
        }

        if (valor == nodo->dato)
        {
            return nodo;
        }
        else if (valor < nodo->dato)
        {
            return BuscarRecursivo(nodo->izq, valor);
        }
        else
        {
            return BuscarRecursivo(nodo->der, valor);
        }
    }

    // Función auxiliar para liberar memoria del árbol
    template<typename T>
    static void LiberarArbol(NodoABB<T>* nodo)
    {
        if (nodo == nullptr) return;
        LiberarArbol(nodo->izq);
        LiberarArbol(nodo->der);
        delete nodo;
    }

public:
    // Búsqueda Secuencial
    // Complejidad: O(n) - Recorre elemento por elemento hasta encontrar o llegar al final
    template<typename T>
    static int BusquedaSecuencial(T arr[], int n, T objetivo)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == objetivo)
            {
                return i;
            }
        }
        return -1; // No encontrado
    }

    // Búsqueda Binaria
    // Complejidad: O(log n) - Requiere array ordenado
    // Divide el espacio de búsqueda a la mitad en cada iteración
    template<typename T>
    static int BusquedaBinaria(T arr[], int n, T objetivo)
    {
        int izq = 0, der = n - 1;

        while (izq <= der)
        {
            int mid = izq + (der - izq) / 2;

            if (arr[mid] == objetivo)
            {
                return mid;
            }
            else if (arr[mid] < objetivo)
            {
                izq = mid + 1;
            }
            else
            {
                der = mid - 1;
            }
        }
        return -1; // No encontrado
    }

    // Árbol de Búsqueda Binaria (ABB)
    // Estructura de datos que mantiene elementos ordenados
    template<typename T>
    class ArbolBusquedaBinaria
    {
    private:
        NodoABB<T>* raiz;

    public:
        ArbolBusquedaBinaria() : raiz(nullptr) {}

        ~ArbolBusquedaBinaria()
        {
            LiberarArbol(raiz);
        }

        // Insertar elemento en el árbol
        // Complejidad: O(log n) promedio, O(n) peor caso
        void Insertar(T valor)
        {
            raiz = InsertarRecursivo(raiz, valor);
        }

        // Buscar elemento en el árbol
        // Complejidad: O(log n) promedio, O(n) peor caso
        bool Buscar(T valor)
        {
            return BuscarRecursivo(raiz, valor) != nullptr;
        }

        // Obtener la raíz del árbol (útil para travesías)
        NodoABB<T>* ObtenerRaiz() const
        {
            return raiz;
        }

        // Recorrido en orden (inorden) - genera secuencia ordenada
        void RecorridoInorden(NodoABB<T>* nodo = nullptr)
        {
            if (nodo == nullptr)
            {
                nodo = raiz;
                if (nodo == nullptr) return;
            }

            if (nodo->izq != nullptr)
                RecorridoInorden(nodo->izq);

            std::cout << nodo->dato << " ";

            if (nodo->der != nullptr)
                RecorridoInorden(nodo->der);
        }
    };
};
