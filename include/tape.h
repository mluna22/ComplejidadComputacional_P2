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

#ifndef TAPE_H
#define TAPE_H

#include <iostream>
#include <string>
#include <vector>

class Tape {
 public:
  Tape();
  void SetInput(std::string input);
  Tape(std::string input);
  ~Tape();
  void Clear();
  char& at(const int);
  char& operator[](const int);
  int size();
  int start();
  void push_back(char symbol);
  void push_front(char symbol);
  void pop_back();
  void pop_front();
 private:
  std::vector<char> positive_tape_;
  std::vector<char> negative_tape_;
};

#endif