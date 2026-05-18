#include <stdio.h>

#define N 5
#define MAX_NOM 30

int main() {
    // 1. Declaración de variables y arreglos paralelos
    char nombres[N][MAX_NOM];
    int cantidades[N];
    float tiempos[N], recursos[N];
    
    float t_disponible, r_disponible;
    float t_total = 0.0, r_total = 0.0;

    // 2. Ingreso de datos de los 5 productos
    printf("--- INGRESO DE PRODUCTOS ---\n");
    for (int i = 0; i < N; i++) {
        printf("Producto %d (Nombre, Demanda, Tiempo Unit, Recurso Unit): ", i + 1);
        scanf("%s %d %f %f", *(nombres + i), (cantidades + i), (tiempos + i), (recursos + i));
    }

    // 3. Ingreso de restricciones de la planta
    printf("\n--- RESTRICCIONES DE LA FABRICA ---\n");
    printf("Ingrese Tiempo Total y Recursos Totales disponibles: ");
    scanf("%f %f", &t_disponible, &r_disponible);

    // 4. Procesamiento matemático usando aritmética de punteros
    for (int i = 0; i < N; i++) {
        t_total += (*(cantidades + i)) * (*(tiempos + i));
        r_total += (*(cantidades + i)) * (*(recursos + i));
    }

    // 5. Salida de resultados y diagnóstico de factibilidad
    printf("\n--- DIAGNOSTICO FINAL ---\n");
    printf("Tiempo Requerido: %.2f / %.2f horas\n", t_total, t_disponible);
    printf("Recursos Requeridos: %.2f / %.2f unidades\n", r_total, r_disponible);
    
    if (t_total <= t_disponible && r_total <= r_disponible) {
        printf("RESULTADO: [FACTIBLE] La demanda puede ser cumplida.\n");
    } else {
        printf("RESULTADO: [NO FACTIBLE] Recursos o tiempo insuficientes.\n");
    }

    return 0;
}