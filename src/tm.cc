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

#include "tm.h"

Tm::Tm(char blank = '.') {
  tape_.SetBlank(blank);
  tape_.SetInput("101");
  char input;
  while (true) {
    std::cout << "Cinta actual: " << tape_ << std::endl;
    std::cout << "Escribir?: " << std::endl;
    std::cin >> input;
    tape_.Write(input);
    std::cout << "Dirección?: " << std::endl;
    std::cin >> input;
    tape_.Move(input);
  }
}

Tm::~Tm() {}