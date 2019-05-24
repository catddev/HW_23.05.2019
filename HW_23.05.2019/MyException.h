﻿#pragma once
#include<exception>
#include<iostream>
#include<string>
using namespace std;

//Задание 1:

//Продемонстрировать обработку исключений трех типов int, char, double и char *,
//используя соответствующие текстовые сообщения, которые будут выводиться на консоль
//- для этого необходимо в коде, размещенном в блоке try сгенерировать необходимые исключительные ситуации
//используя оператор throw;
//-использовать три специализированных блока catch и один универсальный блок catch (…);
//-разместите их в необходимой последовательности, что является очень важным моментом;

//Задание 2:

//Продемонстрируйте повторную генерацию исключений
//- для этого сконструируйте один вложенный блок try - catch во внешнем блоке try с произвольной
//количеством блоков catch;
//например:
//
//// Внешний блок:
//try
//{
//	// Внутренний блок
//	try
//	{
//		// operators;
//	}
//	catch (<type 1>)
//	{
//		// operators;
//	}
//	catch (<type 2>)
//	{
//		// operators;
//	}
//	…….....
//		catch (<type N>)
//	{
//		// operators;
//	}
//	…………
//}
//catch (<type 1>)
//{
//	// operators;
//}
//catch (<type 2>)
//{
//	// operators;
//}
//…….....
//catch (<type N>)
//{
//	// operators;
//}
//- продемонстрируйте повторную генерацию уже отловленного и обработанного исключения в
//внутреннем блоке catch используя оператор throw без аргументов и повторно
//отловите его во внешнем блоке catch;
//-в другом варианте во внутреннем блоке catch после перехвата исключения можно
//повторно сгенерировать исключение другого типа, используя для этого оператор throw
//с параметром;

//Задание 3:

//Каждый блок catch предназначен для перехвата исключения определенного типа.
//До этого момента мы использовали исключения, которые представлялись базовыми типами.
//Давайте создадим пользовательский тип данных – класс CMyException,
//который будет содержать только одно поле данных – это строка(char *, char[], string ...),
//которое будет содержать информацию об ошибке.Создадим конструктор с параметром,
//который будет инициализировать это поле и необходимые методы.
//В блоке try сгенерируем исключение типа CMyException и перехопимо его в соответствующем блоке catch,
//выведем на экран сообщение об ошибке, использовав, например, метод класса имеет следующий прототип :
//char * MyException::ErrorMessage();

//Задание 4:

//Для демонстрации раскрутки стека данных нам необходимо создать класс - демонстратор вызовов конструктора и деструктора(CTest),
//то есть поместим оператор вывода соответствующего сообщения на экран в указанные методы(конструктор и деструктор).
//Объявим и реализуем две функции, в которых создадим объект данного класса(CTest t;).
//Первая функция, после объявления объекта сразу вызовет функцию номер два,
//которая в свою очередь после объявления объекта сгенерирует исключение довідного типа.
//Вызов функции номер один разместим в блоке try
//и отловим сгенерированное второй функцией выключения в соответствующем блоке catch.
//
//Пример :
//
//	class CTest
//{
//public:
//	// consturcor and destructor
//};
//
//void func1();
//void func2();
//
//int main()
//{
//	try
//	{
//		func1();
//	}
//	catch (<type> e)
//	{
//		// something else;
//		cout << "\nError - " << e << endl;
//	}
//
//	return 0;
//}
//void func1()
//{
//	CTest t1;
//	func2();
//}
//void func2()
//{
//	CTest t2;
//	throw varialble_ or literal_ of <type>;
//}
//Если все верно написано, то мы увидим на экране сообщение о вызове двух конструкторов
//и двух деструкторов объектов класса CTest,
//что будет свидетельствовать о том, что стек памяти, в котором содержались данные объекте корректно раскрутился