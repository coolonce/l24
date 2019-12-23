#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;
ref class OpenFiles : public System::Windows::Forms::Form
{
public:
	OpenFiles();
	void Write(System::String^ filename, List<array<double>^>^  preparedate);
};

