#pragma once
#include <vector>
using namespace System;
using namespace System::IO;
using namespace System::Diagnostics;
using namespace System::Collections::Generic;
using namespace System::Collections;
namespace Project1 {
	ref class Calculate
	{
	public:
		List<array<String^>^>^ table;
		List<array<double>^>^ table_prepare;
		Dictionary<String^, double>^ fuel_codes;
		Calculate(List<array<String^>^>^ table);
		void work();
		Dictionary<String^, array<double>^>^ getAvgMarkFuel(List<array<double>^>^ data, Dictionary<String^, double>^ fuel_dict);
		List<array<double>^>^ getPrepareData(List<array<double>^>^ data);
		List<array<double>^>^ toAvgRoll(List<array<double>^>^ data, int workIndex);
		List<double>^ getMA(List<double>^ x, int n, int size);
		double DiffDay(String^ date1, String^ date2);
		//List<double>^ getMA(List<double> x, int n, int size);
	};

}