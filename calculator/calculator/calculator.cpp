// calculator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include <string>
using namespace std;
auto pluss( float a, float b) {
	return (a + b);
}
auto minuss(float a, float b) {
	return a - b;
}
auto multipl(float a, float b) {
	return a*b;
}
auto division(float a, float b) {
	return a/b;
}
auto power(float a, float b) {
	return pow(a, b);
}
auto matrix_pluss(float matrix1[3][3], float matrix2[3][3]) {
	float matrix3[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix3[i][j]=matrix1[i][j]+matrix2[i][j];
		}
	}
	return matrix3;
}
auto matrix_minuss(float matrix1[3][3], float matrix2[3][3]) {
	float matrix3[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
		}
	}
	return matrix3;
}
int number_notnumber(float a) {
	int klone;
	do {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid syntax. You must enter a number. Try adain." << endl;
			cin >> a;
			klone=0;
		}else {
			klone= 1;
		}
	} while (klone==0);
	return a;
	
}
int main()
{
	float a;
	float b;
	char c; //operation//
	char stop = 'n';
	char matrix_operation;
	float matrix_a[3][3];
	float matrix_b[3][3];
	float cmatrix[3][3];
	while (stop == 'n') {
		cout << "Do you want to work with matrices? Print 'y' for 'yes'/'n' for 'not'";
		cin >> matrix_operation;
		if (matrix_operation == 'n') {
			cout << "input mathematical operation (+, -, *, /, ^)";// правильно ли введена мат.операция?
			cin >> c;
			while (c != '+' and c != '-' and c != '*' and c != '^' and c != '/') {
				cout << "Invalid syntax. Please enter one of the operation (+,-,*,/,^)";
				cin >> c;
			}
			cout << "Input A:";
			cin >> a;
			a=number_notnumber(a);
			cout << "Input B:";
			cin >> b;
			b= number_notnumber(b);
			if (c == '/') {
				while (b == 0) {
					cout << "Invalid value. You can't divide by zero. Input B:";
					cin >> b;
				}
			}
			if (c == '*') {
				cout << "A*B=" << (multipl(a,b)) << endl;
			} else if (c == '/') {
				cout << "A/B=" << (division(a,b)) << endl;
			} else if (c == '+') {
				cout << "A+B=" << (pluss(a,b)) << endl;
			} else if (c == '-') {
				cout << "A-B=" << (minuss(a,b)) << endl;
			} else if (c == '^') {
				cout << "A^B=" << (power(a, b)) << endl;
			}
		} else if (matrix_operation == 'y') {
			cout << "input mathematical operation (+, -)" << "\n";// правильно ли введена мат.операция?
			cin >> c;
			while (c != '+' and c != '-') {
				cout << "Invalid syntax. Please enter one of the operation (+,-)" << "\n";
				cin >> c;
			}
			cout << "Input matrix A:" << "\n";
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					cout << "Input A[" << i+1<<"]["<<j+1<<"]";
					cin >> matrix_a[i][j];
					matrix_a[i][j]=number_notnumber(matrix_a[i][j]);

				}
			}
			cout << "Input matrix B:" << "\n";
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					cout << "Input B[" << i + 1 << "][" << j + 1 << "]";
					cin >> matrix_b[i][j];
					matrix_b[i][j] = number_notnumber(matrix_b[i][j]);
				}
			}
			if (c == '+') {
				cout << "matrix A + matrix B =" << "\n";
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						cout << matrix_pluss(matrix_a, matrix_b)[i][j] << "\t";
					}
					cout << "\n";
				}
			} else if (c == '-') {
				cout << "matrix A - matrix B =" << "\n";
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						cout << matrix_minuss(matrix_a, matrix_b)[i][j] << "\t";
					}
					cout << "\n";
				}
			}
		}
		
		cout << "Stop using the calculator? Print 'y'/'n'";
		cin >> stop;
	}
}