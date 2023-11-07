
#include<iostream>
using namespace std;
class Angajat
{
private:
	const int id;
	string Nume;
	string Profesie;
	int NrAniVechime;
	float* Salariu;
	static int SporDeRisc;
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
		this->Nume = " Angajat";
		this->NrAniVechime = 0;
		this->Salariu = NULL;
		this->Profesie = " Profesie ";

	}
	Angajat(int idNou, string Nume, string Profesie) : id(idNou)
	{
		this->Nume = Nume;
		this->NrAniVechime = 0;
		this->Salariu = NULL;
		this->Profesie = Profesie;


	}
	Angajat(int id, string Nume, string Profesie, int NrAniVechime, const float* Salariu) :id(id)
	{
		this->Nume = Nume;
		this->NrAniVechime = NrAniVechime;
		this->Profesie = Profesie;
		if (NrAniVechime != 0)
		{
			this->Salariu = new float[NrAniVechime];
			for (int i = 0;i < NrAniVechime;i++)
			{
				this->Salariu[i] = Salariu[i];

			}
		}
		else this->Salariu = NULL;
	}

	Angajat(const Angajat& a) :id(a.id)//constructor de copiere
	{
		Nume = a.Nume;
		NrAniVechime = a.NrAniVechime;
		Profesie = a.Profesie;
		Salariu = new float[NrAniVechime];
		if (NrAniVechime != 0)
		{
			this->Salariu = new float[NrAniVechime];
			for (int i = 0;i < NrAniVechime;i++)
			{
				this->Salariu[i] = a.Salariu[i];
			}
		}
		else
			this->Salariu = NULL;

	}
	Angajat operator=(const Angajat& a)
	{
		if (this != &a)
		{
			if (this->Salariu != NULL)
			{
				delete[]this->Salariu;
			}
			Nume = a.Nume;
			Profesie = a.Profesie;
			NrAniVechime = a.NrAniVechime;
			Salariu = new float[NrAniVechime];

			if (NrAniVechime != 0)
			{
				this->Salariu = new float[NrAniVechime];
				for (int i = 0;i < NrAniVechime;i++)
				{
					this->Salariu[i] = a.Salariu[i];
				}

			}
			else this->Salariu = NULL;

		}
		return *this;
	}
	~Angajat()
	{
		if (this->Salariu != NULL)
		{
			delete[]this->Salariu;
		}
	}
	void afisare()
	{
		cout << id << "." << " Angajatul: " << Nume << endl;
		cout << "      Profesia:" << Profesie << endl;
		cout << "      Ani vechime:  " << NrAniVechime << " ani." << endl;
		cout << "      Pe fiecare an a avut salariul de: ";
		if (NrAniVechime != NULL)
		{
			for (int i = 0;i < NrAniVechime;i++)
			{
				cout << i + 1 << Salariu[i] << "lei" << " ";
			}
		}
		else
		{
			cout << " - ";
		}
		cout << endl << "    Sporul de risc este: " << SporDeRisc << endl;

	}

	string getNume()
	{
		return this->Nume;
	}
	void setNume(string Nume)
	{
		if (Nume.length() > 2)
		{
			this->Nume = Nume;
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
	int getNrAniVechime()
	{
		return this->NrAniVechime;
	}
	void setNrAniVechime(int NrAniVechime)
	{
		if (NrAniVechime != 0)
		{
			this->NrAniVechime = NrAniVechime;
		}
	}

	const  int getId()
	{
		return this->id;//la const nu se poate modifica pt ca este constant
	}



	void setSalariu(int NrAniVechime, float* Salariu)
	{
		if (NrAniVechime > 0)
		{
			this->NrAniVechime = NrAniVechime;
			if (this->Salariu != NULL)
			{
				delete[]this->Salariu;
			}
			this->Salariu = new float[NrAniVechime];
			for (int i = 0;i < NrAniVechime;i++)
			{
				this->Salariu[i] = Salariu[i];
			}
		}
	}
	float* getSalariu()
	{
		return this->Salariu;
	}
	friend int getNrAniVechime2(Angajat a);
	friend string getNume2(Angajat b);


	Angajat operator+(const Angajat& a)//operator+-supraincarcare
	{
		Angajat aux = *this;//valoare lui this
		aux.NrAniVechime = this->NrAniVechime + a.NrAniVechime;
		if (aux.Salariu != NULL)
		{
			delete[]aux.Salariu;//eliberez spatiu
		}
		if (aux.NrAniVechime > 0)
		{
			aux.Salariu = new float[aux.NrAniVechime];//aloc spatiu
			for (int i = 0;i < this->NrAniVechime;i++)
			{
				aux.Salariu[i] = Salariu[i];

			}
			for (int i = this->NrAniVechime;i < aux.NrAniVechime;i++)
			{
				aux.Salariu[i] = a.Salariu[i - NrAniVechime];
			}
		}
		else
		{
			aux.Salariu = NULL;
		}
		return aux;

	}
	friend ostream& operator<< (ostream& iesire, Angajat& a)//operator<<
	{
		iesire << "Id : " << a.getId() << "." << endl << "Nume  Angajat : " << a.getNume() << "." << endl << "Profesie: " << a.getProfesie() << " ." << endl << " Spor de risc: " << a.getSporDeRisc() << " . " << endl << " Angajatul are " << a.getNrAniVechime() << " ani vechime.  " << endl;
		if (a.getNrAniVechime() != NULL)

		{
			iesire << " Salariul pentru fiecare an : ";
			for (int i = 0; i < a.getNrAniVechime(); i++)
			{

				iesire << a.getSalariu()[i] << ",";
			}
		}
		else
		{
			iesire << "-";
		}
		iesire << endl;
		return iesire;
	}
	//operator->
	Angajat* operator->()
	{
		cout << "Ani de vechime fara promovare:";
		this->NrAniVechime = 1;
		return this;
	}

};
int getNrAniVechime2(Angajat a)//functii globale
{
	return a.NrAniVechime;


}
string getNume2(Angajat b)
{
	return b.Nume;
}



int Angajat::SporDeRisc = 2;
class Firma
{
private:
	const int CodCaen;//atribut constant
	string nume;
	int nrAniVechime;
	float* CifraDeAfaceri;
	int nrAngajati;
	static float PlatitoareTVA;//atribut static
public:
	static float getPlatitoareTVA()
	{
		return Firma::PlatitoareTVA;
	}
	static void setPlatitoareTVA(float TVA)
	{
		if (TVA != 0)
		{
			Firma::PlatitoareTVA = TVA;
		}
	}

	Firma() :CodCaen(2573)//primul constructor de initializare
	{
		this->nume = " Firma ";
		this->nrAniVechime = 0;
		this->CifraDeAfaceri = NULL;
		this->nrAngajati = 0;

	}
	Firma(int CodCaenNou, string nume) :CodCaen(CodCaenNou)// al doilea care primeste 2 parametrii
	{
		this->nume = nume;
		this->nrAngajati = 0;
		this->nrAniVechime = 0;
		this->CifraDeAfaceri = NULL;

	}
	Firma(int CodCaen, string nume, int nrAngajati, int nrAniVechime, const float* CifraDeAfaceri) :CodCaen(CodCaen)//al treilea constructor cu lista de parametrii
	{

		this->nume = nume;
		this->nrAngajati = nrAngajati;
		this->nrAniVechime = nrAniVechime;
		this->CifraDeAfaceri = new float[nrAniVechime];
		for (int i = 0; i < nrAniVechime; i++)
		{
			this->CifraDeAfaceri[i] = CifraDeAfaceri[i];
		}

	}


	Firma(const Firma& f) : CodCaen(f.CodCaen)  //constructor de copiere 
	{
		this->nume = f.nume;
		this->nrAniVechime = f.nrAniVechime;
		this->CifraDeAfaceri = new float[nrAniVechime];
		for (int i = 0; i < nrAniVechime; i++) {

			this->CifraDeAfaceri[i] = f.CifraDeAfaceri[i];

		}
		this->nrAngajati = f.nrAngajati;



	}


	Firma operator=(const Firma& f)// operatorul =
	{
		if (this != &f)
		{
			this->nume = f.nume;
			this->nrAniVechime = f.nrAniVechime;
			if (this->CifraDeAfaceri != NULL) {
				delete[]this->CifraDeAfaceri;
			}

			this->CifraDeAfaceri = new float[nrAniVechime];
			for (int i = 0; i < nrAniVechime; i++) {

				this->CifraDeAfaceri[i] = f.CifraDeAfaceri[i];

			}
			this->nrAngajati = f.nrAngajati;
			return *this;
		}
	}


	~Firma()//destructor
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
		cout << " Vechimea firmei :  " << nrAniVechime << endl;
		if (nrAniVechime != NULL)
		{
			cout << " Cifra de afaceri (mii euro) pentru fiecare an este:" << endl;
			for (int i = 0; i < nrAniVechime; i++)
			{

				cout << " Anul: " << i << "/" << CifraDeAfaceri[i] << " " << endl;

			}
		}
		else
		{
			cout << " Firma nu are rulaj" << endl;
		}
		cout << "TVA-ul platit de firma este: " << PlatitoareTVA << endl;

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
	const int getCodCaen()//pt atributul constant
	{
		return this->CodCaen;
	}
	int getNrAngajati()
	{
		return this->nrAngajati;
	}
	void setNrAngajati(int nrAngajati)
	{
		if (nrAngajati > 0)
		{
			this->nrAngajati = nrAngajati;

		}
		else
		{
			this->nrAngajati = 0;
		}

	}
	int getAniVechime()
	{
		return this->nrAniVechime;
	}
	void setAniVechime(int nrAniVechime)
	{

		this->nrAniVechime = nrAniVechime;
	}


	void setCifra(int nrAniVechime, float* Cifra)
	{

		this->nrAniVechime = nrAniVechime;

		if (this->CifraDeAfaceri != NULL)
		{
			delete[]this->CifraDeAfaceri;
		}
		this->CifraDeAfaceri = new float[nrAniVechime];
		for (int i = 0; i < nrAniVechime; i++)
		{
			this->CifraDeAfaceri[i] = Cifra[i];
		}

	}



	float* getCifradeAfaceri()
	{
		return this->CifraDeAfaceri;
	}



	friend istream& operator>>(istream& intrare, Firma& firma);//functii prietene

	friend ostream& operator<<(ostream& iesire, const Firma& firma);
	float operator()()
	{
		float suma = 0;
		for (int i = 0;i < this->nrAniVechime;i++)
		{
			suma += this->CifraDeAfaceri[i];
		}
		return suma;
	}
	Firma operator++(int)
	{
		Firma copie = *this;
		this->nrAngajati = nrAngajati++;

		return *this;
	}
	Firma* operator->()
	{
		this->nrAniVechime = 15;
		return this;


	}

};

float Firma::PlatitoareTVA = 0.19;
ostream& operator<<(ostream& iesire, Firma& firma)
{
	iesire << "Cod Caen:" << firma.getCodCaen() << endl << "Nume firma: " << firma.getNume() << endl << "Numar angajati: " << firma.getNrAngajati() << endl << " Numar ani vechime :" << firma.getAniVechime() << endl;
	if (firma.getAniVechime() != NULL)

	{
		iesire << "Cifrele de afaceri din ultimii ani :";
		for (int i = 0;i < firma.getAniVechime();i++)
		{

			iesire << "  " << firma.getCifradeAfaceri()[i] << " , ";
		}
	}
	else
	{
		iesire << "-";
	}
	iesire << endl;
	return iesire;

};

istream& operator>>(istream& intrare, Firma& firma)
{
	cout << "Nume firma: " << endl;
	intrare >> firma.nume;
	cout << " Numar ani vechime:" << endl;
	intrare >> firma.nrAniVechime;
	cout << " Numar angajati: " << endl;
	intrare >> firma.nrAngajati;
	if (firma.CifraDeAfaceri != NULL)
	{
		delete[]firma.CifraDeAfaceri;
	}
	if (firma.nrAniVechime > 0)
	{
		firma.CifraDeAfaceri = new float[firma.nrAniVechime];
		for (int i = 0;i < firma.nrAniVechime;i++)
		{
			cout << " Cifra de afaceri a firmei ( mii euro): " << i + 1 << ":";
			intrare >> firma.CifraDeAfaceri[i];
		}
	}
	else
	{
		cout << " Nu exista cifra de afaceri, firma nu are rulaj";
		firma.CifraDeAfaceri = NULL;
	}
	return intrare;



}
class SalariuInvatamant
{
private://declar atributele
	string PozitieAngajat;
	int NrGrade;
	int Valoare;
	float* AdaosGrad;//depinde de gradele obtinute
	static float SalariuMinim;
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
			SalariuInvatamant::SalariuMinim = salariu;//atributul static
		}
	}


	SalariuInvatamant() :CodCOR(23)//constructor 1-initializez atributele
	{

		this->PozitieAngajat = "  Tip profesor ";
		this->NrGrade = 0;
		this->Valoare = 0;
		this->AdaosGrad = NULL;

	}
	SalariuInvatamant(int CodCORNou, string PozitieAngajat) :CodCOR(CodCORNou)//constr cu 2 param
	{

		this->PozitieAngajat = PozitieAngajat;
		this->NrGrade = 0;
		this->Valoare = 0;
		this->AdaosGrad = NULL;

	}
	SalariuInvatamant(int CodCOR, string PozitieAngajat, int NrGrade, int Valoare, const int* AdaosGrad) :CodCOR(CodCOR), PozitieAngajat(PozitieAngajat), NrGrade(NrGrade), Valoare(Valoare)
	{

		if (NrGrade != NULL)
		{
			this->AdaosGrad = new float[NrGrade];
			for (int i = 0;i < NrGrade;i++)
			{
				this->AdaosGrad[i] = AdaosGrad[i];
			}

		}
		else
			this->AdaosGrad = NULL;//constructor cu mai multi param
	}
	SalariuInvatamant(const SalariuInvatamant& s) :CodCOR(s.CodCOR)//de copiere
	{
		cout << "Constructor de copiere" << endl;
		PozitieAngajat = s.PozitieAngajat;
		NrGrade = s.NrGrade;
		//valoare = s.valoare;

		if (NrGrade != 0)
		{
			this->AdaosGrad = new float[NrGrade];
			for (int i = 0;i < NrGrade;i++)
			{
				this->AdaosGrad[i] = s.AdaosGrad[i];
			}
		}
		else
			this->AdaosGrad = NULL;

	}
	SalariuInvatamant operator=(const SalariuInvatamant& s)//operatorul=
	{
		if (this != &s)
		{
			if (this->AdaosGrad != NULL)
			{
				delete[]this->AdaosGrad;
				PozitieAngajat = s.PozitieAngajat;
				NrGrade = s.NrGrade;

			}
			if (NrGrade != 0)
			{
				this->AdaosGrad = new float[NrGrade];
				for (int i = 0;i < NrGrade;i++)
				{
					this->AdaosGrad[i] = s.AdaosGrad[i];
				}

			}
			else this->AdaosGrad = NULL;

		}
		return *this;
		cout << endl;
	}
	~SalariuInvatamant()//destructor
	{
		if (this->AdaosGrad != NULL)
		{
			delete[]this->AdaosGrad;
		}
	}
	void afisare()
	{
		cout << " Codul COR este: " << CodCOR << endl;
		cout << " Tip cadru: " << PozitieAngajat << endl;
		cout << " Numar de grade obtinute: " << NrGrade << endl;
		cout << " Salariul: " << Valoare;
		if (AdaosGrad != NULL)
		{
			for (int i = 0;i < NrGrade;i++)
			{
				this->AdaosGrad[i] = AdaosGrad[i];

				cout << endl << "Adaos[" << i + 1 << "]=" << AdaosGrad[i] << endl;
			}
		}
		else
		{
			cout << " - " << endl;
		}
		cout << "Salariul minim este:" << SalariuMinim << endl;
		cout << endl;

	}
	/*static void setSalariuMinim(float SalariuMinimNou)//functie statica
	{
		SalariuMinim = SalariuMinimNou;
	}*/
	void setPozitieAngajat(string PozitieAngajat)

	{
		this->PozitieAngajat = PozitieAngajat;

	};
	string getPozitieAngajat()
	{
		return  this->PozitieAngajat;
	}

	const int getCodCOR()
	{
		return this->CodCOR;
	}
	void setValoare(int  Valoare)
	{

		this->Valoare = Valoare;

	}
	float getValoare()
	{
		return this->Valoare;
	}
	void setNrGrade(int NrGrade)
	{
		if (NrGrade != 0)
		{
			this->NrGrade = NrGrade;

		}
	}
	int getNrGrade()
	{
		return this->NrGrade;
	}
	void setAdaosGrad(int NrGrade, float* Adaos)//setter compus pt ca un atrb depinde de altul
	{
		if (NrGrade > 0)
		{
			this->NrGrade = NrGrade;
			if (this->AdaosGrad != NULL)
			{
				delete[]this->AdaosGrad;
			}
			this->AdaosGrad = new float[NrGrade];
			for (int i = 0; i < NrGrade; i++)
			{
				this->AdaosGrad[i] = Adaos[i];
			}
		}
	}
	float* getAdaosGrad()
	{
		return this->AdaosGrad;
	}
	friend istream& operator>>(istream& intrare, SalariuInvatamant& salariu);//functiile globale si prietene

	friend ostream& operator<<(ostream& iesire, const SalariuInvatamant& salariu);

	SalariuInvatamant operator--(int)
	{
		SalariuInvatamant copie = *this;
		this->Valoare = Valoare--;
		return copie;

	}
	int operator [](int index)
	{
		if (index >= 0 && index < NrGrade)
		{
			return AdaosGrad[index];
		}
	}
	operator int()//operator de cast
	{
		return Valoare;

	}
};

float SalariuInvatamant::SalariuMinim = 3000;
//functii globale
//cout << "Operator <<";
ostream& operator<<(ostream& iesire, SalariuInvatamant& salariu)
{

	iesire << "Codul COR: " << salariu.getCodCOR() << "." << endl << "Pozitie Angajat : " << salariu.getPozitieAngajat() << "." << endl << "Salariul Minim: " << salariu.getSalariuMinim() << "lei " << endl << " Salariul real: " << salariu.getValoare() << " lei, valoarea reala pentru  " << salariu.getNrGrade() << " grade obtinute.    " << endl;
	if (salariu.getAdaosGrad() != NULL)

	{
		iesire << " Adaosului salariului pentru gradele obtinute: ";
		for (int i = 0; i < salariu.getNrGrade(); i++)
		{

			iesire << salariu.getAdaosGrad()[i] << ",";
		}
	}
	else
	{
		iesire << "-";
	}
	iesire << endl;
	return iesire;
};
istream& operator>>(istream& intrare, SalariuInvatamant& salariu)
{
	cout << "Pozitie Angajat:";
	intrare >> salariu.PozitieAngajat;
	cout << "Valoarea salariului: ";
	intrare >> salariu.Valoare;
	cout << "Grade obtinute: ";
	intrare >> salariu.NrGrade;
	if (salariu.AdaosGrad != NULL)
	{
		delete[]salariu.AdaosGrad;
	}
	if (salariu.NrGrade > 0)

	{
		salariu.AdaosGrad = new float[salariu.NrGrade];
		for (int i = 0; i < salariu.NrGrade; i++)
		{
			cout << "Adaosul salariului:  " << i + 1 << ":";
			intrare >> salariu.AdaosGrad[i];
		}
	}
	else
	{
		cout << "Nu exista  adaos. ";
		salariu.AdaosGrad = NULL;
	}
	return intrare;
	cout << endl;

}

void main()
{
	cout << endl << "Clasa angajat" << endl;
	float Salariu1[] = { 500, 100,1120 };
	cout << "Angajat1" << endl;
	Angajat ang1;//constructorul de initializare
	ang1.afisare();
	cout << endl;
	cout << "Angajat2" << endl;
	Angajat ang2(7, " Ionescu Andreea", " Inginer sef ");//constructorul cu 3 parametrii
	ang2.afisare();
	cout << endl;
	cout << "Angajat3" << endl;
	Angajat ang3(4, "Georgescu ", "Asistent", 3, Salariu1);//apelez constr cu toti parametrii
	Angajat::setSporDeRisc(4);
	ang3.afisare();
	cout << endl;
	cout << "Angajat4- constr copiere" << endl;
	Angajat ang4(ang2);//apelez constructorul de copiere
	ang4.afisare();
	cout << endl;
	cout << "Angajat6- operator =" << endl;
	Angajat ang6;
	ang6 = ang3;//apelez operatorul=
	ang6.afisare();
	cout << endl;
	cout << "functii get si set" << endl;//functii de get si set
	cout << endl;
	ang2.setNume("Popescu Adela");
	cout << "Nume nou:" << ang2.getNume() << endl;

	ang2.setProfesie("Analist financiar");
	cout << "Noua profesie:" << ang2.getProfesie() << endl;

	ang2.setNrAniVechime(3);

	cout << "Ani vechime: " << ang2.getNrAniVechime() << endl;



	float* salariu1 = new float[3] {2000, 2200, 2300};
	ang2.setSalariu(3, salariu1);
	//cout << ang2.getSalariu() << endl;
	//ang2.afisare();

	float* SalariuObtinut = ang2.getSalariu();
	for (int i = 0;i < 3;i++)
	{
		cout << "Salariu obtinut: [" << i + 1 << "]: ";
		cout << SalariuObtinut[i] << "" << endl;
	}


	cout << endl;
	cout << "Functii globale:" << endl;
	cout << "Schimb vechime:" << getNrAniVechime2(ang3) << endl;//functia globala
	cout << "Schimb nume:" << getNume2(ang3) << endl;//functie globala
	cout << endl;
	//supraincarcare operatori
	cout << "Operator +" << endl;
	cout << "Angajatul 1 :" << endl;
	ang1.afisare();
	ang1 = ang4 + ang1;//nu merge
	ang1.afisare();
	cout << endl;
	cout << " Operator iesire" << endl;
	cout << ang3;
	cout << endl;
	cout << "Operator atribuire " << endl;
	Angajat ang8;
	ang8.setNrAniVechime(5);
	cout << "Ani de vechime:" << ang8.getNrAniVechime() << endl;
	cout << ang8->getNrAniVechime() << endl;
	cout << endl;
	cout << endl << "Clasa Firma" << endl;
	float Cifra[] = { 1.9, 9.9, 5.9 };
	cout << "Firma1 ";
	Firma firma1;
	firma1.afisare();//primul constr
	Firma::setPlatitoareTVA(0.20);//functie statica
	cout << endl;
	cout << "Firma2" << endl;
	Firma firma2(6972, "SC.RAMYCONT.SRL");//al doilea constructor
	Firma::setPlatitoareTVA(0.21);
	firma2.afisare();
	cout << endl;
	cout << "Firma3 " << endl;
	Firma firma3(7765, "SC.IMOBILIAR GRUP SRL", 27, 3, Cifra);//al treilea constructor
	Firma::setPlatitoareTVA(0.18);
	firma3.afisare();
	cout << endl;
	cout << "Firma4 " << endl;
	Firma firma4(firma3);
	firma4.afisare();//apelez constr de copiere
	cout << endl;
	cout << "Firma5" << endl;
	Firma firma5;//apelez pt operatorul=
	firma5 = firma3;
	firma5.afisare();
	cout << endl;
	cout << "Firma 6" << endl;
	Firma firma6;
	firma6 = firma4;
	float* CifraDeAfaceri1 = new float[4] {2.2, 1.8, 2.0, 1.4};
	firma6.setCifra(4, CifraDeAfaceri1);


	float* CifraObtinuta = firma6.getCifradeAfaceri();
	for (int i = 0;i < 4;i++)
	{
		cout << "Cifra de afaceri [" << i + 1 << "]: ";
		cout << CifraObtinuta[i] << "" << endl;
	}

	//firma6.afisare();
	cout << endl;
	cout << "Firma7" << endl;
	Firma firma7;

	cout << "Operator>>- intrare " << endl;
	cin >> firma7;
	cout << endl;
	cout << "Operator <<-afisare intrare" << endl;
	cout << firma7;
	cout << endl;
	cout << "Operator ()" << endl;
	cout << " Suma cifrelor de afaceri: ";//operator()
	cout << firma7() << " mii euro." << endl;//dc nu tranf suma in float
	cout << endl;
	cout << " Operator ++:" << endl;//modific numarul de angajati
	cout << firma7;
	firma7 = firma7++;
	cout << endl;
	cout << " Incrementare  numar angajati: " << endl;
	cout << firma7;
	cout << endl;
	cout << "Operator atribuire" << endl;
	cout << "Firma 8" << endl;
	Firma firma8;
	firma8.setAniVechime(2);
	cout << "Ani de vechime:" << firma8.getAniVechime() << endl;
	cout << "Ani de vechime dupa atribuire: " << firma8->getAniVechime() << endl;
	delete[]CifraDeAfaceri1;
	cout << endl;
	cout << endl << "Clasa salariu" << endl;



	int AdaosSalariu[] = { 500,1000 , 467, 200 };
	cout << "Salariu1 - constructor initializare" << endl;
	SalariuInvatamant Sal1;
	Sal1.afisare();//apelez primul constructor, fara param
	SalariuInvatamant::setSalariuMinim(2800);
	cout << endl;
	cout << "Salariu2- constructor 2 parametrii" << endl;
	SalariuInvatamant Sal2(2310, " Profesor univeristar ");//al doilea constructor-2 param
	Sal2.afisare();
	cout << endl;

	cout << "Salariu3- constructor lista parametrii" << endl;
	SalariuInvatamant Sal3(2341, " Profesor invatamant primar ", 2, 4600, AdaosSalariu);//al 3 lea constructor, mai multi param
	SalariuInvatamant::setSalariuMinim(2300);//accesez functia statica
	Sal3.afisare();
	cout << endl;
	cout << "Salariu4 - constructor copiere" << endl;

	SalariuInvatamant Sal4(Sal3);//apelez constr copiere
	Sal4.afisare();
	cout << endl;
	cout << "Salariu 5- operator =" << endl;

	SalariuInvatamant Sal5;
	Sal5 = Sal3;//operatorul=
	Sal5.afisare();
	cout << endl;
	cout << "Salariu6 get si set " << endl;

	SalariuInvatamant Sal6;

	Sal6.setPozitieAngajat(" Profesor invatamant gimnazial");//apelez get si set pt toate atributele
	cout << "Pozitie noua: " << Sal6.getPozitieAngajat() << endl;
	Sal6.setNrGrade(4);
	cout << "Numar grade obtinute: " << Sal6.getNrGrade() << endl;
	Sal6.setValoare(4000);
	cout << "Valoare salariu : " << Sal6.getValoare() << endl;
	float Adaos[] = { 100, 150, 200 };
	Sal6.setAdaosGrad(3, Adaos);
	float* adaosObtinut = Sal6.getAdaosGrad();
	for (int i = 0;i < 3;i++)
	{
		cout << "Adaosul salariului[" << i + 1 << "]: ";
		cout << adaosObtinut[i] << "" << endl;
	}

	cout << endl;
	cout << endl;
	cout << "Operator >>" << endl;//fctie prietena
	cout << Sal6;//pt op<<
	cout << endl;
	cout << "salariu7" << endl;
	SalariuInvatamant Sal7;
	cout << " Operator >>" << endl;//fctie prietena
	cin >> Sal7;
	cout << endl;
	cout << Sal7;
	cout << endl;
	cout << "Operator --";
	Sal4.setValoare(2400);
	Sal7 = Sal4--;
	cout << Sal7 << endl << "Valoarea salariului este ";
	cout << endl;
	cout << " Index" << endl;
	cout << "Salariu 8";
	SalariuInvatamant Sal8(2708, " Profesor universitar stagiar", 3, 3500, new int[3] {100, 500, 1000});
	cout << Sal8;
	int ValoareImplicita = Sal8;///operator de cast
	int ValoareExplicita = (int)Sal8;
	cout << "Valoare explicita: " << ValoareExplicita << endl;
	cout << "Valoare Implicita: " << ValoareImplicita;

};

