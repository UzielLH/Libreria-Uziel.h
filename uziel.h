#include<iostream> //Sirve para manejar la entrada y salida de datos
#include<windows.h> //Sirve para programar aplicaciones de windows como un ejemplo es la gestion de ventanas
#include<conio.h> //La estaremos ocupando para el getch que sirve para que el usuario toque una tecla para seguir o terminar y el limpiador de pantalla
#include<ctime> //Libreria ocupada para que no haya error en la función delay, maneja los tiempos del sistema
#include<string> //Libreria ocupada para manejar cadenas de texto
#include<windows.h> //Sirve para programar aplicaciones de windows como un ejemplo es la gestion de ventanas
#include<sstream> //se utiliza para trabajar con cadenas de caracteres de manera similar a la forma en que trabajamos con archivos
#include <cstring> //proporciona funciones para trabajar con cadenas de caracteres.
#include<cstdlib>
#include<iomanip>
#include<fstream>
#include <math.h>
using namespace std; // permite que los identificadores definidos en el espacio esten disponibles sin utilizar el prefijo std:: en cada uso

//Se definen al principio todas las funciones que incluye el codigo

void posxy(int x, int y);										    //Funcion para ubicar en la pantalla algo
void marco(int renglones, int columnas,int ubicolum,int ubirenglon);//Funcion para realizar el marco
void delay(int secs);											   	//Funcion para que no salga todo de golpe y vaya apareciendo poco a poco
void centraStr(string texto,int y);									//Funcion para centrar el texto
void color(int x);													//Funcion para ponerle color a una cadena de caracteres
void izquierda(const char *texto, int y);							//Funcion para colocar el texto en la derecha
string intTostr(int n);												//Funcion para convertir un entero a string
int strToint(string texto);											//Funcion para convertir un string a entero
string lPad(string texto, char chr, int n);							//Funcion para podder agregar un caracter al lado
string rPad(string texto, char chr, int n);
string substr(string texto, int npos, int num);						//Funcion para sustraer una parte de un string
string todoamayusculas(string texto);								//Funcion para convertir todo a mayusculas
string todoaminusculas(string texto);								//Funcion para convertir todo a minusculas
void ordenarnumerosburbuja(float numeros[],int cantidad);			//ordenamiento burbuja
void ordenar_cadena(string cadena, char* cadenaminusculas, int cantidad);	//ordenamiento burbuja alfanumerico
void ordenarnombres(string nombres[], int cantidad);				//ordenar nombres por ordenamiento burbuja
void cuadricula( int filas , int columnas, int iniciox, int inicioy);
void cuadricula2( int filas , int columnas, int iniciox, int inicioy);
void redondeo(float num, int cantidad);
string esperarentradastring( int x, int y);
int esperarentradaint(int x, int y);
float esperarentradafloat(int x, int y);
void cuadricula3( int filas , int columnas, int iniciox, int inicioy);
float  strTofloat(string cadena);
string floatTostr(float valor);
int entero(float valor);
float decimal(float valor);
 

//la funcion recibe cuatro valores, las cuales los dos primeros son el tamaño del marco, y los otros dos son ubicacion
void marco(int renglones, int columnas,int ubicolum,int ubirenglon){ 
/*Se declara una variable char con el nombre de c, la cual va a recibir un numero
pero checando la tabla ascii este va a representar un valor por lo que se quieremos
traer un caracter solo agregamos el numero deseado, aqui se va a ir inicializado un valor*/
char c;	
	//a traves de la tabla ascii el numero 201 hace referencia al caracter de marco doble que va en la esquina superior izquierda															 
	c=201;													
	//Se ubica en donde vaya a empezar el marco	
	posxy(ubicolum,ubirenglon);cout<<c;
	//a traves de la tabla ascii el numero 187 hace referencia al caracter de marco doble que va en la esquina superior derecha						
	c=187;
	//Para la ubicacion en el eje x se le tiene que sumar en valor de la ubicacion para que empiece a correr desde ahi el marco
	posxy(columnas+ubicolum,ubirenglon);cout<<c;
	//a traves de la tabla ascii el numero 200 hace referencia al caracter de marco doble que va en la esquina inferior izquierda
	c=200;
	//Para la ubicacion en el eje y se le tiene que sumar en valor de la ubicacion para que empiece a correr desde ahi el marco
	posxy(ubicolum,renglones+ubirenglon);cout<<c;
	//a traves de la tabla ascii el numero 188 hace referencia al caracter de marco doble que va en la esquina inferior derecha
	c=188;
	//Para la ubicacion en el eje x y y se le tiene que sumar en valor de la ubicacion para que empiece a correr desde ahi el marco
	posxy(columnas+ubicolum,renglones+ubirenglon);cout<<c;
	//a traves de la tabla ascii el numero 205 hace referencia al caracter de marco doble que es horizontal
	c=205;
	/*Se ocupa el ciclo for para poder hacer que coloque las rayas horizontales, al inicio de valor se le tiene
	quedar un valor de +1 para que no empiece en donde colocamos la esquina y llegara hasta uno antes de la otra esquina
	se le hace la respectiva suma, y va a ir incrementando i de uno en uno*/
	for (int i=(ubicolum+1);i<ubicolum+columnas;i++){
		posxy(i,ubirenglon);cout<<c;				//se ocupa un poxy para poder ubicar en donde colocaran las rayas superiores, y se va imprimiendo
		posxy(i,renglones+ubirenglon);cout<<c;		//se ocupa los valores del poxy para ubicar las rayas inferiores a la ubicacion de renglon se le suma el tamaño del marco y se va imprimiendo
	}
	//a traves de la tabla ascii el numero 205 hace referencia al caracter de marco doble que es vertical
	c=186;
	/*Se ocupa el ciclo for para poder hacer que coloque las rayas verticales, al inicio de valor se le tiene
	quedar un valor de +1 para que no empiece en donde colocamos la esquina y llegara hasta uno antes de la otra esquina
	se le hace la respectiva suma, y va a ir incrementando i de uno en uno*/
	for (int x=(ubirenglon+1);x<renglones+ubirenglon;x++){
		posxy(ubicolum,x);cout<<c;					//se ocupa un posxy para poder ubicar en donde colocaran las rayas de la izquierda y se va imprimiendo
		posxy(columnas+ubicolum,x);cout<<c;			//se ocupa los valores del posxy para ubicar las rayas inferiores a la ubicacion de renglon se le suma el tamaño del marco y se va imprimiendo
	}
}

//Esta funcion tiene como objetivo ubicar y colocar algo en una coordenada de la ventana,para que funcione se solicitan dos valores, x y y.
void posxy(int x, int y){			
	COORD coordenada;		//se declara una variable tipo COORD que almacenara coordenadas de alguna posicion de nuestra ventana
	coordenada.X=x;			//Se le asignan el valor de x que ingrese a la funcion al miembro que pertenece a COORD que es X ya que movera el cursor en este eje
	coordenada.Y=y;			//Se le asignan el valor de y que ingrese a la funcion al miembro que pertenece a COORD que es Y ya que movera el cursor en este eje
	/*Se llama a la funcion SetConsoleCursorPosition que establece la posicion del cursor de la consola, esta toma dos argumentos, 
	uno que es GetStdHandle(STD_OUTPUT_HANDLE) que sirve para obtener el identificador del dispositivo de salida de la consola, y coordenada
	donde se traen las ubicaciones */ 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordenada);
}

//La siguiente funcion tiene como objetivo retrasar la ejecucion por algunos segundos, yendo poco a poco formandola,esta recibe un valor entero de cuanto se le atrasara
void delay(int secs){
	/*Se utiliza un for para relentizar la funcion, para que salga poco a poco, mediante la cantidad mencionada en secs,
	se crea una variable i que se inicializa con la suma de la hora actual del sistema mas la cantidad de segundos especificadas,
	esta se ejecuta mientras que time(null) no sea igual a i, y en cada iteracion se obtiene la hora actual del sistema, el objetivo es
	que la condicion del bucle no se cumplirá hasta que la hora actual del sistema sea mayor o igual a i*/
	for (int i=(time(NULL)+secs);time(NULL) !=i;time(NULL));
}


//La siguiente funcion tiene como objetivo centrar el texto, se le ingresaria la cadena de texto a centrar y el renglon en donde se ubicaria
void centraStr(string texto,int y){
	//Se declara una variable entera nlen que contiene la longitud de la cadena texto utilizando la función length()
	int nlen=texto.length();
	/*Se ocupa posxy para ubicar en pantalla en donde colocar el string, para calcular el valor de x, se hace la resta de 39
	que es mas o menos el centro, entre la longitud de la cadena dividida entre 2, y el valor de y es el que ingresa al principio
	y de ahi imprime la cadena en ese lugar */
	posxy(39-(nlen/2),y);cout<<texto;
}

//La siguiente funcion tiene como objetivo colocar un texto en la derecha, ingresa un puntero de char texto y la ubicacion en y
void izquierda(const char *texto, int y){
	//Se declara una variable entera nlen que contiene la longitud del texto utilizando la funcion strlen de la biblioteca string
	int nlen=strlen(texto);
	/*Llama a la funcion poxy para ubicar el cursor en la consola, la posicion se calcula 79, donde es el limite del marco por decir
	menos el tamaño de la frase para dejarla exacto en la esquina, en y seria dada al ingresar a la funcion y se escribe el texto*/
	posxy(79-(nlen),y);cout<<texto;
}

//Esta funcion sirve para cambiar de color a una cadena de cout, la cual se le ingresara el codigo del color mediante RGB
void color(int x){
	/*Establece el atributo de color de la consola utilizando la función SetConsoleTextAttribute(). El primer argumento es el identificador
	 de la salida estándar de la consola, que se obtiene utilizando la función GetStdHandle().El segundo argumento es un número entero x 
	 que especifica el color que queramos meter a nuestro cadena de texto.*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
}

//Esta funcion tiene como objetivo convertir un valor entero a un valor string, la cual se le ingresa un valor entero.
string intTostr(int n){
	//Se delcara un objeto ostringstream llamado stream
	ostringstream stream;
	//stream para escribir el valor del entero n. Esto convierte el número entero en una cadena de texto.
	stream<<n;
	//asigna la cadena de texto creada a la variable string llamada cadena.
	string cadena=stream.str();
	//Devuelve la cadena de texto.
	return cadena;
}

//Esta funcion tiene como objetivo transformar una cadena de texto en una entero, la cual se le ingresa a la funcion un dato string
int strToint(string texto){
	//Se declara un puntero llamado valor y asigna a este puntero la dirección de memoria de la cadena de texto texto utilizando la función c_str().
	const char *valor=texto.c_str();
	//Convierte la cadena de texto a un entero con la funcion atoi.
	int result=atoi(valor);
	//Se imprime el dato entero como resultado.
	return result;
}

/*Esta funcion sirve para agregar caracteres al principio de una cadena de texto, la cual se ingresan 3 argumentos
uno que es la frase o cadena de texto, el siguiente es el numero que le queremos agregar al principio de la cadena
y el tercero es de que tamaño queremos la cadena*/
string lPad(string texto, char chr, int n){
	//se declara una cadena de texto con el nombre result para almacenar la cadena final
	string result;
	//Se calcula el tamaño de la cadena de texto y se guarda en la variable entera nlen
	int nlen=texto.length();
	/*Se ocupa un for para poder agregar el caracter 'chr' al principio de la cadena de texto "Texto" hasta que la longitud
	de la cadena sea igual a n, para saber cuantos caracteres se van agregar se hace restando el tamaño que queremos de la
	cadena menos el tamaño del string texto, */
	for (int i=0;i<(n-nlen);i++) result+=chr;
	//Agrega la cadena texto original al final de la cadena result
	result+=texto;
	//Devuelve la cadena con los caracteres que queriamos y su respectivo tamaño
	return result;
}

string rPad(string texto, char chr, int n){
	//se declara una cadena de texto con el nombre result para almacenar la cadena final
	string result=texto;
	//Se calcula el tamaño de la cadena de texto y se guarda en la variable entera nlen
	int nlen=texto.length();
	/*Se ocupa un for para poder agregar el caracter 'chr' al principio de la cadena de texto "Texto" hasta que la longitud
	de la cadena sea igual a n, para saber cuantos caracteres se van agregar se hace restando el tamaño que queremos de la
	cadena menos el tamaño del string texto, */
	for (int i=0;i<(n-nlen);i++) result+=chr;
	//Devuelve la cadena con los caracteres que queriamos y su respectivo tamaño
	return result;
}


/*La siguiente funcion trata de extraer una subcadena a partir de una cadena de texto dada, nosotros
decidimos desde que parte de la cadena queremos recuperar y cuantos caracteres necesitamos*/ 
string substr(string texto, int npos, int num){
	//Se declara una cadena de texto llamada result la cual guardara el resultado final
	string result="";
	//Se obtiene la longitud de la cadena mediante el .length() y se guarda en la variable entera nlen
	int nlen=texto.length();
	//Se convierte la cadena en una cadena de caracteres para ir tomando los valores
	const char* cad=texto.c_str();
	//Se ocupa un for para manipular la cadena decaracteres de cad que se encuentran entre las posiciones npos-1 y npos-1+num.
	for (int i=npos-1;i<(npos-1+num);i++){
		//Si la variable i es menor que nlen, se agrega el caracter a la cadena result.
		if (i<nlen) result+=cad[i];
	}
	//Devuelve la cadena de texto final con los datos que queriamos
	return result;
}

//La siguiente funcion tiene como objetivo transformar una cadena de texto completamente a mayusculas, la cual se le tiene que ingresar un string
//NOTA:Para ocuparla tenemos que pedir la cadena como getline(cin, texto);
string todoamayusculas(string texto) {
	//Se calcula el tamaño de la frase o cadena de caracteres que ingresamos y se guarda en una variable entera denominada b, para esto se ocupa .length()
	int b=texto.length();
	/*Se ocupa un for que va recorriendo cada caracter de la cadena original.
	Se ocupa b para saber cuando llega al limite i y este va a ir aumentando de uno en uno*/
    for (int i=0; i<b; i++) {
    	// se ocupa if para saber si el caracter esta entre los rangos de las minusculas las cuales van del 97 al 122, si hay una mayuscula ya no entra al ciclo
        if (texto[i]>=97 && texto[i]<=122) { 
        	/*Si se encuentra en este rango se le resta 32 ya que hay una diferencia de 32 espacios entre la mayuscula y la minuscula
        	y este guarda el nuevo valor que seria el de la mayuscula,*/
            texto[i]-=32;
        }
    }
    //Esta devuelve una cadena de texto con la cadena original transformada todo a mayuscula
    return texto;
}

//La siguiente funcion tiene como objetivo transformar una cadena de texto completamente a mayusculas, la cual se le tiene que ingresar un string
//NOTA:Para ocuparla tenemos que pedir la cadena como getline(cin, texto);
string todoaminusculas(string texto) {
	//Se calcula el tamaño de la frase o cadena de caracteres que ingresamos y se guarda en una variable entera denominada b, para esto se ocupa .length()
	int b=texto.length();
	/*Se ocupa un for que va recorriendo cada caracter de la cadena original.
	Se ocupa b para saber cuando llega al limite i y este va a ir aumentando de uno en uno*/
    for (int i=0; i<b; i++) {
    	// se ocupa if para saber si el caracter esta entre los rangos de las mayusculas las cuales van del 65 al 90, si hay una minuscula ya no entra al ciclo
        if (texto[i]>=65 && texto[i]<=90) { 
        	/*Si se encuentra en este rango se le suma 32 ya que hay una diferencia de 32 espacios entre la mayuscula y la minuscula
        	y este guarda el nuevo valor que seria el de la minuscula,*/
            texto[i]+=32;
        }
    }
    //Esta devuelve una cadena de texto con la cadena original transformada todo a minuscula
    return texto;
}

//Es la funcion donde se va a ordenar los numeros mediante el ordenamiento burbuja
void ordenarnumerosburbuja(float numeros[],int cantidad){
	//Se declara la variable aux de tipo entero, que usaremos para intercambiar elementos en el arreglo.
	int aux;
	/*Iniciamos un ciclo for que va desde el primer elemento del arreglo hasta el penúltimo elemento.
	 La idea de este ciclo es recorrer todo el arreglo varias veces para ir ordenando los elementos*/
		for(int i = 0; i < cantidad-1; i++) {
			/*niciamos otro ciclo for que va desde el primer elemento del arreglo hasta el último elemento que no está aún ordenado. 
			La idea de este ciclo es comparar los elementos siguientes y hacer intercambios si es necesario.*/
	        for(int j = 0; j < cantidad-i-1; j++) {
	        //Si el elemento en la posición j es mayor que el elemento en la posición j+1, entonces se hace un intercambio de elementos.
	           if(numeros[j] > numeros[j+1]) {
            	//aux que es en donde se guardaran los nuevos elementos para intercambiar guarda el valor
	                aux = numeros[j];
	                //El valor siguiente toma el valor en donde esta posicionado
	                numeros[j] = numeros[j+1];
	                //El siguiente valor toda el valor de aux.
	                numeros[j+1] = aux;
			            }
			        }
			    }
}

/*La siguiente funcion tiene como objetivo ordenar los caracteres de una string, donde se pide el string, la cadena 
en donde se va a guardar y la cantidad de letras, siempre se le tiene que sumar +1 por el valor nulo antes
*/
void ordenar_cadena(string cadena, char* cadenaminusculas, int cantidad) {
	//se crea una nueva cadena donde este obtendra la cadena convertida en minusculas
    string cadenamodificada = todoaminusculas(cadena);
    /*se ocupa la funcion strcpy para copiar una cadena de caracteres en otra, se ocupa .c_str
	La función c_str() se utiliza para obtener una representación constante de la cadena de 
	caracteres en forma de un puntero a una cadena de caracteres tipo const char*.
	*/
    strcpy(cadenaminusculas, cadenamodificada.c_str());
    //Se declara la variable aux de tipo entero, que usaremos para intercambiar elementos en el arreglo.
    int aux;
    /*Iniciamos un ciclo for que va desde el primer elemento del arreglo hasta el penúltimo elemento.
	 La idea de este ciclo es recorrer todo el arreglo varias veces para ir ordenando los elementos*/
    for(int i = 0; i < cantidad-1; i++) {
    	/*niciamos otro ciclo for que va desde el primer elemento del arreglo hasta el último elemento que no está aún ordenado. 
			La idea de este ciclo es comparar los elementos siguientes y hacer intercambios si es necesario.*/
        for(int j = 0; j < cantidad-i-1; j++) {
        	//Si el elemento en la posición j es mayor que el elemento en la posición j+1, entonces se hace un intercambio de elementos, se ocupa tabla ascii
            if(cadenaminusculas[j] > cadenaminusculas[j+1]) {
            	//aux que es en donde se guardaran los nuevos elementos para intercambiar guarda el valor
                aux = cadenaminusculas[j];
                //El valor siguiente toma el valor en donde esta posicionado
                cadenaminusculas[j] = cadenaminusculas[j+1];
                //El siguiente valor toda el valor de aux.
                cadenaminusculas[j+1] = aux;
            }
        }
    }
}
//La siguiente funcion tiene como objetivo ordenar nombres, se solicita al usuario la cantidad de nombres y cuales seran
void ordenarnombres(string nombres[], int cantidad){
	//Se crea una variable string donde nos ayudara para hacer el metodo burbuja cuando se intercambien lugares
	string aux;
	/*Iniciamos un ciclo for que va desde el primer elemento del arreglo hasta el penúltimo elemento.
	 La idea de este ciclo es recorrer todo el arreglo varias veces para ir ordenando los elementos*/
	for (int i = 0; i < cantidad-1; i++) {
		/*niciamos otro ciclo for que va desde el primer elemento del arreglo hasta el último elemento que no está aún ordenado. 
			La idea de este ciclo es comparar los elementos siguientes y hacer intercambios si es necesario.*/
    for (int j = 0; j < cantidad-i-1; j++) {
    	/*Se va a estar comparando mediante la tabla ascii por los valores,Si el elemento en la posición j es mayor que 
		el elemento en la posición j+1, entonces se hace un intercambio de elementos, solo considerara la primera letra*/
      if (nombres[j] > nombres[j+1]) {
      	//aux que es en donde se guardaran los nuevos elementos para intercambiar guarda el valor
        aux = nombres[j];
        //El valor siguiente toma el valor en donde esta posicionado
        nombres[j] = nombres[j+1];
        //El siguiente valor toda el valor de aux.
        nombres[j+1] = aux;
      }
    }
  }
}

void cuadricula( int filas , int columnas, int iniciox, int inicioy){
	char c;
	for(int j=inicioy;j<=(filas*2+inicioy); j=j+2){
		for(int i=iniciox; i<=(columnas*10+iniciox); i++){
			//linea horizontal
		c=196;
		posxy(i,j);cout<<c;
		}
	}		
	for(int j=inicioy;j<=(filas*2+inicioy); j++){
	for(int i=iniciox; i<=(columnas*10+iniciox); i=i+10){
		//linea vertical
		c=179;
		posxy(i,j);cout<<c;
 }
	}	
	c=218;//esquina superior izquierda
	posxy(iniciox,inicioy);cout<<c;
	c=192;//esquina inferior izquierda
	posxy(iniciox,inicioy+(filas*2));cout<<c;
	c=191;//esquina superior derecha
	posxy(columnas*10+iniciox,inicioy);cout<<c;
	c=217;//esquina inferior derecha
	posxy(columnas*10+iniciox, filas*2+inicioy);cout<<c;
	for(int j=(1);j<(filas); j++){
		for(int i=(1); i<(columnas); i++){
			//esquina superior
			c=194;
			posxy(i*10+iniciox, inicioy );cout<<c;
			//esquina inferior
			c=193;
			posxy(i*10+iniciox, filas*2+inicioy );cout<<c;	
			//Intersecciones
			c=197;
			posxy(i*10+iniciox, j*2+inicioy );cout<<c;
			//Esquinas izquierda
			c=195;
			posxy(iniciox,j*2+inicioy);cout<<c;
			//Esquina derecha
			c=180;
			posxy(columnas*10+iniciox, j*2+inicioy );cout<<c;
		}		
	}		
	}
	
void cuadricula2( int filas , int columnas, int iniciox, int inicioy){
	char c;
	for(int j=inicioy;j<=(filas*2+inicioy); j=j+2){
		for(int i=iniciox; i<=(columnas*20+iniciox); i++){
		c=196;
		posxy(i,j);cout<<c;
		}
	}		
	for(int j=inicioy;j<=(filas*2+inicioy); j++){
	for(int i=iniciox; i<=(columnas*20+iniciox); i=i+20){
		c=179;
		posxy(i,j);cout<<c;
 }
	}	
	c=218;//esquina superior izquierda
	posxy(iniciox,inicioy);cout<<c;
	c=192;//esquina inferior izquierda
	posxy(iniciox,inicioy+(filas*2));cout<<c;
	c=191;//esquina superior derecha
	posxy(columnas*20+iniciox,inicioy);cout<<c;
	c=217;//esquina inferior derecha
	posxy(columnas*20+iniciox, filas*2+inicioy);cout<<c;
	for(int j=(1);j<(filas); j++){
		for(int i=(1); i<(columnas); i++){
			//esquina superior
			c=194;
			posxy(i*20+iniciox, inicioy );cout<<c;
			//esquina inferior
			c=193;
			posxy(i*20+iniciox, filas*2+inicioy );cout<<c;	
			//Intersecciones
			c=197;
			posxy(i*20+iniciox, j*2+inicioy );cout<<c;
			//Esquinas izquierda
			c=195;
			posxy(iniciox,j*2+inicioy);cout<<c;
			//Esquina derecha
			c=180;
			posxy(columnas*20+iniciox, j*2+inicioy );cout<<c;
		}		
	}		
	}
	
void redondeo(float num, int cantidad){
	cout<<fixed<<setprecision(cantidad)<<num;
}

string esperarentradastring( int x, int y) {
	string entrada;
    posxy(x,y);
    while (true) {
        getline(cin,entrada);  
        if (!entrada.empty()) { 
            break; 
        }
        posxy(x,y);
    }
    return entrada;
}
int esperarentradaint(int x, int y) {
    int entrada;
    string strEntrada;
    posxy(x,y);
    while (true) {
        getline(cin, strEntrada);
        stringstream ss(strEntrada);
        if (ss >> entrada && ss.eof()) {
            break;
        }
        posxy(x,y);
    }
    return entrada;
}
float esperarentradafloat(int x, int y) {
    float entrada;
    string strEntrada;
    posxy(x,y);
    while (true) {
        getline(cin, strEntrada);
        stringstream ss(strEntrada);
        if (ss >> entrada && ss.eof()) {
            break;
        }
        posxy(x,y);
    }
    return entrada;
}

void cuadricula3( int filas , int columnas, int iniciox, int inicioy){
	char c;
	for(int j=inicioy;j<=(filas*2+inicioy); j=j+2){
		for(int i=iniciox; i<=(columnas*15+iniciox); i++){
		c=196;
		posxy(i,j);cout<<c;
		}
	}		
	for(int j=inicioy;j<=(filas*2+inicioy); j++){
	for(int i=iniciox; i<=(columnas*15+iniciox); i=i+15){
		c=179;
		posxy(i,j);cout<<c;
 }
	}	
	c=218;//esquina superior izquierda
	posxy(iniciox,inicioy);cout<<c;
	c=192;//esquina inferior izquierda
	posxy(iniciox,inicioy+(filas*2));cout<<c;
	c=191;//esquina superior derecha
	posxy(columnas*15+iniciox,inicioy);cout<<c;
	c=217;//esquina inferior derecha
	posxy(columnas*15+iniciox, filas*2+inicioy);cout<<c;
	for(int j=(1);j<(filas); j++){
		for(int i=(1); i<(columnas); i++){
			//esquina superior
			c=194;
			posxy(i*15+iniciox, inicioy );cout<<c;
			//esquina inferior
			c=193;
			posxy(i*15+iniciox, filas*2+inicioy );cout<<c;	
			//Intersecciones
			c=197;
			posxy(i*15+iniciox, j*2+inicioy );cout<<c;
			//Esquinas izquierda
			c=195;
			posxy(iniciox,j*2+inicioy);cout<<c;
			//Esquina derecha
			c=180;
			posxy(columnas*15+iniciox, j*2+inicioy );cout<<c;
		}		
	}		
	}
	
float  strTofloat(string cadena){
    float valor;
       stringstream paso(cadena);
       paso >> valor;
    if (!paso.fail()) {
        return valor;
    } else {
        cout << "La conversión ha fallado." << endl;
        return 0;
    }
       return valor;
} 

string floatTostr(float valor) {
    char buffer[50];
    sprintf(buffer, "%.6f", valor);
    string cadena(buffer);
    return cadena;
}

int entero(float valor){
    int nEntero = static_cast<int>(valor);
    return nEntero;
}

float decimal(float valor){
 
    int nEntero=entero(valor);
    float nDecimal=valor-nEntero;
    return nDecimal;
}
 

