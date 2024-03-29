#include <curl/curl.h>

#include <iostream>
#include <string>

#include "config/config.h"
#include "log/banner.h"
#include "task/param_finding_task.h"
#include "wordlist/wordlist.h"

int main(int argc, char* argv[]) {
  curl_global_init(CURL_GLOBAL_ALL);
  auto config{CreateConfigFromCliArgs(argc, argv)};
  auto wordlist{Wordlist(config.WordlistPath())};

  if (!config.Quiet()) {
    logging::PrintBanner(config, wordlist);
  }

  auto task{ParamFindingTask(config, wordlist)};

  auto params{task.Run()};

  std::cout << "\n🦝 Found " << params.size() << " params:\n";
  for (const auto& param : params) {
    std::cout << "  " << param << '\n';
  }

  curl_global_cleanup();
}