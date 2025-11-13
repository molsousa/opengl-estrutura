#include <GL/gl.h>
#include "../include/util.h"

void form_indices(double m[][3], double n)
{
    multiplicar_indices(m[0], 3, n);
    multiplicar_indices(m[1], 3, n);
    multiplicar_indices(m[2], 3, n);
    multiplicar_indices(m[3], 3, n);
    multiplicar_indices(m[4], 3, n);
    multiplicar_indices(m[5], 3, n);
    multiplicar_indices(m[6], 3, n);
    multiplicar_indices(m[7], 3, n);

    glBegin(GL_LINE_LOOP);

    glVertex3dv(m[0]);
    glVertex3dv(m[1]);
    glVertex3dv(m[2]);
    glVertex3dv(m[3]);

    glEnd();

    glBegin(GL_LINE_LOOP);

    glVertex3dv(m[4]);
    glVertex3dv(m[5]);
    glVertex3dv(m[6]);
    glVertex3dv(m[7]);

    glEnd();

    glBegin(GL_LINE_LOOP);

    glVertex3dv(m[0]);
    glVertex3dv(m[1]);
    glVertex3dv(m[5]);
    glVertex3dv(m[6]);

    glEnd();

    glBegin(GL_LINE_LOOP);

    glVertex3dv(m[3]);
    glVertex3dv(m[2]);
    glVertex3dv(m[4]);
    glVertex3dv(m[7]);

    glEnd();

    glBegin(GL_LINE_LOOP);

    glVertex3f(MAX*n, MIN*n, MIN_DEP*n);
    glVertex3f(MAX*n, MAX*n, MIN_DEP*n);
    glVertex3f(MAX*n, MAX*n, MAX_DEP*n);
    glVertex3f(MAX*n, MIN*n, MAX_DEP*n);

    glEnd();

    glBegin(GL_LINE_LOOP);

    glVertex3f(MAX*n, MIN*n, MIN_DEP*n);
    glVertex3f(MAX*n, MAX*n, MIN_DEP*n);
    glVertex3f(MAX*n, MAX*n, MAX_DEP*n);
    glVertex3f(MAX*n, MIN*n, MAX_DEP*n);

    glEnd();

    glBegin(GL_LINE_LOOP);

    glVertex3f(MAX*3*n, (MIN+MOD_MIN)*n, (MAX_DEP-SEC_MOD_MIN)*n);
    glVertex3f(MAX*3*n, (MIN+MOD_MIN)*n, (MIN_DEP+SEC_MOD_MIN)*n);
    glVertex3f(MAX*4*n, ZERO, ZERO);

    glEnd();

    glBegin(GL_LINE_LOOP);

    glVertex3f(MAX*3*n, (MAX-MOD_MIN)*n, (MAX_DEP-SEC_MOD_MIN)*n);
    glVertex3f(MAX*3*n, (MAX-MOD_MIN)*n, (MIN_DEP+SEC_MOD_MIN)*n);
    glVertex3f(MAX*4*n, ZERO, ZERO);

    glEnd();

    glBegin(GL_LINE_LOOP);

    glVertex3f(MAX*3*n, (MAX-MOD_MIN)*n, (MAX_DEP-SEC_MOD_MIN)*n);
    glVertex3f(MAX*3*n, (MIN+MOD_MIN)*n, (MAX_DEP-SEC_MOD_MIN)*n);
    glVertex3f(MAX*3*n, (MIN+MOD_MIN)*n, (MIN_DEP+SEC_MOD_MIN)*n);
    glVertex3f(MAX*3*n, (MAX-MOD_MIN)*n, (MIN_DEP+SEC_MOD_MIN)*n);

    glEnd();

    glBegin(GL_LINE_LOOP);

    glVertex3f(MAX*1.5*n, (ZERO+TER_MOD_MIN)*n, (MIN_DEP+MOD_MIN)*n);
    glVertex3f(MAX*1.5*n, (ZERO+TER_MOD_MIN)*n, (MAX_DEP-MOD_MIN)*n);
    glVertex3f(MAX*3*n, (ZERO+TER_MOD_MIN)*n, (MAX_DEP-MOD_MIN)*n);
    glVertex3f(MAX*3*n, (ZERO+TER_MOD_MIN)*n, (MIN_DEP+MOD_MIN)*n);

    glEnd();

    glBegin(GL_LINE_LOOP);

    glVertex3f(MAX*1.5*n, (ZERO-TER_MOD_MIN)*n, (MIN_DEP+MOD_MIN)*n);
    glVertex3f(MAX*1.5*n, (ZERO-TER_MOD_MIN)*n, (MAX_DEP-MOD_MIN)*n);
    glVertex3f(MAX*3*n, (ZERO-TER_MOD_MIN)*n, (MAX_DEP-MOD_MIN)*n);
    glVertex3f(MAX*3*n, (ZERO-TER_MOD_MIN)*n, (MIN_DEP+MOD_MIN)*n);

    glEnd();

    dividir_indices(m[0], 3, n);
    dividir_indices(m[1], 3, n);
    dividir_indices(m[2], 3, n);
    dividir_indices(m[3], 3, n);
    dividir_indices(m[4], 3, n);
    dividir_indices(m[5], 3, n);
    dividir_indices(m[6], 3, n);
    dividir_indices(m[7], 3, n);
}

void multiplicar_indices(double* v, int n, double modificador)
{
    register int i;

    for(i = 0; i < n; i++)
        v[i] *= modificador;
}

void dividir_indices(double* v, int n, double modificador)
{
    register int i;

    for(i = 0; i < n; i++)
        v[i] /= modificador;
}
