#pragma once


namespace osago {

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
			// ��������� �����������
			//
			
			
			// ������� �����
			textBox1->Text = "1980";
			
			checkBox1->Checked = true;
			
			// ������ ��������
			for ( int i = 0; i < reg->Length; i++)
			{
				comboBox1->Items->Add(reg[i]);
			}
			comboBox1->SelectedItem = 2;
			comboBox1->DropDownStyle = 
				  System::Windows::Forms::ComboBoxStyle::DropDownList;

			/* ����� � ���:
			comboBox1->Items->Add("������������� ���.");
			comboBox1->Items->Add("������");
			comboBox1->Items->Add("���������� ���.");
			comboBox1->Items->Add("��������");
			comboBox1->Items->Add("������ ��������");
			comboBox1->Items->Add("������-��-����");
			comboBox1->Items->Add("������");
			comboBox1->Items->Add("�����-���������");
			*/

			// ������� � ����
			comboBox2->Items->Add("�� 22 ���, ���� ����� 2-� ���");
			comboBox2->Items->Add("�� 22 ���, ���� ����� 2-� ���");
			comboBox2->Items->Add("�� 22 ���, ���� ����� 2-� ���");
			comboBox2->Items->Add("�� 22 ���, ���� ����� 2-� ���");
			comboBox2->DropDownStyle = 
				  System::Windows::Forms::ComboBoxStyle::DropDownList;


		    // �������� ���������
			comboBox3->Items->Add("�� 50 ������������");
			comboBox3->Items->Add("����� 50 �� 70 ������������");
			comboBox3->Items->Add("����� 70 �� 95 ������������");
			comboBox3->Items->Add("����� 95 �� 120 ������������");
			comboBox3->Items->Add("����� 120 �� 160 ������������");
			comboBox3->Items->Add("����� 160 �� 200 ������������");
			comboBox3->Items->Add("����� 200");
			comboBox3->DropDownStyle = 
				  System::Windows::Forms::ComboBoxStyle::DropDownList;

			
			// ������ �������������
			comboBox4->Items->Add("6 �������");
			comboBox4->Items->Add("7 �������");
			comboBox4->Items->Add("8 �������");
			comboBox4->Items->Add("9 �������");
			comboBox4->Items->Add("����� 9 �������");
			comboBox4->DropDownStyle = 
				  System::Windows::Forms::ComboBoxStyle::DropDownList;

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
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::ComboBox^  comboBox4;
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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(21, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(375, 47);
			this->label1->TabIndex = 0;
			this->label1->Text = L"������ ������ �� ������������� �����������  ����������� ��������������� ���������" 
				L" ������������� ��������  (����������� ���� ���������  ��������� ����������)\r\n";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(24, 72);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(246, 14);
			this->label2->TabIndex = 1;
			this->label2->Text = L"������� ������ ���������� ������ (���.):";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(22, 100);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(290, 14);
			this->label3->TabIndex = 2;
			this->label3->Text = L"���������� ����������������� �������������:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(24, 128);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(153, 14);
			this->label4->TabIndex = 3;
			this->label4->Text = L"����� ����������� ����:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(246, 128);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(189, 14);
			this->label5->TabIndex = 4;
			this->label5->Text = L"���������� ��������� �������:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(24, 156);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(98, 14);
			this->label6->TabIndex = 5;
			this->label6->Text = L"������� � ����:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(68, 182);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(356, 14);
			this->label7->TabIndex = 6;
			this->label7->Text = L"����������� ���������� ���, ���������� � ���������� ��";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(24, 212);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(165, 14);
			this->label8->TabIndex = 7;
			this->label8->Text = L"�������� ��������� (�.�.):";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(24, 240);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(162, 14);
			this->label9->TabIndex = 8;
			this->label9->Text = L"������ ������������� ��:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(27, 289);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(276, 69);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 10;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(183, 125);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(48, 22);
			this->textBox2->TabIndex = 11;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(441, 125);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(48, 22);
			this->textBox3->TabIndex = 12;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(317, 97);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(172, 22);
			this->comboBox1->TabIndex = 13;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(128, 153);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(214, 22);
			this->comboBox2->TabIndex = 14;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(33, 182);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(15, 14);
			this->checkBox1->TabIndex = 15;
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(204, 209);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(203, 22);
			this->comboBox3->TabIndex = 16;
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Location = System::Drawing::Point(204, 237);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(162, 22);
			this->comboBox4->TabIndex = 17;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 14);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(509, 340);
			this->Controls->Add(this->comboBox4);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"�����";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private:

// ������
static array<String^>^ reg =
	{"������","���������� ���.","�����-���������",
     "������ ��������","������������� ���.","������-������",
	 "������","��������"};

// ���������� �������
static array<double>^ kt  = {1.8,1.6, 1.8,1.3,1,1,1,1};

/* ������� ����������� ������������ ���������� ������
������ ��� - 3� �����, ������ ��� (���� �� ���� ���������
�������) 4� ����� � �.�.). ���� ��������� ������ ���,
�� ����� � ������ �������: ������ - ����� �����������
����, ������� - ���-�� ��������� �������. */

// ����� �������������� - ������� 6�5 (6 �����, 5 ��������)
static array<int,2>^ cb  /* [6][5] */ = {
{1,-1,-1,-1,-1},
{2,-1,-1,-1,-1},
{3,1,-1,-1,-1},
{4,1,-1,-1,-1},
{5,2,1,-1,-1},
{6,3,1,-1,-1}};

// ����������� ��������������
static array<double>^ kb = {2.3, 1.55, 1.4, 1, 0.95, 0.9};

// ����������� ������������� �����
static array<double>^ kvs = {1.3, 1.2, 1.15, 1};

// ����������� �������� ���������
static array<double>^ km = {0.5, 0.7, 1.0, 1.3, 1.5, 1.7, 1.9};

// ����������� ������� ������������� ��
static array<double>^ ks = {0.7, 0.8, 0.9, 0.95, 1.0};


// ������ �� ������ OK
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	// ������ ��������� "������" :)
	double aTb;  // ������� ������ ������
    double aKt;  // ����. ������
    double aKb;   // ����. ��������������
    double aKvs; // ����. ������������� �����
    double aKo;  // ����., ����������� ���������� ���, ��������� � ����������
    double aKm;  // ����. �������� ���������
    double aKs;  // ����., ����������� ������ ������������� ��

    int pcb,ccb; // ���������� � ������� ����� �������������
    int nss;     // ���������� ��������� ������� ����������� �������


    // ��������, ��� �� ���� ����� ����������
	if ( (comboBox1->SelectedIndex == -1) ||
		(comboBox2->SelectedIndex == -1) ||
		(comboBox3->SelectedIndex == -1) ||
		(comboBox4->SelectedIndex == -1) ||
		(textBox2->Text->Length == 0) ||
		(textBox3->Text->Length == 0)
		)
	{
		MessageBox::Show("���� ��������� ��� ���� �����",
			"�����",
			System::Windows::Forms::MessageBoxButtons::OK,
			System::Windows::Forms::MessageBoxIcon::Warning);

		return;
	}
		

    // ��� ���� ����� ���������

	aTb = System::Convert::ToDouble(textBox1->Text);
    aKt = kt[comboBox1->SelectedIndex];

    pcb = System::Convert::ToInt32(textBox2->Text); // ����. ����� ��������������
    nss = System::Convert::ToInt32(textBox3->Text); // ���-�� ��������� ������� 
   
	if ( pcb > 5)
		pcb = 5; // ��. ����������� ������� cb

	ccb =   cb[pcb-1,nss]; // ������� ����� ��������������
    if ( ccb != -1)
        aKb = kb[ccb];
    else aKb = 2.45;

    // �����. ������������� �����
	aKvs = kvs[comboBox2->SelectedIndex];
    
    // ���������� ���, ��������� � ����������
    if (checkBox1->Checked)
        aKo = 1;
    else
        aKo = 1.5;

    // �������� ���������
	aKm = km[comboBox3->SelectedIndex];
    
    // ������ ������������� ��
	aKs = ks[comboBox4->SelectedIndex];
    
    // ��� ������������ ���������� - ������

    double T; // �����
	String ^st;

    T = aTb * aKt * aKb * aKvs * aKo * aKm *aKs;

	st = "������� ������ ������: " + aTb.ToString("c")+
		"\n����. ������: " + aKt.ToString()+
		"\n����. ��������������: " + aKb.ToString()+
		"\nK���. ������������� �����: " + aKvs.ToString() +
		"\n����. ���-�� ���, ��������� � ����������: " + aKo.ToString() +
		"\n����. �������� ��������: " + aKm.ToString() +
		"\n����. ������� ������������� ��: " + aKs.ToString()+
		"\n\n�����: " + T.ToString("c");

    MessageBox::Show(st,"����� �����");
}



};
}

