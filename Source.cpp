
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#pragma warning (disable: 4996)

using namespace std;

class Comanda {
private:
	const int idComanda;
	string numeClient;
	int nrProduse;
	string* denumireProduse;
	float* cantitatiProduse;
public:

	//Constructor fara parametrii
	Comanda() : idComanda(0) {
		this->numeClient = "Anonim";
		this->nrProduse = 0;
		this->denumireProduse = NULL;
		this->cantitatiProduse = NULL;
	}
	//Constructor cu toti parametrii
	Comanda(const int idComanda, string numeClient, int nrProduse, string* denumireProduse, float* cantitatiProduse) :idComanda(idComanda) {
		this->numeClient = numeClient;
		this->nrProduse = nrProduse;
		this->denumireProduse = new string[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++)
			this->denumireProduse[i] = denumireProduse[i];
			
		this->cantitatiProduse = new float[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++)
			this->cantitatiProduse[i] = cantitatiProduse[i];
	}
	//getter
	string getNumeClient() {
		return this->numeClient;
	}
	//setter
	void setNumeClient(string numeClient) {
		this->numeClient = numeClient;
	}
	//Destructor
	~Comanda() {
		if (this->cantitatiProduse != NULL) {
			delete[]this->cantitatiProduse;
		}
		if (this->denumireProduse != NULL) {
			delete[]this->denumireProduse;
		}
	}
	//Constructor de copiere
	Comanda(const Comanda& c) : idComanda(c.idComanda) {
		this->numeClient = c.numeClient;
		this->nrProduse = c.nrProduse;
		this->denumireProduse = new string[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++)
			this->denumireProduse[i] = c.denumireProduse[i];

		this->cantitatiProduse = new float[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++)
			this->cantitatiProduse[i] = c.cantitatiProduse[i];
	}
	//Operator =
	Comanda& operator=(const Comanda& c) {
		if (this != &c) {
			if (this->cantitatiProduse != NULL) {
				delete[]this->cantitatiProduse;
			}
			if (this->denumireProduse != NULL) {
				delete[]this->denumireProduse;
			}
			this->numeClient = c.numeClient;
			this->nrProduse = c.nrProduse;
			this->denumireProduse = new string[this->nrProduse];
			for (int i = 0; i < this->nrProduse; i++)
				this->denumireProduse[i] = c.denumireProduse[i];

			this->cantitatiProduse = new float[this->nrProduse];
			for (int i = 0; i < this->nrProduse; i++)
				this->cantitatiProduse[i] = c.cantitatiProduse[i];
			}
		return *this;
	}
	//Operator de afisare<<
	friend ostream& operator<<(ostream& out, const Comanda& c) {
		out << "idComanda" << c.idComanda << endl;
		out << "numeClient" << c.numeClient << endl;
		out << "nrProduse" << c.nrProduse << endl;
		for (int i = 0; i < c.nrProduse; i++) {
			out << "deumireProduse" << c.denumireProduse[i] << endl;
		}
		for (int i = 0; i < c.nrProduse; i++) {
			out << "cantitatiProduse" << c.cantitatiProduse[i] << endl;
		}
		return out;

	}

	//Operator []
	string& operator[](int poz) {
		if (poz >= 0 && poz < this->nrProduse) {
			return this->denumireProduse[poz];
		}
		else {
			string mesaj = "Nu e produs";
			return mesaj;
		}
	}
	//Operator +=
	Comanda& operator+=(string denumireProdus) {
		bool gasit = 0;
		int pozEl = 0;
		for (int i = 0; i < this->nrProduse; i++) {
			if (this->denumireProduse[i] == denumireProdus) {
				gasit = 1;
				pozEl = i;
			}
				if (gasit == 1) {
					this->cantitatiProduse[i]++;
				}
				else{
					Comanda aux = *this;
					if (this->cantitatiProduse != NULL) {
						delete[]this->cantitatiProduse;
					}
					if (this->denumireProduse != NULL) {
						delete[]this->denumireProduse;
					}
					this->numeClient = aux.numeClient;
					this->nrProduse = aux.nrProduse;
					this->denumireProduse = new string[this->nrProduse];
					for (int i = 0; i < this->nrProduse; i++)
						this->denumireProduse[i] = aux.denumireProduse[i];

					this->cantitatiProduse = new float[this->nrProduse];
					for (int i = 0; i < this->nrProduse; i++)
						this->cantitatiProduse[i] = aux.cantitatiProduse[i];
					this->denumireProduse[this->nrProduse - 1] = denumireProdus;
					this->cantitatiProduse[this->nrProduse] = 2;
				}
			}
		return *this;
	
		}
		
};

int main() {
	cout << "Constructor fara parametrii" << endl;
	
	Comanda c;
	cout << c.getNumeClient() << endl;
	c.setNumeClient("Popescu Ion");
	cout << c.getNumeClient() << endl;

	cout << "Constructor cu parametrii" << endl;

	string denumireProd[] = {"Cafea","Zahar","Lapte","Paine","Ciocolata"};
	float cantitatiProd[] = {2,7.5,6.1,5,3.4};
	Comanda c1(10,"Ionescu Dan", 3, denumireProd,cantitatiProd);
	cout << c1.getNumeClient() << endl;

	cout << "Constructor de copiere" << endl;
	Comanda c2(c);

	cout << "Operator <<" << endl;
	cout << c2 << endl;

	cout << "Operator []" << endl;
	cout << c2[3];

	cout << "Operator +=" << endl;
	c2 += "Sarmale";
	cout << c2 << endl;
}


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

class Casa {
private:
	static bool auElectricitate;
	int nrCamere;
	char* adresa;
	float suprafata;
	int anConstructie;

public:
	Casa() {
		this->adresa = new char[strlen("?")+1];
		strcpy(this->adresa, "?");
		this->nrCamere = 0;
		this->suprafata = 0;
		this->anConstructie = 2000;
	}

	int getNrCamere() {
		return this->nrCamere;
	}

	void setNrCamere(int nrCamere) {
		this->nrCamere = nrCamere;
	}

	Casa(const char* adresa, int nrCamere, float suprafata, int anConstructie) {
		this->adresa = new char[strlen(adresa) + 1];
		strcpy(this->adresa, adresa);
		this->nrCamere = nrCamere;
		this->suprafata = suprafata;
		this->anConstructie = anConstructie;
	}

	Casa(const Casa &c) {
		this->adresa = new char[strlen(c.adresa) + 1];
		strcpy(this->adresa, c.adresa);
		this->nrCamere = c.nrCamere;
		this->suprafata = c.suprafata;
		this->anConstructie = c.anConstructie;
	}

	~Casa() {
		if (this->adresa != NULL) {
			delete[]this->adresa;
		}

	}

	Casa& operator=(const Casa& c) {
		if (this != &c) {
			if (this->adresa != NULL) {
				delete[]this->adresa;
			}
			this->adresa = new char[strlen(c.adresa) + 1];
			strcpy(this->adresa, c.adresa);
			this->nrCamere = c.nrCamere;
			this->suprafata = c.suprafata;
			this->anConstructie = c.anConstructie;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Casa& c) {
		out << c.adresa << endl;
		out << c.nrCamere << endl;
		out << c.suprafata << endl;
		out << c.anConstructie << endl;
		out << c.auElectricitate << endl;
		return out;
	} 

	friend istream& operator>>(istream& in, const Casa& c) {
		cout << "Adresa"<<endl;
		in >> c.adresa;
		return in;
	}

	bool operator()(int nrPersoane) {
		return this->nrCamere >= nrPersoane;
	}

	bool operator==(Casa c) {
		return (strcmpi(this->adresa, c.adresa) == 0 && this->nrCamere == c.nrCamere
			&& this->suprafata == c.suprafata && this->anConstructie == c.anConstructie);
	}

	bool operator !=(Casa c) {
		return !(*this == c);
	}
};

bool Casa::auElectricitate = true;

int main() {
	Casa c;
	cout << c.getNrCamere() << endl;
	c.setNrCamere(4);
	cout << c.getNrCamere() << endl;
	Casa c1("Str Teiul", 4, 500, 2012);
	cout << c1 << endl;
	Casa c2 = c;
	cout << c2 << endl;
	cout << c2(3) << endl;

	if (c2(3)) {
		cout << "Fiecare pers are camera ei"<<endl;
	}
	else {
		cout << "Fiecare pers nu are camera ei"<<endl;
	}

	if (c1 == c) {
		cout << "Casele sunt identice"<<endl;
	}
	else {
		cout << "Casele sunt diferite"<<endl;
	}

	if (c1 == c2) {
		cout << "Casele sunt identice" << endl;
	}
	else {
		cout << "Casele sunt diferite" << endl;
	}

}
