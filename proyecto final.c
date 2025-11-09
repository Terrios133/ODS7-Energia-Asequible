//PROYECTO FINAL ENERGIA DE HOGAR
//Franco Fernando Solorza Orochon 
//Lopez Muñoz Martha Citlalli
//Dylan de jesús 
//Pascasio Luis Manuel
//Citlali Ortiz Cruz
#include <stdio.h>
#include <locale.h>

void mostrarMenuPrincipal (int DIACTUAL, char USER [13]){
printf("\n (1) C a p t u r a r  2 4  h o r a s\n (2) R e p o r t e  d e  b a s e (D I A: %d)\n (3) S i m u l a d o r  d e  a h o r r o\n (4) C o o m p a r a t i v o  b a s e vs s i m u l a d o\n (5) D i a  s i g u i e n t e\n (6) V e r  r e p o r t e  d e  o t r o  d i a\n (7) C ó m o  a h o r r a r  l u z?\n (8) C O M P A R A R  D I A S\n (9) F I N A L I Z A R\n%s TU NUMERO DE OPCION ES: ", DIACTUAL, USER);
}
void captura24Horas (float HORA[24], float HORASAUTO[24], float HORASREPORTE[24], char USER[13]) {
printf("\n------------------------------------------------------------\n");
            printf("\t---------- C A P T U R A R  2 4  H O R A S ----------\n");
            printf("\t                I N F O R M A C I O N\n %s para saber que datos deberias ingresar deberias conocer que estos electrodomesticos encendidos consumen\n1)Refrigerador:0.88kwh 2)TV 32 pulgadas:.040kwh 3)Foco led :.015kwh\n4)Ventilador:0.09kwh 5)Aire acondicionado:1.6kwh 6)Otro aparatos:.03kwh\n", USER);
            printf("------------------------------------------------------------\n");
            printf("%s ingrese el consumo en kwh de la hora (El sistema empezara desde las 0:00HRS)\n", USER);
            for (int i = 0; i < 24; i++) {
            do {
            if (i < 12) {
            printf("-------------------------⋆｡ﾟ☁︎｡⋆｡ ☾. ݁.𖥔 ݁ ˖｡⋆-------------------------\n");
            printf("Son las %d:00 AM, ingresa tu consumo de KWH: ", i);
            scanf("%f", &HORASREPORTE[i]);
            } else {
            printf("-------------------------⋆｡ﾟ☁︎｡⋆｡ ﾟ☀︎ ˖ ✈︎ﾟ｡--------------------------\n");
            printf("Son las %d:00 PM, ingresa tu consumo de KWH: ", i);
            scanf("%f", &HORASREPORTE[i]);
            }
            }while(HORASREPORTE[i] < 0 || HORASREPORTE[i] > 15);//Validacion para que no se ingresen numeros negativos o muy altos
}
// Suma de consumos
for (int i = 0; i < 24; i++) {
    HORA[i] = HORASAUTO[i] + HORASREPORTE[i];
}

}
 void simuladorAhorro(float HSIMULADOR[24], char USER[13]) {
    printf("------------------------------------------------------------\n");
    printf("\t----------S I M U L A D O R   D E  A H O R R O----------\n%s a continuacion ingresa el consumo simulado por hora y eso se comparara con los datos ingresados en la base\n", USER);
    for (int i = 0; i < 24; i++) {
        if(i<12){
            printf("----------------------------⋆｡ﾟ☁︎｡⋆｡ ☾. ݁.𖥔 ݁ ˖｡⋆----------------------------\n");
            printf("Son las %d:00 AM, ingresa tu consumo de KWH para simularlo: ", i);
            scanf("%f", &HSIMULADOR[i]);
        } else {
            printf("----------------------------⋆｡ﾟ☁︎｡⋆｡ ﾟ☀︎ ˖ ✈︎ﾟ｡⋆----------------------------\n");
            printf("Son las %d:00 PM, ingresa tu consumo de KWH para simularlo: ", i);
            scanf("%f", &HSIMULADOR[i]);
        }
    }
}
 
void formasAhorrarLuz(char USER[13]) {
    printf("------------------------------------------------------------\n");   
    printf("       ----------  F O R M A S  D E  A H O R R A R  ----------\n\t            L U Z");
    printf("\nBienvenido %s, este es el apartado de formas de ahorrar luz ⋆.˚\n", USER);
    printf("------------------------------------------------------------\n");
    printf("Revisa que la instalación eléctrica no tenga fugas. Apaga todas las luces que no necesites\ndesconecta los aparatos eléctricos que no utilices y verifica que el disco del medidor no gire\nsi tu medidor es digital, checa que no avance la numeración");
    printf("\nIdentifica aparatos que al conectarlos producen chispas o calientan el cable. No los uses sin haber resuelto el problema.\n");
    printf("------------------------------------------------------------\n");
    printf("Apaga y desconecta aparatos que no se están usando: televisor, radio, computadora, tostador, horno de microondas, dvd. Si suspendes el uso de la computadora, apaga por lo menos el monitor.");
    printf("Coloca el refrigerador en un lugar fresco y ventilado, lejos de la estufa, el calentador o de una ventana donde el sol dé directamente. Descongélalo y límpialo con frecuencia.\nA su vez recuerda que tener el aire acondicionado encendido todo el día no es lo recomendable\nComo ultima recomendación recuerda buscar información por tu cuenta en artículos o videos");
    printf("------------------------------------------------------------\n");
    printf("%s no solo se trata de ahorrar dinero también se trata de cuidar el planeta :)\n", USER);
}

int main() {
    setlocale(LC_ALL, "");


    char USER[13];//Es para que el nombre de usuario no sea tan largo
    int MENUPRINCIPAL=0, DIACTUAL=0, VERDIA=0, DIA1= 0, DIA2= 0; //
    float HORA[24]={0}, HORASAUTO[24]={0}, HORASREPORTE[24]={0}, HSIMULADOR[24]={0}, DIAS[30][24]={0}; 
    int OPCIONAIREYREFRI=0;
    float TOTALDIAS=0, TOTALPAGAR=0, PRECIOKWH=0, TOTALDIA1=0, TOTALDIA2 = 0;
    float TOTALBASE=0, TOTALSIMULADOR=0;
    float TOTALDIAOTROREPORTE = 0;

    printf("\t---------- SISTEMA DE HOGAR AHORRO DE ENERGIA ----------\n");
    printf("Primer paso Ingrese su nombre de usuario ദ്ദി(˵ •̀ ᴗ - ˵ ) ✧(Solo se permiten letras y de preferencia 13 caracteres maximo): ");//NO SE PERMITEN NUMEROS AAA
    scanf("%12s",USER);
    printf("------------------------------------------------------------\n");
    printf("Cómo segundo paso puedes escoger el precio de tus kwh esto se hace debido a que en cada región varía\n");
    printf("------------------------------------------------------------\n");
    printf("%s ingresa manualmente el precio de tus kwh: ", USER);
    scanf("%f", &PRECIOKWH);
    printf("\nEso se hizo con la intencion que los datos mostrados sean más exactos :)\n------------------------------------------------------------\n");
    printf("Como ultimo paso queremos hacerte esta pregunta\nTienes el refrigerador conectado las 24 hrs y/o el aire acondicionado conectado las 24 hrs\n");
    printf("------------------------------------------------------------\n");
    printf("(1) Tengo solo el refrigerador\n(2) Tengo solo el aire acondicionado\n(3) Tengo ambos las 24 hrs\n(4) No tengo ninguno las 24 hrs\n(5) los tengo conectados a ciertas horas en especifico\n INGRESA EL NUMERO DE TU OPCION: ");
    scanf("%d", &OPCIONAIREYREFRI);
    if(OPCIONAIREYREFRI == 1) {
    for(int i = 0; i < 24; i++) {
    HORASAUTO[i] = HORASAUTO[i] + 0.88;
    }
    printf("\nSe añadio el consumo del refrigerador a las 24 hrs automaticamente \npara que no los tengas que hacer tu");
    }
    else if(OPCIONAIREYREFRI == 2){
    for(int i = 0; i < 24; i++) {
    HORASAUTO[i] = HORASAUTO[i] + 1.6;
    }
    printf("\nSe añadió el consumo del aire acondicionado a las 24 hrs automaticamente \npara que no los tengas que hacer tu");
    }
    else if(OPCIONAIREYREFRI == 3){
    for(int i = 0; i < 24; i++) {
    HORASAUTO[i] = HORASAUTO[i] + 2.04;
    }
        printf("\nSe añadio el consumo del aire acondicionado y refrigerador \na las 24 hrs automaticamente para que no los tengas que hacer tu");
    }
    else if(OPCIONAIREYREFRI == 4){
        printf("\nNo se añadio ningun consumo a las 24 horas");
    }
    else if(OPCIONAIREYREFRI == 5){
        printf("\n%s si deseas tu poner tu consumo del aire acondicionado o refrigerador\nen una hora en especifico mas adelante lo podras hacer en caturar 24 hora", USER);
    }
    else{
        printf("\ningresaste una opcion inexistente, no se hizo ninguna modificacion, continua");
    }
    printf("\n------------------------------------------------------------");
    printf("\n\t      ----------I N T R O D U C C I O N----------\n");
    printf("Bienvenido %s este programa permite registrar el consumo de energia por horas", USER);
    printf("\nAdemas %s podras ver el total de consumo y total a pagar por el consumo\ncontamos con diferentes apartados que pronto descubrirás, muchas gracias por elegirnos\n", USER);
    printf("Espero que este programa te pueda servir %s :)\n", USER);
do {
    printf("------------------------------------------------------------\n");
    printf("================ M E N U  P R I N C I P A L ================");
    mostrarMenuPrincipal (DIACTUAL, USER);
    scanf("%d", &MENUPRINCIPAL);
    
if(MENUPRINCIPAL > 8 || MENUPRINCIPAL < 1){
 printf("\n-----------------------  ᶻ 𝗓 𐰁 .ᐟ  -----------------------\n");
 printf("%s esa opcion es invalida \n", USER);
 continue; 
}
    switch (MENUPRINCIPAL) {
        case 1:
            captura24Horas(HORA, HORASAUTO, HORASREPORTE, USER);
            break;
        case 2:
    TOTALDIAS=0;
    for (int i = 0; i < 24; i++) {
        HORA[i] = HORASAUTO[i] + HORASREPORTE[i];
        TOTALDIAS = TOTALDIAS + HORA[i];
    }
    if (TOTALDIAS == 0){
    printf("\n------------------------------------------------------------\n");
    printf("%s, no se han ingresado datos en captura 24HRS\nni tampoco tienes aparatos conectado las 24HRS\n", USER);
    break;
}
    TOTALPAGAR = TOTALDIAS * PRECIOKWH;
            printf("------------------------------------------------------------");
            printf("\n\t---------- R E P O R T E  D E  B A S E ----------\n");
            printf("\t   ---------- CONSUMO EN EL DIA ----------\n");
            for (int i=0; i<24; i++){
            if(i<12){
            printf("A las %d:00 AM tu consumo fue de: %.2f KWH\n", i, HORA[i]);
        } else {
            printf("A las %d:00 PM tu consumo fue de: %.2f KWH\n", i, HORA[i]);
        }
    }
    printf("--------------------*ੈ ✩ ‧₊˚༺ ☆ ༻ * ੈ ✩‧₊˚--------------------\n");
    printf("-------------------- D I A G N O S T I C O --------------------\n");
    printf("El total del consumo de kwh fue de: %.2f kilovatios en el día \n", TOTALDIAS);
    printf("El total a pagar por el consumo de esos Kilovatios por día es: $%.2f pesos\n", TOTALPAGAR);
    if (TOTALDIAS < 12){
         printf("%s felicidades tu consumo es de %.2f Kwh al día, significa que es bajo sigue asi ( ˶ˆ ꒳ ˆ˵ )\n", USER, TOTALDIAS);
         printf("E X T R A\n%.2f se considera un consumo genial debido a que los datos apuntan que menos de 12 Kilovatiis al dia en un hogar de 2-3 habitantes es algo genial\nsi te interesa saber más de un buen consumo ve a opción 7\n", TOTALDIAS);
        } else if (TOTALDIAS > 12 && TOTALDIAS < 22){
            printf("%s tu consumo es de %.2f Kwh al día es promedio, pero siempre puedes reducirlo un poquito más si en tu casa habítan 2-3 personas mas ٩(ˊᗜˋ*) و\n", USER, TOTALDIAS);
            printf("\nE X T R A:\nTu consumo en el día fue de %.2f se considera un consumo aceptable debido a que los datos apuntan que menos de 33 Kilivatios por dia pero más de 22 kilovatios es algo aceptable :)\nsi te interesa saber más de un buen consumo ve a opción 7\n", TOTALDIAS);
        } else if (TOTALDIAS > 22 && TOTALDIAS < 33)
        {
        printf("%s tu consumo es de %.2f Kwh al día es regular, siempre estas a tiempo de poder reducirlo, recuerda que tenemos la opcion de como ahorrar luz", USER, TOTALDIAS);
        printf("\nE X T R A:\nTu consumo en el día fue de %.2f se considera un consumo regular debido a que los datos apuntan que menos de 33 Kilivatios por dia pero más de 22 kilovatios es algo regular ;)\nsi te interesa saber más de un buen consumo ve a opción 7\n", TOTALDIAS);
        }
        else {
            printf("%s tu consumo es de %.2f Kwh al día, es alto trata de reducirlo para ahorrar energia y dinero (⸝⸝⸝╸▵╺⸝⸝⸝)\n", USER, TOTALDIAS);
            printf("------------------------------------------------------------\n");
            printf("Como comentarios te recomendamos apagar los aparatos electronicos que no estes usando, usar focos ahorradores, usar electrodomesticos de bajo consumo energetico y aprovechar la luz natural del dia :)\nE X T R A:\nMas de 20kilovatios al día en un hogar de 2-3 habitantes es algo regularmente alto en ciertas zonas");
            printf("\nRecuerda que tenemos la opción formas de ahorrar luz para que te puedas informar <3\n");
            }
            break;
        case 3:
    simuladorAhorro(HSIMULADOR, USER);
        case 4:
        TOTALBASE=0;
        TOTALSIMULADOR=0;//Evitar que si el usuario vueleve a entrrar a sinulador se sobre escriban los valores 
            printf("------------------------------------------------------------\n");
            printf("\t----------B A S E  V S  S I M U L A D O----------\n");
            printf("%s a continuacion se mostrara el comparativo entre el consumo base y el consumo simulado \n", USER);
            printf("------------------------------------------------------------\n");
            for (int i = 0; i < 24; i++) {
            if (i<12){
            printf("------------------------------------------------------------\n");
            printf("%d:00 AM || BASE: %.2f kwh || SIMULADOR: %.2f kwh\n", i, HORA[i], HSIMULADOR[i]);
            }
           else {
           printf("------------------------------------------------------------\n");
           printf("%d:00 PM || BASE: %.2f kwh || SIMULADOR: %.2f kwh\n", i, HORA[i], HSIMULADOR[i]);
           }
           TOTALBASE= TOTALBASE + HORA[i];
           TOTALSIMULADOR= TOTALSIMULADOR + HSIMULADOR[i];
          }
          printf("------------------------------------------------------------\n");
          printf("\t R E P O R T E  B A S E   V S  S I M U L A D O R\n");
          printf("El total de consumo en base es de %.2f kilivatios en el dia\nEn cambio en el simulador es de %.2f kilovatios simulados al dia\n", TOTALBASE, TOTALSIMULADOR);
          if (TOTALSIMULADOR < TOTALBASE) {
          printf("Excelente %s! consumiste menos en la simulación.\n", USER);
          printf("Ahorraste %.2f kWh, equivalente a $%.2f pesos\n", TOTALBASE-TOTALSIMULADOR, (TOTALBASE-TOTALSIMULADOR) * PRECIOKWH);
          } else if (TOTALSIMULADOR > TOTALBASE) {
          printf("Cuidado %s!, consumiste más en la simulación que en la base.\n", USER);
          printf("Excediste de %.2f kWh, equivalente a $%.2f pesos\n", TOTALSIMULADOR-TOTALBASE, (TOTALSIMULADOR-TOTALBASE) * PRECIOKWH);
          } else {
          printf("Bueno %s, consumiste lo mismo en base y simulador.\n", USER);
          }
        break;
        case 5:
        printf("------------------------------------------------------------\n");  
        printf("\t    ---------- D I A  S I G U I E N T E  ----------\n");
        printf("Bienvenido este es el apartado para pasar al día siguiente \na continuación al elegir esta opción el día en automáticamente cambiará\nEstabas en el día %d", DIACTUAL);
        for(int i = 0; i < 24; i++){
        HORA[i] = HORASAUTO[i] + HORASREPORTE[i];
        DIAS[DIACTUAL][i] = HORA[i];
        }
        HORA[24] = {0};
        HORASREPORTE[24] = {0};
        HSIMULADOR[24] = {0};
        
        DIACTUAL++;
        TOTALDIAS=0;
        TOTALPAGAR=0;
        printf("\n------------------------------------------------------------\n");
        printf("Felicidades acabas de pasar al dia %d\n", DIACTUAL);
        break;
        case 6: 
        printf("\n------------------------------------------------------------\n");
        printf("\t  ---------- V E R  O T R O  R E P O R T E ----------\n");
         printf("%s a continuación podrás escoger qué reporte de otro día quieres ver\n", USER);
         printf("De qué día quieres ver tu reporte\nLas opciones son del día 0 al %d: ", DIACTUAL);
         scanf("%d", &VERDIA);
         if (VERDIA < 0 || VERDIA > DIACTUAL){
        printf("\nDía inexistente\n");
        break;
    }
    printf("\nREPORTE DEL DÍA %d:\n", VERDIA);
    for (int i = 0; i < 24; i++){
        if(i<12){
            printf("A las %d:00 AM tu consumo fue de: %.2f KWH\n", i, DIAS[VERDIA][i]);
        } else {
            printf("A las %d:00 PM tu consumo fue de: %.2f KWH\n", i, DIAS[VERDIA][i]);
        }
    }
    TOTALDIAOTROREPORTE = 0;
    for (int i = 0; i < 24; i++){
        TOTALDIAOTROREPORTE = TOTALDIAOTROREPORTE + DIAS[VERDIA][i];
    }
    printf("------------------------------------------------------------\n");
    printf("%s el total de consumo del día %d fue: %.2f KWH\n", USER, VERDIA, TOTALDIAOTROREPORTE);
    printf("%s el total a pagar ese día sería: $%.2f pesos\n", USER, TOTALDIAOTROREPORTE * PRECIOKWH);
    break;
        case 7: 
        formasAhorrarLuz(USER);
        break;

        case 8:
    printf("\n------------------------------------------------------------\n");
    printf("\t---------- C O M P A R A C I Ó N  D E  D Í A S ----------\n");
    printf("%s, puedes comparar el consumo entre dos días registrados\n", USER);
    printf("Días disponibles: 0 al %d\n", DIACTUAL);
    printf("------------------------------------------------------------\n");
    printf("Ingrese el primer día que deseas comparar: ");
    scanf("%d", &DIA1);
    printf("Ingrese el segundo día que deseas comparar: ");
    scanf("%d", &DIA2);
    if ( DIACTUAL < 0 || DIA1 > DIACTUAL || DIA2 < 0 || DIA2 > DIACTUAL) {
        printf("\n%s ingresaste un dia o ambos inexiste.\n", USER);
        break;
    }
    TOTALDIA1=0;
    TOTALDIA2=0;
    for (int i = 0; i < 24; i++) {
        TOTALDIA1 = TOTALDIA1 + DIAS[DIA1][i];
        TOTALDIA2 = TOTALDIA2 + DIAS[DIA2][i];
    }

    printf("\n------------------------------------------------------------\n");
    printf("Total día %d: %.2f kwh ($%.2f)\n", DIA1, TOTALDIA1, TOTALDIA1 * PRECIOKWH);
    printf("Total día %d: %.2f kwh ($%.2f)\n", DIA2, TOTALDIA2, TOTALDIA2 * PRECIOKWH);
    printf("------------------------------------------------------------\n");
    // Comparar consumos
    if (TOTALDIA1 > TOTALDIA2) {
        printf("El día %d consumió más energía que el día %d.\n", DIA1, DIA2);
        printf("Diferencia: %.2f kWh (equivalente a $%.2f)\n", 
               TOTALDIA1 - TOTALDIA2, (TOTALDIA1 - TOTALDIA2) * PRECIOKWH);
    } else if (TOTALDIA1 < TOTALDIA2) {
        printf("El día %d consumió menos energía que el día %d.\n", DIA1, DIA2);
        printf("Diferencia: %.2f kWh (equivalente a $%.2f)\n", 
               TOTALDIA2 - TOTALDIA1, (TOTALDIA2 - TOTALDIA1) * PRECIOKWH);
    } else {
        printf("Ambos días tuvieron el mismo consumo: %.2f kWh\n", TOTALDIA1);
    }
    printf("------------------------------------------------------------\n");
    break;
    }
    } while (MENUPRINCIPAL != 9);
    
    return 0;
}