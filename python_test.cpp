#include<Python.h>
#include<iostream>
#include"python_test.h"
using namespace std;
int py_test1() {
	Py_Initialize(); /*初始化python解释器,告诉编译器要用的python编译器*/
	//PyRun_SimpleString("help('modules')"); /*列出所有模块*/
	//PyRun_SimpleString("import networkx as nx"); /*列出所有模块*/
	PyRun_SimpleString("import matplotlib.pyplot as plt"); /*调用python文件*/
	PyRun_SimpleString("plt.plot([1,2,3,4], [12,3,23,231])"); /*调用python文件*/
	PyRun_SimpleString("plt.show()"); /*调用python文件*/
	Py_Finalize(); /*结束python解释器，释放资源*/
	return 0;
}
int py_test2() {
	cout << "in" << endl;
	Py_Initialize(); /*初始化python解释器,告诉编译器要用的python编译器*/
	PyRun_SimpleString("import sys"); /*调用python文件*/
	PyRun_SimpleString("import os"); /*调用python文件*/
	PyRun_SimpleString("print(os.getcwd())"); /*调用python文件*/
	PyRun_SimpleString("sys.path.append('./')");
	PyRun_SimpleString("from time import time,ctime\n"
		"print('Today is', ctime(time()))\n");
	PyObject* pModule = NULL;
	PyObject* pFunc = NULL;
	PyObject* pArg = NULL;
	pModule = PyImport_ImportModule("py_test");
	if (!pModule) {
		cout << "module failed" << endl;
		return -1;
	}
	pFunc = PyObject_GetAttrString(pModule, "hello");//终于告别hello world了，开始使用新的函数
	if (!pFunc) {
		cout << "func failed" << endl;
		return -1;
	}
	pArg = Py_BuildValue("hello");//构造一个元组
	PyObject* temp = PyObject_CallObject(pFunc, pArg);
	if (!temp) {
		cout << "call failed" << endl;
		return -1;
	}
	Py_Finalize(); /*结束python解释器，释放资源*/
	cout << "out" << endl;
	return 0;
}
int py_test3() {
	cout << "in" << endl;
	Py_Initialize(); /*初始化python解释器,告诉编译器要用的python编译器*/
	PyRun_SimpleString("import sys"); /*调用python文件*/
	PyRun_SimpleString("sys.path.append('./')");
	//PyRun_SimpleString("from time import time,ctime\n"
	//	"print('Today is', ctime(time()))\n");
	PyObject* pModule = NULL;
	PyObject* pFunc = NULL;
	PyObject* pArg = NULL;
	pModule = PyImport_ImportModule("py_test");
	if (!pModule) {
		cout << "module failed" << endl;
		return -1;
	}
	pFunc = PyObject_GetAttrString(pModule, "hello2");//终于告别hello world了，开始使用新的函数
	if (!pFunc) {
		cout << "func failed" << endl;
		return -1;
	}
	pArg = Py_BuildValue("");
	PyObject* temp = PyObject_CallObject(pFunc, NULL);
	if (!temp) {
		cout << "call failed" << endl;
		return -1;
	}
	Py_Finalize(); /*结束python解释器，释放资源*/
	cout << "out" << endl;
	return 0;
}
int py_test4() {
	cout << "in" << endl;
	Py_Initialize(); /*初始化python解释器,告诉编译器要用的python编译器*/
	PyRun_SimpleString("import sys"); /*调用python文件*/
	PyRun_SimpleString("sys.path.append('./')");
	//PyRun_SimpleString("from time import time,ctime\n"
	//	"print('Today is', ctime(time()))\n");
	PyObject* pModule = NULL;
	PyObject* pFunc = NULL;
	PyObject* pArg = NULL;
	pModule = PyImport_ImportModule("py_test");
	if (!pModule) {
		cout << "module failed" << endl;
		return -1;
	}
	pFunc = PyObject_GetAttrString(pModule, "hello3");//终于告别hello world了，开始使用新的函数
	if (!pFunc) {
		cout << "func failed" << endl;
		return -1;
	}
	//pArg = Py_BuildValue("s","hello4");
	//PyObject* temp = PyObject_CallObject(pFunc, pArg);
	PyObject* pRet = PyEval_CallObject(pFunc, Py_BuildValue("(s)", "hello4"));//不能是 Py_BuildValue("s", "hello4")，否则出错
	if (!pRet) {
		cout << "call failed" << endl;
		return -1;
	}
	cout << "return succeed" << endl;
	char* ret;
	PyArg_Parse(pRet, "s", &ret);//不能是PyArg_Parse(pRet, "(s)", &ret),很奇怪
	cout << ret << endl;
	Py_Finalize(); /*结束python解释器，释放资源*/
	cout << "out" << endl;
	return 0;
}
int py_test5() {
	cout << "in" << endl;
	Py_Initialize(); /*初始化python解释器,告诉编译器要用的python编译器*/
	PyRun_SimpleString("import sys"); /*调用python文件*/
	PyRun_SimpleString("sys.path.append('./')");
	PyObject* pModule = NULL;
	PyObject* pFunc = NULL;
	PyObject* pArg = NULL;
	pModule = PyImport_ImportModule("py_test");
	if (!pModule) {
		cout << "module failed" << endl;
		return -1;
	}
	pFunc = PyObject_GetAttrString(pModule, "display_binary_tree");
	if (!pFunc) {
		cout << "func failed" << endl;
		return -1;
	}
	PyObject* pedges = PyTuple_New(3);// for
	PyObject* pedges2 = PyTuple_New(1);// for
	PyTuple_SetItem(pedges, 0, Py_BuildValue("[i,i]", 0,1));
	PyTuple_SetItem(pedges, 1, Py_BuildValue("[i,i]", 0,2));
	PyTuple_SetItem(pedges, 2, Py_BuildValue("[i,i]", 1,2));
	PyTuple_SetItem(pedges2, 0, pedges);
	PyObject* pRet = PyEval_CallObject(pFunc, pedges2);//不能是 Py_BuildValue("s", "hello4")，否则出错
	if (!pRet) {
		cout << "call failed" << endl;
		return -1;
	}
	cout << "return succeed" << endl;
	Py_Finalize(); /*结束python解释器，释放资源*/
	cout << "out" << endl;
}
int py_test_inf() {
	//这个测试只列出有用的网上例子网站
	//https://www.cnblogs.com/wjshan0808/p/8409674.html
	return 0;
}