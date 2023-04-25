#include "Borrow.h"

#include <ctime>


Borrow::Borrow(Member member, Edition edition) : member(member), edition(edition)
{
	this->member = member;
	this->edition = edition;
	this->devolution = false;
	this->dateOfBorrow = calculateDateAndTime();
}

Member Borrow::getMember()
{
	return member;
}

Edition Borrow::getEdition()
{
	return edition;
}

string Borrow::getDateOfBorrow()
{
	return dateOfBorrow;
}

string Borrow::getDateOfDevolution()
{
	return dateOfDevolution;
}

bool Borrow::getDevolution()
{
	return devolution;
}

void Borrow::setDevolution(bool state)
{
	devolution = state;
	this->dateOfDevolution = calculateDateAndTime();
}

string Borrow::calculateDateAndTime()
{
	time_t tiempo = time(nullptr);
	tm fechaHora;
	localtime_s(&fechaHora, &tiempo);
	string hora;
	string minutos;
	if (fechaHora.tm_hour < 10) {
		hora = "0" + to_string(fechaHora.tm_hour);
	}
	else {
		hora = to_string(fechaHora.tm_hour);
	}
	if (fechaHora.tm_min < 10) {
		minutos = "0" + to_string(fechaHora.tm_min);
	}
	else {
		minutos = to_string(fechaHora.tm_min);
	}
	string resultado = (to_string(fechaHora.tm_mday) + "/" + to_string(fechaHora.tm_mon + 1) + "/" + to_string(fechaHora.tm_year + 1900) + "  " + hora + ":" + minutos);
	return resultado;
}
