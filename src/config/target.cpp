#include "config/target.h"

#include <string>

std::string Target::Url() const { return url_; }
string_vec_t Target::Headers() const { return headers_; }
std::string Target::Cookies() const { return cookies_; }
std::string Target::Method() const { return method_; }
std::string Target::Data() const { return data_; }
std::string Target::Agent() const { return agent_; }
std::string Target::Proxy() const { return proxy_; }
std::string Target::AbsoluteUri() const { return absolute_uri_; }