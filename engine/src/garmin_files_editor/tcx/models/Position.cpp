//
// Created by Riccardo Petraglia on 10.07.21.
//

#include <iomanip>
#include "Position.h"

std::string gar_edit::Position::str() const
{
  return (std::stringstream()  <<  std::setprecision(17)
                               << "<Position>{lat: "
                               << latitude()
                               << " - long: "
                               << longitude()
                               << "}").str();
}
