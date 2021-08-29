//
// Created by Riccardo Petraglia on 10.07.21.
//

#pragma once //GARMIN_FILES_EDITOR_POSITION_H

#include <pugixml.hpp>
#include <string>
#include <iomanip>
#include <sstream>

namespace gar_edit {
typedef long double coordinate;

class Position {
 private:
  const pugi::xml_node* const node_;

 public:
  explicit Position() : node_{nullptr} {};
  explicit Position(const pugi::xml_node& node) : node_{&node} {};
//  Position& operator=(Position copy) {
//    std::swap(node_, copy.node_);
//    return *this;
//  }
  ~Position() = default;
  [[nodiscard]] coordinate latitude() const { return std::stold(node_->child_value("LatitudeDegrees")); }
  [[nodiscard]] coordinate longitude() const { return std::stold(node_->child_value("LongitudeDegrees")); }
  [[nodiscard]] std::string str() const;
};

}