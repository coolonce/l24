#include "Calculate.h"


namespace Project1 {

	
	Calculate::Calculate(List<array<String^>^>^ table)
	{
		this->table = table;
	}
	void Calculate::work() {
		List<array<String^>^>^ table = Calculate::table;
		List<array<double>^>^ table_double = gcnew List<array<double>^>();

		Dictionary<String^, double>^ fuel_codes = gcnew Dictionary<String^, double>();
		double j = 0;
		for each (array<String^>^ row in table)
		{
			if (row[1] == "mark") {
				continue;
			}
			try
			{
				fuel_codes->Add(row[1], j);
				j++;
			}
			catch (ArgumentException^)
			{
				continue;
			}
		}


		Calculate::fuel_codes = fuel_codes;


		List<double>^ mileage = gcnew List<double>();
		int i = 0;
		for each (array<String^>^ row in table)
		{
			if (i == 0) {
				i++;
				continue;
			}
			array<String^>^ prevRow = table[i - 1];
			double day = DiffDay(i == 1 ? "" : prevRow[0], row[0]);
			Trace::WriteLine(row[2]);
			array<double>^ tmp = {
				day,
				fuel_codes[row[1]],
				System::Convert::ToDouble(row[2]),
				System::Convert::ToDouble(row[3]),
				System::Convert::ToDouble(row[4]),
				System::Convert::ToDouble(row[5]),
			};
			table_double->Add(tmp);
			//mileage->Add(System::Convert::ToDouble(row[2]));
			i++;
		}

		/*table_double = toAvgRoll(table_double, 2);
		table_double = toAvgRoll(table_double, 3);
		table_double = toAvgRoll(table_double, 4);
		table_double = toAvgRoll(table_double, 5);*/
		Calculate::table_prepare = table_double;
		//List<double>^ rollAvgMileage = getMA(mileage, mileage->Count, 2);
	}

	Dictionary<String^, array<double>^>^  Calculate::getAvgMarkFuel(List<array<double>^>^ data, Dictionary<String^, double>^ fuel_dict) {

		Dictionary<String^, array<double>^>^ prepData = gcnew Dictionary<String^, array<double>^>();

		for each (auto fuel_mark in fuel_dict)
		{
			int count_mrk = 0;
			double price_gallon = 0;
			double count_gallon = 0;
			double summ = 0;
			for each (array<double>^ row in data)
			{
				if (row[1] == fuel_mark.Value) {
					count_mrk++;
					price_gallon += row[3];
					count_gallon += row[4];
					summ += row[5];
				}
			}
			price_gallon = price_gallon / count_mrk;
			count_gallon = count_gallon / count_mrk;
			summ = summ / count_mrk;
			array<double>^ tmp = {
				round(price_gallon * 100) / 100,
				round(count_gallon * 100) / 100,
				round(summ * 100) / 100
			};

			prepData->Add(fuel_mark.Key, tmp);
		}
		return prepData;
	}

	List<array<double>^>^  Calculate::getPrepareData(List<array<double>^>^ data) {
		List<array<double>^>^ prepData = gcnew List<array<double>^>();
		int i = 0;
		for each (array<double>^ row in data)
		{
			double prevMileage = 0;

			if (i - 1 >= 0)
			{
				array<double>^ prewRow = data[i - 1];
				prevMileage = prewRow[2];
			}
			double diff_mileage = row[2] - prevMileage; // пробег между заправками
			if (i - 1 < 0) diff_mileage = 0;
			double mileageInGallon = diff_mileage / row[4]; // пробега на 1 галлон
			double priceMileage = diff_mileage / row[5]; // стоимость 1 мили 
			double priceDay = row[0] / row[5]; //Стоимость 1 дня
			double consumptionGallon = row[4] / row[0]; //Время расходывания одного галона
			if (consumptionGallon == INFINITY) consumptionGallon = 0;
			array<double>^ tmp = {
				round(diff_mileage * 100) / 100,
				round(mileageInGallon * 100) / 100,
				round(priceMileage * 100) / 100,
				round(priceDay * 100) / 100,
				round(consumptionGallon * 100) / 100
			};
			prepData->Add(tmp);
			i++;
		}
		return prepData;
	}

	List<array<double>^>^ Calculate::toAvgRoll(List<array<double>^>^ data, int workIndex)
	{
		List<double>^ tmp = gcnew List<double>();
		for each (array<double>^ row in data)
		{
			tmp->Add(row[workIndex]);
		}
		List<double>^ rollAvgTmp = getMA(tmp, tmp->Count, 2);

		/*for (size_t i = 0; i < rollAvgMileage->Count; i++)
		{
			data.
			data[i][workIndex] = rollAvgMileage[i];
		}*/
		int i = 0;
		for each (array<double>^ row in data)
		{
			row[workIndex] = rollAvgTmp[i];
			i++;
		}
		return data;
	}

	List<double>^ Calculate::getMA(List<double>^ x, int n, int size) {
		// size - количество отсчетов интервала усреднения
		double sumx = 0; // сумма отсчетов на интервале
		//double *mas; // массив для хранения size отсчетов
		List<double>^ mas = gcnew List<double>(size);
		List<double>^ ret = gcnew List<double>();

		int index = 0; // индекс элемента массива
		//mas = new double[size];
		for (int i = 0; i<size; i++) mas->Add(0);

		for (int i = 0; i<n; i++) {
			sumx -= mas[index];
			mas[index] = x[i];
			sumx += mas[index];
			index++;
			if (index >= size)
				index = 0; // возврат к началу "окна"
			ret->Add(sumx / size);
		}

		return ret;
	}


	double Calculate::DiffDay(String^ date1, String^ date2) {

		if (date1 == ""|| date2 == "") return 0;

		DateTime startTime = DateTime(1970, 1, 1, 0, 0, 0);
		double oneDay = 86400;

		DateTime dt1 = DateTime();
		dt1 = DateTime::Parse(date1);

		TimeSpan _UnixTimeSpan = (dt1 - startTime);

		DateTime dt2 = DateTime();
		dt2 = DateTime::Parse(date2);

		TimeSpan _UnixTimeSpan2 = (dt2 - startTime);

		double diff = _UnixTimeSpan2.TotalSeconds - _UnixTimeSpan.TotalSeconds;

		return diff / oneDay;
	}



}