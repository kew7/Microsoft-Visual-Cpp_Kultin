#pragma once


namespace usd2rub_c {

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
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(28, 91);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(87, 27);
			this->button1->TabIndex = 0;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 15);
			this->label1->TabIndex = 1;
			this->label1->Text = L"����:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(73, 19);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(116, 21);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox1_KeyPress);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(73, 46);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(116, 21);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox1_KeyPress);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(22, 50);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(36, 15);
			this->label2->TabIndex = 4;
			this->label2->Text = L"����:";
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(25, 131);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(257, 40);
			this->label3->TabIndex = 5;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(331, 180);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"���������";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion






// ������ �� ������ OK
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	double usd; // ���� � �������� 
	double k;   // ����
	double rub; // ���� � ������
				
	usd =  System::Convert::ToDouble(textBox1->Text);
	k =  System::Convert::ToDouble(textBox2->Text);

	rub = usd * k;
		 
	label3->Text = usd.ToString("n") + "$ = " +
		           rub.ToString("c");
}
		 
				
// ��� ������� ������������ ������� ������� � �����
// �������������� textBox1 (����) � textBox2 (����).
// ������� ���� ������� ������� ������� ������
// ��������� ������� KeyPress ��� ����������
// textBox1, ����� - ������� �� � ��������
// ����������� ����� �� ������� ��� ��������� textBox2
private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
{
	if ((e->KeyChar >= '0') && (e->KeyChar <= '9'))
         return;

    if (e->KeyChar == '.') e->KeyChar = ',';

    if (e->KeyChar == ',')
    {
		
		if (sender->Equals(textBox1)) {
			if ((textBox1->Text->IndexOf(',') != -1) ||
				(textBox1->Text->Length == 0))
			{
				e->Handled = true;
			}
		}
		else {
			if ((textBox2->Text->IndexOf(',') != -1) ||
				(textBox2->Text->Length == 0))
			{
				e->Handled = true;
			}
		}
        return;
	}

	if (Char::IsControl(e->KeyChar))
    {
		if (e->KeyChar == (char)Keys::Enter)
        {
			if (sender->Equals(textBox1))
               // ������� <Enter> ������ � ���� ����    
               // ����������� ������ � ���� ����
               textBox2->Focus();
            else
               // ������� <Enter> ������ � ���� ����    
               // ���������� ����� �� ������ OK
               button1->Focus();
        }
        return;
     }

     // ��������� ������� ���������
     e->Handled = true;
}

// ������� ������������ ������� TextChanged (���������
// ����� � ���� ��������������) ����� ����������� TextBox.
// ������� ���� ������� ������� ������� ������
// ��������� ������� TextChanged ��� ����������
// textBox1, ����� - ������� �� � ��������
// ����������� ������� TextChanged ��� ��������� textBox2
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	label3->Text = ""; // �������� ���� �����������
                       // ���������� �������

    if ((textBox1->Text->Length == 0) || (textBox2->Text->Length == 0))
        // � ���� �������������� ��� ������
        // ������� ������ OK �����������
        button1->Enabled = false;
    else
        // ������� ������ OK ���������
        button1->Enabled = true;	 




}
	};
}

