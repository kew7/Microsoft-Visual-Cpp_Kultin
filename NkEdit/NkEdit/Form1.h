#include "Form2.h"

#pragma once


namespace NkEdit {

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
			
			textBox1->ScrollBars = ScrollBars::Vertical;
			textBox1->Text = "";

            this->Text = "NkEdit - ����� ��������";

            // ���������� ������ ������������
            toolStrip1->Visible = true;
            toolStripMenuItem6->Checked = true;

            // ��������� ���� �������
            // helpProvider1.HelpNamespace = "nkedit.chm";

            // ��������� ���������� openDialog1
            openFileDialog1->DefaultExt = "txt";
            openFileDialog1->Filter = "�����|*.txt";
            openFileDialog1->Title = "������� ��������";
            openFileDialog1->Multiselect = false;

            // ��������� ���������� saveDialog1
            saveFileDialog1->DefaultExt = "txt";
            saveFileDialog1->Filter = "�����|*.txt";
            saveFileDialog1->Title = "��������� ��������";

			fn = String::Empty;
			textChanged = false;
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
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;

	protected: 

	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem5;







	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem4;
	private: System::Windows::Forms::ToolStripMenuItem^  paramToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem8;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem9;






	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem6;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem7;





	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton2;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton3;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton4;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::FontDialog^  fontDialog1;
	private: System::Windows::Forms::PrintDialog^  printDialog1;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem5 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->paramToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem6 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem7 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem8 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem9 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->fontDialog1 = (gcnew System::Windows::Forms::FontDialog());
			this->printDialog1 = (gcnew System::Windows::Forms::PrintDialog());
			this->menuStrip1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->fileToolStripMenuItem, 
				this->paramToolStripMenuItem, this->helpToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(474, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->toolStripMenuItem1, 
				this->toolStripMenuItem2, this->toolStripMenuItem3, this->toolStripMenuItem4, this->toolStripMenuItem5});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->fileToolStripMenuItem->Text = L"����";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripMenuItem1.Image")));
			this->toolStripMenuItem1->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(151, 28);
			this->toolStripMenuItem1->Text = L"�������";
			this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem1_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripMenuItem2.Image")));
			this->toolStripMenuItem2->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(151, 28);
			this->toolStripMenuItem2->Text = L"������� ...";
			this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem2_Click);
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripMenuItem3.Image")));
			this->toolStripMenuItem3->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(151, 28);
			this->toolStripMenuItem3->Text = L"��������� ...";
			this->toolStripMenuItem3->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem3_Click);
			// 
			// toolStripMenuItem4
			// 
			this->toolStripMenuItem4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripMenuItem4.Image")));
			this->toolStripMenuItem4->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
			this->toolStripMenuItem4->Size = System::Drawing::Size(151, 28);
			this->toolStripMenuItem4->Text = L"������ ...";
			this->toolStripMenuItem4->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem4_Click);
			// 
			// toolStripMenuItem5
			// 
			this->toolStripMenuItem5->Name = L"toolStripMenuItem5";
			this->toolStripMenuItem5->Size = System::Drawing::Size(151, 28);
			this->toolStripMenuItem5->Text = L"�����";
			this->toolStripMenuItem5->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem5_Click);
			// 
			// paramToolStripMenuItem
			// 
			this->paramToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem6, 
				this->toolStripMenuItem7});
			this->paramToolStripMenuItem->Name = L"paramToolStripMenuItem";
			this->paramToolStripMenuItem->Size = System::Drawing::Size(83, 20);
			this->paramToolStripMenuItem->Text = L"���������";
			// 
			// toolStripMenuItem6
			// 
			this->toolStripMenuItem6->Checked = true;
			this->toolStripMenuItem6->CheckState = System::Windows::Forms::CheckState::Checked;
			this->toolStripMenuItem6->Name = L"toolStripMenuItem6";
			this->toolStripMenuItem6->Size = System::Drawing::Size(196, 22);
			this->toolStripMenuItem6->Text = L"������ ������������";
			this->toolStripMenuItem6->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem6_Click);
			// 
			// toolStripMenuItem7
			// 
			this->toolStripMenuItem7->Name = L"toolStripMenuItem7";
			this->toolStripMenuItem7->Size = System::Drawing::Size(196, 22);
			this->toolStripMenuItem7->Text = L"����� ...";
			this->toolStripMenuItem7->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem7_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem8, 
				this->toolStripMenuItem9});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->helpToolStripMenuItem->Text = L"�������";
			// 
			// toolStripMenuItem8
			// 
			this->toolStripMenuItem8->Enabled = false;
			this->toolStripMenuItem8->Name = L"toolStripMenuItem8";
			this->toolStripMenuItem8->Size = System::Drawing::Size(216, 22);
			this->toolStripMenuItem8->Text = L"���������� ����������";
			// 
			// toolStripMenuItem9
			// 
			this->toolStripMenuItem9->Name = L"toolStripMenuItem9";
			this->toolStripMenuItem9->Size = System::Drawing::Size(216, 22);
			this->toolStripMenuItem9->Text = L"� ���������";
			this->toolStripMenuItem9->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem9_Click);
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(23, 22);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->toolStripButton1, 
				this->toolStripButton2, this->toolStripButton3, this->toolStripSeparator1, this->toolStripButton4});
			this->toolStrip1->Location = System::Drawing::Point(0, 24);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(474, 29);
			this->toolStrip1->TabIndex = 1;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(27, 26);
			this->toolStripButton1->Text = L"toolStripButton1";
			this->toolStripButton1->ToolTipText = L"����� ��������";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &Form1::toolStripButton1_Click);
			// 
			// toolStripButton2
			// 
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(27, 26);
			this->toolStripButton2->Text = L"toolStripButton2";
			this->toolStripButton2->ToolTipText = L"�������";
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &Form1::toolStripButton2_Click);
			// 
			// toolStripButton3
			// 
			this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(27, 26);
			this->toolStripButton3->Text = L"toolStripButton3";
			this->toolStripButton3->ToolTipText = L"���������";
			this->toolStripButton3->Click += gcnew System::EventHandler(this, &Form1::toolStripButton3_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 29);
			// 
			// toolStripButton4
			// 
			this->toolStripButton4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton4.Image")));
			this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton4->Name = L"toolStripButton4";
			this->toolStripButton4->Size = System::Drawing::Size(27, 26);
			this->toolStripButton4->Text = L"toolStripButton4";
			this->toolStripButton4->ToolTipText = L"������";
			this->toolStripButton4->Click += gcnew System::EventHandler(this, &Form1::toolStripButton4_Click);
			// 
			// textBox1
			// 
			this->textBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(0, 53);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(474, 244);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// printDialog1
			// 
			this->printDialog1->UseEXDialog = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(474, 297);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"����� ��������";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private:
	String^ fn;         // ��� �����
	bool textChanged;   // true - � ����� ������� ���������


// ��������� ����� � ���� ���������� textBox
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	textChanged = true; // ����� �������
}

// ���������� ����� � ����.
// ���������� 0 ��� -1, ���� ������������
// � ���� ��������� ������ ������ ������ 
private: int TextToFile()
{
	System::Windows::Forms::DialogResult dr;
	int r = 0;
    
	if (fn == String::Empty)
    {
		// ��� ����� ��������
		// ��������� � ������������ ��� �����

		// ���������� ������ ���������
		dr = saveFileDialog1->ShowDialog();
        if (dr ==
			System::Windows::Forms::DialogResult::OK)
        {
			
            fn = saveFileDialog1->FileName;
            r = 0;
        }
        else
			// � ���� ��������� ������������
			// ������ ������ �� ������ ������
			r = -1;			
     }

     // ��������� ����
	if ( r == 0)
    {
		try
        {
			// ������� ���������� � ����� fn
			System::IO::FileInfo^ fi =
				gcnew System::IO::FileInfo(fn);

            // ����� ��� ������
			System::IO::StreamWriter^ sw =
                      fi->CreateText();
            sw->Write(textBox1->Text);

            sw->Close(); // ��������� �����
			textChanged = false;
            r = 0;
        }
		catch ( System::IO::IOException^ e)
        {
			MessageBox::Show(e->ToString(),
                  "NkEdit",
				  MessageBoxButtons::OK,
				  MessageBoxIcon::Error);
        }
    }
    return r;
}


// ���������, ���� �� ��������� � ������ �
// ��������� ����� � �����.
// ����������:
//   0 ��� -1, ���� ������������
//   ��������� �� ���������� �������� (����� Cancel)
private: int SaveText()
{
	System::Windows::Forms::DialogResult dr;
		
	int r;
	
	r = 0;
	if (textChanged)
	{		
		dr = MessageBox::Show( 
					"� ����� ������� ���������. ��������� ���������� �����?", "NkEdit",
					MessageBoxButtons::YesNoCancel,
					MessageBoxIcon::Warning);
        switch (dr)
        {
			case System::Windows::Forms::DialogResult::Yes:
                r = TextToFile();
                break;
		
			case System::Windows::Forms::DialogResult::No:
				r = 0;
				break;
		
			case System::Windows::Forms::DialogResult::Cancel:
                r = -1;
			    break;
        };
	}
	return r;
}

// ������� ��������
private: void OpenDocument()
{
	System::Windows::Forms::DialogResult dr;
	int r;

	r = SaveText();
    
	if ( r == 0)
	{	
		openFileDialog1->FileName = String::Empty;

		// ���������� ������ �������

		dr = openFileDialog1->ShowDialog();
		if (dr == System::Windows::Forms::DialogResult::OK)
		{
			fn = openFileDialog1->FileName;

			// ���������� ��� ����� � ��������� ����
			this->Text = fn;

			try
			{
				// ��������� ������ �� �����
				System::IO::StreamReader^ sr =
					gcnew System::IO::StreamReader(fn);

				textBox1->Text = sr->ReadToEnd();
				textBox1->SelectionStart =
                              textBox1->TextLength;

				sr->Close();
				textChanged = false;
			}
			catch (  System::IO::FileLoadException^ e)
			{
				MessageBox::Show("������:\n" + e->Message,
                         "NkEdit",
						MessageBoxButtons::OK,
						MessageBoxIcon::Error);
			}
		}
	}
}

// ��������� ��������
private: void SaveDocument()
{
	int r;

	r = SaveText();
    
	if ( r == 0)
	{
		this->Text = fn;
		textChanged = false;		
	}
}

// ������� ��������
private: void NewDocument()
{
	int r;

	r = SaveText();
    
	if ( r == 0)
	{
		this->Text = "����� ��������";
		textBox1->Clear();
		textChanged = false;
		fn = String::Empty;
	}
}


// ����� � ���� ���� ������� �������
private: System::Void toolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e)
{
	OpenDocument();
}

// ����� � ���� ���� ������� ���������
private: System::Void toolStripMenuItem3_Click(System::Object^  sender, System::EventArgs^  e)
{
	SaveDocument();
}

// ����� � ���� ���� ������� �������
private: System::Void toolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e)
{
	NewDocument();
}

// ����� � ���� ���� ������� ������
private: System::Void toolStripMenuItem4_Click(System::Object^  sender, System::EventArgs^  e)
{
	printDialog1->ShowDialog();
}

// ����� � ���� ���� ������� �����
private: System::Void toolStripMenuItem5_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->Close();
}

// ����� � ���� ��������� ������� ������ ������������
private: System::Void toolStripMenuItem6_Click(System::Object^  sender, System::EventArgs^  e)
{
	// ����������/������ ������ ������������
    toolStrip1->Visible = ! toolStrip1->Visible;
    toolStripMenuItem6->Checked =
                         ! toolStripMenuItem6->Checked;
}

// ����� � ���� ��������� ������� �����
private: System::Void toolStripMenuItem7_Click(System::Object^  sender, System::EventArgs^  e)
{
	fontDialog1->Font = textBox1->Font;
	if (fontDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
    {
		textBox1->Font = fontDialog1->Font;
    }
}

// ������ �� ������ �������
private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e)
{
	NewDocument();
}

// ������ �� ������ �������
private: System::Void toolStripButton2_Click(System::Object^  sender, System::EventArgs^  e)
{
	OpenDocument();
}

// ������ �� ������ ���������
private: System::Void toolStripButton3_Click(System::Object^  sender, System::EventArgs^  e)
{
	SaveDocument();
}

// ������ �� ������ ������
private: System::Void toolStripButton4_Click(System::Object^  sender, System::EventArgs^  e)
{
	printDialog1->ShowDialog();
}

// ������� ������� ���� ���������
private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
{
	int r;
	
	r = SaveText();
    
	if ( r != 0)
	{
		e->Cancel = true;
	}	
}

// ����� � ���� ������� ������� � ���������
private: System::Void toolStripMenuItem9_Click(System::Object^  sender, System::EventArgs^  e)
{
	// ����� ����� Form2 ���� ��������,
	// � ������ ��������� ���� ��������
	// ��������� #include "Form2.h",
	// ��� Form2.h - ������, � ������� ���������
	// ����� Form2
	Form2^ about = gcnew Form2();

    about->ShowDialog();
}

};


}

