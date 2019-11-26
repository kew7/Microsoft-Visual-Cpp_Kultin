#pragma once


namespace SecMetr {

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
			// ��������� �������:
            // ������ �� ������� � ������ 0.5 �������
            timer1->Interval = 500;

            // ��������� ���������
            m = 0;
			s = 0;

            label1->Text = "00";
            label2->Text = "00";
            label3->Visible = true;

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
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;



	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(60, 63);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"����";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(141, 63);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"�����";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(106, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(34, 24);
			this->label1->TabIndex = 2;
			this->label1->Text = L"00";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(133, 18);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(16, 24);
			this->label3->TabIndex = 3;
			this->label3->Text = L":";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(146, 18);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(34, 24);
			this->label2->TabIndex = 4;
			this->label2->Text = L"00";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 108);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"  ����������";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private:
		int m;  // ���������� �����
		int s;  // ���������� ������
		
// ������ �� ������ ����/����
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	if (timer1->Enabled)
    {
		// ������ ��������,
		// ������ ������ �� ������ ����.
        // ���������� ������
        timer1->Enabled = false;

       // �������� ����� �� ������
       // � ������� ��������� ������ �����
       button1->Text = "����";
       button2->Enabled = true;
	   
	   label3->Visible = true;
	}
    else
    {
		// ������ �� ��������,
		// ������ ������ �� ����
        // ��������� �����
        timer1->Enabled = true;

        // �������� ����� �� ������
        button1->Text = "����";
		
		// � ������� ����������� ������ �����
        button2->Enabled = false;
     }
}

// ������ �� ������ �����
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

	m = 0;
	s = 0;

    label1->Text = "00";
    label2->Text = "00";
}

// ������ �� �������
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
{
	// ��������� ������ � �������� 0.5 ���
    if (label3->Visible)
    {
		if (s < 59)
        {
			s++;
            if (s < 10)
               label2->Text = "0" + s.ToString();
            else
               label2->Text = s.ToString();
        }
        else
        {
             if (m < 59)
             {
				m++;
                if (m < 10)
					label1->Text = "0" + m.ToString();
                else
					label1->Text = m.ToString();
                s = 0;
                label2->Text = "00";
             }
             else
             {
				m = 0;
                label1->Text = "00";
             }    
         }
         label3->Visible = false;
      }
      else
		label3->Visible = true;
}




};
}

