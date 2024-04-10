#ifndef VECTOR_H
#define VECTOR_H

/**
 * The data struct definition for an individual vector object.
 *
 * Definition: A vector is a list of numbers.
 */
struct vector {

   /**
    * Pointer to the vectors items in the chain.
    *
    * Allow you to walk array/object chains.
    *
    * @var void **items.
    */
   void **items;

   /**
    * The maximum amount elements that the vector instance can contain.
    *
    * @var int capacity.
    */
   int capacity;
};

/*
 * Create a new vector object instance.
 *
 * @param const int capacity
 *   The max size of the vector.
 *
 * @return struct vector*
 *   The pointer to the vector instance, otherwise NULL.
 */
struct vector *vector_create(const int capacity);

/**
 * Free the memory associted to a vector object.
 *
 * @param struct vector* object
 *   The vector object to be clean.
 */
void vector_destroy(struct vector *object);

/**
 * Sets the long double value at the specified index in the given vector.
 *
 * @param struct vector* object
 *   The vector object.
 * @param int index
 *   The position to store the given value.
 * @param long double value
 *   The value to store.
 *
 * @return long double*
 *   The pointer to the long double value stored at the given position; otherwise NULL.
 */
long double *vector_setl(struct vector *object, int index, long double value);

/**
 * Gets the long double value stored at the given index in the given vector.
 *
 * @param struct vector* object
 *   The vector object.
 * @param int index
 *   The position to store the given value.
 * @param long double value
 *
 * @return long double*
 *   The pointer to the long double value stored at the given position; otherwise NULL.
 */
long double *vector_getl(struct vector *object, int index);

/*
 * Concatenate two given vectors.
 *
 * Concatenates the elements of one or more vectors together so that the values
 * of one are appended to the end of the previous one.
 *
 * @param struct vector *a
 *   The first vector to concatenate.
 * @param struct vector *b
 *   The second vector to concatenate.
 *
 * @return struct vector*
 *   The pointer to the new vector instance, otherwise NULL.
 */
struct vector *vector_concatenate(struct vector *a, struct vector *b);

/*
 * Apply a user supplied function to every member of an vector.
 *
 * @param struct vector *a
 *   The vector to run through the callback function.
 * @param long double (*callback)(long double)
 *   A callable to run for each element in each array.
 *
 * @return int
 *   Returns 1 if the walk operation succeeded, otherwise 0.
 */
int vector_walk(struct vector *a, long double (*callback)(long double));

#endif

#ifndef VECTOR_ALGEBRAIC_OPERATIONS_H
#define VECTOR_ALGEBRAIC_OPERATIONS_H

/**
 * Vector addition.
 *
 * @param struct vector* a
 *   The first vector object to be added.
 * @param struct vector* b
 *   The second vector object to be added.
 *
 * @return struct vector*
 *   The new vector instance with the sum of the two given vectors; otherwise NULL.
 */
struct vector *vector_add(struct vector *a, struct vector *b);

/**
 * Vector subtraction.
 *
 * @param struct vector* a
 *   The first vector object to be subtracted.
 * @param struct vector* b
 *   The second vector object to be subtracted.
 *
 * @return struct vector*
 *   The new vector instance with the subtraction of the two given vectors; otherwise NULL.
 */
struct vector *vector_sub(struct vector *a, struct vector *b);

/**
 * Vector multiplication: dot product.
 *
 * @param struct vector* a
 *   The first vector object to be multiplied.
 * @param struct vector* b
 *   The second vector object to be multiplied.
 *
 * @return long double*
 *   The pointer to the long double value from the product of two vectors; otherwise NULL.
 */
long double *vector_dot_product(struct vector *a, struct vector *b);

/**
 * Vector multiplication by a scalar.
 *
 * @param long double scalar
 *   The scalar to be multiplied.
 * @param struct vector* a
 *   The second vector object to be multiplied.
 *
 * @return struct vector*
 *   The new vector instance with the multiplication; otherwise NULL.
 */
struct vector *vector_scalar_mul(long double scalar, struct vector *a);

#endif

#ifndef VECTOR_PRINT_H
#define VECTOR_PRINT_H

/**
 * Prints a vector object.
 *
 * @param struct vector* object
 *   The vector object to be print.
 */
void vector_print(struct vector *object);

#endif

#ifndef MATRIX_H
#define MATRIX_H

/**
 * The data struct definition for an individual matrix object.
 *
 * Definition: A matrix, like a vector, is also a collection of numbers.
 * The difference is that a matrix is a table of numbers rather than a list.
 */
struct matrix {

   /**
    * Pointer to the row vectors in the chain.
    *
    * Allow you to walk array/object chains.
    *
    * @var void **items.
    */
   void **items;

   /**
    * The number of rows in the matrix.
    *
    * @var int rows.
    */
   int rows;

   /**
    * The number of columns in the matrix.
    *
    * @var int columns.
    */
   int columns;
};

/*
 * Create a new matrix object instance.
 *
 * @param const int rows
 *   The numer of rows in the matrix.
 * @param const int columns
 *   The numer of columns in the matrix.
 *
 * @return struct matrix*
 *   The pointer to the matrix instance, otherwise NULL.
 */
struct matrix *matrix_create(const int rows, const int columns);

/**
 * Free the memory associted to a matrix object.
 *
 * @param struct matrix* object
 *   The matrix object to be clean.
 */
void matrix_destroy(struct matrix *object);

/**
 * Check if the given positions j and K are valid in the given matrix object.
 *
 * @param struct matrix* object
 *   The matrix object.
 * @param int j
 *   The j position to check.
 * @param int k
 *   The k position to check.
 * @param long double value
 *   The value to store.
 *
 * @return int
 *   Returns 1 if the given positions j and K are valid, otherwise 0.
 */
int matrix_check_boundaries(struct matrix *object, int j, int k);

/**
 * Sets the long double value at the specified index in the given matrix.
 *
 * @param struct matrix* object
 *   The matrix object.
 * @param int j
 *   The j position to store the given value.
 * @param int k
 *   The k position to store the given value.
 * @param long double value
 *   The value to store.
 *
 * @return long double*
 *   The pointer to the long double value stored at the given position; otherwise NULL.
 */
long double *matrix_setl(struct matrix *object, int j, int k, long double value);

/**
 * Gets the long double value stored at the given index in the given matrix.
 *
 * @param struct matrix* object
 *   The matrix object.
 * @param int j
 *   The x position to store the given value.
 * @param int k
 *   The y position to store the given value.
 * @param long double value
 *
 * @return long double*
 *   The pointer to the long double value stored at the given position; otherwise NULL.
 */
long double *matrix_getl(struct matrix *object, int j, int k);

/*
 * Create a new matrix object instance from the given array values.
 *
 *
 * @param long double *array
 *   The pointer to the tip(first) value on the array.
 * @param const int rows
 *   The numer of rows in the matrix.
 * @param const int columns
 *   The numer of columns in the matrix.
 *
 * @return struct matrix*
 *   The pointer to the matrix instance, otherwise NULL.
 */
struct matrix *matrix_from_array(long double *array, const int rows, const int columns);

/**
 * Set the values of the matrix from the given array.
 *
 * @param long double *array
 *   The pointer to the tip(first) value on the array.
 * @param struct matrix* object
 *   The matrix object.
 * @param const int rows
 *   The numer of rows in the matrix.
 * @param const int columns
 *   The numer of columns in the matrix.
 *
 * @return int
 *   Returns 1 if the given positions j and K are valid, otherwise 0.
 */
void matrix_fill_from_array(long double *array, struct matrix *object, const int rows, const int columns);

#endif

#ifndef MATRIX_ALGEBRAIC_OPERATIONS_H
#define MATRIX_ALGEBRAIC_OPERATIONS_H

/**
 * Matrix addition.
 *
 * @param struct matrix* a
 *   The first matrix object to be added.
 * @param struct matrix* b
 *   The second matrix object to be added.
 *
 * @return struct matrix*
 *   The new matrix instance with the sum of the two given matrixes; otherwise NULL.
 */
struct matrix *matrix_add(struct matrix *a, struct matrix *b);

/**
 * Matrix subtraction.
 *
 * @param struct matrix* a
 *   The first matrix object to be subtracted.
 * @param struct matrix* b
 *   The second matrix object to be subtracted.
 *
 * @return struct matrix*
 *   The new matrix instance with the subtraction of the two given matrixes; otherwise NULL.
 */
struct matrix *matrix_sub(struct matrix *a, struct matrix *b);

/**
 * Matrix multiplication.
 *
 * @param struct matrix* a
 *   The first matrix object to be multiplied.
 * @param struct matrix* b
 *   The second matrix object to be multiplied.
 *
 * @return struct matrix*
 *   The new matrix instance with the product of two matrixes; otherwise NULL.
 */
struct matrix *matrix_mul(struct matrix *a, struct matrix *b);

/**
 * Matrix multiplication by a scalar.
 *
 * @param long double scalar
 *   The scalar to be multiplied.
 * @param struct matrix* a
 *   The second matrix object to be multiplied.
 *
 * @return int
 *   Returns 0 when the operation succeeded, otherwise 1.
 */
int matrix_scalar_mul(long double scalar, struct matrix *a);

#endif

#ifndef MATRIX_PRINT_H
#define MATRIX_PRINT_H

/**
 * Prints a matrix object.
 *
 * @param struct matrix* object
 *   The matrix object to be print.
 */
void matrix_print(struct matrix *object);

#endif

#ifndef MATRIX_CASTING_H
#define MATRIX_CASTING_H

/*
 * Convert the given vector into a one column matrix.
 *
 * @param struct vector* a
 *   The vector object to be type casted.
 *
 * @return struct matrix*
 *   The pointer to the new matrix instance, otherwise NULL.
 */
struct matrix *vector_to_matrix(struct vector *a);

#endif