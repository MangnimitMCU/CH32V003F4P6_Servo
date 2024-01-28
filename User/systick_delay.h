/*
 * systick_delay.h
 *
 *  Created on: Jan 28, 2567 BE
 *      Author: NamtanSugar
 */

#ifndef __SYSTICK_DELAY_H
#define __SYSTICK_DELAY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ch32v00x.h>

void Delay_Init(void);
void Delay_Us(uint32_t n);
void Delay_Ms(uint32_t n);
#ifdef __cplusplus
}
#endif

#endif /* USER_SYSTICK_DELAY_H_ */
