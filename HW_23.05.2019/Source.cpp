#include"MyException.h"


int main() {

	//Задание 1:

//Продемонстрировать обработку исключений трех типов int, char, double и char *,
//используя соответствующие текстовые сообщения, которые будут выводиться на консоль
//- для этого необходимо в коде, размещенном в блоке try сгенерировать необходимые исключительные ситуации
//используя оператор throw;
//-использовать три специализированных блока catch и один универсальный блок catch (…);
//-разместите их в необходимой последовательности, что является очень важным моментом;

	//Задание 2:

//Продемонстрируйте повторную генерацию исключений
//- для этого сконструируйте один вложенный блок try-catch во внешнем блоке try с произвольной
//количеством блоков catch;
//- продемонстрируйте повторную генерацию уже отловленного и обработанного исключения в
//внутреннем блоке catch используя оператор throw без аргументов и повторно
//отловите его во внешнем блоке catch;
//-в другом варианте во внутреннем блоке catch после перехвата исключения можно
//повторно сгенерировать исключение другого типа, используя для этого оператор throw
//с параметром;
	int i;
	cout << "Enter 1 to check tasks 1, 2, 3" << endl << "Enter 2 to check task 4" << endl;
	cin >> i;
	switch (i) {

	case 1: {
		int example;
		char *sym;
		while (1) {
			cout << "Enter a number" << endl;
			cin >> example;
			//task 2
			try {//внешний блок
				//task 1
				try {//вложенный блок
					if (example > 0)
						//throw;
						throw 404;
					else if (example == 0)
						throw "Entered number is 0";
					else
						throw 0.888;
				}
				catch (double d) {//double
					cout << "Entered number is negative, code " << d << endl;
					throw;//перекидываем на повторную отработку исключения во внешнем блоке!!!!!!!!!!!
				}
				catch (const char *c) {//const char*
					cout << c << endl;
					throw runtime_error("CHANGE ZERO!");//а здесь повторная обработка во внешнем блоке, но уже исключения другого типа
				}
				catch (int a) {//int
					cout << "Integer type error with code " << a << endl;
					throw my_ex;//task 3
				}
				catch (...) {//универсальный блок catch (…)
					cout << "Error" << endl;
					throw;
				}

			}
			catch (double d) {
				cout << "Entered number is negative, code " << d << endl;
			}
			catch (const char *c) {
				cout << c << endl;
			}
			catch (int a) {
				cout << "Integer type error with code " << a << endl;
			}
			catch (runtime_error err) {
				cout << err.what() << endl;
			}
			catch (MyException my_ex) {//task 3
				cout << my_ex.ErrorMessage() << endl;
			}
			catch (...) {
				cout << "Error" << endl;
			}
		}
	}
			break;

	case 2: {
		//task 4
		try {
			show();
		}
		catch (...) {
			//cout << "TEST MESSAGE" << endl;
		}
	}
			break;
	}
	system("pause");
	return 0;
}