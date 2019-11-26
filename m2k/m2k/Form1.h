#pragma once


namespace m2k {

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
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label2;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(22, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(42, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"����:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(70, 16);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 21);
			this->textBox1->TabIndex = 1;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox1_KeyPress);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(25, 58);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(22, 103);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(259, 24);
			this->label2->TabIndex = 3;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(308, 145);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"����-���������";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

// ������ �� ������ OK
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	double mile; // ���������� � ����
    double km;   // ���������� � ����������

    // ���� � ���� �������������� ��� ������,
    // �� ��� ������� ������������� ������
    // ������ � ����� ��������� ����������.
    try
    {
		mile = Convert::ToDouble(textBox1->Text);

        km = mile * 1.609344; 

        label2->Text = mile.ToString("n") + " miles - " +
			           km.ToString("n") + " ��.";
    }
	
	catch (System::FormatException^ ex )
	{
		// ��������� ����������:
        // - ���������
		MessageBox::Show(
			"���� ������ ������", "����-���������",
			MessageBoxButtons::OK,
			MessageBoxIcon::Exclamation);
		
		// - ���������� ������ � ���� ��������������
        textBox1->Focus();
	}
}

// ������� ������� � ���� textBox
private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
{
	// ����������� ��������� ��������� �����,
    // �������, <Enter> � <Backspace>.
    // ����� ������� ���������� ��������
    // ����� �����, �� ������� �� �������.
    // ��������� ������� ���������.
    // ����� ����������� ������ �� ����������� 
    // � ���� ��������������, �������� 
    // �������� true �������� Handled ��������� e

    if ((e->KeyChar >= '0') && (e->KeyChar <= '9'))
    {
		// �����
        return;
    }

    
    if (e->KeyChar == '.')
    {
      // ����� ������� �������
      e->KeyChar = ',';
    }

    if (e->KeyChar == ',')
    {
		if (textBox1->Text->IndexOf(',') != -1)
        {
			// ������� ��� ���� � ���� ��������������
            e->Handled = true;
        }
        return;
    }

    if (  Char::IsControl(e->KeyChar) )
    {
		// <Enter>, <Backspace>, <Esc>
		if ( e->KeyChar == (char) Keys::Enter)
			// ������ ������� <Enter>
            // ���������� "�����" �� ������ OK
            button1->Focus(); 
            return;
    }

    // ��������� ������� ���������
    e->Handled = true;
}


};
}

