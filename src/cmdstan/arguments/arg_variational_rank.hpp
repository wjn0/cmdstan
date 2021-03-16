#ifndef CMDSTAN_ARGUMENTS_VARIATIONAL_RANK_HPP
#define CMDSTAN_ARGUMENTS_VARIATIONAL_RANK_HPP

#include <cmdstan/arguments/singleton_argument.hpp>
#include <boost/lexical_cast.hpp>
#include <string>

namespace cmdstan {

using stan::services::experimental::advi::rank;

class arg_variational_rank : public int_argument {
 public:
  arg_variational_rank() : int_argument() {
    _name = "rank";
    _description = rank::description();
    _validity = "0 <= rank";
    _default = boost::lexical_cast<std::string>(rank::default_value());
    _default_value = rank::default_value();
    _constrained = true;
    _good_value = rank::default_value();
    _bad_value = -1.0;
    _value = rank::default_value();
  }
  bool is_valid(int value) { return value >= 0; }
};
}  // namespace cmdstan
#endif
