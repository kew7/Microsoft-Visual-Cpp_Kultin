// Exam.cpp: главный файл проекта.

#include "stdafx.h"
#include "Form1.h"

using namespace Exam;

//using namespace System::IO; 



[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Включение визуальных эффектов Windows XP до создания каких-либо элементов управления
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 


    String^ fpath;
	String^ fname;

    // проверим, указано ли имя файла теста
	if (args->Length > 0)
    {
             // указано только имя файла теста
             if (args[0]->IndexOf(":") == -1)
			 {
				 fpath = Application::StartupPath + "\\";
                 fname = args[0];
			 }
              
             else
             {
				// указано полное имя файла теста
				fpath =
					args[0]->Substring(0,args[0]->LastIndexOf("\\")+1);
				fname =
					args[0]->Substring(args[0]->LastIndexOf("\\")+1);
			 }


        
        // проверим, существует ли указанный файл
			 if ( System::IO::FileInfo( fpath->ToString() +fname->ToString() ).Exists )
		{
			// Создание главного окна и его запуск
			Application::Run(gcnew Form1(fpath,fname));
			return 0;
		}
		else
		{
			MessageBox::Show(
				"Не правильно указано имя файла теста          \n"+
				"(нет папки или файла в указанной папке).\n" +
				fpath->ToString() + fname->ToString(),
		  "Экзаменатор",
		  MessageBoxButtons::OK,
		  MessageBoxIcon::Stop);
		  return -1;
		}

	}
	else
	{
  
		MessageBox::Show(
          "Файл теста необходимо указать " +
          "в команде запуска программы.\n" +
          "Например: 'exam economics.xml' " +
          "или 'exam c:\\spb.xml'.",
		  "Экзаменатор",
		  MessageBoxButtons::OK,
		  MessageBoxIcon::Stop);
		  return -1;
  

	}
}
