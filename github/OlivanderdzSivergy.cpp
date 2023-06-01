#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

string UnderScore(40, '_');

class BranchFinances
{
private:
	const double CostPerMonth = 50;
	const double FixProfitPercent = 0.07;
	const double FixProfit = 270;
	const double Salary = 45;
	const double AurorPayment = 15;
public:
	BranchFinances() {}

	double GrossProfit()
	{
		srand(time(nullptr));
		return rand() % 251 + 250;
	}

	double MonthRent()
	{
		if (GrossProfit() > FixProfit)
			return CostPerMonth + (GrossProfit() - FixProfit) * FixProfitPercent;
		else return CostPerMonth;
	}

	double TotalExpenses()
	{
		return Salary + MonthRent() + AurorPayment;
	}

	void ShowMeMyExpences()
	{
		cout << endl << UnderScore << endl <<
			"Ежемесячные расходы:" << endl
			<< "Зарплаты: " << Salary << "*" << endl
			<< "Рента помещения: " << MonthRent() << endl
			<< "Охрана Мракоборцами: " << AurorPayment
			<< endl << UnderScore << endl <<
			"Общие ежемесячные расходы филиала: " << TotalExpenses()
			<< endl << UnderScore << "\n\n" << "Прибыль чистая: ";
	}

	double NetProfit()
	{
		return GrossProfit() - TotalExpenses();
	}

	~BranchFinances() {}

};

class NewBranch :public BranchFinances
{
private:
	string BranchName;
public:
	NewBranch(string Name)
	{
		BranchName = Name;
		cout << "Добро пожаловать в " << BranchName << " филиал Оливандера!"
			<< endl << UnderScore << "\n\n";
	}
	~NewBranch()
	{
		cout << endl << "Приятного дня!";
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите название вашей лавки!";
	string MyBranchName;
	cin >> MyBranchName;

	NewBranch MyBranch(MyBranchName);

	cout << "Прибыль: " << MyBranch.GrossProfit();
	MyBranch.TotalExpenses();
	MyBranch.ShowMeMyExpences();
	cout << MyBranch.NetProfit();
}
