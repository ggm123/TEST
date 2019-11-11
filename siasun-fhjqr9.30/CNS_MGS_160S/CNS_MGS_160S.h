/*
 * CNS_MGS_160S.h
 *
 *  Created on: 2019-8-26
 *      Author: siasunggm
 */

#ifndef CNS_MGS_160S_H_
#define CNS_MGS_160S_H_

#include <can.h>
#include <stdint.h>

 typedef struct CNS_MGS_160S
{
	 uint16_t point[16];
}CNS_MGS_160S_t;

extern CNS_MGS_160S_t CNS_MGS_160Sa;

CNS_MGS_160S_t CNS_MGS_160Sa_Analyze_Data();
CNS_MGS_160S_t CNS_MGS_160Sc_Analyze_Data();



#endif /* CNS_MGS_160S_H_ */
