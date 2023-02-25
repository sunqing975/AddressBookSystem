#include<iostream>
#include<string>
using namespace std;
// �궨�岻��˵������䣬����ĩ���ؼӷֺţ�����Ϸֺ������ֺ�Ҳһ���û���
#define MAX 1000
struct person {
	string name; // ����
	int sex; // �Ա�  1Ϊ��  0ΪŮ
	int age; // ����
	string phone; // �ֻ�����
	string address; // ��ͥסַ
};
struct addressBook {
	// ͨ��¼�б������ϵ������
	struct person personArry[MAX];
	// ͨ��¼��ǰ��¼��ϵ�˸���
	int p_size;
};

// ��װ������ʾ���棬��void showMenu()
// ��main�����е��÷�װ�õĺ���

// �˵�����
void showMenu() {
	cout << "*************************" << endl;
	cout << "***** 1. �����ϵ�� *****" << endl;
	cout << "***** 2. ��ʾ��ϵ�� *****" << endl;
	cout << "***** 3. ɾ����ϵ�� *****" << endl;
	cout << "***** 4. ������ϵ�� *****" << endl;
	cout << "***** 5. �޸���ϵ�� *****" << endl;
	cout << "***** 6. �����ϵ�� *****" << endl;
	cout << "***** 0. �˳�ͨ��¼ *****" << endl;
	cout << "*************************" << endl;
}
// 1. �����ϵ��
void addPerson(struct addressBook * p) {
	// �ж�ͨѶ¼�Ƿ�������������˾Ͳ������
	if (p->p_size >= MAX) {
		cout << "ͨѶ¼��������ʱ�޷���ӣ��뿪ͨ��Ա" << endl;
		return;
	}
	else {
		// ��Ӿ�����ϵ��

		// ����
		string name;
		cout << "������������" << endl;
		cin >> name;
		p->personArry[p->p_size].name = name;
		// �Ա�
		int sex = 0;
		while (true) {
			cout << "�������Ա�: " << endl;
			cout << "0-------Ů" << endl;
			cout << "1-------��" << endl;
			cin >> sex;
			if (sex == 0 || sex == 1) {
				p->personArry[p->p_size].sex = sex;
				break;
			}
		}
		// ����
		int age = 0;
		while (true) {
			cout << "��������ϵ�����䣺" << endl;
			cout << "����Ӧ����0��" << endl;
			cin >> age;
			if (age > 0) {
				p->personArry[p->p_size].age = age;
				break;
			}
		}
		// �绰
		string phone;
		cout << "�������ֻ����룺" << endl;
		cin >> phone;
		p->personArry[p->p_size].phone = phone;
		// סַ
		string address;
		cout << "�������ͥסַ��" << endl;
		cin >> address;
		p->personArry[p->p_size].address = address;
		// ����ͨѶ¼����
		p->p_size++;

		cout << name << " ��ӳɹ�" << endl;

		system("pause"); // �밴���������
		system("cls");  // ��������
	}
}

// 2. ��ʾ��ϵ��
void showPerson(struct addressBook* p) {
	// �����ж�ͨѶ¼���Ƿ�����
	if (p->p_size == 0) {
		cout << "��ǰ��ϵ��Ϊ�գ�" << endl;
	}
	else {
		for (int i = 0; i < p->p_size;i++) {
			//cout << "������" << p->personArry[i].name << endl;
			/*if (p->personArry[i].sex == 1) {
				cout << "�Ա���"<< endl;
			}
			else {
				cout << "�Ա�Ů" << endl;
			}*/
			/*cout << "�Ա�" << (p->personArry[i].sex == 1 ? "��" : "Ů") << endl;
			cout << "���䣺" << p->personArry[i].age << endl;
			cout << "�绰��" << p->personArry[i].phone << endl;
			cout << "סַ��" << p->personArry[i].address << endl;*/

			cout << "������" << p->personArry[i].name 
				<< "\t�Ա�" << (p->personArry[i].sex == 1 ? "��" : "Ů") 
				<< "\t���䣺" << p->personArry[i].age 
				<< "\t�绰��" << p->personArry[i].phone
				<< "\tסַ��" << p->personArry[i].address
				<< endl;
		}
	}
	system("pause"); // �밴���������
	system("cls");  // ��������
}

// ����3��4��5������һ�������������ҵĺ���

int isExist(struct addressBook* p,string name) {
	// �����ж�ͨѶ¼���Ƿ�����
	int index = -1;
	if (p->p_size == 0) {
		cout << "��ǰ��ϵ��Ϊ�գ�" << endl;
	}
	else {
		for (int i = 0; i < p->p_size; i++) {
			// C++ string�ַ����ıȽ��Ƿ���� ����ʹ��compare Ҳ����ʹ��"=="
			// a == b ||  a.compare(b) == 0
			if (name.compare(p->personArry[i].name)==0) {
				index = i;
				break;
			}
		}
	}
	return index;
}
// 3. ɾ����ϵ��
void deletePerson(struct addressBook* p) {
	cout << "������ɾ����ϵ�˵�������" << endl;
	string name;
	cin >> name;
	int ans = isExist(p, name);
	//cout << "�ҵ�����ϵ�����洢���±�����" << endl;
	if (ans == -1) {
		cout << "���޴��ˣ���ȷ����ϵ��������" << endl;
	}
	else {
		for (int i = ans; i < p->p_size - 1; i++) {
			p->personArry[i] = p->personArry[i + 1];
		}
		// �����
		// ��Ȼδʵ�ֶ����һ���������ֱ���ÿգ�
		// ��ͨ�� p->p_size--; ����ʵ���߼��ϵ��ÿ�
		//p->personArry[p->p_size - 1] = (struct person)NULL;
		p->p_size--;
		// cout << "�ҵ�����" << endl;
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause"); // �밴���������
	system("cls");  // ��������
	}


// 4. ������ϵ��
void findPerson(struct addressBook* p) {
	cout << "��������ϵ�˵�������" << endl;
	string name;
	cin >> name;
	int ans = isExist(p, name);
	//cout << "�ҵ�����ϵ�����洢���±�����" << endl;
	if (ans == -1) {
		cout << "���޴��ˣ���ȷ����ϵ��������" << endl;
	}
	else {
		cout << "������" << p->personArry[ans].name
			<< "\t�Ա�" << (p->personArry[ans].sex == 1 ? "��" : "Ů")
			<< "\t���䣺" << p->personArry[ans].age
			<< "\t�绰��" << p->personArry[ans].phone
			<< "\tסַ��" << p->personArry[ans].address
			<< endl;
	}
	system("pause"); // �밴���������
	system("cls");  // ��������
}
// 5. �޸���ϵ��
void updatePerson(struct addressBook* p) {
	cout << "��������Ҫ�޸ĵ���ϵ��������" << endl;
	string name;
	cin >> name;
	int ans = isExist(p, name);
	//cout << "�ҵ�����ϵ�����洢���±�����" << endl;
	if (ans == -1) {
		cout << "���޴��ˣ���ȷ����ϵ��������" << endl;
	}
	else {
		char select;
	NAME:
		cout << "�Ƿ���Ҫ�޸�������" << p->personArry[ans].name << "  y/n" << endl;
		cin >> select;
		if (select == 'y') {
			cout << "�����������֣�" << endl;
			string newName;
			cin >> newName;
			p->personArry[ans].name = newName;
		}
		else {
			goto SEX;
		}
	SEX:
		cout << "�Ƿ���Ҫ�޸��Ա�" << (p->personArry[ans].sex == 1 ? "��" : "Ů") << "  y/n" << endl;
		cin >> select;
		if (select == 'y') {
			cout << "���������Ա�" << endl;
			cout << "0 --- Ů��" << endl;
			cout << "1 --- �У�" << endl;
			int newSex;
			cin >> newSex;
			p->personArry[ans].sex = newSex;
		}
		else {
			goto AGE;
		}
	AGE:
		cout << "�Ƿ���Ҫ�޸����䣺" << p->personArry[ans].age << "  y/n" << endl;
		cin >> select;
		if (select == 'y') {
			cout << "�����������䣺" << endl;
			int newAge;
			cin >> newAge;
			p->personArry[ans].age = newAge;
		}
		else {
			goto PHONE;
		}
	PHONE:
		cout << "�Ƿ���Ҫ�޸��ֻ����룺" << p->personArry[ans].phone << "  y/n" << endl;
		cin >> select;
		if (select == 'y') {
			cout << "���������ֻ����룺" << endl;
			string newPhone;
			cin >> newPhone;
			p->personArry[ans].phone = newPhone;
		}
		else {
			goto ADDRESS;
		}
	ADDRESS:
		cout << "�Ƿ���Ҫ�޸ĵ�ַ��" << p->personArry[ans].address << "  y/n" << endl;
		cin >> select;
		if (select == 'y') {
			cout << "�������µ�ַ��" << endl;
			string newAddress;
			cin >> newAddress;
			p->personArry[ans].address = newAddress;
		}
	}
	system("pause"); // �밴���������
	system("cls");  // ��������
}

// 6. �����ϵ��
void clearAllPerson(struct addressBook* p) {
	cout << "�Ƿ�ȷ�����ͨѶ¼��   y/n" << endl;
	char confirm;
	cin >> confirm;
	if (confirm == 'y') {
		// ʵ���߼��ϵ����
		p->p_size = 0;
		cout << "ͨѶ¼����գ�" << endl;
	}
	system("pause"); // �밴���������
	system("cls");  // ��������
}

int main() {
	// ����ͨѶ¼�ṹ
	struct addressBook ab;
	// ��ʼ��ͨѶ¼�е�ǰ��Ա�ĸ���
	ab.p_size = 0;

	// �����û�ѡ������ı���
	int select = 0;

	while (1) {		// �˵�����
		showMenu();

		cin >> select;

		switch (select) {
		case 0: // 0. �˳�ͨ��¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		case 1: // 1. �����ϵ��
			addPerson(&ab);
			break;
		case 2: // 2. ��ʾ��ϵ��
			showPerson(&ab);
			break;
		case 3: // 3. ɾ����ϵ��
			deletePerson(&ab);
			break;
		case 4: // 4. ������ϵ��
			findPerson(&ab);
			break;
		case 5: // 5. �޸���ϵ��
			updatePerson(&ab);
			break;
			break;
		case 6: // 6. �����ϵ��
			clearAllPerson(&ab);
			break;
		default:
			cout << "������������������������" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}