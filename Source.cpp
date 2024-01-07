
#include<iostream>
#include<fstream>
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
	
	//operator->
	Angajat* operator->()
	{
		cout << "Ani de vechime fara promovare:";
		this->NrAniVechime = 1;
		return this;
	}
	friend class Angajator;

	friend ofstream& operator<<(ofstream& fisier,  Angajat& a)//fisiere text
	{
		fisier<< a.Nume << endl;
		fisier << a.Profesie << endl;
		fisier << a.NrAniVechime << endl;
		for (int i = 0; i < a.NrAniVechime; i++)
		{
			fisier << a.Salariu[i];
			if (i < a.NrAniVechime - 1)
				fisier << ' '; // sau orice separator dorit
		}

		return fisier;

    }
	friend ifstream& operator>>(ifstream& fisier, Angajat& a)//fisier text
	{
		fisier >> a.Nume;
		fisier >> a.Profesie;
		fisier >> a.NrAniVechime;
		if (a.Salariu != NULL)
			delete[]a.Salariu;
		if(a.NrAniVechime>0)
		{
			a.Salariu = new float[a.NrAniVechime];
			for (int i = 0;i < a.NrAniVechime;i++)
			{
				fisier >> a.Salariu[i];
			}

		}
		else
		{
			a.Salariu = NULL;
		}
		return fisier;

		
	}
	friend ostream& operator<< (ostream& iesire,  Angajat& a)//operator<<
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
class AngajatPromovat : public Angajat// clase mostenite
{
private: string NumeAngajat;
	   float Salariu;
	   int ZiuaLunii;
 public:
	AngajatPromovat() :Angajat()
	{
		this->NumeAngajat = "Andreea Iancu";
		this->Salariu = 1700;
		this->ZiuaLunii = 17;
	}
	AngajatPromovat(string NumeNou, float SalariuNou, int ZiuaLuniiNoua) : Angajat(12,"Popescu Alex", "Farmacist")
	{
		this->NumeAngajat = NumeNou;
		this->Salariu = SalariuNou;
		this->ZiuaLunii = 23;
	}
	~AngajatPromovat()
	{}
	AngajatPromovat(const AngajatPromovat& a) :Angajat(a) {
		this->NumeAngajat = a.NumeAngajat;
		this->Salariu = a.Salariu;
		this->ZiuaLunii = a.ZiuaLunii;

	}
	AngajatPromovat operator=(const AngajatPromovat& a)
	{
		if (this != &a)
		{
			this->NumeAngajat = a.NumeAngajat;
			this->Salariu = a.Salariu;
			this->ZiuaLunii = a.ZiuaLunii;
		}
		return *this;
	}
	string getNumeAngajat()
	{
		return this->NumeAngajat;
	}
	float getSalariu()
	{
		return this->Salariu;
	}
	int getZiuaLunii()
	{
		return this->ZiuaLunii;

	}
	void setNumeAngajat(string NumeNou)
	{
		this->NumeAngajat = NumeNou;
	}
	void setSalariu(float SalariuNou)
	{
		this->Salariu = SalariuNou;
	}
	void setZiuaLunii(int ZiuaLuniiNoua)
	{
		this->ZiuaLunii = ZiuaLuniiNoua;
	}
	friend ostream& operator<<(ostream& afisare1,     AngajatPromovat& a)
	{
		afisare1 << " Numele angajatului promovat este " << a.NumeAngajat << endl;
		afisare1 << " Angajatul va primi salariul de " << a.Salariu<< " pe data de "<<a.ZiuaLunii<<" a lunii"<<endl;
		//afisare1 << (Angajat)a;
		return afisare1;
		
	}


};
///////////////////////////////////////////////////////////



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

	friend ofstream& operator<<(ofstream& fisier, Firma& f);//fisiere text
	friend ifstream& operator>>(ifstream& fisier, Firma& f);
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
ofstream& operator<<(ofstream& fisier,  Firma& f)
{
	fisier << f.nume << endl;
	fisier << f.nrAniVechime << endl;
	fisier << f.CifraDeAfaceri << endl;
	fisier << f.nrAngajati << endl;
	return fisier;

}
ifstream& operator >>(ifstream& fisier, Firma& f)
{
	fisier >> f.nume;
	fisier >> f.nrAniVechime;
	if (f.CifraDeAfaceri != NULL)
	{
		delete[]f.CifraDeAfaceri;
	}
	if (f.nrAniVechime > 0)
	{
		f.CifraDeAfaceri = new float[f.nrAniVechime];
		for (int i = 0;i < f.nrAniVechime;i++)
		{
			fisier >> f.CifraDeAfaceri[i];
		}
	}
	else
	{
		f.CifraDeAfaceri = NULL;

	}
	return fisier;
}

ostream& operator<<(ostream& iesire,  Firma& firma)
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
};
class FirmaAsigurata : public Firma {
private:
	string NumeFirma;
	int PerioadaAsigurare;
	float PretAsigurare;
public:
	FirmaAsigurata():Firma()
	{
		this->NumeFirma = " Aticom";
		this->PerioadaAsigurare = 24;
		this->PretAsigurare = 600;
	}//constr init
	FirmaAsigurata(string NumeNou, int PerioadaNoua, float PretNou) :Firma(1622, "Adamcom")
	{
		this->NumeFirma = NumeNou;
		this->PerioadaAsigurare = PerioadaNoua;
		this->PretAsigurare = PretNou;

	}
	~FirmaAsigurata()
	{};
	FirmaAsigurata(const FirmaAsigurata& fa) :Firma()
	{
		this->NumeFirma = fa.NumeFirma;
		this->PerioadaAsigurare = fa.PerioadaAsigurare;
		this->PretAsigurare = fa.PretAsigurare;
	}//op de copiere
	FirmaAsigurata operator=(const FirmaAsigurata& fa)
	{
		if (this != &fa)
		{
			this->NumeFirma = fa.NumeFirma;
			this->PerioadaAsigurare = fa.PerioadaAsigurare;
			this->PretAsigurare = fa.PretAsigurare;

	     }
		return *this;

	}
	friend ostream& operator<<(ostream& afisare2,  FirmaAsigurata& fa)
	{
		afisare2 << " Nume firma: " << fa.NumeFirma << endl;
		afisare2 << " Perioada de asigurare este de " << fa.PerioadaAsigurare << " luni" << endl;
		afisare2 << " Pretul asigurarii este de " << fa.PretAsigurare << " lei. " << endl;
		afisare2 << (Firma)fa;
		return afisare2;
	}
	string getNume()
	{
		 return this->NumeFirma;
	}
	int getPerioadaAsigurare()
	{
		return this->PerioadaAsigurare;
	}
	float getPretAsigurare()
	{
		return this->PretAsigurare;
	}
	void setNumeFirmaAsig(string NumeNou)
	{
		this->NumeFirma = NumeNou;
	}
	void setPerioadaAsigurare( int PerioadaNoua)
	{
		this->PerioadaAsigurare = PerioadaNoua;
	}
	void setPretAsigurare(float PretNou)
	{
		this->PretAsigurare = PretNou;
	}
};



	
	class Colaborator
	{
	private:
		string nume;
		Firma* firma;
		int vechime;
	public:
		Colaborator()
		{
			this->nume = " Mobexpert ";
			this->firma = NULL;
			this->vechime = 0;
		}
		Colaborator(int vechime)
		{
			this->nume = " Dedeman ";
			this->firma = firma;
			this->vechime = vechime;
		}
		~Colaborator()
		{
			if (this->firma != NULL)
			{
				delete[]this->firma;
			}
		}
		friend ostream& operator<<(ostream& iesire, const Colaborator& c)
		{
			iesire << " Clientul " << c.nume << " colaboreaza cu firma  de " << c.vechime << " ani " << endl;
			iesire << " ----------------------------------------" << endl;
			return iesire;
		}
		string getNumeColaborator()
		{
			return this->nume;
	
		}
		void setNumeColaborator(string numeNou)
		{
			this->nume = numeNou;
		}
		int getVechime()
		{
			return this->vechime;
		}
		void setVechime(int vechimeNoua)
		{
			this->vechime = vechimeNoua;
		}
		Firma* getFirma()
		{
			return this->firma;
	
		}
		Firma operator[](int index)
		{
			return this->firma[index];
		}
		Colaborator operator+(const Colaborator& c)
		{
			Colaborator aux = *this;
			aux.vechime = this->vechime + c.vechime;
			return aux;
	
		}
	};
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
			Angajat angaj1;
			Angajat angaj2;
			Angajat angaj3;
			Angajat* a_angajat = new Angajat[3];//vector de 3 obiecte;
			a_angajat[0] = angaj1;
			a_angajat[1] = angaj2;
			a_angajat[2] = angaj3;
			cout << endl << " Vector de obiecte  angajat " << endl;
			for (int i = 0;i < 3;i++)
			{
				cout << "angajat [" << i + 1 << "]=";
		
				cout << a_angajat[i] << endl;
			}
			delete[]a_angajat;
			cout << "matrice" << endl;
			Angajat** matrice = new Angajat * [3];//pointer la pointer
			for (int i = 0;i < 3;i++)
			{
				matrice[i] = new Angajat[3];
			}//aloc spatiu ptr matrice;
			for (int i = 0;i < 3;i++)
				for (int j = 0;j < 3;j++)
				{
					cout << matrice[i][j];
		
				}
			delete[]matrice;
			//fisiere text 
			//Angajat angajat1;
		
			ofstream fis("Angajat.txt", ios::out);//apelez fisier text de iesire
			fis << ang1;
			fis << ang3;
			fis.close();
		
			ifstream g("Angajat.txt", ios::in);//ap fis text de intrare
			g >> ang3;
			cout << ang3;
			g.close();
		
			Angajat a1;
			fstream x("Angajat.bin", ios::out | ios::binary);//ap fis binare 
			x.write((char*)&a1, sizeof(Angajat));
			x.close();
			fstream y("Angajat.bin", ios::in | ios::binary);
			y.read((char*)&a1, sizeof(Angajat));
			y.close();
			///clase mostenite
			AngajatPromovat AngProm1;
			cout << " Clasa mostenita : Angajat promovat"<<endl;
			cout <<"Angajat promovat 1: "<< AngProm1<<endl;
			AngajatPromovat AngProm2(AngProm1);
			cout << "Angajat promovat 2:"<<AngProm2<<endl;//apelare constructor de copiere 
			AngajatPromovat AngProm3("Angelescu Alina", 1800, 28);
			cout << " Angajat promovat 3:" << AngProm3<<endl;
			AngProm3 = AngProm1;
			cout <<"Angajatul promovat 3 actualizat:" << AngProm3<<endl;
			AngProm1.setNume(" Popescu Isabela");
			cout << " Noul nume pentru AngProm1 este" << AngProm1.getNume()<<endl;
			AngProm2.setSalariu(2600);
			cout << " Noul salariu al AngProm2 este:" << AngProm2.getSalariu()<<endl;
			AngProm3.setZiuaLunii(30);
			cout << " Noua zi de promovare a AngProm3 este:" << AngProm3.getZiuaLunii()<<endl;
		



		





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

	firma6.afisare();
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
	Firma f1;
	Firma f2;
	Firma f3;
	Firma* f_firma = new Firma[3];//vector de 3 obiecte;
	f_firma[0] = f1;
	f_firma[1] = f2;
	f_firma[2] = f3;
	cout <<endl<< " Vector de obiecte  firma  " << endl;
	for (int i = 0;i < 3;i++)
	{
		cout << "firma [" << i + 1 << "]=";

		cout << f_firma[i] << endl;
	}
	delete[]f_firma;


	//fisiere text 
	ofstream m("Firma.txt", ios::out);
	m << firma3;
	m.close();

	ifstream n("Firma.txt", ios::in);
	n >> firma2;
	cout << firma2;
	n.close();

	Firma firma11;
	fstream w("Firma.bin", ios::out | ios::binary);//ap fis binare 
	w.write((char*)&firma11, sizeof(Firma));
	w.close();
	fstream z("Firma.bin", ios::in | ios::binary);
	z.read((char*)&firma11, sizeof(Firma));
	z.close();

    
	

     cout << endl << "~~ has a ~~ " << endl;
	Colaborator client1;//

	cout << client1;
	Colaborator client2(3);
	cout << client2;
	client2.setNumeColaborator(" Ikea ");
	client2.setVechime(5);
	cout << "get pt nume: "<< client2.getNumeColaborator()<<endl<<"get pt vechime : " << client2.getVechime() << endl;
	/*cout << *client2.getFirma();*/
	cout << client2 <<endl;
	
	Colaborator client3(8);
	Colaborator client4;
	cout <<client4 <<endl<< client3;
	cout << endl << "Operator + " << endl;
	client4.setNumeColaborator("Leroy Merlin");
	client4.getNumeColaborator();
	client4 = client3 + client2;
	cout << client4;
	cout << " ";
	FirmaAsigurata fa1;
	cout <<" Prima firma asigurata este:"<< fa1<<endl;
	FirmaAsigurata fa2(fa1);//operatro copiere
	cout <<" A doua firma asigurata este: "<< fa2<<endl;
	FirmaAsigurata fa3(" Taxim", 36, 800);
	cout << "A treia firma asigurata este: " << fa3<<endl;
	fa3 = fa1;//operatro=
	cout << " Firma actualizata este: " << fa3 << endl;

	fa1.setNumeFirmaAsig("SAVCOM");
	cout << " Noul nume al primei firme asigurate este: " << fa1.getNume() << endl;
	fa2.setPerioadaAsigurare(36);
	cout << " Noua perioada de asigurare a firmei2 este de " << fa2.getPerioadaAsigurare() << " luni " << endl;
	fa3.setPretAsigurare(2300);
		cout << " Noul pret de asigurare al firmei 3 este de " << fa3.getPretAsigurare()<<" lei" << endl;



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

	SalariuInvatamant s1;
	SalariuInvatamant s2;
	SalariuInvatamant  s3;
	SalariuInvatamant* s_salariu = new SalariuInvatamant[3];//vector de 3 obiecte;
	s_salariu[0] = s1;
	s_salariu[1] = s2;
	s_salariu[2] = s3;
	cout << " Vector de obiecte  salariu " << endl;
	for (int i = 0;i < 3;i++)
	{
		cout << "salariu [" << i + 1 << "]=";

		cout << s_salariu[i] << endl;
	}
	delete[]s_salariu;




};
