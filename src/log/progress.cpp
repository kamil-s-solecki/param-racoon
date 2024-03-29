#include "log/progress.h"

#include <iostream>
#include <string>

namespace logging {

const std::string kEraseLine{"\33[2K\r"};

Progress::Progress(long total) : total_{total} {}

void Progress::Start() {
  current_ = 0;
  PrintProgress();
}

bool Progress::IsDone() const { return done_; }

void Progress::Advance() {
  if (done_) {
    return;
  }
  ++current_;
  std::cout << kEraseLine;
  PrintProgress();
  if (current_ >= total_) {
    done_ = true;
    std::cout << kEraseLine << "Done!\n" << std::flush;
  }
}

void Progress::LogParam(std::string_view param) {
  std::cout << kEraseLine << "🦝🦝 Found param: " << param << '\n'
            << std::flush;
}

void Progress::PrintProgress() const {
  std::cout << "Running: " << current_ << '/' << total_ << std::flush;
}

}  // namespace logging