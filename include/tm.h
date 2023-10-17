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

#ifndef TM_H
#define TM_H

#include "tm_tape.h"

#include <vector>
#include <set>
#include <string>

class Tm {
 public:
  Tm(char blank);
  ~Tm();

 private:
  TmTape tape_;
  std::set<char> states_;
  std::set<char> input_symbols_;
  std::set<char> tape_symbols_;
  std::string initial_state_;
  std::set<char> final_states_;
  int number_of_tapes_{0};
  std::vector<std::string> transitions_;
};

#endif