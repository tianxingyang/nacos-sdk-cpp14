//#include <unistd.h>
#include "src/utils/RandomUtils.h"

#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>

#include <cstdlib>
#include <ctime>

namespace nacos
{
thread_local bool RandomUtils::initedForThisThread(false);
thread_local std::uniform_int_distribution<int> RandomUtils::_int_dis{
  std::uniform_int_distribution<int>(0, 1 << 8)
};
std::mt19937 RandomUtils::_mt{ std::mt19937(std::random_device{}()) };

size_t RandomUtils::getRandomBuffer(void* dest, size_t size)
{
  size_t bytes_read = 0;

  for (; bytes_read < size; ++bytes_read)
  {
    ((char*)dest)[bytes_read] = char(_int_dis(_mt));
  }

  return bytes_read;
}

int RandomUtils::random(int begin, int end) NACOS_THROW(NacosException)
{
  // 使用 c11 的 random ，避免旧写法导致的随机数问题
  // sanity check
  if (begin == end || begin > end)
  {
    throw NacosException(NacosException::INVALID_PARAM,
                         "end must be greater than begin");
  }

  return std::uniform_int_distribution<int>(begin, end)(_mt);
}
}  // namespace nacos