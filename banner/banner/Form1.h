#pragma once


namespace banner {

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
        try
        {
            bm = gcnew
                 System::Drawing::Bitmap
                 (Application::StartupPath + "\\banner.png");
        }
        catch (System::Exception^ e)
        {
            MessageBox::Show(
               "������ �������� ������ (" +
                Application::StartupPath + "\\banner.png)", 
               "������� ������",
               MessageBoxButtons::OK,
               MessageBoxIcon::Error);
            this->Close();// ��������� �����
            return;
        }

        // ���������� ����������� �����������
        g = this->CreateGraphics();

        // ���������� ������� ����������� �������
        rct.X = 0;
        rct.Y = 0;
        rct.Width = bm->Width;
        rct.Height = bm->Height;

        // ��������� �������
        timer1->Interval = 25;
        timer1->Enabled = true;
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
	private: System::Windows::Forms::Timer^  timer1;
	protected: 
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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(335, 169);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Form1";
			this->Text = L"������� ������";
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->ResumeLayout(false);

		}
#pragma endregion
	
private:
    // ������
    System::Drawing::Bitmap^  bm;

    // ����������� �����������
    Graphics^ g;

    // ������� ������ �������
    Rectangle rct;


	
	// ������ �� �������    
private: System::Void timer1_Tick(System::Object^ sender,
                                  System::EventArgs^  e) 
{
    // �������� ������� �����������
    // ������ �����
    rct.X -= 1;

    // ���� ������� ����������� �������
    // "������" �� ����� ������� �����,
    // ������ �� �������
    if (Math::Abs(rct.X) > rct.Width)
        rct.X += rct.Width;

    // �.�. ������� ����������� ���� �����, �� �����
    // ������ � "���������" �������, ������� �����
    // ��� ��� (��� ������� ����, ���� ������ �����
    // ����� ������ ������)
    for (int i = 0; i <= Convert::ToInt16(
                 this->ClientSize.Width / rct.Width) + 1; i++)
         g->DrawImage(bm, rct.X + i * rct.Width, rct.Y);
}

	// ����������� ��������� ����
private: System::Void Form1_MouseMove(System::Object^ sender,
                   System::Windows::Forms::MouseEventArgs^ e)
{
    // ��� ��������� ��������� ���� �� ������,
    // ��� ��������� (��������) ������������������
    if ((e->Y < rct.Y + rct.Height) && (e->Y > rct.Y))
    {
        // ��������� � ������� ����������� ������
        if (timer1->Enabled )
            // ������ "�����"
            timer1->Enabled = false;
    }
    else
        // ��������� �� �� ������
        {
            if ( ! timer1->Enabled )
                // ������ "�����",
                // �������� ��
                timer1->Enabled = true;
        }
}

	};
}

