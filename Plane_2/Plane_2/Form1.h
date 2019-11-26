#pragma once


namespace Plane_2 {

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
				sky = gcnew  System::Drawing::Bitmap(Application::StartupPath + "\\sky.bmp");
				plane = gcnew  System::Drawing::Bitmap(Application::StartupPath + "\\plane.bmp");
			}
			catch (System::Exception^ e)
            {
				MessageBox::Show(
					"������ �������� �������� ������: " + e->Message, 
				   "�����",MessageBoxButtons::OK,MessageBoxIcon::Error);
                this->Close();// ��������� �����
                return;
			}

			// ������� ���������� ���
            plane->MakeTransparent();

            // ���������� ������ ����� ������
            // ������� �������� �������
			this->ClientSize = sky->Size;

			 // ������ ������� ������� �����
             this->BackgroundImage = gcnew Bitmap(sky);

           
            // g - ����������� �����������, �� �������
            // ����� ����������� �������
			 // ���������� ����������� �����������
            g = this->CreateGraphics();

            // ������������� ���������� ����. �����
			rnd = gcnew System::Random();

            // �������� ��������� ��������
            rct.X = -40;
            rct.Y = 20 + rnd->Next(20);

            rct.Width = plane->Width;
            rct.Height = plane->Height;

            /*
            �������� ������ ������������ �������� ����������
            �������� �� ������� � ���������
            ���������� ���������� X
           */

            dx = 2; // �������� ������ - 2 �������/���_�������

            timer1->Interval = 20;
            timer1->Enabled = true;
		}

 private: System::Windows::Forms::Timer^  timer1;

	
	private:
		System::Drawing::Bitmap^  sky;
		System::Drawing::Bitmap^ plane;

		// ������� ����������� �����������
		Graphics^ g;

		// ���������� ���������� X,
        // ���������� �������� ������
        int dx;

        // �������, � ������� ��������� ������
        Rectangle rct;

		// ��������� ��������� �����
		System::Random^ rnd;

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
	private: System::ComponentModel::IContainer^  components;
	protected: 

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
			this->ClientSize = System::Drawing::Size(401, 264);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"�����";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
private:

System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
{
}


private:
System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
{	 
	// ������� ����������� ������� - �������
	// �������� ���� � �� �������
	// ����������� �����������, � �������
	// ������ ��������� ������
    g->DrawImage(sky,
		         Rectangle(rct.X,rct.Y,rct.Width,rct.Height),
		         Rectangle(rct.X,rct.Y,rct.Width,rct.Height),
				 GraphicsUnit::Pixel);

    // ��������� ����� ��������� �������
    if (rct.X < this->ClientRectangle.Width)
           rct.X += dx;
    else
	{
		// ������ ������ ������ �������,
        // ���������� ��� � ����� �������
        rct.X = -40;
        rct.Y = 20 + rnd->Next(40);

        // �������� ������ �� 2 �� 5
        // ��������/���_�������
        dx = 2 + rnd->Next(4);
    }

	g->DrawImage(plane,rct.X,rct.Y);
}


};
}

