#include<Python.h>
#include<iostream>
#include"python_test.h"
using namespace std;
int py_test1() {
	Py_Initialize(); /*��ʼ��python������,���߱�����Ҫ�õ�python������*/
	//PyRun_SimpleString("help('modules')"); /*�г�����ģ��*/
	//PyRun_SimpleString("import networkx as nx"); /*�г�����ģ��*/
	PyRun_SimpleString("import matplotlib.pyplot as plt"); /*����python�ļ�*/
	PyRun_SimpleString("plt.plot([1,2,3,4], [12,3,23,231])"); /*����python�ļ�*/
	PyRun_SimpleString("plt.show()"); /*����python�ļ�*/
	Py_Finalize(); /*����python���������ͷ���Դ*/
	return 0;
}
int py_test2() {
	cout << "in" << endl;
	Py_Initialize(); /*��ʼ��python������,���߱�����Ҫ�õ�python������*/
	PyRun_SimpleString("import sys"); /*����python�ļ�*/
	PyRun_SimpleString("import os"); /*����python�ļ�*/
	PyRun_SimpleString("print(os.getcwd())"); /*����python�ļ�*/
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
	pFunc = PyObject_GetAttrString(pModule, "hello");//���ڸ��hello world�ˣ���ʼʹ���µĺ���
	if (!pFunc) {
		cout << "func failed" << endl;
		return -1;
	}
	pArg = Py_BuildValue("hello");//����һ��Ԫ��
	PyObject* temp = PyObject_CallObject(pFunc, pArg);
	if (!temp) {
		cout << "call failed" << endl;
		return -1;
	}
	Py_Finalize(); /*����python���������ͷ���Դ*/
	cout << "out" << endl;
	return 0;
}
int py_test3() {
	cout << "in" << endl;
	Py_Initialize(); /*��ʼ��python������,���߱�����Ҫ�õ�python������*/
	PyRun_SimpleString("import sys"); /*����python�ļ�*/
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
	pFunc = PyObject_GetAttrString(pModule, "hello2");//���ڸ��hello world�ˣ���ʼʹ���µĺ���
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
	Py_Finalize(); /*����python���������ͷ���Դ*/
	cout << "out" << endl;
	return 0;
}
int py_test4() {
	cout << "in" << endl;
	Py_Initialize(); /*��ʼ��python������,���߱�����Ҫ�õ�python������*/
	PyRun_SimpleString("import sys"); /*����python�ļ�*/
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
	pFunc = PyObject_GetAttrString(pModule, "hello3");//���ڸ��hello world�ˣ���ʼʹ���µĺ���
	if (!pFunc) {
		cout << "func failed" << endl;
		return -1;
	}
	//pArg = Py_BuildValue("s","hello4");
	//PyObject* temp = PyObject_CallObject(pFunc, pArg);
	PyObject* pRet = PyEval_CallObject(pFunc, Py_BuildValue("(s)", "hello4"));//������ Py_BuildValue("s", "hello4")���������
	if (!pRet) {
		cout << "call failed" << endl;
		return -1;
	}
	cout << "return succeed" << endl;
	char* ret;
	PyArg_Parse(pRet, "s", &ret);//������PyArg_Parse(pRet, "(s)", &ret),�����
	cout << ret << endl;
	Py_Finalize(); /*����python���������ͷ���Դ*/
	cout << "out" << endl;
	return 0;
}
int py_test5() {
	cout << "in" << endl;
	Py_Initialize(); /*��ʼ��python������,���߱�����Ҫ�õ�python������*/
	PyRun_SimpleString("import sys"); /*����python�ļ�*/
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
	PyObject* pRet = PyEval_CallObject(pFunc, pedges2);//������ Py_BuildValue("s", "hello4")���������
	if (!pRet) {
		cout << "call failed" << endl;
		return -1;
	}
	cout << "return succeed" << endl;
	Py_Finalize(); /*����python���������ͷ���Դ*/
	cout << "out" << endl;
}
int py_test_inf() {
	//�������ֻ�г����õ�����������վ
	//https://www.cnblogs.com/wjshan0808/p/8409674.html
	return 0;
}