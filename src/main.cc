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

#include "tm.h"

int program(int argc, char** argv) {
  
  if (argc < 2) {
    throw "Uso: /mt_simulator <config_file>";
  }

  Tm tm('.');

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