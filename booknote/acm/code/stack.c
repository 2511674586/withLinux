/**
 * @file stack.c
 * @brief libstack, implements simple stack model for integer type.
 * @author Lumin <cdluminate@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @struct StackNode
 * @brief node used in a stack
 */
struct StackNode {
	int value;                 // value shiped in this node
	struct StackNode * bottom; // next node
};

/**
 * @struct Stack
 * @brief Stack wrapper, holds no actual data.
 */
struct Stack {
	size_t size;               // stack size
	struct StackNode * top;    // top of stack
};

typedef struct Stack Stack;
typedef struct StackNode StackNode;

/**
 * @brief create stack instance, with size 0 and NULL top
 * @param void
 * @return the stack pointer to the new stack.
 */
struct Stack *
StackCreate (void)
{
	struct Stack * s = (struct Stack *) malloc(sizeof(struct Stack));
	if (NULL == s) {
		fprintf(stderr, "E: malloc() failed.\n");
		exit(EXIT_FAILURE);
	}
	s->size = (size_t) 0;
	s->top = (struct StackNode *) NULL;
	return s;
}

/**
 * @brief push a new value into stack
 * @param s is the pointer to the target stack
 * @param i is the number to be pushed into stack
 * @return the pointer to the updated stack
 */
struct Stack *
StackPush (struct Stack * s, int i)
{
	/* TODO: when reached MAX_INT */
	struct StackNode * n = (struct StackNode *) malloc(sizeof(struct StackNode));
	if (NULL == s) {
		fprintf(stderr, "E: malloc() failed.\n");
		exit(EXIT_FAILURE);
	}
	n->value = i;
	n->bottom = s->top;
	s->top = n;
	s->size += 1;
	return s;
}

/**
 * @brief pop the top value from stack
 * @param s is the pointer to the target stack
 * @return the value holded by the top node of stack
 */
int
StackPop (struct Stack * s)
{
	if (0 == s->size) {
		fprintf(stderr, "E: pop() from empty stack.\n");
		exit(EXIT_FAILURE);
	}
	struct StackNode * p = s->top;
	int value = p->value;
	s->top = p->bottom;
	s->size -= 1;
	free(p);
	return value;
}

/**
 * @brief simple program to test the stack implementation
 */
int
main (void)
{
	Stack * s = StackCreate();

	int i;
	for (i = 0; i < 10; i++)
		StackPush(s, i);
	for (i = 0; i < 10; i++)
		printf("%d\n", StackPop(s));

	return 0;
}
