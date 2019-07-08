//Elaborado el Reyes Udasco Rachelle Nerie 
//Práctica 0
//Competencia: Reafirmar los conocimientos de la POO diseñando y construyendo programas que utilicen clases.
//27 de agosto del 2018, Grupo 551
//Algoritmos y Estructura de Datos

import javax.swing.JOptionPane;
import java.text.DecimalFormat;

/*Clase Polar*/
public class Polar {
	/*Atributos de la clase Polar*/
	private double modulo;
	private double argumento;
	
	/*Constructor de la clase Polar con dos parametros*/
	public Polar(double modulo, double argumento) {
		this.modulo = modulo;
		this.argumento = argumento;
	}
	
	/*Getters y setters de los atributos de la clase*/
	public double getModulo() { //Getter del atributo modulo
		return modulo;
	}
	public void setModulo(double modulo) { //Setter del atributo modulo
		this.modulo =  modulo;
	}
	public double getArgumento() { //Getter del atributo argumento
		return argumento;
	}
	public void setArgumento(double argumento) { //Setter del atributo argumento
		this.argumento = argumento;
	}
	
	/*Metodo que realiza la multiplicacion de dos numeros Polares*/
	public static Polar multiplicacion(Polar num1, Polar num2) {
		Polar resultado = new Polar(num1.getModulo()*num2.getModulo(),num1.getArgumento() + num2.getArgumento());
		return resultado;
	}
	
	/*Metodo que realiza la division de dos numeros Polares*/
	public static Polar division(Polar num1, Polar num2) {
		Polar resultado = new Polar(num1.getModulo()/num2.getModulo(),num1.getArgumento() - num2.getArgumento());
		return resultado;
	}
	
	/*Metodo que convierte la representacion de un Numero Complejo, de Polar a Rectangular*/
	public Rectangular convertirARectangular() {
		Rectangular rectangular = new Rectangular(this.getModulo()*Math.cos(this.getArgumento()),this.getModulo()*Math.sin(this.getArgumento()));
		return rectangular;
	}
	
	/*Metodo que imprime el numero complejo de forma Polar*/
	public void imprimirPolar(String cadena) {
		DecimalFormat formatoDecimal = new DecimalFormat("#.00000"); //Formato para imprimir 5 decimales
		JOptionPane.showMessageDialog(null,cadena+"\nModulo: " + formatoDecimal.format(this.getModulo())+ "\nArgumento: " +formatoDecimal.format(Math.toDegrees(this.getArgumento())),"FORMA POLAR", JOptionPane.PLAIN_MESSAGE); 
	}
}
