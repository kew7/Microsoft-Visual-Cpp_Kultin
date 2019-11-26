#pragma once


namespace f2k {

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
			
			// ��������� �����
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
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label2;
	protected: 

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
			this->label1->Location = System::Drawing::Point(14, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"��� � ������:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(107, 18);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 21);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox1_KeyPress);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(17, 66);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(14, 111);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(203, 32);
			this->label2->TabIndex = 3;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(321, 157);
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
			this->Text = L"�����-����������";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


// ������ �� ������ OK
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	double funt; // ��� � ������
    double kg;   // ��� � �����������

	funt = Convert::ToDouble(textBox1->Text);

    // 1 ���� = 409,5 ������
    kg = funt * 0.4095;

	label2->Text = funt.ToString("N") + " �. = " +
		            kg.ToString("N") + " ��.";

}
	
// ������������ ������� ������ � ���� ��������������
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	label2->Text = ""; // �������� ���� �����������
                       // ���������� �������

    if (textBox1->Text->Length == 0)
        // � ���� �������������� ��� ������
        // ������� ������ OK �����������
        button1->Enabled = false;
    else
        // ������� ������ OK ���������
        button1->Enabled = true;	 
}

// ������� ������� � ���� textBox1
private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
{
	if ((e->KeyChar >= '0') && (e->KeyChar <= '9'))
		// ����� - ���������� �������
		return;

    if (e->KeyChar == '.')
		// ����� ������� �� �������
		e->KeyChar = ',';

    if (e->KeyChar == ',')
    {
		// � ���� �������������� �� �����
        // ���� ������ ����� ������� � �������
        // �� ����� ���� ������ ��������
        if ( (textBox1->Text->IndexOf(',') != -1) ||
                      ( textBox1->Text->Length == 0))
        {
			e->Handled = true;
        }
        return;	
	}

	if (  Char::IsControl(e->KeyChar) )
    {
		// <Enter>, <Backspace>, <Esc>
		if ( e->KeyChar == (char) Keys::Enter)
            // ������ ������� Enter 
			// ���������� ������ �� ������ OK
            button1->Focus(); 
            return;
    }

    // ��������� ������� ���������
    e->Handled = true;

}



};
}

