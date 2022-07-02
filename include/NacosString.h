#ifndef __NACOS_STRING_H_
#define __NACOS_STRING_H_

#include <sstream>
#include <string>

#include "Export.h"

#define NacosString std::string
#define NULLSTR NacosStringOps::nullstr
#define isNull NacosStringOps::isNullStr

namespace nacos
{
class nacos_cli_API NacosStringOps
{
 public:
  static const NacosString nullstr;

  static bool isNullStr(const NacosString& str);

  template <typename T>
  static NacosString valueOf(T val);

  static const NacosString STR_TRUE;
  static const NacosString STR_FALSE;
};

template <typename T>
NacosString NacosStringOps::valueOf(T val)
{
  std::ostringstream os;
  if (os << val)
  {
    return NacosString(os.str().c_str());
  }

  return NULLSTR;
}

template <>
NacosString NacosStringOps::valueOf<bool>(bool val);

}  // namespace nacos

#endif
