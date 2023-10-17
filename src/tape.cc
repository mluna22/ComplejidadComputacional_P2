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

#include "tape.h"

Tape::Tape() {};

void Tape::SetInput(std::string input) {
  negative_tape_.clear();
  positive_tape_.resize(input.length());
  for (uint i{0}; i < input.length(); ++i) {
    positive_tape_[i] = input[i];
  }
}

Tape::Tape(std::string input) {
  SetInput(input);
}

Tape::~Tape() {}

void Tape::Clear() {
  positive_tape_.clear();
  negative_tape_.clear();
}

// Si el indice es negativo, se accede a negative_tape_ invirtiendo los bits del indice
// ~index = -index - 1; -1 -> 0, -2 -> 1, ...
char& Tape::at(const int index) {
  return index < 0 ? negative_tape_[~index] : positive_tape_[index];
}

char& Tape::operator[](const int index) {
  return at(index);
}

int Tape::size() {
  return positive_tape_.size() + negative_tape_.size();
}

int Tape::start() {
  return -negative_tape_.size();
}

void Tape::push_back(char symbol) {
  positive_tape_.push_back(symbol);
}

void Tape::push_front(char symbol) {
  negative_tape_.push_back(symbol);
}

void Tape::pop_back() {
  positive_tape_.pop_back();
}

void Tape::pop_front() {
  negative_tape_.pop_back();
}