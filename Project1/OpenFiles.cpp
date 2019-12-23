#include "OpenFiles.h"



OpenFiles::OpenFiles()
{
	
}

void OpenFiles::Write(System::String ^ filename, List<array<double>^>^ preparedate)
{
	using namespace System::Windows::Forms;
	using namespace System::IO;
	SaveFileDialog^ sfd = gcnew SaveFileDialog();
	if (preparedate == nullptr) {
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
