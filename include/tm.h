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
#include "tm_transition.h"

#include <vector>
#include <set>
#include <string>
#include <fstream>

class Tm {
 public:
  Tm(std::string filename, char blank = '.');
  ~Tm();
  bool Test(std::vector<std::string> input, bool verbose = false);
  int GetNumberOfTapes();

 private:
  void transit();
  std::vector<std::string> states_;
  std::set<char> input_symbols_;
  std::set<char> tape_symbols_;
  std::string initial_state_;
  std::string blank_;
  std::vector<std::string> final_states_;
  int number_of_tapes_{0};
  std::vector<TmTransition> transitions_;

  std::vector<TmTape> tapes_;
  std::string current_state_;
};

#endif