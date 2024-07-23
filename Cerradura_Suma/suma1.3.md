# Programa creado por Leyva Gonzalez Irving Antonio
# Titulo
print(" Mayor - Menor. ")
print("")
# Solicitar al usuario que capture 2 numeros 
num1 = float(input(" Captura El Primer Numero: "))
num2 = float(input(" Captura El Segundo Numero: "))
# Condicionales para el numero Mayor y Menor
# Primera  COndicion
if num1 > num2 :
    print(" El numero {} Es Mayor Que El Numero {}. ".format(num1, num2))
# Segunda Condicion
elif num1 < num2 :
    print(" El Numero {} Es Menor Que El Numero {}. ".format(num1, num2))
# Tercera Condicion 
else :
    print(" Los Numeros {} y {} Son Iguales.".format(num1, num2))