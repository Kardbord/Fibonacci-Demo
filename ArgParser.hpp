#ifndef INPUT_PARSER_HPP
#define INPUT_PARSER_HPP

#include <vector>
#include <string>
#include <memory>

class ArgParser {
  public:
    ArgParser() = delete;
    ~ArgParser() = default;

    static auto BuildArgParser(int argc, char *argv[]) -> std::unique_ptr<ArgParser>;

    auto argc() -> uint32_t;

    auto getArgAsString(uint32_t pos) -> std::string;

    auto getProgramName() -> std::string;

  private:
    ArgParser(uint32_t argc, char *argv[]);

    std::vector<std::string> m_argv{};
};

#endif
