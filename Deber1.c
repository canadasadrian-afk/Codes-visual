#include <stdio.h>
#include <string.h>

int main() {
    // Variables del producto
    int id;
    char nombre[50];
    int stock = 0;
    float precio_unitario;
    float ganancias_totales = 0;

    // Variables auxiliares
    int opcion;
    int cantidad;
    float descuento;

    printf("REGISTRO INICIAL DEL PRODUCTO \n");
    printf("Ingrese ID del producto: ");
    scanf("%d", &id);
    printf("Ingrese nombre del producto: ");
    setbuf(stdin, NULL); // Limpiar el buffer para leer strings
    fgets(nombre, 50, stdin);
    nombre[strcspn(nombre, "\n")] = 0; // Quitar el salto de linea de fgets
    printf("Ingrese cantidad inicial en stock: ");
    scanf("%d", &stock);
    printf("Ingrese precio unitario: ");
    scanf("%f", &precio_unitario);

    // Menu principal
    do {
        printf("\n\t--- MENU DE GESTION ---\n");
        printf("1. Vender producto\n");
        printf("2. Reabastecer stock\n");
        printf("3. Consultar informacion\n");
        printf("4. Ver ganancias totales\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("\nCantidad a vender: ");
                scanf("%d", &cantidad);

                if (cantidad <= 0) {
                    printf("La cantidad debe ser mayor a cero.\n");
                } else if (cantidad > stock) {
                    printf("Stock insuficiente. Solo quedan %d unidades.\n", stock);
                } else {
                    printf("Ingrese porcentaje de descuento (0-100): ");
                    scanf("%f", &descuento);
                    
                    float precio_final = precio_unitario * (1 - (descuento / 100));
                    float subtotal = cantidad * precio_final;
                    
                    stock -= cantidad;
                    ganancias_totales += subtotal;
                    
                    printf("\tVenta exitosa!\n");
                    printf("\tTotal cobrado: $%.2f\n", subtotal);
                }
                break;

            case 2:
                printf("\nCantidad a agregar al stock: ");
                scanf("%d", &cantidad);
                if (cantidad > 0) {
                    stock += cantidad;
                    printf("\tStock actualizado con exito.\n");
                } else {
                    printf("Ingrese un valor valido.\n");
                }
                break;

            case 3:
                printf("\n\t--- INFORMACION DEL PRODUCTO ---\n");
                printf("ID:\t\t%d\n", id);
                printf("Nombre:\t\t%s\n", nombre);
                printf("Stock:\t\t%d unidades\n", stock);
                printf("Precio Und:\t$%.2f\n", precio_unitario);
                break;

            case 4:
                printf("\n\tGANANCIAS ACUMULADAS: $%.2f\n", ganancias_totales);
                break;

            case 5:
                printf("Saliendo del sistema...\n");
                break;

            default:
                printf("[ERROR] Opcion no valida.\n");
        }
    } while (opcion != 5);

    return 0;
}