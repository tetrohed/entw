#pragma once

#include <functional>
#include <vector>

namespace entw {
class TestCase {
 public:
  TestCase() = default;
  using test = std::function<void(void)>;

  void run();

  void it(test &method);

  virtual void include() = 0;

  virtual void runBeforeEach() = 0;

  virtual void runAfterEach() = 0;

  std::vector<test> testMethods_;
};

} // namespace entw