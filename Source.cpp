#include<iostream>
using namespace std;
class Angajat
{
public:
	const int id;
	string nume;
	string Profesie;
	int vechime;
	int* salariu;
	int an;
	static int SporDeRisc;
	Angajat() :id(1)
	{
		this->nume = " Angajat";
		this->vechime = 0;
		this->salariu = NULL;
		this->Profesie = " Profesie ";
		this->an = 0;
	}
	Angajat(int idNou, string nume, string Profesie) : id(idNou)
	{
		this->nume = nume;
		this->vechime = 0;
		this->salariu = NULL;
		this->Profesie = Profesie;
		this->an = 0;

	}
	Angajat(int id, string nume, string Profesie, int vechime, int* salariu, int an) :id(id), nume(nume), Profesie(Profesie), vechime(vechime), an(an)
	{
		if (vechime != 0)
		{
			this->salariu = new int[vechime];
			for (int i = 0;i < vechime;i++)
			{
				this->salariu[i] = salariu[i];

			}
		}
		else this->salariu = NULL;
	}
	~Angajat()
	{
		if (this->salariu != NULL)
		{
			delete[]this->salariu;
		}
	}
	void afisare()
	{
		cout << id << "." << " Angajatul: " << nume << endl;
		cout << "      Profesia:" << Profesie << endl;
		cout << "      Vechime:  " << vechime << " ani." << endl;
		cout << "      Pe fiecare an a avut salariul de: " << endl;
		if (vechime != NULL)
		{
			for (int i = 0;i < vechime;i++)
			{
				cout << "     An: " << an << "  /   " << salariu[i] << "lei" << endl << " ";
			}
		}
		else
		{
			cout << " - ";
		}
		cout << "Sporul de risc este: " << SporDeRisc << endl;

	}
	static void setSporDeRisc(int SpoDeRiscNou)
	{
		SporDeRisc = SpoDeRiscNou;
	}
};
int Angajat::SporDeRisc = 2;

class Firma
{
public:
	const int CodCaen;//atribut constant
	string nume;
	float* CifraDeAfaceri;
	int nrAngajati;
	int vechime;
	int an;
	static float PlatitoareTVA;//atribut static
	Firma() :CodCaen(2573)
	{
		this->nume = " Firma ";
		this->CifraDeAfaceri = NULL;
		this->nrAngajati = 0;
		this->vechime = 0;
		this->an = 0;
	}
	Firma(int CodCaenNou, string nume) :CodCaen(CodCaenNou)
	{
		this->nume = nume;
		//this->nrAngajati = 0;
		this->CifraDeAfaceri = NULL;
		//this->vechime=0
	}
	Firma(int CodCaen, string nume, int nrAngajati, int vechime, float* CifraDeAfaceri, int an) :CodCaen(CodCaen), nume(nume), nrAngajati(nrAngajati), vechime(vechime), an(an)
	{
		if (vechime != 0)
		{
			this->CifraDeAfaceri = new float[vechime];
			for (int i = 0;i < vechime;i++)
			{
				this->CifraDeAfaceri[i] = CifraDeAfaceri[i];
			}

		}
		else
			this->CifraDeAfaceri = NULL;

	}
	~Firma()
	{
		if (this->CifraDeAfaceri != NULL)
		{
			delete[]this->CifraDeAfaceri;
		}
	}
	void afisare()
	{
		cout << endl;
		cout << " Nume firma: " << nume << endl;
		cout << " Cod CAEN: " << CodCaen << endl;
		cout << " Numar de angajati:  " << nrAngajati << endl;
		cout << " Vechimea firmei: " << vechime << endl;
		if (vechime != NULL)
		{
			cout << " Cifra de afaceri (mii euro) pentru fiecare an este:" << endl;
			for (int i = 0;i < vechime;i++)
			{

				cout << " An: " << an << "/" << CifraDeAfaceri[i] << " " << endl;

			}
		}
		else
		{
			cout << " Firma nu are rulaj" << endl;
		}
		cout << "TVA-ul platit de firma este: " << PlatitoareTVA;

	}


	static void setPlatitoareTVA(float TVANou)
	{
		PlatitoareTVA = TVANou;
	}
};
float Firma::PlatitoareTVA = 0.19;
class SalariuInvatamant
{
public:
	string PozitieAngajat;
	float OreLucrate;
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
	SalariuInvatamant(int CodCOR, string PozitieAngajat, float OreLucrate, float valoare, int* adaosGrad) :CodCOR(CodCOR), PozitieAngajat(PozitieAngajat), OreLucrate(OreLucrate), valoare(valoare)
	{
		if (OreLucrate != NULL)
		{
			this->adaosGrad = new float[OreLucrate];
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
			{
				this->adaosGrad[i] = adaosGrad[i];

				cout << endl << "Adaos[" << i + 1 << "]=" << adaosGrad[i] << endl;
			}
		}
		else
		{
			cout << " - " << endl;
		}
		cout << "Salariul minim este:" << SalariuMinim << endl;
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
	int* salariu;
	salariu = new int[3];
	salariu[0] = 1000;
	salariu[1] = 1500;
	salariu[2] = 2000;
	int* salariu2 = new int[4];
	salariu2[0] = 4000;
	salariu2[1] = 4600;
	salariu2[2] = 4900;
	salariu2[3] = 5005;
	int* An;
	An = new int[3];
	An[0] = 2021;
	An[1] = 2022;
	An[2] = 2023;
	An[3] = 2024;

	cout << endl << "Clasa angajat" << endl;
	Angajat ang1;
	ang1.afisare();
	cout << endl;
	Angajat ang2(7, " Ionescu Andreea", " profesoara");
	ang2.afisare();
	//Angajat ang3(101, "Georgescu Ioana", "asistent", 3, *salariu);
	//Angajat::setSporDeRisc(4);
	//ang3.afisare();
	Angajat ang3(102, " Popescu Alin ", " inginer ", 4, salariu2, *An);
	Angajat::setSporDeRisc(5);
	ang3.afisare();
	cout << endl;


	cout << endl << "Clasa Firma" << endl;
	int* an;
	an = new int[3];
	an[0] = 2016;
	an[1] = 2017;
	an[3] = 2018;
	float* Cifra;
	Cifra = new float[3];
	Cifra[0] = 166.9;
	Cifra[1] = 998.99;
	Cifra[2] = 5678.9;
	Firma firma1;
	firma1.afisare();
	Firma::setPlatitoareTVA(0.20);
	cout << endl;
	Firma firma2(6972, "SC.RAMYCONT.SRL");
	Firma::setPlatitoareTVA(0.21);
	firma2.afisare();
	cout << endl;

	cout << endl;
	Firma firma3(7765, "SC.IMOBILIAR GRUP SRL", 27, 3, Cifra, *an);
	Firma::setPlatitoareTVA(0.18);
	firma3.afisare();

	cout << endl;
	cout << endl << "Clasa salariu" << endl;


	int* adaosSalariu;
	adaosSalariu = new int[2];
	adaosSalariu[0] = 500;
	adaosSalariu[1] = 1000;
	SalariuInvatamant Sal1;
	SalariuInvatamant::setSalariuMinim(2800);
	Sal1.afisare();//apelez primul constructor
	SalariuInvatamant Sal2(2310, " Profesor univeristar ");
	Sal2.afisare();
	SalariuInvatamant Sal3(2341, " Profesor invatamant primar ", 2, 4600, adaosSalariu);
	SalariuInvatamant::setSalariuMinim(2300);
	Sal3.afisare();


}

