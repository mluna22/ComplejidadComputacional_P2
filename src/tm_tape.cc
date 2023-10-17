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
  front_tape_.resize(input.size());
  for (uint i = 0; i < input.size(); i++) {
    front_tape_[i] = input[i];
  }
}

TmTape::~TmTape() {}

void TmTape::SetBlank(char blank) {
  blank_ = blank;
}

void TmTape::SetInput(std::string input) {
  back_tape_.clear();
  front_tape_.resize(input.size());
  for (uint i = 0; i < input.size(); i++) {
    front_tape_[i] = input[i];
  }
}

char TmTape::Read() {
  return head_ < 0 ? back_tape_[~head_] : front_tape_[head_];
}

void TmTape::Write(char symbol) {
  if (head_ < 0) {
    back_tape_[~head_] = symbol;
  } else {
    front_tape_[head_] = symbol;
  }
}

void TmTape::Move(char direction) {
  switch (direction) {
    case 'L':
      head_--;
      if (-head_ > int(back_tape_.size())) {
        back_tape_.push_back(blank_);
      }
      break;
    case 'R':
      head_++;
      if (head_ >= int(front_tape_.size())) {
        front_tape_.push_back(blank_);
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
  front_tape_.clear();
  back_tape_.clear();
}

std::ostream& operator<<(std::ostream& os, TmTape& tape) {
  std::string tape_string{""};
  if (-tape.head_ > int(tape.back_tape_.size())) {
    tape_string += "[.]";
  }
  for (int i = tape.back_tape_.size() - 1; i >= 0; i--) {
    if (i == ~tape.head_) tape_string += "[";
    tape_string += tape.back_tape_[i];
    if (i == ~tape.head_) tape_string += "]";
  }
  for (int i = 0; i < int(tape.front_tape_.size()); i++) {
    if (i == tape.head_) tape_string += "[";
    tape_string += tape.front_tape_[i];
    if (i == tape.head_) tape_string += "]";
  }
  while (tape_string.back() == tape.blank_) {
    tape_string.pop_back();
  }
  while (tape_string.front() == tape.blank_) {
    tape_string.erase(0, 1);
  }
  os << tape_string;
  return os;
}