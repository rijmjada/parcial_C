#include <stdio.h>
#include <stdlib.h>

/*Debemos realizar la carga de una compra de 5(cinco) productos de prevenci�n de contagio
        De cada uno debo obtener los siguientes datos:
        el nombre del producto
        el tipo de producto (validar "ALCOHOL" , "IAC" o "QUAT") ,
        el precio (validar entre 100 y 300),
        la cantidad de unidades (no puede ser 0 o negativo y no debe superar las 1000 unidades),
        el tipo de inflamable("ign�fugo", "combustible", "explosivo" )
        y la Marca

        Se debe informar al usuario lo siguiente:

        a) El promedio de cantidad por tipo de producto
        b) El tipo de inflamable con m�s cantidad de unidades en total de la compra

        c) Cu�ntas unidades de IAC con precios menores a 200 (inclusive) se compraron en total

        d) La marca y tipo del m�s caro de los productos<br>*/
int main()
{

    char nombreP [15];
    char tipoP;
    float precioP;
    int cantidadP;
    char tipoInflamable;
    char marca;

    int contadorAlcohol;
    int contadorIac;
    int contadorQuat;

    int acumuladorAlcohol;
    int acumuladorIac;
    int acumuladorQuat;

    float promedioAlcohol;
    float promedioIac;
    float promedioQuat;

    int acumuladorIgnifugo;
    int acumuladorCombustible;
    int acumuladorExplosivo;

    int acumuladorIac200;



    acumuladorIac200 = 0;

    acumuladorIgnifugo = 0;
    acumuladorExplosivo = 0;
    acumuladorCombustible = 0;

    contadorAlcohol = 0;
    contadorIac = 0;
    contadorQuat = 0;

    acumuladorAlcohol = 0;
    acumuladorIac = 0;
    acumuladorQuat = 0;





    for(int cantidadIngresos =0; cantidadIngresos <1 ; cantidadIngresos++)
        {

            printf ("Ingrese el nombre : "); /* NOMBRE */
            fflush(stdin);
            scanf ("%s", nombreP);

            printf("El Usuario Ingreso : %s\n ", nombreP);


            printf ("Ingrese el tipo (A, I o Q ) : "); /* TIPO DE PRODUCTO */
            fflush(stdin);
            scanf ("%c", &tipoP);
                 while(tipoP != 'A' && tipoP != 'I' && tipoP != 'Q'){
                      printf ("ERROR . Ingrese el tipo (A, I o Q ) : ");
                      scanf ("%c", &tipoP);
                }

            printf("El Usuario Ingreso : %c\n", tipoP);

            printf ("Ingrese el precio (entre 100 y 300 ) : "); /* PRECIO DEL PRODUCTO */
            scanf ("%f", &precioP);
                while(precioP < 100 || precioP >300){
                    printf ("ERROR . Ingrese el precio (entre 100 y 300 ) : ");
                    scanf ("%f", &precioP);
                }

            printf("El Usuario Ingreso : %.2f\n", precioP);

            printf ("Ingrese cantidad de unidades ( no puede ser negativo ni mayor a 1000 ): "); /* CANTIDAD DE UNIDADES */
            scanf("%d", &cantidadP);
                while(cantidadP < 1 || cantidadP >1000){
                    printf ("ERROR. Ingrese cantidad de unidades ( no puede ser negativo ni mayor a 1000 ): ");
                    scanf("%d", &cantidadP);
                }

            printf("El Usuario Ingreso : %d\n", cantidadP);

            printf ("Ingrese el tipo de inflamable(I/C/E) : ");  /* TIPO DE INFLAMABLE */
            fflush(stdin);
            scanf("%c", &tipoInflamable);
                while (tipoInflamable != 'I' && tipoInflamable != 'C' && tipoInflamable != 'E' )
                {
                    printf ("ERROR . Ingrese el tipo de inflamable(I/C/E) : ");
                    fflush(stdin);
                    scanf("%c", &tipoInflamable);

                }

            printf("El Usuario Ingreso : %c\n", tipoInflamable);


            printf ("Ingrese la marca : "); /* MARCA DEL PRODUCTO */
            fflush(stdin);
            scanf ("%c", &marca);

            printf("El Usuario Ingreso : %c\n", marca);



            switch (tipoP)
            {
                case 'A':
                    contadorAlcohol++;
                    acumuladorAlcohol = acumuladorAlcohol + cantidadP;
                    break;

                case 'I':
                    contadorIac++;
                    acumuladorIac = acumuladorIac + cantidadP;
                    if(precioP < 201){
                        acumuladorIac200 = acumuladorIac200 + cantidadP;
                       }
                    break;

                case 'Q' :
                    contadorQuat++;
                    acumuladorQuat = acumuladorQuat + cantidadP;
                    break;

            } /*SWITCH*/

            switch (tipoInflamable)
            {
                case 'I':
                    acumuladorIgnifugo = acumuladorIgnifugo + cantidadP;
                    break;

                case 'C':
                    acumuladorCombustible = acumuladorCombustible + cantidadP;
                    break;

                case 'E':
                    acumuladorExplosivo = acumuladorExplosivo + cantidadP;
                    break;

            }

        }/////////////// FINAL DEL FOR //////////////////////

        promedioAlcohol = (float)acumuladorAlcohol / contadorAlcohol;
        promedioIac = (float)acumuladorIac / contadorIac;
        promedioQuat = (float)acumuladorQuat / contadorQuat;

        if(contadorAlcohol > 0 ){
                    printf("El promedio de alcohol comprado es : %.2f\n", promedioAlcohol);
            }

        if(contadorIac > 0 ){
                    printf("El promedio de Iac comprado es : %.2f\n", promedioIac );
            }

        if(contadorQuat > 0 ){
                    printf("El promedio de quat comprado es : %.2f\n", promedioQuat );
            }


        if(acumuladorIgnifugo > acumuladorCombustible && acumuladorIgnifugo > acumuladorExplosivo)
        {
            printf("El tipo de inflamable con mas unidades en total es: Ignifugo y las unidades son : %d\n ", acumuladorIgnifugo);
        }else
            if(acumuladorCombustible > acumuladorIgnifugo && acumuladorCombustible > acumuladorExplosivo)
            {
            printf("El tipo de inflamable con mas unidades en total es: Combustible y las unidades son : %d\n ", acumuladorCombustible);
             }else
                {
            printf("El tipo de inflamable con mas unidades en total es: Explosivo y las unidades son : %d\n ", acumuladorExplosivo);
                 }


        printf("Las cantidad de unidades Iac por debajo de $200 son : %d\n ", acumuladorIac200);


    system("pause");



}
