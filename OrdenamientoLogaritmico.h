#pragma once

class OrdenamientoLogaritmico
{
private:
    // Función auxiliar para Heapsort - construir heap
    template<typename T>
    static void Heapify(T arr[], int n, int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i)
        {
            T temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            Heapify(arr, n, largest);
        }
    }

    // Función auxiliar para Quicksort - particionar
    template<typename T>
    static int Partition(T arr[], int low, int high)
    {
        T pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        T temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return i + 1;
    }

    // Función auxiliar recursiva para Quicksort
    template<typename T>
    static void QuickSortRecursivo(T arr[], int low, int high)
    {
        if (low < high)
        {
            int pi = Partition(arr, low, high);
            QuickSortRecursivo(arr, low, pi - 1);
            QuickSortRecursivo(arr, pi + 1, high);
        }
    }

public:
    // Shell Sort - Extensión de Insertion Sort con espacios decrecientes
    // Complejidad: O(n log n) a O(n²) dependiendo de la secuencia de espacios
    template<typename T>
    static void ShellSort(T arr[], int n)
    {
        for (int gap = n / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < n; i++)
            {
                T temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }

    // Quick Sort - Divide y conquista usando partición
    // Complejidad: O(n log n) promedio, O(n²) peor caso
    template<typename T>
    static void QuickSort(T arr[], int n)
    {
        if (n > 1)
        {
            QuickSortRecursivo(arr, 0, n - 1);
        }
    }

    // Heap Sort - Utiliza estructura de heap
    // Complejidad: O(n log n) - Garantizado incluso en peor caso
    template<typename T>
    static void HeapSort(T arr[], int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
            Heapify(arr, n, i);

        for (int i = n - 1; i > 0; i--)
        {
            T temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            Heapify(arr, i, 0);
        }
    }
};
