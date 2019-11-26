#pragma once


namespace Brushes1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Drawing::Drawing2D;

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
			this->ClientSize = System::Drawing::Size(359, 326);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MinimizeBox = false;
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


	// ����� �� ������ e->Graphics ���������
	// ����������� ����������� g
	System::Drawing::Graphics^ g = e->Graphics;

	// Solid Brush
	g->FillRectangle(Brushes::ForestGreen, 20, 20, 30, 60);
	g->FillRectangle(Brushes::White, 50, 20, 30, 60);
	g->FillRectangle(Brushes::Red, 80, 20, 30, 60);
	g->DrawRectangle(Pens::Black, 20, 20, 90, 60);
    g->DrawString("Solid Brush", this->Font,
		Brushes::Black, 20, 85);

   // ����������� ����� LinearGradientBrush

	LinearGradientBrush^ lgBrush_1 =
                gcnew LinearGradientBrush(
                    RectangleF(200, 20, 90, 10),
					Color::Blue, Color::LightBlue,
					LinearGradientMode::Horizontal);

    g->FillRectangle(lgBrush_1, 200, 20, 90, 60);
    g->DrawString( "Linear Gradient - Horizontal",
		       this->Font, Brushes::Black, 200, 85);

    // ����������� ����� LinearGradientBrush
    LinearGradientBrush^ lgBrush_2 =
                gcnew LinearGradientBrush(
                    RectangleF(0, 0, 10, 60),
					Color::Blue, Color::LightBlue,
					LinearGradientMode::Vertical);

    g->FillRectangle(lgBrush_2, 20, 120, 90, 60);
    g->DrawString("Linear Gradient - Vertical",
		   this->Font, Brushes::Black, 20, 185);

    // ���������� ����� 
    try 
    {
		TextureBrush^ tBrush =
            gcnew TextureBrush(Image::FromFile(   Application::StartupPath+"\\brush_1.bmp"));

        g->FillRectangle(tBrush, 200, 120, 90, 60);
    }
	catch (System::IO::FileNotFoundException^ e)
    {
		g->DrawRectangle(Pens::Black, 200, 120, 90, 60);
		g->DrawString("Source image",
			 this->Font, Brushes::Black, 200, 125);
        g->DrawString(" not found",
			 this->Font, Brushes::Black, 200, 140);
    }
    
	g->DrawString("Texture Brush", this->Font,
				Brushes::Black, 200, 185);
                        
    // ��������� ( HatchBrush �����)
    HatchBrush^ hBrush =
				gcnew HatchBrush(HatchStyle::DottedGrid,
				Color::Black, Color::Gold);

    g->FillRectangle(hBrush, 20, 220, 90, 60);
    g->DrawString("HatchBrush - DottedGrid",
				this->Font, Brushes::Black, 20, 285);

    HatchBrush^ hBrush_2 =
				gcnew HatchBrush(HatchStyle::DiagonalCross,
				Color::Black, Color::Gold);

    g->FillRectangle(hBrush_2, 200, 220, 90, 60);
            g->DrawString(
                 "HatchBrush - DiagonalCross", this->Font,
				 Brushes::Black, 200, 285);
}


	};
}

