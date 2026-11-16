#include <stdio.h>
#include "funciones.h"

int main(void)
{
    char nombres[5][50];
    int demanda[5] = {0};
    float tiempo[5] = {0};
    int recursos[5] = {0};

    int totalProductos = 0;
    int recursosDisponibles = 0;
    float tiempoDisponible = 0;
    int opcion;

    do
    {
        printf("\n======= SISTEMA DE PRODUCCION =======\n");
        printf("1. Registrar producto\n");
        printf("2. Mostrar productos\n");
        printf("3. Editar producto\n");
        printf("4. Eliminar producto\n");
        printf("5. Ingresar recursos y tiempo disponibles\n");
        printf("6. Calcular produccion requerida\n");
        printf("7. Verificar cumplimiento de demanda\n");
        printf("8. Buscar producto\n");
        printf("9. Salir\n");
        printf("Seleccione una opcion: ");

        opcion = validarEnteroRango(1, 9);

        switch (opcion)
        {
        case 1:
            registrarProducto(nombres, demanda, tiempo, recursos, &totalProductos);
            break;

        case 2:
            mostrarProductos(nombres, demanda, tiempo, recursos, totalProductos);
            break;

        case 3:
            editarProducto(nombres, demanda, tiempo, recursos, totalProductos);
            break;

        case 4:
            eliminarProducto(nombres, demanda, tiempo, recursos, &totalProductos);
            break;

        case 5:
            ingresarDisponibilidad(&tiempoDisponible, &recursosDisponibles);
            break;

        case 6:
            calcularProduccion(demanda, tiempo, recursos, totalProductos);
            break;

        case 7:
            verificarProduccion(demanda, tiempo, recursos, totalProductos, tiempoDisponible, recursosDisponibles);
            break;

        case 8:
            buscarProducto(nombres, totalProductos);
            break;

        case 9:
            printf("\nSaliendo del programa...\n");
            break;
        }

    } while (opcion != 9);

    return 0;
}
