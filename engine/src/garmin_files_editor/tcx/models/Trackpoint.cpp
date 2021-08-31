//
// Created by Riccardo Petraglia on 31.07.21.
//
#include "Trackpoint.h"

gar_edit::Altitude gar_edit::Trackpoint::altitude() const {
  return std::stold(node_.child("AltitudeMeters").child_value());
}
gar_edit::Distance gar_edit::Trackpoint::distance() const {
  return std::stold(node_.child("DistanceMeters").child_value());
}
gar_edit::Hbpm gar_edit::Trackpoint::hbpm() const {
  return std::stoi(node_.child("HeartRateBpm").child("Value").child_value());
}
gar_edit::Speed gar_edit::Trackpoint::speed() const {
  return std::stold(node_.child("Extensions").child("ns3:TPX").child("ns3:Speed").child_value());
}

std::time_t gar_edit::Trackpoint::time() const {
  std::string tmp = node_.child("Time").child_value();

  tm when = parseTimeString(tmp);

  return std::mktime(&when);
}

tm gar_edit::Trackpoint::parseTimeString(const std::string &time_string) {
  std::tm tm = {};
  tm.tm_isdst = -1;

  std::cout << "Incoming: `" << time_string << "`" << std::endl;

//  std::stringstream ss;
//  ss << time_string;
//  ss >> std::get_time(&tm, timeFormat);

if (strptime(time_string.c_str(), timeFormat, &tm) == nullptr) {

//  if (ss.fail()) {
    throw std::runtime_error("Could not convert time: `" + time_string + "`.");
  }
  return tm;
}

