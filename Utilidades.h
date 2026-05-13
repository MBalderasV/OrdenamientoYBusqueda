#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

class Utilidades
{
public:
    // Generar array con números aleatorios
    static void GenerarArrayAleatorio(int arr[], int n, int minVal = 1, int maxVal = 100)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] = minVal + rand() % (maxVal - minVal + 1);
        }
    }

    // Imprimir array
    template<typename T>
    static void ImprimirArray(T arr[], int n, const char* titulo = "Array: ")
    {
        std::cout << titulo;
        for (int i = 0; i < n; i++)
        {
            std::cout << arr[i];
            if (i < n - 1) std::cout << ", ";
        }
        std::cout << std::endl;
    }

    // Copiar array
    static void CopiarArray(int source[], int dest[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            dest[i] = source[i];
        }
    }

    // Verificar si array está ordenado
    template<typename T>
    static bool EstaOrdenado(T arr[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
                return false;
        }
        return true;
    }

    // Contar comparaciones (para análisis educativo)
    static long long comparacionesGlobales;
    static long long intercambiosGlobales;

    // Versión de BubbleSort con contador
    static void BubbleSortConContador(int arr[], int n)
    {
        comparacionesGlobales = 0;
        intercambiosGlobales = 0;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                comparacionesGlobales++;
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    intercambiosGlobales++;
                }
            }
        }
    }
};

long long Utilidades::comparacionesGlobales = 0;
long long Utilidades::intercambiosGlobales = 0;
