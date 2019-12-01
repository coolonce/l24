#pragma once
#include <istream>
#include <string>
#include <vector>
#include <fstream>
#include<iostream>
#include <map>
using namespace System;
using namespace System::IO;
using namespace System::Diagnostics;
using namespace System::Collections::Generic;
namespace Project1 {
	
	class ReadCSV
	{

	public:
		std::string filepath;
		ReadCSV();
		List<array<String^>^>^ OpenFile(System::String^ filepath, char sep);
		~ReadCSV();
	};
}
