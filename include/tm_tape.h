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

#include <iostream>
#include <vector>
#include <string>

class TmTape {
 public:
  TmTape();
  TmTape(std::string input);
  ~TmTape();
  void SetBlank(char blank);
  void SetInput(std::string input);
  char Read();
  void Write(char symbol);
  void Move(char direction);
  void Reset();
  friend std::ostream& operator<<(std::ostream& os, TmTape& tape);

 private:
  int head_{0};
  std::vector<char> front_tape_;
  // Si head_ es negativo, se accede a back_tape_ invirtiendo los bits de head_
  // ~head = -head - 1; -1 -> 0, -2 -> 1, ...
  std::vector<char> back_tape_;
  char blank_{'.'};
};

#endif // TM_TAPE_H