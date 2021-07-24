//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Обектно-ориентирано програмиране 2020/21
// Практически изпит
//
// Име: Соня Николова Николова
// ФН: 82213
// Специалност: Компютърни науки
// Курс: 1
// Административна група: 4
// Ден, в който се явявате на изпита:  07.07.2021г.
// Начален час на изпита: 8:00
// Кой компилатор използвате: GCC
//

#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

class Property
{
private:
	std::string m_label;
	int m_quantity;
	double m_multiplier;

public:
	Property(const std::string &label, const int quantity, const double multiplier)
	{
		this->m_label = label;
		this->m_quantity = quantity;
		this->m_multiplier = multiplier;
	}

	std::string getLabel() const
	{
		return this->m_label;
	}
	int getQuantity() const
	{
		return this->m_quantity;
	}
	double getMultiplier() const
	{
		return this->m_multiplier;
	}
};

class Component
{
protected:
	std::vector<Property *> properties;
	std::string m_name;

public:
	int getQuantityByName(const std::string &name)
	{
		int result = 0;
		std::size_t size = this->properties.size();

		for (std::size_t i = 0; i < size; i++)
		{
			if (name == this->properties[i]->getLabel())
			{
				result = this->properties[i]->getQuantity();
				return result;
			}
		}
		std::cout << "No match for the name of the property \n";

		return result;
	}

	double price() const
	{
		double result = 0;
		std::size_t size = this->properties.size();
		if (size)
		{
			for (std::size_t i = 0; i < size; i++)
			{
				result += this->properties[i]->getMultiplier() * this->properties[i]->getQuantity();
			}
		}

		return result;
	}
	std::string getName() const
	{
		return this->m_name;
	}
};

class CPU : public Component
{
public:
	CPU(const std::string &compName,
		const std::string nameCore, const int cores, const double priceCore,
		const std::string &nameClockS, const int clockSpeed, const double priceClock)
	{

		Property *core = nullptr;
		try
		{
			core = new Property(nameCore, cores, priceCore);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Bad allocation of cores" << '\n';
		}
		if (core)
		{
			this->properties.push_back(core);
		}

		Property *clockS = nullptr;
		try
		{
			clockS = new Property(nameClockS, clockSpeed, priceClock);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Bad allocation of clock speed" << '\n';
		}
		if (clockS)
		{
			this->properties.push_back(clockS);
		}

		if (core && clockS)
		{
			this->m_name = compName;
		}
	}
};

class RAM : public Component
{

public:
	RAM(const std::string &compName,
		const std::string &nameGB, const int GB, const double priceGB,
		const std::string &nameChip, const int chips, const double priceChip,
		const std::string &nameColors, const int colors, const double priceColor)
	{
		Property *gigaBytes = nullptr;
		try
		{
			gigaBytes = new Property(nameGB, GB, priceGB);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Bad GB allocation" << '\n';
		}

		if (gigaBytes)
		{
			this->properties.push_back(gigaBytes);
		}

		Property *chip = nullptr;
		try
		{
			chip = new Property(nameChip, chips, priceChip);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Bad chip allocation" << '\n';
		}

		if (chip)
		{
			this->properties.push_back(chip);
		}

		Property *color = nullptr;
		try
		{
			color = new Property(nameColors, colors, priceColor);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Bad color allocation" << '\n';
		}

		if (color)
		{
			this->properties.push_back(color);
		}

		if (gigaBytes && chip && color)

		{
			this->m_name = compName;
		}
	}
};

class HDD : public Component
{
public:
	HDD(const std::string &compName,
		const std::string &nameTB, const int TB, const double priceTB,
		const std::string &nameRead, const int readSpeed, const double priceRead,
		const std::string &nameWrite, const int writeSpeed, const double priceWrite)
	{
		Property *teraBytes = nullptr;
		try
		{
			teraBytes = new Property(nameTB, TB, priceTB);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Bad TB allocation" << '\n';
		}

		if (teraBytes)
		{
			this->properties.push_back(teraBytes);
		}

		Property *read = nullptr;
		try
		{
			read = new Property(nameRead, readSpeed, priceRead);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Bad reading speed allocation" << '\n';
		}

		if (read)
		{
			this->properties.push_back(read);
		}

		Property *write = nullptr;
		try
		{
			write = new Property(nameWrite, writeSpeed, priceWrite);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Bad writing speed allocation" << '\n';
		}

		if (write)
		{
			this->properties.push_back(write);
		}

		if (teraBytes && read && write)
		{
			this->m_name = compName;
		}
	}
};

class Utils
{
protected:
	std::vector<Component *> components;

public:
	std ::size_t size() const
	{
		return this->components.size();
	}

	Component *operator[](std::size_t index) const
	{
		std::size_t size = this->size();
		if (index > size || !index)
		{
			throw std::out_of_range("Invalid index");
		}
		return this->components[index];
	}

	virtual void addComponent()
	{
		std::size_t size = this->size();

		char choice;

		std::cout << "What type of component do you want to add? (c-cpu, h-hdd, r -ram, ! - menu) \n";
		std::cin >> choice;
		std::cin.ignore();

		std::string nameCore, nameCS, nameGB, nameChip, nameColors, nameTB, nameRead, nameWrite, compName1, compName2, compName3;
		int cores, clock, gb, chip, colors, tb, read, write;
		double pCores, pClock, pGb, pChip, pColors, pTb, pRead, pWrite;

		CPU *cpu = nullptr;
		HDD *hdd = nullptr;
		RAM *ram = nullptr;

		switch (choice)
		{
		case 'c':
			std::cout << "Please enter in the following order name of the component, name of core, number of cores, price per core, name of clock speed, clock speed and price per clock speed: \n ";
			std::cin >> compName1 >> nameCore >> cores >> pCores >> nameCS >> clock >> pClock;

			try
			{
				cpu = new CPU(compName1, nameCore, cores, pCores, nameCS, clock, pClock);
			}
			catch (const std::exception &e)
			{
				std::cerr << "Couldn't allocate cpu for config" << '\n';
			}

			if (cpu)
			{
				if (!size)
				{
					this->components.push_back(cpu);
				}

				else
				{
					for (std::size_t i = 0; i < size; i++)
					{
						if (typeid(this->components[i]) == typeid(cpu))
						{
							std::cout << "Component of this type already exists in the configuration \n";
							delete cpu;
						}
					}
					this->components.push_back(cpu);
				}
			}
			break;

		case 'h':
			std::cout << "Please enter in the following order name of component, name of terabytes, number of TB, price per TB, name of writing speed, writing speed, price per writing speed, name of reading speed, reading speed, price per reading speed: \n ";
			std::cin >> compName2 >> nameTB >> tb >> pTb >> nameWrite >> write >> pWrite >> nameRead >> read >> pRead;

			try
			{
				hdd = new HDD(compName2, nameTB, tb, pTb, nameRead, read, pRead, nameWrite, write, pWrite);
			}
			catch (const std::exception &e)
			{
				std::cerr << "Coudln't allocate hdd for config" << '\n';
			}

			if (hdd)
			{
				if (!size)
				{
					this->components.push_back(hdd);
				}
				else
				{
					for (std::size_t i = 0; i < size; i++)
					{
						if (typeid(this->components[i]) == typeid(hdd))
						{
							std::cout << "Component of this type already exists in the configuration \n";
							delete hdd;
						}
					}
					this->components.push_back(hdd);
				}
			}

		case 'r':
			std::cout << "Please enter in the following order name of component, name of gigabytes, number of GB, price per GB, name of chip, number of chips, price per chip, name of color scheme, number of colors, price per color: \n ";
			std::cin >> compName3 >> nameGB >> gb >> pGb >> nameChip >> chip >> pChip >> nameColors >> colors >> pColors;

			try
			{
				ram = new RAM(compName3, nameGB, gb, pGb, nameChip, chip, pChip, nameColors, colors, pColors);
			}
			catch (const std::exception &e)
			{
				std::cerr << "Couldn't allocate ram for the config" << '\n';
			}
			if (ram)
			{
				if (!size)
				{
					this->components.push_back(ram);
				}
				else
				{
					for (std::size_t i = 0; i < size; i++)
					{
						if (typeid(this->components[i]) == typeid(ram))
						{
							std::cout << "Component of this type already exists in the configuration \n";
							delete ram;
						}
					}
					this->components.push_back(ram);
				}
			}

		case '!':
			std::cout << "c - enter CPU \n";
			std::cout << "h - enter HDD \n";
			std::cout << "r - enter RAM \n";
			std::cout << "! - show menu 'n";
			break;

		default:
			std::cout << "Invalid command \n";
			break;
		}
	}
};

class Requirement : public Utils
{
public:
	Requirement() = default;
};
class Configuration : public Utils
{

public:
	static constexpr double OVER_PRICE = 0.07;

	Configuration() = default;
	double price() const
	{
		std::size_t size = this->size();
		double result = 0;

		for (std::size_t i = 0; i < size; i++)
		{
			result += this->components[i]->price();
		}
		result += result * OVER_PRICE;

		return result;
	}

	bool isConfigurationValid(const Requirement &requirement) const
	{
		std::size_t sizeConfig = this->size();
	std:;
		size_t sizeReq = this->size();

		if (sizeReq <= sizeConfig)
		{
			for (std::size_t i = 0; i < sizeReq; i++)
			{
				for (std::size_t j = 0; j < sizeConfig; j++)
				{
					//if (typeid(requirement.components[i]) != typeid(this->components[i]))
				}
			}
		}
		return true;
	}
};

class Store : public Utils //uses the Utils::size()  and Utils:: operator[]
						   //can't use the Utils::addComponent() because we can have multiple components of the same type in the store
{
protected:
	std::vector<Component *> components;

public:
	Store() = default;
	virtual void addComponent() override
	{
		std::size_t size = this->size();

		char choice;

		std::cout << "What type of component do you want to add? (c-cpu, h-hdd, r -ram, ! - menu) \n";
		std::cin >> choice;
		std::cin.ignore();

		std::string nameCore, nameCS, nameGB, nameChip, nameColors, nameTB, nameRead, nameWrite, compName1, compName2, compName3;
		int cores, clock, gb, chip, colors, tb, read, write;
		double pCores, pClock, pGb, pChip, pColors, pTb, pRead, pWrite;

		CPU *cpu = nullptr;
		HDD *hdd = nullptr;
		RAM *ram = nullptr;

		switch (choice)
		{
		case 'c':
			std::cout << "Please enter in the following order name of the component, name of core, number of cores, price per core, name of clock speed, clock speed and price per clock speed: \n ";
			std::cin >> compName1 >> nameCore >> cores >> pCores >> nameCS >> clock >> pClock;

			try
			{
				cpu = new CPU(compName1, nameCore, cores, pCores, nameCS, clock, pClock);
			}
			catch (const std::exception &e)
			{
				std::cerr << "Couldn't allocate cpu for config" << '\n';
			}

			if (cpu)
			{
				this->components.push_back(cpu);
			}

			break;

		case 'h':
			std::cout << "Please enter in the following order name of component, name of terabytes, number of TB, price per TB, name of writing speed, writing speed, price per writing speed, name of reading speed, reading speed, price per reading speed: \n ";
			std::cin >> compName2 >> nameTB >> tb >> pTb >> nameWrite >> write >> pWrite >> nameRead >> read >> pRead;

			try
			{
				hdd = new HDD(compName2, nameTB, tb, pTb, nameRead, read, pRead, nameWrite, write, pWrite);
			}
			catch (const std::exception &e)
			{
				std::cerr << "Coudln't allocate hdd for config" << '\n';
			}

			if (hdd)
			{
				this->components.push_back(hdd);
			}

		case 'r':
			std::cout << "Please enter in the following order name of component, name of gigabytes, number of GB, price per GB, name of chip, number of chips, price per chip, name of color scheme, number of colors, price per color: \n ";
			std::cin >> compName3 >> nameGB >> gb >> pGb >> nameChip >> chip >> pChip >> nameColors >> colors >> pColors;

			try
			{
				ram = new RAM(compName3, nameGB, gb, pGb, nameChip, chip, pChip, nameColors, colors, pColors);
			}
			catch (const std::exception &e)
			{
				std::cerr << "Couldn't allocate ram for the config" << '\n';
			}
			if (ram)
			{
				this->components.push_back(ram);
			}

		case '!':
			std::cout
				<< "c - enter CPU \n";
			std::cout << "h - enter HDD \n";
			std::cout << "r - enter RAM \n";
			std::cout << "! - show menu 'n";
			break;

		default:
			std::cout << "Invalid command \n";
			break;
		}
	}
	void removeComponent(const Component *component)
	{
		std::string name = component->getName();
		std::size_t size = this->size();

		for (std::size_t i = 0; i < size; i++)
		{
			if (name == this->components[i]->getName())
			{
				this->components.erase(this->components.begin() + i);
			}
		}
	}
};

class Configurator : public Store
{
public:
	Configuration *createConfig(const Requirement &Requirement);
};

int main()
{
	// CPU test("first", "core", 4, 4, "nvidia", 2, 5);
	// std::cout << test.price() << std::endl;
	// std::cout << test.getQuantityByName("core") << std::endl;
	// RAM test2("second", "giga", 4, 2, "intel", 2, 4, "rgb", 4, 3);
	// std::cout << test2.price() << std::endl;
	// std::cout << test2.getQuantityByName("rgb") << std::endl;
	// Configuration config;
	// std::cout << config.size();
	// config.addComponent();
	// std::cout << config.size();

	return 0;
}