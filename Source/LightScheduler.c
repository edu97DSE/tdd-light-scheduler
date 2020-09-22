/*!
 * @file
 * @brief Light scheduler implementation.
 */

#include "LightScheduler.h"

void LightScheduler_Init(
   LightScheduler_t *instance,
   I_DigitalOutputGroup_t *lights,
   I_TimeSource_t *timeSource)
{
   instance->_private.lights = lights;
   instance->_private.timeSource = timeSource;
}