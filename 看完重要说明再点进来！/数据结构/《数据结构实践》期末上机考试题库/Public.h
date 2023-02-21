
#ifndef _PUBLIC_H_
#define _PUBLIC_H_

#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

/*以下是严蔚敏版《数据结构》书中的有关宏定义*/
#define  TRUE  1       
#define  FALSE  0     
#define  OK 1
#define  ERROR 0
#define  INFEASIBLE -1
#define  OVERFLOW -2
typedef int Status;

/*以下是《Fundamentals of Data Structures in C (2nd Edition) 》书中的有关宏定义*/
#define  MAX_SIZE  100  //Chapter 1
#define  SWAP(x,y,t)  ((t) = (x),(x) = (y),(y) = (t)) //Chapter 1
#define  MAX_TERMS  101  //Chapter 2
#define  MAX_POLYS  15   //Chapter 2
#define  MAX_STACK_SIZE 100  //Chapter 3
#define  MAX_QUEUE_SIZE 100  //Chapter 3
#define  MEMORY_SIZE 100 //Chapter 3
#define  MAX_STACKS 10     //Chapter 3
#define  MAX_QUEUES 10     //Chapter 3
#define  IS_EMPTY(first) (!(first))  //Chapter 4
#define  IS_FULL(temp) (!(temp))  //Chapter 4

#define  MAX_ELEMENTS 200   //Chapter 5
#define  HEAP_FULL(n) (n == MAX_ELEMENTS - 1) //Chapter 5
#define  HEAP_EMPTY(n) (!n)   //Chapter 5
#define  MAX_VERTICES  50   //Chapter 6

#define MALLOC(p,s,type)\
	if (!((p) = (type)malloc(s)))\
{\
	fprintf(stderr,"Insufficient memory");\
	exit(EXIT_FAILURE);\
}

#define REALLOC(p,s)\
	if (!(realloc((void*)p,s)))\
	{\
	fprintf(stderr,"Insufficient memory");\
	exit(EXIT_FAILURE);\
	}
#define CALLOC(p,n,s,type)\
	if (!((p) = (type)calloc(n,s)))\
	{\
	fprintf(stderr,"Insufficient memory");\
	exit(EXIT_FAILURE);\
	}
#define  FREE(p)\
	if (p)\
	{ \
	free(p);p = NULL;\
	}

#endif

