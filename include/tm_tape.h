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

#ifndef TM_TAPE_H
#define TM_TAPE_H

#include "tape.h"

#include <iostream>
#include <vector>
#include <string>

class TmTape : public Tape {
 public:
  TmTape();
  TmTape(std::string input);
  ~TmTape();
  void Reset();
  void SetBlank(char blank);
  char Read();
  void Write(char symbol);
  void Move(char direction);
  std::string ToString();
  friend std::ostream& operator<<(std::ostream& os, TmTape& tape);

 private:
  int head_{0};
  char blank_{'.'};
};

#endif // TM_TAPE_H