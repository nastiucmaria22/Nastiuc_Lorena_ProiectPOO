#include<iostream>
using namespace std;
class Angajat
{
private:
	const int id;
	string nume;//get+set
	string Profesie;//get+set
	int vechime;//get+set
	int* salariu;
	int an;
	static int SporDeRisc;//get+set
public://trec din public in privat
	static int getSporDeRisc()//doar citire, functia statica
	{
		return Angajat::SporDeRisc;

	}
	static void setSporDeRisc(int spor)//accesez si modific
	{
		if (spor > 0)
		{
			Angajat::SporDeRisc = spor;
		}
	}

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
	//constructor de copiere
	Angajat(const Angajat& a) :id(a.id)
	{
		nume = a.nume;
		vechime = a.vechime;
		salariu = new int[vechime];
		if (vechime != 0)
		{
			this->salariu = new int[vechime];
			for (int i = 0;i < vechime;i++)
			{
				this->salariu[i] = a.salariu[i];
			}
		}
		else
			this->salariu = NULL;

	}
	Angajat operator=(const Angajat& a)
	{
		if (this != &a)
		{
			if (this->salariu != NULL)
			{
				delete[]this->salariu;
				nume = a.nume;
				vechime = a.vechime;
				salariu = new int[vechime];
			}
			if (vechime != 0)
			{
				this->salariu = new int[vechime];
				for (int i = 0;i < vechime;i++)
				{
					this->salariu[i] = a.salariu[i];
				}

			}
			else this->salariu = NULL;

		}
		return *this;
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
	/*static void setSporDeRisc(int SpoDeRiscNou)
	{
		SporDeRisc = SpoDeRiscNou;
	}*/
	string getNume()
	{
		return this->nume;
	}
	void setNume(string nume)
	{
		if (nume.length() > 2)
		{
			this->nume = nume;
		}
	}
	string getProfesie()
	{
		return this->Profesie;

	}
	void setProfesie(string Profesie)
	{
		if (Profesie.length() > 0)
		{
			this->Profesie = Profesie;
		}

	}
	int getVechime()
	{
		return this->vechime;
	}
	void setVechime(int vechime)
	{
		if (vechime != 0)
		{
			this->vechime = vechime;
		}
	}
	int getAn()
	{
		return this->an;
	}
	/*void setAn(int an)
	{
		if (an != 0)
		{
			this->an = an+1;
		}
	}*/
	const  int getId()
	{
		return this->id;//la const nu se poate modifica pt ca este constant
	}
	void setAn(int an)
	{
		if (an != 0)
		{
			this->an = an;

		}
		an++;
	}


	void setSalariu(int an, int* salariu2)
	{
		if (vechime > 0)
		{
			this->vechime = vechime;
			if (this->salariu != NULL)
			{
				delete[]this->salariu;
			}
			this->salariu = new int[vechime];
			for (int i = 0;i < vechime;i++)
			{
				this->salariu[i] = salariu2[i];
			}
		}
	}
	int* getSalariu()
	{
		return this->salariu;
	}
	/*	void setAn(int an)
		{
			if (an != 0)
			{
				this->an = an;
				an++
			}
		}
		*/
	int getSalariu(int index)
	{
		return this->salariu[index];
	}
};

int Angajat::SporDeRisc = 2;

class Firma
{
private:
	const int CodCaen;//atribut constant//get+set
	string nume;//get+set
	float* CifraDeAfaceri;
	int nrAngajati;
	int vechime;
	int an;
	static float PlatitoareTVA;//atribut static
public:
	static float getPlatitoareTVA()
	{
		return Firma::PlatitoareTVA;
	}
	static void setPlatitoareTVA(float TVA)
	{
		if (TVA !=0)
		{
			Firma::PlatitoareTVA = TVA;
		}
	}

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
	//constructor de copiere 
	Firma operator=(const Firma& f)
	{
		if (this != &f)
		{
			if (this->vechime != NULL)
				delete[]this->CifraDeAfaceri;
			nume = f.nume;
			vechime = f.vechime;
			CifraDeAfaceri = new float[vechime];
			if (vechime!= 0)
			{
				this->CifraDeAfaceri = new float[vechime];
				for (int i = 0; i < vechime; i++)
				{
					this-> CifraDeAfaceri[i] = f.CifraDeAfaceri[i];
				}
			}
			else this->CifraDeAfaceri = NULL;
		}
		return *this;
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

				cout << " An: " << an++ << "/" << CifraDeAfaceri[i] << " " << endl;

			}
		}
		else
		{
			cout << " Firma nu are rulaj" << endl;
		}
		cout << "TVA-ul platit de firma este: " << PlatitoareTVA;

	}
	void setNume(string nume)
	{

		if (nume.length() > 3)
		{
			this->nume = nume;
		}
	}
	string getNume()
	{
		return this->nume;
	}
	const int GetCodCaen()//pt atributul constant
	{
		return this->CodCaen;
	}
	int GetNrAngajati()
	{
		return this->nrAngajati;
	}
	void setNrAngajati(int NrAngajati)
	{
		if (NrAngajati > 0)
		{
			this->nrAngajati = NrAngajati;

		}
	}
	int getVechime()
	{
		return this->vechime;
	}
	void setVechime(int vechime)
	{
		if (vechime != 0)
		{
			this->vechime = vechime;
		}
	}
	int getAn()
	{
		return this->an;
	}
	const  int getCodCaen()
	{
		return this->CodCaen;//la const nu se poate modifica pt ca este constant
	}
	void setAn(int an)
	{
		if (an != 0)
		{
			this->an = an;

		}
		an++;
	}
	void setCifra(int an, float* Cifra)
	{
		if (vechime > 0)
		{
			this->vechime = vechime;
			if (this->CifraDeAfaceri!= NULL)
			{
				delete[]this->CifraDeAfaceri;
			}
			this->CifraDeAfaceri = new float[vechime];
			for (int i = 0;i < vechime;i++)
			{
				this->CifraDeAfaceri[i] = Cifra[i];
			}
		}
	}
	float* getCifraDeAfaceri()
	{
		return this->CifraDeAfaceri;
	}



	//static void setPlatitoareTVA(float TVANou)//functia statica
	//{
	//	PlatitoareTVA = TVANou;
	//}
};
float Firma::PlatitoareTVA = 0.19;
class SalariuInvatamant
	{
	private:
		string PozitieAngajat;
		float OreLucrate;
		float valoare;
		static float SalariuMinim;
		float* adaosGrad;
		const int CodCOR;
	public:
		static float getSalariuMinim()//doar citire, functia statica
		{
			return SalariuInvatamant::SalariuMinim;

		}
		static void setSalariuMinim(float salariu)//accesez si modific
		{
			if (salariu > 0)
			{
				SalariuInvatamant::SalariuMinim = salariu;
			}
		}

	
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
		SalariuInvatamant (const SalariuInvatamant& s) :CodCOR(s.CodCOR)
		{
			PozitieAngajat = s.PozitieAngajat;
			OreLucrate = s.OreLucrate;
			adaosGrad = new float[OreLucrate];
			if (OreLucrate != 0)
			{
				this->adaosGrad = new float[OreLucrate];
				for (int i = 0;i < OreLucrate;i++)
				{
					this->adaosGrad[i] = s.adaosGrad[i];
				}
			}
			else
				this->adaosGrad = NULL;

		}
		SalariuInvatamant operator=(const SalariuInvatamant& s)
		{
			if (this != &s)
			{
				if (this->adaosGrad != NULL)
				{
					delete[]this->adaosGrad;
					PozitieAngajat = s.PozitieAngajat;
					OreLucrate = s.OreLucrate;
					adaosGrad = new float[OreLucrate];
				}
				if (OreLucrate != 0)
				{
					this->adaosGrad = new float[OreLucrate];
					for (int i = 0;i < OreLucrate;i++)
					{
						this->adaosGrad[i] = s.adaosGrad[i];
					}

				}
				else this->adaosGrad= NULL;

			}
			return *this;
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
		/*static void setSalariuMinim(float SalariuMinimNou)
		{
			SalariuMinim = SalariuMinimNou;
		}*/
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
	Angajat ang4(ang2);//apelez constr de copiere
	ang4.afisare();
	Angajat ang5 = ang1;//alt mod de a scrie apelul pt construct de copiere
	ang5.afisare();
	//Angajat ang6;
	//ang6 = ang1;//apelez operatorul=
	//ang6.afisare();
	//ang2 = ang2;
	ang2.afisare();
	ang2.setNume("Popescu Adela");//apelez setterul si getterul 
	cout << ang2.getNume() << endl;
	ang2.setProfesie("Analist financiar");
	cout << ang2.getProfesie() << endl;
	ang2.setVechime(3);
	
	cout << ang2.getVechime() << endl;
	ang2.setAn(2015);
	cout << ang2.getAn() << endl;
	ang2.setAn(2016);
	cout << ang2.getAn() << endl;
	ang2.setAn(2017);
	cout << ang2.getAn() << endl;
	int* salariu1 = new int[3] {2000, 2200, 2300};
	ang2.setSalariu(3, salariu1);
	cout << ang2.getSalariu() << endl;
	ang2.afisare();
	//cout << ang2.getSalariu()[3];
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


	Firma firma3(7765, "SC.IMOBILIAR GRUP SRL", 27, 3, Cifra, *an);
	Firma::setPlatitoareTVA(0.18);
	firma3.afisare();
	Firma firma4(firma1);//apelez constr de copiere
	cout << endl;
	//F/*irma firma5;
	//firma5 = firma3;
	//firma4.afisare();
	//firma5.afisare();*/
	cout << endl;
	Firma firma6(firma2);
	firma6.setNume(" SC.DANYCOM.SRL");
	cout << "Numele nou" << firma6.getNume() << endl;
	firma6.setPlatitoareTVA(0.23);
	cout << "Noul TVA :" << firma6.getPlatitoareTVA() << endl;
	firma6.setNrAngajati(3);
	cout << "Noul nr angajati : " << firma6.GetNrAngajati() << endl;
	firma6.setVechime(4);
	cout << "Vechimea actuala: " << firma6.getVechime() << endl;
	firma6.setAn(2014);
	cout << "Anii de functionare ai firmei : "<<endl<<firma6.getAn() << endl;
	firma6.setAn(2015);
	cout << firma6.getAn() << endl;
	firma6.setAn(2016);
	cout << firma6.getAn() << endl;
	firma6.setAn(2017);
	cout << firma6.getAn() << endl;
	 float* CifraDeAfaceri1 = new float[34] {2.2, 1.8, 2.0, 1.4};
	firma6.setCifra(4, CifraDeAfaceri1);
	cout << firma6.getCifraDeAfaceri()[4];
	firma6.afisare();
	//cout<<" Cifra de afaceri corespunzatoare anilor(mii euro): "<<firma6.getCifraDeAfaceri() << endl;//nu apar valorile , doar o adresa
	//cout << firma6.getCifraDeAfaceri()[4];
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
			cout << "constructor de copiere "<<endl;
			SalariuInvatamant Sal4(Sal3);//apelez constr copiere
			Sal4.afisare();
			cout << "operator="<<endl;
			SalariuInvatamant Sal5;
			Sal5 = Sal2;
			Sal5.afisare();
}
