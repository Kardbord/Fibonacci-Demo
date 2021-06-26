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

    auto argc() const -> uint32_t;

    auto getArgAsString(const uint32_t pos) const -> std::string;
    auto getArgAsUint32(const uint32_t pos) const -> uint32_t;

    auto getProgramName() const -> std::string;

  private:
    ArgParser(uint32_t argc, char *argv[]);
    auto validatePos(const uint32_t pos) const -> void;

    std::vector<std::string> m_argv{};
};

#endif
