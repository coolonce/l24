#pragma once
#include "ReadCSV.h"
#include "Calculate.h"
#include <locale>
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	public:
		List<array<String^>^>^ table;
		Dictionary<String^, array<double>^>^  dataMarkFuel;
		List<array<double>^>^  preparedate;
		MyForm(void)
		{
			InitializeComponent();
			
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button1;
	
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::DataGridView^  SourceDataGrid;
	private: System::Windows::Forms::DataGridView^  PrepDataView;
	private: System::Windows::Forms::DataGridView^  MarkData;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TextBox^  textBoxDate;
	private: System::Windows::Forms::TextBox^  textBoxMark;
	private: System::Windows::Forms::TextBox^  textBoxMileage;
	private: System::Windows::Forms::TextBox^  textBoxPrice;
	private: System::Windows::Forms::TextBox^  textBoxCount;



	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBoxSum;
	private: System::Windows::Forms::Button^  buttonAddRow;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SourceDataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->PrepDataView = (gcnew System::Windows::Forms::DataGridView());
			this->MarkData = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBoxDate = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMark = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMileage = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPrice = (gcnew System::Windows::Forms::TextBox());
			this->textBoxCount = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBoxSum = (gcnew System::Windows::Forms::TextBox());
			this->buttonAddRow = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SourceDataGrid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PrepDataView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MarkData))->BeginInit();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(264, 7);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(116, 32);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Загрузить файл";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(12, 12);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(236, 22);
			this->textBox2->TabIndex = 2;
			// 
			// SourceDataGrid
			// 
			this->SourceDataGrid->AllowUserToAddRows = false;
			this->SourceDataGrid->AllowUserToDeleteRows = false;
			this->SourceDataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->SourceDataGrid->Location = System::Drawing::Point(12, 161);
			this->SourceDataGrid->Name = L"SourceDataGrid";
			this->SourceDataGrid->ReadOnly = true;
			this->SourceDataGrid->RowTemplate->Height = 24;
			this->SourceDataGrid->Size = System::Drawing::Size(741, 328);
			this->SourceDataGrid->TabIndex = 3;
			// 
			// PrepDataView
			// 
			this->PrepDataView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->PrepDataView->Location = System::Drawing::Point(12, 610);
			this->PrepDataView->Name = L"PrepDataView";
			this->PrepDataView->RowTemplate->Height = 24;
			this->PrepDataView->Size = System::Drawing::Size(741, 288);
			this->PrepDataView->TabIndex = 4;
			// 
			// MarkData
			// 
			this->MarkData->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->MarkData->Location = System::Drawing::Point(779, 161);
			this->MarkData->Name = L"MarkData";
			this->MarkData->RowTemplate->Height = 24;
			this->MarkData->Size = System::Drawing::Size(433, 737);
			this->MarkData->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 141);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(127, 17);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Исходные данные";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 587);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(162, 17);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Обработанные данные";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(776, 141);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(193, 17);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Данные по маркам бензина";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 904);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(236, 57);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Сохранить обработанные файлы";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(779, 904);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(293, 57);
			this->button3->TabIndex = 10;
			this->button3->Text = L"Сохранить данные по маркам бензина";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(12, 495);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(213, 50);
			this->button4->TabIndex = 11;
			this->button4->Text = L"Сохранить исходные данные";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// textBoxDate
			// 
			this->textBoxDate->Location = System::Drawing::Point(12, 92);
			this->textBoxDate->Name = L"textBoxDate";
			this->textBoxDate->Size = System::Drawing::Size(127, 22);
			this->textBoxDate->TabIndex = 12;
			// 
			// textBoxMark
			// 
			this->textBoxMark->Location = System::Drawing::Point(145, 92);
			this->textBoxMark->Name = L"textBoxMark";
			this->textBoxMark->Size = System::Drawing::Size(124, 22);
			this->textBoxMark->TabIndex = 13;
			// 
			// textBoxMileage
			// 
			this->textBoxMileage->Location = System::Drawing::Point(275, 92);
			this->textBoxMileage->Name = L"textBoxMileage";
			this->textBoxMileage->Size = System::Drawing::Size(121, 22);
			this->textBoxMileage->TabIndex = 14;
			// 
			// textBoxPrice
			// 
			this->textBoxPrice->Location = System::Drawing::Point(402, 92);
			this->textBoxPrice->Name = L"textBoxPrice";
			this->textBoxPrice->Size = System::Drawing::Size(121, 22);
			this->textBoxPrice->TabIndex = 15;
			// 
			// textBoxCount
			// 
			this->textBoxCount->Location = System::Drawing::Point(529, 92);
			this->textBoxCount->Name = L"textBoxCount";
			this->textBoxCount->Size = System::Drawing::Size(121, 22);
			this->textBoxCount->TabIndex = 16;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 63);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(42, 17);
			this->label4->TabIndex = 17;
			this->label4->Text = L"Дата";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(142, 63);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(109, 17);
			this->label5->TabIndex = 18;
			this->label5->Text = L"Марка бензина";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(278, 63);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(102, 17);
			this->label6->TabIndex = 19;
			this->label6->Text = L"Пробег (мили)";
			// 
			// label7
			// 
			this->label7->Location = System::Drawing::Point(402, 41);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(121, 47);
			this->label7->TabIndex = 20;
			this->label7->Text = L"Цена галлона (центы)";
			this->label7->Click += gcnew System::EventHandler(this, &MyForm::label7_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(526, 54);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(117, 17);
			this->label8->TabIndex = 21;
			this->label8->Text = L"Кол-во галлонов";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(653, 54);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(50, 17);
			this->label9->TabIndex = 22;
			this->label9->Text = L"Сумма";
			// 
			// textBoxSum
			// 
			this->textBoxSum->Location = System::Drawing::Point(656, 92);
			this->textBoxSum->Name = L"textBoxSum";
			this->textBoxSum->Size = System::Drawing::Size(121, 22);
			this->textBoxSum->TabIndex = 23;
			// 
			// buttonAddRow
			// 
			this->buttonAddRow->Location = System::Drawing::Point(783, 85);
			this->buttonAddRow->Name = L"buttonAddRow";
			this->buttonAddRow->Size = System::Drawing::Size(186, 37);
			this->buttonAddRow->TabIndex = 24;
			this->buttonAddRow->Text = L"Добавить данные";
			this->buttonAddRow->UseVisualStyleBackColor = true;
			this->buttonAddRow->Click += gcnew System::EventHandler(this, &MyForm::buttonAddRow_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1224, 1056);
			this->Controls->Add(this->buttonAddRow);
			this->Controls->Add(this->textBoxSum);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBoxCount);
			this->Controls->Add(this->textBoxPrice);
			this->Controls->Add(this->textBoxMileage);
			this->Controls->Add(this->textBoxMark);
			this->Controls->Add(this->textBoxDate);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->MarkData);
			this->Controls->Add(this->PrepDataView);
			this->Controls->Add(this->SourceDataGrid);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"Бензин";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SourceDataGrid))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PrepDataView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MarkData))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			
			if (this->openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				System::String^ filepath = this->openFileDialog1->FileName;
				this->textBox2->Text = filepath;
				
				ReadCSV csv;
				//List<array<String^>^>^ table = csv.OpenFile(filepath->ToString(), ';');
				this->table = csv.OpenFile(filepath->ToString(), ';');
				//this->textBox1->Text = System::IO::File::ReadAllText(this->textBox2->Text);
				this->render();

				
				
			}
		}
	private: System::Void label7_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: void render() {

		Calculate clc(this->table);
		clc.work();
		this->dataMarkFuel = clc.getAvgMarkFuel(clc.table_prepare, clc.fuel_codes);
		preparedate = clc.getPrepareData(clc.table_prepare);
		//SourceDataGrid->DataSource = table->ToArray();

		array<String^>^ headers = this->table[0];
		SourceDataGrid->Rows->Clear();
		for each (array<String^>^ row in this->table)
		{
			if (row[0] == "date")
			{
				SourceDataGrid->ColumnCount = row->Length;
				for (int i = 0; i < row->Length; i++)
				{

					SourceDataGrid->Columns[i]->Name = row[i];
					//SourceDataGrid->Columns[i].Name = row[i];
				}
				continue;
			}
			array<String^>^ tmp = {
				row[0],
				row[1],
				row[2],
				row[3],
				row[4],
				row[5],
			};
			SourceDataGrid->Rows->Add(tmp);
		}

		PrepDataView->ColumnCount = 5;
		PrepDataView->Columns[0]->Name = "Пробег между заправками";
		PrepDataView->Columns[1]->Name = "Пробег на 1 галон";
		PrepDataView->Columns[2]->Name = "Стоимость пробега в одну милю";
		PrepDataView->Columns[3]->Name = "Стоимость одного дня";
		PrepDataView->Columns[4]->Name = "Время расходывания одного галлона";
		PrepDataView->Rows->Clear();
		for each (array<double>^ row in preparedate)
		{
			array<double^>^ tmp = {
				row[0],
				row[1],
				row[2],
				row[3],
				row[4],
			};
			PrepDataView->Rows->Add(tmp);
		}

		
		MarkData->ColumnCount = 4;
		MarkData->Columns[0]->Name = "Марка бензина";
		MarkData->Columns[1]->Name = "Цена галлона в центах";
		MarkData->Columns[2]->Name = "Кол-во галлонов";
		MarkData->Columns[3]->Name = "Сумма";
		MarkData->Rows->Clear();
		for each (auto marks in this->dataMarkFuel)
		{


			array<String^>^ tmp = {
				marks.Key,
				marks.Value[0].ToString(),
				marks.Value[1].ToString(),
				marks.Value[2].ToString(),
			};
			MarkData->Rows->Add(tmp);
		}
	}

	private: bool validate() {
//		System::Convert::ToDouble(row[2])
		int countGood = 6;
		try
		{
			DateTime::Parse(textBoxDate->Text);
		}
		catch (System::FormatException ^ e)
		{
			textBoxDate->BackColor = Color::FromName("Red");
			countGood--;
		}
		double tmp;
		if (!(Double::TryParse(textBoxMileage->Text, tmp))) {
			textBoxMark->BackColor = Color::FromName("Red");
			countGood--;
		}
		if (!(Double::TryParse(textBoxMileage->Text, tmp))) {
			textBoxMileage->BackColor = Color::FromName("Red");
			countGood--;
		}
		if (!(Double::TryParse(textBoxPrice->Text, tmp))) {
			textBoxPrice->BackColor = Color::FromName("Red");
			countGood--;
		}
		if (!(Double::TryParse(textBoxCount->Text, tmp))) {
			textBoxCount->BackColor = Color::FromName("Red");
			countGood--;
		}

		if (!(Double::TryParse(textBoxSum->Text, tmp))) {
			textBoxSum->BackColor = Color::FromName("Red");
			countGood--;
		}		
		if (table == nullptr) {
			MessageBox::Show("Необходимо загрузить основной файл данных");
			countGood--;
		}
		return countGood == 6;
	}
	private: System::Void buttonAddRow_Click(System::Object^  sender, System::EventArgs^  e) {
		bool correctValid = this->validate();
		if (!correctValid)
			return;

		array<String^>^ tmp = {
			textBoxDate->Text,
			textBoxMark->Text,
			textBoxMileage->Text,
			textBoxPrice->Text,
			textBoxCount->Text,
			textBoxSum->Text,
		};
		table->Add(tmp);
		this->render();
	}

	

	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		SaveFileDialog^ sfd = gcnew SaveFileDialog();
		if (table == nullptr) {
			MessageBox::Show("Нет данных для сохранения");
			return;
		}
		try
		{
			sfd->Filter = "SourceData|*.csv";
			sfd->FileName = "Source Data";
			sfd->Title = "Save Source Data";
			if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{

				String^ path = sfd->FileName;
				StreamWriter^ writer = gcnew StreamWriter(File::Create(path));
				try
				{
					
					for each (array<String^>^ row in table)
					{						
						String^ saveStr = "";
						for each (auto field in row)
						{
							saveStr += field + ";";
						}
						writer->Write(saveStr + "\t\r\n");
					}
					
				}
				finally
				{
					delete writer;
				}
			}
		}
		finally
		{
			delete sfd;
		}
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		SaveFileDialog^ sfd = gcnew SaveFileDialog();
		if (preparedate == nullptr) {
			MessageBox::Show("Нет данных для сохранения");
			return;
		}
		try
		{
			sfd->Filter = "PrepareDate|*.csv";
			sfd->FileName = "Prepare Date";
			sfd->Title = "Save Prepare Date";
			if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{

				String^ path = sfd->FileName;
				StreamWriter^ writer = gcnew StreamWriter(File::Create(path));
				try
				{
					writer->Write(L"Пробег между заправками;Пробег на 1 галон;Стоимость пробега в одну милю;Стоимость одного дня;Время расходывания одного галлона\t\r\n");
					
					PrepDataView->Rows->Clear();
					for each (array<double>^ row in preparedate)
					{

						String^ saveStr = "";
						for each (auto field in row)
						{
							saveStr += field + ";";
						}
						writer->Write(saveStr + "\t\r\n");
						
					}

				}
				finally
				{
					delete writer;
				}
			}
		}
		finally
		{
			delete sfd;
		}
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		SaveFileDialog^ sfd = gcnew SaveFileDialog();
		if (dataMarkFuel == nullptr) {
			MessageBox::Show("Нет данных для сохранения");
			return;
		}
		try
		{
			sfd->Filter = "MarkFuel|*.csv";
			sfd->FileName = "Mark Fuel";
			sfd->Title = "Save Mark Fuel";
			if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{

				String^ path = sfd->FileName;
				StreamWriter^ writer = gcnew StreamWriter(File::Create(path));
				try
				{

					

					String^ str = "Марка бензина;Цена галлона в центах;Кол-во галлонов;Сумма\t\r\n";
					writer->Write(str);



					for each (auto row in dataMarkFuel)
					{
						String^ saveStr = "";
						saveStr += row.Key;
						saveStr += row.Value[0].ToString(),
						saveStr += row.Value[1].ToString(),
						saveStr += row.Value[2].ToString(),
						writer->Write(saveStr + "\t\r\n");
					}

				}
				finally
				{
					delete writer;
				}
			}
		}
		finally
		{
			delete sfd;
		}
	}
};
}
