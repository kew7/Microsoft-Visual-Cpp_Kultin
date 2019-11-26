#pragma once


namespace drawString {

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
			this->SuspendLayout();
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(418, 199);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"DrawString";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->Resize += gcnew System::EventHandler(this, &Form1::Form1_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion
	
// ��������� ������� Paint
private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
{
	       int x,y;
		   int w,h; // ������ ������� ����������� ������

		   x = 10;
		   y = 10;
	       

		   String^ st =
                   "Microsoft Visual C++ Express Edition";

		   // ����� ������ �������, �������� ���������
           // �������� Font �����. Brushes - ���������
		   // ����������� ������.
           e->Graphics->DrawString(st,
			   this->Font, Brushes::DarkGreen, x, y);

          
		   // ���������� ������ ������� �����������
		   // ���������� ������

		    h = (int)e->Graphics->MeasureString(st, this->Font).Height;

			// ��������� Y ���������� ������� �����������
			// ������ ������
			y = y + h;
		   
		   // ����� ������ �������, ��������� �������������:
		   System::Drawing::Font^ aFont = 
			              gcnew System::Drawing::Font("Tahoma", 10,
						         			FontStyle::Regular);

            e->Graphics->DrawString(st,
									aFont, Brushes::Black, x, y);

            // ����� ������ � ������ �����
            System::Drawing::Font^ hFont = gcnew System::Drawing::Font("Tahoma", 14,
									FontStyle::Italic);
            

            // ������ ������� ����������� ������ ������� ��
            // ������������� ������, ������� �� ������������

            // ���������� ������ ������� ����������� ������
            w = (int)e->Graphics->
                        MeasureString(st, hFont).Width;
            h = (int)e->Graphics->
                        MeasureString(st, hFont).Height;

            // ��������� ���������� ������ �������� ���� 
            // ������� ����������� ������, ��� ����� ����� ��� 
            // �������� � ������ ����� �� ����������� �
            // ���������. ClientSize.Width - ������ ����������
            // ������� �����
            x = (this->ClientSize.Width - w) / 2;
            y = (this->ClientSize.Height - h) / 2;

            // ������� ����� � ������ �����
            e->Graphics->DrawString(st, hFont,
				System::Drawing::Brushes::DarkGreen, x, y);

            // ������� ����� ��� ���
            e->Graphics->DrawString(st, hFont,
				System::Drawing::Brushes::DarkGreen, x, y + h);	 
}

// ��������� ������ �����
private: System::Void Form1_Resize(System::Object^  sender, System::EventArgs^  e)
{
	// �������� ������� � �������������
    // ������������ ����. � ���������� �����
    // ������������� ������� Paint.
	this->Refresh();
}



};
}

