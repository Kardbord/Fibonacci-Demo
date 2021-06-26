#include "ArgParser.hpp"
#include <sstream>

auto ArgParser::BuildArgParser(int argc, char *argv[]) -> std::unique_ptr<ArgParser> {
  if (argc < 1) return nullptr;
  return std::make_unique<ArgParser>(ArgParser(static_cast<uint32_t>(argc), argv));
}

ArgParser::ArgParser(uint32_t argc, char *argv[]) 
  : m_argv(argv, argv + argc) {}

auto ArgParser::argc() const -> uint32_t {
  return m_argv.size();
}

auto ArgParser::validatePos(const uint32_t pos) const -> void {
  if (pos >= argc()) {
    throw std::out_of_range("Provided pos is out of range: " + std::to_string(pos));
  }
}

auto ArgParser::getArgAsString(const uint32_t pos) const -> std::string {
  validatePos(pos);
  return m_argv.at(pos);
}

auto ArgParser::getArgAsUint32(const uint32_t pos) const -> uint32_t {
  validatePos(pos);
  uint32_t ret = 0;
  if (!(std::istringstream(m_argv.at(pos)) >> ret)) {
    throw std::invalid_argument("Positional argument argv[" + std::to_string(pos) + "]=" + m_argv.at(pos) + " cannot be converted to uint32_t");
  }
  return ret;
}

auto ArgParser::getProgramName() const -> std::string {
  return getArgAsString(0);
}

