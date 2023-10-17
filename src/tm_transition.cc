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

#include "tm_transition.h"
#include "utils.h"

#include <vector>
#include <set>
#include <algorithm>

TmTransition::TmTransition(std::string transition, int number_of_tapes, 
  const std::vector<std::string>& states,
  const std::set<char>& tape_symbols) {
  std::vector<std::string> transition_split = split(transition, ' ');
  int index = 0;
  // Estado inicial
  state = transition_split[index++];
  if (std::find(states.begin(), states.end(), state) == states.end()) {
    throw "Error: estado de transición no pertenece al conjunto de estados";
  }
  // Símbolos de entrada
  for (int i{0}; i < number_of_tapes; ++i) {
    if (std::find(tape_symbols.begin(), tape_symbols.end(), transition_split[index][0]) == tape_symbols.end()) {
      throw "Error: símbolo de transición no pertenece al alfabeto de cinta";
    }
    read.push_back(transition_split[index++][0]);
  }
  // Estado de transición
  next_state = transition_split[index++];
  if (std::find(states.begin(), states.end(), next_state) == states.end()) {
    throw "Error: estado de transición no pertenece al conjunto de estados";
  }
  // Símbolos de escritura
  for (int i{0}; i < number_of_tapes; ++i) {
    if (std::find(tape_symbols.begin(), tape_symbols.end(), transition_split[index][0]) == tape_symbols.end()) {
      throw "Error: símbolo de transición no pertenece al alfabeto de cinta";
    }
    write.push_back(transition_split[index++][0]);
    if (transition_split[index] != "L" && transition_split[index] != "R" && transition_split[index] != "S") {
      throw "Error: movimiento de transición no válido";
    }
    move.push_back(transition_split[index++][0]);
  }
}

bool TmTransition::IsValid(std::string state, const std::vector<char>& read) {
  if (this->state != state) return false;
  for (uint i{0}; i < read.size(); ++i) {
    if (this->read[i] != read[i]) return false;
  }
  return true;
}

std::string TmTransition::GetNextState() {
  return next_state;
}

std::vector<char> TmTransition::GetWrite() {
  return write;
}

std::vector<char> TmTransition::GetMove() {
  return move;
}