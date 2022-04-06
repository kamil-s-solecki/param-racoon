#pragma once

#include <curl/curl.h>

#include <map>
#include <string>

#include "http/response.h"

class HttpClient {
 private:
  CURL* curl_;

 public:
  HttpClient();
  ~HttpClient();
  Response Get(const std::string& host,
               const std::map<std::string, std::string>& query);

 private:
  static std::string CreateFullUrl(
      const std::string& host, const std::map<std::string, std::string>& query);
  Response CreateResponse();
};