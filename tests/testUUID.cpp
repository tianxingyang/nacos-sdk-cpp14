// #include <iostream>

// #include "src/utils/UuidUtils.h"

// using namespace std;
// using namespace nacos;

// bool testUUID()
// {
//   cout << "in function testUUID" << endl;

//   cout << "Generating UUID..." << endl;
//   for (int i = 0; i < 100; i++)
//   {
//     cout << "UUID:" << UuidUtils::generateUuid() << endl;
//   }
//   cout << "test end..." << endl;

//   return true;
// }

// void* UUIDThreadFunc(void* param)
// {
//   Thread* thisThread = *((Thread**)param);
//   for (int i = 0; i < 100; i++)
//   {
//     log_debug("Thread %s UUID: %s\n",
//               thisThread->getThreadName().c_str(),
//               UuidUtils::generateUuid().c_str());
//   }

//   return NULL;
// }

// bool testUUIDMT()
// {
//   cout << "in function testUUIDMT" << endl;

//   cout << "Generating UUID..." << endl;

//   Thread* threads[10] = { NULL };
//   for (int i = 0; i < 10; i++)
//   {
//     NacosString threadName = "UUIDThread-" + NacosStringOps::valueOf(i);
//     threads[i] = new Thread(threadName, UUIDThreadFunc, (void*)&threads[i]);
//     threads[i]->start();
//   }

//   for (int i = 0; i < 10; i++)
//   {
//     threads[i]->join();
//     delete threads[i];
//   }

//   cout << "test end..." << endl;

//   return true;
// }

#include <gtest/gtest.h>

#include "src/utils/UuidUtils.h"

using namespace nacos;

TEST(UTILS_TEST, UUID_TEST)
{
  auto uuid1 = UuidUtils::generateUuid();
  auto uuid2 = UuidUtils::generateUuid();
  EXPECT_STRNE(uuid1.data(), uuid2.data());
}

TEST(UTILS_TEST, UUID_THREAD_TEST)
{
}