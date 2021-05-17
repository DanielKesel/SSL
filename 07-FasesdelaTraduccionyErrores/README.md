Tarea de investigación
Fases de la Traducción y Errores

1.	Preprocesador:

a.	Procedemos a escribir el programa Hello2.c que es una variante de Hello.c

 ![image](https://user-images.githubusercontent.com/82064789/118426125-041e0c00-b6a1-11eb-9493-84daef7e07b8.png)

b.	Pre-procesamos hello2.c. No lo estamos compilando. Al preprocesar se nos genera el archivo hello2.i:
 
 ![image](https://user-images.githubusercontent.com/82064789/118426150-10a26480-b6a1-11eb-91dc-e67e3b0515b2.png)
 ![image](https://user-images.githubusercontent.com/82064789/118426190-23b53480-b6a1-11eb-8ed0-7d4b5d143363.png)
![image](https://user-images.githubusercontent.com/82064789/118426197-2748bb80-b6a1-11eb-9aff-8531741b7b3e.png)


Observamos que pasa si ejecutamos directamente el hello2.c nos da error por no estar definida prontf:

 ![image](https://user-images.githubusercontent.com/82064789/118426215-30d22380-b6a1-11eb-8d05-0f277b2341ee.png)


Conclusión: Podemos observar dos cosas, en primer lugar, la función prontf no está declarada dentro de la biblioteca estándar stdio.h, por lo que el programa no la reconoce al pre-procesar en el caso del hello2.i y mucho menos compilar en el caso de hello2.c. Por otro lado observamos que la función principal main, no contiene su llave de cierre “}” por lo que el programa no entiende cuando finaliza la función y arroja error.

c.	Escribimos hello3.c cual es una nueva variante:

![image](https://user-images.githubusercontent.com/82064789/118426244-40ea0300-b6a1-11eb-87cd-eb2516bbc037.png)

 
Observamos una nueva función declarada: int printf(const char * restrict s,…), investigando en internet, puede saber que “const char * restrict s” nos indica una restricción como descripción de la salida, por eso, la letra “s” debería estar asociada con placeholders marcados por caracteres de escape "%", para especificar la localización relativa y el tipo de salida que la función debe producir.

Pre-procesamos hello3.c, es decir que no lo compilamos y generamos hello3.i:

![image](https://user-images.githubusercontent.com/82064789/118426262-49423e00-b6a1-11eb-9e39-3cead2563fcc.png) 

Ahora compilamos hello3.c:

![image](https://user-images.githubusercontent.com/82064789/118426289-56f7c380-b6a1-11eb-99da-979dd97efdfa.png)
 
Conclusiones: Podemos observar códigos más parecidos entre hello3.c y hello3.i ya que en hello3.c no colocamos el llamado a la biblioteca estándar stdin.h por lo que no muestra ningún contenido al respecto alguno.


2.	Compilación

a.	Compilamos el resultado y generamos hello3.s, no ensamblamos; 

![image](https://user-images.githubusercontent.com/82064789/118426361-71ca3800-b6a1-11eb-9085-e9db6ab50ee7.png)
![image](https://user-images.githubusercontent.com/82064789/118426374-77c01900-b6a1-11eb-8732-acf34a34e7ed.png)


b.	Compilamos y verificamos donde nos tira error: 

![image](https://user-images.githubusercontent.com/82064789/118426392-7f7fbd80-b6a1-11eb-9846-38adb4583e3a.png)

Procedemos a corregir únicamente el error y no el warning:

![image](https://user-images.githubusercontent.com/82064789/118426433-91616080-b6a1-11eb-8cd2-e477a7ce0a21.png)
![image](https://user-images.githubusercontent.com/82064789/118426556-c8d00d00-b6a1-11eb-857c-4a4a180a301d.png)

 
Verificamos que, al corregir el error, el warning anterior se convirtió en error ya que la función prontf no está declarada ni tampoco se encuentra en la biblioteca estándar.

c. Generamos hello4.s e investigamos sobre el lenguaje ensamblador y el objetivo de este código: 

 ![image](https://user-images.githubusercontent.com/82064789/118426466-a211d680-b6a1-11eb-9430-a7d38fa388be.png)
![image](https://user-images.githubusercontent.com/82064789/118426572-d38aa200-b6a1-11eb-82af-4a37ce3447c1.png)

 
Conclusión: Observamos que, al corregir los errores del programa, se genera todo el lenguaje ensamblador, a diferencia del archivo hello3.s que no vimos código ensamblador alguno. 
Este código ensamblador sirve para que el ensamblador pueda traducir las sentencias en código máquina. Si podemos explicar más específicamente que hace este código ensamblador para el programa hello4.s puntual, está yendo a buscar a las ubicaciones correspondientes de la biblioteca estándar cada registro que contiene la declaración de la variable printf con const char* restrict s
d.	Ensamblamos hello4.s en hello4.o, no vinculamos.
Con el comando en la consola CMD as -o hello4.o hello4.s podemos crear el código objeto a raiz del código ensamblador:
 
 ![image](https://user-images.githubusercontent.com/82064789/118426592-de453700-b6a1-11eb-947c-1e8ffdc47d72.png)
![image](https://user-images.githubusercontent.com/82064789/118426598-e1d8be00-b6a1-11eb-8c7c-a8fcc47489c1.png)

3. Vinculación
a. Vinculamos hello4.o con la biblioteca estándar y generamos el ejecutable. 
Creamos nuestro archivo de biblioteca con el siguiente comando: ar -cvr bibliotecaHello.a hello4.o
 
 ![image](https://user-images.githubusercontent.com/82064789/118426649-ffa62300-b6a1-11eb-8e64-9aaec6a6eca1.png)
 ![image](https://user-images.githubusercontent.com/82064789/118426673-09c82180-b6a2-11eb-8320-1f37fb6f3ef0.png)
 
Luego utilizamos el comando gcc hello4.o -lm para vincular el el código objeto con la biblioteca estándar: 

![image](https://user-images.githubusercontent.com/82064789/118426699-1187c600-b6a2-11eb-80b4-4b9bbd460394.png)

Observamos que no puede linkearse debido a que el programa encuentra un error en la declaración de la función “prontf”

b.	Corregimos en hello5.c y generamos el ejecutable. Solo corregimos lo necesario para que vincule. 
c.	Ejecutamos y analizamos el resultado:
Para corregir el error, cambiamos el nombre de la función prontf por printf que estaba definida arriba:

 ![image](https://user-images.githubusercontent.com/82064789/118426727-25332c80-b6a2-11eb-8a69-4958c5b29241.png)

Observamos que nos imprime la cadena de strings “La respuesta es” y al lado los números “ 12327024”
Conclusión: la impresión de 12327024 es que al definir printf estamos llamando a los “placeholders” para darle formato de salida a la función, al colocar Restrict s, no se sabe bien qué placeholders está tomando.


4	Corrección de Bugs

a.	Corregimos en hello6.c y empezamos de nuevo; verificamos que funciona como se espera.
He corregido el código para hello6.c, ya que la letra i no está dentro del printf, se debe quitar el llamado a los placeholder %d .
 
Vamos a verificar que todos los archivos que todos los archivos se generen correctamente (preprocesador, compilador, ensamblador)
Hello6.i: No tenía incluido la biblioteca estándar por lo que no la muestra en el programa:

 ![image](https://user-images.githubusercontent.com/82064789/118426863-6c212200-b6a2-11eb-875f-65a61619e82d.png)

Hello6.s: Observamos el lenguaje ensamblador:
 
 ![image](https://user-images.githubusercontent.com/82064789/118426885-780ce400-b6a2-11eb-91e1-cdd425605153.png)

Hello6.o: lenguaje máquina (aunque el programa no lo reproduce)
 
 ![image](https://user-images.githubusercontent.com/82064789/118426902-7e9b5b80-b6a2-11eb-9fb9-53cd56f94490.png)
 
Hello6.exe: el ejecutable: 

![image](https://user-images.githubusercontent.com/82064789/118426916-83600f80-b6a2-11eb-8be4-5a2f1a804c4e.png)


5. Remoción de prototipo
a. Escribimos hello7.c, una nueva variante. Observamos que a pesar de no definir printf y no incluir la biblioteca estándar el programa funciona igual.
 
 ![image](https://user-images.githubusercontent.com/82064789/118426953-8eb33b00-b6a2-11eb-8349-5544d9dddf2a.png)

 
Conclusiones: esto es debido a que el linker siempre va a buscar a la biblioteca estándar, y justamente printf forma parte de ella, el motivo de incluir al inicio del programa la inclusión a la biblioteca estándar stdio.h es para “firmar un contrato” en el que se especifica que para este programa se va a usar siempre esa biblioteca.
6. Compilación Separada: Contratos y Módulos
 a. Escribimos studio1.c (sí, studio1, no stdio) y hello8.c. La unidad de traducción studio1.c tiene una implementación de la función prontf, que es solo un wrappwer1 de la función estándar printf:
 
 ![image](https://user-images.githubusercontent.com/82064789/118426975-970b7600-b6a2-11eb-97dc-3bfa5a827c6e.png)
 ![image](https://user-images.githubusercontent.com/82064789/118426989-9d99ed80-b6a2-11eb-984c-be49b93ec8f2.png)

Observamos que si compilamos antes de realizar algún tipo de vinculación entre los dos programas “ .c “ tira error porque no reconoce prontf:
 
 ![image](https://user-images.githubusercontent.com/82064789/118427004-a68abf00-b6a2-11eb-8f1c-ee0fb439bca1.png)
 
Colocando un #include “studio1.c” se vinculan los dos programas y se puede generar el ejecutable:
 
 ![image](https://user-images.githubusercontent.com/82064789/118427028-b1ddea80-b6a2-11eb-9d2d-d8c1a47a287b.png)
 
Observesé que el programa arroja “warning” porque dentro de studio1.c no hay un llamado a la biblioteca estándar, pero como vimos anteriormente, siempre el programa se linkea a la biblioteca estándar.

b.	¿qué ocurre si eliminamos o agregamos argumentos a la invocación de prontf? 

Arroja error por exceso de argumentos:

![image](https://user-images.githubusercontent.com/82064789/118427064-c1f5ca00-b6a2-11eb-8e0f-95218d22e77b.png)
 
Justificación: este error ocurre debido a que al declarar la función printf en studio1.c, solo la definimos para que reciba un solo argumento:
 
 ![image](https://user-images.githubusercontent.com/82064789/118427079-c9b56e80-b6a2-11eb-9ad7-a67b3865dc83.png)
 
c.	Revisitar el punto anterior, esta vez utilizando un contrato de interfaz en un archivo header. 

Escribimos el contrato en studio.h.

![image](https://user-images.githubusercontent.com/82064789/118427101-d934b780-b6a2-11eb-85de-92ac9aa34b23.png)
 
Escribimos hello9.c, un cliente que sí incluye el contrato.

![image](https://user-images.githubusercontent.com/82064789/118427109-ddf96b80-b6a2-11eb-9cc0-f22b5f6e2937.png)

Escribimos studio2.c proveedor que incluye contrato

![image](https://user-images.githubusercontent.com/82064789/118427132-ea7dc400-b6a2-11eb-9559-452ae13b1026.png)
 
¿Qué ventaja da incluir el contrato en los clientes y en el proveedor?
Para generar un ejecutable con todos los programas que hemos creado, utilizamos MAKE:
 
 ![image](https://user-images.githubusercontent.com/82064789/118427144-f2d5ff00-b6a2-11eb-84ef-c1c7f1e317f6.png)

Vemos como se ha generado el ejecutable y funciona correctamente:
 
 ![image](https://user-images.githubusercontent.com/82064789/118427169-fc5f6700-b6a2-11eb-884c-547c5c7ed0c2.png)


Conclusión: Las ventajas de incluir el contrato en el cliente y el proveedor es establecer las funciones y variables en común en ambos programas. Observamos que la función prontf no viene originalmente enla biblioteca estándar, sin embargo, nosotros mediante el contrato studio.h la definimos. Al agregar studio.h al cliente y proveedor nos aseguramos de que las dos partes entiendan por igual “las consignas”.
Punto extra:
Las bibliotecas son archivos (almacenados en una dirección específica del pc o creada externamente) que nos permiten llevar a cabo diferentes tareas sin necesidad de preocuparnos por cómo se hacen sino simplemente entender cómo usarlas. Las bibliotecas permiten hacer nuestros programas más simples y reutilizables, facilitando además crear programas con funcionalidades bastante complejas en unas pocas líneas de código.
El estándar definido ANSI en c, en cuanto a su portabilidad consta de 24 ficheros cabecera que pueden ser incluidos en un proyecto de programación con una simple directiva. Cada cabecera contiene la declaración de una o más funciones, tipos de datos y macros. La principal ventaja del reducido tamaño de la biblioteca estándar de C es que construir un entorno de trabajo en ANSI C es muy fácil y, en consecuencia, portar un programa en ANSI C de una plataforma a otra es relativamente fácil.
Cómo desventaja podríamos considerar que muchas de las funciones definidas en la biblioteca no son utilizadas para programas cortos. Por otro lado, la biblioteca estándar ANSI es tan sencilla que puede ser contraproducente en programas más complejos, por ejemplo el caso de studio.h que tuvimos que agregar la función prontf que no estaba definida en la biblioteca estándar.
