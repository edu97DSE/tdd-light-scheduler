/*!
 * @file
 * @brief Implementation of time source test double.
 *
 * Copyright GE Appliances - Confidential - All rights reserved
 */

#include "TimeSource_TestDouble.h"
#include "utils.h"

static TimeSourceTickCount_t GetTicks(I_TimeSource_t *_instance)
{
   REINTERPRET(instance, _instance, TimeSource_TestDouble_t *);

   if(instance->_private.autoIncrementTicks > 0)
   {
      instance->_private.autoIncrementTicks--;
      return instance->_private.ticks++;
   }
   else
   {
      return instance->_private.ticks;
   }
}

static const I_TimeSource_Api_t timeSourceApi =
   { GetTicks };

void TimeSource_TestDouble_Init(TimeSource_TestDouble_t *instance)
{
   instance->interface.api = &timeSourceApi;
   instance->_private.ticks = 0;
   instance->_private.autoIncrementTicks = 0;
}

void TimeSource_TestDouble_SetTicks(TimeSource_TestDouble_t *instance, const TimeSourceTickCount_t ticks)
{
   instance->_private.ticks = ticks;
}

void TimeSource_TestDouble_TickOnce(TimeSource_TestDouble_t *instance)
{
   instance->_private.ticks += 1;
}

void TimeSource_TestDouble_TickMany(TimeSource_TestDouble_t *instance, const TimeSourceTickCount_t ticks)
{
   instance->_private.ticks += ticks;
}

void TimeSource_TestDouble_EnableAutoIncrement(TimeSource_TestDouble_t *instance, TimeSourceTickCount_t howMany)
{
   instance->_private.autoIncrementTicks = howMany;
}

void TimeSource_TestDouble_DisableAutoIncrement(TimeSource_TestDouble_t *instance)
{
   instance->_private.autoIncrementTicks = 0;
}
