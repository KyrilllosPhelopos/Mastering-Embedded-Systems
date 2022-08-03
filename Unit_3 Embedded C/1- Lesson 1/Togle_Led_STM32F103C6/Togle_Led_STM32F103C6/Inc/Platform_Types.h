/*
 * Platform_Types.h
 *
 *  Created on: Aug 3, 2022
 *      Author: phelp
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_


#include <stdio.h>
#include<stdbool.h>
#include <stdlib.h>

/*false=0, true=1*/

typedef unsigned char 			  boolean;
#ifndef FALSE
#define FALSE		((boolean)0)
#endif
#ifndef TRUE
#define TRUE		((boolean)1)
#endif


					/* integer data types */

typedef signed char	              sint8;
typedef unsigned char          	  uint8;
typedef signed short       		  sint16;
typedef unsigned short            uint16;
typedef signed int        	      sint32;
typedef unsigned        	      uint32;
typedef signed long long    	  sint64;
typedef unsigned long long        uint64;

				/* real data types */

typedef float float32;
typedef double float64;

				/* Volatile data types */

typedef volatile int8_t     vint8_t;
typedef volatile uint8_t    vuint8_t;
typedef volatile int16_t    vint16_t;
typedef volatile uint16_t   vuint16_t;
typedef volatile int32_t    vint32_t;
typedef volatile uint32_t   vuint32_t;
typedef volatile int64_t    vint64_t;
typedef volatile uint64_t   vuint64_t;



#endif /* PLATFORM_TYPES_H_ */
