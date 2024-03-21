#include <stdio.h>
#include "matrix.h"
#include "matrix_print.h"
#include "matrix_algebraic_operations.h"
#include "matrix_tests.h"

/**
 * Main controller function.
 *
 * @return int
 *   The constant that represent the exit status.
 */
int matrix_tests()
{
   printf("------------ Matrix setters and getters. ------------\n");
   // Create two matrixes of 3 * 3 elements from arrays.
   int rows = 3, columns = 3;

   long double array_a[3][3] = {
       {1, 2, 3},
       {5, 6, 7},
       {9, 10, 11}
   };
   struct matrix *matrix_a = matrix_from_array(&array_a[0][0], rows, columns);

   long double array_b[3][3] = {
       {12, 20, 3},
       {45, 6, 9},
       {9, 5, 11}
   };
   struct matrix *matrix_b = matrix_from_array(&array_b[0][0], rows, columns);

   // Print the Matrix.
   matrix_print(matrix_a);
   matrix_print(matrix_b);

   // Test Scalar multiplication.
   printf("------------ Matrix multiplication by a scalar[4.5]. ------------\n");
   matrix_scalar_mul(4.5, matrix_a);
   matrix_print(matrix_a);

   // Test Matrix addition.
   printf("------------ Matrix addition. ------------\n");
   struct matrix *matrix_c = matrix_add(matrix_a, matrix_b);
   matrix_print(matrix_c);
   
   // Test Matrix subtraction.
   printf("------------ Matrix subtraction. ------------\n");
   struct matrix *matrix_d = matrix_sub(matrix_c, matrix_b);
   matrix_print(matrix_d);

   // Test Matrix multiplication
   printf("------------ Matrix multiplication. ------------\n");
   long double array_e[2][2] = {
       {1, 1},
       {2, 2}
   };
   struct matrix *matrix_e = matrix_from_array(&array_e[0][0], 2, 2);

   long double array_f[2][3] = {
       {1, 1, 1},
       {2, 2, 2}
   };
   struct matrix *matrix_f = matrix_from_array(&array_f[0][0], 2, 3);

   matrix_print(matrix_e);
   matrix_print(matrix_f);
   struct matrix *matrix_g = matrix_mul(matrix_e, matrix_f);
   matrix_print(matrix_g);

   printf("-------------------------------------------\n");

   matrix_print(matrix_a);
   matrix_print(matrix_b);
   struct matrix *matrix_h = matrix_mul(matrix_a, matrix_b);
   matrix_print(matrix_h);

   // Clear the used memory.
   matrix_destroy(matrix_a);
   matrix_destroy(matrix_b);
   matrix_destroy(matrix_c);
   matrix_destroy(matrix_d);
   matrix_destroy(matrix_e);
   matrix_destroy(matrix_f);
   matrix_destroy(matrix_g);
   matrix_destroy(matrix_h);
   // Return success response.
   return 0;
}
