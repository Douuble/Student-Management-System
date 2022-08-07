#include <iostream>
#include <stdlib.h> 
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MaxSize 100                    //ѧ���������ֵ ���޸�
using namespace std;


class Student {                        //ѧ��������Ϣ����
public:
	char* id[MaxSize];
	char* name[MaxSize];
	char* age[MaxSize];
	char* sex[MaxSize];
	char* class_[MaxSize];
	char* English[MaxSize];
	char* total[MaxSize];
	//���캯������
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
	//�麯������
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

FILE* fp;                      //�ļ�ָ��
int i;
int n;                        //���ڴ���ѧ����Ϣ��
int x;                        //���ڶ����˵���ѡ��

class Pupil :public virtual Student {                    //Сѧ��������
public:
	char* Chinese[MaxSize];
	char* math[MaxSize];
	Pupil() {
		for (int i = 0; i < MaxSize; i++) {
			Chinese[i] = new char[100];
			math[i] = new char[100];
		}
	}

	//�ļ���ȡ����
	void Read() {
		fp = fopen("pupil.txt", "r");
		if (fp == NULL) {
			cout << "���ļ�ʧ�ܣ�" << endl;
			exit(0);
		}
		while (fscanf(fp, "%s%s%s%s%s%s%s%s%s", id[i], name[i], sex[i], age[i], class_[i], English[i], math[i], Chinese[i], total[i]) == 9) {  // ѭ������ѧ����Ϣ
			i++;
		}
		n = i;                                               //���ڴ洢�Ѷ�ȡ��ѧ����Ϣ��
		if (i == 0)
			cout << "�ļ�Ϊ��!�������ѧ����Ϣ��ִ�д��" << endl;
		else
			cout << "��ȡ�ļ��ɹ�!" << endl;
		fclose(fp);
		cout << endl;
	}

	//������Ӳ���
	void Insert() {
		int add;
		cout << "������Ҫ���������������" << endl;
		cin >> add;
		if (add <= 0) {
			cout << "������Ϣ���󣡣�" << endl;
			cout << endl;
			return;
		}
		cout << "����������ѧ�š��������Ա����䡢�༶��Ӣ��ɼ�����ѧ�ɼ������ĳɼ����ܷ֣�" << endl;
		for (i = n; i < n + add; i++) {
			cin >> id[i] >> name[i] >> sex[i] >> age[i] >> class_[i] >> English[i] >> math[i] >> Chinese[i] >> total[i];
		}
		n = add + n;                                                        //�ı�ѧ��������
		cout << "��Ϣ������ϣ�" << endl;
		cout << endl;
	}

	//ɾ������
	void Delete() {
		int flag = 1;                                //��־λflag����ȷ���Ƿ��ҵ���ѧ��
		int j;
		char target[20];
		cout << "������Ҫɾ��ѧ����ѧ�ţ�" << endl;
		cin >> target;
		for (i = 0; i <= n; i++) {
			if (strcmp(id[i], target) == 0) {
				flag = 0; break;
			}
		}
		if (flag == 1) cout << "��¼Ϊ�գ�ɾ��ʧ�ܣ�" << endl;
		else {
			n--;
			for (j = i; j <= n; j++) {                                  //��j������ǰ��һλ
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
			cout << "ɾ���ɹ�����" << endl;
		}cout << endl;
	}

	//ͳ�Ʋ���
	void Sum() {
		cout << "����" << n << "λѧ������Ϣ��" << endl;
		cout << endl;
	}

	//��ʾ����
	void Student::Print() {
		system("cls");
		Sum();
		cout << "  ѧ��      ����      �Ա�      ����       �༶      Ӣ��ɼ�     ��ѧ�ɼ�     ���ĳɼ�      �ܷ�" << endl;
		cout << "----------------------------------------------------------------------------------------------------" << endl;
		if (n != 0) {
			for (i = 0; i < n; i++) {
				printf("%-11s %-10s %-9s %-8s %-14s %-12s %-10s %-11s %-10s\n", id[i], name[i], sex[i], age[i], class_[i], English[i], math[i], Chinese[i], total[i]);
			}
		}
		else cout << "����ϵͳΪ�գ�" << endl;
		cout << endl;
	}

	//���±������
	void Updata() {
		fp = fopen("pupil.txt", "w");
		if (fp == NULL) cout << "���ļ�ʧ�ܣ�" << endl;
		else {
			for (i = 0; i < n; i++) {
				fprintf(fp, " % s % s % s % s % s % s % s % s % s\n", id[i], name[i], sex[i], age[i], class_[i], English[i], math[i], Chinese[i], total[i]);
			}cout << "��Ϣ����ɸ���,�����ı��ĵ��в鿴!" << endl;
			cout << endl;
		}fclose(fp);
	}

	//����������˳�����
	void SqSearch() {
		char aim[10];
		int flag = 1;
		cout << "������Ҫ����ѧ����������" << endl;
		cin >> aim;
		for (i = 0; i <= n; i++) {
			if (strcmp(name[i], aim) == 0) {
				flag = 0; break;
			}
		}
		if (flag == 1) {
			cout << "δ�ҵ�Ҫ���ҵ�������" << endl;
			cout << endl;
		}
		else {
			cout << "���ҽ�����£�" << endl;
			cout << "  ѧ��      ����       �Ա�     ����        �༶      Ӣ��ɼ�     ��ѧ�ɼ�     ���ĳɼ�      �ܷ�" << endl;
			cout << "----------------------------------------------------------------------------------------------------" << endl;
			printf("%-11s %-10s %-9s %-8s %-14s %-12s %-10s %-11s %-10s\n", id[i], name[i], sex[i], age[i], class_[i], English[i], math[i], Chinese[i], total[i]);
		}
		cout << endl;
	}

	//��ѧ�Ž��ж��ַ�����
	void BinarySearch() {
		char goal[10];
		Sort(0, n - 1);
		int high = n - 1;
		int low = 0;
		int flag = 0;
		cout << "������Ҫ���ҵ�ѧ��:" << endl;
		cin >> goal;
		while (low <= high) {
			int mid = (high + low) / 2;
			if (strcmp(id[mid], goal) == 0) {
				cout << "���ҽ�����£�" << endl;
				cout << "  ѧ��      ����       �Ա�     ����        �༶      Ӣ��ɼ�     ��ѧ�ɼ�     ���ĳɼ�      �ܷ�" << endl;
				cout << "----------------------------------------------------------------------------------------------------" << endl;
				printf("%-11s %-10s %-9s %-8s %-14s %-12s %-10s %-11s %-10s\n", id[mid], name[mid], sex[mid], age[mid], class_[mid], English[mid], math[mid], Chinese[mid], total[mid]);
				flag = 1;
				break;
			}
			else if (strcmp(goal, id[mid]) < 0) high = mid - 1;                   //�����㷨�Է�Χ��low��high���仯
			else if (strcmp(goal, id[mid]) > 0)low = mid + 1;

		}
		if (flag == 0) cout << "δ�ҵ���Ӧѧ�ţ���" << endl;
		cout << endl;
	}

	//�����Ӳ˵�
	void Search() {
		int x;
		cout << "^^^^^^^^^^^^^^^^^" << endl;
		cout << "^    *�Ӳ˵�*   ^" << endl;
		cout << "^ 1������������ ^" << endl;
		cout << "^ 2����ѧ�Ų��� ^" << endl;
		cout << "^ 3���˳����˵� ^" << endl;
		cout << "^               ^" << endl;
		cout << "^^^^^^^^^^^^^^^^^" << endl;
		while (1) {
			cout << "��ѡ���Ӳ˵����:" << endl;
			cin >> x;
			cout << endl;
			switch (x) {
			case 1:SqSearch(); break;
			case 2:BinarySearch(); break;
			case 3:return;
			default:cout << "ѡ����Ŵ���" << endl;
			}
		}
	}

	//���ֽܷ��п�������		
	void Sort(int left, int right) {
		/*���ģ����ݻ�׼����������л��֣�С����������࣬�������Ҳࣩ*/
		int i, j;
		char* standard;                       //�洢��׼��
		if (left > right) {                   //��ֹ
			return;
		}
		standard = total[left];
		i = left;
		j = right;
		while (i != j) {
			while (strcmp(total[j], standard) >= 0 && i < j) {         //����������С�ڻ�׼����ֵ
				j--;
			}
			while (strcmp(total[i], standard) <= 0 && i < j) {      //���������Ҵ��ڻ�׼����ֵ
				i++;
			}
			/*��������������������Ϣ���������е�λ��*/
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
		/*������׼����i=jʱ��ֵ*/
		swap(id[i], id[left]);
		swap(name[i], name[left]);
		swap(sex[i], sex[left]);
		swap(age[i], age[left]);
		swap(class_[i], class_[left]);
		swap(English[i], English[left]);
		swap(math[i], math[left]);
		swap(Chinese[i], Chinese[left]);
		swap(total[i], total[left]);
		Sort(left, i - 1);//�ݹ鴦���������
		Sort(i + 1, right);//�ݹ鴦�������ұ�	
	}
};

class Middle :public Pupil {                    //��ѧ��������
public:
	char* history[MaxSize];
	char* geography[MaxSize];
	Middle() {
		for (int i = 0; i < MaxSize; i++) {
			history[i] = new char[100];
			geography[i] = new char[100];
		}
	}
	//�ļ���ȡ����
	void Read() {
		fp = fopen("middle.txt", "r");
		if (fp == NULL) {
			cout << "���ļ�ʧ�ܣ�" << endl;
			exit(0);
		}
		while (fscanf(fp, "%s%s%s%s%s%s%s%s%s%s%s", id[i], name[i], sex[i], age[i], class_[i], English[i], math[i], Chinese[i], history[i], geography[i], total[i]) == 11) {  // ѭ������ѧ����Ϣ
			i++;
		}
		n = i;                                               //���ڴ洢�Ѷ�ȡ��ѧ����Ϣ��
		if (i == 0)
			cout << "�ļ�Ϊ��!�������ѧ����Ϣ��ִ�д��" << endl;
		else
			cout << "��ȡ�ɹ�!" << endl;
		fclose(fp);
		cout << endl;
	}

	//������Ӳ���
	void Insert() {
		int add;
		cout << "������Ҫ���������������" << endl;
		cin >> add;
		if (add <= 0) {
			cout << "������Ϣ���󣡣�" << endl;
			cout << endl;
			return;
		}
		cout << "����������ѧ�š��������Ա����䡢�༶��Ӣ��ɼ�����ѧ�ɼ������ĳɼ�����ʷ�ɼ�������ɼ����ܷ֣�" << endl;
		for (i = n; i < n + add; i++) {
			cin >> id[i] >> name[i] >> sex[i] >> age[i] >> class_[i] >> English[i] >> math[i] >> Chinese[i] >> history[i] >> geography[i] >> total[i];
		}
		n = add + n;                                                        //�ı�ѧ��������
		cout << "��Ϣ������ϣ�" << endl;
		cout << endl;
	}

	//ɾ������
	void Delete() {
		int flag = 1;                                //��־λflag����ȷ���Ƿ��ҵ���ѧ��
		int j;
		char target[20];
		cout << "������Ҫɾ��ѧ����ѧ�ţ�" << endl;
		cin >> target;
		for (i = 0; i <= n; i++) {
			if (strcmp(id[i], target) == 0) {
				flag = 0; break;
			}
		}
		if (flag == 1) cout << "��¼Ϊ�գ�ɾ��ʧ�ܣ�" << endl;
		else {
			n--;
			for (j = i; j <= n; j++) {                                  //��j������ǰ��һλ
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
			cout << "ɾ���ɹ�����" << endl;
		}cout << endl;
	}

	//ͳ�Ʋ���
	void Sum() {
		cout << "����" << n << "λѧ������Ϣ��" << endl;
		cout << endl;
	}

	//��ʾ����
	void Student::Print() {
		system("cls");
		Sum();
		cout << "  ѧ��      ����       �Ա�     ����        �༶      Ӣ��ɼ�     ��ѧ�ɼ�     ���ĳɼ�     ��ʷ�ɼ�       ����ɼ�     �ܷ�" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
		if (n != 0) {
			for (i = 0; i < n; i++) {
				printf("%-11s %-10s %-10s %-9s %-10s %-13s %-10s %-14s %-14s %-10s %-10s\n", id[i], name[i], sex[i], age[i], class_[i], English[i], math[i], Chinese[i], history[i], geography[i], total[i]);
			}
		}
		else cout << "����ϵͳΪ�գ�" << endl;
		cout << endl;
	}

	//���±������
	void Updata() {
		fp = fopen("middle.txt", "w");
		if (fp == NULL) cout << "���ļ�ʧ�ܣ�" << endl;
		else {
			for (i = 0; i < n; i++) {
				fprintf(fp, " % s % s % s % s % s % s % s % s % s % s % s\n", id[i], name[i], sex[i], age[i], class_[i], English[i], math[i], Chinese[i], history[i], geography[i], total[i]);
			}cout << "��Ϣ����ɸ���,�����ı��ĵ��в鿴!" << endl;
			cout << endl;
		}fclose(fp);
	}

	//����������˳�����
	void SqSearch() {
		char aim[10];
		int flag = 1;
		cout << "������Ҫ����ѧ����������" << endl;
		cin >> aim;
		for (i = 0; i <= n; i++) {
			if (strcmp(name[i], aim) == 0) {
				flag = 0; break;
			}
		}
		if (flag == 1) {
			cout << "δ�ҵ�Ҫ���ҵ�������" << endl;
			cout << endl;
		}
		else {
			cout << "���ҽ�����£�" << endl;
			cout << "  ѧ��      ����       �Ա�     ����        �༶      Ӣ��ɼ�     ��ѧ�ɼ�     ���ĳɼ�     ��ʷ�ɼ�       ����ɼ�     �ܷ�" << endl;
			cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
			printf("%-10s %-10s %-10s %-8s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", id[i], name[i], sex[i], age[i], class_[i], English[i], math[i], Chinese[i], history[i], geography[i], total[i]);
		}
		cout << endl;
	}

	//��ѧ�Ž��ж��ַ�����
	void BinarySearch() {
		char goal[10];
		Sort(0, n - 1);
		int high = n - 1;
		int low = 0;
		int flag = 0;
		cout << "������Ҫ���ҵ�ѧ��:" << endl;
		cin >> goal;
		while (low <= high) {
			int mid = (high + low) / 2;
			if (strcmp(id[mid], goal) == 0) {
				cout << "���ҽ�����£�" << endl;
				cout << "  ѧ��      ����       �Ա�     ����        �༶      Ӣ��ɼ�     ��ѧ�ɼ�     ���ĳɼ�     ��ʷ�ɼ�       ����ɼ�     �ܷ�" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
				printf("%-10s %-10s %-10s %-8s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", id[mid], name[mid], sex[mid], age[mid], class_[mid], English[mid], math[mid], Chinese[mid], history[mid], geography[mid], total[mid]);
				flag = 1;
				break;
			}
			else if (strcmp(goal, id[mid]) < 0) high = mid - 1;                   //�����㷨�Է�Χ��low��high���仯
			else if (strcmp(goal, id[mid]) > 0)low = mid + 1;

		}
		if (flag == 0) cout << "δ�ҵ���Ӧѧ�ţ���" << endl;
		cout << endl;
	}

	//�����Ӳ˵�
	void Search() {
		int x;
		cout << "^^^^^^^^^^^^^^^^^" << endl;
		cout << "^    *�Ӳ˵�*   ^" << endl;
		cout << "^ 1������������ ^" << endl;
		cout << "^ 2����ѧ�Ų��� ^" << endl;
		cout << "^ 3���˳����˵� ^" << endl;
		cout << "^               ^" << endl;
		cout << "^^^^^^^^^^^^^^^^^" << endl;
		while (1) {
			cout << "��ѡ���Ӳ˵����:" << endl;
			cin >> x;
			cout << endl;
			switch (x) {
			case 1:SqSearch(); break;
			case 2:BinarySearch(); break;
			case 3:return;
			default:cout << "ѡ����Ŵ���" << endl;
			}
		}
	}

	//���ֽܷ��п�������		
	void Sort(int left, int right) {
		/*���ģ����ݻ�׼����������л��֣�С����������࣬�������Ҳࣩ*/
		int i, j;
		char* standard;                       //�洢��׼��
		if (left > right) {                   //��ֹ
			return;
		}
		standard = total[left];
		i = left;
		j = right;
		while (i != j) {
			while (strcmp(total[j], standard) >= 0 && i < j) {         //����������С�ڻ�׼����ֵ
				j--;
			}
			while (strcmp(total[i], standard) <= 0 && i < j) {      //���������Ҵ��ڻ�׼����ֵ
				i++;
			}
			/*��������������������Ϣ���������е�λ��*/
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
		/*������׼����i=jʱ��ֵ*/
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
		Sort(left, i - 1);//�ݹ鴦���������
		Sort(i + 1, right);//�ݹ鴦�������ұ�	
	}
};

class Undergraduate :public Student {          //��ѧ��������
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
	//�ļ���ȡ����
	void Read() {
		fp = fopen("undergraduate.txt", "r");
		if (fp == NULL) {
			cout << "���ļ�ʧ�ܣ�" << endl;
			exit(0);
		}
		while (fscanf(fp, "%s%s%s%s%s%s%s%s%s%s", id[i], name[i], sex[i], age[i], class_[i], major[i], English[i], programing[i], highermath[i], total[i]) == 10) {  // ѭ������ѧ����Ϣ
			i++;
		}
		n = i;                                               //���ڴ洢�Ѷ�ȡ��ѧ����Ϣ��
		if (i == 0)
			cout << "�ļ�Ϊ��!�������ѧ����Ϣ��ִ�д��" << endl;
		else
			cout << "��ȡ�ɹ�!" << endl;
		fclose(fp);
		system("pause");
		cout << endl;
	}

	//������Ӳ���
	void Insert() {
		int add;
		cout << "������Ҫ���������������" << endl;
		cin >> add;
		if (add <= 0) {
			cout << "������Ϣ���󣡣�" << endl;
			cout << endl;
			return;
		}
		cout << "����������ѧ�š��������Ա����䡢�༶��רҵ��Ӣ��ɼ���������Ƴɼ��������ɼ����ܷ֣�" << endl;
		for (i = n; i < n + add; i++) {
			cin >> id[i] >> name[i] >> sex[i] >> age[i] >> class_[i] >> major[i] >> English[i] >> programing[i] >> highermath[i] >> total[i];
		}
		n = add + n;                                                        //�ı�ѧ��������
		cout << "��Ϣ������ϣ�" << endl;
		cout << endl;
	}

	//ɾ������
	void Delete() {
		int flag = 1;                                //��־λflag����ȷ���Ƿ��ҵ���ѧ��
		int j;
		char target[20];
		cout << "������Ҫɾ��ѧ����ѧ�ţ�" << endl;
		cin >> target;
		for (i = 0; i <= n; i++) {
			if (strcmp(id[i], target) == 0) {
				flag = 0; break;
			}
		}
		if (flag == 1) cout << "��¼Ϊ�գ�ɾ��ʧ�ܣ�" << endl;
		else {
			n--;
			for (j = i; j <= n; j++) {                                  //��j������ǰ��һλ
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
			cout << "ɾ���ɹ�����" << endl;
		}cout << endl;
	}

	//ͳ�Ʋ���
	void Sum() {
		cout << "����" << n << "λѧ������Ϣ��" << endl;
		cout << endl;
	}

	//��ʾ����
	void Student::Print() {
		system("cls");
		Sum();
		cout << "  ѧ��      ����       �Ա�     ����        �༶      רҵ     Ӣ��ɼ�     ������Ƴɼ�     �ߵ���ѧ�ɼ�     �ܷ�" << endl;
		cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
		if (n != 0) {
			for (i = 0; i < n; i++) {
				printf("%-10s %-12s %-10s %-8s %-10s %-12s %-12s %-12s %-12s %-10s\n", id[i], name[i], sex[i], age[i], class_[i], major[i], English[i], programing[i], highermath[i], total[i]);
			}
		}
		else cout << "����ϵͳΪ�գ�" << endl;
		cout << endl;
	}

	//���±������
	void Updata() {
		fp = fopen("undergraduate.txt", "w");
		if (fp == NULL) cout << "���ļ�ʧ�ܣ�" << endl;
		else {
			for (i = 0; i < n; i++) {
				fprintf(fp, " % s % s % s % s % s % s % s % s % s % s\n", id[i], name[i], sex[i], age[i], class_[i], major[i], English[i], programing[i], highermath[i], total[i]);
			}cout << "��Ϣ����ɸ���,�����ı��ĵ��в鿴!" << endl;
			cout << endl;
		}fclose(fp);
	}

	//����������˳�����
	void SqSearch() {
		char aim[10];
		int flag = 1;
		cout << "������Ҫ����ѧ����������" << endl;
		cin >> aim;
		for (i = 0; i <= n; i++) {
			if (strcmp(name[i], aim) == 0) {
				flag = 0; break;
			}
		}
		if (flag == 1) {
			cout << "δ�ҵ�Ҫ���ҵ�������" << endl;
			cout << endl;
		}
		else {
			cout << "���ҽ�����£�" << endl;
			cout << "  ѧ��      ����       �Ա�     ����        �༶      רҵ     Ӣ��ɼ�     ������Ƴɼ�     �ߵ���ѧ�ɼ�     �ܷ�" << endl;
			cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
			printf("%-10s %-10s %-10s %-8s %-10s %-10s %-10s %-10s %-10s %-10s\n", id[i], name[i], sex[i], age[i], class_[i], major[i], English[i], programing[i], highermath[i], total[i]);
		}
		cout << endl;
	}

	//��ѧ�Ž��ж��ַ�����
	void BinarySearch() {
		char goal[10];
		Sort(0, n - 1);
		int high = n - 1;
		int low = 0;
		int flag = 0;
		cout << "������Ҫ���ҵ�ѧ��:" << endl;
		cin >> goal;
		while (low <= high) {
			int mid = (high + low) / 2;
			if (strcmp(id[mid], goal) == 0) {
				cout << "���ҽ�����£�" << endl;
				cout << "  ѧ��      ����       �Ա�     ����        �༶      רҵ     Ӣ��ɼ�     ������Ƴɼ�     �ߵ���ѧ�ɼ�     �ܷ�" << endl;
				cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
				printf("%-10s %-10s %-10s %-8s %-10s %-10s %-10s %-10s %-10s %-10s \n", id[mid], name[mid], sex[mid], age[mid], class_[mid], major[i], English[mid], programing[i], highermath[mid], total[mid]);
				flag = 1;
				break;
			}
			else if (strcmp(goal, id[mid]) < 0) high = mid - 1;                   //�����㷨�Է�Χ��low��high���仯
			else if (strcmp(goal, id[mid]) > 0)low = mid + 1;

		}
		if (flag == 0) cout << "δ�ҵ���Ӧѧ�ţ���" << endl;
		cout << endl;
	}

	//�����Ӳ˵�
	void Search() {
		int x;
		cout << "^^^^^^^^^^^^^^^^^" << endl;
		cout << "^    *�Ӳ˵�*   ^" << endl;
		cout << "^ 1������������ ^" << endl;
		cout << "^ 2����ѧ�Ų��� ^" << endl;
		cout << "^ 3���˳����˵� ^" << endl;
		cout << "^               ^" << endl;
		cout << "^^^^^^^^^^^^^^^^^" << endl;
		while (1) {
			cout << "��ѡ���Ӳ˵����:" << endl;
			cin >> x;
			cout << endl;
			switch (x) {
			case 1:SqSearch(); break;
			case 2:BinarySearch(); break;
			case 3:return;
			default:cout << "ѡ����Ŵ���" << endl;
			}
		}
	}

	//���ֽܷ��п�������		
	void Sort(int left, int right) {
		/*���ģ����ݻ�׼����������л��֣�С����������࣬�������Ҳࣩ*/
		int i, j;
		char* standard;                       //�洢��׼��
		if (left > right) {                   //��ֹ
			return;
		}
		standard = total[left];
		i = left;
		j = right;
		while (i != j) {
			while (strcmp(total[j], standard) >= 0 && i < j) {         //����������С�ڻ�׼����ֵ
				j--;
			}
			while (strcmp(total[i], standard) <= 0 && i < j) {      //���������Ҵ��ڻ�׼����ֵ
				i++;
			}
			/*��������������������Ϣ���������е�λ��*/
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
		/*������׼����i=jʱ��ֵ*/
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
		Sort(left, i - 1);//�ݹ鴦���������
		Sort(i + 1, right);//�ݹ鴦�������ұ�	
	}
};

/*��ӭ����*/
void Hello() {                                                                 //��ӭ�˵�
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "*  Student Achievement Studentment System 1.0 *" << endl;
	cout << "*                                             *" << endl;
	cout << "*          ��ӭ����ѧ���ɼ�����ϵͳ��         *" << endl;
	cout << "*                                             *" << endl;
	cout << "* Copyright 2021 Yangyao.All Rights Reserved. *" << endl;
	cout << "*                                             *" << endl;
	cout << "*                 19041106                    *" << endl;
	cout << "*                                             *" << endl;
	cout << "                                               " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
/*��ʾ����*/
void Notice() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "*                 *ʹ��˵��*                     *" << endl;
	cout << "*                                                *" << endl;
	cout << "*         1����һ�ν���ϵͳ���ȶ�ȡ�ļ�          *" << endl;
	cout << "*                                                *" << endl;
	cout << "*      2�����Ҫ���浱ǰ������ѡ�����ѡ��       *" << endl;
	cout << "*                                                *" << endl;
	cout << "*  3 ��ϵͳ�����ѧ��Ⱥ���ѡ���Զ���ȡ��Ӧ�ļ�  *" << endl;
	cout << "*                                                *" << endl;
	cout << "* 4����Ҫ��ȡ����������Ϣ��ѡ��txt�ļ�����ΪANSI *" << endl;
	cout << "                                                  " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	system("pause");
}
/*�˵�����*/
void Menu() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "*              * ����ѡ�����˵� *             *" << endl;
	cout << "*                                             *" << endl;
	cout << "*        1������               2��ɾ��        *" << endl;
	cout << "*        3������               4������        *" << endl;
	cout << "*        5��ͳ��               6����ʾ        *" << endl;
	cout << "*        7������               8���˳�        *" << endl;
	cout << "*                                             *" << endl;
	cout << "                                               " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
/*Ⱥ��ѡ�����*/
void Level() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "*         ����ѡ����Ҫ�����ѧ��Ⱥ�壺        *" << endl;
	cout << "*                 1��Сѧ                     *" << endl;
	cout << "*                 2����ѧ                     *" << endl;
	cout << "*                 3����ѧ                     *" << endl;
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
	cout << "������Ҫѡ��Ĳ�����ţ�" << endl;
	cin >> choice1;
	switch (choice1) {
	case 1:P.Read(); break;
	case 2:M.Read(); break;
	case 3:U.Read(); break;
	}
	while (fp != NULL) {
		Menu();
		cout << "������Ҫѡ��Ĳ�����ţ�" << endl;
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
		default:cout << "ѡ����Ŵ��󣡣�" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}