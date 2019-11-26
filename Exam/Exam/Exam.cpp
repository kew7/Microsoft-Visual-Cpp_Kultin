// Exam.cpp: ������� ���� �������.

#include "stdafx.h"
#include "Form1.h"

using namespace Exam;

//using namespace System::IO; 



[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// ��������� ���������� �������� Windows XP �� �������� �����-���� ��������� ����������
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 


    String^ fpath;
	String^ fname;

    // ��������, ������� �� ��� ����� �����
	if (args->Length > 0)
    {
             // ������� ������ ��� ����� �����
             if (args[0]->IndexOf(":") == -1)
			 {
				 fpath = Application::StartupPath + "\\";
                 fname = args[0];
			 }
              
             else
             {
				// ������� ������ ��� ����� �����
				fpath =
					args[0]->Substring(0,args[0]->LastIndexOf("\\")+1);
				fname =
					args[0]->Substring(args[0]->LastIndexOf("\\")+1);
			 }


        
        // ��������, ���������� �� ��������� ����
			 if ( System::IO::FileInfo( fpath->ToString() +fname->ToString() ).Exists )
		{
			// �������� �������� ���� � ��� ������
			Application::Run(gcnew Form1(fpath,fname));
			return 0;
		}
		else
		{
			MessageBox::Show(
				"�� ��������� ������� ��� ����� �����          \n"+
				"(��� ����� ��� ����� � ��������� �����).\n" +
				fpath->ToString() + fname->ToString(),
		  "�����������",
		  MessageBoxButtons::OK,
		  MessageBoxIcon::Stop);
		  return -1;
		}

	}
	else
	{
  
		MessageBox::Show(
          "���� ����� ���������� ������� " +
          "� ������� ������� ���������.\n" +
          "��������: 'exam economics.xml' " +
          "��� 'exam c:\\spb.xml'.",
		  "�����������",
		  MessageBoxButtons::OK,
		  MessageBoxIcon::Stop);
		  return -1;
  

	}
}
