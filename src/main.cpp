#include <curl/curl.h>

#include <iostream>
#include <string>

#include "config/config.h"
#include "task/param_finding_task.h"
#include "wordlist/wordlist.h"

int main(int argc, char* argv[]) {
  curl_global_init(CURL_GLOBAL_ALL);
  const Config config{CreateConfigFromCliArgs(argc, argv)};
  Wordlist wordlist{config.WordlistPath()};

  std::cout << "🦝 Hello.\n";
  std::cout << "🦝🦝🦝🦝\n";
  std::cout << "🦝 url: " << config.ATarget().Url() << '\n';
  std::cout << "🦝 method: " << config.ATarget().Method() << '\n';
  std::cout << "🦝 wordlist: " << config.WordlistPath() << '\n';
  std::cout << "🦝 words: " << wordlist.Total() << '\n';
  std::cout << "🦝 threads: " << config.Threads() << '\n';
  if (!config.ATarget().Headers().empty()) {
    std::cout << "🦝 headers: ";
    for (const auto& header : config.ATarget().Headers()) {
      std::cout << header << "\n            ";
    }
  }
  if (!config.ATarget().Cookies().empty()) {
    std::cout << "🦝 cookies: " << config.ATarget().Cookies() << '\n';
  }
  if (!config.Match().empty()) {
    std::cout << "🦝 match: " << config.Match() << '\n';
  }
  std::cout << '\n';

  ParamFindingTask task{config, wordlist};

  const auto params{task.Run()};

  for (const auto& param : params) {
    std::cout << "🦝🦝 Found param: " << param << '\n';
  }

  curl_global_cleanup();
}