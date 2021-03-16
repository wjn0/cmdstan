#ifndef CMDSTAN_ARGUMENTS_VARIATIONAL_LOWRANK_HPP
#define CMDSTAN_ARGUMENTS_VARIATIONAL_LOWRANK_HPP

#include <cmdstan/arguments/categorical_argument.hpp>

namespace cmdstan {

class arg_variational_lowrank : public categorical_argument {
 public:
  arg_variational_lowrank() {
    _name = "lowrank";
    _description = "low-rank covariance";
  }
};
}  // namespace cmdstan
#endif
