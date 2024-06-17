# Ejercicio de Coordenadas Esféricas Clase 4

## Enunciado

Dado \( P_1 \) y \( P_2 \) en \( \mathbb{R}^3 \) expresados en coordenadas esféricas, programe:

1. Una clase `Point` con atributos privados \( r, \theta, \psi \).
2. Constructor y métodos set tales que: \( r \in \mathbb{R}^+ \), \( \theta \in [0, 2\pi] \), \( \psi \in [0, \pi] \).
3. Sobrecargue el operador `==` para objetos `Point`.
4. Programe el método `octant(P)` que determine el octante al que pertenece `P`.


### Explicación

- La clase `Point` tiene atributos privados para almacenar las coordenadas esféricas.
- El constructor y los métodos set garantizan que los valores de las coordenadas se mantengan dentro de los rangos especificados.
- El operador `==` se sobrecarga para comparar dos objetos `Point`.
- El método `octant()` convierte las coordenadas esféricas a cartesianas y determina el octante correspondiente.
