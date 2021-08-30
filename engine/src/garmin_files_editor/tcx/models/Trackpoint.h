//
// Created by Riccardo Petraglia on 31.07.21.
//

#pragma once //GARMIN_FILES_EDITOR_ENGINE_SRC_GARMIN_FILES_EDITOR_TCX_MODELS_TRACKPOINT_H_

#include <pugixml.hpp>
#include <string>
#include <iostream>

#include "Position.h"
#include "types.h"

namespace gar_edit {

class Trackpoint {
 private:
  pugi::xml_node node_;
  Position* position_;

 public:
  pugi::xml_node position_node_;
  explicit Trackpoint(pugi::xml_node node) : node_{node}, position_{nullptr} {
    position_node_ = node_.child("Position");
    position_ = new Position(node_.child("Position"));
  }
  ~Trackpoint() = default; //{ delete position_; }
  Trackpoint(const Trackpoint &){std::cout << "USING FORBIDDEN FUNCTION" << std::endl;};
  [[nodiscard]] const Position* position() const { return position_; }
  [[nodiscard]] Altitude altitude() const;
  [[nodiscard]] Distance distance() const;
  [[nodiscard]] Hbpm hbpm() const;
  [[nodiscard]] Speed speed() const;
  [[nodiscard]] Time time() const;

 private:
  [[nodiscard]] static tm parseTimeString(const std::string &time_string) ;
};

}