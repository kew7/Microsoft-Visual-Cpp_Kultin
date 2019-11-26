#pragma once


namespace kred {

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
			
			// ��������� listView1 - ���������
			// ������ ���������� �� ������ ������������
			// ������ ����������
			int w = 0;
			for ( int i=0; i < listView1->Columns->Count; i++)
				w += listView1->Columns[i]->Width;
			if (listView1->BorderStyle == BorderStyle::Fixed3D)
				w +=4;
			listView1->Width = w + 17;

			listView1->FullRowSelect = true;
			
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
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;
	private: System::Windows::Forms::ColumnHeader^  columnHeader4;

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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(52, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"�����:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(29, 48);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(67, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"���� (���.):";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(19, 74);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"����. ������:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(102, 19);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(102, 45);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 4;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(102, 71);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 5;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(102, 107);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {this->columnHeader1, this->columnHeader2, 
				this->columnHeader3, this->columnHeader4});
			this->listView1->Location = System::Drawing::Point(32, 154);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(312, 128);
			this->listView1->TabIndex = 8;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"�����";
			this->columnHeader1->Width = 50;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"����";
			this->columnHeader2->Width = 80;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"�������";
			this->columnHeader3->Width = 80;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"������";
			this->columnHeader4->Width = 80;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(379, 306);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"���������� �����������";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

// ������ �� ������ OK
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	float value; // ����� �������
    int period;  // ����
    float rate;  // ���������� ������

    float debt; // ����, �� ������ �������� ������
    float interest; // ����� �� ������ (�������� �� ����)
    float paying;   // ����� �������
    float suminterest; // ����� ����� �� ������

	String ^ st; // �����

    // �����
	value = System::Convert::ToSingle(textBox1->Text);

	// ����
	period = System::Convert::ToInt32(textBox2->Text);

	// ���������� ������
	rate = System::Convert::ToSingle(textBox3->Text);

	debt = value;
    suminterest = 0;

	// ������ ��� ������� ������
    for ( int i = 1; i <= period; i++)
    {
        interest = debt * (rate/12/100);
        suminterest += interest;
        paying = value/period + interest;

		st = i.ToString() + "  " + debt.ToString("c") + "  " +
			 interest.ToString("c") + "  " + paying.ToString("c");
		
		// �������� � listView ������� -
		// ������ (������ � ������ �������)
		listView1->Items->Add(i.ToString());

		// �������� � ����������� ������ ����������� -
		// ������ �� �����, ������ � ��������� �������
		listView1->Items[i-1]->SubItems->Add(debt.ToString("c"));
		listView1->Items[i-1]->SubItems->Add(interest.ToString("c"));
		listView1->Items[i-1]->SubItems->Add(paying.ToString("c"));

        debt = debt - value/period;
    }
}

// ������������ ������� TextChanged �����������
// textBox1 - textBox3
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	// ���� ���� �� � ����� �� ����� ��� ������,
	// ������� ������ OK �����������
	if ( (textBox1->Text->Length == 0) || 
		 (textBox2->Text->Length == 0) ||
		 (textBox3->Text->Length == 0)
		)
		button1->Enabled = false;
	else
	    button1->Enabled = true;
}


};
}

