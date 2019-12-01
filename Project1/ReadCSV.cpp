#include "ReadCSV.h"

namespace Project1 {
	ReadCSV::ReadCSV()
	{
		/*this->filepath = filepath;
		this->OpenFile;*/
	}

	List<array<String^>^>^ ReadCSV::OpenFile(System::String^ filepath, char sep) {
		//try {
			//System::IO::StreamReader
		System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(filepath);
		List<array<String^>^>^ table = gcnew List<array<String^>^>();
		while (sr->Peek() > -1)
		{
			array<String^>^ words;
			String^ str = sr->ReadLine();
			//Trace::WriteLine(str);
			words = str->Split(sep);
			table->Add(words);
		}
		sr->Close();
		return table;
	}

	ReadCSV::~ReadCSV()
	{

	}
}