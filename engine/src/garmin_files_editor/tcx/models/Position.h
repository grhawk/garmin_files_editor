//
// Created by Riccardo Petraglia on 10.07.21.
//

#pragma once //GARMIN_FILES_EDITOR_POSITION_H

#include <pugixml.hpp>
#include <iostream>
#include <sstream>
#include <cstdlib>

namespace gar_edit {
typedef long double coordinate;

class Position {
 private:
  pugi::xml_node node_;

 public:
  explicit Position() : node_{nullptr} {};
  explicit Position(pugi::xml_node node) : node_{node} {};
  Position& operator=(Position copy) {
    std::swap(node_, copy.node_);
    return *this;
  }
  ~Position() = default;
  [[nodiscard]] coordinate latitude() const { return std::strtold(node_.child_value("LatitudeDegrees"), nullptr); }
  [[nodiscard]] coordinate longitude() const { return std::strtold(node_.child_value("LongitudeDegrees"), nullptr); }
  [[nodiscard]] std::string str() const;
};

}