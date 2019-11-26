#pragma once


namespace wr2txt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::IO;

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
			
			button1->Enabled = false;
			
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
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;

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
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(27, 21);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 21);
			this->dateTimePicker1->TabIndex = 0;
			this->dateTimePicker1->TabStop = false;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &Form1::dateTimePicker1_ValueChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(27, 62);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 21);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox1_KeyPress);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(27, 108);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"��������";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(295, 161);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dateTimePicker1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"USD (����  �� ��)";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

// ������� ������� � ���� ��������������
private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
{
	if ((e->KeyChar >= '0') && (e->KeyChar <= '9'))
                return;

    if (e->KeyChar == '.')
		e->KeyChar = ',';

    if (e->KeyChar == ',')
    {
		// � ���� �������������� �� �����
        // ���� ������ ����� ������� � �������
        // �� ����� ���� ������ ��������
        if ((textBox1->Text->IndexOf(',') != -1) ||
             (textBox1->Text->Length == 0))
        {
			e->Handled = true;
        }
        return;
     }

	if (Char::IsControl(e->KeyChar))
    {
		// <Enter>, <Backspace>, <Esc>
		if (e->KeyChar == (char)Keys::Enter)
			// ���������� ������ �� ������ OK
            button1->Focus();
            return;
    }
    
	// ��������� ������� ���������
    e->Handled = true;
}

	
// ���������� ���������� ���� ��������������	
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e)
{

	if (textBox1->Text->Length == 0)
       button1->Enabled = false;
    else
        button1->Enabled = true;
}



// ������ �� ������ ��������
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	double kurs;   // ����
    DateTime date; // ����
      
    date = dateTimePicker1->Value;
	kurs =  System::Convert::ToDouble(textBox1->Text);
           
    // �������� ���������� � �����
	System::IO::FileInfo^ fi =
		gcnew System::IO::FileInfo(
		Application::StartupPath + "\\usd.txt");

    // ����� ��� ������        
	System::IO::StreamWriter^ sw;
           
    if (fi->Exists) // ���� ������ ����������?
        // ������� ����� ��� ����������
        sw = fi->AppendText();
    else
		// ������� ���� � ������� ����� ��� ������
        sw = fi->CreateText();
			
    // ������ � ����
	sw->WriteLine(date.ToShortDateString());
    sw->WriteLine(kurs.ToString("N"));
      
    // ������� �����
    sw->Close();

    // ����� �� ������ �� �������� ������
    // ������ ���, ������� ����������� ����
    // ����� � ������
    button1->Enabled = false;
    textBox1->Enabled = false;
}


// ������������ ������ ������ ����
private: System::Void dateTimePicker1_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
	// �������� � ������� ���������
    // ���� �����
    textBox1->Enabled = true;
    textBox1->Clear();
    
	// ���������� ������ � ���� �����
    textBox1->Focus();
}


};
}

