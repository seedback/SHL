#pragma once

#include <iostream>
#include <string>

namespace shl {
class NotImplementedException : public std::runtime_error {
 public:
  NotImplementedException() : runtime_error("Not implemented exception.") {}

  NotImplementedException(std::string method_name_or_aditional,
                          bool is_aditional = false)
      : runtime_error(find_method_name_or_aditional(method_name_or_aditional,
                                                    is_aditional)) {}

  NotImplementedException(std::string method_name, std::string class_name)
      : runtime_error("Not implemented exception in method " + method_name +
                      " of class " + class_name + ".") {}

  NotImplementedException(std::string method_name, std::string class_name,
                          std::string aditional)
      : runtime_error("Not implemented exception in method " + method_name +
                      " of class " + class_name + " " + aditional + ".") {}

 private:
  std::string find_method_name_or_aditional(
      std::string method_name_or_aditional, bool is_aditional) {
    if (is_aditional)
      return "Not implemented exception " + method_name_or_aditional + ".";
    return "Not implemented exception in method " + method_name_or_aditional +
           ".";
  }
};
}  // namespace shl
