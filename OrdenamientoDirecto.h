#pragma once

class OrdenamientoDirecto
{
public:
    // Ordenamiento por Intercambio (Bubble Sort)
    // Complejidad: O(n²) - Compara elementos adyacentes e intercambia si es necesario
    template<typename T>
    static void BubbleSort(T arr[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    // Ordenamiento por Inserción
    // Complejidad: O(n²) - Inserta cada elemento en su posición correcta
    template<typename T>
    static void InsertionSort(T arr[], int n)
    {
        for (int i = 1; i < n; i++)
        {
            T key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    // Ordenamiento por Selección
    // Complejidad: O(n²) - Selecciona el mínimo y lo coloca en la posición correcta
    template<typename T>
    static void SelectionSort(T arr[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            int minIdx = i;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[minIdx])
                {
                    minIdx = j;
                }
            }
            if (minIdx != i)
            {
                T temp = arr[i];
                arr[i] = arr[minIdx];
                arr[minIdx] = temp;
            }
        }
    }
};
