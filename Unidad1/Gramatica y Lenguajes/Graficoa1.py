import matplotlib.pyplot as plt
import numpy as np
# Solicitar al usuario que ingrese los valores de m, x y b
m = float(input("Ingrese la pendiente (m): "))
b = float(input("Ingrese la ordenada al origen (b): "))
# Crear un rango de valores de x
x = np.linspace(-10, 10, 400)
# Calcular el valor de la función para cada x
y = m * x + b
# Crear la figura y el eje
fig, ax = plt.subplots()
# Graficar la función
ax.plot(x, y)
# Agregar título y etiquetas
ax.set_title("Gráfico de la función y = mx + b")
ax.set_xlabel("x")
ax.set_ylabel("y")
# Mostrar la gráfica
plt.show()