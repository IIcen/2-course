#include <iostream>
#include <string>

const int days = 50;

struct joke
{
	std::string type;
	bool AliceReaction;
	bool BobReaction;
	std::string description;

};

void Records(joke records[], int d)
{
	for (int i = 0; i < d; i += 3 & 5)
	{
		std::cout << "Day: " << i + 1 << std::endl;
		std::cout << "Enter type of joke (programming, student, universal): ";
		std::cin >> records[i].type;
		std::cout << "Enter Alices reaction (1 - laugh, 0 - no): ";
		std::cin >> records[i].AliceReaction;
		std::cout << "Enter Bobs reaction (1 - laugh, 0 - no): ";
		std::cin >> records[i].BobReaction;
		std::cout << "Enter description of joke: ";
		std::cin >> records[i].description;
	}
}

void Results(joke records[], int d)
{
	int AliceSmileProg = 0;
	int AliceSmileStud = 0;
	int AliceSmileUniv = 0;
	int BobSmileProg = 0;
	int BobSmileStud = 0;
	int BobSmileUniv = 0;

	for (int i = 0; i < d; i += 3 & 5)
	{
		if (records[i].type == "programming")
		{
			if (records[i].AliceReaction)
			{
				AliceSmileProg++;
			}
			if (records[i].BobReaction)
			{
				BobSmileProg++;
			}
		}
		else if (records[i].type == "student")
		{
			if (records[i].AliceReaction)
			{
				AliceSmileStud++;
			}
			if (records[i].BobReaction)
			{
				BobSmileStud++;
			}
		}
		else if (records[i].type == "universal")
		{
			if (records[i].AliceReaction)
			{
				AliceSmileUniv++;
			}
			if (records[i].BobReaction)
			{
				BobSmileUniv++;
			}
		}
	}

	std::cout << "Results: " << std::endl;
	std::cout << "Programming jokes: " << std::endl;
	std::cout << "Alice laughed: " << AliceSmileProg << std::endl;
	std::cout << "Bob laughed: " << BobSmileProg << std::endl;
	std::cout << "Student jokes: " << std::endl;
	std::cout << "Alice laughed: " << AliceSmileStud << std::endl;
	std::cout << "Bob laughed: " << BobSmileStud << std::endl;
	std::cout << "Universal jokes: " << std::endl;
	std::cout << "Alice laughed: " << AliceSmileUniv << std::endl;
	std::cout << "Bob laughed: " << BobSmileUniv << std::endl;
}

int main()
{
	joke records[days];

	Records(records, days);
	Results(records, days);

}