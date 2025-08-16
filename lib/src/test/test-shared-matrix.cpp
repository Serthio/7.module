#include <src/matrix.h>
#include <iostream>
#include <src/export.h>

struct Matrix;

#ifdef __cplusplus
extern "C"
{
#endif
    extern Matrix *MATRIXLIB_EXPORT math_createMatrix(int, int);
    extern void MATRIXLIB_EXPORT math_deleteMatrix(Matrix*);
    extern double MATRIXLIB_EXPORT math_get(Matrix*, int, int);
    extern void MATRIXLIB_EXPORT math_set(Matrix*, int, int, float); //не нашёл причину почему с double не работает
    extern void MATRIXLIB_EXPORT math_print(Matrix*);
#ifdef __cplusplus
}
#endif 

int main()
{

    Matrix *m = math_createMatrix(3, 3);

    math_set(m, 0, 0, 1.);
    math_set(m, 1, 1, 1.);
    math_print(m);

    // в конце обязательно вызываем деструктор
    math_deleteMatrix(m);

    return 0;
}