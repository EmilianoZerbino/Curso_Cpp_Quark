#pragma once
#include "View.h"
#include "Library.h"
#include "Member.h"
#include "VipMember.h"
#include "Book.h"
#include "IView.h"

class Presenter
{

public:

	Presenter();
	void PrecargarDatos();
	void excute();

private:

	View view;
	Library library;
};

