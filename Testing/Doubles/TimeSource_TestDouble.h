/*!
 * @file
 * @brief Time source that allows manual control of the time. Additionally, this test double allows
 * for the time to be automatically incremented on read.
 *
 * Copyright GE Appliances - Confidential - All rights reserved
 */

#ifndef TIMESOURCE_TESTDOUBLE_H
#define TIMESOURCE_TESTDOUBLE_H

#include <stdbool.h>
#include "I_TimeSource.h"

typedef struct
{
   I_TimeSource_t interface;

   struct
   {
      TimeSourceTickCount_t autoIncrementTicks;
      TimeSourceTickCount_t ticks;
   } _private;
} TimeSource_TestDouble_t;

void TimeSource_TestDouble_Init(TimeSource_TestDouble_t *instance);
void TimeSource_TestDouble_SetTicks(TimeSource_TestDouble_t *instance, const TimeSourceTickCount_t ticks);
void TimeSource_TestDouble_TickOnce(TimeSource_TestDouble_t *instance);
void TimeSource_TestDouble_TickMany(TimeSource_TestDouble_t *instance, const TimeSourceTickCount_t ticks);

/*!
 * Enable auto-increment. This causes the tick count to be incremented by 1 each time it is read.
 * Will auto-increment up to `howMany` times.
 * @param instance The time source test double.
 * @param howMany Maximum amount of times to auto-increment. Defaults to UINT16_MAX.
 */
void TimeSource_TestDouble_EnableAutoIncrement(TimeSource_TestDouble_t *instance, TimeSourceTickCount_t howMany = UINT16_MAX);

/*!
 * Disable auto-increment. This causes the tick count to _not_ be incremented each time it is read.
 * @param instance The time source test double.
 */
void TimeSource_TestDouble_DisableAutoIncrement(TimeSource_TestDouble_t *instance);

#endif
