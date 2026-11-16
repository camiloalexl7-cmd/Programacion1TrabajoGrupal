int validarEnteroRango(int minimo, int maximo);
float validarFloatPositivo(void);
void leerCadena(char *cadena, int tamanio);

void registrarProducto(char nombres[][50], int *demanda, float *tiempo, int *recursos, int *totalProductos);

void mostrarProductos(char nombres[][50], int *demanda, float *tiempo, int *recursos, int totalProductos);

int buscarProducto(char nombres[][50], int totalProductos);

void editarProducto(char nombres[][50], int *demanda, float *tiempo, int *recursos, int totalProductos);

void eliminarProducto(char nombres[][50], int *demanda, float *tiempo, int *recursos, int *totalProductos);

void ingresarDisponibilidad(float *tiempoDisponible, int *recursosDisponibles);

void calcularProduccion(int *demanda, float *tiempo, int *recursos, int totalProductos);

void verificarProduccion(int *demanda, float *tiempo, int *recursos, int totalProductos, float tiempoDisponible, int recursosDisponibles);