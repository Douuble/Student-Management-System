#include <iostream>
#include <stdlib.h> 
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MaxSize 100                    //学生人数最大值 可修改
using namespace std;


class Student {                        //学生基本信息父类
public:
	char* id[MaxSize];
	char* name[MaxSize];
	char* age[MaxSize];
	char* sex[MaxSize];
	char* class_[MaxSize];
	char* English[MaxSize];
	char* total[MaxSize];
	//构造函数定义
	Student() {
		for (int i = 0; i < MaxSize; i++) {
			id[i] = new char[100];
			name[i] = new char[100];
			age[i] = new char[100];
			sex[i] = new char[100];
			class_[i] = new char[100];
			English[i] = new char[100];
			total[i] = new char[100];
		}
	}
	//虚函数定义
	virtual void Read() = 0;
	virtual void Insert() = 0;
	virtual void Delete() = 0;
	virtual void Updata() = 0;
	virtual void Sum() = 0;
	virtual void Print() = 0;
	virtual void Search() = 0;
	virtual void SqSearch() = 0;
	virtual void BinarySearch() = 0;
	virtual void Sort(int low, int high) = 0;
};

FILE* fp;                      //文件指针
int i;
int n;                        //用于储存学生信息数
int x;                        //用于二级菜单的选择

class Pupil :public virtual Student {                    //小学生派生类
public:
	char* Chinese[MaxSize];
	char* math[MaxSize];
	Pupil() {
		for (int i = 0; i < MaxSize; i++) {
			Chinese[i] = new char[100];
			math[i] = new char[100];
		}
	}

	//文件读取操作
	void Read() {
		fp = fopen("pupil.txt", "r");
		if (fp == NULL) {
			cout << "打开文件失败！" << endl;
			exit(0);
		}
		while (fscanf(fp, "%s%s%s%s%s%s%s%s%s", id[i], name[i], sex[i], age[i], class_[i], English[i], math[i], Chinese[i], total[i]) == 9) {  // 循环读入学生信息
			i++;
		}
		n = i;                                               //用于存储已读取的学生信息数
		if (i == 0)
			cout << "文件为空!请先添加学生信息再执行此项！" << endl;
		else
			cout << "读取文件成功!" << endl;
		fclose(fp);
		cout << endl;
	}

	//插入添加操作
	void Insert() {
		int add;
		cout << "请输入要插入的数据项数：" << endl;
		cin >> add;
		if (add <= 0) {
			cout << "键入信息错误！！" << endl;
			cout << endl;
			return;
		}
		cout << "请依次输入学号、姓名、性别、年龄、班级、英语成绩、数学成绩、语文成绩、总分：" << endl;
		for (i = n; i < n + add; i++) {
			cin >> id[i] >> name[i] >> sex[i] >> age[i] >> class_[i] >> English[i] >> math[i] >> Chinese[i] >> total[i];
		}
		n = add + n;                                                        //改变学生总人数
		cout << "信息插入完毕！" << endl;
		cout << endl;
	}

	//删除操作
	void Delete() {
		int flag = 1;                                //标志位flag用于确定是否找到该学号
		int j;
		char target[20];
		cout << "请输入要删除学生的学号：" << endl;
		cin >> target;
		for (i = 0; i <= n; i++) {
			if (strcmp(id[i], target) == 0) {
				flag = 0; break;
			}
		}
		if (flag == 1) cout << "记录为空！删除失败！" << endl;
		else {
			n--;
			for (j = i; j <= n; j++) {                                  //将j后所有前移一位
				id[j] = id[j + 1];
				age[j] = age[j + 1];
				name[j] = name[j + 1];
				sex[j] = sex[j + 1];
				class_[j] = class_[j + 1];
				English[j] = English[j + 1];
				math[j] = math[j + 1];
				Chinese[j] = Chinese[j + 1];
				total[j] = total[j + 1];
			}
			cout << "删除成功！！" << endl;
		}cout << endl;
	}

	//统计操作
	void Sum() {
		cout << "共有" << n << "位学生的信息！" << endl;
		cout << endl;
	}

	//显示操作
	void Student::Print() {
		system("cls");
		Sum();
		cout << "  学号      姓名      性别      年龄       班级      英语成绩     数学成绩     语文成绩      总分" << endl;
		cout << "----------------------------------------------------------------------------------------------------" << endl;
		if (n != 0) {
			for (i = 0; i < n; i++) {
				printf("%-11s %-10s %-9s %-8s %-14s %-12s %-10s %-11s %-10s\n", id[i], name[i], sex[i], age[i], class_[i], English[i], math[i], Chinese[i], total[i]);
			}
		}
		else cout << "管理系统为空！" << endl;
		cout << endl;
	}

	//更新保存操作
	void Updata() {
		fp = fopen("pupil.txt", "w");
		if (fp == NULL) cout << "打开文件失败！" << endl;
		else {
			for (i = 0; i < n; i++) {
				fprintf(fp, " % s % s % s % s % s % s % s % s % s\n", id[i], name[i], sex[i], age[i], class_[i], English[i], math[i], Chinese[i], total[i]);
			}cout << "信息已完成更新,可在文本文档中查看!" << endl;
			cout << endl;
		}fclose(fp);
	}

	//对姓名进行顺序查找
	void SqSearch() {
		char aim[10];
		int flag = 1;
		cout << "请输入要查找学生的姓名：" << endl;
		cin >> aim;
		for (i = 0; i <= n; i++) {
			if (strcmp(name[i], aim) == 0) {
				flag = 0; break;
			}
		}
		if (flag == 1) {
			cout << "未找到要查找的姓名！" << endl;
			cout << endl;
		}
		else {
			cout << "查找结果如下：" << endl;
			cout << "  学号      姓名       性别     年龄        班级      英语成绩     数学成绩     语文成绩      总分" << endl;
			cout << "----------------------------------------------------------------------------------------------------" << endl;
			printf("%-11s %-10s %-9s %-8s %-14s %-12s %-10s %-11s %-10s\n", id[i], name[i], sex[i], age[i], class_[i], English[i], math[i], Chinese[i], total[i]);
		}
		cout << endl;
	}

	//对学号进行二分法查找
	void BinarySearch() {
		char goal[10];
		Sort(0, n - 1);
		int high = n - 1;
		int low = 0;
		int flag = 0;
		cout << "请输入要查找的学号:" << endl;
		cin >> goal;
		while (low <= high) {
			int mid = (high + low) / 2;
			if (strcmp(id[mid], goal) == 0) {
				cout << "查找结果如下：" << endl;
				cout << "  学号      姓名       性别     年龄        班级      英语成绩     数学成绩     语文成绩      总分" << endl;
				cout << "----------------------------------------------------------------------------------------------------" << endl;
				printf("%-11s %-10s %-9s %-8s %-14s %-12s %-10s %-11s %-10s\n", id[mid], name[mid], sex[mid], age[mid], class_[mid], English[mid], math[mid], Chinese[mid], total[mid]);
				flag = 1;
				break;
			}
			else if (strcmp(goal, id[mid]) < 0) high = mid - 1;                   //根据算法对范围（low、high）变化
			else if (strcmp(goal, id[mid]) > 0)low = mid + 1;

		}
		if (flag == 0) cout << "未找到对应学号！！" << endl;
		cout << endl;
	}

	//查找子菜单
	void Search() {
		int x;
		cout << "^^^^^^^^^^^^^^^^^" << endl;
		cout << "^    *子菜单*   ^" << endl;
		cout << "^ 1、按姓名查找 ^" << endl;
		cout << "^ 2、按学号查找 ^" << endl;
		cout << "^ 3、退出本菜单 ^" << endl;
		cout << "^               ^" << endl;
		cout << "^^^^^^^^^^^^^^^^^" << endl;
		while (1) {
			cout << "请选择子菜单编号:" << endl;
			cin >> x;
			cout << endl;
			switch (x) {
			case 1:SqSearch(); break;
			case 2:BinarySearch(); break;
			case 3:return;
			default:cout << "选择序号错误！" << endl;
			}
		}
	}

	//对总分进行快速排序		
	void Sort(int left, int right) {
		/*核心：根据基准数对数组进行划分（小于枢轴在左侧，大于在右侧）*/
		int i, j;
		char* standard;                       //存储基准数
		if (left > right) {                   //终止
			return;
		}
		standard = total[left];
		i = left;
		j = right;
		while (i != j) {
			while (strcmp(total[j], standard) >= 0 && i < j) {         //从右向左找小于基准数的值
				j--;
			}
			while (strcmp(total[i], standard) <= 0 && i < j) {      //从左向右找大于基准数的值
				i++;
			}
			/*交换两个数（及其他信息）在数组中的位置*/
			if (i <= j) {
				swap(id[i], id[j]);
				swap(name[i], name[j]);
				swap(sex[i], sex[j]);
				swap(age[i], age[j]);
				swap(class_[i], class_[j]);
				swap(English[i], English[j]);
				swap(math[i], math[j]);
				swap(Chinese[i], Chinese[j]);
				swap(total[i], total[j]);
			}
		}
		/*交换基准数和i=j时的值*/
		swap(id[i], id[left]);
		swap(name[i], name[left]);
		swap(sex[i], sex[left]);
		swap(age[i], age[left]);
		swap(class_[i], class_[left]);
		swap(English[i], English[left]);
		swap(math[i], math[left]);
		swap(Chinese[i], Chinese[left]);
		swap(total[i], total[left]);
		Sort(left, i - 1);//递归处理枢轴左边
		Sort(i + 1, right);//递归处理枢轴右边	
	}
};

class Middle :public Pupil {                    //中学生派生类
public:
	char* history[MaxSize];
	char* geography[MaxSize];
	Middle() {
		for (int i = 0; i < MaxSize; i++) {
			history[i] = new char[100];
			geography[i] = new char[100];
		}
	}
	//文件读取操作
	void Read() {
		fp = fopen("middle.txt", "r");
		if (fp == NULL) {
			cout << "打开文件失败！" << endl;
			exit(0);
		}
		while (fscanf(fp, "%s%s%s%s%s%s%s%s%s%s%s", id[i], name[i], sex[i], age[i], class_[i], English[i], math[i], Chinese[i], history[i], geography[i], total[i]) == 11) {  // 循环读入学生信息
			i++;
		}
		n = i;                                               //用于存储已读取的学生信息数
		if (i == 0)
			cout << "文件为空!请先添加学生信息再执行此项！" << endl;
		else
			cout << "读取成功!" << endl;
		fclose(fp);
		cout << endl;
	}

	//插入添加操作
	void Insert() {
		int add;
		cout << "请输入要插入的数据项数：" << endl;
		cin >> add;
		if (add <= 0) {
			cout << "键入信息错误！！" << endl;
			cout << endl;
			return;
		}
		cout << "请依次输入学号、姓名、性别、年龄、班级、英语成绩、数学成绩、语文成绩、历史成绩、地理成绩、总分：" << endl;
		for (i = n; i < n + add; i++) {
			cin >> id[i] >> name[i] >> sex[i] >> age[i] >> class_[i] >> English[i] >> math[i] >> Chinese[i] >> history[i] >> geography[i] >> total[i];
		}
		n = add + n;                                                        //改变学生总人数
		cout << "信息插入完毕！" << endl;
		cout << endl;
	}

	//删除操作
	void Delete() {
		int flag = 1;                                //标志位flag用于确定是否找到该学号
		int j;
		char target[20];
		cout << "请输入要删除学生的学号：" << endl;
		cin >> target;
		for (i = 0; i <= n; i++) {
			if (strcmp(id[i], target) == 0) {
				flag = 0; break;
			}
		}
		if (flag == 1) cout << "记录为空！删除失败！" << endl;
		else {
			n--;
			for (j = i; j <= n; j++) {                                  //将j后所有前移一位
				id[j] = id[j + 1];
				age[j] = age[j + 1];
				name[j] = name[j + 1];
				sex[j] = sex[j + 1];
				class_[j] = class_[j + 1];
				English[j] = English[j + 1];
				math[j] = math[j + 1];
				Chinese[j] = Chinese[j + 1];
				history[j] = history[j + 1];
				geography[j] = geography[j + 1];
				total[j] = total[j + 1];
			}
			cout << "删除成功！！" << endl;
		}cout << endl;
	}

	//统计操作
	void Sum() {
		cout << "共有" << n << "位学生的信息！" << endl;
		cout << endl;
	}

	//显示操作
	void Student::Print() {
		system("cls");
		Sum();
		cout << "  学号      姓名       性别     年龄        班级      英语成绩     数学成绩     语文成绩     历史成绩       地理成绩     总分" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
		if (n != 0) {
			for (i = 0; i < n; i++) {
				printf("%-11s %-10s %-10s %-9s %-10s %-13s %-10s %-14s %-14s %-10s %-10s\n", id[i], name[i], sex[i], age[i], class_[i], English[i], math[i], Chinese[i], history[i], geography[i], total[i]);
			}
		}
		else cout << "管理系统为空！" << endl;
		cout << endl;
	}

	//更新保存操作
	void Updata() {
		fp = fopen("middle.txt", "w");
		if (fp == NULL) cout << "打开文件失败！" << endl;
		else {
			for (i = 0; i < n; i++) {
				fprintf(fp, " % s % s % s % s % s % s % s % s % s % s % s\n", id[i], name[i], sex[i], age[i], class_[i], English[i], math[i], Chinese[i], history[i], geography[i], total[i]);
			}cout << "信息已完成更新,可在文本文档中查看!" << endl;
			cout << endl;
		}fclose(fp);
	}

	//对姓名进行顺序查找
	void SqSearch() {
		char aim[10];
		int flag = 1;
		cout << "请输入要查找学生的姓名：" << endl;
		cin >> aim;
		for (i = 0; i <= n; i++) {
			if (strcmp(name[i], aim) == 0) {
				flag = 0; break;
			}
		}
		if (flag == 1) {
			cout << "未找到要查找的姓名！" << endl;
			cout << endl;
		}
		else {
			cout << "查找结果如下：" << endl;
			cout << "  学号      姓名       性别     年龄        班级      英语成绩     数学成绩     语文成绩     历史成绩       地理成绩     总分" << endl;
			cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
			printf("%-10s %-10s %-10s %-8s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", id[i], name[i], sex[i], age[i], class_[i], English[i], math[i], Chinese[i], history[i], geography[i], total[i]);
		}
		cout << endl;
	}

	//对学号进行二分法查找
	void BinarySearch() {
		char goal[10];
		Sort(0, n - 1);
		int high = n - 1;
		int low = 0;
		int flag = 0;
		cout << "请输入要查找的学号:" << endl;
		cin >> goal;
		while (low <= high) {
			int mid = (high + low) / 2;
			if (strcmp(id[mid], goal) == 0) {
				cout << "查找结果如下：" << endl;
				cout << "  学号      姓名       性别     年龄        班级      英语成绩     数学成绩     语文成绩     历史成绩       地理成绩     总分" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
				printf("%-10s %-10s %-10s %-8s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", id[mid], name[mid], sex[mid], age[mid], class_[mid], English[mid], math[mid], Chinese[mid], history[mid], geography[mid], total[mid]);
				flag = 1;
				break;
			}
			else if (strcmp(goal, id[mid]) < 0) high = mid - 1;                   //根据算法对范围（low、high）变化
			else if (strcmp(goal, id[mid]) > 0)low = mid + 1;

		}
		if (flag == 0) cout << "未找到对应学号！！" << endl;
		cout << endl;
	}

	//查找子菜单
	void Search() {
		int x;
		cout << "^^^^^^^^^^^^^^^^^" << endl;
		cout << "^    *子菜单*   ^" << endl;
		cout << "^ 1、按姓名查找 ^" << endl;
		cout << "^ 2、按学号查找 ^" << endl;
		cout << "^ 3、退出本菜单 ^" << endl;
		cout << "^               ^" << endl;
		cout << "^^^^^^^^^^^^^^^^^" << endl;
		while (1) {
			cout << "请选择子菜单编号:" << endl;
			cin >> x;
			cout << endl;
			switch (x) {
			case 1:SqSearch(); break;
			case 2:BinarySearch(); break;
			case 3:return;
			default:cout << "选择序号错误！" << endl;
			}
		}
	}

	//对总分进行快速排序		
	void Sort(int left, int right) {
		/*核心：根据基准数对数组进行划分（小于枢轴在左侧，大于在右侧）*/
		int i, j;
		char* standard;                       //存储基准数
		if (left > right) {                   //终止
			return;
		}
		standard = total[left];
		i = left;
		j = right;
		while (i != j) {
			while (strcmp(total[j], standard) >= 0 && i < j) {         //从右向左找小于基准数的值
				j--;
			}
			while (strcmp(total[i], standard) <= 0 && i < j) {      //从左向右找大于基准数的值
				i++;
			}
			/*交换两个数（及其他信息）在数组中的位置*/
			if (i <= j) {
				swap(id[i], id[j]);
				swap(name[i], name[j]);
				swap(sex[i], sex[j]);
				swap(age[i], age[j]);
				swap(class_[i], class_[j]);
				swap(English[i], English[j]);
				swap(math[i], math[j]);
				swap(Chinese[i], Chinese[j]);
				swap(history[i], history[j]);
				swap(geography[i], geography[j]);
				swap(total[i], total[j]);
			}
		}
		/*交换基准数和i=j时的值*/
		swap(id[i], id[left]);
		swap(name[i], name[left]);
		swap(sex[i], sex[left]);
		swap(age[i], age[left]);
		swap(class_[i], class_[left]);
		swap(English[i], English[left]);
		swap(math[i], math[left]);
		swap(Chinese[i], Chinese[left]);
		swap(history[i], history[left]);
		swap(geography[i], geography[left]);
		swap(total[i], total[left]);
		Sort(left, i - 1);//递归处理枢轴左边
		Sort(i + 1, right);//递归处理枢轴右边	
	}
};

class Undergraduate :public Student {          //大学生派生类
public:
	char* major[MaxSize];
	char* programing[MaxSize];
	char* highermath[MaxSize];
	Undergraduate() {
		for (int i = 0; i < MaxSize; i++) {
			major[i] = new char[100];
			programing[i] = new char[100];
			highermath[i] = new char[100];
		}
	}
	//文件读取操作
	void Read() {
		fp = fopen("undergraduate.txt", "r");
		if (fp == NULL) {
			cout << "打开文件失败！" << endl;
			exit(0);
		}
		while (fscanf(fp, "%s%s%s%s%s%s%s%s%s%s", id[i], name[i], sex[i], age[i], class_[i], major[i], English[i], programing[i], highermath[i], total[i]) == 10) {  // 循环读入学生信息
			i++;
		}
		n = i;                                               //用于存储已读取的学生信息数
		if (i == 0)
			cout << "文件为空!请先添加学生信息再执行此项！" << endl;
		else
			cout << "读取成功!" << endl;
		fclose(fp);
		system("pause");
		cout << endl;
	}

	//插入添加操作
	void Insert() {
		int add;
		cout << "请输入要插入的数据项数：" << endl;
		cin >> add;
		if (add <= 0) {
			cout << "键入信息错误！！" << endl;
			cout << endl;
			return;
		}
		cout << "请依次输入学号、姓名、性别、年龄、班级、专业、英语成绩、程序设计成绩、高数成绩、总分：" << endl;
		for (i = n; i < n + add; i++) {
			cin >> id[i] >> name[i] >> sex[i] >> age[i] >> class_[i] >> major[i] >> English[i] >> programing[i] >> highermath[i] >> total[i];
		}
		n = add + n;                                                        //改变学生总人数
		cout << "信息插入完毕！" << endl;
		cout << endl;
	}

	//删除操作
	void Delete() {
		int flag = 1;                                //标志位flag用于确定是否找到该学号
		int j;
		char target[20];
		cout << "请输入要删除学生的学号：" << endl;
		cin >> target;
		for (i = 0; i <= n; i++) {
			if (strcmp(id[i], target) == 0) {
				flag = 0; break;
			}
		}
		if (flag == 1) cout << "记录为空！删除失败！" << endl;
		else {
			n--;
			for (j = i; j <= n; j++) {                                  //将j后所有前移一位
				id[j] = id[j + 1];
				age[j] = age[j + 1];
				name[j] = name[j + 1];
				sex[j] = sex[j + 1];
				class_[j] = class_[j + 1];
				major[j] = major[j + 1];
				English[j] = English[j + 1];
				programing[j] = programing[j + 1];
				highermath[j] = highermath[j + 1];
				total[j] = total[j + 1];
			}
			cout << "删除成功！！" << endl;
		}cout << endl;
	}

	//统计操作
	void Sum() {
		cout << "共有" << n << "位学生的信息！" << endl;
		cout << endl;
	}

	//显示操作
	void Student::Print() {
		system("cls");
		Sum();
		cout << "  学号      姓名       性别     年龄        班级      专业     英语成绩     程序设计成绩     高等数学成绩     总分" << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
		if (n != 0) {
			for (i = 0; i < n; i++) {
				printf("%-10s %-12s %-10s %-8s %-10s %-12s %-12s %-12s %-12s %-10s\n", id[i], name[i], sex[i], age[i], class_[i], major[i], English[i], programing[i], highermath[i], total[i]);
			}
		}
		else cout << "管理系统为空！" << endl;
		cout << endl;
	}

	//更新保存操作
	void Updata() {
		fp = fopen("undergraduate.txt", "w");
		if (fp == NULL) cout << "打开文件失败！" << endl;
		else {
			for (i = 0; i < n; i++) {
				fprintf(fp, " % s % s % s % s % s % s % s % s % s % s\n", id[i], name[i], sex[i], age[i], class_[i], major[i], English[i], programing[i], highermath[i], total[i]);
			}cout << "信息已完成更新,可在文本文档中查看!" << endl;
			cout << endl;
		}fclose(fp);
	}

	//对姓名进行顺序查找
	void SqSearch() {
		char aim[10];
		int flag = 1;
		cout << "请输入要查找学生的姓名：" << endl;
		cin >> aim;
		for (i = 0; i <= n; i++) {
			if (strcmp(name[i], aim) == 0) {
				flag = 0; break;
			}
		}
		if (flag == 1) {
			cout << "未找到要查找的姓名！" << endl;
			cout << endl;
		}
		else {
			cout << "查找结果如下：" << endl;
			cout << "  学号      姓名       性别     年龄        班级      专业     英语成绩     程序设计成绩     高等数学成绩     总分" << endl;
			cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
			printf("%-10s %-10s %-10s %-8s %-10s %-10s %-10s %-10s %-10s %-10s\n", id[i], name[i], sex[i], age[i], class_[i], major[i], English[i], programing[i], highermath[i], total[i]);
		}
		cout << endl;
	}

	//对学号进行二分法查找
	void BinarySearch() {
		char goal[10];
		Sort(0, n - 1);
		int high = n - 1;
		int low = 0;
		int flag = 0;
		cout << "请输入要查找的学号:" << endl;
		cin >> goal;
		while (low <= high) {
			int mid = (high + low) / 2;
			if (strcmp(id[mid], goal) == 0) {
				cout << "查找结果如下：" << endl;
				cout << "  学号      姓名       性别     年龄        班级      专业     英语成绩     程序设计成绩     高等数学成绩     总分" << endl;
				cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
				printf("%-10s %-10s %-10s %-8s %-10s %-10s %-10s %-10s %-10s %-10s \n", id[mid], name[mid], sex[mid], age[mid], class_[mid], major[i], English[mid], programing[i], highermath[mid], total[mid]);
				flag = 1;
				break;
			}
			else if (strcmp(goal, id[mid]) < 0) high = mid - 1;                   //根据算法对范围（low、high）变化
			else if (strcmp(goal, id[mid]) > 0)low = mid + 1;

		}
		if (flag == 0) cout << "未找到对应学号！！" << endl;
		cout << endl;
	}

	//查找子菜单
	void Search() {
		int x;
		cout << "^^^^^^^^^^^^^^^^^" << endl;
		cout << "^    *子菜单*   ^" << endl;
		cout << "^ 1、按姓名查找 ^" << endl;
		cout << "^ 2、按学号查找 ^" << endl;
		cout << "^ 3、退出本菜单 ^" << endl;
		cout << "^               ^" << endl;
		cout << "^^^^^^^^^^^^^^^^^" << endl;
		while (1) {
			cout << "请选择子菜单编号:" << endl;
			cin >> x;
			cout << endl;
			switch (x) {
			case 1:SqSearch(); break;
			case 2:BinarySearch(); break;
			case 3:return;
			default:cout << "选择序号错误！" << endl;
			}
		}
	}

	//对总分进行快速排序		
	void Sort(int left, int right) {
		/*核心：根据基准数对数组进行划分（小于枢轴在左侧，大于在右侧）*/
		int i, j;
		char* standard;                       //存储基准数
		if (left > right) {                   //终止
			return;
		}
		standard = total[left];
		i = left;
		j = right;
		while (i != j) {
			while (strcmp(total[j], standard) >= 0 && i < j) {         //从右向左找小于基准数的值
				j--;
			}
			while (strcmp(total[i], standard) <= 0 && i < j) {      //从左向右找大于基准数的值
				i++;
			}
			/*交换两个数（及其他信息）在数组中的位置*/
			if (i <= j) {
				swap(id[i], id[j]);
				swap(name[i], name[j]);
				swap(sex[i], sex[j]);
				swap(age[i], age[j]);
				swap(class_[i], class_[j]);
				swap(English[i], English[j]);
				swap(major[i], major[j]);
				swap(highermath[i], highermath[j]);
				swap(programing[i], programing[j]);
				swap(total[i], total[j]);
			}
		}
		/*交换基准数和i=j时的值*/
		swap(id[i], id[left]);
		swap(name[i], name[left]);
		swap(sex[i], sex[left]);
		swap(age[i], age[left]);
		swap(class_[i], class_[left]);
		swap(English[i], English[left]);
		swap(major[i], major[left]);
		swap(highermath[i], highermath[left]);
		swap(programing[i], programing[left]);
		swap(total[i], total[left]);
		Sort(left, i - 1);//递归处理枢轴左边
		Sort(i + 1, right);//递归处理枢轴右边	
	}
};

/*欢迎界面*/
void Hello() {                                                                 //欢迎菜单
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "*  Student Achievement Studentment System 1.0 *" << endl;
	cout << "*                                             *" << endl;
	cout << "*          欢迎进入学生成绩管理系统！         *" << endl;
	cout << "*                                             *" << endl;
	cout << "* Copyright 2021 Yangyao.All Rights Reserved. *" << endl;
	cout << "*                                             *" << endl;
	cout << "*                 19041106                    *" << endl;
	cout << "*                                             *" << endl;
	cout << "                                               " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
/*提示界面*/
void Notice() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "*                 *使用说明*                     *" << endl;
	cout << "*                                                *" << endl;
	cout << "*         1、第一次进入系统请先读取文件          *" << endl;
	cout << "*                                                *" << endl;
	cout << "*      2、如果要保存当前操作请选择更新选项       *" << endl;
	cout << "*                                                *" << endl;
	cout << "*  3 、系统会根据学生群体的选择自动读取相应文件  *" << endl;
	cout << "*                                                *" << endl;
	cout << "* 4、需要读取中文文字信息请选择txt文件编码为ANSI *" << endl;
	cout << "                                                  " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	system("pause");
}
/*菜单界面*/
void Menu() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "*              * 功能选择主菜单 *             *" << endl;
	cout << "*                                             *" << endl;
	cout << "*        1、插入               2、删除        *" << endl;
	cout << "*        3、查找               4、排序        *" << endl;
	cout << "*        5、统计               6、显示        *" << endl;
	cout << "*        7、更新               8、退出        *" << endl;
	cout << "*                                             *" << endl;
	cout << "                                               " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
/*群体选择界面*/
void Level() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "*         请先选择需要管理的学生群体：        *" << endl;
	cout << "*                 1、小学                     *" << endl;
	cout << "*                 2、中学                     *" << endl;
	cout << "*                 3、大学                     *" << endl;
	cout << "                                               " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

int main() {
	int choice1, choice2;
	Pupil P;
	Middle M;
	Undergraduate U;
	Hello();
	system("pause");
	system("cls");
	Notice();
	system("cls");
	Level();
	cout << "请输入要选择的操作序号：" << endl;
	cin >> choice1;
	switch (choice1) {
	case 1:P.Read(); break;
	case 2:M.Read(); break;
	case 3:U.Read(); break;
	}
	while (fp != NULL) {
		Menu();
		cout << "请输入要选择的操作序号：" << endl;
		cin >> choice2;
		if (choice2 == 8) break;
		switch (choice2) {
		case 1:
			if (choice1 == 1) { P.Insert(); }
			if (choice1 == 2) { M.Insert(); }
			if (choice1 == 3) { U.Insert(); }
			break;
		case 2:
			if (choice1 == 1) { P.Delete(); }
			if (choice1 == 2) { M.Delete(); }
			if (choice1 == 3) { U.Delete(); }
			break;
		case 3:
			if (choice1 == 1) { P.Search(); }
			if (choice1 == 2) { M.Search(); }
			if (choice1 == 3) { U.Search(); }
			break;
		case 4:
			if (choice1 == 1) { P.Sort(0, n); }
			if (choice1 == 2) { M.Sort(0, n); }
			if (choice1 == 3) { U.Sort(0, n); }
			break;
		case 5:
			if (choice1 == 1) { P.Sum(); }
			if (choice1 == 2) { M.Sum(); }
			if (choice1 == 3) { U.Sum(); }
			break;
		case 6:
			if (choice1 == 1) { P.Print(); }
			if (choice1 == 2) { M.Print(); }
			if (choice1 == 3) { U.Print(); }
			break;
		case 7:
			if (choice1 == 1) { P.Updata(); }
			if (choice1 == 2) { M.Updata(); }
			if (choice1 == 3) { U.Updata(); }
			break;
		default:cout << "选择序号错误！！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}