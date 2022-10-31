#include<iostream>
using namespace std;
#include<string>
class Parent 
{
	static int id;
	int own_id;
	string name;//private - частная переменная
	int money;
	static int take_id()
	{
		id++;
		return id;

	}
	friend Parent operator+(const Parent& p1, const Parent& p2)
	{
		Parent p3(p1.name + " + " + p2.name, p1.money + p2.money);
		return p3;
	}
public:
	friend void rename(Parent&, string);
	friend void operator+=(Parent& obj,int number)
	{
		obj.money += number;
	}

	
	Parent(string _name, int _money)
	{
		name = _name;
		own_id = take_id();
		money = _money;
	}
	Parent() 
	{
		name = "Ivan";
		own_id = take_id();
		money = 0;
	}

	void print()
	{
		cout <<"Your ID is " << own_id 
			<<", your name is " << name <<". You have "<< money << " rubles"<< "\n";
	}

};
int Parent::id = 0;

class Child
{
	int id;
	string name;
	int class_number;
	int school_number;
public:
	Child(int _id, string _name, int _class_name, int _school_number)
	{
		id = _id;
		name = _name;
		class_number = _class_name;
		school_number = _school_number;
	}

	friend void rename(Child&, string);
	void print()
	{
		cout << "My name is " << name << ". I study in school number " << school_number << "\n";
	
	}
};
class Fraction
{
	friend class FriendlyFraction;
	int chisl;
	int znam;

	friend Fraction operator+(const Fraction& obj1, const Fraction& obj2)
	{
		/*
		Fracrtion d1;
		d1.chisl = obj1.chisl * obj2.znam + obj2.chisl * obj1.znam;
		d1.znam = obj1.znam * obj2.znam;
		return d1;
		*/
		return Fraction(obj1.chisl * obj2.znam + obj2.chisl * obj1.znam, obj1.znam * obj2.znam);
	}

public:
	Fraction()
	{
		chisl = 1;
		znam = 1;
	}

	Fraction(int a, int b)
	{
		/*int i;
		a > b ? i = a : i = b;

		while (i>1)

		{
			if (a%i == 0 && b % i == 0)
			{
				a /= i;
				b /= i;
			}
			i--;
		}
		*/
		chisl = a;
		znam = b;
	}

	void print() {
		cout << "Drob " << chisl << " / " << znam << "\n";
	}

};
class FriendlyFraction
{
public:
	static void simple(Fraction& obj1)
	{
		int i;
		obj1.chisl > obj1.znam ? i = obj1.chisl : i = obj1.znam;

		while (i > 1)

		{
			if (obj1.chisl % i == 0 && obj1.znam % i == 0)
			{
				obj1.chisl /= i;
				obj1.znam /= i;
			}
			i--;
		}
	}
};

int main()
{
	/*Parent one("Igor", 100);
	Parent two("Alex", 50);
	Parent three;
	one.print();
	two.print();
	rename(two, "Sasha");
	two.print();
	Child student(1,"Nick", 10, 56);
	three.print();
	student.print();
	rename(student, "Misha");
	student.print();
	Parent four = one + two;
	four.print();
	four += 50;
	four.print();
	*/
	Fraction fr1(1, 2);
	Fraction fr2(1, 4);
	Fraction fr3 = fr1 + fr2;
	FriendlyFraction::simple(fr3);
	fr3.print();
	return 0;
}
void rename(Parent & obj, string new_name)
{
	obj.name = new_name;

}
void rename(Child& obj, string new_name)
{
	obj.name = new_name;
	obj.school_number = 10;

}