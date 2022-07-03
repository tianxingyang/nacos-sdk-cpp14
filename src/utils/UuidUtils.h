#ifndef __UUID_UTILS_H_
#define __UUID_UTILS_H_

#include "Export.h"
#include "NacosString.h"

#define UUID_LEN_BYTES 16

/**
 * UuidUtils
 *
 * @author yzz-ihep
 * Generates UUID from /dev/urandom
 */

namespace nacos
{
class nacos_cli_API UuidUtils
{
 public:
  static NacosString generateUuid();
};
}  // namespace nacos

#endif