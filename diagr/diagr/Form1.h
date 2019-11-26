#pragma once


namespace diagr {

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
			

			// ������ ������ �� ����� � ������
			System::IO::StreamReader^ sr; // ����� ��� ������
            try
            {
				sr = gcnew System::IO::StreamReader(
					Application::StartupPath + "\\usd.dat");

                // c������ ������ 
                d = gcnew array<double>(10);

                // ������ ������ �� �����
                int i = 0;
                String^ t = sr->ReadLine();
				while ((  t != String::Empty) && (i < d->Length))
                {
                    // ���������� ��������� ����� � ������
					d[i++] = Convert::ToDouble(t);
                    t = sr->ReadLine();
                }

                // ��������� �����
                sr->Close();


			    // ������ ���������
				// ������ ������� ��������� ������� Paint
				this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::drawDiagram);
                
            }
            
			// ��������� ����������:
            // - ���� ������ �� ������
			catch (System::IO::FileNotFoundException^ ex)
            { 
				MessageBox::Show( ex->Message + "\n",
                    "������",
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
			this->SuspendLayout();
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(429, 264);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"���������";
			this->Resize += gcnew System::EventHandler(this, &Form1::Form1_Resize);
			this->ResumeLayout(false);

		}
#pragma endregion


private:
        
// ������
array<double>^ d;      

// ������ ������ 
void drawDiagram(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
{
	// ����������� �����������
	System::Drawing::Graphics^ g = e->Graphics;

    // ����� �������� ������
    System::Drawing::Font^ dFont = gcnew System::Drawing::Font("Tahoma", 9);

    // ** ��������� **
    // ����� ���������
    System::Drawing::Font^ hFont = gcnew System::Drawing::Font("Tahoma", 14,
				FontStyle::Regular);
    String^ header = "��������� ����� �������";

    // ������ ������� ����������� ������
    int wh =(int)g->MeasureString(header, hFont).Width;

    int x = (this->ClientSize.Width - wh) / 2; 
            
    g->DrawString(header,hFont, Brushes::DarkGreen, x, 5);

    /* ������� ���������� ���������.
       �������:
	       ������ - 100;
           ����� - 20;
           ����� - 20;
           ������ - 20.
             
        ClientSize - ������ ���������� ������� ����
             
        ������ ������ � ����������� �� ������������
        �������� ���� ������, ���, ����� �� �������
        ��� ������� ����������
	*/
            
    double max = d[0]; // ������������ ��-� �������
    double min = d[0]; // ����������� ��-� �������

    for (int i = 1; i < d.Length; i++)
    {
		if (d[i] > max) max = d[i];
        if (d[i] < min) min = d[i];
    }

    // ������ ��������
    int x1, y1; // ���������� ������ ��������
                //  ���� ��������
    int w, h;   // ������ �������
 
    // ������ ��������� ���������
    // 5 - ���������� ����� ����������
    // d.Length - ���-�� ����� ������ (���������)
    
	w = (ClientSize.Width - 40 - 5 * (d.Length - 1))
                                         / d.Length;
    x1 = 20;
    for (int i = 0; i < d.Length; i++)
	{
		y1 = ClientSize.Height - 20 -
                 (int)((ClientSize.Height - 100) *
                    (d[i] - min) / (max - min));

        // ������� ���������� �������� ������ �����
		g->DrawString(Convert::ToString(d[i]),
					dFont, Brushes::Black,
                    x1, y1 - 20);
                
        // ������ ������� - ������� �������������
        h = ClientSize.Height - y1 - 20 + 1;
 
		g->FillRectangle(Brushes::ForestGreen,
                                x1, y1, w, h);
                
        // ������ ��������������
    	g->DrawRectangle(Pens::Black,
                                x1, y1, w, h);

         x1 = x1 + w +5;
	}
}


private: System::Void Form1_Resize(System::Object^  sender, System::EventArgs^  e)
			 {
				 this->Refresh();
			 }
};
}

