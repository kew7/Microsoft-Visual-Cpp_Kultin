#pragma once


namespace jal {

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
			
            // ��������� �����������
            comboBox1->DropDownStyle =
				ComboBoxStyle::DropDownList;

            comboBox1->Items->Add("�������");
            comboBox1->Items->Add("��������");
            comboBox1->Items->Add("������");
            comboBox1->Items->Add("�������");
            comboBox1->Items->Add("��������");

            comboBox1->SelectedIndex = 0;

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
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label4;

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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(33, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"������ (��.)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(33, 50);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(80, 15);
			this->label2->TabIndex = 1;
			this->label2->Text = L"������ (��.)";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(139, 19);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(140, 21);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox1_KeyPress);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(139, 46);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(140, 21);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox1_KeyPress);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(33, 82);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(67, 15);
			this->label3->TabIndex = 4;
			this->label3->Text = L"��������";
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(139, 78);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(140, 23);
			this->comboBox1->TabIndex = 5;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(36, 124);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(87, 27);
			this->button1->TabIndex = 6;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(33, 166);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(290, 60);
			this->label4->TabIndex = 7;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(415, 245);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"������";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
// ������ �� ������ OK
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	double w;
    double h;
    double cena = 0; // ���� �� 1 ��.�.
    double sum;

	w = Convert::ToDouble(textBox1->Text);
	h = Convert::ToDouble(textBox2->Text);

    switch (comboBox1->SelectedIndex)
    {
		case 0: cena = 100;  break; // �������
        case 1: cena = 250; break; // ��������
        case 2: cena = 170;  break; // ������
        case 3: cena = 170;  break; // �������
        case 4: cena = 120;  break; // �������
    }

    sum = (w * h) / 10000 * cena;
    label4->Text =
				"������: " + w + " x " + h + " ��.\n" +
                "���� (�./�.��.): " + cena.ToString("c") +
                "\n�����: " + sum.ToString("c");
}

// ������� ������� � ���� ��������������.
// ������� ������������ ������� KeyPress
// ����������� textBox1 � textBox2
private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e)
{
	if ((e->KeyChar >= '0') && (e->KeyChar <= '9'))
         return;
    
	if (Char::IsControl(e->KeyChar))
    {
		if (e->KeyChar == (char)Keys::Enter)
        {
			if (sender->Equals(textBox1))
				// ������� <Enter> ������ � ���� ������
                // ����������� ������ � ���� ������
                textBox2->Focus();
            else
                // ������� <Enter> ������ � ���� ������
                // ����������� ����� �� �omboBox1
                button1->Focus();
         }
         return;
    }
    
    // ��������� ������� ���������
    e->Handled = true;		 
}


// � ������ �������� ������������
// ������ ������ �������
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	label4->Text = "";
}

// ������������ ������� ������ (����������
// textBox1 ��� textBox2)
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	label4->Text = "";
	
	if ((textBox1->Text->Length == 0) ||
        (textBox2->Text->Length == 0))
                 
         button1->Enabled = false;
     else
         button1->Enabled = true; 
}
};
}

