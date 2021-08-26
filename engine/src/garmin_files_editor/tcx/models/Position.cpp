//
// Created by Riccardo Petraglia on 10.07.21.
//

#include "Position.h"

std::string gar_edit::Position::str() const
{
  std::stringstream ss;
  ss <<  std::setprecision(17)
     << "<Position>{lat: "
     << latitude()
     << " - long: "
     << longitude()
     << "}";
  return ss.str();
}
