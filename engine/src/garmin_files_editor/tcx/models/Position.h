//
// Created by Riccardo Petraglia on 10.07.21.
//

#pragma once //GARMIN_FILES_EDITOR_POSITION_H

#include <sstream>

typedef long double coordinate;

namespace gar_edit {

class Position {
 private:
  coordinate latitude_;
  coordinate longitude_;

 public:
  Position(coordinate latitude, coordinate longitude) : latitude_{latitude}, longitude_{longitude} {};
  ~Position() = default;
  [[nodiscard]] std::string str() const;
  [[nodiscard]] coordinate latitude() const { return latitude_; }
  [[nodiscard]] coordinate longitude() const {return longitude_; }

};

}