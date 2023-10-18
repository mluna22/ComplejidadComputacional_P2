# Complejidad Computacional
## Práctica 2: Simulador de Máquina de Turing

Compilar: `make`  
Uso: `./bin/tm_simulator <config_file> [input_file]`  

- El programa lee el archivo de configuración indicado como argumento y simula el comportamiento de una máquina de Turing.
- Opcionalmente puede introducir como argumento un fichero con las cadenas de entrada, o introducirlas por consola
- La máquina ha sido configurada de la siguiente manera:
    - Escritura y movimiento simultáneos
    - Posibilidad de no movimiento (S)
    - Cinta infinita en ambas direcciones
    - Una o más cintas