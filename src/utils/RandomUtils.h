#ifndef __RND_UTILS_H_
#define __RND_UTILS_H_

#include <random>

#include "Compatibility.h"
#include "Export.h"
#include "NacosExceptions.h"

/**
 * RandomUtils
 *
 * @author Liu, Hanyu
 * get random buffer from /dev/urandom
 * and helper functions to get random random number
 */

namespace nacos
{
class RandomUtils
{
 private:
  static std::mt19937 _mt;

  static thread_local std::uniform_int_distribution<int> _int_dis;

  static thread_local bool initedForThisThread;

 public:
  static nacos_cli_API size_t getRandomBuffer(void* dest, size_t size);

  /**
   * generates a random number ranges from begin to end (including the begin and
   * the end)
   *
   * @param begin begin of the range (inclusive)
   * @param end   end of the range   (inclusive)
   * @return a long random number
   * @throw (NacosException) if begin >= end
   */
  static nacos_cli_API int random(int begin, int end)
      NACOS_THROW(NacosException);
};
}  // namespace nacos

#endif
