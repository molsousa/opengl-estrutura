#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

#define ZERO 0.0f

#define MIN -0.1f
#define MAX 0.1f

#define MAX_DEP 0.08f
#define MIN_DEP -0.08f

#define POS_REL 1.1

#define MOD_MIN 0.07
#define SEC_MOD_MIN 0.06
#define TER_MOD_MIN 0.01

#define NUM_INDICE_X 8
#define NUM_INDICE_Y 3

void form_indices(double[][3], double);

void multiplicar_indices(double*, int, double);

void dividir_indices(double*, int, double);

#endif // MATRIZ_H_INCLUDED
