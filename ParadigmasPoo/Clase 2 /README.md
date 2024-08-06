# Clase 2 Paradigmas POO
defina una clase para manipular elipses en un plano cartesiano. La clase debe tener los siguientes métodos:
1. Considere atributos publicos y privados para la clase. justifique su elección.
2. Defina atributos y funciones para mantener:
    - semieje mayor a
    - semieje menor b
    - focos -sqrt(a^2 - b^2) y sqrt(a^2 - b^2)
    - excentricidad  e = sqrt(sqrt(a^2 - b^2)/a)
    - distancia focal 
    - area
    - perimetro:
      - aproximacion de ramanujan: 2 * pi *(3(a + b  - sqrt((3a + b) (a + 3b))))
      - ramanujan II: pi (a + b) (1 + 3 h / (10 + sqrt(4 - 3 h))), h = (a - b) ^ 2 / (a + b) ^ 2
      - gauss-kummer : pi (a + b) (1 + (1/4) h / (1 + (9/64) h / (1 + (25/256) h / (1 + (49/625) h / ...))))
    - haga una definicion del operador == (sobregarca):
        - para areas iguales 
        - para perimetros iguales (ramaunjan II)
        - para perimetros iguales(Gaus-kummer)