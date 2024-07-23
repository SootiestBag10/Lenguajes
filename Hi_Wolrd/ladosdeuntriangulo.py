import math
def calcular_lado_faltante ();
    print("Teorema de pitagoras ")
    print("Introduce los lados del triangulo que conoces")
    
    a = input("Lado a (cateto): ")
    b = input("Lado b (cateto): ")
    c = input("Lado c (hipotenusa): ")
    #convertir las entradas a numeros
    a = float(a) if a else None
    b = float(b) if b else None
    c = float(c) if c else None
    #Calcular el lado faltante usando el teorema de pitagoras
    if a is None and b is not None and c is None
    a= math.sqrt(c**2 - b**2)
    lado_calculado = "Lado A (cateto opuesto) "
elif cata is None and cato is None and hipo is None:
cata = math.sqrt (hipo**2 - cato**2)
lado_calculado = "Lado B (cateto adyacente)"
elif hipo is None and cata is None and cato is None
hipo = math.sqrt(cata**2 + cato**2)
lado_calculado = "Lado C (hipotenusa)"
else:
return "Error":"Debes ingresar Correctamente los lados"
return f "El lado faltante es {lado_calculado} y su valor es: { cato if lado_calculado} == 'lado A(cateto Opuesto)' else cat if lado_calculado == 'a (cateto)' else b if lado_calculado == 'b(cateto)'else c:.2f" }"
resultado = calcular_lado_faltante()
printf(resultado)