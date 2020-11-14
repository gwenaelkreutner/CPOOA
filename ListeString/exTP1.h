#pragma once

#include <iostream>
using namespace std;

#include <string.h>

/**
Classe destinée à gérer les exceptions du TP1
*/
class exTP1
{
	char * _msg;	// message de l'exception

public:
	/**
	Construction de l'exception avec son message
	*/
	exTP1 (const char *msg) :
		_msg (strdup (msg))
	{}

	/**
	Constructeur par recopie
	*/
	exTP1  (const exTP1 &e)
	{
		_msg = strdup (e._msg);
	}

	/**
	Destructeur
	*/
	virtual ~exTP1(void)
	{
		delete (_msg);
	}

	/**
	Getter pour accéder au message
	*/
	const char *  getMsg () const { return _msg; }

	/**
	Opérateur d'affectation (obligatoire car données dynamiques)
	*/
	const exTP1 & operator = (const exTP1 &e)
	{
		if (this != &e)
		{
			delete (_msg);
			_msg = strdup (e._msg);
		}
		return *this;
	}
};

/**
Fonction de surcharge pour l'affichage <<
*/
extern ostream & operator << (ostream &s, const exTP1 &e);

