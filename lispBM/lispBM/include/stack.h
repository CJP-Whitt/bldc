/** \file stack.h */
/*
    Copyright 2019 Joel Svensson        svenssonjoel@yahoo.se

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef STACK_H_
#define STACK_H_


#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "lbm_types.h"

typedef struct {
  lbm_uint* data;
  lbm_uint sp;
  lbm_uint size;
  lbm_uint max_sp;
} lbm_stack_t;

/** Allocate a stack on the symbols and arrays memory.
 *  lbm_memory_init must have been run before this function or it will fail.
 * \param s Pointer to an lbm_stack_t to initialize.
 * \param stack_size Size in 32 bit words of stack to allocate.
 * \return 1 on success and 0 on failure.
 */
extern int lbm_stack_allocate(lbm_stack_t *s, lbm_uint stack_size);
/** Create a stack in a statically allocated array.
 *
 * \param s Pointer to an lbm_stack_t to initialize.
 * \param data Pointer to array of 32 bit words to use as the stack storage.
 * \param size Size in number of 32 bit words.
 * \return 1
 */
extern int lbm_stack_create(lbm_stack_t *s, lbm_uint* data, lbm_uint size);
/** Free a stack allocated on the lispbm_memory.
 *
 * \param s Pointer to lbm_stack_t to free.
 */
extern void lbm_stack_free(lbm_stack_t *s);
/** Sets the stack SP to 0.
 *
 * \param s Stack to clear.
 * \return 1
 */
extern int lbm_stack_clear(lbm_stack_t *s);
/** Get a pointer to the nth element (from the top) of a stack.
 *
 * \param s Stack.
 * \param n Index.
 * \return Pointer into the stack or NULL.
 */
extern lbm_uint *lbm_get_stack_ptr(lbm_stack_t *s, lbm_uint n);
/** Drop n elements (from the top) of a stack.
 *
 * \param s Stack to drop elements from.
 * \param n Number of elements to drop.
 * \return 1 on Success and 0 on failure.
 */
extern int lbm_stack_drop(lbm_stack_t *s, lbm_uint n);
/** Push an element onto a stack.
 *
 * \param s Stack to push a value onto.
 * \param val Value to push to the stack.
 * \return 1 on success and 0 on failure (stack is full).
 */
extern int lbm_push(lbm_stack_t *s, lbm_uint val);
/** Pop a value from a stack.
 *
 * \param s Stack to pop a value from.
 * \param val Pointer to an lbm_value to store the pop:ed value int.
 * \return 1 on success and 0 on failure (stack is empty).
 */
extern int lbm_pop(lbm_stack_t *s, lbm_uint *val);

/** Check if a stack is empty.
 *
 * \param s Stack to check.
 * \return 1 if stack is empty otherwise 0.
 */
static inline int lbm_stack_is_empty(lbm_stack_t *s) {
  if (s->sp == 0) return 1;
  return 0;
}

/** Push 2 values to a stack.
 *
 * \param s Stack to push values onto.
 * \param val0 Is pushed first.
 * \param val1 Is pushed last.
 * \return 1 on success and 0 on failure (stack is full).
 */
static inline int lbm_push_2(lbm_stack_t *s, lbm_uint val0, lbm_uint val1) {
  int res = 1;
  res &= lbm_push(s,val0);
  res &= lbm_push(s,val1);
  return res;
}

/** Push 3 values to a stack.
 *
 * \param s Stack to push values onto.
 * \param val0
 * \param val1
 * \param val2
 * \return 1 on success and 0 on failure (stack is full).
 */
static inline int lbm_push_3(lbm_stack_t *s, lbm_uint val0, lbm_uint val1, lbm_uint val2) {
  int res = 1;
  res &= lbm_push(s,val0);
  res &= lbm_push(s,val1);
  res &= lbm_push(s,val2);
  return res;
}

/** Push 4 values to a stack.
 *
 * \param s Stack to push values onto.
 * \param val0
 * \param val1
 * \param val2
 * \param val3
 * \return 1 on success and 0 on failure (stack is full).
 */
static inline int lbm_push_4(lbm_stack_t *s, lbm_uint val0, lbm_uint val1, lbm_uint val2, lbm_uint val3) {
  int res = 1;
  res &= lbm_push(s,val0);
  res &= lbm_push(s,val1);
  res &= lbm_push(s,val2);
  res &= lbm_push(s,val3);
  return res;
}

/** Push 5 values to a stack.
 *
 * \param s Stack to push values onto.
 * \param val0
 * \param val1
 * \param val2
 * \param val3
 * \param val4
 * \return 1 on success and 0 on failure (stack is full).
 */
static inline int lbm_push_5(lbm_stack_t *s, lbm_uint val0, lbm_uint val1, lbm_uint val2, lbm_uint val3, lbm_uint val4) {
  int res = 1;
  res &= lbm_push(s,val0);
  res &= lbm_push(s,val1);
  res &= lbm_push(s,val2);
  res &= lbm_push(s,val3);
  res &= lbm_push(s,val4);
  return res;
}

/** Pop 2 values from a stack.
 *
 * \param s Stack to pop values from.
 * \param r0 Pointer to lbm_value where the first pop:ed value will be stored.
 * \param r1 Pointer to lbm_value where the seconds pop:ed value will be stored.
 * \return 1 on success and 0 on failure (stack is empty).
 */
static inline int lbm_pop_2(lbm_stack_t *s, lbm_uint *r0, lbm_uint *r1) {
  int res = 1;
  res &= lbm_pop(s, r0);
  res &= lbm_pop(s, r1);
  return res;
}

/** Pop 3 values from a stack.
 *
 * \param s Stack to pop values from.
 * \param r0
 * \param r1
 * \param r2
 * \return 1 on success and 0 on failure (stack is empty).
 */
static inline int lbm_pop_3(lbm_stack_t *s, lbm_uint *r0, lbm_uint *r1, lbm_uint *r2) {
  int res = 1;
  res &= lbm_pop(s, r0);
  res &= lbm_pop(s, r1);
  res &= lbm_pop(s, r2);
  return res;
}

/** Pop 4 values from a stack.
 *
 * \param s Stack to pop values from.
 * \param r0
 * \param r1
 * \param r2
 * \param r3
 * \return 1 on success and 0 on failure (stack is empty).
 */
static inline int lbm_pop_4(lbm_stack_t *s, lbm_uint *r0, lbm_uint *r1, lbm_uint *r2, lbm_uint *r3) {
  int res = 1;
  res &= lbm_pop(s, r0);
  res &= lbm_pop(s, r1);
  res &= lbm_pop(s, r2);
  res &= lbm_pop(s, r3);
  return res;
}

/** Pop 5 values from a stack.
 *
 * \param s Stack to pop values from.
 * \param r0
 * \param r1
 * \param r2
 * \param r3
 * \param r4
 * \return 1 on success and 0 on failure (stack is empty).
 */
static inline int lbm_pop_5(lbm_stack_t *s, lbm_uint *r0, lbm_uint *r1, lbm_uint *r2, lbm_uint *r3, lbm_uint *r4) {
  int res = 1;
  res &= lbm_pop(s, r0);
  res &= lbm_pop(s, r1);
  res &= lbm_pop(s, r2);
  res &= lbm_pop(s, r3);
  res &= lbm_pop(s, r4);
  return res;
}


#endif
