#include<iostream>
#include<string>
using namespace std;
// 宏定义不是说明或语句，在行末不必加分号，如加上分号则连分号也一起置换。
#define MAX 1000
struct person {
	string name; // 姓名
	int sex; // 性别  1为男  0为女
	int age; // 年龄
	string phone; // 手机号码
	string address; // 家庭住址
};
struct addressBook {
	// 通信录中保存的联系人数据
	struct person personArry[MAX];
	// 通信录当前记录联系人个数
	int p_size;
};

// 封装函数显示界面，如void showMenu()
// 在main函数中调用封装好的函数

// 菜单界面
void showMenu() {
	cout << "*************************" << endl;
	cout << "***** 1. 添加联系人 *****" << endl;
	cout << "***** 2. 显示联系人 *****" << endl;
	cout << "***** 3. 删除联系人 *****" << endl;
	cout << "***** 4. 查找联系人 *****" << endl;
	cout << "***** 5. 修改联系人 *****" << endl;
	cout << "***** 6. 清空联系人 *****" << endl;
	cout << "***** 0. 退出通信录 *****" << endl;
	cout << "*************************" << endl;
}
// 1. 添加联系人
void addPerson(struct addressBook * p) {
	// 判断通讯录是否已满，如果满了就不再添加
	if (p->p_size >= MAX) {
		cout << "通讯录已满，暂时无法添加！请开通会员" << endl;
		return;
	}
	else {
		// 添加具体联系人

		// 姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		p->personArry[p->p_size].name = name;
		// 性别
		int sex = 0;
		while (true) {
			cout << "请输入性别: " << endl;
			cout << "0-------女" << endl;
			cout << "1-------男" << endl;
			cin >> sex;
			if (sex == 0 || sex == 1) {
				p->personArry[p->p_size].sex = sex;
				break;
			}
		}
		// 年龄
		int age = 0;
		while (true) {
			cout << "请输入联系人年龄：" << endl;
			cout << "年龄应大于0：" << endl;
			cin >> age;
			if (age > 0) {
				p->personArry[p->p_size].age = age;
				break;
			}
		}
		// 电话
		string phone;
		cout << "请输入手机号码：" << endl;
		cin >> phone;
		p->personArry[p->p_size].phone = phone;
		// 住址
		string address;
		cout << "请输入家庭住址：" << endl;
		cin >> address;
		p->personArry[p->p_size].address = address;
		// 更新通讯录人数
		p->p_size++;

		cout << name << " 添加成功" << endl;

		system("pause"); // 请按任意键继续
		system("cls");  // 清屏操作
	}
}

// 2. 显示联系人
void showPerson(struct addressBook* p) {
	// 首先判断通讯录中是否有人
	if (p->p_size == 0) {
		cout << "当前联系人为空！" << endl;
	}
	else {
		for (int i = 0; i < p->p_size;i++) {
			//cout << "姓名：" << p->personArry[i].name << endl;
			/*if (p->personArry[i].sex == 1) {
				cout << "性别：男"<< endl;
			}
			else {
				cout << "性别：女" << endl;
			}*/
			/*cout << "性别：" << (p->personArry[i].sex == 1 ? "男" : "女") << endl;
			cout << "年龄：" << p->personArry[i].age << endl;
			cout << "电话：" << p->personArry[i].phone << endl;
			cout << "住址：" << p->personArry[i].address << endl;*/

			cout << "姓名：" << p->personArry[i].name 
				<< "\t性别：" << (p->personArry[i].sex == 1 ? "男" : "女") 
				<< "\t年龄：" << p->personArry[i].age 
				<< "\t电话：" << p->personArry[i].phone
				<< "\t住址：" << p->personArry[i].address
				<< endl;
		}
	}
	system("pause"); // 请按任意键继续
	system("cls");  // 清屏操作
}

// 方法3、4、5都基于一个根据姓名查找的函数

int isExist(struct addressBook* p,string name) {
	// 首先判断通讯录中是否有人
	int index = -1;
	if (p->p_size == 0) {
		cout << "当前联系人为空！" << endl;
	}
	else {
		for (int i = 0; i < p->p_size; i++) {
			// C++ string字符串的比较是否相等 可以使用compare 也可以使用"=="
			// a == b ||  a.compare(b) == 0
			if (name.compare(p->personArry[i].name)==0) {
				index = i;
				break;
			}
		}
	}
	return index;
}
// 3. 删除联系人
void deletePerson(struct addressBook* p) {
	cout << "请输入删除联系人的姓名：" << endl;
	string name;
	cin >> name;
	int ans = isExist(p, name);
	//cout << "找到的联系人所存储的下标索引" << endl;
	if (ans == -1) {
		cout << "查无此人，请确认联系人姓名！" << endl;
	}
	else {
		for (int i = ans; i < p->p_size - 1; i++) {
			p->personArry[i] = p->personArry[i + 1];
		}
		// 待解决
		// 虽然未实现对最后一个数组进行直接置空，
		// 但通过 p->p_size--; 可以实现逻辑上的置空
		//p->personArry[p->p_size - 1] = (struct person)NULL;
		p->p_size--;
		// cout << "找到此人" << endl;
		cout << "删除成功" << endl;
	}
	system("pause"); // 请按任意键继续
	system("cls");  // 清屏操作
	}


// 4. 查找联系人
void findPerson(struct addressBook* p) {
	cout << "请输入联系人的姓名：" << endl;
	string name;
	cin >> name;
	int ans = isExist(p, name);
	//cout << "找到的联系人所存储的下标索引" << endl;
	if (ans == -1) {
		cout << "查无此人，请确认联系人姓名！" << endl;
	}
	else {
		cout << "姓名：" << p->personArry[ans].name
			<< "\t性别：" << (p->personArry[ans].sex == 1 ? "男" : "女")
			<< "\t年龄：" << p->personArry[ans].age
			<< "\t电话：" << p->personArry[ans].phone
			<< "\t住址：" << p->personArry[ans].address
			<< endl;
	}
	system("pause"); // 请按任意键继续
	system("cls");  // 清屏操作
}
// 5. 修改联系人
void updatePerson(struct addressBook* p) {
	cout << "请输入需要修改的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ans = isExist(p, name);
	//cout << "找到的联系人所存储的下标索引" << endl;
	if (ans == -1) {
		cout << "查无此人，请确认联系人姓名！" << endl;
	}
	else {
		char select;
	NAME:
		cout << "是否需要修改姓名：" << p->personArry[ans].name << "  y/n" << endl;
		cin >> select;
		if (select == 'y') {
			cout << "请输入新名字：" << endl;
			string newName;
			cin >> newName;
			p->personArry[ans].name = newName;
		}
		else {
			goto SEX;
		}
	SEX:
		cout << "是否需要修改性别：" << (p->personArry[ans].sex == 1 ? "男" : "女") << "  y/n" << endl;
		cin >> select;
		if (select == 'y') {
			cout << "请输入新性别：" << endl;
			cout << "0 --- 女：" << endl;
			cout << "1 --- 男：" << endl;
			int newSex;
			cin >> newSex;
			p->personArry[ans].sex = newSex;
		}
		else {
			goto AGE;
		}
	AGE:
		cout << "是否需要修改年龄：" << p->personArry[ans].age << "  y/n" << endl;
		cin >> select;
		if (select == 'y') {
			cout << "请输入新年龄：" << endl;
			int newAge;
			cin >> newAge;
			p->personArry[ans].age = newAge;
		}
		else {
			goto PHONE;
		}
	PHONE:
		cout << "是否需要修改手机号码：" << p->personArry[ans].phone << "  y/n" << endl;
		cin >> select;
		if (select == 'y') {
			cout << "请输入新手机号码：" << endl;
			string newPhone;
			cin >> newPhone;
			p->personArry[ans].phone = newPhone;
		}
		else {
			goto ADDRESS;
		}
	ADDRESS:
		cout << "是否需要修改地址：" << p->personArry[ans].address << "  y/n" << endl;
		cin >> select;
		if (select == 'y') {
			cout << "请输入新地址：" << endl;
			string newAddress;
			cin >> newAddress;
			p->personArry[ans].address = newAddress;
		}
	}
	system("pause"); // 请按任意键继续
	system("cls");  // 清屏操作
}

// 6. 清空联系人
void clearAllPerson(struct addressBook* p) {
	cout << "是否确认清空通讯录！   y/n" << endl;
	char confirm;
	cin >> confirm;
	if (confirm == 'y') {
		// 实现逻辑上的清空
		p->p_size = 0;
		cout << "通讯录已清空！" << endl;
	}
	system("pause"); // 请按任意键继续
	system("cls");  // 清屏操作
}

int main() {
	// 创建通讯录结构
	struct addressBook ab;
	// 初始化通讯录中当前人员的个数
	ab.p_size = 0;

	// 创建用户选择输入的变量
	int select = 0;

	while (1) {		// 菜单调用
		showMenu();

		cin >> select;

		switch (select) {
		case 0: // 0. 退出通信录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		case 1: // 1. 添加联系人
			addPerson(&ab);
			break;
		case 2: // 2. 显示联系人
			showPerson(&ab);
			break;
		case 3: // 3. 删除联系人
			deletePerson(&ab);
			break;
		case 4: // 4. 查找联系人
			findPerson(&ab);
			break;
		case 5: // 5. 修改联系人
			updatePerson(&ab);
			break;
			break;
		case 6: // 6. 清空联系人
			clearAllPerson(&ab);
			break;
		default:
			cout << "您输入的命令错误，请重新输入" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}