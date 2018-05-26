/**
 * @file test.h
 *
 * Provides a function for testing the program.
 */
#ifndef TEST_H_
#define TEST_H_

#ifndef SIZE_X
/** Defines the number of colums of the field */
#define SIZE_X	8
#endif
#ifndef SIZE_Y
/** Defines the number of rows of the field */
#define SIZE_Y	8
#endif
#ifndef VERBOSE
/** Defines if output of tests will be verbose */
#define VERBOSE 0
#endif

bool run_full_test(void);

#endif /* TEST_H_ */
