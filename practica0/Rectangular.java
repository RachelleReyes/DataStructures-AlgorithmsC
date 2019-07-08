//Elaborado el Reyes Udasco Rachelle Nerie 
//Práctica 0
//Competencia: Reafirmar los conocimientos de la POO diseñando y construyendo programas que utilicen clases.
//27 de agosto del 2018, Grupo 551
//Algoritmos y Estructura de Datos

import javax.swing.JOptionPane;
import java.text.DecimalFormat;

/*Clase Rectangular*/
public class Rectangular {
	
	/*Atributos de la clase Rectangular*/
	private double num_real;
	private double num_imaginario;
	
	/*Constructor de la clase Rectangular con dos parametros*/
	public Rectangular(double num_real, double num_imaginario) {
		this.num_real = num_real;
		this.num_imaginario =num_imaginario;
	}
	
	/*Getters y setters de los atributos de la clase*/
	public double getNum_real() {  //Getter del atributo num_real
		return num_real;
	}
	public void setNum_real(double num_real) { //Setter del atributo num_real
		this.num_real = num_real;
	}
	public double getNum_imaginario() { //Getter del atributo num_imaginario
		return num_imaginario;
	}
	public void setNum_imaginario(double num_imaginario) { //Setter del atributo num_imaginario
		this.num_imaginario = num_imaginario;
	}
	
	/*Metodo que realiza la suma de dos numeros en forma Rectangular*/
	public static Rectangular suma(Rectangular num1, Rectangular num2) {
		Rectangular resultado = new Rectangular(num1.getNum_real() + num2.getNum_real(),num1.getNum_imaginario() + num2.getNum_imaginario());
		return resultado;
	}
	
	/*Metodo que realiza la resta de dos numeros en forma Rectangular*/
	public static Rectangular resta(Rectangular num1, Rectangular num2) {
		Rectangular resultado = new Rectangular(num1.getNum_real() - num2.getNum_real(),num1.getNum_imaginario() - num2.getNum_imaginario());
		return resultado;
	}
	
	/*Metodo que convierte la representacion de un Numero Complejo, de Rectangular a Polar*/
	public Polar convertirAPolar() {
		Polar polar = new Polar(Math.sqrt(Math.pow(this.getNum_real(),2)+ Math.pow(this.getNum_imaginario(),2)),Math.atan(this.getNum_imaginario()/this.getNum_real()));
		return polar;
	}
	
	/*Metodo que imprime el numero complejo de forma Rectangular*/
	public void imprimirRectangular(String cadena) {
		DecimalFormat formatoDecimal = new DecimalFormat("#.00000"); //Formato para imprimir 5 decimales
		JOptionPane.showMessageDialog(null,cadena + "\n"+ formatoDecimal.format(this.getNum_real()) + " + " +formatoDecimal.format(this.getNum_imaginario())+ "i","FORMA RECTANGULAR", JOptionPane.PLAIN_MESSAGE); 
	}	
}
