#include <stdio.h>
#include <stdlib.h>

int main(){
    int comprar = 0;
    int turistico[15][4];
    int col, fil;
    int carretera[10][4];
    int vagoneta[5][3];
    int destino;
    int transporte;
    int peru;
    printf("Bienvenido, ¿Quieres comprar un boleto?\n si=1\n no=0\n");
    scanf("%i",&peru);
    switch (peru){
        case 1:
            printf("Selecciona un tipo de transporte\n");
            printf("Autobus turistico = 1\n");
            printf("Autobus de carretera = 2\n");
            printf("Vagonetas = 3\n");
            scanf("%i", &transporte);
            switch (transporte) {
                case 1:
                    printf("Selecciona un destino\n");
                    printf("Circuito Historico = 1\n");
                    printf("Tour Gastronomico = 2\n");
                    printf("Parque La Mexicana = 3\n");
                    printf("Universum = 4\n");
                    scanf("%i", &destino);
                    switch (destino) {
                        case 1:
                             // Inicializa la matriz de los asientos
                            for (int i = 0; i < 15; i++) {
                                for (int r = 0; r < 4; r++) {
                                    turistico[r][i] = (r + 1) * 10 + (i + 1);
                                }
                            }
        
                            do {
                            // Muestra los asientos
                            for (int i = 0; i < 15; i++) {
                                for (int r = 0; r < 4; r++) {
                                    if (turistico[r][i] == 0) {
                                        printf("XX\t"); // Marca el asiento con XX
                                    } else {
                                        printf("%d\t", turistico[r][i]);
                                    }
                                }
                                printf("\n");
                            }
        
                            printf("Escoje la fila donde se encuentra el asiento (1-15):\n");
                            scanf("%d", &col);
                            printf("Escoje la columna donde se encuentra el asiento (1-4):\n");
                            scanf("%d", &fil);
        
                            // Verifica que se ingrese un valor valido
                            if (col < 1 || col > 15 || fil < 1 || fil > 4) {
                                printf("Entrada no válida. Inténtalo de nuevo.\n");
                                continue;
                            }
        
                            // Ajuste para la indexación de base cero
                            col--;
                            fil--;
        
                            // Verifica si el asiento esta disponible
                            if (turistico[fil][col] != 0) {
                                printf("Tu numero de asiento es %d\n", turistico[fil][col]);
                                turistico[fil][col] = 0; // Marca si el asiento esta ocupado
                            } else {
                                printf("Asiento ocupado, favor de elegir otro asiento\n");
                            }
        
                            printf("¿Quieres seguir comprando? 0=si 1=no\n");
                            scanf("%d", &comprar);
        
                            if (comprar != 0 && comprar != 1) {
                                printf("Dato no válido.\n");
                                comprar = 1; // Fin del programa si se invalida
                            }
        
                            } while (comprar == 0);
        
                                printf("Gracias por usar el sistema de compra de boletos.\n");
                            break;
                        case 2:
                             // Inicializa la matriz de los asientos
                            for (int i = 0; i < 15; i++) {
                                for (int r = 0; r < 4; r++) {
                                    turistico[r][i] = (r + 1) * 10 + (i + 1);
                                }
                            }
        
                            do {
                            // Muestra los asientos
                            for (int i = 0; i < 15; i++) {
                                for (int r = 0; r < 4; r++) {
                                    if (turistico[r][i] == 0) {
                                        printf("XX\t"); // Marca el asiento con XX
                                    } else {
                                        printf("%d\t", turistico[r][i]);
                                    }
                                }
                                printf("\n");
                            }
        
                            printf("Escoje la fila donde se encuentra el asiento (1-15):\n");
                            scanf("%d", &col);
                            printf("Escoje la columna donde se encuentra el asiento (1-4):\n");
                            scanf("%d", &fil);
        
                            // Verifica que se ingrese un valor valido
                            if (col < 1 || col > 15 || fil < 1 || fil > 4) {
                                printf("Entrada no válida. Inténtalo de nuevo.\n");
                                continue;
                            }
        
                            // Ajuste para la indexación de base cero
                            col--;
                            fil--;
        
                            // Verifica si el asiento esta disponible
                            if (turistico[fil][col] != 0) {
                                printf("Tu numero de asiento es %d\n", turistico[fil][col]);
                                turistico[fil][col] = 0; // Marca si el asiento esta ocupado
                            } else {
                                printf("Asiento ocupado, favor de elegir otro asiento\n");
                            }
        
                            printf("¿Quieres seguir comprando? 0=si 1=no\n");
                            scanf("%d", &comprar);
        
                            if (comprar != 0 && comprar != 1) {
                                printf("Dato no válido.\n");
                                comprar = 1; // Fin del programa si se invalida
                            }
        
                            } while (comprar == 0);
        
                                printf("Gracias por usar el sistema de compra de boletos.\n");
                            break;
                        case 3:
                             // Inicializa la matriz de los asientos
                            for (int i = 0; i < 15; i++) {
                                for (int r = 0; r < 4; r++) {
                                    turistico[r][i] = (r + 1) * 10 + (i + 1);
                                }
                            }
        
                            do {
                            // Muestra los asientos
                            for (int i = 0; i < 15; i++) {
                                for (int r = 0; r < 4; r++) {
                                    if (turistico[r][i] == 0) {
                                        printf("XX\t"); // Marca el asiento con XX
                                    } else {
                                        printf("%d\t", turistico[r][i]);
                                    }
                                }
                                printf("\n");
                            }
        
                            printf("Escoje la fila donde se encuentra el asiento (1-15):\n");
                            scanf("%d", &col);
                            printf("Escoje la columna donde se encuentra el asiento (1-4):\n");
                            scanf("%d", &fil);
        
                            // Verifica que se ingrese un valor valido
                            if (col < 1 || col > 15 || fil < 1 || fil > 4) {
                                printf("Entrada no válida. Inténtalo de nuevo.\n");
                                continue;
                            }
        
                            // Ajuste para la indexación de base cero
                            col--;
                            fil--;
        
                            // Verifica si el asiento esta disponible
                            if (turistico[fil][col] != 0) {
                                printf("Tu numero de asiento es %d\n", turistico[fil][col]);
                                turistico[fil][col] = 0; // Marca si el asiento esta ocupado
                            } else {
                                printf("Asiento ocupado, favor de elegir otro asiento\n");
                            }
        
                            printf("¿Quieres seguir comprando? 0=si 1=no\n");
                            scanf("%d", &comprar);
        
                            if (comprar != 0 && comprar != 1) {
                                printf("Dato no válido.\n");
                                comprar = 1; // Fin del programa si se invalida
                            }
        
                            } while (comprar == 0);
        
                                printf("Gracias por usar el sistema de compra de boletos.\n");
                            break;
                        case 4:
                             // Inicializa la matriz de los asientos
                            for (int i = 0; i < 15; i++) {
                                for (int r = 0; r < 4; r++) {
                                    turistico[r][i] = (r + 1) * 10 + (i + 1);
                                }
                            }
        
                            do {
                            // Muestra los asientos
                            for (int i = 0; i < 15; i++) {
                                for (int r = 0; r < 4; r++) {
                                    if (turistico[r][i] == 0) {
                                        printf("XX\t"); // Marca el asiento con XX
                                    } else {
                                        printf("%d\t", turistico[r][i]);
                                    }
                                }
                                printf("\n");
                            }
        
                            printf("Escoje la fila donde se encuentra el asiento (1-15):\n");
                            scanf("%d", &col);
                            printf("Escoje la columna donde se encuentra el asiento (1-4):\n");
                            scanf("%d", &fil);
        
                            // Verifica que se ingrese un valor valido
                            if (col < 1 || col > 15 || fil < 1 || fil > 4) {
                                printf("Entrada no válida. Inténtalo de nuevo.\n");
                                continue;
                            }
        
                            // Ajuste para la indexación de base cero
                            col--;
                            fil--;
        
                            // Verifica si el asiento esta disponible
                            if (turistico[fil][col] != 0) {
                                printf("Tu numero de asiento es %d\n", turistico[fil][col]);
                                turistico[fil][col] = 0; // Marca si el asiento esta ocupado
                            } else {
                                printf("Asiento ocupado, favor de elegir otro asiento\n");
                            }
        
                            printf("¿Quieres seguir comprando? 0=si 1=no\n");
                            scanf("%d", &comprar);
        
                            if (comprar != 0 && comprar != 1) {
                                printf("Dato no válido.\n");
                                comprar = 1; // Fin del programa si se invalida
                            }
        
                            } while (comprar == 0);
        
                                printf("Gracias por usar el sistema de compra de boletos.\n");
                            break;
                        default:
                            printf("Ya w no tenemos tours al gigante de chimalhuacan deja de cagar el palo");
                    }
                    break;
                case 2:
                    printf("Selecciona un destino\n");
                    printf("CDMX-Puebla = 1\n");
                    printf("CDMX-Queretaro = 2\n");
                    printf("CDMX-Hidaldo = 3\n");
                    scanf("%i", &destino);
                    switch (destino) {
                        case 1:
                             // Inicializa la matriz de los asientos
                            for (int i = 0; i < 10; i++) {
                                for (int r = 0; r < 4; r++) {
                                    carretera[r][i] = (r + 1) * 10 + (i + 1);
                                }
                            }
        
                            do {
                            // Muestra los asientos
                            for (int i = 0; i < 10; i++) {
                                for (int r = 0; r < 4; r++) {
                                    if (carretera[r][i] == 0) {
                                        printf("XX\t"); // Marca el asiento con XX
                                    } else {
                                        printf("%d\t", carretera[r][i]);
                                    }
                                }
                                printf("\n");
                            }
        
                            printf("Escoje la fila donde se encuentra el asiento (1-10):\n");
                            scanf("%d", &col);
                            printf("Escoje la columna donde se encuentra el asiento (1-4):\n");
                            scanf("%d", &fil);
        
                            // Verifica que se ingrese un valor valido
                            if (col < 1 || col > 10 || fil < 1 || fil > 4) {
                                printf("Entrada no válida. Inténtalo de nuevo.\n");
                                continue;
                            }
        
                            // Ajuste para la indexación de base cero
                            col--;
                            fil--;
        
                            // Verifica si el asiento esta disponible
                            if (carretera[fil][col] != 0) {
                                printf("Tu numero de asiento es %d\n", carretera[fil][col]);
                                carretera[fil][col] = 0; // Marca si el asiento esta ocupado
                            } else {
                                printf("Asiento ocupado, favor de elegir otro asiento\n");
                            }
        
                            printf("¿Quieres seguir comprando? 0=si 1=no\n");
                            scanf("%d", &comprar);
        
                            if (comprar != 0 && comprar != 1) {
                                printf("Dato no válido.\n");
                                comprar = 1; // Fin del programa si se invalida
                            }
        
                            } while (comprar == 0);
        
                                printf("Gracias por usar el sistema de compra de boletos.\n");
                            break;
                        case 2:
                             // Inicializa la matriz de los asientos
                            for (int i = 0; i < 10; i++) {
                                for (int r = 0; r < 4; r++) {
                                    carretera[r][i] = (r + 1) * 10 + (i + 1);
                                }
                            }
        
                            do {
                            // Muestra los asientos
                            for (int i = 0; i < 10; i++) {
                                for (int r = 0; r < 4; r++) {
                                    if (carretera[r][i] == 0) {
                                        printf("XX\t"); // Marca el asiento con XX
                                    } else {
                                        printf("%d\t", carretera[r][i]);
                                    }
                                }
                                printf("\n");
                            }
        
                            printf("Escoje la fila donde se encuentra el asiento (1-10):\n");
                            scanf("%d", &col);
                            printf("Escoje la columna donde se encuentra el asiento (1-4):\n");
                            scanf("%d", &fil);
        
                            // Verifica que se ingrese un valor valido
                            if (col < 1 || col > 10 || fil < 1 || fil > 4) {
                                printf("Entrada no válida. Inténtalo de nuevo.\n");
                                continue;
                            }
        
                            // Ajuste para la indexación de base cero
                            col--;
                            fil--;
        
                            // Verifica si el asiento esta disponible
                            if (carretera[fil][col] != 0) {
                                printf("Tu numero de asiento es %d\n", carretera[fil][col]);
                                carretera[fil][col] = 0; // Marca si el asiento esta ocupado
                            } else {
                                printf("Asiento ocupado, favor de elegir otro asiento\n");
                            }
        
                            printf("¿Quieres seguir comprando? 0=si 1=no\n");
                            scanf("%d", &comprar);
        
                            if (comprar != 0 && comprar != 1) {
                                printf("Dato no válido.\n");
                                comprar = 1; // Fin del programa si se invalida
                            }
        
                            } while (comprar == 0);
        
                                printf("Gracias por usar el sistema de compra de boletos.\n");
                            break;
                        case 3:
                             // Inicializa la matriz de los asientos
                            for (int i = 0; i < 10; i++) {
                                for (int r = 0; r < 4; r++) {
                                    carretera[r][i] = (r + 1) * 10 + (i + 1);
                                }
                            }
        
                            do {
                            // Muestra los asientos
                            for (int i = 0; i < 10; i++) {
                                for (int r = 0; r < 4; r++) {
                                    if (carretera[r][i] == 0) {
                                        printf("XX\t"); // Marca el asiento con XX
                                    } else {
                                        printf("%d\t", carretera[r][i]);
                                    }
                                }
                                printf("\n");
                            }
        
                            printf("Escoje la fila donde se encuentra el asiento (1-10):\n");
                            scanf("%d", &col);
                            printf("Escoje la columna donde se encuentra el asiento (1-4):\n");
                            scanf("%d", &fil);
        
                            // Verifica que se ingrese un valor valido
                            if (col < 1 || col > 10 || fil < 1 || fil > 4) {
                                printf("Entrada no válida. Inténtalo de nuevo.\n");
                                continue;
                            }
        
                            // Ajuste para la indexación de base cero
                            col--;
                            fil--;
        
                            // Verifica si el asiento esta disponible
                            if (carretera[fil][col] != 0) {
                                printf("Tu numero de asiento es %d\n", carretera[fil][col]);
                                carretera[fil][col] = 0; // Marca si el asiento esta ocupado
                            } else {
                                printf("Asiento ocupado, favor de elegir otro asiento\n");
                            }
        
                            printf("¿Quieres seguir comprando? 0=si 1=no\n");
                            scanf("%d", &comprar);
        
                            if (comprar != 0 && comprar != 1) {
                                printf("Dato no válido.\n");
                                comprar = 1; // Fin del programa si se invalida
                            }
        
                            } while (comprar == 0);
        
                                printf("Gracias por usar el sistema de compra de boletos.\n");
                            break;
                        default:
                            printf("No patricio no tenemos autobuses a tecamachalco ni a tlajomulco");
                    }
                    break;
                case 3:
                    printf("Selecciona un destino\n");
                    printf("CDMX-Tepoztlan = 1\n");
                    printf("CDMX-Valle de Bravo = 2\n");
                    scanf("%i", &destino);
                    switch (destino) {
                        case 1:
                             // Inicializa la matriz de los asientos
                            for (int i = 0; i < 5; i++) {
                                for (int r = 0; r < 3; r++) {
                                    vagoneta[r][i] = (r + 1) * 10 + (i + 1);
                                }
                            }
        
                            do {
                            // Muestra los asientos
                            for (int i = 0; i < 5; i++) {
                                for (int r = 0; r < 3; r++) {
                                    if (vagoneta[r][i] == 0) {
                                        printf("XX\t"); // Marca el asiento con XX
                                    } else {
                                        printf("%d\t", vagoneta[r][i]);
                                    }
                                }
                                printf("\n");
                            }
        
                            printf("Escoje la fila donde se encuentra el asiento (1-5):\n");
                            scanf("%d", &col);
                            printf("Escoje la columna donde se encuentra el asiento (1-3):\n");
                            scanf("%d", &fil);
        
                            // Verifica que se ingurese un valor valido
                            if (col < 1 || col > 5 || fil < 1 || fil > 3) {
                                printf("Entrada no válida. Inténtalo de nuevo.\n");
                                continue;
                            }
        
                            // Ajuste para la indexación de base cero
                            col--;
                            fil--;
        
                            // Verifica si el asiento esta disponible
                            if (vagoneta[fil][col] != 0) {
                                printf("Tu numero de asiento es %d\n", vagoneta[fil][col]);
                                vagoneta[fil][col] = 0; // Marca si el asiento esta ocupado
                            } else {
                                printf("Asiento ocupado, favor de elegir otro asiento\n");
                            }
        
                            printf("¿Quieres seguir comprando? 0=si 1=no\n");
                            scanf("%d", &comprar);
        
                            if (comprar != 0 && comprar != 1) {
                                printf("Dato no válido.\n");
                                comprar = 1; // Fin del programa si se invalida
                            }
        
                            } while (comprar == 0);
        
                                printf("Gracias por usar el sistema de compra de boletos.\n");
                            break;
                        case 2:
                             // Inicializa la matriz de los asientos
                            for (int i = 0; i < 5; i++) {
                                for (int r = 0; r < 3; r++) {
                                    vagoneta[r][i] = (r + 1) * 10 + (i + 1);
                                }
                            }
        
                            do {
                            // Muestra los asientos
                            for (int i = 0; i < 5; i++) {
                                for (int r = 0; r < 3; r++) {
                                    if (vagoneta[r][i] == 0) {
                                        printf("XX\t"); // Marca el asiento con XX
                                    } else {
                                        printf("%d\t", vagoneta[r][i]);
                                    }
                                }
                                printf("\n");
                            }
        
                            printf("Escoje la fila donde se encuentra el asiento (1-5):\n");
                            scanf("%d", &col);
                            printf("Escoje la columna donde se encuentra el asiento (1-3):\n");
                            scanf("%d", &fil);
        
                            // Verifica que se ingurese un valor valido
                            if (col < 1 || col > 5 || fil < 1 || fil > 3) {
                                printf("Entrada no válida. Inténtalo de nuevo.\n");
                                continue;
                            }
        
                            // Ajuste para la indexación de base cero
                            col--;
                            fil--;
        
                            // Verifica si el asiento esta disponible
                            if (vagoneta[fil][col] != 0) {
                                printf("Tu numero de asiento es %d\n", vagoneta[fil][col]);
                                vagoneta[fil][col] = 0; // Marca si el asiento esta ocupado
                            } else {
                                printf("Asiento ocupado, favor de elegir otro asiento\n");
                            }
        
                            printf("¿Quieres seguir comprando? 0=si 1=no\n");
                            scanf("%d", &comprar);
        
                            if (comprar != 0 && comprar != 1) {
                                printf("Dato no válido.\n");
                                comprar = 1; // Fin del programa si se invalida
                            }
        
                            } while (comprar == 0);
        
                                printf("Gracias por usar el sistema de compra de boletos.\n");
                            break;
                        default:
                            printf("No hay vagonetas a tu pueblito agropecuaro ya vete");
                    }
                    break;
                default:
                    printf("Error transporte no existente el dispositivo explotara en en minuto 42:37, por cierto prestame unos 1000 pesos w pal sparking zero");
            }
            break;
        case 2:
            
            break;
        default:
            printf("Que no hay mas opciones w");
    }
    return 0;
}    
