#pragma once


namespace readTxt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� Form1
	///
	/// ��������! ��� ��������� ����� ����� ������ ���������� ����� ��������
	///          �������� ����� ����� �������� ("Resource File Name") ��� �������� ���������� ������������ �������,
	///          ���������� �� ����� ������� � ����������� .resx, �� ������� ������� ������ �����. � ��������� ������,
	///          ������������ �� ������ ��������� �������� � ���������������
	///          ���������, ��������������� ������ �����.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MonthCalendar^  monthCalendar1;
	protected: 
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ListBox^  listBox1;

	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->monthCalendar1 = (gcnew System::Windows::Forms::MonthCalendar());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// monthCalendar1
			// 
			this->monthCalendar1->Location = System::Drawing::Point(18, 18);
			this->monthCalendar1->Name = L"monthCalendar1";
			this->monthCalendar1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(18, 192);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(221, 18);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(136, 186);
			this->listBox1->TabIndex = 2;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(384, 228);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->monthCalendar1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"���������  - USD (�� ��)";
			this->ResumeLayout(false);

		}
#pragma endregion


private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	System::IO::StreamReader^ sr; // ����� ��� ������ 
    try
    {
		// ������� ����� ��� ������
		sr = gcnew System::IO::StreamReader(
			Application::StartupPath + "\\usd.txt",
			System::Text::Encoding::GetEncoding(1251));
                
        // ������ � ����� ���������, �����������
        // �� ���������
        DateTime dateStart =
                        monthCalendar1->SelectionStart;
        DateTime dateEnd =
                        monthCalendar1->SelectionEnd;
               
		String^ st1;
		String^ st2;
        
		DateTime date;

        listBox1->Items->Clear();

        // ������ ������ �� �����
        while ( ! sr->EndOfStream )
        {
			st1 = sr->ReadLine(); // ���� ��� ������
			date = System::Convert::ToDateTime(st1);
            st2 = sr->ReadLine(); 

            if ((date >= dateStart) && 
                                (date <= dateEnd))
            {
				listBox1->Items->Add(st1 + " - " + st2);
             }
         }
         sr->Close();

         if (listBox1->Items->Count == 0)
         {
			listBox1->Items->Add("--- ��� ������ ---");
         }
    }
	catch(System::IO::FileNotFoundException^ e)
    {
		MessageBox::Show
                   ("��� ����� ������\n" +
                    Application::StartupPath + "\\usd.txt",
                    "���������",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
        button1->Enabled = false;
     }
}


	};
}

