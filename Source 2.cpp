#include <iostream>

struct telephoneNum
{
	std::string name = "no name";
	int telNum = 0000;
	int adress = 0000;

	void setValues(std::string name, int telNum, int adress)
	{
		this->name = name;
		this->telNum = telNum;
		this->adress = adress;
	}
};

struct telephoneList
{
	int size = 2;
	telephoneNum* tephs;

	telephoneList(std::string name, int telNum, int adress, std::string name1, int telNum1, int adress1)
	{
		tephs = new telephoneNum[size];
		tephs[0].setValues(name, telNum, adress);
		tephs[1].setValues(name1, telNum1, adress1);

	}

	void addContact(std::string name, int telNum, int adress)
	{
		telephoneNum* newTephs = new telephoneNum[this->size + 1];

		for (int i = 0; i < size; i++)
		{
			newTephs[i].name = tephs[i].name;
			newTephs[i].adress = tephs[i].adress;
			newTephs[i].telNum = tephs[i].telNum;
		}

		newTephs[this->size].name = name;
		newTephs[this->size].adress = adress;
		newTephs[this->size].telNum = telNum;

		if (tephs != nullptr)
		{
			delete tephs;
		}

		tephs = newTephs;
		this->size++;
		newTephs = nullptr;
	}

	void deleteContact(std::string name)
	{
		telephoneNum* newTephs = new telephoneNum[this->size - 1];

		for (int i = 0, j = 0; i < size; i++)
		{
			if (tephs[i].name == name)
			{
				continue;
			}
			newTephs[j].name = tephs[i].name;
			newTephs[j].adress = tephs[i].adress;
			newTephs[j].telNum = tephs[i].telNum;
			j++;
		}


		if (tephs != nullptr)
		{
			delete tephs;
		}

		tephs = newTephs;
		this->size--;
		newTephs = nullptr;
	}

	void searchContact(std::string name)
	{

		for (int i = 0; i < size; i++)
		{
			if (tephs[i].name == name)
			{
				std::cout << "name - " << tephs[i].name << "\nadress - " << tephs[i].adress << "\ntelephone number - " << tephs[i].telNum << "\n";
				break;
			}
		}
	}

	void print()
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << "name - " << tephs[i].name << "\nadress - " << tephs[i].adress << "\ntelephone number - " << tephs[i].telNum << "\n";
		}
	}

};
int main()
{
	telephoneList t1("grog", 5981, 03625, "reg", 6874, 0274);

	t1.addContact("joestar", 985, 9631);
	t1.print();

}