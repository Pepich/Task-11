/**********************************/
/* Benedikt Abel, Justus Faust    */
/* Gruppe: Di08                   */
/* Uebungsblatt: 11, Aufgabe B-22 */
/* Thema: Vektoren                */
/* Version: v1.0.0                */
/* Datum: 20160711                */
/* Status: werks                  */
/**********************************/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum { N = 100 };

double absolute(double x)
{
    return x > 0 ? x : -x;
}

double Norm1(double *v, int l)
{
    double r = 0;
    for (int i = 0; i < l; ++i)
	r += absolute(v[i]);
    return r;
}

double Norm2(double *v, int l)
{
    double r = 0;
    for (int i = 0; i < l; ++i)
	r += v[i]*v[i];
    return sqrt(r);
}

double NormInf(double *v, int l)
{
    double r = 0;
    for (int i = 0; i < l; ++i)
	r = absolute(v[i]) > r ? v[i] : r;
    return r;
}


int main(void)
{
    double v[N];
    srand(time(NULL));
    for (int i = 0; i < N; i++)
	v[i] = (double)rand() / RAND_MAX;

    printf("Norm 1: %f\nNorm 2: %f\nNorm inf: %f\n", Norm1(v, N), Norm2(v, N), NormInf(v, N));
}
