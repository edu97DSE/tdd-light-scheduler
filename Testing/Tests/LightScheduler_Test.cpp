/*!
 * @file
 * @brief Tests for light scheduler implementation.
 */

extern "C"
{
#include "LightScheduler.h"
}

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "DigitalOutputGroup_Mock.h"
#include "TimeSource_Mock.h"
#include "uassert_test.h"
#include "TimeSource_TestDouble.h"

#define Given

TEST_GROUP(LightScheduler)
{
   LightScheduler_t instance;

   DigitalOutputGroup_Mock_t fakeDigitalOutputGroup;
   TimeSource_TestDouble_t fakeTimeSource;

   void setup()
   {
      DigitalOutputGroup_Mock_Init(&fakeDigitalOutputGroup);
      TimeSource_TestDouble_Init(&fakeTimeSource);
   }

   void teardown()
   {
   }

   void TheModuleIsInitialized(void)
   {
      LightScheduler_Init(
         &instance,
         &fakeDigitalOutputGroup.interface,
         &fakeTimeSource.interface);
   }
};

TEST(LightScheduler, ModuleShouldBeInitialized)
{
   Given TheModuleIsInitialized();
}
