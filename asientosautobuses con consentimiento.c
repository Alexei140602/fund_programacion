#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USUARIOS 100
#define MAX_NOMBRE 100
#define MAX_CORREO 100
#define MAX_TELEFONO 20
#define MAX_CONTRASENA 20

typedef struct {
    char nombre[MAX_NOMBRE];
    char correo[MAX_CORREO];
    char telefono[MAX_TELEFONO];
    char contrasena[MAX_CONTRASENA];
} Usuario;


int registrar_usuario(Usuario *usuarios, int *num_usuarios) 
    {
        
        if (*num_usuarios >= MAX_USUARIOS)
        {
        printf("No se pueden registrar mas usuarios.\n");
        return 0;
        }

    Usuario nuevo_usuario;
    
        printf("INGRESA TU NOMBRE COMPLETO: ");
        fgets(nuevo_usuario.nombre, MAX_NOMBRE, stdin);
    nuevo_usuario.nombre[strcspn(nuevo_usuario.nombre, "\n")] = 0;


    do
    {
    printf("INGRESA TU CORREO ELECTRONICO: ");
    fgets(nuevo_usuario.correo, MAX_CORREO, stdin);
    if (strchr( nuevo_usuario.correo, '@' )== NULL)
    {
       printf("correo invalido, intente de nuevo\n");
    }
    else
    {
         nuevo_usuario.correo[strcspn(nuevo_usuario.correo, "\n")] = 0;
    }
    } while (strchr( nuevo_usuario.correo, '@' )== NULL);

      do
    {
    printf("INGRESA TU NUMERO DE TELEFONO: ");
    fgets(nuevo_usuario.telefono, MAX_TELEFONO, stdin);
     if (strlen( nuevo_usuario.telefono )!=11)
    {
       printf("numero invalido, intente de nuevo\n");
    }
    else
    {
    nuevo_usuario.telefono[strcspn(nuevo_usuario.telefono, "\n")] = 0;
    }
    } while (strlen( nuevo_usuario.telefono )==11);

    printf("INGRESA TU CONTRASENA: ");
    fgets(nuevo_usuario.contrasena, MAX_CONTRASENA, stdin);
    nuevo_usuario.contrasena[strcspn(nuevo_usuario.contrasena, "\n")] = 0;
    usuarios[*num_usuarios] = nuevo_usuario;
    (*num_usuarios)++;

    printf("\nREGISTRADO EXITOSAMENTE.\n");
    return 1;
}


int login(Usuario *usuarios, int num_usuarios) {
    char correo[MAX_CORREO], contrasena[MAX_CONTRASENA];

    printf("\nINGRESA TU CORREO ELECTRONICO: ");
    fgets(correo, MAX_CORREO, stdin);
    correo[strcspn(correo, "\n")] = 0;

    printf("INGRESA TU CONTRASENA: ");
    fgets(contrasena, MAX_CONTRASENA, stdin);
    contrasena[strcspn(contrasena, "\n")] = 0;

    for (int i = 0; i < num_usuarios; i++) {
        if (strcmp(usuarios[i].correo, correo) == 0 && strcmp(usuarios[i].contrasena, contrasena) == 0) {
            printf("BIENVENIDO A TRAVELBUS, %s.\n", usuarios[i].nombre);
            return 1;
        }
    }

    printf("Correo o contrasena incorrectos.\n");
    return 0;
}

void mostrarticket(char *archivo){
        char texto;
        FILE *file = fopen(archivo, "r");
        while ((texto = fgetc(file)) != EOF){
                putchar(texto);
        }
        fclose(file);
}


int main(){
     Usuario usuarios[MAX_USUARIOS];
    int num_usuarios = 0;
    char aut[100];
    char dest[100];
    char nombreArch[100];
    int opcion;
    do {
        printf("\n1. Registrar usuario\n");
        printf("2. Iniciar sesion\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1:
                registrar_usuario(usuarios, &num_usuarios);
                break;
            case 2:
                if (login(usuarios, num_usuarios)) 
            {
                int comprar = 0;
                int turistico[15][4];
                int col, fil;
                int carretera[10][4];
                int vagoneta[5][4];
                int destino;
                int transporte;
                int desicion;
                printf("Bienvenido, Quieres comprar un boleto?\n si=1\n no=0\n");
                scanf("%i",&desicion);
                switch (desicion){
                    case 1:
                        printf("Selecciona un tipo de transporte\n");
                        printf("Autobus turistico = 1\n");
                        printf("Autobus de carretera = 2\n");
                        printf("Vagonetas = 3\n");
                        scanf("%i", &transporte);
                        switch (transporte) {
                            case 1:
                                strcpy(aut,"Autobus turistico");
                                printf("Selecciona un destino\n");
                                printf("Circuito Historico = 1\n");
                                printf("Tour Gastronomico = 2\n");
                                printf("Parque La Mexicana = 3\n");
                                printf("Universum = 4\n");
                                scanf("%i", &destino);
                                switch (destino) {
                                    case 1:
                                         // Inicializa la matriz de los asientos
                                        strcpy(dest,"Circuito Historico");
                                        for (int i = 1; i <=4; i++) {
                                            for (int r = 1; r <= 15; r++) {
                                                turistico[r][i] = r * 10 +i;
                                            }
                                        }
        
                            do {
                            // Muestra los asientos
                            for (int i = 1; i <= 4; i++) {
                                for (int r = 1; r <= 15; r++) {
                                    if (turistico[r][i] == 0) {
                                        printf("XX   "); // Marca el asiento con XX
                                    } else {
                                        printf("%d   ", turistico[r][i]);
                                    }
                                }
                                printf("\n");
                            }
        
                            printf("Escoje la columna donde se encuentra el asiento (1-15):\n");
                            scanf("%d", &col);
                        
                            printf("Escoje la fila donde se encuentra el asiento (1-4):\n");
                            scanf("%d", &fil);
                                   
                            // Verifica que se ingrese un valor valido
                            if (col < 1 || col > 15 || fil < 1 || fil > 4) {
                                printf("Entrada no valida. Intentalo de nuevo.\n");
                                continue;
                            }
        
                            
        
                            // Verifica si el asiento esta disponible
                            if (turistico[fil][col] != 0) {
                               sprintf(nombreArch, "%s.txt", usuarios[0].correo);
                                FILE *file = fopen(nombreArch, "w");
                                if (file != NULL){
                                    fprintf(file, "Nombre: %s\nAutobus: %s\nDestino: %s\nAsiento: %d\n", usuarios[0].correo, aut, dest, turistico[fil][col]);
                                    fclose(file);
                                }else {
                                    puts("Error al generar el ticket");
                                }
                                mostrarticket(nombreArch);
                                turistico[fil][col] = 0; // Marca si el asiento esta ocupado
                            } else {
                                printf("Asiento ocupado, favor de elegir otro asiento\n");
                            }
        
                            printf("Quieres seguir comprando? 0=si 1=no\n");
                            scanf("%d", &comprar);
        
                            if (comprar != 0 && comprar != 1) {
                                printf("Dato no valido.\n");
                                comprar = 1; // Fin del programa si se invalida
                            }
        
                            } while (comprar == 0);
        
                                printf("Gracias por usar el sistema de compra de boletos.\n");
                            break;
                        case 2:
                             // Inicializa la matriz de los asientos
                            strcpy(dest,"Tour Gastronomico");
                            for (int i = 1; i <= 4; i++) {
                                for (int r = 1; r <= 15; r++) {
                                    turistico[r][i] = r * 10 + i;
                                }
                            }
        
                            do {
                            // Muestra los asientos
                            for (int i = 1; i <= 4; i++) {
                                for (int r = 1; r <= 15; r++) {
                                    if (turistico[r][i] == 0) {
                                        printf("XX   "); // Marca el asiento con XX
                                    } else {
                                        printf("%d   ", turistico[r][i]);
                                    }
                                }
                                printf("\n");
                            }
        
                            printf("Escoje la columna donde se encuentra el asiento (1-15):\n");
                            scanf("%d", &col);
                            printf("Escoje la fila donde se encuentra el asiento (1-4):\n");
                            scanf("%d", &fil);
        
                            // Verifica que se ingrese un valor valido
                            if (col < 1 || col > 15 || fil < 1 || fil > 4) {
                                printf("Entrada no valida. Intentalo de nuevo.\n");
                                continue;
                            }
        
                        
                            // Verifica si el asiento esta disponible
                            if (turistico[fil][col] != 0) {
                                sprintf(nombreArch, "%s.txt", usuarios[0].correo);
                                FILE *file = fopen(nombreArch, "w");
                                if (file != NULL){
                                    fprintf(file, "Nombre: %s\nAutobus: %s\nDestino: %s\nAsiento: %d\n", usuarios[0].correo, aut, dest, turistico[fil][col]);
                                    fclose(file);
                                }else {
                                    puts("Error al generar el ticket");
                                }
                                mostrarticket(nombreArch);
                                turistico[fil][col] = 0; // Marca si el asiento esta ocupado
                            } else {
                                printf("Asiento ocupado, favor de elegir otro asiento\n");
                            }
        
                            printf("Quieres seguir comprando? 0=si 1=no\n");
                            scanf("%d", &comprar);
        
                            if (comprar != 0 && comprar != 1) {
                                printf("Dato no valido.\n");
                                comprar = 1; // Fin del programa si se invalida
                            }
        
                            } while (comprar == 0);
        
                                printf("Gracias por usar el sistema de compra de boletos.\n");
                            break;
                        case 3:
                             // Inicializa la matriz de los asientos
                              strcpy(dest,"Parque: La Mexicana");
                           for (int i = 1; i <= 4; i++) {
                                for (int r = 1; r <= 15; r++) {
                                    turistico[r][i] = r * 10 + i;
                                }
                            }
        
                            do {
                            // Muestra los asientos
                            for (int i = 1; i <= 4; i++) {
                                for (int r = 1; r <= 15; r++) {
                                    if (turistico[r][i] == 0) {
                                        printf("XX   "); // Marca el asiento con XX
                                    } else {
                                        printf("%d   ", turistico[r][i]);
                                    }
                                }
                                printf("\n");
                            }
        
                            printf("Escoje la columna donde se encuentra el asiento (1-15):\n");
                            scanf("%d", &col);
                            printf("Escoje la fila donde se encuentra el asiento (1-4):\n");
                            scanf("%d", &fil);
        
                            // Verifica que se ingrese un valor valido
                            if (col < 1 || col > 15 || fil < 1 || fil > 4) {
                                printf("Entrada no valida. Intentalo de nuevo.\n");
                                continue;
                            }
        
                            // Verifica si el asiento esta disponible
                            if (turistico[fil][col] != 0) {
                                sprintf(nombreArch, "%s.txt", usuarios[0].correo);
                                FILE *file = fopen(nombreArch, "w");
                                if (file != NULL){
                                    fprintf(file, "Nombre: %s\nAutobus: %s\nDestino: %s\nAsiento: %d\n", usuarios[0].correo, aut, dest, turistico[fil][col]);
                                    fclose(file);
                                }else {
                                    puts("Error al generar el ticket");
                                }
                                mostrarticket(nombreArch);
                                turistico[fil][col] = 0; // Marca si el asiento esta ocupado
                            } else {
                                printf("Asiento ocupado, favor de elegir otro asiento\n");
                            }
        
                            printf("Quieres seguir comprando? 0=si 1=no\n");
                            scanf("%d", &comprar);
        
                            if (comprar != 0 && comprar != 1) {
                                printf("Dato no valido.\n");
                                comprar = 1; // Fin del programa si se invalida
                            }
        
                            } while (comprar == 0);
        
                                printf("Gracias por usar el sistema de compra de boletos.\n");
                            break;
                        case 4:
                             // Inicializa la matriz de los asientos
                              strcpy(dest,"Universum");
                            for (int i = 1; i <= 4; i++) {
                                for (int r = 1; r <= 15; r++) {
                                    turistico[r][i] = r * 10 + i;
                                }
                            }
        
                            do {
                            // Muestra los asientos
                            for (int i = 1; i <= 4; i++) {
                                for (int r = 1; r <= 15; r++) {
                                    if (turistico[r][i] == 0) {
                                        printf("XX   "); // Marca el asiento con XX
                                    } else {
                                        printf("%d   ", turistico[r][i]);
                                    }
                                }
                                printf("\n");
                            }
        
                            printf("Escoje la columna donde se encuentra el asiento (1-15):\n");
                            scanf("%d", &col);
                            printf("Escoje la fila donde se encuentra el asiento (1-4):\n");
                            scanf("%d", &fil);
        
                            // Verifica que se ingrese un valor valido
                            if (col < 1 || col > 15 || fil < 1 || fil > 4) {
                                printf("Entrada no valida. Intentalo de nuevo.\n");
                                continue;
                            }
        
                          
                            // Verifica si el asiento esta disponible
                            if (turistico[fil][col] != 0) {
                                sprintf(nombreArch, "%s.txt", usuarios[0].correo);
                                FILE *file = fopen(nombreArch, "w");
                                if (file != NULL){
                                    fprintf(file, "Nombre: %s\nAutobus: %s\nDestino: %s\nAsiento: %d\n", usuarios[0].correo, aut, dest, turistico[fil][col]);
                                    fclose(file);
                                }else {
                                    puts("Error al generar el ticket");
                                }
                                mostrarticket(nombreArch);
                                turistico[fil][col] = 0; // Marca si el asiento esta ocupado
                            } else {
                                printf("Asiento ocupado, favor de elegir otro asiento\n");
                            }
        
                            printf("Quieres seguir comprando? 0=si 1=no\n");
                            scanf("%d", &comprar);
        
                            if (comprar != 0 && comprar != 1) {
                                printf("Dato no valido.\n");
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
                    strcpy(aut,"Autobus de carretera");
                    printf("Selecciona un destino\n");
                    printf("CDMX-Puebla = 1\n");
                    printf("CDMX-Queretaro = 2\n");
                    printf("CDMX-Hidaldo = 3\n");
                    scanf("%i", &destino);
                    switch (destino) {
                        case 1:
                             // Inicializa la matriz de los asientos
                              strcpy(dest,"CDMX->Puebla");
                           for (int i = 1; i <= 4; i++) {
                                for (int r = 1; r <= 10; r++) {
                                    carretera[r][i] = r * 10 + i;
                                }
                            }
        
                            do {
                            // Muestra los asientos
                            for (int i = 1; i <= 4; i++) {
                                for (int r = 1; r <= 10; r++) {
                                    if (carretera[r][i] == 0) {
                                        printf("XX   "); // Marca el asiento con XX
                                    } else {
                                        printf("%d   ", carretera[r][i]);
                                    }
                                }
                                printf("\n");
                            }
        
                            printf("Escoje la columna donde se encuentra el asiento (1-10):\n");
                            scanf("%d", &col);
                            printf("Escoje la fila donde se encuentra el asiento (1-4):\n");
                            scanf("%d", &fil);
        
                            // Verifica que se ingrese un valor valido
                            if (col < 1 || col > 10 || fil < 1 || fil > 4) {
                                printf("Entrada no valida. Intentalo de nuevo.\n");
                                continue;
                            }
        
                            
                            // Verifica si el asiento esta disponible
                            if (carretera[fil][col] != 0) {
                               sprintf(nombreArch, "%s.txt", usuarios[0].correo);
                                FILE *file = fopen(nombreArch, "w");
                                if (file != NULL){
                                    fprintf(file, "Nombre: %s\nAutobus: %s\nDestino: %s\nAsiento: %d\n", usuarios[0].correo, aut, dest, carretera[fil][col]);
                                    fclose(file);
                                }else {
                                    puts("Error al generar el ticket");
                                }
                                mostrarticket(nombreArch);
                                carretera[fil][col] = 0; // Marca si el asiento esta ocupado
                            } else {
                                printf("Asiento ocupado, favor de elegir otro asiento\n");
                            }
        
                            printf("Quieres seguir comprando? 0=si 1=no\n");
                            scanf("%d", &comprar);
        
                            if (comprar != 0 && comprar != 1) {
                                printf("Dato no valido.\n");
                                comprar = 1; // Fin del programa si se invalida
                            }
        
                            } while (comprar == 0);
        
                                printf("Gracias por usar el sistema de compra de boletos.\n");
                            break;
                        case 2:
                             // Inicializa la matriz de los asientos
                             strcpy(dest,"CDMX->Queretaro");
                            for (int i = 1; i <= 4; i++) {
                                for (int r = 1; r <= 10; r++) {
                                    carretera[r][i] = r * 10 + i;
                                }
                            }
        
                            do {
                            // Muestra los asientos
                            for (int i = 1; i <= 4; i++) {
                                for (int r = 1; r <= 10; r++) {
                                    if (carretera[r][i] == 0) {
                                        printf("XX   "); // Marca el asiento con XX
                                    } else {
                                        printf("%d   ", carretera[r][i]);
                                    }
                                }
                                printf("\n");
                            }
        
                            printf("Escoje la columna donde se encuentra el asiento (1-10):\n");
                            scanf("%d", &col);
                            printf("Escoje la fila donde se encuentra el asiento (1-4):\n");
                            scanf("%d", &fil);
        
                            // Verifica que se ingrese un valor valido
                            if (col < 1 || col > 10 || fil < 1 || fil > 4) {
                                printf("Entrada no valida. Intentalo de nuevo.\n");
                                continue;
                            }
        
                          
                            // Verifica si el asiento esta disponible
                            if (carretera[fil][col] != 0) {
                              sprintf(nombreArch, "%s.txt", usuarios[0].correo);
                                FILE *file = fopen(nombreArch, "w");
                                if (file != NULL){
                                    fprintf(file, "Nombre: %s\nAutobus: %s\nDestino: %s\nAsiento: %d\n", usuarios[0].correo, aut, dest, carretera[fil][col]);
                                    fclose(file);
                                }else {
                                    puts("Error al generar el ticket");
                                }
                                mostrarticket(nombreArch);
                                carretera[fil][col] = 0; // Marca si el asiento esta ocupado
                            } else {
                                printf("Asiento ocupado, favor de elegir otro asiento\n");
                            }
        
                            printf("Quieres seguir comprando? 0=si 1=no\n");
                            scanf("%d", &comprar);
        
                            if (comprar != 0 && comprar != 1) {
                                printf("Dato no valido.\n");
                                comprar = 1; // Fin del programa si se invalida
                            }
        
                            } while (comprar == 0);
        
                                printf("Gracias por usar el sistema de compra de boletos.\n");
                            break;
                        case 3:
                             // Inicializa la matriz de los asientos
                             strcpy(dest,"CDMX->Hidalgo");
                            for (int i = 1; i <= 4; i++) {
                                for (int r = 1; r <= 10; r++) {
                                    carretera[r][i] = r * 10 + i;
                                }
                            }
        
                            do {
                            // Muestra los asientos
                            for (int i = 1; i <= 4; i++) {
                                for (int r = 1; r <= 10; r++) {
                                    if (carretera[r][i] == 0) {
                                        printf("XX   "); // Marca el asiento con XX
                                    } else {
                                        printf("%d   ", carretera[r][i]);
                                    }
                                }
                                printf("\n");
                            }
        
                            printf("Escoje la columna donde se encuentra el asiento (1-10):\n");
                            scanf("%d", &col);
                            printf("Escoje la fila donde se encuentra el asiento (1-4):\n");
                            scanf("%d", &fil);
        
                            // Verifica que se ingrese un valor valido
                            if (col < 1 || col > 10 || fil < 1 || fil > 4) {
                                printf("Entrada no valida. Intentalo de nuevo.\n");
                                continue;
                            }
        
                           
                            // Verifica si el asiento esta disponible
                            if (carretera[fil][col] != 0) {
                                sprintf(nombreArch, "%s.txt", usuarios[0].correo);
                                FILE *file = fopen(nombreArch, "w");
                                if (file != NULL){
                                    fprintf(file, "Nombre: %s\nAutobus: %s\nDestino: %s\nAsiento: %d\n", usuarios[0].correo, aut, dest, carretera[fil][col]);
                                    fclose(file);
                                }else {
                                    puts("Error al generar el ticket");
                                }
                                mostrarticket(nombreArch);
                                carretera[fil][col] = 0; // Marca si el asiento esta ocupado
                            } else {
                                printf("Asiento ocupado, favor de elegir otro asiento\n");
                            }
        
                            printf("Quieres seguir comprando? 0=si 1=no\n");
                            scanf("%d", &comprar);
        
                            if (comprar != 0 && comprar != 1) {
                                printf("Dato no valido.\n");
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
                    strcpy(aut,"Vagoneta");
                    printf("Selecciona un destino\n");
                    printf("CDMX-Tepoztlan = 1\n");
                    printf("CDMX-Valle de Bravo = 2\n");
                    scanf("%i", &destino);
                    switch (destino) {
                        case 1:
                             // Inicializa la matriz de los asientos
                             strcpy(dest,"CDMX->Tepoztlan");
                              for (int i = 1; i <= 4; i++) {
                                for (int r = 1; r <= 5; r++) {
                                    vagoneta[r][i] = r * 10 + i;
                                }
                            }
        
                            do {
                            // Muestra los asientos
                            for (int i = 1; i <= 4; i++) {
                                for (int r = 1; r <= 5; r++) {
                                    if (vagoneta[r][i] == 0) {
                                        printf("XX   "); // Marca el asiento con XX
                                    } else {
                                        printf("%d   ", vagoneta[r][i]);
                                    }
                                }
                                printf("\n");
                            }
        
                            printf("Escoje la columna donde se encuentra el asiento (1-5):\n");
                            scanf("%d", &col);
                            printf("Escoje la fila donde se encuentra el asiento (1-3):\n");
                            scanf("%d", &fil);
        
                            // Verifica que se ingurese un valor valido
                            if (col < 1 || col > 5 || fil < 1 || fil > 3) {
                                printf("Entrada no valida. Intentalo de nuevo.\n");
                                continue;
                            }
        
                            // Verifica si el asiento esta disponible
                            if (vagoneta[fil][col] != 0) {
                                sprintf(nombreArch, "%s.txt", usuarios[0].correo);
                                FILE *file = fopen(nombreArch, "w");
                                if (file != NULL){
                                    fprintf(file, "Nombre: %s\nAutobus: %s\nDestino: %s\nAsiento: %d\n", usuarios[0].correo, aut, dest, vagoneta[fil][col]);
                                    fclose(file);
                                }else {
                                    puts("Error al generar el ticket");
                                }
                                mostrarticket(nombreArch);
                                vagoneta[fil][col] = 0; // Marca si el asiento esta ocupado
                            } else {
                                printf("Asiento ocupado, favor de elegir otro asiento\n");
                            }
        
                            printf("Quieres seguir comprando? 0=si 1=no\n");
                            scanf("%d", &comprar);
        
                            if (comprar != 0 && comprar != 1) {
                                printf("Dato no valido.\n");
                                comprar = 1; // Fin del programa si se invalida
                            }
        
                            } while (comprar == 0);
        
                                printf("Gracias por usar el sistema de compra de boletos.\n");
                            break;
                        case 2:
                             // Inicializa la matriz de los asientos
                             strcpy(dest,"CDMX->Valle de Bravo");
                            for (int i = 1; i <= 4; i++) {
                                for (int r = 1; r <= 5; r++) {
                                    vagoneta[r][i] = r * 10 + i;
                                }
                            }
        
                            do {
                            // Muestra los asientos
                            for (int i = 1; i <= 4; i++) {
                                for (int r = 1; r <= 5; r++) {
                                    if (vagoneta[r][i] == 0) {
                                        printf("XX   "); // Marca el asiento con XX
                                    } else {
                                        printf("%d   ", vagoneta[r][i]);
                                    }
                                }
                                printf("\n");
                            }
        
                            printf("Escoje la columna donde se encuentra el asiento (1-5):\n");
                            scanf("%d", &col);
                            printf("Escoje la fila donde se encuentra el asiento (1-3):\n");
                            scanf("%d", &fil);
        
                            // Verifica que se ingurese un valor valido
                            if (col < 1 || col > 5 || fil < 1 || fil > 3) {
                                printf("Entrada no valida. Intentalo de nuevo.\n");
                                continue;
                            }
        
                            // Verifica si el asiento esta disponible
                            if (vagoneta[fil][col] != 0) {
                                sprintf(nombreArch, "%s.txt", usuarios[0].correo);
                                FILE *file = fopen(nombreArch, "w");
                                if (file != NULL){
                                    fprintf(file, "Nombre: %s\nAutobus: %s\nDestino: %s\nAsiento: %d\n", usuarios[0].correo, aut, dest, vagoneta[fil][col]);
                                    fclose(file);
                                }else {
                                    puts("Error al generar el ticket");
                                }
                                mostrarticket(nombreArch);
                                vagoneta[fil][col] = 0; // Marca si el asiento esta ocupado
                            } else {
                                printf("Asiento ocupado, favor de elegir otro asiento\n");
                            }
        
                            printf("Quieres seguir comprando? 0=si 1=no\n");
                            scanf("%d", &comprar);
        
                            if (comprar != 0 && comprar != 1) {
                                printf("Dato no valido.\n");
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

                }
                break;
            case 3:
                printf("SALIENDO DEL SISTEMA.\n");
                break;
            default:
                printf("Opcion no valida. Intente nuevamente.\n");
        
        }
    
    } while (opcion != 3);

    return 0;
}


