//
// Created by Riccardo Petraglia on 31.07.21.
//

#pragma once //GARMIN_FILES_EDITOR_ENGINE_SRC_GARMIN_FILES_EDITOR_TCX_MODELS_TRACKPOINT_H_

#include <pugixml.hpp>
#include <string>
//#include <iomanip>
//#include <ctime>
//#include <sstream>

#include "Position.h"

namespace gar_edit {

typedef long double Altitude;
typedef long double Distance;
typedef unsigned int Hbpm;
typedef long double Speed;
typedef std::time_t Time;

class Trackpoint {
 private:
  pugi::xml_node node_;
  Position* position_;

 public:
  explicit Trackpoint() : node_{nullptr}, position_{nullptr} {};
  explicit Trackpoint(pugi::xml_node node) : node_{node}, position_{nullptr} {
    position_ = new Position(node_.child("Position"));
  }
  ~Trackpoint() = default; //{ delete position_; }
  Trackpoint(const Trackpoint &) = default;
  Trackpoint& operator=(Trackpoint copy) {
    std::swap(node_, copy.node_);
    std::swap(position_, copy.position_);
    return *this;
  }

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