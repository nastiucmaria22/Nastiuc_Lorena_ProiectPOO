#include<iostream>
using namespace std;
class SalariuInvatamant
{
public:
	string PozitieAngajat;
	int OreLucrate;
	float valoare;
	static float SalariuMinim;
	float* adaosGrad;
	const int CodCOR;

	SalariuInvatamant() :CodCOR(23)
	{
		this->PozitieAngajat = "  Tip profesor ";
		this->OreLucrate = 0;
		this->valoare = 0;
		this->adaosGrad = NULL;

	}
	SalariuInvatamant(int CodCORNou, string PozitieAngajat) :CodCOR(CodCORNou)
	{
		this->PozitieAngajat = PozitieAngajat;
		this->OreLucrate = 0;
		this->adaosGrad = NULL;

	}
	SalariuInvatamant(int CodCOR, string PozitieAngajat, int OreLucrate, float valoare, int* adaosGrad) :CodCOR(CodCOR), PozitieAngajat(PozitieAngajat), OreLucrate(OreLucrate), valoare(valoare)
	{
		if (OreLucrate != NULL)
		{
			this->adaosGrad = new int[OreLucrate];
			for (int i = 0;i < OreLucrate;i++)
			{
				this->adaosGrad[i] = adaosGrad[i];
			}

		}
		else
			this->adaosGrad = NULL;
	}
	~SalariuInvatamant()
	{
		if (this->adaosGrad != NULL)
		{
			delete[]this->adaosGrad;
		}
	}
	void afisare()
	{
		cout << " Codul COR este: " << CodCOR << endl;
		cout << " Tip cadru: " << PozitieAngajat << endl;
		cout << " Numar de ore lucrate: " << OreLucrate << endl;
		cout << " Salariul: " << valoare;
		if (adaosGrad != NULL)
		{
			for (int i = 0;i < OreLucrate;i++)
				cout << adaosGrad[i] << " ";
		}
		else
		{
			cout << " - " << endl;
		}
		cout << "Salariul minim este:" << SalariuMinim;
		cout << endl;

	}
	static void setSalariuMinim(float SalariuMinimNou)
	{
		SalariuMinim = SalariuMinimNou;
	}
};
float SalariuInvatamant::SalariuMinim = 3000;
void main()
{
	int* adaos;
	adaos = new int[2];
	adaos[0] = 500;
	adaos[1] = 1000;
	SalariuInvatamant Sal1;
	SalariuInvatamant::setSalariuMinim(2.800);
	Sal1.afisare();//apelez primul constructor
	SalariuInvatamant Sal2(2310, " Profesor univeristar ");
	Sal2.afisare();
	SalariuInvatamant Sal3(2341, " Profesor invatamant primar ", 40, 4600, *adaos);
	SalariuInvatamant::setSalariuMinim(2.300);
	Sal3.afisare();

}