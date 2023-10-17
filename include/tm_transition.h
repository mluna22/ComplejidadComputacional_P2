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

#ifndef TM_TRANSITION_H
#define TM_TRANSITION_H

#include <string>
#include <vector>
#include <set>
#include <map>

class TmTransition {
 public:
  TmTransition(std::string transition, int number_of_tapes,
    const std::vector<std::string>& states,
    const std::set<char>& tape_symbols);
    bool IsValid(std::string state, const std::vector<char>& read);
    std::string GetNextState();
    std::vector<char> GetWrite();
    std::vector<char> GetMove();
 private:
  std::string state;
  std::vector<char> read;
  std::string next_state;
  std::vector<char> write;
  std::vector<char> move;
};

#endif // TM_TRANSITION_H