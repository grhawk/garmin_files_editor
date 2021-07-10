//
// Created by Riccardo Petraglia on 10.07.21.
//

#include "Position.h"
std::string gar_edit::Position::str() const
{
    return (std::stringstream() << "<Position>{lat: "
        << latitude_
        << " - long: "
        << longitude_ << "}").str();
}
