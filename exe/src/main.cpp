#include <iostream>

// Объявляем сигнатуры функций из DLL
extern "C" {
    typedef struct Matrix Matrix;
    Matrix* math_createMatrix(int rows, int cols);
    void math_deleteMatrix(Matrix* m);
    void math_set(Matrix* m, int row, int col, float val); //не нашёл ошибку. Если double ставлю, то 0.
    void math_print(Matrix* m);
}

int main() {
    // Создаём матрицу 3x3 через DLL
    Matrix* m = math_createMatrix(3, 3);
    math_set(m, 0, 0, 1.0);
    math_set(m, 1, 1, 2.0);
    
    math_print(m);  // Выводим матрицу
    
    math_deleteMatrix(m);  // Освобождаем память
    return 0;
}