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

#include "tm_tape.h"

TmTape::TmTape() {}

TmTape::TmTape(std::string input) {
  SetInput(input);
}

TmTape::~TmTape() {}

void TmTape::SetBlank(char blank) {
  blank_ = blank;
}

char TmTape::Read() {
  return at(head_);
}

void TmTape::Write(char symbol) {
  at(head_) = symbol;
}

void TmTape::Move(char direction) {
  switch (direction) {
    case 'L':
      head_--;
      if (head_ < start()) {
        push_front(blank_);
      }
      break;
    case 'R':
      head_++;
      if (head_ >= start() + size()) {
        push_back(blank_);
      }
      break;
    case 'S':
      break;
    default:
      throw "Error: Dirección de movimiento no válida";
  }
}

void TmTape::Reset() {
  head_ = 0;
  Clear();
}

std::string TmTape::ToString() {
  std::string tape_string{""};
  if (head_ < start()) {
    tape_string += "[.]";
  }
  for (int i = start(); i < start() + size(); i++) {
    if (i == head_) tape_string += "[";
    tape_string += at(i);
    if (i == head_) tape_string += "]";
  }
  while (tape_string.back() == blank_) {
    tape_string.pop_back();
  }
  while (tape_string.front() == blank_) {
    tape_string.erase(0, 1);
  }
  return tape_string;
}

std::ostream& operator<<(std::ostream& os, TmTape& tape) {
  os << tape.ToString();
  return os;
}