// ��� ����� ����� ���������� � ��������� �����
// ��������� ��������� ������.
// ������� ���������� ��������� ������� main (��. Exam.cpp)
// � ������ ����� ��� ����� ����� � ���� � ���� ���������� �����
// ��������� ������������. 

#pragma once


namespace Exam {

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
		Form1(String^ fpath, String^ fname)
		{
			InitializeComponent();
			//
		  
		picpath = fpath; // ���� � ������ �����������

		radioButton1->Visible = false;
          radioButton2->Visible = false;
          radioButton3->Visible = false;

		  
	try
    {
          // ��������� xml-����
          xmlReader =
			  gcnew System::Xml::XmlTextReader(fpath + fname);
          xmlReader->Read();

          mode = 0;
          n    = 0;

          // ��������� � �������� ��������� �����
          this->showHead();

          // ��������� � �������� �������� �����
          this->showDescription();
      }
      
      catch(Exception^ e)
      {
          
		  MessageBox::Show( e->Message,
              "�����������",
			  MessageBoxButtons::OK,
			  MessageBoxIcon::Error);

          mode = 2;
      }

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
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::RadioButton^  radioButton4;

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(20, 24);
			this->label1->MaximumSize = System::Drawing::Size(500, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(45, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(23, 53);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(248, 161);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(25, 231);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(101, 20);
			this->radioButton1->TabIndex = 2;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"radioButton1";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->Click += gcnew System::EventHandler(this, &Form1::radioButton1_Click);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(24, 257);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(101, 20);
			this->radioButton2->TabIndex = 3;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"radioButton2";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->Click += gcnew System::EventHandler(this, &Form1::radioButton1_Click);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(25, 283);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(101, 20);
			this->radioButton3->TabIndex = 4;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"radioButton3";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->Click += gcnew System::EventHandler(this, &Form1::radioButton1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(33, 330);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(171, 333);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(101, 20);
			this->radioButton4->TabIndex = 6;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"radioButton4";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->Visible = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(551, 370);
			this->Controls->Add(this->radioButton4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"�����������";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	


private:

	// String^ fpath; // ���� � ����� �����
    // String^ fname; // ���� �����


    // XmlReader ������������ ������ ������ xml-�����
	System::Xml::XmlReader^ xmlReader;
     
    String^ qw;     // ������
      
    // �������� ������ - ������ ����� (���������� �� ������)
    static array<String^>^ answ = gcnew array<String^>(3);

    
	String^ picpath; // ���� � ����� �����������
	String^ pic;     // ���� �����������

    int right; // ���������� ����� (�����)
    int otv;   // ��������� ����� (�����)
    int n;     // ���������� ���������� �������
    int nv;    // ����� ���������� ��������
    int mode;  // ��������� ���������:
                         // 0 - ������ ������;
                         // 1 - ������������;
                         // 2 - ���������� ������


// ������� �������� (���������) �����
void showHead()
{
  // ���� ���� <head>
  do 
  {
	xmlReader->Read();
  }
  while(xmlReader->Name != "head");

  // ��������� ���������
  xmlReader->Read();

  // ������� �������� ����� � ��������� ����
  this->Text = xmlReader->Value;

  // ������� �� ���� <head>
  xmlReader->Read();
}

  // ������� �������� �����
  void showDescription()
  {
      // ���� ���� <description>
      do
	  {
          xmlReader->Read();
	  }
      while(xmlReader->Name != "description");

      // ��������� �������� �����
      xmlReader->Read();

      // ������� �������� �����
      label1->Text = xmlReader->Value;

      // ������� �� ���� <description>
      xmlReader->Read();

      // ���� ���� �������� <qw>
      do
          xmlReader->Read();
      while(xmlReader->Name != "qw");

      // ������ � ���� "qw"
      xmlReader->Read();
  }

// ������ ������ �� ����� �����
bool getQw()
{
	// ��������� ��� <q>
    xmlReader->Read();

	if (xmlReader->Name == "q")
    {
		// ����� �������� ��� <q>,
        // ������� text �������� �������� ������, �
        // ������� src - ��� ����� �����������.

        // ��������� �������� ���������:
        qw  = xmlReader->GetAttribute("text");
        pic = xmlReader->GetAttribute("src");
		if (!pic->Equals(String::Empty))
			pic = picpath + pic;

        // ������ ������ ����
        xmlReader->Read();
        int i = 0;

        // ��������� ������ ���� ������� <q>
        while (xmlReader->Name != "q")
        {
			xmlReader->Read();

            // �������� ������
            if (xmlReader->Name == "a")
            {
				// ���� ���� ������� right, �� ���
                // ���������� �����
                if (xmlReader->GetAttribute("right") ==
                        "yes")
                      right = i;

                // ��������� ������� ������
                xmlReader->Read();
                if (i < 3) answ[i] = xmlReader->Value;

                // ������� �� ���� <a>
                xmlReader->Read();

                  i++;
             }
		}

		// ������� �� ���� ������� <q>
		xmlReader->Read();

		return true;
	}
    // ���� ��������� ��� �� <q>
    else
          return false;
}

// ������� ������ � �������� ������
void showQw()
{
	// ������� ������
    label1->Text = qw;

    // �����������
    if (pic->Length != 0)
    {
		try
        {
			pictureBox1->Image = gcnew Bitmap(pic);

            pictureBox1->Visible = true;

            radioButton1->Top = pictureBox1->Bottom + 16;
        }
		catch (Exception^ )
        {
              if (pictureBox1->Visible)
                  pictureBox1->Visible = false;

              label1->Text +=
                  "\n\n\n������ ������� � ����� " + pic + ".";

              radioButton1->Top = label1->Bottom + 8;
        }
      }
      else
      {
          if (pictureBox1->Visible)
              pictureBox1->Visible = false;

          radioButton1->Top = label1->Bottom + 16;
      }

      // �������� �������� ������
      radioButton1->Text = answ[0];
      radioButton2->Top  = radioButton1->Top + 24;;
      radioButton2->Text = answ[1];
      radioButton3->Top  = radioButton2->Top + 24;;
      radioButton3->Text = answ[2];

      radioButton4->Checked = true; 
      button1->Enabled = false;
}


// ������ �� ������ ������ ������.
// ������� ������������ ������� Click
// ����������� radioButton1 - radioButton3
private: System::Void radioButton1_Click(System::Object^  sender, System::EventArgs^  e)
{
	 if ((RadioButton^)sender == radioButton1) otv = 0;
     if ((RadioButton^)sender == radioButton2) otv = 1;
     if ((RadioButton^)sender == radioButton3) otv = 2;

      button1->Enabled = true;
}


// ������ �� ������ OK
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	switch (mode)
      {
      case 0:
		  // ������ �� ������ OK 
		  // ����� � ���� ������������
		  // ���������� � ����� � �������
          radioButton1->Visible = true;
          radioButton2->Visible = true;
          radioButton3->Visible = true;

          getQw();
          showQw();

          mode = 1;

          button1->Enabled = false;
          radioButton4->Checked = true;
          break;

      case 1:
		  // ������, ��������������
		  // ����� ������
          nv++;

          // ���������� �� ����� ������
          if (otv == right) n++;

          if (getQw())
			  showQw();
          else {
              // ������ �������� ���
              radioButton1->Visible = false;
              radioButton2->Visible = false;
              radioButton3->Visible = false;

              pictureBox1->Visible  = false;

              // ��������� � ����� ����������
              showLevel();

              // ��������� ������ �� ������ Ok
              // ������ ������� ���� ���������
              mode = 2;
          }
          break;
      
	  case 2:
		  // ���������� ������ ���������
          this->Close(); // ������� ����
          break;
      }
}


// ������� ������ 
void showLevel()
{
	// ���� ���� <levels>
    do
		xmlReader->Read();
    while (xmlReader->Name != "levels");

    // ������ ������ ����
    xmlReader->Read();

    // ������ ������ ����
    while (xmlReader->Name != "levels")
    {
		xmlReader->Read();

        if (xmlReader->Name == "level")
              // n - ���-�� ���������� �������.
              // ��� ���������� ������, ���-��
			  // ���������� ������� ������ ����
			  // ����� ��� ��������� ��������,
			  // �������� ��������� score 
		 	
			if (n >= Convert::ToInt32(
                  xmlReader->GetAttribute("score")))
              break;
		 
     }

     // ������� ������
     label1->Text =
          "������������ ���������.\n" +
          "����� ��������: " + nv.ToString() + "\n" +
          "���������� �������: " + n.ToString() + "\n\n" +
          xmlReader->GetAttribute("text");
  
  }

  
  





};
}

