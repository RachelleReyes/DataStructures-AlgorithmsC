//Elaborado el Reyes Udasco Rachelle Nerie 
//Práctica 0
/*
	 Competencia: Reafirmar los conocimientos de la POO diseñando y construyendo programas que utilicen clases.
	Un número complejo z=x+iy se puede representar también en forma polar r,theta.
	Las operaciones de suma y resta de dos números complejos se pueden realizar directamente en este formato, 
	sin embargo, la multiplicación y la división requiere que los números se conviertan a su forma polar.
	
	Para convertir de la forma polar a rectangular.
	r=sqrt(x2+y2)
	theta=tan-1
	(y/x)

	Se pide que capture dos números en su forma rectangular y a continuación presente un menú que permita al 
	usuario efectuar N veces las operaciones aritméticas básicas. Las funciones que se le pide implementar son:
	1. Suma de dos números complejos.
	2. Resta de dos números complejos.
	3. Multiplicación de dos números complejos.
	4. División de dos números complejos.
	5. Salir

	- Los números deben capturarse en forma rectangular.
	- Los objetos de la clase polar deben crearse a partir de los objetos de los número	complejos, es decir NO van a ser capturados por el usuario.
	- Los números deben convertirse a la forma polar para las operaciones de multiplicación y división.
	- Las operaciones solo se pueden realizar si se han capturado ambos números.
	- Cada número complejo es un objeto distinto.
	- El objeto para forma rectangular solo puede contener un número complejo en su forma rectangular (x+iy).
	- El objeto para forma polar solo puede contener un número complejo en su forma polar (x+iy).
	- Las operaciones de multiplicación y división se deben realizar utilizando la forma polar de ambos números.
	- En todos los casos se deben mostrar los datos y resultados en forma rectangular y forma polar.
	- El programa debe repetirse N veces hasta que se elija la opción de salida.
	- El lenguaje para esta práctica es Java.
	- Durante la clase se revisará el modelado de las clases.
  */
//27 de agosto del 2018, Grupo 551
//Algoritmos y Estructura de Datos

//Declaraciones de importacion
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;
import java.text.DecimalFormat;

/*Clase Principal utilizada para ejecutar la clase Polar y Numeros Complejos*/
public class Principal {

	/*Metodo Principal (main)*/
	public static void main(String [] args) {
		Principal principal = new Principal();
		
		/*Declaracion de variables*/
		String [] opciones = {"SUMA", "RESTA", "MULTIPLICACION", "DIVISION"}; //Operaciones Aritmeticas
		String [] cadenaCapturado = new String[2]; //Numeros que se capturan en las ventanas
		Rectangular rectangular1, rectangular2, resultadoRectangular = new Rectangular(0,0); //Declaracion de objetos de la clase Rectangular
		Polar polar1, polar2, resultadoPolar = new Polar(0,0); //Declaracion de objetos de la clase Polar
		int salir = 0, repetir, otraOperacion=0; 
		DecimalFormat formatoDecimal = new DecimalFormat("#.00000"); //Formato para imprimir 5 decimales
	
		
		do { //Ciclo do while que controla si el usuario desea ingresar otros numeros
			/*Captura de numeros*/
			cadenaCapturado = principal.capturarNumeros("Numero Complejo 1 en forma Rectangular");
			rectangular1 = new Rectangular(Double.parseDouble(cadenaCapturado[0]),Double.parseDouble(cadenaCapturado[1])); //Inicializa el primer numero complejo
			cadenaCapturado = principal.capturarNumeros("Numero Complejo 2 en forma Rectangular");
			rectangular2 = new Rectangular(Double.parseDouble(cadenaCapturado[0]),Double.parseDouble(cadenaCapturado[1])); //Inicializa el segundo numero complejo
			
			/*Conversion de rectangular a polar*/
			polar1 = rectangular1.convertirAPolar();
			polar2 = rectangular2.convertirAPolar();

			do{ //Ciclo do while que controla si el usuario desea realizar otra operacion con los mismos numeros
			
				//Ventana que pregunta al usuario el tipo de operacion desea realizar
				String elegido = (String)JOptionPane.showInputDialog(null,"Seleccione una operacion", "OPERACIONES", JOptionPane.QUESTION_MESSAGE, null, opciones,opciones[0]);
				
				/*Comparacion del tipo de operacion*/
				switch(elegido) {
					case "SUMA" : 				
						resultadoRectangular = Rectangular.suma(rectangular1, rectangular2);
						break;
					case "RESTA" : 
						resultadoRectangular = Rectangular.resta(rectangular1, rectangular2);
						break;
					case "MULTIPLICACION":
						resultadoPolar = Polar.multiplicacion(polar1, polar2);
						break;
					case "DIVISION":
						resultadoPolar= Polar.division(polar1, polar2);
						break;
				}
				
				/*Conversion de rectagular a polar (suma o resta), polar a rectangular (multiplicacion o division)*/
				if(elegido=="SUMA" ||elegido=="RESTA" ) {
					resultadoPolar = resultadoRectangular.convertirAPolar();
				} else if(elegido=="MULTIPLICACION" ||elegido=="DIVISION" ) {
					resultadoRectangular = resultadoPolar.convertirARectangular();
				} 
				
				/*Impresion de resultados*/
				resultadoRectangular.imprimirRectangular(elegido + " de " + rectangular1.getNum_real() +"+" + rectangular1.getNum_imaginario() +"i y " + rectangular2.getNum_real() +"+" + rectangular2.getNum_imaginario() +"i \n\nResultado:" );
				resultadoPolar.imprimirPolar(elegido + " de r=" + formatoDecimal.format(polar1.getModulo()) +", theta:" + formatoDecimal.format(polar1.getArgumento())+ " y \nr=" + formatoDecimal.format(polar2.getModulo()) +", theta: " + formatoDecimal.format(polar2.getArgumento())+ "\n\nResultado:");
		
				otraOperacion = JOptionPane.showConfirmDialog(null, "¿Deseas elegir otra operacion?","Selcciona una opcion",JOptionPane.YES_NO_CANCEL_OPTION);
				if (JOptionPane.OK_OPTION == otraOperacion){
					otraOperacion = 1;
				} else {
					otraOperacion =0;
				}	
					
			} while(otraOperacion==1);
				
			/*Pregunta para repeticion del ciclo do while*/
			repetir = JOptionPane.showConfirmDialog(null, "¿Deseas capturar otros numeros?","Selcciona una opcion",JOptionPane.YES_NO_CANCEL_OPTION);
			if (JOptionPane.OK_OPTION == repetir){
				salir = 1;
			} else {
				salir =0;
			}	
				
		}while(salir==1);
	}

	/*Metodo que despliega una ventana para capturar numeros complejos en forma rectangular*/
	public String [] capturarNumeros(String cadena) {
		String [] cadenaRecibido = new String[2];
		int resultado;
		
		/*Campos de texto para los dos valores*/
		JTextField primerCampo = new JTextField(7);
	    JTextField segundoCampo = new JTextField(7);
	    
	    /*Creacion y agregacion de los componentes (JTextField y JLabel) al JPanel*/
	    JPanel seccionPanel = new JPanel();
		seccionPanel.add(primerCampo);
	    seccionPanel.add(new JLabel("+"));
	    seccionPanel.add(segundoCampo);
		seccionPanel.add(new JLabel("i"));
	
		/*Ciclo que captura numeros con validacion*/
		do {
		    resultado = JOptionPane.showConfirmDialog(null, seccionPanel, cadena, JOptionPane.OK_CANCEL_OPTION,JOptionPane.PLAIN_MESSAGE);
		     if (resultado == JOptionPane.OK_OPTION) {
		    	 cadenaRecibido[0] = primerCampo.getText(); //Obtiene el numero real del primer campo de texto
		    	 cadenaRecibido[1] = segundoCampo.getText(); //Obtiene el numero imaginario del segundo campo de texto
		     } 
		} while(!esNumero(cadenaRecibido[0]) || !esNumero(cadenaRecibido[1]));  //No termina si uno de los valores contienen caracteres no validos para la operacion
		
		return cadenaRecibido;
	}

	/*Metodo para validar si la cadena aceptada es un double*/
	public boolean esNumero(String cadena) {
		boolean resultado;
		
		/*Intenta convertir la cadena a double, si no lo logra regresa un valor 0 booleano*/
        try {
            Double.parseDouble(cadena);
            resultado = true;
        } catch (NumberFormatException excepcion) {
            resultado = false;
        }
        return resultado;
	}
}
