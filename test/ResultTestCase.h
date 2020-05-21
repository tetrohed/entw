#pragma once
#include <Result.h>
#include <TestCase.h>

namespace entw {
class ResultTestCase : public TestCase {
public:
  void include() override {
    it("reports the failed results with reason of failure", [&]() {
      Result result(false, "test", "it had to");
      expect(result.wasSuccessful()).toEqual(false);
      expect(result.asString())
          .toEqual(std::string("[\033[31mfailed\033[0m] test\nit had to"));
    });

    it("reports the success results", [&]() {
      Result result(true, "another test");
      expect(result.wasSuccessful()).toEqual(true);
      expect(result.asString())
          .toEqual(std::string("[\033[32mpassed\033[0m] another test"));
    });
  }
};
} // namespace entw
