
#include <stdio.h>

int main()
{
    float notas[5][3];
    float promedio[5];
    float promedioMateria[3];
    float maxEstudiante[5];
    float minEstudiante[5];
    float maxMateria[3];
    float minMateria[3];
    float suma;

    int aprobados[3];
    int reprobados[3];
    int i, j;
    int valido;
    int caracter;

    // 1. INGRESAR CALIFICACIONES
    printf("=== SISTEMA DE CALIFICACIONES ===\n");

    for (i = 0; i < 5; i++)
    {
        printf("\n--- ESTUDIANTE %d ---\n", i + 1);

        for (j = 0; j < 3; j++)
        {
            do
            {
                printf("Ingrese la nota de la materia %d: ", j + 1);

                valido = scanf("%f", &notas[i][j]);

                if (valido != 1)
                {
                    printf("Error: debe ingresar un numero.\n");

                    while ((caracter = getchar()) != '\n' && caracter != EOF)
                    {
                    }
                }
                else if (notas[i][j] < 0 || notas[i][j] > 10)
                {
                    printf("Error: la nota debe estar entre 0 y 10.\n");
                }

            } while (valido != 1 || notas[i][j] < 0 || notas[i][j] > 10);
        }
    }

    // 2. PROMEDIOS POR ESTUDIANTE
    printf("\n=== PROMEDIOS POR ESTUDIANTE ===\n");

    for (i = 0; i < 5; i++)
    {
        suma = 0;

        for (j = 0; j < 3; j++)
        {
            suma = suma + notas[i][j];
        }

        promedio[i] = suma / 3;

        printf("Estudiante %d: %.2f\n", i + 1, promedio[i]);
    }

    // 3. PROMEDIOS POR ASIGNATURA
    printf("\n=== PROMEDIOS POR ASIGNATURA ===\n");

    for (j = 0; j < 3; j++)
    {
        suma = 0;

        for (i = 0; i < 5; i++)
        {
            suma = suma + notas[i][j];
        }

        promedioMateria[j] = suma / 5;

        printf("Materia %d: %.2f\n", j + 1, promedioMateria[j]);
    }

    // 4. MAXIMOS Y MINIMOS POR ESTUDIANTE
    printf("\n=== NOTAS MAXIMAS Y MINIMAS POR ESTUDIANTE ===\n");

    for (i = 0; i < 5; i++)
    {
        maxEstudiante[i] = notas[i][0];
        minEstudiante[i] = notas[i][0];

        for (j = 0; j < 3; j++)
        {
            if (notas[i][j] > maxEstudiante[i])
            {
                maxEstudiante[i] = notas[i][j];
            }

            if (notas[i][j] < minEstudiante[i])
            {
                minEstudiante[i] = notas[i][j];
            }
        }

        printf("Estudiante %d - Maxima: %.2f - Minima: %.2f\n",
               i + 1, maxEstudiante[i], minEstudiante[i]);
    }

    // 5. MAXIMOS Y MINIMOS POR ASIGNATURA
    printf("\n=== NOTAS MAXIMAS Y MINIMAS POR ASIGNATURA ===\n");

    for (j = 0; j < 3; j++)
    {
        maxMateria[j] = notas[0][j];
        minMateria[j] = notas[0][j];

        for (i = 0; i < 5; i++)
        {
            if (notas[i][j] > maxMateria[j])
            {
                maxMateria[j] = notas[i][j];
            }

            if (notas[i][j] < minMateria[j])
            {
                minMateria[j] = notas[i][j];
            }
        }

        printf("Materia %d - Maxima: %.2f - Minima: %.2f\n",
               j + 1, maxMateria[j], minMateria[j]);
    }

    // 6. APROBADOS Y REPROBADOS
    printf("\n=== APROBADOS Y REPROBADOS POR ASIGNATURA ===\n");

    for (j = 0; j < 3; j++)
    {
        aprobados[j] = 0;
        reprobados[j] = 0;

        for (i = 0; i < 5; i++)
        {
            if (notas[i][j] >= 6)
            {
                aprobados[j]++;
            }
            else
            {
                reprobados[j]++;
            }
        }

        printf("Materia %d - Aprobados: %d - Reprobados: %d\n",
               j + 1, aprobados[j], reprobados[j]);
    }

    printf("\n=== FIN DEL PROGRAMA ===\n");

    return 0;
}