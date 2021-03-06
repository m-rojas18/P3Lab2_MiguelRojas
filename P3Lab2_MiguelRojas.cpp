#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;

void imprimirMatriz(double**,int);
double calcularMu(double** , int );
double calcularSigma(double** , int , double);
void calcularSumatoria(double, double, double);
void sacarRaices(double, double, double, double, double, int, int);

int main(){

    char seguir = 's';
    int resp;
    while (seguir == 's'){
        cout << "** Menu **" << endl
            << "[1] Metodo Newton-Raphson " << endl
            << "[2] Matriz Estandarizada" << endl
            << "[3] Aproximacion de PI" << endl
            << "Salir" << endl
            << "Seleccione una opcion: ";
        cin >> resp;
        cout << endl;
        switch (resp){
            case 1: {
                //Ejercicio 1 - Metodo Newton-Raphson 
                //Pedir valores
                double coeficiente_a, coeficiente_b, coeficiente_c;
                cout << "Ingresara un polinomio e la forma ax^2 + bx + c." << endl;
                cout << "Ingrese a: ";
                cin >> coeficiente_a;
                cout << endl;
                //Validar a
                while(coeficiente_a == 0){
                    cout << "El valor de a no puede ser 0\nIngrese otro valor para a: ";
                    cin >> coeficiente_a;
                    cout << endl;
                }
                cout << "Ingrese b: ";
                cin >> coeficiente_b;
                cout << endl;
                cout << "Ingrese c: ";
                cin >> coeficiente_c;
                cout << endl;
                double vertice_x = (-coeficiente_b )/ (2 * coeficiente_a);
                double x0_intento1 = vertice_x - 200;
                double x0_intento2 = vertice_x + 200;
                cout << "No logre terminar el ejercicio :(" << endl;
               // sacarRaices(coeficiente_a, coeficiente_b, coeficiente_c, x0_intento1,0, 0, 0);


                break;
            }
            case 2: {
                srand(time(0));
                //Ejericio 2- Matriz Estandarizada
                int size;
                cout << "Ingrese el tamano de la matriz: ";
                cin >> size;
                //Crear matriz
                double** matriz_creada = new double*[size];
                for (int j = 0; j < size; j++)
                    matriz_creada[j] = new double[size];
                //Llenar la matriz
                for (int i = 0; i < size; i++){
                    for (int j = 0; j < size; j++){
                       matriz_creada[i][j] = (rand() % 89 + 10);
                    }     
                } 
                cout << "Matriz Original" << endl;
                imprimirMatriz(matriz_creada, size);
                cout << endl;
                //Conseguir Valores de matriz estandarizada
                double valor_mu = calcularMu(matriz_creada, size);
                //cout << "valor_mu = " << valor_mu << endl;
                double valor_sigma = calcularSigma(matriz_creada, size, valor_mu);
                //cout << "valor sigma = " << valor_sigma ;

                //Recorrer la matriz y llenarla con sus valores estandarizados
                for (int i = 0; i < size; i++){
                    for (int j = 0; j < size; j++){
                        matriz_creada[i][j] = (matriz_creada[i][j] - valor_mu)/valor_sigma;
                    }
                }
                //Imprimir la matriz estandarizada
                cout << "Matriz Estandarizada" << endl;
                imprimirMatriz(matriz_creada, size);
                cout << endl;
                // Libera la matriz
	            for(int i = 0; i < size; i++){
		            delete[] matriz_creada[i];
		        matriz_creada[i] = NULL;
	            }
	            delete[] matriz_creada;
                break;
            }
            case 3:{
                //Ejercicio -3 Aproximacion de pi
                int limite_sumatoria;
                cout << "Ingrese el limite de la sumatoria: ";
                cin >> limite_sumatoria;
                calcularSumatoria(limite_sumatoria, 0, 0);
                break;
            }
            case 4:{
                cout << "Fin del Programa" << endl << endl;
                seguir = 'n';
                break;
            }
        default:
            cout << "Ingreso una opcion no valida." << endl << endl;
            break;
        }
    }
}
//Metodos

void imprimirMatriz(double** matriz, int tamano){
    for (int i = 0; i < tamano; i++){
        cout << "[";
        for (int j = 0; j < tamano; j++){
            cout <<  setw(10) << matriz[i][j] << "  ";
        }
        cout << "]"<<endl;   
    } 
}

double calcularMu(double** matriz, int tamano){
    double resultado_mu, sumatoria, tamano_total;
    //Conseguir la sumatoria de la matriz
    for (int i = 0; i < tamano; i++){
        for (int j = 0; j < tamano; j++){
            sumatoria += matriz[i][j];
        }
    }
    //Conseguir el tamaño total de la matriz
    tamano_total = tamano * tamano;
    //Evaluar para conseguir el valor de mu
    resultado_mu = sumatoria / tamano_total;
    return resultado_mu;
}

double calcularSigma(double** matriz, int tamano, double valor_mu){
    double resultado_sigma, sumatoria_sigma, tamano_total;
    //Conseguir la nueva sumatoria restando mu  y elevado  a 2
    for (int i = 0; i < tamano; i++){
        for (int j = 0; j < tamano; j++){
            sumatoria_sigma += pow(matriz[i][j] - valor_mu,2);
        }   
    }
    //Conseguir el tamano total de la matriz
    tamano_total = tamano * tamano;
    //Evaluar el resultado
    resultado_sigma = sqrt(sumatoria_sigma/tamano_total);
    return resultado_sigma;
}

void calcularSumatoria(double limit_sumatoria, double contador, double sumatoria){

    double resultado, numerador;
    if(contador > limit_sumatoria){
        resultado = 4 * sumatoria;
        cout << "PI = " << resultado << endl << endl; 
    }   else {
        sumatoria += pow(-1,contador) / ( 2 * contador + 1);
        calcularSumatoria(limit_sumatoria, ++ contador, sumatoria);
    }
}

void sacarRaices(double a, double b, double c, double x_n, double sumatoria, int indicador, int contador){
    string salida = "";
    if(indicador == 0){
        salida = "Raiz uno: ";
    } else {
        salida = "Raiz dos: ";
    }
    double f_xn, f_prima_xn;
    if(contador > 0){
        cout << "Valor Final = " << sumatoria ;
        //cout << salida;
    } else {
        //Sacar f(x)
        f_xn= pow(a * x_n,2) + b * x_n + c;
        //Sacar f'(x)
        f_prima_xn = 2 * a * x_n + b;
        sumatoria += x_n- (f_xn/f_prima_xn); 
        sacarRaices(a, b, c, sumatoria, sumatoria, indicador, ++ contador);
    }


}