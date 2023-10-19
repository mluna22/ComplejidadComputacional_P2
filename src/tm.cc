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
#include "utils.h"

#include <algorithm>

Tm::Tm(std::string filename) {
  std::ifstream file(filename);
  if (!file) throw "Error al abrir el archivo";

  std::string line;
  while (std::getline(file, line)) {
    if (line[0] == '#') continue;
    break;
  }

  // Conjunto de estados
  states_ = split(line, ' ');

  // Alfabeto de entrada
  std::getline(file, line);
  std::vector<std::string> input_symbols = split(line, ' ');
  for (std::string symbol : input_symbols) input_symbols_.insert(symbol[0]);

  // Alfabeto de cinta
  std::getline(file, line);
  std::vector<std::string> tape_symbols = split(line, ' ');
  for (std::string symbol : tape_symbols) tape_symbols_.insert(symbol[0]);

  // Estado inicial
  std::getline(file, line);
  initial_state_ = line;
  if (std::find(states_.begin(), states_.end(), line) == states_.end()) throw "Error: estado inicial no pertenece al conjunto de estados";

  // Simbolo blanco
  std::getline(file, line);
  blank_ = line[0];
  if (tape_symbols_.find(blank_) == tape_symbols_.end()) throw "Error: símbolo blanco no pertenece al alfabeto de cinta";

  // Conjunto de estados finales
  std::getline(file, line);
  final_states_ = split(line, ' ');
  for (std::string state : final_states_) {
    if (std::find(states_.begin(), states_.end(), state) == states_.end()) throw "Error: estado final no pertenece al conjunto de estados";
  }

  // Número de cintas
  std::getline(file, line);
  number_of_tapes_ = std::stoi(line);
  tapes_.resize(number_of_tapes_);
  for (TmTape tape : tapes_) tape.SetBlank(blank_);
  
  // Transiciones
  while (std::getline(file, line)) {
    if (line[0] == '#') continue;
    transitions_.emplace_back(line, number_of_tapes_, states_, tape_symbols_);
  }
}

Tm::~Tm() {}

bool Tm::Test(std::string input) {
  for (int i{0}; i < number_of_tapes_; ++i) {
    tapes_[i].Reset();
    
  }
  tapes_[0].SetInput(input);

  current_state_ = initial_state_;
  bool remaining_transitions{true};
  while (remaining_transitions) {
    remaining_transitions = false;
    for (TmTransition transition: transitions_) {
      std::vector<char> read;
      for (int i{0}; i < number_of_tapes_; ++i) read.push_back(tapes_[i].Read());
      if (transition.IsValid(current_state_, read)) {
        current_state_ = transition.GetNextState();
        std::vector<char> write = transition.GetWrite();
        std::vector<char> move = transition.GetMove();
        for (int i{0}; i < number_of_tapes_; ++i) {
          tapes_[i].Write(write[i]);
          tapes_[i].Move(move[i]);
        }
        remaining_transitions = true;
        break;
      }
    }
  }

  return std::find(final_states_.begin(), final_states_.end(), current_state_) != final_states_.end();
}

int Tm::GetNumberOfTapes() {
  return number_of_tapes_;
}

std::string Tm::ToString(int index) {
  return tapes_[index].ToString();
}