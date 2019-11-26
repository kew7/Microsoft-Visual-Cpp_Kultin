// ������ �������� ���������.
// ������ ����������� �� �����.
// ������������ ���������� ����� ������ - 8.
#pragma once


namespace cDiagr {

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
	
	
private:
	String^ header;  // ��������� ���������

    // ���������� ��������� ������
    int N;
      
    array<double>^ dat; // ��� ������
    array<double>^ p;   // ���� ��������� � ����� �����

    // ������� ������
   array<String^>^ title;

	
	public:
		Form1(void)
		{
			InitializeComponent();
			
			System::IO::StreamReader^ sr;

			
	try
    {

			sr = gcnew System::IO::StreamReader(
				Application::StartupPath + "\\date.dat",
				System::Text::Encoding::GetEncoding(1251));

            // ��������� ��������� ���������
            header = sr->ReadLine();

            // ��������� ������ � ���������� �������
			N = Convert::ToInt16(sr->ReadLine());
            
			// � �������������� �������
			dat = gcnew array<double>(N);
            p = gcnew array<double>(N);
            title = gcnew array<String^>(N);

            // ������ ������
            int i = 0;
            String^ st;
            st = sr->ReadLine();
			while ((st != String::Empty) && (i < N))
            {
				title[i] = st;

                st = sr->ReadLine();
			    dat[i++] = Convert::ToDouble(st);

                st = sr->ReadLine();
            }

            // ��������� �����
            sr->Close();

            // ������ ���������
			// ������ ������� ��������� ������� Paint
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::drawDiagram);
              
            double sum = 0;
            int j = 0;
                
            // ��������� �����
            for (j = 0; j < N; j++)
				sum += dat[j];

            // ��������� ���� ������ ���������
            for (j = 0; j < N; j++)
                    p[j] = (double)(dat[j] / sum);
       }
       catch (System::IO::FileNotFoundException^ ex)
            {
				MessageBox::Show(ex->Message,
                    "���������",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
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
			this->ClientSize = System::Drawing::Size(454, 264);
			this->MinimumSize = System::Drawing::Size(470, 300);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"�������� ���������";
			this->Resize += gcnew System::EventHandler(this, &Form1::Form1_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion

// ������ �������� ��������� 
void drawDiagram(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
{
	// ����������� �����������
	System::Drawing::Graphics^ g = e->Graphics;

    // ����� ���������	 
			System::Drawing::Font^ hFont = gcnew System::Drawing::Font("Tahoma", 12);
       
    // ������� ���������
    int w = (int)g->MeasureString(header, hFont).Width;
    int x = (ClientSize.Width - w) / 2;

    g->DrawString(header,hFont, Brushes::Black, x, 10);

    // ����� �������
	System::Drawing::Font^ lFont = gcnew System::Drawing::Font("Tahoma", 9);

    // ������� ���������
    int d = ClientSize.Height - 80;

    int x0 = 30;
    int y0 = (ClientSize.Height - d) / 2 + 10;

    // ���������� �������� ������ ����
    // ������� �������
    int lx = 60 + d;
    int ly = y0 + (d - N * 20 + 10) / 2;

    int swe; // ������ ���� �������

    // ����� ��� ������� ������� ���������
	System::Drawing::Brush^  fBrush = Brushes::White;

    // ��������� ����� ���� �������
    int sta = -90;
            
    // ������ ���������
    for (int i = 0; i < N; i++)
    {
		// ������ ����
        swe = (int)(360 * p[i]);

		// ������ ���� �������
        switch (i)
        {
			case 0:
				fBrush = Brushes::YellowGreen;
				break;
            case 1:
				fBrush = Brushes::Gold;
				break;
            case 2:
				fBrush = Brushes::Pink;
				break;
            case 3:
				fBrush = Brushes::Violet;
				break;
            case 4:
				fBrush = Brushes::OrangeRed;
				break;
            case 5:
				fBrush = Brushes::RoyalBlue;
				break;
            case 6:
				fBrush = Brushes::SteelBlue;
				break;
            case 7:
				fBrush = Brushes::Chocolate;
				break;
            case 8:
				fBrush = Brushes::LightGray;
				break;
		}

        // ��-�� ���������� �������� ��������
        // ��� ������� ����� ���������� �����
        // ��������� � ������ ���������
        if (i == N - 1)
			// ��������� ������
            swe = 270 - sta;
                

        // ������ ������
        g->FillPie(fBrush, x0, y0, d, d, sta, swe);

        // ������ ������� �������
		g->DrawPie(Pens::Black, x0, y0,
                        d, d, sta, swe);
                
        // ������������� �������
        g->FillRectangle(fBrush,
                          lx, ly + i * 20, 20, 10);
		g->DrawRectangle(Pens::Black,
                          lx, ly + i * 20, 20, 10);

        // �������
        g->DrawString( title[i] + " - " +
					p[i].ToString("P"),
					lFont, Brushes::Black,
                          lx + 24, ly + i * 20 - 3);

        // ��������� ����� ���� ��� ���������� �������
        sta = sta + swe; 
	}
}


private: System::Void Form1_Resize(System::Object^  sender, System::EventArgs^  e)
			 {
				 this->Refresh();
			 }




};
}

