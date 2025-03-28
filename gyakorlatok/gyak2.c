#include <stdio.h>
#include <math.h>  // A trigonometrikus függvényekhez szükséges könyvtár

#define MATRIX_SIZE 3  // 3x3 mátrix, homogén koordinátákhoz
#define MAX_STACK_SIZE 10  // A verem maximális mérete

// Transzformációs mátrixokat tároló verem
double transformation_stack[MAX_STACK_SIZE][MATRIX_SIZE][MATRIX_SIZE];
int stack_top = -1;  // A verem teteje (üres verem esetén -1)

// Mátrix szorzása
void multiply_matrices(double result[MATRIX_SIZE][MATRIX_SIZE],
                       double matrix1[MATRIX_SIZE][MATRIX_SIZE],
                       double matrix2[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < MATRIX_SIZE; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Egységmátrix inicializálása
void init_identity_matrix(double matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            if (i == j)
                matrix[i][j] = 1.0;  // Átlóban 1
            else
                matrix[i][j] = 0.0;  // Minden más elem 0
        }
    }
}

// Mátrix kiírása
void print_matrix(double matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Transzformációs mátrix verem műveletei

// Push művelet: A jelenlegi mátrixot elmentjük a verembe
void push_matrix(double matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    if (stack_top < MAX_STACK_SIZE - 1) {
        stack_top++;
        for (int i = 0; i < MATRIX_SIZE; i++) {
            for (int j = 0; j < MATRIX_SIZE; j++) {
                transformation_stack[stack_top][i][j] = matrix[i][j];
            }
        }
        printf("A matrix elmentve a verembe:\n");
        print_matrix(matrix);
    } else {
        printf("Hiba: A verem tulcsordult!\n");
    }
}

// Pop művelet: A legutóbbi mátrixot visszaállítjuk
void pop_matrix(double matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    if (stack_top >= 0) {
        for (int i = 0; i < MATRIX_SIZE; i++) {
            for (int j = 0; j < MATRIX_SIZE; j++) {
                matrix[i][j] = transformation_stack[stack_top][i][j];
            }
        }
        printf("A legutobbi matrix visszaallitva a verembopl:\n");
        print_matrix(matrix);
        stack_top--;
    } else {
        printf("Hiba: A verem ures!\n");
    }
}

// Skálázás
void scale(double matrix[MATRIX_SIZE][MATRIX_SIZE], double sx, double sy) {
    double scale_matrix[3][3] = {
        {sx, 0, 0},
        {0, sy, 0},
        {0, 0, 1}
    };
    double result[3][3];
    multiply_matrices(result, matrix, scale_matrix);
    // Az eredményt visszarakjuk a mátrixba
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = result[i][j];
        }
    }
}

// Eltolás
void shift(double matrix[MATRIX_SIZE][MATRIX_SIZE], double tx, double ty) {
    double shift_matrix[3][3] = {
        {1, 0, tx},
        {0, 1, ty},
        {0, 0, 1}
    };
    double result[3][3];
    multiply_matrices(result, matrix, shift_matrix);
    // Az eredményt visszarakjuk a mátrixba
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = result[i][j];
        }
    }
}

// Forgatás
void rotate(double matrix[MATRIX_SIZE][MATRIX_SIZE], double angle) {
    double radian = angle * (3.14159265359 / 180.0);  // Átváltás fokból radiánba
    double cos_theta = cos(radian);
    double sin_theta = sin(radian);
    
    double rotation_matrix[3][3] = {
        {cos_theta, -sin_theta, 0},
        {sin_theta, cos_theta, 0},
        {0, 0, 1}
    };
    double result[3][3];
    multiply_matrices(result, matrix, rotation_matrix);
    // Az eredményt visszarakjuk a mátrixba
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = result[i][j];
        }
    }
}

int main() {
    // Mátrixok és pontok inicializálása
    double matrix[3][3];
    double point[3] = {1.0, 2.0, 1.0};  // Homogén koordináták (x, y, 1)

    // Egységmátrix inicializálása
    init_identity_matrix(matrix);
    printf("Egysegmatrix:\n");
    print_matrix(matrix);

    // Push művelet: Elmentjük a jelenlegi mátrixot a verembe
    push_matrix(matrix);

    // Skálázás
    scale(matrix, 2.0, 2.0);  // 2x2-es skálázás
    printf("\nSkalazas:\n");
    print_matrix(matrix);

    // Eltolás
    shift(matrix, 3.0, 4.0);  // Eltolás 3, 4
    printf("\nEltolas:\n");
    print_matrix(matrix);

    // Forgatás
    rotate(matrix, 90.0);  // 90 fokos forgatás
    printf("\nForgatas:\n");
    print_matrix(matrix);

    // Pop művelet: Visszaállítjuk a legutóbb elmentett mátrixot
    pop_matrix(matrix);
    printf("\nVisszaallitott matrix:\n");
    print_matrix(matrix);

    return 0;
}
