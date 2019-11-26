#pragma once


namespace rectangle {

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
			this->ClientSize = System::Drawing::Size(284, 178);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"��������������";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->SizeChanged += gcnew System::EventHandler(this, &Form1::Form1_SizeChanged);
			this->ResumeLayout(false);

		}
#pragma endregion
	
private:

// ��������� ������� Paint
System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
{
	int w,h;   // ������ �����
	int ws;    // ������ ������
	int x0,y0; // ���������� ������ �������� ���� �����

	int x,y;   // ���������� ������ �������� ���� ������

	w = 83;
	h = 60;
	
	// ��������� ���� � ������ �����:
	// this->ClientSize.Width - ������ ���������� ������� �����;
    // this->ClientSize.Height - ������ ���������� ������� �����;
    
	x0 = (this->ClientSize.Width - w) / 2;
	y0 = (this->ClientSize.Height - h) /2;

	ws = w / 3; // ���� �� ���� ������������ �����

	// ������ ����
	x = x0;
	y = y0;
	
	// ������� ������
	e->Graphics->FillRectangle(Brushes::Green,x,y,ws,h);
	
	// ����� ������
	x = x + ws+1;
	e->Graphics->FillRectangle(System::Drawing::Brushes::White,x,y,ws,h);
	
	// ������� ������
	x = x + ws+1;
	e->Graphics->FillRectangle(System::Drawing::Brushes::Red,x,y,ws,h);

    // ���������
	e->Graphics->DrawRectangle(System::Drawing::Pens::Black,x0,y0,w,h);
}


// ������� SizeChanged ��������� ��� ��������� ������� �����
private: System::Void Form1_SizeChanged(System::Object^  sender, System::EventArgs^  e)
{
	// ����� Refresh ����������� ������� � �������������
	// ������������ (��������) �����. � ����������
	// ������������ ������� Paint
	this->Refresh(); // �������� �����
}

	
};
}

