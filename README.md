# Algoritmos de Ordenamiento y Búsqueda en C++

Proyecto educativo que demuestra la implementación de diversos algoritmos fundamentales de ordenamiento interno y búsqueda en C++. Este proyecto es ideal para estudiantes que deseen comprender cómo funcionan estos algoritmos a nivel de implementación.

## Descripción del Proyecto

Este proyecto implementa algoritmos clásicos organizados en tres categorías principales:

### 1. Algoritmos de Ordenamiento Directo
Estos algoritmos tienen complejidad O(n²) y son más lentos pero más fáciles de comprender.

- **Bubble Sort (Intercambio)**
  - Concepto: Compara elementos adyacentes e intercambia si está en el orden incorrecto
  - Complejidad: O(n²) en todos los casos
  - Uso: Educativo, datos pequeños, datos casi ordenados
  - Archivo: `OrdenamientoDirecto.h`

- **Insertion Sort (Inserción)**
  - Concepto: Inserta cada elemento en su posición correcta dentro de la porción ordenada
  - Complejidad: O(n²) peor caso, O(n) mejor caso
  - Uso: Datos pequeños o parcialmente ordenados, muy eficiente en estos casos
  - Archivo: `OrdenamientoDirecto.h`

- **Selection Sort (Selección)**
  - Concepto: Selecciona el elemento mínimo y lo coloca en su posición correcta
  - Complejidad: O(n²) en todos los casos
  - Uso: Cuando queremos minimizar el número de intercambios
  - Archivo: `OrdenamientoDirecto.h`

### 2. Algoritmos de Ordenamiento Logarítmico
Estos algoritmos tienen mejor complejidad temporal (O(n log n)) y son más eficientes para conjuntos grandes.

- **Shell Sort**
  - Concepto: Extensión de Insertion Sort que utiliza espacios decrecientes entre elementos
  - Complejidad: O(n log n) a O(n²) dependiendo de la secuencia de espacios
  - Uso: Excelente compromiso entre simplicidad e eficiencia
  - Archivo: `OrdenamientoLogaritmico.h`

- **Quick Sort**
  - Concepto: Algoritmo divide y conquista que particiona el array alrededor de un pivote
  - Complejidad: O(n log n) promedio, O(n²) peor caso
  - Uso: Generalmente muy rápido en la práctica, ampliamente utilizado
  - Archivo: `OrdenamientoLogaritmico.h`

- **Heap Sort**
  - Concepto: Utiliza una estructura de heap (montículo) para ordenar elementos
  - Complejidad: O(n log n) garantizado en todos los casos
  - Uso: Cuando se necesita garantizar O(n log n), rendimiento consistente
  - Archivo: `OrdenamientoLogaritmico.h`

### 3. Algoritmos de Búsqueda
Métodos para encontrar elementos específicos en colecciones de datos.

- **Búsqueda Secuencial**
  - Concepto: Recorre el array elemento por elemento hasta encontrar el objetivo
  - Complejidad: O(n)
  - Requisitos: Ninguno, funciona en arrays desordenados
  - Uso: Arrays pequeños, datos desordenados
  - Archivo: `Busqueda.h`

- **Búsqueda Binaria**
  - Concepto: Divide el espacio de búsqueda por la mitad en cada iteración
  - Complejidad: O(log n)
  - Requisitos: Array debe estar ordenado
  - Uso: Búsquedas rápidas en arrays grandes y ordenados
  - Archivo: `Busqueda.h`

- **Árbol de Búsqueda Binaria (ABB)**
  - Concepto: Estructura de datos que mantiene elementos ordenados para búsquedas eficientes
  - Complejidad: O(log n) promedio, O(n) peor caso
  - Requisitos: Inserción previa de elementos en el árbol
  - Uso: Mantenimiento dinámico de conjuntos ordenados, búsquedas recurrentes
  - Archivo: `Busqueda.h`

## Estructura del Proyecto

```
OrdenamientoYBusqueda/
??? OrdenamientoYBusqueda.cpp      # Archivo principal con menú y demostraciones
??? OrdenamientoDirecto.h          # Implementación de algoritmos O(n²)
??? OrdenamientoLogaritmico.h      # Implementación de algoritmos O(n log n)
??? Busqueda.h                      # Implementación de algoritmos de búsqueda
??? Utilidades.h                    # Funciones auxiliares y utilidades
??? OrdenamientoYBusqueda.sln       # Solución Visual Studio
??? OrdenamientoYBusqueda.vcxproj   # Archivo de proyecto Visual Studio
??? README.md                       # Este archivo
```

## Características Principales

- **Plantillas genéricas**: Los algoritmos utilizan templates para trabajar con cualquier tipo de dato comparable
- **Interfaz interactiva**: Menú de usuario para seleccionar qué algoritmos demostrar
- **Análisis educativo**: Contadores de comparaciones e intercambios para entender el comportamiento
- **Ejemplos claros**: Demostración paso a paso de cada algoritmo
- **Documentación completa**: Comentarios extensos explicando cada algoritmo

## Tabla Comparativa de Complejidad

| Algoritmo | Mejor Caso | Caso Promedio | Peor Caso | Espacio |
|-----------|-----------|---------------|-----------|---------|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) |
| Shell Sort | O(n) | O(n log n) | O(n²) | O(1) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) |
| Búsqueda Secuencial | O(1) | O(n/2) | O(n) | O(1) |
| Búsqueda Binaria | O(1) | O(log n) | O(log n) | O(1) |
| Árbol de Búsqueda | O(log n) | O(log n) | O(n) | O(n) |

## Requisitos del Sistema

- **Compilador**: C++ 14 o superior
- **Entorno**: Visual Studio 2015+ (también compatible con otros compiladores)
- **SO**: Windows, Linux, macOS
- **RAM**: Mínimo 512 MB

## Compilación y Ejecución

### Visual Studio (Windows)
1. Abrir `OrdenamientoYBusqueda.sln`
2. Compilar: `Ctrl + B` o menú Compilar > Compilar solución
3. Ejecutar: `Ctrl + F5` (sin depuración) o `F5` (con depuración)

### Línea de comandos (g++ en Linux/macOS)
```bash
g++ -std=c++14 -o ordenamiento OrdenamientoYBusqueda.cpp
./ordenamiento
```

### Línea de comandos (clang)
```bash
clang++ -std=c++14 -o ordenamiento OrdenamientoYBusqueda.cpp
./ordenamiento
```

## Guía de Uso

Al ejecutar el programa, se mostrará un menú interactivo:

```
=====================================
ALGORITMOS DE ORDENAMIENTO Y BUSQUEDA
=====================================

1. Ordenamiento Directo
2. Ordenamiento Logaritmico
3. Algoritmos de Busqueda
4. Ejecutar todo
5. Salir

Seleccione una opción:
```

### Opciones disponibles:

1. **Ordenamiento Directo**: Demuestra Bubble Sort, Insertion Sort y Selection Sort
2. **Ordenamiento Logarítmico**: Demuestra Shell Sort, Quick Sort y Heap Sort
3. **Algoritmos de Búsqueda**: Demuestra Búsqueda Secuencial, Binaria y Árbol de Búsqueda Binaria
4. **Ejecutar todo**: Ejecuta todas las demostraciones
5. **Salir**: Cierra el programa

Cada demostración muestra:
- El algoritmo siendo demostrado
- Su complejidad temporal
- Array antes y después de la operación
- Estadísticas adicionales (para ordenamiento)

## Concepto Educativo

Este proyecto está diseñado para:

1. **Comprender fundamentos**: Cada algoritmo está implementado de forma clara y fácil de seguir
2. **Aprender complejidad**: Comparar cómo behave cada algoritmo con diferentes tamaños de entrada
3. **Experiencia práctica**: Observar el comportamiento real de los algoritmos
4. **Análisis comparativo**: Ver diferencias entre algoritmos similares

### Sugerencias de estudio:

- Ejecute los algoritmos y observe los contadores de comparaciones
- Modifique el tamaño del array para ver cómo escala cada algoritmo
- Compare los resultados entre diferentes algoritmos
- Lea el código fuente para entender la implementación
- Agregue sus propios algoritmos siguiendo la misma estructura

## Explicación de Conceptos Clave

### Complejidad Temporal
Mide cuántas operaciones básicas realiza un algoritmo en función del tamaño de entrada (n):
- **O(1)**: Tiempo constante, muy rápido
- **O(log n)**: Logarítmica, muy eficiente
- **O(n)**: Lineal, eficiente
- **O(n log n)**: Linearítmica, buena para la mayoría
- **O(n²)**: Cuadrática, lenta para n grande

### Complejidad Espacial
Mide cuánta memoria adicional necesita un algoritmo.

### Dividir y Conquistar
Estrategia donde se divide el problema en subproblemas más pequeños (Quick Sort, Merge Sort).

### Estructura de Heap
Árbol binario completo donde cada padre es mayor que sus hijos (max-heap).

## Debugging y Depuración

El código incluye funciones de utilidad para análisis:
- `ImprimirArray()`: Visualizar el contenido del array
- `EstaOrdenado()`: Verificar si el array está correctamente ordenado
- Contadores de operaciones para análisis de rendimiento

## Ejemplo de Uso

```cpp
// Ordenamiento
int arr[] = {64, 25, 12, 22, 11};
OrdenamientoLogaritmico::QuickSort(arr, 5);

// Búsqueda en array ordenado
int resultado = Busqueda::BusquedaBinaria(arr, 5, 25);
// resultado será 1

// Árbol de Búsqueda
Busqueda::ArbolBusquedaBinaria<int> arbol;
arbol.Insertar(50);
arbol.Insertar(30);
arbol.Insertar(70);
if (arbol.Buscar(30)) {
    cout << "Elemento encontrado" << endl;
}
```

## Recursos Adicionales

Para profundizar en estos temas, se recomienda:
- **"Introduction to Algorithms"** de Cormen, Leiserson, Rivest y Stein
- **"The Algorithm Design Manual"** de Steven Skiena
- Plataformas como LeetCode, HackerRank para practicar

## Notas Importantes

- Este proyecto implementa **ordenamiento interno** (en memoria)
- **No incluye** transformación de claves (hashing)
- Todos los algoritmos son **comparativos** (basados en comparación de elementos)
- Los templates permiten usar cualquier tipo de dato con operador `<`, `>`, `==`

## Autor

Manuel Balderas - Proyecto educativo de demostración de algoritmos fundamentales en C++.

## Licencia

Este proyecto es de uso educativo. Siéntase libre de modificarlo y adaptarlo a sus necesidades.

## Contribuciones

Si desea mejorar este proyecto, puede:
- Agregar más algoritmos (Merge Sort, Counting Sort, etc.)
- Mejorar la documentación
- Agregar más análisis de rendimiento
- Crear visualizaciones mejoradas

---

**Última actualización**: 2026

Proyecto diseñado para estudiantes de Estructuras de Datos y Análisis de Algoritmos.
