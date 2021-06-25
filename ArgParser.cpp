#include "ArgParser.hpp"

auto ArgParser::BuildArgParser(int argc, char *argv[]) -> std::unique_ptr<ArgParser> {
  if (argc < 1) return nullptr;
  return std::make_unique<ArgParser>(ArgParser(static_cast<uint32_t>(argc), argv));
}

ArgParser::ArgParser(uint32_t argc, char *argv[]) 
  : m_argv(argv, argv + argc) {}

auto ArgParser::argc() -> uint32_t {
  return this->m_argv.size();
}

auto ArgParser::getArgAsString(uint32_t pos) -> std::string {
  return this->m_argv.at(pos);
}

auto ArgParser::getProgramName() -> std::string {
  return this->getArgAsString(0);
}

