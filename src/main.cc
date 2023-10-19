/** Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Complejidad Computacional
 * Curso: 4º
 * Práctica 2: Simulación de Máquina de Turing (TM)
 * Autor: Miguel Luna García
 * Correo: miguel.luna.19@ull.edu.es
 * Fecha: 20/10/2023
 */

#include <iostream>
#include <vector>
#include <fstream>

#include "tm.h"
#include "utils.h"

int program(int argc, char** argv) {
  
  if (argc < 2) {
    throw "Uso: /mt_simulator <config_file>";
  }

  Tm tm(argv[1]);

  std::string line;
  std::vector<std::string> input;

  if (argc > 2) {
    // Entrada por fichero
    std::ifstream file(argv[2]);
    if (!file) throw "Error al abrir el archivo de entrada";
    while (std::getline(file, line)) {
      input.push_back(line);
    }
    if (input.empty()) throw "Error: fichero vacío";
  } else {
    // Entrada por consola
    std::cout << "Introduzca las cadenas a probar (una por línea)" << std::endl;
    std::cout << "Para dejar la cinta vacía introduzca un símbolo blanco" << std::endl;
    std::cout << "Para terminar, introduzca una línea vacía: \n" << std::endl;
    do {
      std::getline(std::cin, line);
      if (line.empty()) break;
      input.push_back(line);
    } while (true);
  }

  for (uint i{0}; i < input.size(); i++) {
    std::cout << input[i] << ": ";
    if (tm.Test(input[i])) {
      std::cout << "Aceptada" << std::endl;
    } else {
      std::cout << "Rechazada" << std::endl;
    }
    for (int i{0}; i < tm.GetNumberOfTapes(); ++i) std::cout << "Cinta " << i + 1 << ": " << tm.ToString(i) << std::endl;
    std::cout << std::endl; 
  } 

  return 0;
}

int main (int argc, char** argv) {
  try {
    program(argc, argv);
  } catch (char const* e) {
    std::cerr << e << std::endl;
    return 1;
  }
}