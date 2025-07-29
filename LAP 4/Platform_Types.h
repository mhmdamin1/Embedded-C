/*
 * Platform_Types.h
 *MOAHMED AMIIN 
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

/* Unsigned  */
typedef unsigned char 					uint8_t;
typedef unsigned short 					uint16_t;
typedef unsigned long 					uint32_t;
typedef unsigned long long 				uint64_t;

/* signed  */
typedef signed char 					sint8_t;
typedef signed short 					sint16_t;
typedef signed long 					sint32_t;
typedef signed long long 				sint64_t;

typedef float 							float32_t;
typedef double 							double64_t;
typedef unsigned char					boolean_t;


/* Volatile */

/* Unsigned  */
typedef volatile uint8_t                vuint8_t;
typedef volatile uint16_t 				vuint16_t;
typedef volatile uint32_t	 			vuint32_t;
typedef volatile uint64_t 				vuint64_t;

/* signed  */
typedef volatile sint8_t 				vsint8_t;
typedef volatile sint16_t 				vsint16_t;
typedef volatile sint32_t				vsint32_t;
typedef volatile sint64_t				vsint64_t;

typedef volatile float 					vfloat32_t;
typedef volatile double 				vdouble64_t;
typedef volatile unsigned char			vboolean_t;

#endif /* PLATFORM_TYPES_H_ */
