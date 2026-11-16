#include <stdio.h>
#include <string.h>
#include <math.h>
#include "funciones.h"


// Validar numeros enteros
int validarEnteroRango(int minimo, int maximo)
{
    int numero = 0;
    int validacion;
    int caracter;
    int entradaValida;

    do
    {
        validacion = scanf("%d", &numero);
        entradaValida = 1;

        while ((caracter = getchar()) != '\n' && caracter != EOF)
        {
            if (caracter != ' ' && caracter != '\t')
            {
                entradaValida = 0;
            }
        }

        if (validacion != 1 || entradaValida == 0 ||
            numero < minimo || numero > maximo)
        {
            printf("ERROR: Ingrese un numero entero entre %d y %d.\n",
                   minimo, maximo);
            printf("Ingrese nuevamente: ");
        }

    } while (validacion != 1 || entradaValida == 0 ||
             numero < minimo || numero > maximo);

    return numero;
}


// Validar numeros decimales positivos
float validarFloatPositivo(void)
{
    float numero = 0;
    int validacion;
    int caracter;
    int entradaValida;

    do
    {
        validacion = scanf("%f", &numero);
        entradaValida = 1;

        while ((caracter = getchar()) != '\n' && caracter != EOF)
        {
            if (caracter != ' ' && caracter != '\t')
            {
                entradaValida = 0;
            }
        }

        if (validacion != 1 || entradaValida == 0 ||
            !isfinite(numero) || numero <= 0)
        {
            printf("ERROR: Ingrese un numero mayor que cero.\n");
            printf("Ingrese nuevamente: ");
        }

    } while (validacion != 1 || entradaValida == 0 ||
             !isfinite(numero) || numero <= 0);

    return numero;
}


// Leer cadenas de caracteres
void leerCadena(char *cadena, int tamanio)
{
    int longitud;
    int caracter;

    do
    {
        if (fgets(cadena, tamanio, stdin) == NULL)
        {
            cadena[0] = '\0';
            return;
        }

        longitud = strlen(cadena);

        if (longitud > 0 && cadena[longitud - 1] == '\n')
        {
            cadena[longitud - 1] = '\0';
        }
        else
        {
            while ((caracter = getchar()) != '\n' && caracter != EOF);
        }

        if (cadena[0] == '\0')
        {
            printf("ERROR: El nombre no puede estar vacio.\n");
            printf("Ingrese nuevamente: ");
        }

    } while (cadena[0] == '\0');
}


// Registrar productos
void registrarProducto(char nombres[][50], int *demanda,
                       float *tiempo, int *recursos, int *totalProductos)
{
    if (*totalProductos >= 5)
    {
        printf("\nERROR: No se pueden registrar mas de 5 productos.\n");
        return;
    }

    printf("\n======= REGISTRAR PRODUCTO =======\n");

    printf("Nombre del producto: ");
    leerCadena(nombres[*totalProductos], 50);

    printf("Cantidad demandada: ");
    demanda[*totalProductos] = validarEnteroRango(0, 1000000);

    printf("Tiempo de fabricacion por unidad (horas): ");
    tiempo[*totalProductos] = validarFloatPositivo();

    printf("Recursos necesarios por unidad: ");
    recursos[*totalProductos] = validarEnteroRango(1, 1000000);

    (*totalProductos)++;

    printf("\nProducto registrado correctamente.\n");
}


// Mostrar productos
void mostrarProductos(char nombres[][50], int *demanda,
                      float *tiempo, int *recursos, int totalProductos)
{
    if (totalProductos == 0)
    {
        printf("\nNo existen productos registrados.\n");
        return;
    }

    printf("\n======= PRODUCTOS REGISTRADOS =======\n");

    for (int i = 0; i < totalProductos; i++)
    {
        printf("\nProducto %d\n", i + 1);
        printf("Nombre: %s\n", nombres[i]);
        printf("Demanda: %d unidades\n", demanda[i]);
        printf("Tiempo por unidad: %.2f horas\n", tiempo[i]);
        printf("Recursos por unidad: %d\n", recursos[i]);
    }
}


// Buscar productos
int buscarProducto(char nombres[][50], int totalProductos)
{
    char nombreBuscar[50];
    int posicion = -1;

    if (totalProductos == 0)
    {
        printf("\nNo existen productos registrados.\n");
        return -1;
    }

    printf("\nIngrese el nombre del producto: ");
    leerCadena(nombreBuscar, 50);

    for (int i = 0; i < totalProductos; i++)
    {
        if (strcmp(nombreBuscar, nombres[i]) == 0)
        {
            posicion = i;
            break;
        }
    }

    if (posicion == -1)
    {
        printf("\nERROR: Producto no encontrado.\n");
    }
    else
    {
        printf("\nProducto encontrado en la posicion %d.\n",
               posicion + 1);
    }

    return posicion;
}


// Editar productos
void editarProducto(char nombres[][50], int *demanda,
                    float *tiempo, int *recursos, int totalProductos)
{
    int posicion;
    int opcion;

    printf("\n======= EDITAR PRODUCTO =======\n");

    posicion = buscarProducto(nombres, totalProductos);

    if (posicion == -1)
    {
        return;
    }

    do
    {
        printf("\n======= OPCIONES DE EDICION =======\n");
        printf("1. Editar nombre\n");
        printf("2. Editar demanda\n");
        printf("3. Editar tiempo de fabricacion\n");
        printf("4. Editar recursos necesarios\n");
        printf("5. Regresar\n");
        printf("Seleccione una opcion: ");

        opcion = validarEnteroRango(1, 5);

        switch (opcion)
        {
        case 1:
            printf("Nuevo nombre: ");
            leerCadena(nombres[posicion], 50);
            printf("Nombre actualizado.\n");
            break;

        case 2:
            printf("Nueva cantidad demandada: ");
            demanda[posicion] = validarEnteroRango(0, 1000000);
            printf("Demanda actualizada.\n");
            break;

        case 3:
            printf("Nuevo tiempo por unidad: ");
            tiempo[posicion] = validarFloatPositivo();
            printf("Tiempo actualizado.\n");
            break;

        case 4:
            printf("Nueva cantidad de recursos por unidad: ");
            recursos[posicion] = validarEnteroRango(1, 1000000);
            printf("Recursos actualizados.\n");
            break;

        case 5:
            printf("Regresando al menu principal.\n");
            break;
        }

    } while (opcion != 5);
}


// Eliminar productos
void eliminarProducto(char nombres[][50], int *demanda,
                      float *tiempo, int *recursos, int *totalProductos)
{
    int posicion;

    printf("\n======= ELIMINAR PRODUCTO =======\n");

    posicion = buscarProducto(nombres, *totalProductos);

    if (posicion == -1)
    {
        return;
    }

    for (int i = posicion; i < *totalProductos - 1; i++)
    {
        strcpy(nombres[i], nombres[i + 1]);
        demanda[i] = demanda[i + 1];
        tiempo[i] = tiempo[i + 1];
        recursos[i] = recursos[i + 1];
    }

    (*totalProductos)--;

    printf("\nProducto eliminado correctamente.\n");
}


// Ingresar disponibilidad
void ingresarDisponibilidad(float *tiempoDisponible,
                            int *recursosDisponibles)
{
    printf("\n======= DISPONIBILIDAD DE FABRICA =======\n");

    printf("Tiempo disponible de produccion (horas): ");
    *tiempoDisponible = validarFloatPositivo();

    printf("Cantidad de recursos disponibles: ");
    *recursosDisponibles = validarEnteroRango(1, 1000000);

    printf("\nDisponibilidad registrada correctamente.\n");
}


// Calcular produccion requerida
void calcularProduccion(int *demanda, float *tiempo,
                        int *recursos, int totalProductos)
{
    float tiempoTotal = 0;
    long long recursosTotales = 0;

    if (totalProductos == 0)
    {
        printf("\nNo existen productos registrados.\n");
        return;
    }

    printf("\n======= CALCULO DE PRODUCCION =======\n");

    for (int i = 0; i < totalProductos; i++)
    {
        float tiempoProducto = demanda[i] * tiempo[i];
        long long recursosProducto = (long long)demanda[i] * recursos[i];

        tiempoTotal += tiempoProducto;
        recursosTotales += recursosProducto;

        printf("\nProducto %d\n", i + 1);
        printf("Tiempo requerido: %.2f horas\n", tiempoProducto);
        printf("Recursos requeridos: %lld\n", recursosProducto);
    }

    printf("\n======= RESULTADOS TOTALES =======\n");
    printf("Tiempo total requerido: %.2f horas\n", tiempoTotal);
    printf("Recursos totales requeridos: %lld\n", recursosTotales);
}


// Verificar cumplimiento de demanda
void verificarProduccion(int *demanda, float *tiempo,
                         int *recursos, int totalProductos,
                         float tiempoDisponible, int recursosDisponibles)
{
    float tiempoTotal = 0;
    long long recursosTotales = 0;

    if (totalProductos == 0)
    {
        printf("\nNo existen productos registrados.\n");
        return;
    }

    if (tiempoDisponible <= 0 || recursosDisponibles <= 0)
    {
        printf("\nERROR: Primero debe ingresar la disponibilidad de la fabrica.\n");
        return;
    }

    for (int i = 0; i < totalProductos; i++)
    {
        tiempoTotal += demanda[i] * tiempo[i];
        recursosTotales += (long long)demanda[i] * recursos[i];
    }

    printf("\n======= VERIFICACION DE PRODUCCION =======\n");

    printf("\nTiempo requerido: %.2f horas\n", tiempoTotal);
    printf("Tiempo disponible: %.2f horas\n", tiempoDisponible);

    printf("\nRecursos requeridos: %lld\n", recursosTotales);
    printf("Recursos disponibles: %d\n", recursosDisponibles);

    if (tiempoTotal <= tiempoDisponible &&
        recursosTotales <= recursosDisponibles)
    {
        printf("\nRESULTADO: La fabrica SI puede cumplir con la demanda.\n");
    }
    else
    {
        printf("\nRESULTADO: La fabrica NO puede cumplir con la demanda.\n");

        if (tiempoTotal > tiempoDisponible)
        {
            printf("Tiempo faltante: %.2f horas\n",
                   tiempoTotal - tiempoDisponible);
        }

        if (recursosTotales > recursosDisponibles)
        {
            printf("Recursos faltantes: %lld\n",
                   recursosTotales - recursosDisponibles);
        }
    }
}