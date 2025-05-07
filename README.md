# Estructuras de Datos con ADT en C++

Este repositorio contiene múltiples ejemplos de implementación de **Tipos Abstractos de Datos (ADT)** para diseñar estructuras de datos eficientes y reutilizables, todos desarrollados en **C++**.

## Descripción General

Cada estructura fue diseñada siguiendo principios de programación orientada a objetos y encapsulamiento, permitiendo comprender el uso práctico de los ADT en la resolución de problemas comunes.

### Estructuras Implementadas

- **Bitácora**  
  Una estructura que permite almacenar y consultar registros ordenados cronológicamente, ideal para sistemas de logs o auditorías.

- **Torneo**  
  Estructura que simula el desarrollo de un torneo eliminatorio, utilizando colas y pilas para organizar rondas y participantes.

- **Fila Priorizada (Priority Queue)**  
  Estructura basada en una heap que permite extraer elementos según su prioridad. Útil en planificación de tareas, sistemas operativos y algoritmos como Dijkstra.

- **Grafo**  
  Implementación de grafos orientados/no orientados con soporte para algoritmos de recorrido (DFS, BFS) y búsqueda de caminos. Representación mediante listas de adyacencia.

## Objetivo del Proyecto

Proveer implementaciones claras y funcionales de estructuras de datos fundamentales para fortalecer la comprensión de conceptos clave como:

- Encapsulamiento
- Uso de punteros y memoria dinámica
- Modularidad en el diseño de software
- Eficiencia algorítmica

## Requisitos

- **Compilador de C++** compatible con C++17 o superior (por ejemplo, `g++`, `clang++`)
- Sistema operativo Linux, macOS o Windows con terminal

## Instrucciones de Compilación y Ejecución

Cada estructura se encuentra implementada en archivos separados. Para compilar y ejecutar cualquiera de ellos:

1. Navega a la carpeta correspondiente (por ejemplo, `/bitacora/`, `/torneo/`, etc.)
2. Compila el archivo fuente principal. Por ejemplo:

```bash
g++  bitacora.cpp
```
Y ejecutalo: 
```bash
./bitacora
```
